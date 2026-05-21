/*
 * Copyright (c) 2025, RPTU Kaiserslautern-Landau
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
 *    Thomas Zimmermann
 *    Lukas Steiner
 */

#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR6_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR6_H

#include <optional>
#include <string>
#include <string_view>

#include "DRAMUtils/util/json_utils.h"

namespace DRAMUtils::MemSpec
{

struct MemArchitectureSpecTypeLPDDR6
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
    bool WCKalwaysOn;
    std::optional<uint64_t> maxBurstLength;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemArchitectureSpecTypeLPDDR6,
                            nbrOfDevices,
                            nbrOfChannels,
                            nbrOfRanks,
                            nbrOfBanks,
                            nbrOfBankGroups,
                            nbrOfRows,
                            nbrOfColumns,
                            burstLength,
                            dataRate,
                            width,
                            WCKalwaysOn,
                            maxBurstLength)

struct MemImpedanceSpecTypeLPDDR6
{
    // Clock
    bool ck_termination;
    double ck_R_eq;
    double ck_dyn_E;

    // Commandbus
    bool ca_termination;
    double ca_R_eq;
    double ca_dyn_E;

    // Data bus read
    bool rdq_termination;
    double rdq_R_eq;
    double rdq_dyn_E;
    // Data bus write
    bool wdq_termination;
    double wdq_R_eq;
    double wdq_dyn_E;

    // DQS read
    bool rdqs_termination;
    double rdqs_R_eq;
    double rdqs_dyn_E;
    // WCK
    bool wck_termination;
    double wck_R_eq;
    double wck_dyn_E;

    // DBI read
    bool rdbi_termination;
    double rdbi_R_eq;
    double rdbi_dyn_E;
    // DBI write
    bool wdbi_termination;
    double wdbi_R_eq;
    double wdbi_dyn_E;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemImpedanceSpecTypeLPDDR6,
                            ck_termination,
                            ck_R_eq,
                            ck_dyn_E,
                            ca_termination,
                            ca_R_eq,
                            ca_dyn_E,
                            rdq_termination,
                            rdq_R_eq,
                            rdq_dyn_E,
                            wdq_termination,
                            wdq_R_eq,
                            wdq_dyn_E,
                            rdqs_termination,
                            rdqs_R_eq,
                            rdqs_dyn_E,
                            wck_termination,
                            wck_R_eq,
                            wck_dyn_E,
                            rdbi_termination,
                            rdbi_R_eq,
                            rdbi_dyn_E,
                            wdbi_termination,
                            wdbi_R_eq,
                            wdbi_dyn_E)

struct MemTimingSpecTypeLPDDR6
{
    double tCK;
    uint64_t REFI;
    uint64_t RFCab;
    uint64_t RFCdb;
    uint64_t RAS;
    uint64_t RPab;
    uint64_t RPpb;
    uint64_t RCpb;
    uint64_t RCab;
    uint64_t PPD;
    uint64_t FAW;
    uint64_t RRD;
    uint64_t RL;
    uint64_t RBTP;
    uint64_t WL;
    uint64_t WR;
    uint64_t RTRS;
    uint64_t BL_n_min_24;
    uint64_t BL_n_max_24;
    uint64_t BL_n_L_24;
    uint64_t BL_n_S_24;
    uint64_t BL_n_min_48;
    uint64_t BL_n_max_48;
    uint64_t BL_n_L_48;
    uint64_t BL_n_S_48;
    uint64_t WTR_L;
    uint64_t WTR_S;
    uint64_t WCK2DQO;
    uint64_t WCK2CK;
    uint64_t RTP_24;
    uint64_t RTP_48;
    uint64_t RTW_L_48;
    uint64_t RTW_S_48;
    uint64_t RTW_L_24;
    uint64_t RTW_S_24;
    uint64_t WCKPST;
    uint64_t WCK2DQI;
    uint64_t WTP;
    uint64_t ACU;
    uint64_t RCD_r;
    uint64_t RCD_w;
    uint64_t CMDPD;
    uint64_t dbR2act;
    uint64_t ESPD;
    uint64_t SR;
    uint64_t XSR;
    // TODO: just temporarily for compatibility reasons; will get removed later
    uint64_t RCD_L;
    uint64_t RCD_S;
    uint64_t RFCpb;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemTimingSpecTypeLPDDR6,
                            tCK,
                            REFI,
                            RFCab,
                            RAS,
                            RPab,
                            RPpb,
                            RCpb,
                            RCab,
                            PPD,
                            FAW,
                            RRD,
                            RL,
                            RBTP,
                            WL,
                            WR,
                            RTRS,
                            BL_n_min_24,
                            BL_n_max_24,
                            BL_n_L_24,
                            BL_n_S_24,
                            BL_n_min_48,
                            BL_n_max_48,
                            BL_n_L_48,
                            BL_n_S_48,
                            WTR_L,
                            WTR_S,
                            WCK2DQO,
                            WCK2CK,
                            RTP_24,
                            RTP_48,
                            RTW_L_48,
                            RTW_S_48,
                            RTW_L_24,
                            RTW_S_24,
                            WCKPST,
                            WCK2DQI,
                            WTP,
                            ACU,
                            RCD_r,
                            RCD_w,
                            CMDPD,
                            dbR2act,
                            ESPD,
                            SR,
                            XSR)

