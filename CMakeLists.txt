cmake_minimum_required(VERSION 4.2.1)

set(CMAKE_CXX_COMPILER g++)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
	bhr
	LANGUAGES CXX C
)

include(FetchContent)



FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 3.4

)

FetchContent_MakeAvailable(glfw)



add_library(glad)

target_sources(
	glad
	PUBLIC
		FILE_SET HEADERS
		FILES
			deps/glad/include/glad/gl.h
			deps/glad/include/KHR/khrplatform.h
	PRIVATE
		deps/glad/src/gl.c
)

include_directories(deps/glad/include)



FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG 1.0.3
)

FetchContent_MakeAvailable(glm)



FetchContent_Declare(
	spdlog
	GIT_REPOSITORY https://github.com/gabime/spdlog.git
	GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(spdlog)

add_executable(bhr)

set_property(
	TARGET bhr
	PROPERTY CXX_STANDARD 17
)

target_sources(
	bhr
	PRIVATE
		src/main.cpp

		src/Layers/BlackHole/Layer.cpp

		src/App.cpp
		src/Window.cpp
)

target_link_libraries(
	bhr
	PRIVATE
		glfw
		glad
		glm::glm
		spdlog::spdlog
)
