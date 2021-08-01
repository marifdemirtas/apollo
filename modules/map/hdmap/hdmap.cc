/* Copyright 2017 The Apollo Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
=========================================================================*/

#include "modules/map/hdmap/hdmap.h"

#include "modules/map/hdmap/hdmap_util.h"

namespace apollo {
namespace hdmap {

int HDMap::LoadMapFromFile(const std::string& map_filename) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  AINFO << "Loading HDMap: " << map_filename << " ...";
  try
  {
    AINFO << "Arif called macro 1:" << __func__;
  }
  catch(const std::exception& e)
  {
    AINFO << "Arif called macro 1 and it raised an exception";
  }
  try
  {
    AINFO << "Arif called macro 2:" << __FUNCTION__;
  }
  catch(const std::exception& e)
  {
    AINFO << "Arif called macro 2 and it raised an exception";
  }
  try
  {
    AINFO << "Arif called macro 3:" << __PRETTY_FUNCTION__;
  }
  catch(const std::exception& e)
  {
    AINFO << "Arif called macro 3 and it raised an exception";
  }
  
  return impl_.LoadMapFromFile(map_filename);
}

int HDMap::LoadMapFromProto(const Map& map_proto) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  ADEBUG << "Loading HDMap with header: "
         << map_proto.header().ShortDebugString();
  return impl_.LoadMapFromProto(map_proto);
}

LaneInfoConstPtr HDMap::GetLaneById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetLaneById(id);
}

JunctionInfoConstPtr HDMap::GetJunctionById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetJunctionById(id);
}

SignalInfoConstPtr HDMap::GetSignalById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetSignalById(id);
}

CrosswalkInfoConstPtr HDMap::GetCrosswalkById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetCrosswalkById(id);
}

StopSignInfoConstPtr HDMap::GetStopSignById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetStopSignById(id);
}

YieldSignInfoConstPtr HDMap::GetYieldSignById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetYieldSignById(id);
}

ClearAreaInfoConstPtr HDMap::GetClearAreaById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetClearAreaById(id);
}

SpeedBumpInfoConstPtr HDMap::GetSpeedBumpById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetSpeedBumpById(id);
}

OverlapInfoConstPtr HDMap::GetOverlapById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetOverlapById(id);
}

RoadInfoConstPtr HDMap::GetRoadById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetRoadById(id);
}

ParkingSpaceInfoConstPtr HDMap::GetParkingSpaceById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetParkingSpaceById(id);
}

PNCJunctionInfoConstPtr HDMap::GetPNCJunctionById(const Id& id) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetPNCJunctionById(id);
}

int HDMap::GetLanes(const apollo::common::PointENU& point, double distance,
                    std::vector<LaneInfoConstPtr>* lanes) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetLanes(point, distance, lanes);
}

int HDMap::GetJunctions(const apollo::common::PointENU& point, double distance,
                        std::vector<JunctionInfoConstPtr>* junctions) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetJunctions(point, distance, junctions);
}

int HDMap::GetSignals(const apollo::common::PointENU& point, double distance,
                      std::vector<SignalInfoConstPtr>* signals) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetSignals(point, distance, signals);
}

int HDMap::GetCrosswalks(const apollo::common::PointENU& point, double distance,
                         std::vector<CrosswalkInfoConstPtr>* crosswalks) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetCrosswalks(point, distance, crosswalks);
}

int HDMap::GetStopSigns(const apollo::common::PointENU& point, double distance,
                        std::vector<StopSignInfoConstPtr>* stop_signs) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetStopSigns(point, distance, stop_signs);
}

int HDMap::GetYieldSigns(
    const apollo::common::PointENU& point, double distance,
    std::vector<YieldSignInfoConstPtr>* yield_signs) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetYieldSigns(point, distance, yield_signs);
}

int HDMap::GetClearAreas(
    const apollo::common::PointENU& point, double distance,
    std::vector<ClearAreaInfoConstPtr>* clear_areas) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetClearAreas(point, distance, clear_areas);
}

