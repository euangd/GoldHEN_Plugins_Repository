#pragma once
#include "global.h"
#include "addresses.h"

//typedef unsigned long long u64;

// uint64_t globalAddress = CALC_ADDRESS(0x1F3BB50);
// sceKernelMprotect((void*)globalAddress, 0x1000, 0x7);
//unsigned long long* (*getGlobal)(int index) = (void*)(globalAddress);
//unsigned long long* (*getGlobal)(int index) = (void*)globalAddress;
unsigned long long* (*getGlobal)(int index) = ((unsigned long long*(*)(int index)) (globalAddress));// 1.47 0x2323190; //1.46 0x230cd00; // 1.38 0x23270F0