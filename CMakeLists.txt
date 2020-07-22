cmake_minimum_required(VERSION 3.11)

set(EXEC_NAME gameOfLife)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories(${SFML_INCLUDE_DIRS})

# when adding src add them here
set(SOURCES
  src/main.cpp
  src/Board.cpp
  src/Error.cpp
  src/Game.cpp
  src/HelpButton.cpp
  src/StartupAnimation.cpp
  src/Toolbar.cpp
  )

set(CMAKE_CXX_STANDARD 11)
project(${EXEC_NAME})

find_package(SFML 2.4 REQUIRED graphics window system)

add_executable(${EXEC_NAME} ${SOURCES})
target_link_libraries(${EXEC_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
