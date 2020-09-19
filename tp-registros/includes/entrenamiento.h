#ifndef ENTRENAMIENTO_H_INCLUDED
#define ENTRENAMIENTO_H_INCLUDED

entrenamiento Cargarentrenamiento(){
    entrenamiento   ent;
    system ("cls");
    int  dia, mes, anio, fecha;
    bool verificado;
    verificado = false;
    int cod;

    SetConsoleTextAttribute(hConsole, 6);                                       ///APARTADO VISUAL
    recuadro(26,10,46,25);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(31,11); cout << "          NUEVO ENTRENAMIENTO";
    gotoxy(27,12); cout << "---------------------------------------------";

    ShowConsoleCursor(true);
    gotoxy(27,20); cout << "     INGRESE UNA ID DE USUARIO EXISTE";
    SetConsoleTextAttribute(hConsole, 6);
    recuadro(34,22,30,2);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(35,23); cin >> cod;

    while(BuscarId(cod) <0){
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(37,26); cout << "ESTA ID NO FUE REGISTRADA";
        SetConsoleTextAttribute(hConsole, 7);
        gotoxy(35,23); cout << "               ";
        gotoxy(35,23); cin >> cod;
    }
    SetConsoleTextAttribute(hConsole, 2);
    gotoxy(37,26); cout << "                             ";
    gotoxy(42,26); cout << "ID ENCONTRADA!";
    SetConsoleTextAttribute(hConsole, 7);
    ShowConsoleCursor(false);
    system("pause");
    system ("cls");



    SetConsoleTextAttribute(hConsole, 6);                                       ///DISE�O DE LA CARGA DE DATOS
    recuadro(26,10,46,25);
    recuadro(26,36,46,2);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(31,37); cout <<"***PRESIONA ENTER CUANDO TERMINES***";
    SetConsoleTextAttribute(hConsole, 6);

    gotoxy(29,12); cout << "ID ENTRENAMIENTO";                                    ///ID ENTRENAMIENTO
    gotoxy(29,15); cout << "ID USUARIO";                                          ///ID USUARIO
    gotoxy(29,18); cout << "FECHA DE ENTRENAMIENTO";                              ///FECHA DE ENTRENAMIENTO
    gotoxy(29,21); cout << "ACTIVIDAD";                                           ///ACTIVIDAD
    gotoxy(29,24); cout << "CALORIAS";                                            ///CALOR�AS
    gotoxy(29,27); cout << "TIEMPO (EN MINUTOS)";                                 ///TIEMPO (EN MINUTOS)
    SetConsoleTextAttribute(hConsole, 7);                                         ///RECUADROS

    recuadro(52,11,18,2);
    recuadro(52,14,18,2);
    recuadro(52,17,18,2);
    recuadro(52,20,18,2);
    recuadro(52,23,18,2);
    recuadro(52,26,18,2);
    ShowConsoleCursor(true);
    int autoEnt;
    autoEnt = autonumerico();

    gotoxy(53,12); cout << autoEnt + 1;
    ent.idEntrenamiento = autoEnt + 1;
    gotoxy(53,15); cout << cod;
    ent.IDUsuario = cod;

    while(verificado!=true){
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(30,37); cout <<"PRESIONA ENTER PARA PASAR AL MES";
    gotoxy(53,18); cin >> dia;
    gotoxy(30,37); cout <<"                                        ";
    gotoxy(30,37); cout <<"PRESIONA ENTER PARA PASAR AL ANIO";
    gotoxy(56,18); cout <<"/"; cin >> mes;
    gotoxy(30,37); cout <<"                                        ";
    gotoxy(31,37); cout <<"PRESIONA ENTER CUANDO TERMINES";
    gotoxy(60,18); cout <<"/"; cin >> anio;

    ent.fechadeEntranmiento = dia + (mes * 100) + (anio * 10000);
    fecha = fechasEnt(dia,mes,anio);
    gotoxy(29,17); cout << "                      ";

    switch(fecha){
    case 1:
        SetConsoleTextAttribute(hConsole, 2);
        gotoxy(29,17); cout << "VERIFICADO";
        verificado = true;
    break;
    case 2:
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(29,17); cout << "EXCEDE LA FECHA ACTUAL";
        gotoxy(53,18); cout << "           ";
    break;
    case 3:
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(29,17); cout << "LA FECHA NO EXISTE";
        gotoxy(53,18); cout << "           ";
    break;
    }
    }
    int opc, pos = 1;
    opc = 1;
    while(true){                                                                ///APTO MEDICO DEL USUARIO
    switch(opc){
    case 77: //IZQUIERDA
    pos++;
    if(pos>5){pos=1;}
    break;
    case 75: //DERECHA
    pos--;
    if(pos<1){pos=5;}
    break;
    case 13: //ENTER
        switch(pos){
        case 1:
            ent.actividad = 1;
            SetConsoleTextAttribute(hConsole, 2);
            gotoxy(29,20); cout << "HABILITADO";
            SetConsoleTextAttribute(hConsole, 7);
            ShowConsoleCursor(true);
            gotoxy(53,24); cin >> ent.calorias;
            gotoxy(53,27); cin >> ent.tiempo;
            guardarEntrenamiento(ent);
        break;
        case 2:
            ent.actividad = 2;
            SetConsoleTextAttribute(hConsole, 2);
            gotoxy(29,20); cout << "HABILITADO";
            SetConsoleTextAttribute(hConsole, 7);
            ShowConsoleCursor(true);
            gotoxy(53,24); cin >> ent.calorias;
            gotoxy(53,27); cin >> ent.tiempo;
            guardarEntrenamiento(ent);
        break;
        case 3:
            ent.actividad = 3;
            SetConsoleTextAttribute(hConsole, 2);
            gotoxy(29,20); cout << "HABILITADO";
            SetConsoleTextAttribute(hConsole, 7);
            ShowConsoleCursor(true);
            gotoxy(53,24); cin >> ent.calorias;
            gotoxy(53,27); cin >> ent.tiempo;
            guardarEntrenamiento(ent);
        break;
        case 4:
            Usuario user;
            FILE * f;
            f = fopen("UsuariosC.dat","rb");
            fseek(f,(BuscarId(cod))*sizeof(Usuario),SEEK_SET);
            fread(&user,sizeof(Usuario),1,f);
            if(user.AptoMedico == true){
            SetConsoleTextAttribute(hConsole, 2);
            gotoxy(29,20); cout << "CUMPLE APTO MEDICO";
            SetConsoleTextAttribute(hConsole, 7);
            gotoxy(53,24); cin >> ent.calorias;
            gotoxy(53,27); cin >> ent.tiempo;
            guardarEntrenamiento(ent);
            ShowConsoleCursor(true);
            }
            else{
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(29,20); cout << "NO CUMPLE APTO MEDICO";
            }
            SetConsoleTextAttribute(hConsole, 7);
            fclose(f);
        break;
        case 5:
            f = fopen("UsuariosC.dat","rb");
            fseek(f,(BuscarId(cod))*sizeof(Usuario),SEEK_SET);
            fread(&user,sizeof(Usuario),1,f);
            if(user.AptoMedico == true){
            SetConsoleTextAttribute(hConsole, 2);
            gotoxy(29,20); cout << "CUMPLE APTO MEDICO";
            SetConsoleTextAttribute(hConsole, 7);
            gotoxy(53,24); cin >> ent.calorias;
            gotoxy(53,27); cin >> ent.tiempo;
            guardarEntrenamiento(ent);
            ShowConsoleCursor(true);
            }
            else{
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(29,20); cout << "NO CUMPLE APTO MEDICO";
            }
            SetConsoleTextAttribute(hConsole, 7);
            fclose(f);
        break;
        }
        }
        switch(pos){
    case 1:
    ShowConsoleCursor(false);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(53,21); cout << "               ";
    recuadro(52,20,18,2); gotoxy(53,21); cout << "CAMINATA";
    break;
    case 2:
    ShowConsoleCursor(false);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(53,21); cout << "               ";
    recuadro(52,20,18,2); gotoxy(53,21); cout << "CORRER";
    break;
    case 3:
    ShowConsoleCursor(false);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(53,21); cout << "               ";
    recuadro(52,20,18,2); gotoxy(53,21); cout << "BICICLETA";
    break;
    case 4:
    ShowConsoleCursor(false);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(53,21); cout << "               ";
    recuadro(52,20,18,2); gotoxy(53,21); cout << "NATACION";
    break;
    case 5:
    ShowConsoleCursor(false);
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(53,21); cout << "               ";
    recuadro(52,20,18,2); gotoxy(53,21); cout << "PESAS";
    break;
    }
    opc = getch();
    gotoxy(29,20); cout << "                      ";


}


system("pause");
}

