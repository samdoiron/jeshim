set(physics_source_files
  basiccollisionsystem.cc
  basiccollisionsystem.hh
  collidable.cc
  collidable.hh
  collisionsystem.cc
  collisionsystem.hh
  gridcollisionsystem.cc
  gridcollisionsystem.hh
)
add_library(physics ${physics_source_files})
