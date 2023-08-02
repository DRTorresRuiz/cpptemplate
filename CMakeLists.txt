cmake_minimum_required(VERSION 3.22)

set(LIBRARY_NAME HelloLib)
set(LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
  hello
  VERSION 0.1.0
  DESCRIPTION "Hello world library. C++ Template."
  LANGUAGES CXX
)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.0.0
)
FetchContent_MakeAvailable(fmt)

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
    fmt::fmt-header-only
)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
  enable_testing()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs --coverage")
  file(GLOB TEST_SOURCES ${LIBRARY_PATH}/tests/*.cpp)
  
  find_package(GTest)

  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  add_executable(tests ${TEST_SOURCES})
  target_link_libraries(tests
    PRIVATE
      ${LIBRARY_NAME}
      GTest::gtest
      GTest::gtest_main
      gcov
  )

  include(GoogleTest)
  gtest_discover_tests(tests)
ENDIF()