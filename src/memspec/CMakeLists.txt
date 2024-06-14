########################################
###             DRAMUtils            ###
########################################

project(DRAMUtils)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.h;*.hpp)

add_library(DRAMUtils ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(DRAMUtils PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(DRAMUtils PUBLIC 
	nlohmann_json::nlohmann_json
    DRAMUtils::util
)

add_library(DRAMSys::DRAMUtils ALIAS DRAMUtils)

build_source_group()