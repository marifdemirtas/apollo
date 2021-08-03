#include "cyber/common/log.h"
/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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
#include "modules/perception/tool/benchmark/lidar/util/object_supplement.h"

namespace apollo {
namespace perception {
namespace benchmark {

/**LidarSupplement implementation*/
LidarSupplement::LidarSupplement() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

LidarSupplement::~LidarSupplement() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

LidarSupplement::LidarSupplement(const LidarSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

LidarSupplement& LidarSupplement::operator=(const LidarSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return (*this);
}

void LidarSupplement::clone(const LidarSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

/**RadarSupplement implementation*/
RadarSupplement::RadarSupplement() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

RadarSupplement::~RadarSupplement() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

RadarSupplement::RadarSupplement(const RadarSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  range = rhs.range;
  angle = rhs.angle;
  relative_radial_velocity = rhs.relative_radial_velocity;
  relative_tangential_velocity = rhs.relative_tangential_velocity;
}

RadarSupplement& RadarSupplement::operator=(const RadarSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  range = rhs.range;
  angle = rhs.angle;
  relative_radial_velocity = rhs.relative_radial_velocity;
  relative_tangential_velocity = rhs.relative_tangential_velocity;
  return (*this);
}

void RadarSupplement::clone(const RadarSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  range = rhs.range;
  angle = rhs.angle;
  relative_radial_velocity = rhs.relative_radial_velocity;
  relative_tangential_velocity = rhs.relative_tangential_velocity;
}

/**CameraSupplement implementation*/
CameraSupplement::CameraSupplement() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

CameraSupplement::~CameraSupplement() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

CameraSupplement::CameraSupplement(const CameraSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  upper_left = rhs.upper_left;
  lower_right = rhs.lower_right;
}

CameraSupplement& CameraSupplement::operator=(const CameraSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  upper_left = rhs.upper_left;
  lower_right = rhs.lower_right;
  return (*this);
}

void CameraSupplement::clone(const CameraSupplement& rhs) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  upper_left = rhs.upper_left;
  lower_right = rhs.lower_right;
}

}  // namespace benchmark
}  // namespace perception
}  // namespace apollo
