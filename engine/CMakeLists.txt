set (engine_source_files
  enemy.cc
  enemyview.cc
  entity.cc
  fixedtile.cc
  level.cc
  levelstate.cc
  levelview.cc
  player.cc
  playerview.cc
  singlespriteview.cc
  slime.cc
  sprite.cc
  sword.cc
  swordview.cc
  tile.cc
)
add_library(engine ${engine_source_files})
