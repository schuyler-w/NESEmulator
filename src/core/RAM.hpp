#pragma once

#include <cstdint>
#include <cstdio>

#include "typedefs.hpp"
#include "BusInterface.hpp"

namespace NES {

class RAM : public BusInterface {
public:
    u8 read(u16 address);
    void write(u16 address, u8 data);
private:
    u8 ram[2048] = {0};
};

} // end namespace NES