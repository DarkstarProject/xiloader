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
extern bool g_Hide;

namespace xiloader
{
    /**
     * @brief Prints a text fragment with the specified color to the console.
     * 
     * @param c         The color to print the fragment with.
     * @param message   The fragment to print.
     */
    void console::print(xiloader::color c, std::string const& message)
    {
        auto stdout_handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
        ::CONSOLE_SCREEN_BUFFER_INFO info;
        ::GetConsoleScreenBufferInfo(stdout_handle, &info);
        auto attributes = info.wAttributes & 0xFFF0 | static_cast<::WORD>(c);
        ::SetConsoleTextAttribute(stdout_handle, static_cast<::WORD>(attributes));
        std::cout << message;
        ::SetConsoleTextAttribute(stdout_handle, info.wAttributes);
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

        auto console = ::GetConsoleWindow();

        // Adjust the task bar
        ::ITaskbarList* taskbar = nullptr;
        auto hr = ::CoCreateInstance(
            CLSID_TaskbarList,
            nullptr,
            ::CLSCTX_INPROC_SERVER,
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
        ::ShowWindow(console, visible ? SW_SHOW : SW_HIDE);
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
