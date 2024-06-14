#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECWIDEIO_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECWIDEIO_H

#include <string_view>
#include <string>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemSpecWideIO : BaseMemSpec
{
    static constexpr inline const std::string_view id = "WIDEIO_SDR";
    std::string memoryId;

};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecWideIO, memoryId)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECWIDEIO_H */
