cmake_minimum_required(VERSION 3.20)

# プロジェクト名
project(JsonPencil CXX)

# c++の設定
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 実行結果の出力先
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SOURCES 
    src/*.cpp)

add_executable(app ${SOURCES})

target_include_directories(app PRIVATE include)