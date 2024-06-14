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

#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECDDR4_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECDDR4_H

#include <string_view>
#include <string>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemArchitectureSpecTypeDDR4
{
    uint64_t nbrOfRows;
    uint64_t nbrOfColumns;
    uint64_t burstLength;
    uint64_t dataRate;
    uint64_t width;
    std::optional<uint64_t> maxBurstLength;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemArchitectureSpecTypeDDR4, nbrOfRows, nbrOfColumns, burstLength, dataRate, width, maxBurstLength)

struct MemTimingSpecDDR4
{
    double      tCK;
    uint64_t    CKE;
    uint64_t    CKESR;
    uint64_t    RAS;
    uint64_t    RC;
    uint64_t    RCD;
    uint64_t    RL;
    uint64_t    RPRE;
    uint64_t    RTP;
    uint64_t    WL;
    uint64_t    WPRE;
    uint64_t    WR;
    uint64_t    XP;
    uint64_t    XS;
    uint64_t    REFM;
    uint64_t    REFI;
    uint64_t    RFC;    // TODO different in DRAMSys DRAMPower
    uint64_t    RFC1;   // TODO different in DRAMSys DRAMPower
    uint64_t    RFC2;
    uint64_t    RFC4;
    uint64_t    RP;
    uint64_t    DQSCK;
    uint64_t    CCD_S;
    uint64_t    CCD_L;
    uint64_t    FAW;
    uint64_t    RRD_S;
    uint64_t    RRD_L;
    uint64_t    WTR_S;
    uint64_t    WTR_L;
    uint64_t    XPDLL;
    uint64_t    XSDLL;
    uint64_t    AL;
    uint64_t    ACTPDEN;
    uint64_t    PRPDEN;
    uint64_t    REFPDEN;
    uint64_t    RTRS;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemTimingSpecDDR4, tCK, CKE, CKESR, RAS, RC, RCD, RL, RTP, WL, WPRE, WR, XP, XS, REFM, REFI, RFC, RFC1, RFC2, RFC4, RP, DQSCK, CCD_S, CCD_L, FAW, RRD_S, RRD_L, WTR_S, WTR_L, XPDLL, XSDLL, AL, ACTPDEN, PRPDEN, REFPDEN, RTRS)

struct MemPowerSpecDDR4
{
    double vdd;
    double idd0;
    double idd2n;
    double idd3n;
    double idd4r;
    double idd4w;
    double idd6n;
    double idd2p;
    double idd3p;

    double vpp;
    double ipp0;
    double ipp2n;
    double ipp3n;
    double ipp4r;
    double ipp4w;
    double ipp6;
    double ipp2p;
    double ipp3p;
    
    // refreshMode==1
    double idd5B;
    double ipp5B;
    
    // refreshMode==2
    double idd5F2;
    double ipp5F2;
    
    // refreshMode!=1 && refreshMode!=2
    double idd5F4;
    double ipp5F4;
    
    std::optional<double> iBeta;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemPowerSpecDDR4, vdd, idd0, idd2n, idd3n, idd4r, idd4w, idd6n, idd2p, idd3p, vpp, ipp0, ipp2n, ipp3n, ipp4r, ipp4w, ipp6, ipp2p, ipp3p, idd5B, ipp5B, idd5F2, ipp5F2, idd5F4, ipp5F4, iBeta)

struct BankWiseSpecDDR4
{
    double factRho;
};
NLOHMANN_JSONIFY_ALL_THINGS(BankWiseSpecDDR4, factRho)

struct MemSpecDDR4 : BaseMemSpec
{
    static constexpr inline const std::string_view id = "DDR4";
    std::string memoryId;
    
    uint64_t RefreshMode = 1;
    MemArchitectureSpecTypeDDR4 memarchitecturespec;
    MemPowerSpecDDR4 mempowerspec;
    MemTimingSpecDDR4 memtimingspec;
    BankWiseSpecDDR4 bankwisespec;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecDDR4, memoryId, memarchitecturespec, mempowerspec, memtimingspec, bankwisespec)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECDDR4_H */
