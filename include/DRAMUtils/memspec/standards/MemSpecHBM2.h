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

#include <optional>
#include "DRAMUtils/util/json_utils.h"
#include <string>
#include <string_view>

namespace DRAMUtils::MemSpec
{

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
    uint64_t nbrOfStacks;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemArchitectureSpecTypeHBM2,
                            nbrOfRows,
                            nbrOfColumns,
                            burstLength,
                            maxBurstLength,
                            dataRate,
                            width,
                            nbrOfChannels,
                            nbrOfPseudoChannels,
                            nbrOfDevices,
                            nbrOfBanks,
                            nbrOfBankGroups,
                            nbrOfStacks)

struct MemTimingSpecTypeHBM2
{
    double tCK;
    uint64_t DQSCK;
    uint64_t RC;
    uint64_t RAS;
    uint64_t RCDRD;
    uint64_t RCDWR;
    uint64_t RRDL;
    uint64_t RRDS;
    uint64_t FAW;
    uint64_t RTP;
    uint64_t RP;
    uint64_t RL;
    uint64_t WL;
    uint64_t PL;
    uint64_t WR;
    uint64_t CCDL;
    uint64_t CCDS;
    uint64_t CCDR;
    uint64_t WTRL;
    uint64_t WTRS;
    uint64_t RTW;
    uint64_t XP;
    uint64_t CKE;
    uint64_t XS;
    uint64_t RFC;
    uint64_t RFCSB;
    uint64_t RREFD;
    uint64_t REFI;
    uint64_t REFISB;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemTimingSpecTypeHBM2,
                            tCK,
                            DQSCK,
                            RC,
                            RAS,
                            RCDRD,
                            RCDWR,
                            RRDL,
                            RRDS,
                            FAW,
                            RTP,
                            RP,
                            RL,
                            WL,
                            PL,
                            WR,
                            CCDL,
                            CCDS,
                            CCDR,
                            WTRL,
                            WTRS,
                            RTW,
                            XP,
                            CKE,
                            XS,
                            RFC,
                            RFCSB,
                            RREFD,
                            REFI,
                            REFISB)

struct MemPowerSpecTypeHBM2
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
    double ipp6n;
    double ipp2p;
    double ipp3p;
    
    double idd5b;
    double idd5bpb;
    double ipp5b;
    double ipp5bpb;
    
    double vddq;
    
    std::optional<double> iBeta_vdd;
    std::optional<double> iBeta_vpp;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemPowerSpecTypeHBM2, vdd, idd0, idd2n, idd3n, idd4r, idd4w, idd6n, idd2p, idd3p, vpp, ipp0, ipp2n, ipp3n, ipp4r, ipp4w, ipp6n, ipp2p, ipp3p, idd5b, idd5bpb, ipp5b, ipp5bpb, vddq, iBeta_vdd, iBeta_vpp)

struct BankWiseSpecTypeHBM2
{
    std::optional<double> factRho;
};
NLOHMANN_JSONIFY_ALL_THINGS(BankWiseSpecTypeHBM2, factRho)

struct MemImpedanceSpecTypeHBM2 {
    // Clock
    bool ck_termination;
    double ck_R_eq;
    double ck_dyn_E;

    // Clock Enable
    bool cke_termination;
    double cke_R_eq;
    double cke_dyn_E;

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
    // DQS write
    bool wdqs_termination;
    double wdqs_R_eq;
    double wdqs_dyn_E;

    // DBI read
    bool rdbi_termination;
    double rdbi_R_eq;
    double rdbi_dyn_E;
    // DBI write
    bool wdbi_termination;
    double wdbi_R_eq;
    double wdbi_dyn_E;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemImpedanceSpecTypeHBM2, ck_termination, ck_R_eq, ck_dyn_E, cke_termination, cke_R_eq, cke_dyn_E, ca_termination, ca_R_eq, ca_dyn_E, rdq_termination, rdq_R_eq, rdq_dyn_E, wdq_termination, wdq_R_eq, wdq_dyn_E, rdqs_termination, rdqs_R_eq, rdqs_dyn_E, wdqs_termination, wdqs_R_eq, wdqs_dyn_E, rdbi_termination, rdbi_R_eq, rdbi_dyn_E, wdbi_termination, wdbi_R_eq, wdbi_dyn_E)

struct MemSpecHBM2
{
    static constexpr inline const std::string_view id = "HBM2";
    std::string memoryId;

    MemArchitectureSpecTypeHBM2 memarchitecturespec;
    MemPowerSpecTypeHBM2 mempowerspec;
    MemTimingSpecTypeHBM2 memtimingspec;
    std::optional<BankWiseSpecTypeHBM2> bankwisespec;
    MemImpedanceSpecTypeHBM2 memimpedancespec;

};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecHBM2, memoryId, memarchitecturespec, mempowerspec, memtimingspec, bankwisespec, memimpedancespec)

} // namespace DRAMUtils::MemSpec

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECHBM2_H */
