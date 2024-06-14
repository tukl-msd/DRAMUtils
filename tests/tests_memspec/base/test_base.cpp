#include <gtest/gtest.h>

#include <memory>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <variant>
#include <utility>

#include "DRAMUtils/memspec/MemSpec.h"
#include "DRAMUtils/memspec/standards/MemSpecDDR3.h"

using namespace DRAMUtils;

// TODO change Config::MemSpec namespace to MemSpec
class Memspec_Base_Test : public ::testing::Test {
protected:
    // Test variables
    std::string_view path = "test.json";
    Config::MemSpecContainer writeContainer;
    Config::MemSpecContainer readContainer;

    bool writeContainerToJsonFile()
    {
        std::ofstream file(path.data());
        if(!file.is_open())
            return false;
        nlohmann::json j = writeContainer;
        file << j.dump(4);
        return true;
    }

    bool readContainerFromJsonFile()
    {
        std::ifstream file(path.data());
        if(!file.is_open())
            return false;
        nlohmann::json j;
        file >> j;
        readContainer = j;
        return true;
    }

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(Memspec_Base_Test, Test_0)
{
    using namespace DRAMUtils::Config;
    // Write MemSpecContainer to file
    {
        MemSpecDDR3 memspec;
        memspec.memarchitecturespec = MemArchitectureSpecTypeDDR3{};
        memspec.memoryId = "Test_DDR3";
        memspec.memarchitecturespec.nbrOfRows = 10;
        memspec.memtimingspec = MemTimingSpecDDR3{};
        memspec.memtimingspec.CKE = 11;
        writeContainer.memspec.setVariant(memspec);
        ASSERT_TRUE(writeContainerToJsonFile());
    }
    // Readback container from file
    {
        // Read file
        ASSERT_TRUE(readContainerFromJsonFile());
        auto variant = readContainer.memspec.getVariant();
        // Get variant
        MemSpecDDR3 memspec = std::get<MemSpecDDR3>(variant);
        // MemoryId
        ASSERT_EQ(memspec.memoryId, "Test_DDR3");
        // MemArchitectureSpecType
        ASSERT_EQ(memspec.memarchitecturespec.nbrOfRows, 10);
        // MemTimingSpecType
        ASSERT_EQ(memspec.memtimingspec.CKE, 11);
    }
}
