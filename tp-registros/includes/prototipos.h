#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void ShowConsoleCursor();
void gotoxy();                                                                  ///GOTOXY
void recuadro();                                                                ///CREA RECUADROS
                                                      ///VISUALIZACION DEL CURSOR


void MenuPrincipal();                                                           ///MENU PRINCIPAL
void MenuUsuario();
void menuEntrenamiento ();

 struct Usuario{                                                                ///ESTRUCTURA DE LOS USUARIOS
    int     Id;                                                                 ///DEBE SER UN NUMERO ENTERO POSITIVO Y UNICO (NO PUEDE REPETIRSE)
    char    Nombre[50];                                                         ///DEBE SER UNA CADENA QUE ADMITA ESPACIOS, QUE NO PUEDA SER VACIA
    char    Apellido[50];                                                       ///DEBE SER UNA CADENA QUE ADMITA ESPACIOS, QUE NO PUEDA SER VACIA
    int     FechaNac;                                                           ///DEBE SER UNA FECHA VALIDA (EL USUARIO DEBE TENER MAYOR A 13 AÑOS)
    float   Altura;                                                             ///ES UN NUMERO REAL QUE NO PUEDE SER NEGATIVO
    float   Peso;                                                               ///ES UN NUMERO REAL QUE NO PUEDE SER NEGATIVO
    char    PerfilAct;                                                          ///DEBE SER DE CARACTER 'A'-'B'-'C' (PUEDE SER TAMBIEN EN MINUSCULAS)
    bool    AptoMedico;                                                         ///DEBE SER NUMEROS ENTEROS 1 o 0;
    bool    Estado;                                                             ///DENE SER VALOR BOOBEANO, (CUANDO SE CARGUE UN USUARIO DEBE SER TRUE)
};
Usuario CargarUsuario();
void CargaUsuario();
int  Fechasverificador();
bool GuardarUsuarios(Usuario);

void ModificarUsuario();
void BajaUsuario();

void ListarUsuarios();
int  BuscarId();
void ListarId();
void MostrarUsuario (Usuario);


struct entrenamiento{
    int     idEntrenamiento;
    int     IDUsuario;
    int     fechadeEntranmiento;
    int     actividad;
    float   calorias;
    int     tiempo;
};

entrenamiento Cargarentrenamiento();
void cargaEntrenamiento();
int autonumerico();
int fechasEnt(int dd, int mm, int aa);
bool guardarEntrenamiento(entrenamiento);


#endif // PROTOTIPOS_H_INCLUDED
