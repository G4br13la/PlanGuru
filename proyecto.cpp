#include <iostream>
#include <string>
#include <queue>
#include <string>
#include <limits>
#include <stack>
#include <set>
#include <map>
#include <vector>
using namespace std;
// 1. crear usuario
class Usuario
{
private:
    string nombre_usuario;
    string clave;
    string correo;

public:
    Usuario() {}
    Usuario(string nombre_usuario, string clave, string correo)
    {
        this->nombre_usuario = nombre_usuario;
        this->clave = clave;
        this->correo = correo;
    }

    Usuario(string nombre_usuario)
    {
        this->nombre_usuario = nombre_usuario;
        this->clave = "";
        this->correo = "";
    }

    string getNombre_usuario() const
    {
        return nombre_usuario;
    }
    string getClave()
    {
        return clave;
    }
    string getCorreo()
    {
        return correo;
    }

    void setNombre_usuario(string nombre_usuario)
    {
        this->nombre_usuario = nombre_usuario;
    }

    void setClave(string clave)
    {
        this->clave = clave;
    }
    void setCorreo(string correo)
    {
        this->correo = correo;
    }

    bool operator<(const Usuario &otro) const
    {
        return nombre_usuario < otro.nombre_usuario;
    }

    /*1. El sistema debe permitir loguearse y autenticarse, por tal motivo debe tener un componente de inicio
    de sesión y de registro de usuarios utilizando una estructura de datos que cada equipo defina*/
    void registro(set<Usuario> usuarios)
    {
        string user;
        string pass;
        string correo;
        cout << "Ingrese su nombre de usuario: ";
        cin >> user;
        cout << "Ingrese su contraseña: ";
        cin >> pass;
        cout << "Ingrese su correo: ";
        cin >> correo;
        for (const auto &usuario : usuarios)
        {
            if (usuario.nombre_usuario == user)
            {
                cout << "Usuario ya existe" << endl;
                return;
            }
        }
        usuarios.insert(Usuario(user, pass, correo));
        cout << "Usuario registrado" << endl;
    }

    bool InicioSesion(set<Usuario> &usuarios)
    {
        string user;
        string pass;
        cout << "ingresa tu usuario: ";
        cin >> user;
        cout << "ingresa tu contraseña: ";
        cin >> pass;

        for (const auto &usuario : usuarios)
        {
            if (usuario.nombre_usuario == user && usuario.clave == pass)
            {
                cout << "Iniciaste sesión. " << endl;
                return true;
            }
        }
        cout << "Usuario o contraseña incorrectos" << endl;
        return false;
    };
};

class Notas
{
private:
    string titulo_nota;
    string autor_nota;
    string comentarios;
    vector<string> reacciones;

public:
    Notas() {}
    Notas(string titulo_nota, string autor_nota, string comentarios, vector<string> reacciones)
    {
        this->titulo_nota = titulo_nota;
        this->autor_nota = autor_nota;
        this->comentarios = comentarios;
        this->reacciones = reacciones;
    }
    string getTitulo_notas() const
    {
        return titulo_nota;
    }
    string getAutor_nota() const
    {
        return autor_nota;
    }
    string getComentarios() const
    {
        return comentarios;
    }
    vector<string> getReacciones()
    {
        return reacciones;
    }

    void setTitulo_notas(string titulo_nota)
    {
        this->titulo_nota = titulo_nota;
    }
    void setAutor_nota(string autor_nota)
    {
        this->autor_nota = autor_nota;
    }
    void setComentarios(string comentarios)
    {
        this->comentarios = comentarios;
    }
    void setReacciones(vector<string> reaciones)
    {
        this->reacciones = reaciones;
    }
    // 5. El sistema debe permitir agregar reacciones a las notas creadas.
    void agregar_reaccion(string titulo_nota, string nueva_reaccion, set<string> titulos_notas)
    {
        auto iterador = titulos_notas.find(titulo_nota);

        if (iterador != titulos_notas.end())
        {
            cout << "Se encontró " << titulo_nota << " en las notas" << endl;
            reacciones.push_back(nueva_reaccion);
        }
        else
        {
            cout << "NO se encontró " << titulo_nota << " en las notas" << endl;
        }
    }
};

