#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Core>
#include <Eigen/LU>

#include "stl_parser/parse_stl.h"

namespace raytest
{
  using Vector3d = Eigen::Vector3d;
  using Matrix3d = Eigen::Matrix3d;

  std::vector<double> ray_test(
      const stl::stl_data& mesh, const Vector3d& p_start, const Vector3d& ray_dir);

  std::vector<double> ray_test_expose(
      const std::string& stl_file_name, const Vector3d& p_start, const Vector3d& ray_dir);

}
