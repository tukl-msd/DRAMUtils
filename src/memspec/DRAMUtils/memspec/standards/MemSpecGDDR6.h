#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECGDDR6_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECGDDR6_H

#include <string_view>
#include <string>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemSpecGDDR6 : BaseMemSpec
{
    static constexpr inline const std::string_view id = "GDDR6";
    std::string memoryId;

};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecGDDR6, memoryId)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECGDDR6_H */
