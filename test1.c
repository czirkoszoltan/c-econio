#include <stdio.h>
#include <stdbool.h>
#include "econio.h"

int main() {
    // Init
    econio_set_title("python-econio test");

    // Positioning;
    econio_clrscr();
    econio_gotoxy(0, 0);
    econio_textcolor(COL_LIGHTGREEN);
    printf("Hello");
    econio_gotoxy(10, 0);
    econio_textbackground(COL_LIGHTBLUE);
    printf("world!");
    printf("\n");

    // Color combinations;
    for (int b = 0; b < 16; ++b) {
        econio_gotoxy(5, 5+b);
        for (int t = 0; t < 16; ++t) {
            econio_textcolor(t);
            econio_textbackground(b);
            printf(" X ");
        }
        printf("\n");
    }
    printf("\n");

    // Raw input;
    econio_textbackground(COL_RESET);
    econio_textcolor(COL_RESET);
    printf("Raw input test, press keys and then Enter:\n");
    econio_rawmode();
    while (true) {
        int ch = econio_getch();
        if (ch == KEY_ENTER)
            break;
        printf("%d ", ch);
    }
    printf("\n");
    econio_normalmode();

    // Raw input buffering;
    printf("Raw input buffering test, 3s delay, press any keys\n");
    econio_rawmode();
    econio_sleep(3);
    if (!econio_kbhit()) {
        printf("No keys pressed.");
    } else {
        while (econio_kbhit()) {
            printf("%d ", econio_getch());
        }
        printf("\n");
    }
    printf("\n");
    econio_normalmode();

    // Normal input;
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s", name);
    
    return 0;
}
