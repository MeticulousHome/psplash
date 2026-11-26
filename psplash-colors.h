/*
 *  pslash - a lightweight framebuffer splashscreen for embedded devices.
 *
 *  Copyright (c) 2012 sleep(5) ltd
 *  Author: Tomas Frydrych <tomas@sleepfive.com>
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#ifndef _HAVE_PSPLASH_COLORS_H
#define _HAVE_PSPLASH_COLORS_H

/* This is the overall background color */
#define PSPLASH_BACKGROUND_COLOR 0x00,0x00,0x00

/* This is the color of any text output */
#define PSPLASH_TEXT_COLOR 0xFF,0xFF,0xFF

/* This is the color of the progress bar indicator */
#define PSPLASH_BAR_COLOR 0xFF,0xFF,0xFF

/* This is the color of the progress bar background */
#define PSPLASH_BAR_BACKGROUND_COLOR 0x00,0x00,0x00

/* The light theme (--theme-file): the Dial's light background and text colors (meticulous-dial
 * qt/qml/Dial/Core/Theme.qml), so that the boot looks the same until the Dial takes over. */
#define PSPLASH_LIGHT_BACKGROUND_COLOR 0xF3,0xF0,0xE9
#define PSPLASH_LIGHT_TEXT_COLOR 0x1C,0x1A,0x17
#define PSPLASH_LIGHT_BAR_COLOR 0x1C,0x1A,0x17
#define PSPLASH_LIGHT_BAR_BACKGROUND_COLOR 0xF3,0xF0,0xE9

#endif
