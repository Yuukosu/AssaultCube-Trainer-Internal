#include "Memory.h"

void Memory::Patch(BYTE* dst, BYTE* src, int size) {
    DWORD protect;
    VirtualProtect(dst, size, PAGE_READWRITE, &protect);
    memcpy(dst, src, size);
    VirtualProtect(dst, size, protect, &protect);
}

void Memory::Nop(BYTE* dst, int size) {
    DWORD protect;
    VirtualProtect(dst, size, PAGE_READWRITE, &protect);
    memset(dst, 0x90, size);
    VirtualProtect(dst, size, protect, &protect);
}
