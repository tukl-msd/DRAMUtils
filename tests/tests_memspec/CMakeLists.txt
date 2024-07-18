###############################################
###               tests_memspec             ###
###############################################

cmake_minimum_required(VERSION 3.1.0)

project(tests_memspec)

file(GLOB_RECURSE SOURCE_FILES base/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_compile_definitions(${PROJECT_NAME} PUBLIC TEST_RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/temp/")
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}
    gtest_main
    DRAMSys::DRAMUtils
)

gtest_discover_tests(${PROJECT_NAME})