#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR5_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR5_H

#include <string_view>
#include <string>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemSpecLPDDR5 : BaseMemSpec
{
    static constexpr inline const std::string_view id = "LPDDR5";
    std::string memoryId;

};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecLPDDR5, memoryId)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR5_H */
