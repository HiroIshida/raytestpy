#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Core>
#include <Eigen/LU>

#include "stl_parser/parse_stl.h"

using Vector3d = Eigen::Vector3d;
using Matrix3d = Eigen::Matrix3d;

Vector3d to_vector(const stl::point& p){
  return Vector3d(p.x, p.y, p.z);
}

std::vector<double> ray_test(
    const stl::stl_data& mesh, const Vector3d& p_start, const Vector3d& ray_dir){

  std::vector<double> vec;
  Matrix3d m = Matrix3d::Constant(0.0);
  for(const auto& tri: mesh.triangles){
    const auto v1 = to_vector(tri.v1);
    const auto&& v2 = to_vector(tri.v2);
    const auto&& v3 = to_vector(tri.v3);

    const auto&& e1 = v2 - v1;
    const auto&& e2 = v3 - v1;
    m.col(0) = e1;
    m.col(1) = e2;
    m.col(2) = ray_dir;
    const auto result = m.inverse() * (p_start - v1);
    if(0.0 < result(0) && result(0) < 1.0){
      if(0.0 < result(1) && result(1) < 1.0){
        vec.push_back(-result(2));
      }
    }
  }
  return vec;
}

int main(int argc, char* argv[]) {
  std::string stl_file_name = "/home/h-ishida/.predlearn/ycb/002_master_chef_can.stl";

  auto mesh = stl::parse_stl(stl_file_name);
  const auto& vec = ray_test(mesh, Vector3d(0, 0, 1.0), Vector3d(0, 0, -1.0));
  std::cout << vec.size() << std::endl;
  for(const auto& e : vec){
    std::cout << e << std::endl;
  }


  /*
  std::vector<stl::triangle> triangles = info.triangles;
  std::cout << "STL HEADER = " << info.name << std::endl;
  std::cout << "# triangles = " << triangles.size() << std::endl;
  for (auto t : info.triangles) {
    std::cout << t << std::endl;
  }
  */
}
