/*
===========================================================================

Copyright (c) 2010-2014 Darkstar Dev Teams

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses/

This file is part of DarkStar-server source code.

===========================================================================
*/

#include "defines.h"

#include "console.h"
#include "functions.h"
#include "network.h"

/* Global Variables */
xiloader::Language g_Language = xiloader::Language::English; // The language of the loader to be used for polcore.
std::string g_ServerAddress = "127.0.0.1"; // The server address to connect to.
std::string g_ServerPort = "51220"; // The server lobby server port to connect to.
std::string g_Username = ""; // The username being logged in with.
std::string g_Password = ""; // The password being logged in with.
char* g_CharacterList = NULL; // Pointer to the character list data being sent from the server.
bool g_IsRunning = false; // Flag to determine if the network threads should hault.
CRITICAL_SECTION g_CriticalSection; // Critical section object to prevent console logging issues from threads.

/* Hairpin Fix Variables */
DWORD g_NewServerAddress; // Hairpin server address to be overriden with.
DWORD g_HairpinReturnAddress; // Hairpin return address to allow the code cave to return properly.

static float g_DrawDistance = 20.0f;
static float g_MobDistance = 20.0f;

/**
 * @brief Detour function definitions.
 */
extern "C"
{
    hostent* (WINAPI __stdcall * Real_gethostbyname)(const char* name) = gethostbyname;
}

/**
 * @brief Hairpin fix codecave.
 */
#ifndef __GNUC__
__declspec(naked)
#endif
void HairpinFixCave(void)
{
#ifndef __GNUC__
    __asm mov eax, g_NewServerAddress
    __asm mov [edx + 0x012E90], eax
    __asm mov [edx], eax
    __asm jmp g_HairpinReturnAddress
#endif
}

/**
 * @brief Modifies FPS lock.
 *
 * @param lpParam       Thread param object.
 *
 * @return Non-important return.
 */
DWORD ApplyFPSHack(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    do
    {
        /* Sleep until we find FFXiMain loaded.. */
        Sleep(100);
    } while (GetModuleHandleA("FFXiMain.dll") == NULL);

    static float frameskip = 60.0f;

    auto raddr = (DWORD)xiloader::functions::FindPattern("FFXiMain.dll", (BYTE*)"\x89\x46\x28\xD9\x46\x28\xD8\x1D", "xxxxxxxx");
    if (raddr == 0)
    {
        xiloader::console::output(xiloader::color::error, "Failed to locate frame skip address!");
        return 0;
    }

    *(unsigned long*)(raddr + 0x8) = (unsigned long)&frameskip;

    auto raddr2 = (DWORD)xiloader::functions::FindPattern("FFXiMain.dll", (BYTE*)"\xC7\x46\x28\x00\x00\xA0\x41\xD8\x15", "xxxxxxxxx");
    if (raddr2 == 0)
    {
        xiloader::console::output(xiloader::color::error, "Failed to locate frame skip address!");
        return 0;
    }

    *(unsigned long*)(raddr2 + 0x9) = (unsigned long)&frameskip;

    struct {
        char *pattern;
        char *mask;
        DWORD offset;
    } regions[4] = {
        { "\x6A\x04\xE8\xFF\xFF\xFF\xFF\xA0", "xxx????x", 0x1 }, // 15FPS (04) [Fishing]
        { "\x6A\x02\x66\xC7\x41\x3A", "xxxxxx", 0x1 }, // 30FPS (02) [???]
        { "\x6A\x02\x81\xE2", "xxxx", 0x1 }, // 30FPS (02) [Zoning]
        // { "\xC2\x04\x00\x90\x90\x90\x90\x6A\x02\xE8", "xxxxxxxx?x", 0x8 }, // 30FPS (02) [Startup]
        { "\x75\x0A\x6A\x02\xE8", "xxxx", 0x3 }, // 30FPS (02) [Title/Logout]
    };

    DWORD addr[4];
    for (int i = 0; i < 4; ++i) {
        addr[i] = (DWORD)xiloader::functions::FindPattern("FFXiMain.dll", (BYTE*)regions[i].pattern, regions[i].mask);
        if (addr[i] == 0)
        {
            xiloader::console::output(xiloader::color::error, "Failed to locate FPS cap address! (%d)", i);
            return 0;
        }
    }

    for (int i = 0; i < 4; ++i)
        *(BYTE*)(addr[i] + regions[i].offset) = 0x01;

    xiloader::console::output(xiloader::color::success, "FPS hack applied!");
    return 0;
}

