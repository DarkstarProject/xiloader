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

#ifndef __XILOADER_DEFINES_H_INCLUDED__
#define __XILOADER_DEFINES_H_INCLUDED__

#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#pragma comment(lib, "WS2_32.lib")
#include <WinSock2.h>

#include <Windows.h>
#include <process.h>
#include <stdint.h>
#include <string>
#include <time.h>

#pragma comment(lib, "detours/detours.lib")
#include "detours/detours.h"

#include "polcore.h"
#include "FFXi.h"
#include "FFXiMain.h"

/* Function Offset Definitions */
#define POLFUNC_INET_MUTEX      0x032F
#define POLFUNC_REGISTRY_LANG   0x03C5
#define POLFUNC_FFXI_LANG       0x01A4
#define POLFUNC_REGISTRY_KEY    0x016F
#define POLFUNC_INSTALL_FOLDER  0x007D

namespace xiloader
{
    /* PolCore COM Class ID Definitions */
    const CLSID CLSID_POLCoreCom[] =
    {
        { 0x07974581, 0x0df6, 0x4ef0, { 0xbd, 0x05, 0x60, 0x4b, 0x3a, 0xda, 0x9b, 0xe9 } }, // JP
        { 0x3501f5dd, 0x7894, 0x42df, { 0x86, 0x6a, 0xa2, 0xb6, 0x52, 0x7d, 0x80, 0x49 } }, // US
        { 0xe5966fb3, 0xc97b, 0x42eb, { 0x84, 0xbf, 0x37, 0xf9, 0x5e, 0xe5, 0x4a, 0x9f } }, // EU
    };

    /* PolCore COM Object ID Defintions */
    const IID IID_IPOLCoreCom[] =
    {
        { 0x9a30d565, 0xa74c, 0x4b56, { 0xb9, 0x71, 0xdc, 0xf0, 0x21, 0x85, 0xb1, 0x0d } }, // JP
        { 0xe0516654, 0xef77, 0x435d, { 0xaa, 0x7d, 0x50, 0xd2, 0xc0, 0x69, 0xce, 0x34 } }, // US
        { 0xdfec2e93, 0x4971, 0x4a54, { 0xb8, 0xed, 0x63, 0x81, 0x5c, 0x20, 0x8c, 0x5a } }, // EU
    };

    /* FFXi COM Object Definitions */
    const CLSID CLSID_FFXiEntry = { 0x989D790D, 0x6236, 0x11D4, { 0x80, 0xE9, 0x00, 0x10, 0x5A, 0x81, 0xE8, 0x90 } };
    const IID IID_IFFXiEntry = { 0x989D790C, 0x6236, 0x11D4, { 0x80, 0xE9, 0x00, 0x10, 0x5A, 0x81, 0xE8, 0x90 } };

    /* PlayOnline Language Enumeration */
    enum Language
    {
        Japanese = 0,
        English = 1,
        European = 2
    };

}; // namespace xiloader

#endif // __XILOADER_DEFINES_H_INCLUDED__
