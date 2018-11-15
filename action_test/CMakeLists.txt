cmake_minimum_required(VERSION 2.8.3)
project(action_test)

set(PACKAGE_DEPENDS
  roscpp
  std_msgs
  actionlib
  actionlib_msgs
  control_msgs
)

find_package(catkin REQUIRED COMPONENTS ${PACKAGE_DEPENDS} message_generation)

catkin_package(
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS ${PACKAGE_DEPENDS}
  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(server src/server.cpp)
target_link_libraries(server ${catkin_LIBRARIES})
add_dependencies(server ${catkin_EXPORTED_TARGETS})

add_executable(client src/client.cpp)
target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client ${catkin_EXPORTED_TARGETS})

file(GLOB_RECURSE SCRIPT_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/script ${CMAKE_CURRENT_SOURCE_DIR}/script/*)
execute_process(COMMAND chmod +x ${SCRIPT_FILES} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/script)

