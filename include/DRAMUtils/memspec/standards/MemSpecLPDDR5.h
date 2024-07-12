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

#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR5_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR5_H

#include <string_view>
#include <string>
#include <optional>

#include "DRAMUtils/util/json.h"
#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemArchitectureSpecTypeLPDDR5
{
    uint64_t nbrOfDevices;
    uint64_t nbrOfChannels;
    uint64_t nbrOfRanks;
    uint64_t nbrOfBanks;
    uint64_t nbrOfBankGroups;
    uint64_t nbrOfRows;
    uint64_t nbrOfColumns;
    uint64_t burstLength;
    uint64_t dataRate;
    uint64_t width;
    uint64_t per2BankOffset;
    bool     WCKalwaysOn;
    std::optional<uint64_t> maxBurstLength;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemArchitectureSpecTypeLPDDR5, nbrOfDevices, nbrOfChannels, nbrOfRanks, nbrOfBanks, nbrOfBankGroups, nbrOfRows, nbrOfColumns, burstLength, dataRate, width, per2BankOffset, WCKalwaysOn, maxBurstLength)

struct MemImpedanceSpecTypeLPDDR5
{
    double C_total_cb;
    double C_total_ck;
    double C_total_wck;
    double C_total_dqs;
    double C_total_rb;
    double C_total_wb;

    double R_eq_cb;
    double R_eq_ck;
    double R_eq_wck;
    double R_eq_dqs;
    double R_eq_rb;
    double R_eq_wb;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemImpedanceSpecTypeLPDDR5, C_total_cb, C_total_ck, C_total_wck, C_total_dqs, C_total_rb, C_total_wb, R_eq_cb, R_eq_ck, R_eq_wck, R_eq_dqs, R_eq_rb, R_eq_wb)

struct MemTimingSpecTypeLPDDR5
{
    double      tCK;
    uint64_t    REFI;
    uint64_t    REFIpb;
    uint64_t    RFCab;
    uint64_t    RFCpb;
    uint64_t    RAS;
    uint64_t    RPab;
    uint64_t    RPpb;
    uint64_t    RCpb;
    uint64_t    RCab;
    uint64_t    PPD;
    uint64_t    RCD;
    uint64_t    RCD_L;  // TODO
    uint64_t    RCD_S;  // TODO
    uint64_t    FAW;
    uint64_t    RRD;
    uint64_t    RL;
    uint64_t    RBTP;
    uint64_t    WL;
    uint64_t    WR;
    uint64_t    RTRS;
    uint64_t    BL_n_min_16;
    uint64_t    BL_n_max_16;
    uint64_t    BL_n_L_16;
    uint64_t    BL_n_S_16;
    uint64_t    BL_n_min_32;
    uint64_t    BL_n_max_32;
    uint64_t    BL_n_L_32;
    uint64_t    BL_n_S_32;
    uint64_t    WTR_L;
    uint64_t    WTR_S;
    uint64_t    WCK2DQO;
    uint64_t    WCKtoCK;
    uint64_t    pbR2act;
    uint64_t    pbR2pbR;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemTimingSpecTypeLPDDR5, tCK, REFI, REFIpb, RFCab, RFCpb, RAS, RPab, RPpb, RCpb, RCab, PPD, RCD, RCD_L, RCD_S, FAW, RRD, RL, RBTP, WL, WR, RTRS, BL_n_min_16, BL_n_max_16, BL_n_L_16, BL_n_S_16, BL_n_min_32, BL_n_max_32, BL_n_L_32, BL_n_S_32, WTR_L, WTR_S, WCK2DQO, WCKtoCK, pbR2act, pbR2pbR)

struct BankWiseSpecTypeLPDDR5
{
    std::optional<double>   factRho;
};
NLOHMANN_JSONIFY_ALL_THINGS(BankWiseSpecTypeLPDDR5, factRho)

struct MemPowerSpecTypeLPDDR5
{
    double vdd1;
    double idd01;
    double idd2n1;
    double idd3n1;
    double idd4r1;
    double idd4w1;
    double idd51;
    double idd5pb1;
    double idd61;
    double idd6ds1;
    double idd2p1;
    double idd3p1;
    
    double vdd2h;
    double idd02h;
    double idd2n2h;
    double idd3n2h;
    double idd4r2h;
    double idd4w2h;
    double idd52h;
    double idd5pb2h;
    double idd62h;
    double idd6ds2h;
    double idd2p2h;
    double idd3p2h;
    
    double vdd2l;
    double idd02l;
    double idd2n2l;
    double idd3n2l;
    double idd4r2l;
    double idd4w2l;
    double idd52l;
    double idd5pb2l;
    double idd62l;
    double idd6ds2l;
    double idd2p2l;
    double idd3p2l;

    double vddq;

    std::optional<double> iBeta_vdd1;
    std::optional<double> iBeta_vdd2h;
    std::optional<double> iBeta_vdd2l;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemPowerSpecTypeLPDDR5, vdd1, idd01, idd2n1, idd3n1, idd4r1, idd4w1, idd51, idd5pb1, idd61, idd6ds1, idd2p1, idd3p1, vdd2h, idd02h, idd2n2h, idd3n2h, idd4r2h, idd4w2h, idd52h, idd5pb2h, idd62h, idd6ds2h, idd2p2h, idd3p2h, vdd2l, idd02l, idd2n2l, idd3n2l, idd4r2l, idd4w2l, idd52l, idd5pb2l, idd62l, idd6ds2l, idd2p2l, idd3p2l, vddq, iBeta_vdd1, iBeta_vdd2h, iBeta_vdd2l)

struct MemSpecLPDDR5 : BaseMemSpec
{
    static constexpr inline const std::string_view id = "LPDDR5";
    std::string memoryId;

    MemArchitectureSpecTypeLPDDR5 memarchitecturespec;
    MemPowerSpecTypeLPDDR5 mempowerspec;
    MemTimingSpecTypeLPDDR5 memtimingspec;
    std::optional<BankWiseSpecTypeLPDDR5> bankwisespec;
    MemImpedanceSpecTypeLPDDR5 memimpedancespec;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecLPDDR5, memoryId, memarchitecturespec, mempowerspec, memtimingspec, bankwisespec, memimpedancespec)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR5_H */
