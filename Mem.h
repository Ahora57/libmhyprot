#pragma once
#include <Windows.h>
#include <cstdint>
#include <vector>
#include "../src/libmhyprot.h"
namespace mem {


    uintptr_t FindDMAAddy(uint32_t target_process_id, uintptr_t ptr, std::vector<unsigned int> offsets)
    {

        DWORD    addr = ptr;        //for brevent double value (work:0x13371337, but need just 0x1337)



        for (unsigned int i = 0; i < offsets.size(); ++i)
        {
            if (offsets[i] != 0)      //for prevent break value or just dont add 0
                addr = libmhyprot::read_process_memory<DWORD>(target_process_id, addr + offsets[i]);
        }
        return addr;

    }

    uintptr_t FindDMAAddyKernelMem(uintptr_t ptr, std::vector<unsigned int> offsets)
    {

        DWORD    addr = ptr;    

      

        for (unsigned int i = 0; i < offsets.size(); ++i)
        {
            if (offsets[i] != 0)  
           addr =      libmhyprot::read_kernel_memory<DWORD>(addr + offsets[i]);
        }
        return addr;
    }

}