//
//  main.cpp
//  bits_calculator
//
//  Created by Vinod Gupta on 1/28/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <iostream>

int brootForceNumSetBits(unsigned long long num)
{
    int numSetBits = 0;
    for (int i = 0; i < (sizeof(num)*8); ++i)
        numSetBits += ((num >> i) & 0x1);
    
    return numSetBits;
}

int optiHash1[256];

void initOptimal1()
{
    for (int i = 0; i < sizeof optiHash1 / sizeof(int); ++i)
    {
        optiHash1[i] = brootForceNumSetBits(i);
    }
}

int optimal1NumSetBits(unsigned long long num)
{
    int numSetBits = 0;
    for (int i = 0; i < sizeof(num); ++i)
    {
        numSetBits += optiHash1[(num >> (i * 8)) & 0xFF];
    }
    return numSetBits;
}

int main(int argc, char* argv[])
{
    unsigned long long num = 0xFFFFFFFFFFFFFFFF;
    std::cout << "Number of bits set in " <<
    num << " = " <<
    brootForceNumSetBits(num)<<std::endl;
    std::cout << "Opti1 trial";
    initOptimal1();
    
    std::cout << "Number of bits set in " <<
    num << " = " <<
    optimal1NumSetBits(num) << std::endl;
    return 0;
}