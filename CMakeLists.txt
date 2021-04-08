cmake_minimum_required(VERSION 3.10)

project(Remesher)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ext)

find_package(Threads REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
	# libigl
	${EXT_DIR}/libigl/include
	)

add_executable(remeshmesh

	# Headers
	src/collapse_edges.h
	src/equalize_valences.h
	src/remesh_botsch.h
	src/split_edges.h
	src/split_edges_until_bound.h
	src/tangential_relaxation.h

	# Source
	remeshmesh.cpp
	src/collapse_edges.cpp
	src/equalize_valences.cpp
	src/remesh_botsch.cpp
	src/split_edges.cpp
	src/split_edges_until_bound.cpp
	src/tangential_relaxation.cpp

	)


target_link_libraries(remeshmesh Threads::Threads Eigen3::Eigen)
