cmake_minimum_required (VERSION 3.8)

project(LuaSolRepro LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (UNIX AND NOT APPLE)
    add_definitions( -DLUA_USE_POSIX )
endif()
file(GLOB_RECURSE LUA_SRC lua/*.c)
list(REMOVE_ITEM LUA_SRC "${CMAKE_SOURCE_DIR}/lua/lua.c")
list(REMOVE_ITEM LUA_SRC "${CMAKE_SOURCE_DIR}/lua/luac.c")
add_library(lua ${LUA_SRC})
set_target_properties(lua PROPERTIES LINKER_LANGUAGE C)

add_executable(luaSolRepro main.cpp sol.hpp)

include_directories(lua/)

target_link_libraries(luaSolRepro lua)