/**
 * @brief Modifies draw distance larger.
 *
 * @param lpParam       Thread param object.
 *
 * @return Non-important return.
 */
DWORD ApplyDrawDistanceHack(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    do
    {
        /* Sleep until we find FFXiMain loaded.. */
        Sleep(100);
    } while (GetModuleHandleA("FFXiMain.dll") == NULL);

    auto addr = (DWORD)xiloader::functions::FindPattern("FFXiMain.dll", (BYTE*)"\x8B\xC1\x48\x74\x08\xD8\x0D", "xxxxxxx");
    if (addr == 0)
    {
        xiloader::console::output(xiloader::color::error, "Failed to locate draw distance address!");
        return 0;
    }

    *(unsigned long*)(addr + 0x07) = (unsigned long)&g_DrawDistance;

    xiloader::console::output(xiloader::color::success, "Draw distance hack applied! (%.2f)", g_DrawDistance);
    return 0;
}

/**
 * @brief Modifies mob distance larger.
 *
 * @param lpParam       Thread param object.
 *
 * @return Non-important return.
 */
DWORD ApplyMobDistanceHack(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    do
    {
        /* Sleep until we find FFXiMain loaded.. */
        Sleep(100);
    } while (GetModuleHandleA("FFXiMain.dll") == NULL);

    auto addr = (DWORD)xiloader::functions::FindPattern("FFXiMain.dll", (BYTE*)"\x8B\xC1\x48\x74\x08\xD8\x0D", "xxxxxxx");
    if (addr == 0)
    {
        xiloader::console::output(xiloader::color::error, "Failed to locate mob distance address!");
        return 0;
    }

    *(unsigned long*)(addr + 0x0F) = (unsigned long)&g_MobDistance;

    xiloader::console::output(xiloader::color::success, "Mob distance hack applied! (%.2f)", g_MobDistance);
    return 0;
}

/**
 * @brief Disables swear filter.
 *
 * @param lpParam       Thread param object.
 *
 * @return Non-important return.
 */
DWORD ApplySwearFilterHack(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    do
    {
        /* Sleep until we find FFXiMain loaded.. */
        Sleep(100);
    } while (GetModuleHandleA("FFXiMain.dll") == NULL);

    auto addr = (DWORD)xiloader::functions::FindPattern("FFXiMain.dll", (BYTE*)"\x83\xF8\xFF\x89\x46\x04", "xx?xxx");
    if (addr == 0)
    {
        xiloader::console::output(xiloader::color::error, "Failed to locate swear filter address!");
        return 0;
    }

    *(BYTE*)(addr + 0x02) = 0x0;
    xiloader::console::output(xiloader::color::success, "Swear filter hack applied!");
    return 0;
}

/**
 * @brief Applies the hairpin fix modifications.
 *
 * @param lpParam       Thread param object.
 *
 * @return Non-important return.
 */
DWORD ApplyHairpinFixThread(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);

    do
    {
        /* Sleep until we find FFXiMain loaded.. */
        Sleep(100);
    } while (GetModuleHandleA("FFXiMain.dll") == NULL);

    /* Convert server address.. */
    xiloader::network::ResolveHostname(g_ServerAddress.c_str(), &g_NewServerAddress);

    // Locate the main hairpin location..
    //
    // As of 07.08.2013:
    //      8B 82 902E0100        - mov eax, [edx+00012E90]
    //      89 02                 - mov [edx], eax <-- edit this

    auto hairpinAddress = (DWORD)xiloader::functions::FindPattern("FFXiMain.dll", (BYTE*)"\x8B\x82\xFF\xFF\xFF\xFF\x89\x02\x8B\x0D", "xx????xxxx");
    if (hairpinAddress == 0)
    {
        xiloader::console::output(xiloader::color::error, "Failed to locate main hairpin hack address!");
        return 0;
    }

    // Locate zoning IP change address..
    //
    // As of 07.08.2013
    //      74 08                 - je FFXiMain.dll+E5E72
    //      8B 0D 68322B03        - mov ecx, [FFXiMain.dll+463268]
    //      89 01                 - mov [ecx], eax <-- edit this
    //      8B 46 0C              - mov eax, [esi+0C]
    //      85 C0                 - test eax, eax

    auto zoneChangeAddress = (DWORD)xiloader::functions::FindPattern("FFXiMain.dll", (BYTE*)"\x8B\x0D\xFF\xFF\xFF\xFF\x89\x01\x8B\x46", "xx????xxxx");
    if (zoneChangeAddress == 0)
    {
        xiloader::console::output(xiloader::color::error, "Failed to locate zone change hairpin address!");
        return 0;
    }

    /* Apply the hairpin fix.. */
    auto caveDest = ((int)HairpinFixCave - ((int)hairpinAddress)) - 5;
    g_HairpinReturnAddress = hairpinAddress + 0x08;

    *(BYTE*)(hairpinAddress + 0x00) = 0xE9; // jmp
    *(UINT*)(hairpinAddress + 0x01) = caveDest;
    *(BYTE*)(hairpinAddress + 0x05) = 0x90; // nop
    *(BYTE*)(hairpinAddress + 0x06) = 0x90; // nop
    *(BYTE*)(hairpinAddress + 0x07) = 0x90; // nop

    /* Apply zone ip change patch.. */
    memset((LPVOID)(zoneChangeAddress + 0x06), 0x90, 2);

    xiloader::console::output(xiloader::color::success, "Hairpin fix applied!");
    return 0;
}

