cmake_minimum_required(VERSION 3.5)
project(OriC50)

set(CMAKE_VERBOSE_MAKEFILE OFF)

message("-- Preprocess in ${PROJECT_SOURCE_DIR}...")
execute_process(COMMAND ${PROJECT_SOURCE_DIR}/preprocess.sh ${PROJECT_SOURCE_DIR})

add_subdirectory(cpp_wrapper)

set(MAIN_SRCS global.c
	c50.c
	construct.c
	formtree.c
	info.c
	discr.c
	contin.c
	subset.c
	prune.c
	p-thresh.c
	trees.c
	siftrules.c
	ruletree.c
	rules.c
	getdata.c
	implicitatt.c
	mcost.c
	confmat.c
	sort.c
	update.c
	attwinnow.c
	classify.c
	formrules.c
	getnames.c
	modelfiles.c
	utility.c
	xval.c
		debug.c)

# Phony target for preprocess
add_custom_target(
	preTarget
	COMMAND sh ${PROJECT_SOURCE_DIR}/preprocess.sh /d/GenInvLearn/C50
	COMMENT "Preprocess in ${PROJECT_SOURCE_DIR}..."
)

add_executable(c5.0dbg ${MAIN_SRCS})
set_target_properties(c5.0dbg PROPERTIES COMPILE_FLAGS "-g -Wall -DVerbOpt -O0 -DDEBUG -DPENALTY")
target_link_libraries(c5.0dbg cpp_wrapper m stdc++)

add_executable(c5.0.dt_entropy c50gt.c)
#add_dependencies(c5.0.dt_entropy preTarget)
set_target_properties(c5.0.dt_entropy PROPERTIES COMPILE_FLAGS "-static-libgcc -static-libstdc++")
target_link_libraries(c5.0.dt_entropy cpp_wrapper m stdc++)

add_executable(c5.0.dt_penalty c50gt.c)
#add_dependencies(c5.0.dt_penalty preTarget)
set_target_properties(c5.0.dt_penalty PROPERTIES COMPILE_FLAGS "-DPENALTY -static-libgcc -static-libstdc++")
target_link_libraries(c5.0.dt_penalty cpp_wrapper m stdc++)

