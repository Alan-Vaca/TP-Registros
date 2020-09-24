#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void gotoxy();
void recuadro();
void ShowConsoleCursor();

void MenuUsuario();
void MenuPrincipal();
void menuEntrenamiento ();
void menuConfiguraciones();

 struct Usuario{
    int     Id;
    char    Nombre[50];
    char    Apellido[50];
    int     FechaNac;
    float   Altura;
    float   Peso;
    char    PerfilAct;
    bool    AptoMedico;
    bool    Estado;
};

Usuario CargarUsuario();
void CargaUsuario();
bool GuardarUsuarios(Usuario);

void BajaUsuario();
void ModificarUsuario();

void ListarId();
void ListarUsuarios();
void MostrarUsuario (Usuario);

int  BuscarId(int cod);
int  Fechasverificador(int dd, int mm, int aa);


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
bool guardarEntrenamiento(entrenamiento);

void modificarEntrenamiento();

void listarEntrenamiento();
void listarIdEntrenamiento();
void listarEntrenamientoXusuario();
void mostrarEntrenamiento(entrenamiento);

int autonumerico();
int BuscarXentrenamiento(int id);
int buscarIdEntrenamiento(int cod);
int fechasEnt(int dd, int mm, int aa);

void crearCopia();
void restaurarCopia();
void backupUsuario();
void backupEntrenamiento();

#endif // PROTOTIPOS_H_INCLUDED
