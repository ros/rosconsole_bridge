cmake_minimum_required(VERSION 2.8)
project(rosconsole_bridge)

find_package(catkin REQUIRED)
catkin_stack()

catkin_project(${PROJECT_NAME}
  LIBRARIES ${PROJECT_NAME}
  INCLUDE_DIRS include
  )

find_package(ROS REQUIRED COMPONENTS rosconsole)
include_directories(${ROS_INCLUDE_DIRS})

find_package(console_bridge REQUIRED)
include_directories(${console_bridge_INCLUDE_DIR})
include_directories(include)

add_library(${PROJECT_NAME}
  src/bridge.cpp)

target_link_libraries(${PROJECT_NAME} ${console_bridge_LIBRARIES} ${ROS_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(DIRECTORY include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")

# for compatibility with old build system
install(FILES manifest.xml
        DESTINATION share/${PROJECT_NAME})