/**
 * @brief gethostbyname detour callback.
 *
 * @param name      The hostname to obtain information of.
 *
 * @return Hostname information object.
 */
hostent* __stdcall Mine_gethostbyname(const char* name)
{
    xiloader::console::output(xiloader::color::debug, "Resolving host: %s", name);

    if (!strcmp("ffxi00.pol.com", name))
        return Real_gethostbyname(g_ServerAddress.c_str());
    if (!strcmp("pp000.pol.com", name))
        return Real_gethostbyname("127.0.0.1");

    return Real_gethostbyname(name);
}

/**
 * @brief Locates the INET mutex function call inside of polcore.dll
 *
 * @return The pointer to the function call.
 */
inline DWORD FindINETMutex(void)
{
    const char* module = (g_Language == xiloader::Language::European) ? "polcoreeu.dll" : "polcore.dll";
    auto result = (DWORD)xiloader::functions::FindPattern(module, (BYTE*)"\x8B\x56\x2C\x8B\x46\x28\x8B\x4E\x24\x52\x50\x51", "xxxxxxxxxxxx");
    return (*(DWORD*)(result - 4) + (result));
}

/**
 * @brief Locates the PlayOnline connection object inside of polcore.dll
 *
 * @return Pointer to the pol connection object.
 */
inline DWORD FindPolConn(void)
{
    const char* module = (g_Language == xiloader::Language::European) ? "polcoreeu.dll" : "polcore.dll";
    auto result = (DWORD)xiloader::functions::FindPattern(module, (BYTE*)"\x81\xC6\x38\x03\x00\x00\x83\xC4\x04\x81\xFE", "xxxxxxxxxxx");
    return (*(DWORD*)(result - 10));
}

/**
 * @brief Locates the current character information block.
 *
 * @return Pointer to the character information table.
 */
inline LPVOID FindCharacters(void** commFuncs)
{
    LPVOID lpCharTable = NULL;
    memcpy(&lpCharTable, (char*)commFuncs[0xD3] + 31, sizeof(lpCharTable));
    return lpCharTable;
}

#ifdef __GNUC__
static HRESULT (WINAPI* Real_CoCreateInstance)(REFCLSID, IUnknown*, DWORD, REFIID, void**) = nullptr;
void _install_module(BYTE *head);

HRESULT WINAPI Mine_CoCreateInstance(REFCLSID rclsid, IUnknown* outer, DWORD flags, REFIID riid, void **ppv)
{
    HRESULT hr = Real_CoCreateInstance(rclsid, outer, flags, riid, ppv);
    if (SUCCEEDED(hr)) {
        _install_module((BYTE*)GetModuleHandleA("polcore.dll"));
        _install_module((BYTE*)GetModuleHandleA("polcoreE.dll"));
        _install_module((BYTE*)GetModuleHandleA("FFXi.dll"));
        _install_module((BYTE*)GetModuleHandleA("FFXiMain.dll"));
    }
    return hr;
}

void _install_func(IMAGE_THUNK_DATA *iat, DWORD hook)
{
    if (iat->u1.Function == hook)
        return;

    DWORD old;
    if (VirtualProtect(&iat->u1.Function, 4, PAGE_EXECUTE_READWRITE, &old)) {
        iat->u1.Function = hook;
        VirtualProtect(&iat->u1.Function, 4, old, &old);
    }
}

