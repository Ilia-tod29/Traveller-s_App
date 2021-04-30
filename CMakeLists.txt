cmake_minimum_required(VERSION 3.19)
project(Traveller_s_App)

set(CMAKE_CXX_STANDARD 14)

add_executable(Traveller_s_App main.cpp User.cpp User.h Authorization.cpp Authorization.h Journey.cpp Journey.h String.cpp String.h Vector.h)