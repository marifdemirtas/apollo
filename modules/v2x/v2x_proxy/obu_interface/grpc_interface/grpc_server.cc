/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file grpc_server.cc
 * @brief define v2x proxy module and onboard unit interface grpc implement
 */

#include "modules/v2x/v2x_proxy/obu_interface/grpc_interface/grpc_server.h"

#include <chrono>

#include "modules/v2x/common/v2x_proxy_gflags.h"

namespace apollo {
namespace v2x {

using ::apollo::v2x::StatusResponse;
using ::apollo::v2x::obu::ObuRsi;
using ::apollo::v2x::obu::ObuTrafficLight;
using grpc::Status;

GrpcServerImpl::GrpcServerImpl()
    : node_(::apollo::cyber::CreateNode("v2x_grpc_server")) {
  CHECK(!!node_);
  // _monitor = cybertron::MetricController::Instance();
  AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AINFO << "GrpcServerImpl initial success";
   init_flag_ = true;
}

grpc::Status GrpcServerImpl::SendV2xRSI(grpc::ServerContext * /* context */,
                                        const ObuRsi *request,
                                        StatusResponse *response) {
  AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 ADEBUG << "Received SendV2xRSI request from client!";
   AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 ADEBUG << request->DebugString();
 
  if (!request->has_header()) {
    response->set_status(false);
    response->set_info("error no header in RSI request");
    AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AERROR << "SendV2xRSI request has no header";
    return Status::CANCELLED;
  }
  {
    std::lock_guard<std::mutex> guard(rsi_mutex_);
    latest_rsi_.CopyFrom(*request);
    auto obu_header = latest_rsi_.mutable_header();
    if (obu_header->has_timestamp_sec()) {
      AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AINFO << "Obu Timestamp: " << std::setiosflags(std::ios::fixed)
             << std::setprecision(11) << obu_header->timestamp_sec();
      AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AINFO << "SVB Timestamp: " << std::setiosflags(std::ios::fixed)
             << std::setprecision(11) << ::apollo::cyber::Time::Now().ToSecond();
      obu_header->set_timestamp_sec(::apollo::cyber::Time::Now().ToSecond());
    }
    rsi_refresh_ = true;
  }
  rsi_condition_.notify_one();

  response->set_status(true);
  AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AINFO << "SendV2xRSI response success.";
   return Status::OK;
}
grpc::Status GrpcServerImpl::SendPerceptionObstacles(
    grpc::ServerContext *, const apollo::v2x::V2XObstacles *request,
    StatusResponse *response) {
  AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 ADEBUG << "Received SendPerceptionObstacles request from client!";
   {
    std::lock_guard<std::mutex> guard(obstacles_mutex_);
    latest_obstacles_.CopyFrom(*request);
    response->set_status(true);
    obs_refresh_ = true;
    AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 ADEBUG << "SendPerceptionObstacles response success.";
   }
  obs_condition_.notify_one();
  return Status::OK;
}

grpc::Status GrpcServerImpl::SendV2xTrafficLight(
    grpc::ServerContext * /* context */, const ObuTrafficLight *request,
    StatusResponse *response) {
  AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 ADEBUG << "Received SendV2xTrafficLight request from client!";
   AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 ADEBUG << request->DebugString();
 
  int num_current_light = request->road_traffic_light_size();

  if (0 == num_current_light) {
    response->set_status(false);
    response->set_info("error v2x current lane traffic light size == 0");
    AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AERROR << "SendV2xTrafficLight request no current lane traffic light.";
    return Status::CANCELLED;
  }
  if (!request->has_header()) {
    response->set_status(false);
    response->set_info(
        "error no header in IntersectionTrafficLightData request");
    AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AERROR << "SendV2xTrafficLight request has no header";
    return Status::CANCELLED;
  }
  {
    std::lock_guard<std::mutex> guard(traffic_light_mutex_);
    latest_traffic_light_.CopyFrom(*request);
    auto obu_header = latest_traffic_light_.mutable_header();
    if (obu_header->has_timestamp_sec()) {
      obu_header->set_timestamp_sec(::apollo::cyber::Time::Now().ToSecond());
    }
    refresh_ = true;
  }
  traffic_light_condition_.notify_one();
  auto cur_junction_id = request->intersection_id();
  AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 ADEBUG << "recieved the junction id " << cur_junction_id;
   response->set_status(true);
  return Status::OK;
}

grpc::Status GrpcServerImpl::SendObuAlarm(
    grpc::ServerContext *context, const ::apollo::v2x::ObuAlarm *request,
    StatusResponse *response) {
  AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 ADEBUG << "Received SendOBUAlarm request from client!";
   if (request->error_num() != ::apollo::v2x::ErrorCode::OBUID) {
  } else {
    AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AERROR << "OBU id:" << request->error_msg();
  }
  response->set_status(true);
  return Status::OK;
}

void GrpcServerImpl::GetMsgFromGrpc(std::shared_ptr<ObuRsi> *ptr) {
  if (nullptr == ptr) {
    return;
  }
  std::unique_lock<std::mutex> guard(rsi_mutex_);
  rsi_condition_.wait(guard, [this] { return rsi_refresh_; });
  rsi_refresh_ = false;
  *ptr = std::make_shared<ObuRsi>();
  if (nullptr == *ptr) {
    return;
  }
  (*ptr)->CopyFrom(latest_rsi_);
}

void GrpcServerImpl::GetMsgFromGrpc(
    std::shared_ptr<::apollo::v2x::V2XObstacles> *ptr) {
  if (nullptr == ptr) {
    return;
  }
  std::unique_lock<std::mutex> guard(obstacles_mutex_);
  obs_condition_.wait(guard, [this] { return obs_refresh_; });
  obs_refresh_ = false;
  *ptr = std::make_shared<::apollo::v2x::V2XObstacles>();
  if (nullptr == *ptr) {
    return;
  }
  (*ptr)->CopyFrom(latest_obstacles_);
}

void GrpcServerImpl::GetMsgFromGrpc(std::shared_ptr<ObuTrafficLight> *ptr) {
  if (nullptr == ptr) {
    return;
  }
  std::unique_lock<std::mutex> guard(traffic_light_mutex_);
  if (!traffic_light_condition_.wait_for(
          guard, std::chrono::milliseconds(FLAGS_msg_timeout),
          [this] { return refresh_; })) {
    AINFO << "[COV_LOG] " << __PRETTY_FUNCTION__;
 AERROR << "GetMsgFromGrpc IntersectionTrafficLightData is timeout";
    *ptr = nullptr;
    return;
  }
  *ptr = std::make_shared<ObuTrafficLight>();
  if (nullptr == *ptr) {
    return;
  }
  (*ptr)->CopyFrom(latest_traffic_light_);
  latest_traffic_light_.Clear();
  refresh_ = false;
}

}  // namespace v2x
}  // namespace apollo
