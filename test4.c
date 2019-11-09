#include <stdio.h>
#include "econio.h"

int main(void) {
    struct col {
        int col;
        char const *name;
    } cols[] = {
        {COL_BLACK, "COL_BLACK"},
        {COL_BLUE, "COL_BLUE"},
        {COL_GREEN, "COL_GREEN"},
        {COL_CYAN, "COL_CYAN"},
        {COL_RED, "COL_RED"},
        {COL_MAGENTA, "COL_MAGENTA"},
        {COL_BROWN, "COL_BROWN"},
        {COL_LIGHTGRAY, "COL_LIGHTGRAY"},
        {COL_DARKGRAY, "COL_DARKGRAY"},
        {COL_LIGHTBLUE, "COL_LIGHTBLUE"},
        {COL_LIGHTGREEN, "COL_LIGHTGREEN"},
        {COL_LIGHTCYAN, "COL_LIGHTCYAN"},
        {COL_LIGHTRED, "COL_LIGHTRED"},
        {COL_LIGHTMAGENTA, "COL_LIGHTMAGENTA"},
        {COL_YELLOW, "COL_YELLOW"},
        {COL_WHITE, "COL_WHITE"},
    };

    for (int i = 0; i < sizeof(cols)/sizeof(*cols); ++i) {
        econio_textcolor(cols[i].col);
        printf("%s\n", cols[i].name);
    }
    econio_textcolor(COL_RESET);
    printf("\n");

    for (int i = 0; i < sizeof(cols)/sizeof(*cols); ++i) {
        econio_textbackground(cols[i].col);
        printf("%s\n", cols[i].name);
    }
    econio_textbackground(COL_RESET);
}
