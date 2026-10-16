cmake_minimum_required(VERSION 4.3)
project(lignd)

set(CMAKE_CXX_STANDARD 23)

add_library(ecs STATIC
        ecs/entity.cc
        ecs/entity.h)