add_library(DRAMUtils INTERFACE)
target_include_directories(DRAMUtils INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_features(DRAMUtils INTERFACE cxx_std_17)
set_target_properties(DRAMUtils PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(DRAMUtils PROPERTIES CXX_STANDARD_REQUIRED ON)

target_sources(DRAMUtils
PUBLIC
    FILE_SET api
TYPE HEADERS
FILES
    DRAMUtils/config/toggling_rate.h
    DRAMUtils/memspec/MemSpec.h
    DRAMUtils/memspec/standards/MemSpecDDR3.h
    DRAMUtils/memspec/standards/MemSpecDDR4.h
    DRAMUtils/memspec/standards/MemSpecDDR5.h
    DRAMUtils/memspec/standards/MemSpecGDDR5.h
    DRAMUtils/memspec/standards/MemSpecGDDR5X.h
    DRAMUtils/memspec/standards/MemSpecGDDR6.h
    DRAMUtils/memspec/standards/MemSpecHBM2.h
    DRAMUtils/memspec/standards/MemSpecHBM3.h
    DRAMUtils/memspec/standards/MemSpecHBM4.h
    DRAMUtils/memspec/standards/MemSpecLPDDR4.h
    DRAMUtils/memspec/standards/MemSpecLPDDR5.h
    DRAMUtils/memspec/standards/MemSpecLPDDR6.h
    DRAMUtils/memspec/standards/MemSpecSTTMRAM.h
    DRAMUtils/memspec/standards/MemSpecWideIO.h
    DRAMUtils/memspec/standards/MemSpecWideIO2.h
    DRAMUtils/util/collapsingvector.h
    DRAMUtils/util/id_variant.h
    DRAMUtils/util/json.h
    DRAMUtils/util/json_utils.h
    DRAMUtils/util/types.h
)

install(TARGETS DRAMUtils FILE_SET api)

target_link_libraries(DRAMUtils
    INTERFACE
        nlohmann_json::nlohmann_json
)

add_library(DRAMUtils::DRAMUtils ALIAS DRAMUtils)
