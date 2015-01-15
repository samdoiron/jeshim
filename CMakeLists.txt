cmake_minimum_required (VERSION 2.6)

project (Jeshim)

set (EXECUTABLE_NAME "jeshim")

add_executable(${EXECUTABLE_NAME} 
  dimensions.cc
  entity.cc
  event.cc
  eventemitter.cc
  eventlistener.cc
  game.cc
  gamestate.cc
  jeshim.cc
  keypressevent.cc
  keyreleaseevent.cc
  mousemoveevent.cc
  player.cc
  playerview.cc
  point.cc
  rendersurface.cc
  sprite.cc
  teststate.cc
  vector.cc
  view.cc
  window.cc
)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything -O4 -Ofast-math -g -gdwarf-2 -std=c++11 -Wno-c++98-compat -Wno-c++11-extensions -Wno-padded -Wno-c++98-compat -Wno-c++98-compat-pedantic")

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

set (HACK_VERSION_MAJOR 0)
set (HACK_VERSION_MINOR 1)

# Include Boost 
set (Boost_STATIC_LIBRARIES TRUE)
find_package(Boost 1.5.7 REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})