int autonumerico(){
    int autoEnt;
    FILE * f;
    f = fopen ( "entrenamientosC.dat", "rb");
    if (f == NULL){
        return 0;
    }
    fseek (f, 0, SEEK_END);

    autoEnt = ftell(f) / sizeof(entrenamiento);

    fclose(f);

    return autoEnt;
    }

int fechasEnt(int dd, int mm, int aa){                                  //ESTA FUNCION VERIFICARA SI LA FECHA EXISTE Y SI ES MAYOR A 13 A�OS
    int fechaUsuario, fechaActual, diferencia, opcion;
    bool Existe;
    bool Mayor;

    Mayor  = false;                                                             ///PARA SABER SI ES MAYOR A 13 A�OS
    Existe = false;                                                             ///PARA SABER SI LA FECHA EXISTE
    fechaUsuario = (aa*10000) + (mm * 100) + dd;                                ///CALCULO DE LA FECHA EN SUMA

        switch(mm){                                                             ///COMPRUEBA QUE SEA UNA FECHA VALIDA
        case 1:                                                                 ///ENERO
            if(dd>0 && dd<=31 && aa>=0){
                Existe = true;
            }
        break;
        case 2:                                                                 ///FEBRERO
            if(aa%4==0 || aa%100==0 || aa%400==0){                              ///EN CASO DE UN A�O BICIESTO
                if(dd>0 && dd<=29 && aa>=0){
                    Existe = true;
                }
            }
            else{
                if(dd>0 && dd<=28 && aa>=0){                                    ///EN CASO DE QUE NO SEA BICIESTO
                    Existe = true;
                }
            }
        break;
        case 3:                                                                 ///MARZO
            if(dd>0 && dd<=31 && aa>=0){
                Existe = true;
            }
        break;
        case 4:                                                                 ///ABRIL
            if(dd>0 && dd<=30 && aa>=0){
                Existe = true;
            }
        break;
        case 5:                                                                 ///MAYO
            if(dd>0 && dd<=31 && aa>=0){
                Existe = true;
            }
        break;
        case 6:                                                                 ///JUNIO
            if(dd>0 && dd<=30 && aa>=0){
                Existe = true;
            }
        break;
        case 7:                                                                 ///JULIO
            if(dd>0 && dd<=31 && aa>=0){
                Existe = true;
            }
        break;
        case 8:                                                                 ///AGOSTO
            if(dd>0 && dd<=31 && aa>=0){
                Existe = true;
            }
        break;
        case 9:                                                                 ///SEPTIEMBRE
            if(dd>0 && dd<=30 && aa>=0){
                Existe = true;
            }
        break;
        case 10:                                                                ///OCTUBRE
            if(dd>0 && dd<=31 && aa>=0){
                Existe = true;
            }
        break;
        case 11:                                                                ///NOVIEMBRE
            if(dd>0 && dd<=30 && aa>=0){
                Existe = true;
            }
        break;
        case 12:                                                                ///DICIEMBRE
            if(dd>0 && dd<=31 && aa>=0){
                Existe = true;
            }
        break;
        default:                                                                ///SI LA FECHA NO EXISTE
            Existe = false;
        break;
        }
        time_t tiempo;                                                           ///SACARA LA FECHA ACTUAL
        struct tm * tmPtr;
        tiempo = time(NULL);
        tmPtr  = localtime(&tiempo);
        fechaActual = tmPtr->tm_mday + ((tmPtr->tm_mon+1) * 100) + ((1900+tmPtr->tm_year) * 10000);

        diferencia = fechaActual - fechaUsuario;                                ///COMPARA LAS FECHAS PARA SABER SI ES MAYOR A 13 A�OS
        if(diferencia < 0){
            Mayor = true;
        }
        if(Existe == true && Mayor == false){                                    ///EN CASO DE QUE LA FECHA EXISTE Y SEA MAYOR
            opcion = 1;
        }
        else if(Existe == true && Mayor == true){                              ///EN CASO QUE NO SEA MAYOR DE 13 A�OS
            opcion = 2;
        }
        else{                                                                   ///EN CASO QUE LA FECHA NO EXISTE
            opcion = 3;
        }
    return opcion;
}

