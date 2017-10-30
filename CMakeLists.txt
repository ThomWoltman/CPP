cmake_minimum_required(VERSION 3.8)
project(CPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Libs/String.cpp Libs/String.h Libs/StringVector.cpp Libs/StringVector.h Source/Game.cpp Headers/Game.h Source/State/Haven_state.cpp Headers/State/Haven_state.h Source/State/Fight_state.cpp Headers/State/Fight_state.h Source/State/Sea_state.cpp Headers/State/Sea_state.h Source/State/Game_state.cpp Headers/State/Game_state.h Source/Models/Ship.cpp Headers/Models/Ship.h Source/Models/Resource.cpp Headers/Models/Resource.h Source/Models/Player.cpp Headers/Models/Player.h Source/Models/Canon.cpp Headers/Models/Canon.h Source/State/Game_state_context.cpp Headers/State/Game_state_context.h Libs/DestanceReader.cpp Libs/DestanceReader.h Libs/City.cpp Libs/City.h)
add_executable(CPP ${SOURCE_FILES})

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
