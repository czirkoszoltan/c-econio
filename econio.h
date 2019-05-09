#ifndef ECONIO_H
#define ECONIO_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum EconioColor {
    COL_BLACK = 0,
    COL_BLUE = 1,
    COL_GREEN = 2,
    COL_CYAN = 3,
    COL_RED = 4,
    COL_MAGENTA = 5,
    COL_BROWN = 6,
    COL_LIGHTGRAY = 7,
    COL_DARKGRAY = 8,
    COL_LIGHTBLUE = 9,
    COL_LIGHTGREEN = 10,
    COL_LIGHTCYAN = 11,
    COL_LIGHTRED = 12,
    COL_LIGHTMAGENTA = 13,
    COL_YELLOW = 14,    COL_LIGHTYELLOW = COL_YELLOW,
    COL_WHITE = 15,
    COL_RESET = 16,
} EconioColor;


typedef enum EconioKey {
    // function keys are not supported on Windows
    KEY_F1 = -1,
    KEY_F2 = -2,
    KEY_F3 = -3,
    KEY_F4 = -4,
    KEY_F5 = -5,
    KEY_F6 = -6,
    KEY_F7 = -7,
    KEY_F8 = -8,
    KEY_F9 = -9,
    KEY_F10 = -10,
    KEY_F11 = -11,
    KEY_F12 = -12,

    KEY_UP = -20,
    KEY_DOWN = -21,
    KEY_LEFT = -22,
    KEY_RIGHT = -23,
    KEY_PAGEUP = -24,
    KEY_PAGEDOWN = -25,
    KEY_HOME = -26,
    KEY_END = -27,
    KEY_INSERT = -28,
    KEY_DELETE = -29,

    KEY_CTRLUP = -30,
    KEY_CTRLDOWN = -31,
    KEY_CTRLLEFT = -32,
    KEY_CTRLRIGHT = -33,
    KEY_CTRLPAGEUP = -34,
    KEY_CTRLPAGEDOWN = -35,
    KEY_CTRLHOME = -36,
    KEY_CTRLEND = -37,
    KEY_CTRLINSERT = -38,
    KEY_CTRLDELETE = -39,

    KEY_UNKNOWNKEY = -255,

    KEY_BACKSPACE = 8,
    KEY_ENTER = 10,
    KEY_ESCAPE = 27,
    KEY_TAB = 9,
} EconioKey;


/** 
 * Change text color to the one specified. See the color constants in
 * the colors header. */
void econio_textcolor(int color);


/** 
 * Change background color to the one specified. See the color constants in
 * the colors header.
 */
void econio_textbackground(int color);


/** Jump to position (x, y) with the cursor. Upper left corner is (0, 0). */
void econio_gotoxy(int x, int y);


/** Clear the screen and return the cursor to the upper left position. */
void econio_clrscr();


/**
 * Send output to the terminal. To be called if many characters were
 * drawn to the terminal and there was no \n at the end.
 */
void econio_flush();


/** Set the title of the terminal window. */
void econio_set_title(char const *title);


/** 
 * Switch the terminal to raw mode, to detect F1-F10, cursor keys and
 * other controlling keys. Use econio_getch() and econio_kbhit() afterwards.
 * Characters are not echoed to the screen when in raw mode.
 * Switching back to line-oriented mode is possible using econio_normalmode().
 */
void econio_rawmode();


/** 
 * Switch the terminal back to normal, line-oriented mode. Characters
 * are echoed to the screen when in normal mode.
 */
void econio_normalmode();


/** 
 * Detect if a key is pressed. If so, it can be read with econio_getch().
 * Only to be used after calling econio_rawmode().
 */
bool econio_kbhit();


/**
 * Get one raw character from terminal. This can detect F1-F10, cursor keys,
 * backspace and other controlling keys: see the keyboard constants.
 * ASCII code is returned for other keys. Non-ASCII keys probably won't work.
 * Characters are not echoed to the screen when in raw mode.
 * Only to be used after calling econio_rawmode().
 * Note that backspace will be code 8, regardless of terminal settings
 * (whether it sent BS or DEL char). Enter will always be 10, even on Windows.
 * On Windows, this function sometimes returns 0's, so just ignore them.
 * Also function keys are not supported on Windows.
 */
int econio_getch();


/**
 * Delay for the specified amount of time (sec can be an arbitrary floating
 * point number, not just integer).
 */
void econio_sleep(double sec);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
