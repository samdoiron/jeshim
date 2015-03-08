set (engine_source_files
  enemy.cc
  enemy.hh
  entity.cc
  entity.hh
  fixedtile.cc
  fixedtile.hh
  level.cc
  level.hh
  levelstate.cc
  levelstate.hh
  levelview.cc
  levelview.hh
  player.cc
  player.hh
  playerview.cc
  playerview.hh
  singlespriteview.cc
  singlespriteview.hh
  slime.cc
  slime.hh
  sprite.cc
  sprite.hh
  tile.cc
  tile.hh
  tiletype.hh
)
add_library(engine ${engine_source_files})
