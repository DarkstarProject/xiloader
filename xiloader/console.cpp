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

#include "console.h"

#include <ShObjIdl.h>

/* Global Externs */
extern CRITICAL_SECTION g_CriticalSection;
extern bool g_Hide;

namespace xiloader
{
    /**
     * @brief Operator overload to handle custom color tags in an ostream.
     *
     * @param s         The incoming stream to append to.
     * @param c         The color tag to set the console foreground to.
     *
     * @return The incoming stream.
     */
    inline std::ostream& operator << (std::ostream& s, const xiloader::color::colors& c)
    {
        EnterCriticalSection(&g_CriticalSection);

        /* Print timestamp if requested.. */
        if (c == xiloader::color::timestamp)
        {
            __time32_t rawtime;
            struct tm timeinfo;

            /* Get the current timestamp.. */
            _time32(&rawtime);
            _localtime32_s(&timeinfo, &rawtime);

            /* Format the timestamp.. */
            char timestamp[256];
            strftime(timestamp, sizeof(timestamp), "[%m/%d/%y %H:%M:%S] ", &timeinfo);

            /* Output the timestamp.. */
            s << xiloader::color::lightyelllow << timestamp;
            LeaveCriticalSection(&g_CriticalSection);
            return s;
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)c);
        LeaveCriticalSection(&g_CriticalSection);
        return s;
    }

    /**
     * @brief Prints the given message to the console.
     *
     * @param format    The format of the message to print.
     * @param ...       The arguments to fill the format.
     */
    void console::output(const char* format, ...)
    {
        EnterCriticalSection(&g_CriticalSection);

        __time32_t rawtime;
        struct tm timeinfo;
        va_list args;

        /* Get the current timestamp.. */
        _time32(&rawtime);
        _localtime32_s(&timeinfo, &rawtime);

        /* Parse the incoming message.. */
        char buffer[1024] = { 0 };
        va_start(args, format);
        vsprintf_s(buffer, format, args);
        va_end(args);

        /* Format the timestamp.. */
        char timestamp[256];
        strftime(timestamp, sizeof(timestamp), "[%m/%d/%y %H:%M:%S] ", &timeinfo);

        /* Output the timestamp and message.. */
        std::cout << std::endl << xiloader::color::lightyelllow << timestamp << xiloader::color::white << buffer;

        LeaveCriticalSection(&g_CriticalSection);
    }

    /**
     * @brief Prints the given message to the console with a specific color.
     *
     * @param c         The color to print the message with.
     * @param format    The format of the message to print.
     * @param ...       The arguments to fill the format.
     */
    void console::output(const xiloader::color::colors& c, const char* format, ...)
    {
        EnterCriticalSection(&g_CriticalSection);

        __time32_t rawtime;
        struct tm timeinfo;
        va_list args;

        /* Get the current timestamp.. */
        _time32(&rawtime);
        _localtime32_s(&timeinfo, &rawtime);

        /* Parse the incoming message.. */
        char buffer[1024] = { 0 };
        va_start(args, format);
        vsprintf_s(buffer, format, args);
        va_end(args);

        /* Format the timestamp.. */
        char timestamp[256];
        strftime(timestamp, sizeof(timestamp), "[%m/%d/%y %H:%M:%S] ", &timeinfo);

        /* Output the timestamp and message.. */
        std::cout << std::endl << xiloader::color::lightyelllow << timestamp << c << buffer;

        LeaveCriticalSection(&g_CriticalSection);
    }

    /**
     * @brief Shows or hides the console based on the provided argument.
     *
     * @param visible   "true" to show the console, "false" to hide it.
     */
    void console::visible(bool visible)
    {
        if (!g_Hide)
            return;

        HWND console = GetConsoleWindow();

        // Adjust the task bar
        ITaskbarList* taskbar = nullptr;
        HRESULT hr = CoCreateInstance(
            CLSID_TaskbarList,
            nullptr,
            CLSCTX_INPROC_SERVER,
            IID_ITaskbarList,
            reinterpret_cast<void**>(&taskbar));
        if (SUCCEEDED(hr))
        {
            if (visible)
            {
                taskbar->AddTab(console);
            }
            else
            {
                taskbar->DeleteTab(console);
            }
            taskbar->Release();
        }

        // Adjust the window's visibility
        ShowWindow(console, visible ? SW_SHOW : SW_HIDE);
    }

    /**
     * @brief Hides the console window.
     */
    void console::hide()
    {
        visible(false);
    }

    /**
     * @brief Shows the console window.
     */
    void console::show()
    {
        visible(true);
    }

}; // namespace xiloader
