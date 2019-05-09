#include <iostream>
#include "econio.h"

int main() {
    econio_clrscr();
    econio_gotoxy(10, 20);
    econio_textcolor(COL_LIGHTGREEN);
    std::cout << "Hello world" << std::endl;

    return 0;
}
