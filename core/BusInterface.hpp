#pragma once

#include <cstdint>
#include <cstdio>

#include "typedefs.hpp"

namespace NES {

class BusInterface {
public:
    virtual ~BusInterface() {}
    virtual u8 read(u16 address) = 0;
    virtual void write(u16 address, u8 data) = 0;
};

} // end namespace NES