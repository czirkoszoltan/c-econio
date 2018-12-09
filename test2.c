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
