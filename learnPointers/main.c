#include <locale.h>

#include "libs/menu.h"

int main() {
    setlocale(LC_ALL, "PORTUGUESE");
    menu();
    return 0;
}