class Tareas
{
private:
    string nombre_tarea;
    string estado;
    string prioridad;
    string responsable;
    string comentarios;
    vector<Notas> notas;

public:
    Tareas() {}
    Tareas(string nombre_tarea, string estado, string prioridad, string responsable, string comentarios)
    {
        this->nombre_tarea = nombre_tarea;
        this->estado = estado;
        this->prioridad = prioridad;
        this->responsable = responsable;
        this->comentarios = comentarios;
    }

    Tareas(string nombre_tarea)
    {
        this->nombre_tarea = nombre_tarea;
        this->estado = "";
        this->prioridad = "";
        this->responsable = "";
        this->comentarios = "";
    }

    bool operator<(const Tareas &otra) const
    {
        return nombre_tarea < otra.nombre_tarea;
    }

    string getNombre_tarea() const
    {
        return nombre_tarea;
    }
    string getEstado() const
    {
        return estado;
    }
    string getPrioridad() const
    {
        return prioridad;
    }
    string getResponsable() const
    {
        return responsable;
    }
    string getComentarios()
    {
        return comentarios;
    }
    vector<Notas> getNotas() const
    {
        return notas;
    };

    void setNombre_tarea(string nombre_tarea)
    {
        this->nombre_tarea = nombre_tarea;
    }
    void setEstado(string estado)
    {
        this->estado = estado;
    }
    void setPrioridad(string prioridad)
    {
        this->prioridad = prioridad;
    }
    void setResponsable(string responsable)
    {
        this->responsable = responsable;
    }
    void setComentarios(string comentarios)
    {
        this->comentarios = comentarios;
    }
    void setNotas(vector<Notas> notas)
    {
        this->notas = notas;
    }

    /* 4. El sistema debe permitir agregar una o más notas a cada
    proyecto y/o tareas, incluyendo título de la nota, autor de la nota y descripción.*/

    void agregar_nota(set<Tareas> tareas, Notas nota)
    {
        cout << "nombre de la tarea al que quiere ponerle una nota: " << endl;
        string nombre_tarea;
        cin >> nombre_tarea;
        for (auto tarea : tareas)
        {
            if (tarea.getNombre_tarea() == nombre_tarea)
            {
                vector<Notas> notas;
                notas.push_back(nota);
                tarea.setNotas(notas);
            }
        }
        notas.push_back(nota);
    }

    // 3.crear tareas
    void crear_Tarea(set<Tareas> tareas)
    {
        Tareas tarea;
        cout << "nombre de la tarea";
        cin.ignore();
        getline(cin, nombre_tarea);
        cout << "ingresa descripcion de tarea";
        getline(cin, comentarios);
        cout << "ingresa el estado de la tarea";
        getline(cin, estado);

        for (const auto &words : tareas)
        {
            if (tarea.getNombre_tarea() == words.getNombre_tarea())
            {
                cout << "La tarea ya esta en la lista" << endl;
                return;
            }
        }
        tareas.insert(tarea);

        cout << "tarea agregada" << endl;
        cout << "" << endl;
    }

    // 12.el sistema debe permitir oredenar las tareas por prioridad
    void ordenar_tarea_prioridad(set<Tareas> &tarea) // Añadí una referencia para modificar el conjunto
    {
        vector<string> prioridad_alta;
        vector<string> prioridad_media;
        vector<string> prioridad_baja;
        string nombre_tarea;
        string priority;

        cout << "Escriba el nombre de la tarea: " << endl;
        cin.ignore();
        getline(cin, nombre_tarea);
        cout << "Asignele una prioridad(alta, media o baja): " << endl;
        getline(cin, priority);

        // Crear una tarea temporal solo con el nombre para buscarla en el conjunto
        Tareas tarea_busqueda;
        tarea_busqueda.setNombre_tarea(nombre_tarea);

        auto iterador = tarea.find(tarea_busqueda);
        if (iterador != tarea.end())
        {
            if (iterador != tarea.end())
            {
                cout << "Se encontró la tarea." << endl;
                if (priority == "alta")
                {
                    prioridad_alta.push_back(iterador->getNombre_tarea());
                    cout << "Tarea asignada a prioridad alta" << endl;
                }
                else if (priority == "media")
                {
                    prioridad_media.push_back(iterador->getNombre_tarea());
                    cout << "Tarea asignada a prioridad alta" << endl;
                }
                else if (priority == "baja")
                {
                    prioridad_baja.push_back(iterador->getNombre_tarea());
                    cout << "Tarea asignada a prioridad baja" << endl;
                }
            }
        }
    }

