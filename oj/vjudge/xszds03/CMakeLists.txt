# CMakeList.txt : CMake project for xszds03, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("main")

# Add source to this project's executable.
add_executable (A A.cpp)
add_executable (B B.cpp)
add_executable (C C.cpp)
# TODO: Add tests and install targets if needed.