int HDMap::GetSpeedBumps(
    const apollo::common::PointENU& point, double distance,
    std::vector<SpeedBumpInfoConstPtr>* speed_bumps) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetSpeedBumps(point, distance, speed_bumps);
}

int HDMap::GetRoads(const apollo::common::PointENU& point, double distance,
                    std::vector<RoadInfoConstPtr>* roads) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetRoads(point, distance, roads);
}

int HDMap::GetParkingSpaces(
    const apollo::common::PointENU& point, double distance,
    std::vector<ParkingSpaceInfoConstPtr>* parking_spaces) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetParkingSpaces(point, distance, parking_spaces);
}

int HDMap::GetPNCJunctions(
    const apollo::common::PointENU& point, double distance,
    std::vector<PNCJunctionInfoConstPtr>* pnc_junctions) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetPNCJunctions(point, distance, pnc_junctions);
}

int HDMap::GetNearestLane(const common::PointENU& point,
                          LaneInfoConstPtr* nearest_lane, double* nearest_s,
                          double* nearest_l) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetNearestLane(point, nearest_lane, nearest_s, nearest_l);
}

int HDMap::GetNearestLaneWithHeading(const apollo::common::PointENU& point,
                                     const double distance,
                                     const double central_heading,
                                     const double max_heading_difference,
                                     LaneInfoConstPtr* nearest_lane,
                                     double* nearest_s,
                                     double* nearest_l) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetNearestLaneWithHeading(point, distance, central_heading,
                                         max_heading_difference, nearest_lane,
                                         nearest_s, nearest_l);
}

int HDMap::GetLanesWithHeading(const apollo::common::PointENU& point,
                               const double distance,
                               const double central_heading,
                               const double max_heading_difference,
                               std::vector<LaneInfoConstPtr>* lanes) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetLanesWithHeading(point, distance, central_heading,
                                   max_heading_difference, lanes);
}

int HDMap::GetRoadBoundaries(
    const apollo::common::PointENU& point, double radius,
    std::vector<RoadROIBoundaryPtr>* road_boundaries,
    std::vector<JunctionBoundaryPtr>* junctions) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetRoadBoundaries(point, radius, road_boundaries, junctions);
}

int HDMap::GetRoadBoundaries(
    const apollo::common::PointENU& point, double radius,
    std::vector<RoadRoiPtr>* road_boundaries,
    std::vector<JunctionInfoConstPtr>* junctions) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetRoadBoundaries(point, radius, road_boundaries, junctions);
}

int HDMap::GetRoi(const apollo::common::PointENU& point, double radius,
                  std::vector<RoadRoiPtr>* roads_roi,
                  std::vector<PolygonRoiPtr>* polygons_roi) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetRoi(point, radius, roads_roi, polygons_roi);
}

int HDMap::GetForwardNearestSignalsOnLane(
    const apollo::common::PointENU& point, const double distance,
    std::vector<SignalInfoConstPtr>* signals) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetForwardNearestSignalsOnLane(point, distance, signals);
}

int HDMap::GetStopSignAssociatedStopSigns(
    const Id& id, std::vector<StopSignInfoConstPtr>* stop_signs) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetStopSignAssociatedStopSigns(id, stop_signs);
}

int HDMap::GetStopSignAssociatedLanes(
    const Id& id, std::vector<LaneInfoConstPtr>* lanes) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetStopSignAssociatedLanes(id, lanes);
}

int HDMap::GetLocalMap(const apollo::common::PointENU& point,
                       const std::pair<double, double>& range,
                       Map* local_map) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetLocalMap(point, range, local_map);
}

int HDMap::GetForwardNearestRSUs(const apollo::common::PointENU& point,
                    double distance, double central_heading,
                    double max_heading_difference,
                    std::vector<RSUInfoConstPtr>* rsus) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return impl_.GetForwardNearestRSUs(point, distance,
                    central_heading,
                    max_heading_difference, rsus);
}

}  // namespace hdmap
}  // namespace apollo