    // 15. El sistema debe permitir cambiar el estado de la tarea.
    void cambiarEstado(set<Tareas> tarea)
    {
        string nuevoEstado;
        cout << "Escriba el nombre de la tarea: " << endl;
        cin.ignore();
        getline(cin, nombre_tarea);
        cout << "Escriba el nuevo estado de la tarea: " << endl;
        getline(cin, nuevoEstado);
        // Crear una tarea temporal solo con el nombre para buscarla en el conjunto
        Tareas tarea_busqueda(nombre_tarea);
        // tarea_busqueda.setNombre_tarea(nombre_tarea);
        auto iterador = tarea.find(tarea_busqueda);
        if (iterador != tarea.end())
        {
            Tareas estado_actualizado = *iterador;
            cout << "Se encontró la tarea." << endl;
            estado_actualizado.setEstado(nuevoEstado);
            cout << "Estado de la tarea cambiado." << endl;

            tarea.erase(iterador);
            tarea.insert(estado_actualizado);
        }

        cout << "No se encontró la tarea con nombre '" << nombre_tarea << "'." << endl;
        estado = nuevoEstado;
        cout << "El estado de la tarea '" << nombre_tarea << "' ha cambiado a: " << estado << endl;
    }

    // 7. El sistema debe permitir que a cada tarea se le pueda asignar una o más responsables.

    void asignarTareaPersona(set<Tareas> &tarea, set<Usuario> &persona)
    {
        string nombre_tarea;
        string nombre_usuario;

        cout << "ingresa el nombre de la tarea";
        cin >> nombre_tarea;
        cout << "ingresa el nombre de la persona";
        cin >> nombre_usuario;
        // Crear objetos temporales para la búsqueda
        Tareas buscar_tarea(nombre_tarea);
        Usuario buscar_usuario(nombre_usuario);

        auto iterador_tarea = tarea.find(buscar_tarea);

        if (iterador_tarea != tarea.end())
        {
            cout << "Se encontró la tarea." << endl;
            // tarea.setNombre_tarea(nombre_tarea);
        }
        else
        {
            cout << "No se encontró la tarea. " << endl;
        }

        auto iterador_persona = persona.find(buscar_usuario);

        if (iterador_persona != persona.end())
        {
            cout << "Se encontró al usuario." << endl;
            // persona.setNombre_usuario(nombre_usuario);
        }
        else
        {
            cout << "No se encontró el usuario. " << endl;
        }

        // Asignar el responsable a la tarea
        Tareas tarea_actualizada = *iterador_tarea;
        tarea_actualizada.setResponsable(iterador_persona->getNombre_usuario());

        // Actualizar el set de tareas
        tarea.erase(iterador_tarea);
        tarea.insert(tarea_actualizada);

        cout << "Tarea asignada a: " << tarea_actualizada.getResponsable() << endl;
    }
};

class Proyecto
{
private:
    string nombre_proyecto;
    string propietario;
    string descripcion;
    string estado_proyecto;
    string fecha;
    set<Tareas> tareas;
    vector<Notas> notas;

public:
    Proyecto() {}
    Proyecto(string nombre_proyecto, string descripcion, string propietario, string estado_proyecto)
    {
        this->nombre_proyecto = nombre_proyecto; // nombre del proyecto
        this->descripcion = descripcion;         // descripcion del proyecto
        this->propietario = propietario;         // propietario del proyecto
        this->estado_proyecto = estado_proyecto; // estado del proyecto
    }
    // Sobrecarga del operador <
    bool operator<(const Proyecto &otro) const
    {
        return nombre_proyecto < otro.nombre_proyecto;
    }

