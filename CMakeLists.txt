cmake_minimum_required(VERSION 3.0)
set(CMAKE_GENERATOR "Ninja")
project("Computer-Automation")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
include_directories(include)

set(SOURCES
	main.c
	src/scanner.c
	include/scanner.h
	src/script.c
	include/script.h
	src/x11.c
	include/x11.h
	src/Win32.c
	include/Win32.h
)


add_executable(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib)

