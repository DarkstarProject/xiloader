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

#include <windows.h>
#include <iostream>
#include <string>
#include <time.h>

namespace xiloader
{
    /**
     * @brief Color namespace containing console color information.
     */
    namespace color
    {
        /**
        * @brief Console color enumeration.
        */
        enum colors
        {
            /* Custom color code to print out the current timestamp. */
            timestamp = 0,

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

    }; // namespace color

    /**
     * @brief Operator overload to handle custom color tags in an ostream.
     *
     * @param s     The incoming stream to append to.
     * @param c     The color tag to set the console foreground to.
     *
     * @return The incoming stream.
     */
    inline std::ostream& operator << (std::ostream& s, const xiloader::color::colors& c);

    /**
     * @brief Console class containing helper functions for console output.
     */
    class console
    {
    public:

        /**
         * @brief Prints the given message to the console.
         *
         * @param format    The format of the message to print.
         * @param ...       The arguments to fill the format.
         */
        static void output(const char* format, ...);

        /**
         * @brief Prints the given message to the console with a specific color.
         *
         * @param c         The color to print the message with.
         * @param format    The format of the message to print.
         * @param ...       The arguments to fill the format.
         */
        static void output(const xiloader::color::colors& c, const char* format, ...);
    };

}; // namespace xiloader

#endif // __XILOADER_CONSOLE_H_INCLUDED__
