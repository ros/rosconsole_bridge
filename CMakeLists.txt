cmake_minimum_required(VERSION 2.8)
project(rosconsole_bridge)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS rosconsole)

catkin_package(
  LIBRARIES ${PROJECT_NAME}
  INCLUDE_DIRS include
  )


include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

find_package(console_bridge REQUIRED)
include_directories(${console_bridge_INCLUDE_DIR})
include_directories(include)

add_library(${PROJECT_NAME}
  src/bridge.cpp)

target_link_libraries(${PROJECT_NAME} ${console_bridge_LIBRARIES} ${catkin_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(DIRECTORY include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")