    string getNombre_proyecto() const
    {
        return nombre_proyecto;
    }
    string getPropietario()
    {
        return propietario;
    }
    string getDescripcion()
    {
        return descripcion;
    }
    string getEstado_proyecto()
    {
        return estado_proyecto;
    }

    string getFecha()
    {
        return fecha;
    }

    set<Tareas> getTareas()
    {
        return tareas;
    };

    vector<Notas> getNotas() const
    {
        return notas;
    };

    void setTareas(set<Tareas> tareas)
    {
        this->tareas = tareas;
    }

    void setNombre_proyecto(string nombre_proyecto)
    {
        this->nombre_proyecto = nombre_proyecto;
    }
    void setPropietario(string propietario)
    {
        this->propietario = propietario;
    }
    void setDescripcion(string descripcion)
    {
        this->descripcion = descripcion;
    }
    void setEstado_proyecto(string estado_proyecto)
    {
        this->estado_proyecto = estado_proyecto;
    }

    void setFecha(string fecha)
    {
        this->fecha = fecha;
    }

    void setNotas(vector<Notas> notas)
    {
        this->notas = notas;
    }

    /* 4. El sistema debe permitir agregar una o más notas a cada
    proyecto y/o tareas, incluyendo título de la nota, autor de la nota y descripción.*/
    void agregar_nota(set<Proyecto> proyectos, Notas nota)
    {
        cout << "nombre del proyecto al que quiere ponerle una nota: " << endl;
        string nombre_proyecto;
        cin >> nombre_proyecto;
        for (auto proyecto : proyectos)
        {
            if (proyecto.getNombre_proyecto() == nombre_proyecto)
            {
                vector<Notas> notas;
                notas.push_back(nota);
                proyecto.setNotas(notas);
            }
        }
    }
    void agregar_tarea(Tareas tarea)
    {
        tareas.insert(tarea);
    }

    // void eliminar_tarea(int indice)
    // {
    //     tareas.erase(tareas.begin() + indice);
    // }

    // 2.crear proyecto
    void CrearProyecto(set<Proyecto> proyectos)
    {
        Proyecto proyecto;
        cout << "ingresa nombre: ";
        cin >> nombre_proyecto;
        cout << "Ingresa propietario: ";
        cin >> propietario;
        cout << "Ingressa descripcion: ";
        cin >> descripcion;
        cout << "Ingrese la fecha de inicio del proyecto(yy/mm/dd): ";
        cin >> fecha;

        for (const auto &poyect : proyectos)
        {
            if (proyecto.getNombre_proyecto() == poyect.getNombre_proyecto())
            {
                cout << "el proyecto ya esta en la lista" << endl;
                return;
            }
        }
        proyectos.insert(proyecto);

        cout << "proyecto agregado" << endl;
        cout << "" << endl;
    }

    // 10. el sistema debe permitir mostrar los estados de las tareas
    void estado_tareas(vector<Proyecto> proyectos)
    {
        for (const auto &proyecto : proyectos)
        {
            cout << "Nombre del proyecto: " << proyecto.nombre_proyecto << endl;
            cout << "Estados de las tareas:" << endl;
            for (const auto &tarea : proyecto.tareas)
            {
                cout << "Nombre de la tarea: " << tarea.getNombre_tarea() << endl;
                cout << "Estado de la tarea: " << tarea.getEstado() << endl;
                cout << "Prioridad de la tarea: " << tarea.getPrioridad() << endl;
            }
        }
    }

    // 8. el sisetma debe permitir mostrar los proyectos creados con sus detalles.
    void mostrarProyectos(vector<Proyecto> proyectos)
    {
        for (const auto &proyecto : proyectos)
        {
            cout << "Nombre del proyecto: " << proyecto.nombre_proyecto << endl;
            cout << "Descripción del proyecto: " << proyecto.descripcion << endl;
            cout << "Propietario del proyecto: " << proyecto.propietario << endl;
        }
    }