struct BankWiseSpecTypeLPDDR6
{
    std::optional<double> factRho;
};
NLOHMANN_JSONIFY_ALL_THINGS(BankWiseSpecTypeLPDDR6, factRho)

struct MemPowerSpecTypeLPDDR6
{
    double vdd1;
    double idd01;
    double idd2n1;
    double idd3n1;
    double idd4r1;
    double idd4w1;
    double idd51;
    double idd5pdb1;
    double idd61;
    double idd6ds1;
    double idd2p1;
    double idd3p1;
    
    double vdd2c;
    double idd02c;
    double idd2n2c;
    double idd3n2c;
    double idd4r2c;
    double idd4w2c;
    double idd52c;
    double idd5pdb2c;
    double idd62c;
    double idd6ds2c;
    double idd2p2c;
    double idd3p2c;
    
    double vdd2d;
    double idd02d;
    double idd2n2d;
    double idd3n2d;
    double idd4r2d;
    double idd4w2d;
    double idd52d;
    double idd5pdb2d;
    double idd62d;
    double idd6ds2d;
    double idd2p2d;
    double idd3p2d;

    double vddq;

    std::optional<double> iBeta_vdd1;
    std::optional<double> iBeta_vdd2c;
    std::optional<double> iBeta_vdd2d;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemPowerSpecTypeLPDDR6,
                            vdd1,
                            idd01,
                            idd2n1,
                            idd3n1,
                            idd4r1,
                            idd4w1,
                            idd51,
                            idd5pdb1,
                            idd61,
                            idd6ds1,
                            idd2p1,
                            idd3p1,
                            vdd2c,
                            idd02c,
                            idd2n2c,
                            idd3n2c,
                            idd4r2c,
                            idd4w2c,
                            idd52c,
                            idd5pdb2c,
                            idd62c,
                            idd6ds2c,
                            idd2p2c,
                            idd3p2c,
                            vdd2d,
                            idd02d,
                            idd2n2d,
                            idd3n2d,
                            idd4r2d,
                            idd4w2d,
                            idd52d,
                            idd5pdb2d,
                            idd62d,
                            idd6ds2d,
                            idd2p2d,
                            idd3p2d,
                            vddq,
                            iBeta_vdd1,
                            iBeta_vdd2c,
                            iBeta_vdd2d)

struct MemSpecLPDDR6
{
    static constexpr inline const std::string_view id = "LPDDR6";
    std::string memoryId;

    MemArchitectureSpecTypeLPDDR6 memarchitecturespec;
    MemPowerSpecTypeLPDDR6 mempowerspec;
    MemTimingSpecTypeLPDDR6 memtimingspec;
    std::optional<BankWiseSpecTypeLPDDR6> bankwisespec;
    MemImpedanceSpecTypeLPDDR6 memimpedancespec;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecLPDDR6,
                            memoryId,
                            memarchitecturespec,
                            mempowerspec,
                            memtimingspec,
                            bankwisespec,
                            memimpedancespec)

} // namespace DRAMUtils::MemSpec

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR6_H */
