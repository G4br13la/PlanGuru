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

// 15. El sistema debe permitir cambiar el estado de la tarea.

    class Tarea {
    public:
        Tarea(const string& nombre, const string& estado = "Pendiente")
            : nombre(nombre), estado(estado) {}

        void cambiarEstado(const string& nuevoEstado) {
            estado = nuevoEstado;
            cout << "El estado de la tarea '" << nombre << "' ha cambiado a: " << estado << endl;
        }

        string getNombre() const { return nombre; }
        string getEstado() const { return estado; }

    private:
        string nombre;
        string estado;
    };

    class GestorDeTareas {
    public:
        void agregarTarea(const string& nombre) {
            tareas.emplace_back(nombre);
            cout << "Tarea '" << nombre << "' ha sido agregada." << endl;
        }

        void listarTareas() const {
            for (const auto& tarea : tareas) {
                cout << "Tarea: " << tarea.getNombre() << ", Estado: " << tarea.getEstado() << endl;
            }
        }

        void cambiarEstadoTarea(const string& nombre, const string& nuevoEstado) {
            for (auto& tarea : tareas) {
                if (tarea.getNombre() == nombre) {
                    tarea.cambiarEstado(nuevoEstado);
                    return;
                }
            }
            cout << "No se encontró la tarea con nombre '" << nombre << "'." << endl;
        }

    private:
        vector<Tarea> tareas;
    };

    int main() {
        GestorDeTareas gestor;
        gestor.agregarTarea("Comprar leche");
        gestor.agregarTarea("Estudiar C++");
        gestor.listarTareas();

        gestor.cambiarEstadoTarea("Comprar leche", "En Proceso");
        gestor.cambiarEstadoTarea("Estudiar C++", "Completada");
        gestor.listarTareas();

        return 0;
    }

// 18. El sistema debe permitir realizar dos tipos de búsqueda, cada equipo debe definir cuáles
class Elemento {
public:
    Elemento(const string& nombre) : nombre(nombre) {}

    string getNombre() const { return nombre; }

private:
    string nombre;
};

bool buscarLineal(const vector<Elemento>& elementos, const string& nombre) {
    for (const auto& elemento : elementos) {
        if (elemento.getNombre() == nombre) {
            return true;
        }
    }
    return false;
}

int main() {
    Elemento elem1("1");
    Elemento elem2("2");
    Elemento elem3("3");

    // Ejemplo de búsqueda lineal en un vector
    vector<Elemento> elementosVector = {elem1, elem2, elem3};
    string nombreBuscado = "2";
    cout << "Búsqueda lineal en un vector:" << std::endl;
    if (buscarLineal(elementosVector, nombreBuscado)) {
        std::cout << "El elemento '" << nombreBuscado << "' fue encontrado en el vector." << endl;
    } else {
        cout << "El elemento '" << nombreBuscado << "' no fue encontrado en el vector." << endl;
    }

    // Ejemplo de búsqueda en un conjunto
    set<string> elementosSet = {"1", "2", "3"};
    nombreBuscado = "3";
    cout << "Búsqueda en un conjunto:" << endl;
    if (elementosSet.find(nombreBuscado) != elementosSet.end()) {
        cout << "El elemento '" << nombreBuscado << "' fue encontrado en el conjunto." << endl;
    } else {
        cout << "El elemento '" << nombreBuscado << "' no fue encontrado en el conjunto." << endl;
    }

    map<string, int> elementosMapa = {{"1", 1}, {"2", 2}, {"3", 3}};
    nombreBuscado = "1";
    cout << "Búsqueda en un mapa:" << endl;
    if (elementosMapa.find(nombreBuscado) != elementosMapa.end()) {
        cout << "El elemento '" << nombreBuscado << "' fue encontrado en el mapa." << endl;
    } else {
        cout << "El elemento '" << nombreBuscado << "' no fue encontrado en el mapa." << endl;
    }

    return 0;
}


// 19. El sistema debe mostrar los proyectos por fechas.

class Proyecto {
public:
    Proyecto(const string& nombre, const string& fecha)
        : nombre(nombre), fecha(fecha) {}

    string getNombre() const { return nombre; }
    string getFecha() const { return fecha; }

private:
    string nombre;
    string fecha;
};

class GestorDeProyectos {
public:
    void agregarProyecto(const string& nombre, const string& fecha) {
        proyectos.push_back(Proyecto(nombre, fecha));
        cout << "Proyecto '" << nombre << "' agregado para la fecha " << fecha << endl;
    }

    vector<Proyecto> buscarPorNombre(const std::string& nombre) const {
        vector<Proyecto> resultados;
        for (const auto& proyecto : proyectos) {
            if (proyecto.getNombre() == nombre) {
                resultados.push_back(proyecto);
            }
        }
        return resultados;
    }

    vector<Proyecto> buscarPorFecha(const string& fecha) const {
        vector<Proyecto> resultados;
        for (const auto& proyecto : proyectos) {
            if (proyecto.getFecha() == fecha) {
                resultados.push_back(proyecto);
            }
        }
        return resultados;
    }

private:
    vector<Proyecto> proyectos;
};

int main() {
    GestorDeProyectos gestor;

    gestor.agregarProyecto("Proyecto 1", "2023-05-25");
    gestor.agregarProyecto("Proyecto 2", "2023-05-26");
    gestor.agregarProyecto("Proyecto 3", "2023-05-25");

    cout << "Búsqueda por nombre (Proyecto 1):" << endl;
    auto resultadosNombre = gestor.buscarPorNombre("Proyecto 1");
    for (const auto& proyecto : resultadosNombre) {
        cout << "Nombre: " << proyecto.getNombre() << ", Fecha: " << proyecto.getFecha() << endl;
    }

    cout << "Búsqueda por fecha (2023-05-25):" << endl;
    auto resultadosFecha = gestor.buscarPorFecha("2023-05-25");
    for (const auto& proyecto : resultadosFecha) {
        cout << "Nombre: " << proyecto.getNombre() << ", Fecha: " << proyecto.getFecha() << endl;
    }

    return 0;
}

