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

class Notas
{
private:
    string titulo_notas;
    string autor_nota;
    string comentarios;
    vector<string> reacciones;
    set<string> nombre_notas;

public:
    Notas() {}
    Notas(string titulo_notas, string autor_notas, string comentarios, vector<string> reacciones)
    {
        this->titulo_notas = titulo_notas;
        this->autor_nota = autor_nota;
        this->comentarios = comentarios;
        this->reacciones = reacciones;
    }
    string getTitulo_notas()
    {
        return titulo_notas;
    }
    string getAutor_nota()
    {
        return autor_nota;
    }
    string getComentarios()
    {
        return comentarios;
    }
    vector<string> getReacciones()
    {
        return reacciones;
    }
    void setTitulo_notas(string titulo_notas)
    {
        this->titulo_notas = titulo_notas;
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

//5. El sistema debe permitir agregar reacciones a las notas creadas.
    void agregar_reaccion(string nombre_nota, string nueva_reaccion)
    {
        auto iterador = nombre_notas.find(nombre_nota);

        if (iterador != nombre_notas.end())
        {
            cout << "Se encontró " << nombre_nota << "en las notas" << endl;
            reacciones.push_back(nueva_reaccion);
        }
        else
        {
            cout << "No se encontró " << nombre_nota << "en las notas" << endl;
        }
    }
//11. mostrar las notas
    void mostrar_notas(string nota)
    {
        auto iterador = nombre_notas.find(nota); // busca el titulo de la nota en el vector de titulos
        if (iterador != nombre_notas.end())      // si se encuentra el titulo
        {
            cout << "Se encontró " << nota << "en las notas" << endl;
            cout << titulo_notas;
            cout << autor_nota;
            cout << comentarios;
        }
        else
        {
            cout << "No se encontró " << nombre_nota << "en las notas" << endl;
        }
    }
};

struct Tareas
{
    string nombre_tarea;
    string estado;
    string prioridad;
    int fecha_limite;
    string responsable;
    string comentarios;
};

class Proyecto
{
private:
    string nombre_proyecto;
    string propietario;
    string descripcion;
    string estado_proyecto;
    vector<Notas> nota;
    vector<Tareas> tarea;

private:
    string getNombre_proyecto()
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
    vector<Notas> getNota()
    {
        return nota;
    };
    vector<Tareas> getTarea()
    {
        return tarea;
    };

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
    void setNota(vector<Notas> nota)
    {
        this->nota = nota;
    }
    void setTarea(vector<Tareas> tarea)
    {
        this->tarea = tarea;
    }
//10. mostrar el estado de las tareas
    void estado_tareas(vector<Proyecto> proyectos)
    {
        for (const auto &proyecto : proyectos)
        {
            cout << "Nombre del proyecto: " << proyecto.nombre << endl;
            cout << "Estados de las tareas:" << endl;
            for (const auto &tareas : proyectos.tarea)
            {
                cout << "Nombre de la tarea: " << tareas.nombre_tarea << endl;
                cout << "Estado de la tarea: " << tareas.estado << endl;
                cout << "Prioridad de la tarea: " << tareas.prioridad << endl;
            }
        }
    }
};

int main()
{
    Notas nota1;

    nota1.setTitulo_notas("prueba 1");
    nota1.setAutor_nota("gabs");
    nota1.agregar_reaccion("no me gusta .-.");
    nota1.agregar_reaccion("no me gusta x2 .-.");

    Notas nota2;

    nota2.setTitulo_notas("prueba 2");
    nota2.setAutor_nota("santiago");
    nota2.agregar_reaccion("si me gusta .-.");
    nota2.agregar_reaccion("si me gusta x2 .-.");

    vector<string> reaccion1 = nota1.getReacciones();
    vector<string> reaccion2 = nota2.getReacciones();

    for (int i = 0; i < reaccion1.size(); i++)
    {
        cout << reaccion1[i] << endl;
    }

    for (int i = 0; i < reaccion2.size(); i++)
    {
        cout << reaccion2[i] << endl;
    }

    Proyecto proyecto1;
    proyecto1.setNombre("proyecto 1"); // nombre del proyecto
    proyecto1.setTarea("1. hacer el loguing.");
    mostrarEstadosTareas(proyecto1);
}

/*
1) cuando se cree una una nota guardarlo en un conjunto
2) cuando se vaya a agregar la reaccion a una nota, pedir el identificador de una nota y la reaccion
3) buscar en el conjunto la nota con  el identificador, en caso de que no exista retornar
un "no existe la nota" y en caso de que si exista, agregarlo a la lista de reacciones
*/


/////////////////////////////////////////////////////////////////////////////////////////////////
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
/*1. El sistema debe permitir loguearse y autenticarse, por tal motivo debe tener un componente de inicio
de sesión y de registro de usuarios utilizando una estructura de datos que cada equipo defina*/

// atributos del usuario
struct DatosUsuario
{
    string usuario;
    string clave;
    string correo;
};

// creación de nuevo usuario
void NuevoUsuario(map<string, DatosUsuario> &usuarios)
{
    string usuario;
    string clave;
    string correo;
    cout << "Ingresa tu utuario: ";
    cin >> usuario;
    cout << "Ingresa tu contraseña: ";
    cin >> clave;
    cout << "Ingresa tu correo: ";
    cin >> correo;

    usuarios[usuario] = {usuario, clave, correo};
};

// inicio de sesión
bool InicioSesion(const map<string, DatosUsuario> &usuarios)
{
    string usuario;
    string clave;
    cout << "ingresa tu usuario: ";
    cin >> usuario;
    cout << "ingresa tu contraseña: ";
    cin >> clave;

    if (usuarios.at(usuario).clave == clave)
    {
        cout << "Iniciaste sesión. " << endl;
        return true;
    }
    else
    {
        cout << "Acceso invalido" << endl;
        return false;
    }
};

class Notas
{
private:
    string titulo_notas;
    string autor_nota;
    string comentarios;
    vector<string> reacciones;
    set<string> nombre_notas;

public:
    Notas() {}
    Notas(string titulo_notas, string autor_notas, string comentarios, vector<string> reacciones)
    {
        this->titulo_notas = titulo_notas;
        this->autor_nota = autor_nota;
        this->comentarios = comentarios;
        this->reacciones = reacciones;
    }
    string getTitulo_notas()
    {
        return titulo_notas;
    }
    string getAutor_nota()
    {
        return autor_nota;
    }
    string getComentarios()
    {
        return comentarios;
    }
    vector<string> getReacciones()
    {
        return reacciones;
    }
    void setTitulo_notas(string titulo_notas)
    {
        this->titulo_notas = titulo_notas;
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

    void agregar_notas_tareas(map(Tareas, vector<Notas>) & tarea)
    {
        while (true)
        {
            string opcion;
            cout << "¿Quiere agregarle un titulo a la tarea? si/no" << endl;
            cin >> opcion;
            if (opcion == "si")
            {
                Notas nueva_nota;
                cout << "Ingrese el titulo de la nota: " << endl;
                getline(cin, nueva_nota.titulo_notas);
                cout << "Ingrese el autor de la nota: " << endl;
                getline(cin, nueva_nota.autor_nota);
                cout << "Ingrese los comentarios de la nota: " << endl;
                getline(cin, nueva_nota.comentarios);
                cout << "Ingrese las reacciones de la nota: " << endl;

                tarea.Notas.push_back(nueva_nota);
            }
            else
            {
                break;
            }
        }
    }

    void agregar_notas_proyecto(map(Proyecto, vector<Notas>) & proyecto)
    {
        while (true)
        {
            string opcion;
            cout << "¿Quiere agregarle un titulo al proyecto? si/no" << endl;
            cin >> opcion;
            if (opcion == "si")
            {
                Notas nueva_nota;
                cout << "Ingrese el titulo de la nota: " << endl;
                getline(cin, nueva_nota.titulo_notas);
                cout << "Ingrese el autor de la nota: " << endl;
                getline(cin, nueva_nota.autor_nota);
                cout << "Ingrese los comentarios de la nota: " << endl;
                getline(cin, nueva_nota.comentarios);
                cout << "Ingrese las reacciones de la nota: " << endl;

                proyecto.Notas.push_back(nueva_nota);
            }
            else
            {
                break;
            }
        }
    }
    void agregar_reaccion(string nombre_nota, string nueva_reaccion)
    {
        auto iterador = nombre_notas.find(nombre_nota);

        if (iterador != nombre_notas.end())
        {
            cout << "Se encontró " << nombre_nota << "en las notas" << endl;
            reacciones.push_back(nueva_reaccion);
        }
        else
        {
            cout << "No se encontró " << nombre_nota << "en las notas" << endl;
        }
    }

    void mostrar_notas(string nota)
    {
        auto iterador = nombre_notas.find(nota); // busca el titulo de la nota en el vector de titulos
        if (iterador != nombre_notas.end())      // si se encuentra el titulo
        {
            cout << "Se encontró " << nota << "en las notas" << endl;
            cout << titulo_notas;
            cout << autor_nota;
            cout << comentarios;
        }
        else
        {
            cout << "No se encontró " << nombre_nota << "en las notas" << endl;
        }
    }
};

class Tareas
{
    private:
    vector<string> nombre_tarea;
    string estado;
    string prioridad;
    int fecha_limite;
    string responsable;
    string comentarios;
    public:
    void AgregarTarea(Proyecto &proyecto)
    {
        Tareas tarea;
        cout << "nombre de la tarea";
        cin.ignore();
        getline(cin, tarea.nombre);
        cout << "ingresa descripcion de tarea";
        getline(cin, tarea.descripcion);

        char añadirResponsables;
        do
        {
            string responsable;
            cout << "ingresa el responsable de la tarea elegida:";
            getline(cin, responsable);
            tarea.responsable.push_back(responsable);
        } while (añadirResponsables == 'n' || añadirResponsables == 'N');
        proyecto.tareas.push_back(tarea);
        cout << "Tarea añadida al proyecto con su respecito responsable" << endl;
    }

