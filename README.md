# Econio library for C and C++

Colored output and raw keyboard handling for Linux and Windows console in C and C++.

This package is created for educational purposes. For the Windows version, it uses code from the econio library written by Eric Tetz.


## Screen and cursor positioning

See the functions in `econio.h`:

```c
#include <stdio.h>
#include "econio.h"

int main() {
    econio_clrscr();
    econio_gotoxy(10, 0);
    printf("Hello world!\n");
    return 0;
}
```


## Colored output

See the constants in `econio.h`:

```c
econio_textcolor(COL_LIGHTGREEN);
econio_textbackground(COL_BLUE);
printf("Hello world!\n");
```


## Buffered output

Stdout is usually buffered, and buffer is flushed when printing a newline `'\n'` char.
So a entire scene can be drawn without flickering, then you can use `econio_flush()`.
But econio tries to handle that the same way the standard library does, by flushing the
output when input is requested.


## Line-oriented input

Just use `scanf()` or `fgets()` as usual.


## Raw keyboard input

Switch to raw mode using `econio_rawmode()`. Then use `econio_kbhit()` to check
if a key is pressed. `econio_getch()` returns an ASCII code or a key code
(see `econio.h`). Finally, call `econio_normalmode()`.

```c
#include <stdio.h>
#include <stdbool.h>
#include "econio.h"

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
    econio_clrscr();
    printf("Use cursor keys to control the asterisk");

    int x = 40;
    int y = 12;
    econio_rawmode();
    while (true) {
        econio_gotoxy(x, y);
        econio_textcolor(COL_LIGHTGREEN);
        printf("*");
        econio_gotoxy(80, 24);
        
        int key = econio_getch();
        econio_gotoxy(x, y);
        econio_textcolor(COL_BLUE);
        printf(".");

        if (key == KEY_UP)
            y = max(y-1, 1);
        else if (key == KEY_DOWN)
            y = min(y+1, 23);
        else if (key == KEY_LEFT)
            x = max(x-1, 0);
        else if (key == KEY_RIGHT)
            x = min(x+1, 79);
        else if (key == KEY_ESCAPE)
            break;
    }
    econio_normalmode();
    
    return 0;
}
```

## C++

Works with C++ as well. You can rename `econio.c` to `econio.cpp`, and compile as C++, if needed.

## License

MIT licensed.
