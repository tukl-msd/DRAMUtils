#ifndef DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR4_H
#define DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR4_H

#include <string_view>
#include <string>
#include <optional>
#include "DRAMUtils/util/json.h"

#include "DRAMUtils/memspec/BaseMemSpec.h"

namespace DRAMUtils::Config {

struct MemArchitectureSpecTypeLPDDR4
{
    uint64_t nbrOfChannels;
    uint64_t nbrOfDevices;
    uint64_t nbrOfRanks;
    uint64_t nbrOfBanks;
    uint64_t nbrOfBankGroups;
    uint64_t nbrOfRows;
    uint64_t nbrOfColumns;
    uint64_t burstLength;
    uint64_t dataRate;
    uint64_t width;
    std::optional<uint64_t> maxBurstLength;
};

struct MemImpedanceSpecTypeLPDDR4 {
    double C_total_ck;
    double C_total_cb;
    double C_total_rb;
    double C_total_wb;
    double C_total_dqs;

    double R_eq_ck;
    double R_eq_cb;
    double R_eq_rb;
    double R_eq_wb;
    double R_eq_dqs;
};

struct MemTimingSpecTypeLPDDR4
{
    double      tCK;
    uint64_t    CKE;
    uint64_t    ESCKE;
    uint64_t    CMDCKE;
    uint64_t    RAS;
    uint64_t    RCD;
    uint64_t    RL;
    uint64_t    REFM;
    uint64_t    REFI;
    uint64_t    REFIpb;
    uint64_t    RFCpb;
    uint64_t    RFCab;
    uint64_t    RPpb;
    uint64_t    RPab;
    uint64_t    RCpb;
    uint64_t    RCab;
    uint64_t    PPD;
    uint64_t    RCD;
    uint64_t    FAW;
    uint64_t    RRD;
    uint64_t    CCD;
    uint64_t    CCDMW;
    uint64_t    RL;
    uint64_t    RPST;
    uint64_t    DQSCK;
    uint64_t    RTP;
    uint64_t    WL;
    uint64_t    DQSS;
    uint64_t    DQS2DQ;
    uint64_t    WR;
    uint64_t    WPRE;
    uint64_t    WTR;
    uint64_t    XP;
    uint64_t    SR;
    uint64_t    XSR;
    uint64_t    RTRS;
};

enum class pasrModesType {
    PASR_0,
    PASR_1,
    PASR_2,
    PASR_3,
    PASR_4,
    PASR_5,
    PASR_6,
    PASR_7,
    Invalid = -1,
};
NLOHMANN_JSON_SERIALIZE_ENUM(pasrModesType,
                             {{pasrModesType::Invalid, nullptr},
                              {pasrModesType::PASR_0, 0},
                              {pasrModesType::PASR_1, 1},
                              {pasrModesType::PASR_2, 2},
                              {pasrModesType::PASR_3, 3},
                              {pasrModesType::PASR_4, 4},
                              {pasrModesType::PASR_5, 5},
                              {pasrModesType::PASR_6, 6},
                              {pasrModesType::PASR_7, 7},})

struct BankWiseSpecTypeLPDDR4
{
    std::optional<double>           factRho;
    std::optional<double>           factSigma;
    std::optional<pasrModesType>    pasrMode;
};

struct MemPowerSpecTypeLPDDR4
{
    double  vdd1;
    double  idd01;
    double  idd2n1;
    double  idd3n1;
    double  idd4r1;
    double  idd4w1;
    double  idd51;
    double  idd5pb1;
    double  idd61;
    double  idd2p1;
    double  idd3p1;

    double  vdd2;
    double  idd02;
    double  idd2n2;
    double  idd3n2;
    double  idd4r2;
    double  idd4w2;
    double  idd52;
    double  idd5pb2;
    double  idd62;
    double  idd2p2;
    double  idd3p2;

    double vddq;
};

struct MemSpecLPDDR4 : BaseMemSpec
{
    static constexpr inline const std::string_view id = "LPDDR4";
    std::string memoryId;

    MemArchitectureSpecTypeLPDDR4 memarchitecturespec;
    MemPowerSpecTypeLPDDR4 mempowerspec;
    MemTimingSpecTypeLPDDR4 memtimingspec;
    MemImpedanceSpecTypeLPDDR4 memimpedancespec;
    std::optional<BankWiseSpecTypeLPDDR4> bankwisespec;
};
NLOHMANN_JSONIFY_ALL_THINGS(MemSpecLPDDR4, memoryId, memarchitecturespec, mempowerspec, memtimingspec, bankwisespec, memimpedancespec)

} // namespace DRAMUtils::Config

#endif /* DRAMUTILS_MEMSPEC_STANDARDS_MEMSPECLPDDR4_H */
