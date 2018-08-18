# C language econio library

Colored output and raw keyboard handling for Linux and Windows console in C.

This package is created for educational purposes. For the Windows version, it uses code from the econio library of Eric Tetz.


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
econio_textcolor(LIGHTGREEN);
econio_textbackground(BLUE);
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
        econio_textcolor(LIGHTGREEN);
        printf("*");
        econio_gotoxy(80, 24);
        
        int key = econio_getch();
        econio_gotoxy(x, y);
        econio_textcolor(BLUE);
        printf(".");

        if (key == UP)
            y = max(y-1, 1);
        else if (key == DOWN)
            y = min(y+1, 23);
        else if (key == LEFT)
            x = max(x-1, 0);
        else if (key == RIGHT)
            x = min(x+1, 79);
        else if (key == ESCAPE)
            break;
    }
    econio_normalmode();
    
    return 0;
}
```

## License

MIT licensed.
