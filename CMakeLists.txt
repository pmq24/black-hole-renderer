cmake_minimum_required(VERSION 4.2.1)

set(CMAKE_CXX_COMPILER g++)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
	bhr
	LANGUAGES CXX
)

add_executable(bhr)

set_property(
	TARGET bhr
	PROPERTY CXX_STANDARD 17
)

target_sources(
	bhr
	PRIVATE
		src/main.cpp
)