void _try_ws2(BYTE *head, LPCSTR dllname, IMAGE_IMPORT_DESCRIPTOR *imp)
{
    if (_stricmp(dllname, "Ws2_32.dll") != 0)
        return;

    IMAGE_THUNK_DATA *pint = (IMAGE_THUNK_DATA*)(head + imp->OriginalFirstThunk);
    IMAGE_THUNK_DATA *piat = (IMAGE_THUNK_DATA*)(head + imp->FirstThunk);
    for (; piat->u1.Function; ++piat, ++pint) {
        if (IMAGE_SNAP_BY_ORDINAL(pint->u1.Ordinal)) {
            DWORD id = IMAGE_ORDINAL(pint->u1.Ordinal);
            if (id != 52)
                continue;

            _install_func(piat, (DWORD)Mine_gethostbyname);
        }
    }
}

void _try_ole32(BYTE *head, LPCSTR dllname, IMAGE_IMPORT_DESCRIPTOR *imp)
{
    if (_stricmp(dllname, "Ole32.dll") != 0)
        return;

    IMAGE_THUNK_DATA *pint = (IMAGE_THUNK_DATA*)(head + imp->OriginalFirstThunk);
    IMAGE_THUNK_DATA *piat = (IMAGE_THUNK_DATA*)(head + imp->FirstThunk);
    for (; piat->u1.Function; ++piat, ++pint) {
        if (!IMAGE_SNAP_BY_ORDINAL(pint->u1.Ordinal)) {
            LPCSTR procname = (LPCSTR) ((IMAGE_IMPORT_BY_NAME*)(head + pint->u1.AddressOfData))->Name;
            if (_stricmp(procname, "CoCreateInstance") != 0)
                continue;

            _install_func(piat, (DWORD)Mine_CoCreateInstance);
        }
    }
}

void _install_module(BYTE *head)
{
    if(!head)
        return;

    IMAGE_DOS_HEADER *dos = (IMAGE_DOS_HEADER*)(head + 0);
    IMAGE_NT_HEADERS *nt  = (IMAGE_NT_HEADERS*)(head + dos->e_lfanew);
    IMAGE_DATA_DIRECTORY *dir = nt->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_IMPORT;

    if (!dir->VirtualAddress || !dir->Size)
        return;

    IMAGE_IMPORT_DESCRIPTOR *imp = (IMAGE_IMPORT_DESCRIPTOR*)(head + dir->VirtualAddress);
    for (; imp->FirstThunk; ++imp) {
        LPCSTR dllname = (LPCSTR)(head + imp->Name);
        _try_ws2(head, dllname, imp);
        _try_ole32(head, dllname, imp);
    }
}

static void hook(void)
{
    HMODULE self = GetModuleHandleA(NULL);
    HMODULE ole = GetModuleHandleA("Ole32.dll");
    HMODULE ws2 = GetModuleHandleA("Ws2_32.dll");
    Real_CoCreateInstance = (HRESULT(WINAPI*)(REFCLSID, IUnknown*, DWORD, REFIID, void**))GetProcAddress(ole, "CoCreateInstance");
    Real_gethostbyname = (struct hostent*(WSAAPI*)(const char*))GetProcAddress(ws2, "gethostbyname");
    _install_module((BYTE*)self);
}
#endif

/**
 * @brief Main program entrypoint.
 *
 * @param argc      The count of arguments being passed to this application on launch.
 * @param argv      Pointer to array of argument data.
 *
 * @return 1 on error, 0 on success.
 */
