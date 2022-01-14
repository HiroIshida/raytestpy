#include "raytest.hpp"

using namespace Eigen;

int main(int argc, char* argv[]) {
  std::string stl_file_name = "/home/h-ishida/.predlearn/ycb/002_master_chef_can.stl";
  const auto& vec = raytest::ray_test_expose(stl_file_name, Vector3d(0, 0, 1.0), Vector3d(0, 0, -1.0));
  std::cout << vec.size() << std::endl;
  for(const auto& e : vec){
    std::cout << e << std::endl;
  }
}
