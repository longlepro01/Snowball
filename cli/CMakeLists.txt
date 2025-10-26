cmake_minimum_required(VERSION 3.10)
project(Snowball)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(include)

# Find JSON library
find_package(nlohmann_json 3.10.5 REQUIRED)

# Add all source files
add_executable(snowball
    src/main.cpp
    src/helpers/data_manager.cpp
    src/helpers/utils.cpp
    src/screens/ui.cpp
    src/screens/dashboard.cpp
    src/screens/add_goal.cpp
    src/screens/view_goals.cpp
    src/screens/random_task.cpp
)

# Link libraries
target_link_libraries(snowball PRIVATE nlohmann_json::nlohmann_json)
