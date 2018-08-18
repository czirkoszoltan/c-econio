#ifndef ECONIO_H
#define ECONIO_H

#include <stdbool.h>


typedef enum EconioColor {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,    LIGHTYELLOW = YELLOW,
    WHITE = 15,
    RESET = 16,
} EconioColor;


typedef enum EconioKey {
    // function keys are not supported on Windows
    F1 = -1,
    F2 = -2,
    F3 = -3,
    F4 = -4,
    F5 = -5,
    F6 = -6,
    F7 = -7,
    F8 = -8,
    F9 = -9,
    F10 = -10,
    F11 = -11,
    F12 = -12,

    UP = -20,
    DOWN = -21,
    LEFT = -22,
    RIGHT = -23,
    PAGEUP = -24,
    PAGEDOWN = -25,
    HOME = -26,
    END = -27,
    INSERT = -28,
    DELETE = -29,

    CTRLUP = -30,
    CTRLDOWN = -31,
    CTRLLEFT = -32,
    CTRLRIGHT = -33,
    CTRLPAGEUP = -34,
    CTRLPAGEDOWN = -35,
    CTRLHOME = -36,
    CTRLEND = -37,
    CTRLINSERT = -38,
    CTRLDELETE = -39,

    UNKNOWNKEY = -255,

    BACKSPACE = 8,
    ENTER = 10,
    ESCAPE = 27,
    TAB = 9,
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


#endif
