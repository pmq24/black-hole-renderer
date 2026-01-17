cmake_minimum_required(VERSION 4.2.1)

set(CMAKE_CXX_COMPILER g++)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
	bhr
	LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 3.4

)

FetchContent_MakeAvailable(
	glfw
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

target_link_libraries(
	bhr
	PRIVATE
		glfw
)
