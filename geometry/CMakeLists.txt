set (geometry_source_files
  dimensions.cc
  dimensions.hh
  point.cc
  point.hh
  rectangle.cc
  rectangle.hh
  vector.cc
  vector.hh
)
add_library(geometry ${geometry_source_files})