    void estado_tareas(vector<Proyecto> proyectos)
    {
        for (const auto &proyecto : proyectos)
        {
            cout << "Nombre del proyecto: " << proyecto.nombre << endl;
            cout << "Estados de las tareas:" << endl;
            for (const auto &tareas : proyectos.tarea)
            {
                cout << "Nombre de la tarea: " << tareas.nombre_tarea << endl;
                cout << "Estado de la tarea: " << tareas.estado << endl;
                cout << "Prioridad de la tarea: " << tareas.prioridad << endl;
            }
        }
    }
    
    
};

class Proyecto
{
private:
    string nombre_proyecto;
    string propietario;
    string descripcion;
    string estado_proyecto;
    vector<Notas> nota;
    vector<Tareas> tareas;

private:
    // Constructor
    Proyecto(string nombre_proyecto, string descripcion, string propietario, string estado_proyecto)
    {
        this->nombre_proyecto = nombre_proyecto; // nombre del proyecto
        this->descripcion = descripcion;         // descripcion del proyecto
        this->propietario = propietario;         // propietario del proyecto
        this->estado_proyecto = estado_proyecto; // estado del proyecto
    }

    string getNombre_proyecto()
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
    vector<Notas> getNota()
    {
        return nota;
    };
    vector<Tareas> getTareas()
    {
        return tareas;
    };

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
    void setNota(vector<Notas> nota)
    {
        this->nota = nota;
    }
    void setTareas(vector<Tareas> tareas)
    {
        this->tareas = tareas;
    }