int __cdecl main(int argc, char* argv[])
{
    bool bUseHairpinFix = false;
    bool bUseDrawDistanceHack = false;
    bool bUseMobDistanceHack = false;
    bool bUseFPSHack = false;
    bool bUseSwearHack = false;

    /* Create critical section for console output.. */
    if (!InitializeCriticalSectionAndSpinCount(&g_CriticalSection, 0x00000400))
    {
        xiloader::console::output(xiloader::color::error, "Failed to initialize critical section! Error code: %d", GetLastError());
        return 0;
    }

    /* Output the DarkStar banner.. */
    xiloader::console::output(xiloader::color::error, "==========================================================");
    xiloader::console::output(xiloader::color::success, "DarkStar Boot Loader (c) 2015 DarkStar Team");
    xiloader::console::output(xiloader::color::lightpurple, "Bug Reports: https://github.com/DarkstarProject/darkstar/issues");
    xiloader::console::output(xiloader::color::lightpurple, "Git Repo   : https://github.com/DarkstarProject/darkstar");
    xiloader::console::output(xiloader::color::error, "==========================================================");

    /* Initialize Winsock */
    WSADATA wsaData = { 0 };
    auto ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (ret != 0)
    {
        xiloader::console::output(xiloader::color::error, "Failed to initialize winsock, error code: %d", ret);
        return 1;
    }

    /* Initialize COM */
    auto hResult = CoInitialize(NULL);
    if (hResult != S_OK && hResult != S_FALSE)
    {
        /* Cleanup Winsock */
        WSACleanup();

        xiloader::console::output(xiloader::color::error, "Failed to initialize COM, error code: %d", hResult);
        return 1;
    }

#ifndef __GNUC__
    /* Attach detour for gethostbyname.. */
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)Real_gethostbyname, Mine_gethostbyname);
    if (DetourTransactionCommit() != NO_ERROR)
    {
        /* Cleanup COM and Winsock */
        CoUninitialize();
        WSACleanup();

        xiloader::console::output(xiloader::color::error, "Failed to detour function 'gethostbyname'. Cannot continue!");
        return 1;
    }
#else
    hook();
