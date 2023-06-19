#pragma once

#ifndef ASSAULTINTERNAL_MEMORY_H
#define ASSAULTINTERNAL_MEMORY_H

#include <Windows.h>
#include <TlHelp32.h>

namespace Memory {
    void Patch(BYTE* dst, BYTE* src, int size);
    void Nop(BYTE* dst, int size);
}

#endif //ASSAULTINTERNAL_MEMORY_H
