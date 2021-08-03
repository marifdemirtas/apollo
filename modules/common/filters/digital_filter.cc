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

#include "modules/common/filters/digital_filter.h"

#include <cmath>

#include "cyber/common/log.h"

namespace {

const double kDoubleEpsilon = 1.0e-6;

}  // namespace

namespace apollo {
namespace common {

DigitalFilter::DigitalFilter(const std::vector<double> &denominators,
                             const std::vector<double> &numerators) {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  set_coefficients(denominators, numerators);
}

void DigitalFilter::set_denominators(const std::vector<double> &denominators) {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  denominators_ = denominators;
  y_values_.resize(denominators_.size(), 0.0);
}

void DigitalFilter::set_numerators(const std::vector<double> &numerators) {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  numerators_ = numerators;
  x_values_.resize(numerators_.size(), 0.0);
}

void DigitalFilter::set_coefficients(const std::vector<double> &denominators,
                                     const std::vector<double> &numerators) {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  set_denominators(denominators);
  set_numerators(numerators);
}

void DigitalFilter::set_dead_zone(const double deadzone) {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  dead_zone_ = std::fabs(deadzone);
  AINFO << "Setting digital filter dead zone = " << dead_zone_;
}

double DigitalFilter::Filter(const double x_insert) {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  if (denominators_.empty() || numerators_.empty()) {
    AERROR << "Empty denominators or numerators";
    return 0.0;
  }

  x_values_.pop_back();
  x_values_.push_front(x_insert);
  const double xside =
      Compute(x_values_, numerators_, 0, numerators_.size() - 1);

  y_values_.pop_back();
  const double yside =
      Compute(y_values_, denominators_, 1, denominators_.size() - 1);

  double y_insert = 0.0;
  if (std::fabs(denominators_.front()) > kDoubleEpsilon) {
    y_insert = (xside - yside) / denominators_.front();
  }
  y_values_.push_front(y_insert);

  return UpdateLast(y_insert);
}

void DigitalFilter::reset_values() {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  std::fill(x_values_.begin(), x_values_.end(), 0.0);
  std::fill(y_values_.begin(), y_values_.end(), 0.0);
}

double DigitalFilter::UpdateLast(const double input) {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  const double diff = std::fabs(input - last_);
  if (diff < dead_zone_) {
    return last_;
  }
  last_ = input;
  return input;
}

double DigitalFilter::Compute(const std::deque<double> &values,
                              const std::vector<double> &coefficients,
                              const std::size_t coeff_start,
                              const std::size_t coeff_end) {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  ACHECK(coeff_start <= coeff_end && coeff_end < coefficients.size());
  ACHECK((coeff_end - coeff_start + 1) == values.size());

  double sum = 0.0;
  auto i = coeff_start;
  for (const auto value : values) {
    sum += value * coefficients[i];
    ++i;
  }
  return sum;
}

const std::vector<double> &DigitalFilter::denominators() const {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return denominators_;
}

const std::vector<double> &DigitalFilter::numerators() const {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return numerators_;
}

double DigitalFilter::dead_zone() const {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";
 return dead_zone_; }

const std::deque<double> &DigitalFilter::inputs_queue() const {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return x_values_;
}

const std::deque<double> &DigitalFilter::outputs_queue() const {
cout << "[ARIF_LOG] __PRETTY_FUNCTION__ called.";

  return y_values_;
}

}  // namespace common
}  // namespace apollo
