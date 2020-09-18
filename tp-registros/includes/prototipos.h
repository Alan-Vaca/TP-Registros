#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void gotoxy();                                                                  ///GOTOXY
void recuadro();                                                                ///CREA RECUADROS
void ShowConsoleCursor();                                                       ///VISUALIZACION DEL CURSOR
void MenuPrincipal();                                                           ///MENU PRINCIPAL
void MenuUsuario();
void menuEntrenamiento ();                                                             ///MENU DE USUARIO
void CargaUsuario();                                                            ///CARGAR EL USUARIO
int  Fechasverificador();                                                       ///FERIVICARA LA VALIDEZ DE LA FECHA
void ListarUsuarios();                                                          ///LISTARA LOS USUARIOS
int  BuscarId();                                                                ///BUSCARA LA ID DEL USUARIO
void ListarId();                                                                ///LISTARA LA ID DEL USUARIO

struct Usuario{                                                                 //ESTRUCTURA DE LOS USUARIOS
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

Usuario CargarUsuario();                                                        ///CARGAR EL USUARIO
void MostrarUsuario (Usuario);                                                  ///VISUALIZACION DE COMO SE VA A MOSTRAR
bool GuardarUsuarios(Usuario);                                                  ///GUARDARA EL USUARIO REGISTRADO
void ModificarUsuario();                                                        ///MODIFICAR EL USUARIO POR ID
void BajaUsuario();

#endif // PROTOTIPOS_H_INCLUDED
