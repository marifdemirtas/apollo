#include "modules/covlogger.h"
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
#include "modules/perception/fusion/base/scene.h"

namespace apollo {
namespace perception {
namespace fusion {

Scene::Scene() {
COVERAGE_LOG_TOKEN
}

Scene::~Scene() {
COVERAGE_LOG_TOKEN
}

void Scene::AddForegroundTrack(TrackPtr track) {
COVERAGE_LOG_TOKEN

  foreground_tracks_.push_back(track);
}

void Scene::AddBackgroundTrack(TrackPtr track) {
COVERAGE_LOG_TOKEN

  background_tracks_.push_back(track);
}

}  // namespace fusion
}  // namespace perception
}  // namespace apollo
