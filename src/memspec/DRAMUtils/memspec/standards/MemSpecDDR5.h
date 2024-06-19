#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECDDR5_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECDDR5_H

#include <string_view>
#include <string>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemArchitectureSpecTypeDDR5
{
    uint64_t nbrOfChannels;
    uint64_t nbrOfDevices;
    uint64_t nbrOfRanks;
    uint64_t nbrOfDIMMRanks;
    uint64_t nbrOfPhysicalRanks;
    uint64_t nbrOfLogicalRanks;
    uint64_t nbrOfBanks;
    uint64_t nbrOfBankGroups;
    uint64_t nbrOfRows;
    uint64_t nbrOfColumns;
    uint64_t burstLength;
    uint64_t dataRate;
    uint64_t width;
    std::optional<uint64_t> maxBurstLength;

    uint64_t cmdMode;
    uint64_t refMode;
    uint64_t RAAIMT;
    uint64_t RAAMMT;
    uint64_t RAADEC;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemArchitectureSpecTypeDDR5, nbrOfChannels, nbrOfDevices, nbrOfRanks, nbrOfDIMMRanks, nbrOfPhysicalRanks, nbrOfLogicalRanks, nbrOfBanks, nbrOfBankGroups, nbrOfRows, nbrOfColumns, burstLength, dataRate, width, maxBurstLength, cmdMode, refMode, RAAIMT, RAAMMT, RAADEC)

struct MemTimingSpecTypeDDR5
{
    double      tCK;
    uint64_t    RAS;
    uint64_t    RCD;
    uint64_t    RTP;
    uint64_t    WL;
    uint64_t    WR;
    uint64_t    RP;
    uint64_t    RFCsb;

    uint64_t    RFC1;
    uint64_t    RFC2;

    uint64_t    PPD;
    uint64_t    RL;
    uint64_t    RPRE;
    uint64_t    RPST;
    uint64_t    RDDQS;
    uint64_t    WPRE;
    uint64_t    WPST;

    uint64_t    CCD_L_slr;
    uint64_t    CCD_L_WR_slr;
    uint64_t    CCD_L_WR2_slr;
    uint64_t    CCD_M_slr;
    uint64_t    CCD_M_WR_slr;
    uint64_t    CCD_S_slr;
    uint64_t    CCD_S_WR_slr;
    uint64_t    CCD_dlr;
    uint64_t    CCD_WR_dlr;
    uint64_t    CCD_WR_dpr;
    uint64_t    RRD_L_slr;
    uint64_t    RRD_S_slr;
    uint64_t    RRD_dlr;
    uint64_t    FAW_slr;
    uint64_t    FAW_dlr;
    uint64_t    WTR_L;
    uint64_t    WTR_M;
    uint64_t    WTR_S;
    uint64_t    RFC1_slr;
    uint64_t    RFC2_slr;
    uint64_t    RFC1_dlr;
    uint64_t    RFC2_dlr;
    uint64_t    RFC1_dpr;
    uint64_t    RFC2_dpr;
    uint64_t    RFCsb_slr;
    uint64_t    RFCsb_dlr;
    uint64_t    REFI1;
    uint64_t    REFI2;
    uint64_t    REFISB;
    uint64_t    REFSBRD_slr;
    uint64_t    REFSBRD_dlr;
    uint64_t    RTRS;
    uint64_t    CPDED;
    uint64_t    PD;
    uint64_t    XP;
    uint64_t    ACTPDEN;
    uint64_t    PRPDEN;
    uint64_t    REFPDEN;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemTimingSpecTypeDDR5, tCK, RAS, RCD, RTP, WL, WR, RP, RFCsb, RFC1, RFC2, PPD, RL, RPRE, RPST, RDDQS, WPRE, WPST, CCD_L_slr, CCD_L_WR_slr, CCD_L_WR2_slr, CCD_M_slr, CCD_M_WR_slr, CCD_S_slr, CCD_S_WR_slr, CCD_dlr, CCD_WR_dlr, CCD_WR_dpr, RRD_L_slr, RRD_S_slr, RRD_dlr, FAW_slr, FAW_dlr, WTR_L, WTR_M, WTR_S, RFC1_slr, RFC2_slr, RFC1_dlr, RFC2_dlr, RFC1_dpr, RFC2_dpr, RFCsb_slr, RFCsb_dlr, REFI1, REFI2, REFISB, REFSBRD_slr, REFSBRD_dlr, RTRS, CPDED, PD, XP, ACTPDEN, PRPDEN, REFPDEN)

struct MemPowerSpecTypeDDR5
{
    double vdd;
    double idd0;
    double idd2n;
    double idd3n;
    double idd4r;
    double idd4w;
    double idd5c;
    double idd6n;
    double idd2p;
    double idd3p;

    double vpp;
    double ipp0;
    double ipp2n;
    double ipp3n;
    double ipp4r;
    double ipp4w;
    double ipp5c;
    double ipp6n;
    double ipp2p;
    double ipp3p;

    double idd5b;
    double idd5f;

    double ipp5b;
    double ipp5f;

    double vddq;

    std::optional<double> iBeta;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemPowerSpecTypeDDR5, vdd, idd0, idd2n, idd3n, idd4r, idd4w, idd5c, idd6n, idd2p, idd3p, vpp, ipp0, ipp2n, ipp3n, ipp4r, ipp4w, ipp5c, ipp6n, ipp2p, ipp3p, idd5b, idd5f, ipp5b, ipp5f, vddq, iBeta)

struct BankWiseSpecTypeDDR5
{
    std::optional<double> factRho;
};
NLOHMANN_JSONIFY_ALL_THINGS(BankWiseSpecTypeDDR5, factRho)

struct MemImpedanceSpecTypeDDR5 {
    double C_total_cb;
    double C_total_ck;
    double C_total_dqs;
    double C_total_rb;
    double C_total_wb;

    double R_eq_cb;
    double R_eq_ck;
    double R_eq_dqs;
    double R_eq_rb;
    double R_eq_wb;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemImpedanceSpecTypeDDR5, C_total_cb, C_total_ck, C_total_dqs, C_total_rb, C_total_wb, R_eq_cb, R_eq_ck, R_eq_dqs, R_eq_rb, R_eq_wb)

struct MemSpecDDR5 : BaseMemSpec
{
    static constexpr inline const std::string_view id = "DDR5";
    std::string memoryId;

    uint64_t RefreshMode;
    MemArchitectureSpecTypeDDR5 memarchitecturespec;
    MemPowerSpecTypeDDR5 mempowerspec;
    MemTimingSpecTypeDDR5 memtimingspec;
    std::optional<BankWiseSpecTypeDDR5> bankwisespec;
    MemImpedanceSpecTypeDDR5 memimpedancespec;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecDDR5, memoryId, RefreshMode, memarchitecturespec, mempowerspec, memtimingspec, bankwisespec, memimpedancespec)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECDDR5_H */
