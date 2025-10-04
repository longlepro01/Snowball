cmake_minimum_required(VERSION 3.10)
project(Snowball)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(nlohmann_json 3.11.2 REQUIRED)
add_executable(Snowball main.cpp)
target_link_libraries(Snowball PRIVATE nlohmann_json::nlohmann_json)