    // 9. El sistema debe permitir mostrar las tareas de cada uno de sus proyectos.

    void mostrar_tareas(Proyecto proyecto)
    {
        for (const auto &tarea : proyecto.getTareas())
        {
            cout << "Nombre de la tarea: " << tarea.getNombre_tarea() << endl;
            cout << "Estado de la tarea: " << tarea.getEstado() << endl;
            cout << "Prioridad de la tarea: " << tarea.getPrioridad() << endl;
        }
    }

    // 19. El sistema debe mostrar los proyectos por fechas.
    void proyecto_por_fecha(map<string, Proyecto> proyectos)
    {
        vector<Proyecto> lista_proyectos;
        for (const auto &proyecto : proyectos)
        {
            lista_proyectos.push_back(proyecto.second);
        }
        for (const auto &proyecto : lista_proyectos)
        {
            cout << "Nombre del proyecto: " << proyecto.nombre_proyecto << endl;
            cout << "Fecha de creación del proyecto: " << proyecto.fecha << endl;
        }
    }
};

// 18. El sistema debe permitir realizar dos tipos de búsqueda, cada equipo debe definir cuáles
class Elemento
{
public:
    Elemento(const string &nombre) : nombre(nombre) {}

    string getNombre() const { return nombre; }

private:
    string nombre;
};

bool buscarLineal(const vector<Elemento> &elementos, const string &nombre)
{
    for (const auto &elemento : elementos)
    {
        if (elemento.getNombre() == nombre)
        {
            return true;
        }
    }
    return false;
}

// 6. El sistema debe permitir que a cada uno de los proyectos creados se le pueda asignar una o más tareas
void asignar_tarea_a_proyecto(map<string, Proyecto> proyectos, map<string, Tareas> tareas)
{
    string nombre_proyecto, nombre_tarea;
    cout << "ingresa el nombre del proyecto" << endl;
    cin.ignore();
    getline(cin, nombre_proyecto);
    cout << "ingresa el nombre de la tarea" << endl;
    getline(cin, nombre_tarea);

    if (proyectos.find(nombre_proyecto) == proyectos.end() || tareas.find(nombre_tarea) == tareas.end())
    {
        cout << "El poyecto y/o tarea buscada no existe." << endl;
        return;
    }

    Proyecto proyecto = proyectos[nombre_proyecto];
    Tareas tarea = tareas[nombre_tarea];
    proyecto.agregar_tarea(tarea);
    proyectos[nombre_proyecto] = proyecto;
    cout << "tarea asignada al proyecto" << endl;
}

// 13. El sistema debe permitir organizar los responsables por nombre.
void responsables_Por_nombre(Proyecto proyecto)
{
    vector<string> responsables;
    for (const auto tarea : proyecto.getTareas())
    {
        responsables.push_back(tarea.getResponsable());
    }
    sort(responsables.begin(), responsables.end());

    cout << "Responsables alfabeticamente: " << endl;
    for (const auto responsable : responsables)
    {
        cout << responsable << endl;
    }
}

// 14. El sistema debe permitir hacer consultas de proyectos por nombres y mostrar las tareas que cada uno contiene.
void consultar_proyecto(map<string, Proyecto> proyectos, map<string, Tareas> tareas)
{
    string nombre_proyecto;
    cout << "ingresa el nombre del proyecto" << endl;
    cin.ignore();
    getline(cin, nombre_proyecto);
    if (proyectos.find(nombre_proyecto) == proyectos.end())
    {
        cout << "El proyecto buscado no existe." << endl;
        return;
    }
    Proyecto proyecto = proyectos[nombre_proyecto];
    cout << "proyecto: " << proyecto.getNombre_proyecto() << endl;
    cout << "tareas: " << endl;
    for (const auto tarea : proyecto.getTareas())
    {
        cout << tarea.getNombre_tarea() << endl;
    }
}

