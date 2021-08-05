#include <iostream>
/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

#include "modules/localization/msf/local_map/base_map/base_map_matrix.h"

namespace apollo {
namespace localization {
namespace msf {

BaseMapMatrix::BaseMapMatrix() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

BaseMapMatrix::~BaseMapMatrix() {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

BaseMapMatrix::BaseMapMatrix(const BaseMapMatrix& cells) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
}

unsigned int BaseMapMatrix::LoadBinary(unsigned char* buf) {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
 return 0; }

unsigned int BaseMapMatrix::CreateBinary(unsigned char* buf,
                                         unsigned int buf_size) const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return 0;
}

unsigned int BaseMapMatrix::GetBinarySize() const {
AINFO << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
 return 0; }

}  // namespace msf
}  // namespace localization
}  // namespace apollo