    void CrearProyecto()
    {
        Proyecto proyecto;
        cout << "ingresa nombre: ";
        cin >> nombre;
        cout << "Ingresa propietario: ";
        cin >> propietario;
        cout << "Ingresa el estado: ";
        cin >> estado;
        cout << "Ingressa descripcion: ";
        cin >> descripcion;
        return proyecto;
    }

    void AgregarTarea(Proyecto &proyecto)
    {
        Tareas tarea;
        cout << "nombre de la tarea";
        cin.ignore();
        getline(cin, tarea.nombre);
        cout << "ingresa descripcion de tarea";
        getline(cin, tarea.descripcion);

        char añadirResponsables;
        do
        {
            string responsable;
            cout << "ingresa el responsable de la tarea elegida:";
            getline(cin, responsable);
            tarea.responsable.push_back(responsable);
        } while (añadirResponsables == 'n' || añadirResponsables == 'N');
        proyecto.tareas.push_back(tarea);
        cout << "Tarea añadida al proyecto con su respecito responsable" << endl;
    }

    void estado_tareas(vector<Proyecto> proyectos)
    {
        for (const auto &proyecto : proyectos)
        {
            cout << "Nombre del proyecto: " << proyecto.nombre << endl;
            cout << "Estados de las tareas:" << endl;
            for (const auto &tareas : proyectos.tarea)
            {
                cout << "Nombre de la tarea: " << tareas.nombre_tarea << endl;
                cout << "Estado de la tarea: " << tareas.estado << endl;
                cout << "Prioridad de la tarea: " << tareas.prioridad << endl;
            }
        }
    }

