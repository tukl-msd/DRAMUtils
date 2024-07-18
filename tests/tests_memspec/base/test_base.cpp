#include <gtest/gtest.h>

#include <memory>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <variant>
#include <utility>
#include <filesystem>

#include "DRAMUtils/util/json.h"
#include "DRAMUtils/memspec/MemSpec.h"
#include "DRAMUtils/memspec/standards/MemSpecDDR3.h"

using namespace DRAMUtils;

// TODO change Config::MemSpec namespace to MemSpec
class Memspec_Base_Test : public ::testing::Test {
protected:
    // Test variables
    std::string_view path = TEST_RESOURCE_DIR "test.json";
    MemSpec::MemSpecContainer writeContainer;
    MemSpec::MemSpecContainer readContainer;

    bool writeContainerToJsonFile()
    {
        std::ofstream file(path.data());
        if(!file.is_open())
            return false;
        json_t j = writeContainer;
        file << j.dump(4);
        file.close();
        return true;
    }

    bool readContainerFromJsonFile()
    {
        std::ifstream file(path.data());
        if(!file.is_open())
            return false;
        json_t j;
        file >> j;
        file.close();
        readContainer = j;
        return true;
    }

    MemSpec::MemSpecVariant createDummyMemSpec()
    {
        MemSpec::MemSpecDDR3 memspec;
        memspec.memarchitecturespec = MemSpec::MemArchitectureSpecTypeDDR3{};
        memspec.memoryId = "Test_DDR3";
        memspec.memarchitecturespec.nbrOfRows = 10;
        memspec.memtimingspec = MemSpec::MemTimingSpecDDR3{};
        memspec.memtimingspec.CKE = 11;
        MemSpec::MemSpecVariant variant;
        variant.setVariant(memspec);
        return variant;
    }
    
    void compareMemSpec(MemSpec::MemSpecVariant& variant)
    {
        MemSpec::MemSpecDDR3 memspec = std::get<MemSpec::MemSpecDDR3>(variant.getVariant());
        ASSERT_EQ(memspec.memoryId, "Test_DDR3");
        ASSERT_EQ(memspec.memarchitecturespec.nbrOfRows, 10);
        ASSERT_EQ(memspec.memtimingspec.CKE, 11);
    }

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(Memspec_Base_Test, IDVariant)
{
    writeContainer.memspec = createDummyMemSpec();
    ASSERT_TRUE(writeContainerToJsonFile());
    ASSERT_TRUE(readContainerFromJsonFile());
    compareMemSpec(readContainer.memspec);
}

TEST_F(Memspec_Base_Test, HelperFunctions)
{
    using namespace DRAMUtils::MemSpec;
    std::optional<MemSpecVariant> variant_in;
    MemSpecVariant variant_out;
    json_t j_out, j_in;
    std::ifstream file_in;
    std::ofstream file_out;

    // Write MemSpecContainer to file
    writeContainer.memspec = createDummyMemSpec();
    ASSERT_TRUE(writeContainerToJsonFile());

    // Read from file
    variant_in = parse_memspec_from_file(std::filesystem::path(path));
    ASSERT_TRUE(variant_in.has_value());
    compareMemSpec(*variant_in);

    // Read from buffer
    file_in = std::ifstream(path.data());
    ASSERT_TRUE(file_in.is_open());
    std::string buffer((std::istreambuf_iterator<char>(file_in)), std::istreambuf_iterator<char>());
    variant_in = parse_Memspec_from_buffer(buffer);
    ASSERT_TRUE(variant_in.has_value());
    compareMemSpec(*variant_in);

    // Read from json
    file_in = std::ifstream(path.data());
    ASSERT_TRUE(file_in.is_open());
    j_in = json_t::parse(file_in);
    variant_in = parse_memspec_from_json(j_in);
    ASSERT_TRUE(variant_in.has_value());
    compareMemSpec(*variant_in);

    // Read from json with different key
    variant_out = createDummyMemSpec();
    file_out = std::ofstream(path.data());
    ASSERT_TRUE(file_out.is_open());
    j_out.clear();
    j_out["test"] = variant_out;
    file_out << j_out.dump(4);
    file_out.close();
    variant_in = parse_memspec_from_file(std::filesystem::path(path), "test");
    // Get variant
    ASSERT_TRUE(variant_in.has_value());
    compareMemSpec(*variant_in);

    // Read from json with no key (std::nullopt)
    variant_out = createDummyMemSpec();
    file_out = std::ofstream(path.data());
    ASSERT_TRUE(file_out.is_open());
    j_out.clear();
    j_out = variant_out;
    file_out << j_out.dump(4);
    file_out.close();
    variant_in = parse_memspec_from_file(std::filesystem::path(path), std::nullopt);
    ASSERT_TRUE(variant_in.has_value());
    compareMemSpec(*variant_in);

    // Test exception with invalid json
    variant_out = createDummyMemSpec();
    file_out = std::ofstream(path.data());
    ASSERT_TRUE(file_out.is_open());
    j_out.clear();
    j_out = variant_out;
    // remove memarchitecturespec.nbrOfRows
    j_out["memarchitecturespec"].erase("nbrOfRows");
    file_out << j_out.dump(4);
    file_out.close();
    ASSERT_THROW(parse_memspec_from_file(std::filesystem::path(path), std::nullopt), json_t::out_of_range);
}