bool guardarEntrenamiento(entrenamiento ent){                           //FUNCION GUARDAR USUARIO
    bool grabo;
    FILE *f;
    f = fopen("entrenamientosC.dat","ab");                                            ///CREARA UN ARCHIVO
    if(f == NULL){
        return false;                                                           ///EN CASO DE QUE NO PUEDA CREARLO
    }
    fwrite(&ent, sizeof(entrenamiento),1,f);                                         ///ESCRIBIRA EL STRUCT "USUARIO" EN EL ARCHIVO
    fclose(f);
}

void mostrarEntrenamiento(entrenamiento ent){                                      //MOSTRAR USUARIOS
    SetConsoleTextAttribute(hConsole, 7);
    cout << "\t \t \t \t ================================" << endl;
    cout << "\t \t \t \t ID ENTRENAMIENTO: "        << ent.idEntrenamiento << endl;               ///ID
    cout << "\t \t \t \t ID USUARIO: "              << ent.IDUsuario << endl;                     ///NOMBRE
    cout << "\t \t \t \t FECHA DE ENTRENAMIENTO: "  << ent.fechadeEntranmiento << endl;           ///APELLIDO

    if(ent.actividad == 1){                                                ///APTO MEDICO
        cout << "\t \t \t \t ACTIVIDAD: CAMINATA" << endl;
    }
    else if(ent.actividad == 2){
        cout << "\t \t \t \t ACTIVIDAD: CORRER" << endl;
    }
    else if(ent.actividad == 3){                                                    ///ESTADO
        cout << "\t \t \t \t ACTIVIDAD: BICICLETA"  << endl;
    }
    else if(ent.actividad == 4){                                                    ///ESTADO
        cout << "\t \t \t \t ACTIVIDAD: NATACION"  << endl;
    }
    else {                                                    ///ESTADO
        cout << "\t \t \t \t ACTIVIDAD: PESAS"  << endl;
    }
    cout << "\t \t \t \t CALORIAS: "                << ent.calorias << endl;
    cout << "\t \t \t \t TIEMPO: "                  << ent.tiempo << endl;
    cout << "\t \t \t \t ================================" << endl << endl;
}

void listarEntrenamiento(){                                                  //FUNCION LISTAR USUARIO
    system("cls");
    entrenamiento ent;
    FILE * f;
    f = fopen("entrenamientosC.dat","rb");                                            ///LEERA EL ARCHIVO CREADO
    if(f == NULL){                                                              ///EN CASO DE QUE NO CONTEGA DATOS
        return;
    }
    while(fread(&ent, sizeof(entrenamiento),1,f)){                                   ///EN CASO DE QUE TENGA DATOS, LEERA DE A UNO
         mostrarEntrenamiento(ent);
    }
    fclose(f);
    system("pause");
    menuEntrenamiento();                                                              ///VUELVE AL MENU USUARIO
}
#endif // ENTRENAMIENTO_H_INCLUDED
