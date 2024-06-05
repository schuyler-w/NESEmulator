#pragma once

#include <SDL.h>
#include <cstdio>

#include <string>

#include "typedefs.hpp"
#include "BusInterface.hpp"

namespace NES {

class Joystick : BusInterface {
    u8 JOY1 = 0;
    u8 JOY2 = 0;
    u8 btnStateLocked = 0;
    u8 btnState = 0;
    bool strobe;

public:
    u8 read(u16 address);
    void write(u16 address, u8 data);

    void setButtonPressed(SDL_Keycode, bool);
};

}