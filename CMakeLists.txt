cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(metamod CXX)

if(NOT ANDROID)
	message(FATAL_ERROR "Android only: pass -DCMAKE_TOOLCHAIN_FILE=<NDK>/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a or armeabi-v7a")
endif()

add_subdirectory(metamod)
