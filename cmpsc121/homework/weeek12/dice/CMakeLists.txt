cmake_minimum_required(VERSION 3.20) # no ancient bad defaults
project(project) # not that important

add_executable(program main.cpp dice.cpp) # tell cmake to build an executable from these source files
