/*
 * DisplaySize.hpp
 *
 *  Created on: 10 Jan 2017
 *      Author: David
 */

#ifndef SRC_DISPLAYSIZE_HPP_
#define SRC_DISPLAYSIZE_HPP_

#include "Configuration.hpp"
#include "Hardware/DisplayOrientation.hpp"

typedef uint16_t PixelNumber;

// From the display type, we determine the display controller type and touch screen orientation adjustment
#if DISPLAY_TYPE == DISPLAY_TYPE_ITDB02_32WD

# define DISPLAY_CONTROLLER		HX8352A
const DisplayOrientation DefaultDisplayOrientAdjust = static_cast<DisplayOrientation>(SwapXY | ReverseY | InvertBitmap);
const DisplayOrientation DefaultTouchOrientAdjust = static_cast<DisplayOrientation>(ReverseY);
const bool is24BitLcd = true;
# define DISPLAY_X				(400)
# define DISPLAY_Y				(240)

#elif DISPLAY_TYPE == DISPLAY_TYPE_ITDB02_43

# define DISPLAY_CONTROLLER		SSD1963_480
const DisplayOrientation DefaultDisplayOrientAdjust = static_cast<DisplayOrientation>(SwapXY | ReverseX | InvertBitmap);
const DisplayOrientation DefaultTouchOrientAdjust = SwapXY;
const bool is24BitLcd = true;
# define DISPLAY_X				(480)
# define DISPLAY_Y				(272)

#elif DISPLAY_TYPE == DISPLAY_TYPE_ITDB02_50

# define DISPLAY_CONTROLLER		SSD1963_800
const DisplayOrientation DefaultDisplayOrientAdjust = static_cast<DisplayOrientation>(SwapXY | ReverseX | InvertBitmap);
const DisplayOrientation DefaultTouchOrientAdjust = static_cast<DisplayOrientation>(SwapXY | ReverseY);
const bool is24BitLcd = true;
# define DISPLAY_X				(800)
# define DISPLAY_Y				(480)

#elif DISPLAY_TYPE == DISPLAY_TYPE_ITDB02_70

# define DISPLAY_CONTROLLER		SSD1963_800
const DisplayOrientation DefaultDisplayOrientAdjust = static_cast<DisplayOrientation>(SwapXY | ReverseX | ReverseY | InvertText | InvertBitmap);
const DisplayOrientation DefaultTouchOrientAdjust = static_cast<DisplayOrientation>(SwapXY | ReverseY);
const bool is24BitLcd = false;
# define DISPLAY_X				(800)
# define DISPLAY_Y				(480)

#else
# error DISPLAY_TYPE is not defined correctly
#endif

const PixelNumber DisplayX = DISPLAY_X;
const PixelNumber DisplayY = DISPLAY_Y;

#endif /* SRC_DISPLAYSIZE_HPP_ */
