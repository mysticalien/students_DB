cmake_minimum_required(VERSION 3.24)
project(my_project)

# Add your source files
set(SOURCES
        src/main.c
        src/check.c
        src/parse.c
        src/read.c
        src/free_malloc.c
        src/print.c
        src/display.c
        src/change_db.c
        src/students.h)

# Find the Jansson package using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(JANSSON REQUIRED jansson)

# Add the Jansson include directory to the project
include_directories(${JANSSON_INCLUDE_DIRS})

# Add your executable
add_executable(my_project ${SOURCES})

# Link the Jansson library to your executable
target_link_libraries(my_project PUBLIC /usr/local/Cellar/jansson/2.14/lib/libjansson.a)
