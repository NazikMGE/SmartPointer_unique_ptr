#include "class.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    unique_ptr<Menu> menu(new Menu);
    menu->mainMenu();
    return 0;
}