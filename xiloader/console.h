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

#ifndef __XILOADER_CONSOLE_H_INCLUDED__
#define __XILOADER_CONSOLE_H_INCLUDED__

#if defined (_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <Windows.h>
#include <iostream>
#include <string>
#include <ctime>

namespace xiloader
{
    /**
    * @brief Console color enumeration.
    */
    enum class color
    {
        /* Red color codes. */
        red = FOREGROUND_RED,
        lightred = FOREGROUND_RED | FOREGROUND_INTENSITY,

        /* Green color codes. */
        green = FOREGROUND_GREEN,
        lightgreen = FOREGROUND_GREEN | FOREGROUND_INTENSITY,

        /* Blue color codes. */
        blue = FOREGROUND_BLUE,
        lightblue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,

        /* Cyan color codes. */
        cyan = FOREGROUND_BLUE | FOREGROUND_GREEN,
        lightcyan = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,

        /* Yellow color codes. */
        yellow = FOREGROUND_GREEN | FOREGROUND_RED,
        lightyelllow = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,

        /* Purple color codes. */
        purple = FOREGROUND_BLUE | FOREGROUND_RED,
        lightpurple = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,

        /* White color codes. */
        grey = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        white = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,

        /* Common color codes. */
        debug = lightcyan,
        error = lightred,
        info = white,
        success = lightgreen,
        warning = lightyelllow
    };

    /**
     * @brief Console class containing helper functions for console output.
     */
    class console
    {
    private:

        /**
         * @brief Shows or hides the console based on the provided argument.
         *
         * @param visible   "true" to show the console, "false" to hide it.
         */
        static void visible(bool visible);

        /**
         * @brief Prints a text fragment with the specified color to the console.
         * 
         * @param c         The color to print the fragment with.
         * @param message   The fragment to print.
         */
        static void print(xiloader::color c, std::string const& message);

    public:

        /**
         * @brief Prints the given message to the console.
         *
         * @param format    The format of the message to print.
         * @param args      The arguments to fill the format.
         */
        template<typename... Args>
        static void output(char const* format, Args... args)
        {
            output(xiloader::color::white, format, args...);
        }

        /**
         * @brief Prints the given message to the console with the specific color.
         *
         * @param c         The color to print the message with.
         * @param format    The format of the message to print.
         * @param args      The arguments to fill the format.
         */
        template<typename... Args>
        static void output(xiloader::color c, char const* format, Args... args)
        {
            /* Get the current timestamp */
            ::__time32_t rawtime;
            ::_time32(&rawtime);

            ::tm timeinfo;
            ::_localtime32_s(&timeinfo, &rawtime);

            /* Format the timestamp */
            char timestamp[256];
            ::strftime(timestamp, sizeof timestamp, "[%m/%d/%y %H:%M:%S] ", &timeinfo);

            /* Output the timestamp */
            print(xiloader::color::lightyelllow, timestamp);

            /* Parse the incoming message */
            char buffer[1024];
            ::snprintf(buffer, sizeof buffer, format, args...);
            /* Output the message */

            print(c, buffer);

            std::cout << std::endl;
        }

        /**
         * @brief Hides the console window.
         */
        static void hide();

        /**
         * @brief Shows the console window.
         */
        static void show();
    };

}; // namespace xiloader

#endif // __XILOADER_CONSOLE_H_INCLUDED__