#endif

    /* Read Command Arguments */
    for (auto x = 1; x < argc; ++x)
    {
        /* Server Address Argument */
        if (!_strnicmp(argv[x], "--server", 8))
        {
            g_ServerAddress = argv[++x];
            continue;
        }

        /* Server Port Argument */
        if (!_strnicmp(argv[x], "--port", 6))
        {
            g_ServerPort = argv[++x];
            continue;
        }

        /* Username Argument */
        if (!_strnicmp(argv[x], "--user", 6))
        {
            g_Username = argv[++x];
            continue;
        }

        /* Password Argument */
        if (!_strnicmp(argv[x], "--pass", 6))
        {
            g_Password = argv[++x];
            continue;
        }

        /* Language Argument */
        if (!_strnicmp(argv[x], "--lang", 6))
        {
            std::string language = argv[++x];

            if (!_strnicmp(language.c_str(), "JP", 2) || !_strnicmp(language.c_str(), "0", 1))
                g_Language = xiloader::Language::Japanese;
            if (!_strnicmp(language.c_str(), "US", 2) || !_strnicmp(language.c_str(), "1", 1))
                g_Language = xiloader::Language::English;
            if (!_strnicmp(language.c_str(), "EU", 2) || !_strnicmp(language.c_str(), "2", 1))
                g_Language = xiloader::Language::European;

            continue;
        }

        /* Hairpin Argument */
        if (!_strnicmp(argv[x], "--hairpin", 9))
        {
            bUseHairpinFix = true;
            continue;
        }

        if (!_strnicmp(argv[x], "--drawdistance", 14))
        {
            if ((g_DrawDistance = atof(argv[++x])) <= 0.0f)
                g_DrawDistance = 20.0f;

            bUseDrawDistanceHack = true;
            continue;
        }

        if (!_strnicmp(argv[x], "--mobdistance", 14))
        {
            if ((g_MobDistance = atof(argv[++x])) <= 0.0f)
                g_MobDistance = 20.0f;

            bUseMobDistanceHack = true;
            continue;
        }

        if (!_strnicmp(argv[x], "--fps", 5))
        {
            bUseFPSHack = true;
            continue;
        }

        if (!_strnicmp(argv[x], "--swear", 7))
        {
            bUseSwearHack = true;
            continue;
        }

        xiloader::console::output(xiloader::color::warning, "Found unknown command argument: %s", argv[x]);
    }

    /* Attempt to resolve the server address.. */
    ULONG ulAddress = 0;
    if (xiloader::network::ResolveHostname(g_ServerAddress.c_str(), &ulAddress))
    {
        g_ServerAddress = inet_ntoa(*((struct in_addr*)&ulAddress));

        /* Attempt to create socket to server..*/
        xiloader::datasocket sock;
        if (xiloader::network::CreateConnection(&sock, "54231"))
        {
            /* Attempt to verify the users account info.. */
            while (!xiloader::network::VerifyAccount(&sock))
                Sleep(10);

            /* Start hairpin hack thread if required.. */
            if (bUseHairpinFix)
            {
                CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ApplyHairpinFixThread, NULL, 0, NULL);
            }

            if (bUseDrawDistanceHack)
            {
                CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ApplyDrawDistanceHack, NULL, 0, NULL);
            }

            if (bUseMobDistanceHack)
            {
                CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ApplyMobDistanceHack, NULL, 0, NULL);
            }

            if (bUseFPSHack)
            {
                CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ApplyFPSHack, NULL, 0, NULL);
            }

            if (bUseSwearHack)
            {
                CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ApplySwearFilterHack, NULL, 0, NULL);
            }

            /* Create listen servers.. */
            g_IsRunning = true;
            HANDLE hFFXiServer = CreateThread(NULL, 0, xiloader::network::FFXiServer, &sock, 0, NULL);
            HANDLE hPolServer = CreateThread(NULL, 0, xiloader::network::PolServer, NULL, 0, NULL);

            /* Attempt to create polcore instance..*/
            IPOLCoreCom* polcore = NULL;
            if (CoCreateInstance(xiloader::CLSID_POLCoreCom[g_Language], NULL, 0x17, xiloader::IID_IPOLCoreCom[g_Language], (LPVOID*)&polcore) != S_OK)
            {
                xiloader::console::output(xiloader::color::error, "Failed to initialize instance of polcore!");
            }
            else
            {
                /* Invoke the setup functions for polcore.. */
                polcore->SetAreaCode(g_Language);
                polcore->SetParamInit(GetModuleHandle(NULL), " /game eAZcFcB -net 3");

                /* Obtain the common function table.. */
                void * (**lpCommandTable)(...);
                polcore->GetCommonFunctionTable((unsigned long**)&lpCommandTable);

                /* Invoke the inet mutex function.. */
                auto findMutex = (void * (*)(...))FindINETMutex();
                findMutex();

                /* Locate and prepare the pol connection.. */
                auto polConnection = (char*)FindPolConn();
                memset(polConnection, 0x00, 0x68);
                auto enc = (char*)malloc(0x1000);
                memset(enc, 0x00, 0x1000);
                memcpy(polConnection + 0x48, &enc, sizeof(char**));

                /* Locate the character storage buffer.. */
                g_CharacterList = (char*)FindCharacters((void **)lpCommandTable);

                /* Invoke the setup functions for polcore.. */
                lpCommandTable[POLFUNC_REGISTRY_LANG](g_Language);
                lpCommandTable[POLFUNC_FFXI_LANG](xiloader::functions::GetRegistryPlayOnlineLanguage(g_Language));
                lpCommandTable[POLFUNC_REGISTRY_KEY](xiloader::functions::GetRegistryPlayOnlineKey(g_Language));
                lpCommandTable[POLFUNC_INSTALL_FOLDER](xiloader::functions::GetRegistryPlayOnlineInstallFolder(g_Language));
                lpCommandTable[POLFUNC_INET_MUTEX]();

                const bool bot = false;
                if (bot) {
                    /* Bot code here.. */
                } else {
                    /* Attempt to create FFXi instance.. */
                    IFFXiEntry* ffxi = NULL;
                    if (CoCreateInstance(xiloader::CLSID_FFXiEntry, NULL, 0x17, xiloader::IID_IFFXiEntry, (LPVOID*)&ffxi) != S_OK)
                    {
                        xiloader::console::output(xiloader::color::error, "Failed to initialize instance of FFxi!");
                    }
                    else
                    {
                        /* Attempt to start Final Fantasy.. */
                        IUnknown* message = NULL;
                        ffxi->GameStart(polcore, &message);
                        ffxi->Release();
                    }
                }

                /* Cleanup polcore object.. */
                if (polcore != NULL)
                    polcore->Release();
            }

            /* Cleanup threads.. */
            g_IsRunning = false;
            TerminateThread(hFFXiServer, 0);
            TerminateThread(hPolServer, 0);

            WaitForSingleObject(hFFXiServer, 1000);
            WaitForSingleObject(hPolServer, 1000);

            CloseHandle(hFFXiServer);
            CloseHandle(hPolServer);
        }
    }
    else
    {
        xiloader::console::output(xiloader::color::error, "Failed to resolve server hostname.");
    }

#ifndef __GNUC__
    /* Detach detour for gethostbyname. */
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)Real_gethostbyname, Mine_gethostbyname);
    DetourTransactionCommit();
#endif

    /* Cleanup COM and Winsock */
    CoUninitialize();
    WSACleanup();

    xiloader::console::output(xiloader::color::error, "Closing...");
    Sleep(2000);

    DeleteCriticalSection(&g_CriticalSection);

    return ERROR_SUCCESS;
}
