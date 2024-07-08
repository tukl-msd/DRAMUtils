/*
 * Copyright (c) 2024, RPTU Kaiserslautern-Landau
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors:
 *    Marco Mörz
 */

#ifndef DRAMUTILS_MEMSPEC_MEMSPEC_H
#define DRAMUTILS_MEMSPEC_MEMSPEC_H

#include <string>
#include <variant>
#include "DRAMUtils/util/util.h"
#include "DRAMUtils/util/json.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include "DRAMUtils/util/types.h"
#include "DRAMUtils/util/id_variant.h"

#include "standards/MemSpecDDR3.h"
#include "standards/MemSpecDDR4.h"
#include "standards/MemSpecDDR5.h"
#include "standards/MemSpecLPDDR4.h"
#include "standards/MemSpecLPDDR5.h"
#include "standards/MemSpecWideIO.h"
#include "standards/MemSpecWideIO2.h"
#include "standards/MemSpecGDDR5.h"
#include "standards/MemSpecGDDR5X.h"
#include "standards/MemSpecGDDR6.h"
#include "standards/MemSpecHBM2.h"
#include "standards/MemSpecHBM3.h"
#include "standards/MemSpecSTTMRAM.h"

DEFINE_HAS_MEMBER(memoryType) // Required by util::IdVariant
namespace DRAMUtils::Config
{

// Variant types
using VariantTypes = util::type_sequence<
    MemSpecDDR3,
    MemSpecDDR4,
    MemSpecDDR5,
    MemSpecLPDDR4,
    MemSpecLPDDR5,
    MemSpecWideIO,
    MemSpecWideIO2,
    MemSpecGDDR5,
    MemSpecGDDR5X,
    MemSpecGDDR6,
    MemSpecHBM2,
    MemSpecHBM3,
    MemSpecSTTMRAM
>;

// util::MemSpecContainerIdName::name defined by DEFINE_HAS_MEMBER
using MemSpecVariant = util::IdVariant<util::memoryType::name, VariantTypes>;

// Simple MemSpecContainer
struct MemSpecContainer
{
    DRAMUtils::Config::MemSpecVariant memspec;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecContainer, memspec)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_MEMSPEC_H */
