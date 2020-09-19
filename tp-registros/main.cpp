#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                              ///FUNCION PARA PINTAR
using namespace std;
#include "includes/prototipos.h"
#include "includes/visuales.h"
#include "includes/menues.h"
#include "includes/usuarios.h"
#include "includes/entrenamiento.h"
                                                                ///LISTARA LA ID DEL USUARIO


int main(){
    /*ShowConsoleCursor(false);                                                               //MAIN PRINCIPAL
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(26,10,46,21);
    SetConsoleTextAttribute(hConsole, 7);
    MenuPrincipal();*/
    MenuPrincipal();
    return 0;
}
