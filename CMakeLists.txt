cmake_minimum_required(VERSION 3.22)

set(LIBRARY_NAME HelloLib)
set(LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello)

file(GLOB SOURCES ${LIBRARY_PATH}/src/*.cpp)
file(GLOB HEADERS ${LIBRARY_PATH}/include/*.h)
add_library(${LIBRARY_NAME} ${SOURCES} ${HEADERS})
IF(CMAKE_BUILD_TYPE MATCHES Release)
  target_compile_options(${LIBRARY_NAME} PRIVATE -O3 -DNDEBUG)
ENDIF()
target_include_directories(${LIBRARY_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:${LIBRARY_PATH}/include>
    $<BUILD_INTERFACE:${LIBRARY_PATH}/include>
  PRIVATE
    ${LIBRARY_PATH}/src
)

# Main
add_executable(main main.cpp)
IF(CMAKE_BUILD_TYPE MATCHES Release)
  target_compile_options(main PRIVATE -O3 -DNDEBUG)
ENDIF()
target_link_libraries(main
  PRIVATE
    ${LIBRARY_NAME}
)
