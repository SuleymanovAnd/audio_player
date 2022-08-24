cmake_minimum_required(VERSION 3.22)

set( MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set (SOURCE
        main.cpp
        track.cpp
        player.cpp
        )
set (INCLUDE

        ${MY_INCLUDE}/track.h
        ${MY_INCLUDE}/player.h
        )

add_executable(desktop_window ${INCLUDE} ${SOURCE} )
target_include_directories(desktop_window PUBLIC ${MY_INCLUDE})