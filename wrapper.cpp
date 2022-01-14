#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>

#include "raytest.hpp"

PYBIND11_MODULE(raytestpy, m) {
  m.doc() = "raytest example";
  m.def("raytest", &raytest::ray_test_expose, "ray test against a mesh");
}
