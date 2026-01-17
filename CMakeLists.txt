cmake_minimum_required(VERSION 4.2.1)

project(
	bhr
	LANGUAGES CXX
)

add_executable(bhr)

target_sources(
	bhr
	PRIVATE
		src/main.cpp
)
