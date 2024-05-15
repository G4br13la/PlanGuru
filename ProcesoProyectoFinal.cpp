#include <iostream> 
#include <string> 
#include <map>
#include <vector>

using namespace std; 


// menu 
int main(){
    map<string, DatosUsuario> usuarios;
    int eleccion; 
    do{
        cout << "1. Iniciar sesion" << endl; 
        cout << "2. Registro" << endl; 
        cout << "3. Crear proyecto" << endl;
        cout << "4. Agregar tarea a proyecto" << endl;
        cout << "5. Salir" << endl; 
        cout <<"ingresa 1, 2, 3, 4 o 5: "; 
        cin >> eleccion;

        switch (eleccion){
            case 1: 
                if (InicioSesion(usuarios)){
                    return 0;
                }
                break;
            case 2: 
                NuevoUsuario(usuarios);
                break;
            case 3: {
                Proyecto nuevo = CrearProyecto();
                proyectos.push_back(nuevo);
                cout << "Proyecto creado" << endl; 
                break;
                }
            case 4: {
                 if (proyectos.empty()) {
                    cout << "No hay proyectos para agregar tareas." << endl;
                } else {
                    string nombreProyecto;
                    cout << "Ingrese el nombre del proyecto al que desea agregar una tarea: ";
                    cin.ignore();
                    getline(cin, nombreProyecto);
                    auto it = proyectos.find(nombreProyecto);
                    if (it != proyectos.end()) {
                        AgregarTarea(it->second);
                    } else {
                        cout << "No se encontró un proyecto con ese nombre." << endl;
                    }
                }
                break;
                }
            case 5: 
                cout << "Saliste " << endl; 
                return 0;
        }
    } while (true);

    return 0;
}

// 1. El sistema debe permitir loguearse y autenticarse, por tal motivo debe tener un componente de inicio de sesión y de registro de usuarios utilizando una estructura de datos que cada equipo defina

    // atributos del usuario 
    struct DatosUsuario{
        string usuario; 
        string clave;
    };

    // creación de nuevo usuario
    void NuevoUsuario(map<string, DatosUsuario>& usuarios){
        string usuario; 
        string clave; 
        cout << "Ingresa tu utuario: "; 
        cin >> usuario; 
        cout << "Ingresa tu contraseña: "; 
        cin >> clave; 

        usuarios[usuario] = {usuario, clave}; 
    };

    // inicio de sesión
    bool InicioSesion(const map<string, DatosUsuario>& usuarios){
        string usuario; 
        string clave; 
        cout << "ingresa tu usuario: "; 
        cin >> usuario; 
        cout << "ingresa tu contraseña: "; 
        cin >> clave; 

        if (usuarios.at(usuario).clave==clave){
            cout << "Iniciaste sesión. " << endl; 
            return true; 
        }else {
            cout << "Acceso invalido" << endl; 
            return false;
        }
    };


//2. El sistema debe permitir crear el proyecto incluyendo nombre del proyecto, propietario, Estado del proyecto, descripción.

    //atributos del proyecto 
    struct Proyecto{
        string nombre;
        string propietario; 
        string estado; 
        string descripcion;
        vector<Tarea> tareas;
    };

    // creacion de un proyecto nuevo 
    Proyecto CrearProyecto(){
        Proyecto proyecto; 
        cout << "ingresa nombre: " ; 
        cin >> nombre; 
        cout << "Ingresa propietario: "; 
        cin >> propietario; 
        cout << "Ingresa el estado: "; 
        cin >> estado; 
        cout << "Ingressa descripcion: "; 
        cin >> descripcion; 
        return proyecto; 
    };


// 6. El sistema debe permitir que a cada uno de los proyectos creados se le pueda asignar una o más tareas

    // atributos de una tarea 
    struct Tarea{
        string nombre; 
        string descripcion; 
        vector<string> responsables;
    }; 

    // ar¿gregar tarea a proyecto 
    void AgregarTarea(Proyecto& proyecto){
        Tarea tarea; 
        cout << "nombre de la tarea"; 
        cin.ignore();
        getline(cin, tarea.nombre);
        cout << "ingresa descripcion de tarea"; 
        getline(cin, tarea.descripcion);
        proyecto.tarea.push_back(tarea);
        cout << "Tarea agregada al proyecto " << nombre << endl;
    }

//7. El sistema debe permitir que a cada tarea se le pueda asignar una o más responsables.

    // agregar tarea a proyecto 
    void AgregarTarea(Proyecto& proyecto){
        Tarea tarea; 
        cout << "nombre de la tarea"; 
        cin.ignore();
        getline(cin, tarea.nombre);
        cout << "ingresa descripcion de tarea"; 
        getline(cin, tarea.descripcion);

        char añadirResponsables;
        do{
            string responsable;
            cout << "ingresa el responsable de la tarea elegida:"; 
            getline(cin, responsable); 
            tarea.responsable.push_back(responsable);
        }while (añadirResponsables == 'n' || añadirResponsables == 'N');
        proyecto.tareas.push_back(tarea);
        cout << "Tarea añadida al proyecto con su respecito responsable" << endl; 

    };
