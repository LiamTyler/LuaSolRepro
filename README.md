# LuaSolRepro

## Description
Minimal repro of issue using Sol that won't compile on msvc 2017, and gives many warnings in 2019. Oddly enough, i noticed the following fixes:
- remove line "player_type["speed"] = &player::speed;"
- remove "using namespace std;"

The 2nd one is usable obviously, but I am unsure why it works

## Setup
```
git clone https://github.com/LiamTyler/LuaSolRepro.git
cd LuaSolRepro
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" ..
```
