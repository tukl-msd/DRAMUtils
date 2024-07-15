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

#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECHBM2_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECHBM2_H

#include <string_view>
#include <string>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::MemSpec {

struct MemArchitectureSpecTypeHBM2
{
    uint64_t nbrOfRows;
    uint64_t nbrOfColumns;
    uint64_t burstLength;
    std::optional<uint64_t> maxBurstLength;
    uint64_t dataRate;
    uint64_t width;
    uint64_t nbrOfChannels;
    uint64_t nbrOfPseudoChannels;
    uint64_t nbrOfDevices;
    uint64_t nbrOfBanks;
    uint64_t nbrOfBankGroups;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemArchitectureSpecTypeHBM2, nbrOfRows, nbrOfColumns, burstLength, maxBurstLength, dataRate, width, nbrOfChannels, nbrOfPseudoChannels, nbrOfDevices, nbrOfBanks, nbrOfBankGroups)

struct MemTimingSpecTypeHBM2
{
    double      tCK;
    uint64_t    DQSCK;
    uint64_t    RC;
    uint64_t    RAS;
    uint64_t    RCDRD;
    uint64_t    RCDWR;
    uint64_t    RRDL;
    uint64_t    RRDS;
    uint64_t    FAW;
    uint64_t    RTP;
    uint64_t    RP;
    uint64_t    RL;
    uint64_t    WL;
    uint64_t    PL;
    uint64_t    WR;
    uint64_t    CCDL;
    uint64_t    CCDS;
    uint64_t    WTRL;
    uint64_t    WTRS;
    uint64_t    RTW;
    uint64_t    XP;
    uint64_t    CKE;
    uint64_t    XS;
    uint64_t    RFC;
    uint64_t    RFCSB;
    uint64_t    RREFD;
    uint64_t    REFI;
    uint64_t    REFISB;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemTimingSpecTypeHBM2, tCK, DQSCK, RC, RAS, RCDRD, RCDWR, RRDL, RRDS, FAW, RTP, RP, RL, WL, PL, WR, CCDL, CCDS, WTRL, WTRS, RTW, XP, CKE, XS, RFC, RFCSB, RREFD, REFI, REFISB)

struct MemSpecHBM2 : BaseMemSpec
{
    static constexpr inline const std::string_view id = "HBM2";
    std::string memoryId;

    MemArchitectureSpecTypeHBM2 memarchitecturespec;
    MemTimingSpecTypeHBM2 memtimingspec;

};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecHBM2, memoryId, memarchitecturespec, memtimingspec)

} // namespace DRAMUtils::MemSpec

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECHBM2_H */
