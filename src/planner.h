#pragma once

#include <array>
#include "perception.h"

using std::array;
using std::vector;

class Planner {
 public:
  /**
   * Constructor.
   */
  Planner(const double &max_front, const double &max_rear, const float &lwidth);

  /**
   * Destructor.
   */
  virtual ~Planner();

  void sense(const vector<vector<double> > &sensor_fusion,
             const double &delta_t, const double &car_s);

  void update(int &lane, double &target_vel);

  // Motion planning
  double front_margin, rear_margin;
  array<bool, 3> is_avail, is_allowed;

 private:
  void reset_env();
  PerceptionModule module;
};