// 11. el sistema debe permitir mostrar las notas
void mostrar_notas(set<Proyecto> proyectos)
{
    for (const auto proyecto : proyectos)
    {
        cout << "Proyecto: " << proyecto.getNombre_proyecto() << endl;
        cout << "Notas del proyecto: " << endl;
        for (const auto &nota : proyecto.getNotas())
        {
            cout << "Titulo: " << nota.getTitulo_notas() << endl;
            cout << "Autor: " << nota.getAutor_nota() << endl;
            cout << "Descripcion: " << nota.getComentarios() << endl;
            cout << endl;
        }
        cout << endl;
    }
}

void mostrar_notas(set<Tareas> tareas)
{
    for (const auto tarea : tareas)
    {
        cout << "tarea: " << tarea.getNombre_tarea() << endl;
        cout << "Notas del tarea: " << endl;
        for (const auto &nota : tarea.getNotas())
        {
            cout << "Titulo: " << nota.getTitulo_notas() << endl;
            cout << "Autor: " << nota.getAutor_nota() << endl;
            cout << "Descripcion: " << nota.getComentarios() << endl;
            cout << endl;
        }
        cout << endl;
    }
}

// 20. El sistema debe contener los menús necesarios para que sea amigable al usuario.

class Interfaz
{
private:
    Usuario usuario;
    Proyecto proyecto;
    Tareas tarea;
    Notas nota;
    set<Notas> notas;
    set<Proyecto> proyectos;
    set<Tareas> tareas;

public:
    void menu()
    {
        int opcion;
        do
        {
            cout << "Bienvenido a TaskMaster." << endl;
            cout << " " << endl;
            cout << "Donde creas tus proyectos de forma eficiente." << endl;
            cout << " " << endl;
            cout << "¿Que quieres hacer?" << endl;
            cout << " " << endl;
            cout << "1. Login ." << endl;
            cout << "2. Proyectos" << endl;
            cout << "3. tareas." << endl;
            cout << "4. Notas." << endl;
            cout << "5. Salir." << endl;
            cout << " " << endl;
            cout << "EMPECEMOS CON TU TRABAJO :D: " << endl;
            cout << " " << endl;
            cout << "Ingrese su opción: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                cout << "Si ya estas registrado, inicia secion, si no, registrate." << endl;
                cout << " " << endl;
                cout << "1. Iniciar secion." << endl;
                cout << "2. Registrarse." << endl;
                cout << " " << endl;
                cout << "Ingrese su opcion: ";
                int opcion2;
                cin >> opcion2;
                switch (opcion2)
                {
                case 1:

                    break;

                default:
                    break;
                }
                break;
            case 2:
                cout << "Proyectos" << endl;
                cout << " " << endl;
                cout << "1. Crear proyecto." << endl;
                cout << "2. Ver proyectos." << endl;
                cout << "3. Agregar notas." << endl;
                cout << "4. Eliminar proyecto." << endl;
                cout << "5. Estado de las tareas." << endl;
                cout << "6. Ver notas." << endl;
                cout << " " << endl;
                cout << "Ingrese su opcion: ";
                int opcion3;
                cin >> opcion3;
                switch (opcion3)
                {
                case 1:

                    break;

                default:
                    break;
                }
                break;
            case 3:
                cout << "Tareas" << endl;
                cout << " " << endl;
                cout << "1. Crear tarea." << endl;
                cout << "2. Ver tareas." << endl;
                cout << "3. Agregar notas." << endl;
                cout << "4. Eliminar tarea." << endl;
                cout << "5. Ver notas." << endl;
                cout << "6. Ordenar por prioridad." << endl;
                cout << "7. Ordenar responsables por nombre" << endl;
                cout << " " << endl;
                cout << "Ingrese su opcion: ";
                int opcion4;
                cin >> opcion4;
                switch (opcion4)
                {
                case 1:
                    
                    break;
                
                default:
                    break;
                }
                break;
            case 4:
                // Agregar opciones para notas
                break;
            case 5:
                // Salir
                break;
            default:
                cout << "Opción no válida. Por favor, intente nuevamente." << endl;
                break;
            }
        } while (opcion != 5);
    }
};
