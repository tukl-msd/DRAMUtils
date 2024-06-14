#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECGDDR5X_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECGDDR5X_H

#include <string_view>
#include <string>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemSpecGDDR5X : BaseMemSpec
{
    static constexpr inline const std::string_view id = "GDDR5X";
    std::string memoryId;

};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecGDDR5X, memoryId)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECGDDR5X_H */
