cmake_minimum_required(VERSION 3.24)
project(NEmu)

set(CMAKE_CXX_STANDARD 23)

# Find the SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(NEmu
        src/Desktop/main.cpp

        src/core/CPU.hpp
        src/core/typedefs.hpp
        src/core/PPU.hpp
        src/core/RAM.hpp
        src/core/ROM.hpp
        src/core/BusInterface.hpp
        src/core/Mapper/Mapper.hpp
        src/core/Joystick.hpp
        src/core/Joystick.cpp src/core/CPU.cpp src/core/Mapper/Mapper.cpp src/core/Mapper/NROM.hpp src/core/Mapper/NROM.cpp src/core/PPU.cpp src/core/RAM.cpp src/core/ROM.cpp src/core/Mapper/UnROM.hpp src/core/Mapper/UnROM.cpp src/core/Mapper/MMC1.cpp src/core/Mapper/MMC1.hpp src/core/Mapper/CNROM.cpp src/core/Mapper/CNROM.hpp)

# Link SDL2 library
target_link_libraries(NEmu ${SDL2_LIBRARIES})