    // Método para mostrar los detalles del proyecto
    void mostrarProyectos(vector<Proyecto> proyectos)
    {
        for (const auto &proyecto : proyectos)
        {
            cout << "Nombre del proyecto: " << proyecto.nombre << endl;
            cout << "Descripción del proyecto: " << proyecto.descripcion << endl;
            cout << "Propietario del proyecto: " << proyecto.propietario << endl;
        }
    }
    void mostrar_proyectos() const
    {
        cout << "nombre del proyecto: " << nombre_proyecto << endl;
        cout << "descripcion: " << descripcion << endl;
        cout << "propietario: " << propietario << endl;
        cout << "estado del proyecto: " << estado_proyecto << endl;
    }
};

class Interfaz
{
public:
    void mostrarMenu()
    {
        int opcion;
        do
        {
            cout << "Bienvenido." << endl;
            cout << " " << endl;
            cout << "¿Que quieres hacer?" << endl;
            cout << " " << endl;
            cout << "1. Login ." << endl;
            cout << "2. Crear Proyecto" << endl;
            cout << "3. Crear tareas." << endl;
            cout << "4. Asignar tareas." << endl;
            cout << "5. Agregar notas." << endl;
            cout << "6. reacionar a las notas." << endl;
            cout << "7. Ver el estado de los proyectos o tareas." << endl;
            cout << " " << endl;
            cout << "¡Buena suerte!" << endl;
            cout << " " << endl;
            cout << "EMPECEMOS :D : " << endl;
            cout << " " << endl;
            cout << "Ingrese su opción: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                Fijas_Picas();
                break;
            case 2:
                Tres_en_linea();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
                break;
            }
        } while (opcion != 3);
    }
}

int
main()
{
    Notas nota1;

    nota1.setTitulo_notas("prueba 1");
    nota1.setAutor_nota("gabs");
    nota1.agregar_reaccion("no me gusta .-.");
    nota1.agregar_reaccion("no me gusta x2 .-.");

    Notas nota2;

    nota2.setTitulo_notas("prueba 2");
    nota2.setAutor_nota("santiago");
    nota2.agregar_reaccion("si me gusta .-.");
    nota2.agregar_reaccion("si me gusta x2 .-.");

    vector<string> reaccion1 = nota1.getReacciones();
    vector<string> reaccion2 = nota2.getReacciones();

    for (int i = 0; i < reaccion1.size(); i++)
    {
        cout << reaccion1[i] << endl;
    }

    for (int i = 0; i < reaccion2.size(); i++)
    {
        cout << reaccion2[i] << endl;
    }

    Proyecto proyecto1;
    proyecto1.setNombre("proyecto 1"); // nombre del proyecto
    proyecto1.setTarea("1. hacer el loguing.");
    mostrarEstadosTareas(proyecto1);
}

/*
1) cuando se cree una una nota guardarlo en un conjunto
2) cuando se vaya a agregar la reaccion a una nota, pedir el identificador de una nota y la reaccion
3) buscar en el conjunto la nota con  el identificador, en caso de que no exista retornar
un "no existe la nota" y en caso de que si exista, agregarlo a la lista de reacciones
*/
