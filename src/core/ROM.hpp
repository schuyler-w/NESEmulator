#pragma once

#include <cstdint>
#include <cstdio>

#include <bitset>
#include <string>
#include <vector>

#include "BusInterface.hpp"

namespace NES {

class Mapper;

struct ROMHeader {
    char nes[4];
    u8 prgRomSize;    // PRG ROM size in 16 KB units
    u8 chrRomSize;    // CHR ROM size in 8 KB units (0 indicates CHR RAM)
    u8 flags6;        // Flags 6
    u8 flags7;        // Flags 7
    u8 prgRamSize;    // PRG RAM size in 8 KB units (for compatibility)
    u8 flags9;        // Flags 9
    u8 flags10;       // Flags 10
    char padding[5];  // Unused padding bytes
};

class ROM {

public:
    std::vector<u8> getChrData() { return chrData; };
    std::vector<u8> getPrgCode() { return prgCode; };
    void open(std::string);
    void printHeader();
    int getMirroring();
    Mapper *getMapper();
private:
    ROMHeader header;
    std::vector<u8> trainer;
    std::vector<u8> prgCode;
    std::vector<u8> chrData;
    int mirroring;
    u8 mapperNum;
};

} // end namespace NES