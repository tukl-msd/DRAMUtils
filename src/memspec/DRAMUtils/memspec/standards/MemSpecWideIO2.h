#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECWIDEIO2_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECWIDEIO2_H

#include <string_view>
#include <string>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemSpecWideIO2 : BaseMemSpec
{
    static constexpr inline const std::string_view id = "WIDEIO2";
    std::string memoryId;

};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecWideIO2, memoryId)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECWIDEIO2_H */
