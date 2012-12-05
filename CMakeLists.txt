cmake_minimum_required(VERSION 2.8.3)
project(rosconsole_bridge)

find_package(catkin REQUIRED COMPONENTS console_bridge rosconsole)

include_directories(include ${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

catkin_package(
  LIBRARIES ${PROJECT_NAME}
  INCLUDE_DIRS include
  CATKIN_DEPENDS console_bridge rosconsole
)

add_library(${PROJECT_NAME} src/bridge.cpp)

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

install(
  DIRECTORY include/
  DESTINATION include
  FILES_MATCHING PATTERN "*.h"
)
