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

#ifndef __XILOADER_NETWORK_H_INCLUDED__
#define __XILOADER_NETWORK_H_INCLUDED__

#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <string>
#include <conio.h>

#include "console.h"

namespace xiloader
{
    /**
     * @brief Socket object used to hold various important information.
     */
    typedef struct datasocket_t
    {
        datasocket_t() : s(INVALID_SOCKET), AccountId(0), LocalAddress((ULONG)-1), ServerAddress((ULONG)-1)
        {}

        SOCKET s;
        UINT32 AccountId;
        ULONG LocalAddress;
        ULONG ServerAddress;
    } datasocket;

    /**
     * @brief Network class containing functions related to networking.
     */
    class network
    {
        /**
         * @brief Data communication between the local client and the game server.
         *
         * @param lpParam       Thread param object.
         *
         * @return Non-important return.
         */
        static DWORD __stdcall FFXiDataComm(LPVOID lpParam);

        /**
         * @brief Data communication between the local client and the lobby server.
         *
         * @param lpParam       Thread param object.
         *
         * @return Non-important return.
         */
        static DWORD __stdcall PolDataComm(LPVOID lpParam);
        
    public:

        /**
         * @brief Creates a connection on the given port.
         *
         * @param sock          The datasocket object to store information within.
         * @param port          The port to create the connection on.
         *
         * @return True on success, false otherwise.
         */
        static bool CreateConnection(datasocket* sock, const char* port);

        /**
         * @brief Creates a listening server on the given port and protocol.
         *
         * @param sock          The socket object to bind to.
         * @param protocol      The protocol to use on the new listening socket.
         * @param port          The port to bind to listen on.
         *
         * @return True on success, false otherwise.
         */
        static bool CreateListenServer(SOCKET* sock, int protocol, const char* port);
        
        /**
         * @brief Resolves the given hostname to its long ip format.
         *
         * @param host          The host name to resolve.
         * @param lpOutput      Pointer to a ULONG to store the result.
         *
         * @return True on success, false otherwise.
         */
        static bool ResolveHostname(const char* host, PULONG lpOutput);

        /**
         * @brief Verifies the players login information; also handles creating new accounts.
         *
         * @param sock          The datasocket object with the connection socket.
         *
         * @return True on success, false otherwise.
         */
        static bool VerifyAccount(datasocket* sock);
        
        /**
         * @brief Starts the data communication between the client and server.
         *
         * @param lpParam       Thread param object.
         *
         * @return Non-important return.
         */
        static DWORD __stdcall FFXiServer(LPVOID lpParam);

        /**
         * @brief Starts the local listen server to lobby server communications.
         *
         * @param lpParam       Thread param object.
         *
         * @return Non-important return.
         */
        static DWORD __stdcall PolServer(LPVOID lpParam);
    };

}; // namespace xiloader

#endif // __XILOADER_NETWORK_H_INCLUDED__
