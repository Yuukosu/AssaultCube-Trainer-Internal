#include <iostream>
#include <Windows.h>
#include "Memory.h"

DWORD WINAPI MainThread(HMODULE hModule) {
    AllocConsole();
    FILE* file;
    freopen_s(&file, "CONOUT$", "w", stdout);

    auto baseAddress = (uintptr_t) GetModuleHandle(nullptr);
    bool infHealth;

    std::cout << "HELLO!" << std::endl;
    std::cout << "Press F1 to Toggle Unlimited Health." << std::endl;
    std::cout << "Press F12 to Exit." << std::endl;

    while (!GetAsyncKeyState(VK_F12)) {
        auto* localPlayer = (uintptr_t*) (baseAddress + 0x10F4F4);

        if (GetAsyncKeyState(VK_F1) & 1) {
            infHealth = !infHealth;
            std::cout << "Unlimited Health: " << infHealth << std::endl;
        }

        if (localPlayer) {
            if (infHealth) {
                auto *health = (uintptr_t *) (*localPlayer + 0xF8);
                *(int *) health = 1337;
            }
        }

        Sleep(10);
    }

    if (file) {
        fclose(file);
    }

    FreeConsole();
    FreeLibraryAndExitThread(hModule, EXIT_SUCCESS);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH: {
            HANDLE handle = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) MainThread, hModule, 0, nullptr);

            if (handle) {
                CloseHandle(handle);
            }
            break;
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
        default:
            break;
    }

    return TRUE;
}
