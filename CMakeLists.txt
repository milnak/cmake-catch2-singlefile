# cmake -S . -B build [--trace-expand] cmake --build build --config
# RelWithDebInfo
cmake_minimum_required(VERSION 3.5)

function(prepareTestLibrary)
  find_package(Catch2 QUIET)
  if(NOT Catch2_FOUND)
    message(STATUS "Fetching Catch2")
    include(FetchContent)

    FetchContent_Declare(
      CATCH2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG v2.13.8)

    FetchContent_MakeAvailable(Catch2)

    message(STATUS "catch2_SOURCE_DIR: ${catch2_SOURCE_DIR}")

    # For include(Catch)
    list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/contrib")
    message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
  endif()

  include(CTest)
  include(Catch)
endfunction()

project(
  fact
  LANGUAGES CXX
  VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)

preparetestlibrary()

# enable_testing() is essential for ctest to find tests!
enable_testing()

add_executable(${PROJECT_NAME} fact.cpp fact_test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)

catch_discover_tests(${PROJECT_NAME})
