cmake_minimum_required(VERSION 3.0.0)
project(sock VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)

include(ExternalProject)

ExternalProject_Add(
  URI
  GIT_REPOSITORY  https://github.com/cpp-netlib/uri.git
  PREFIX          ${CMAKE_CURRENT_BINARY_DIR}/deps/uri
  INSTALL_DIR     ${CMAKE_CURRENT_BINARY_DIR}
  CMAKE_GENERATOR "MinGW Makefiles"
  CMAKE_ARGS      -DCMAKE_SH=CMAKE_SH-NOTFOUND
                  -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
                  -DUri_BUILD_TESTS=OFF
                  -DUri_BUILD_DOCS=OFF
)

add_executable(sock main.cpp)

add_dependencies(sock URI)
target_link_libraries(sock network-uri wsock32 ws2_32)
