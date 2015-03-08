cmake_minimum_required (VERSION 2.6)

project (Jeshim)
set (JESH_VERSION_MAJOR 0)
set (JESH_VERSION_MINOR 1)
set (EXECUTABLE_NAME "jeshim")

# Compile Flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -Weverything -g -std=c++11 -Wno-c++98-compat -Wno-c++11-extensions -Wno-padded -Wno-c++98-compat -Wno-c++98-compat-pedantic")
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(engine)
add_subdirectory(geometry)
add_subdirectory(physics)
add_subdirectory(util)

add_executable(${EXECUTABLE_NAME}
  game.cc
  gamestate.cc
  jeshim.cc
)
target_link_libraries(${EXECUTABLE_NAME} physics geometry engine)

# Include SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Include Boost
set (Boost_STATIC_LIBRARIES TRUE)
find_package(Boost 1.5.7 REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
