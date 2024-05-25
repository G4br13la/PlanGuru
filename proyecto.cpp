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
    string getNombre_usuario()
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

class Tareas
{
private:
    string nombre_tarea;
    string estado;
    string prioridad;
    string responsable;
    string comentarios;

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

    bool operator<(const Tareas &otra) const
    {
        return nombre_tarea < otra.nombre_tarea;
    }

    string getNombre_tarea() const
    {
        return nombre_tarea;
    }
    string getEstado()
    {
        return estado;
    }
    string getPrioridad()
    {
        return prioridad;
    }
    string getResponsable()
    {
        return responsable;
    }
    string getComentarios()
    {
        return comentarios;
    }

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

    // void asignar_tarea_persona(set<Tareas> &tarea, set<Usuario> persona)
    // {
    //     string nombre_tarea;
    //     string nombre_usuario;
    //     string tarea_no_encotrada;
    //     string usuario_no_encontrado;

    //     cout << "ingresa el nombre de la tarea";
    //     cin.ignore();
    //     getline(cin, nombre_tarea);
    //     cout << "ingresa el nombre de la persona";
    //     getline(cin, nombre_usuario);

    //     auto iterador = tarea.find(nombre_tarea);

    //     if (iterador != tarea.end())
    //     {
    //         cout << "Se encontró la tarea." << endl;
    //         tarea.setNombre_tarea(nombre_tarea);
    //     }
    //     else
    //     {
    //         cout << "No se encontró la tarea. " << endl;
    //     }

    //     auto iterador2 = persona.find(nombre_usuario);

    //     if (iterador != persona.end())
    //     {
    //         cout << "Se encontró al usuario." << endl;
    //         persona.setNombre_usuario(nombre_usuario);
    //     }
    //     else
    //     {
    //         cout << "No se encontró el usuario. " << endl;
    //     }

    //     tarea.setResponsable(persona.getNombre_usuario());
    //     cout << "tarea asignada a: " << endl;
    // }

    // void ordenar_tarea_prioridad()
    // {
    //     string prioridad_alta;
    //     string prioridad_media;
    //     string prioridad_baja;
    // }
};

class Proyecto
{
private:
    string nombre_proyecto;
    string propietario;
    string descripcion;
    string estado_proyecto;
    set<Tareas> tareas;

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

    void agregar_tarea(Tareas tarea)
    {
        tareas.insert(tarea);
    }

    // void eliminar_tarea(int indice)
    // {
    //     tareas.erase(tareas.begin() + indice);
    // }

    void CrearProyecto(set<Proyecto> proyectos)
    {
        Proyecto proyecto;
        cout << "ingresa nombre: ";
        cin >> nombre_proyecto;
        cout << "Ingresa propietario: ";
        cin >> propietario;
        cout << "Ingressa descripcion: ";
        cin >> descripcion;

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

    // Método para mostrar los detalles del proyecto
    void mostrarProyectos(vector<Proyecto> proyectos)
    {
        for (const auto &proyecto : proyectos)
        {
            cout << "Nombre del proyecto: " << proyecto.nombre_proyecto << endl;
            cout << "Descripción del proyecto: " << proyecto.descripcion << endl;
            cout << "Propietario del proyecto: " << proyecto.propietario << endl;
        }
    }

    // void estado_tareas(vector<Proyecto> proyectos)
    // {
    //     for (const auto &proyecto : proyectos)
    //     {
    //         cout << "Nombre del proyecto: " << proyecto.nombre_proyecto << endl;
    //         cout << "Estados de las tareas:" << endl;
    //         for (const auto &tarea : proyecto.tareas)
    //         {
    //             cout << "Nombre de la tarea: " << tarea.nombre_tarea << endl;
    //             cout << "Estado de la tarea: " << tarea.estado << endl;
    //             cout << "Prioridad de la tarea: " << tarea.prioridad << endl;
    //         }
    //     }
    // }

    // void mostrar_proyectos() const
    // {
    //     cout << "nombre del proyecto: " << nombre_proyecto << endl;
    //     cout << "descripcion: " << descripcion << endl;
    //     cout << "propietario: " << propietario << endl;
    //     cout << "estado del proyecto: " << estado_proyecto << endl;
    // }
};

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
    string getTitulo_notas()
    {
        return titulo_nota;
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

    // void agregar_notas_tareas(map<string, Tareas> tarea, map<string, vector<Nota>> &notas)
    // {
    //     while (true)
    //     {
    //         string opcion;
    //         cout << "¿Quiere agregarle un nota a la nota? si/no" << endl;
    //         cin >> opcion;
    //         if (opcion == "si")
    //         {
    //             Notas nueva_nota;
    //             cout << "Ingrese el titulo de la nota: " << endl;
    //             getline(cin, nueva_nota.titulo_notas);
    //             cout << "Ingrese el autor de la nota: " << endl;
    //             getline(cin, nueva_nota.autor_nota);
    //             cout << "Ingrese los comentarios de la nota: " << endl;
    //             getline(cin, nueva_nota.comentarios);
    //             cout << "Ingrese las reacciones de la nota: " << endl;

    //             tarea.Notas.push_back(nueva_nota);
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    // }

    // void agregar_notas_proyecto(map<Proyecto, vector<Notas>> & proyecto)
    // {
    //     while (true)
    //     {
    //         string opcion;
    //         cout << "¿Quiere agregarle un titulo al proyecto? si/no" << endl;
    //         cin >> opcion;
    //         if (opcion == "si")
    //         {
    //             Notas nueva_nota;
    //             cout << "Ingrese el titulo de la nota: " << endl;
    //             getline(cin, nueva_nota.titulo_notas);
    //             cout << "Ingrese el autor de la nota: " << endl;
    //             getline(cin, nueva_nota.autor_nota);
    //             cout << "Ingrese los comentarios de la nota: " << endl;
    //             getline(cin, nueva_nota.comentarios);
    //             cout << "Ingrese las reacciones de la nota: " << endl;

    //             proyecto.Notas.push_back(nueva_nota);
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    // }

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

    void mostrar_notas(string nota, set<string> titulos_notas)
    {
        auto iterador = titulos_notas.find(nota); // busca el titulo de la nota en el vector de titulos
        if (iterador != titulos_notas.end())      // si se encuentra el titulo
        {
            cout << " Se encontró " << nota << " en las notas" << endl;
            cout << titulo_nota;
            cout << autor_nota;
            cout << comentarios;
        }
        else
        {
            cout << " No se encontró " << nota << "en las notas" << endl;
        }
    }
};

// class Interfaz
// {
// public:
//     void mostrarMenu()
//     {
//         int opcion;
//         do
//         {
//             cout << "Bienvenido." << endl;
//             cout << " " << endl;
//             cout << "¿Que quieres hacer?" << endl;
//             cout << " " << endl;
//             cout << "1. Login ." << endl;
//             cout << "2. Crear Proyecto" << endl;
//             cout << "3. Crear tareas." << endl;
//             cout << "4. Asignar tareas." << endl;
//             cout << "5. Agregar notas." << endl;
//             cout << "6. reacionar a las notas." << endl;
//             cout << "7. Ver el estado de los proyectos o tareas." << endl;
//             cout << " " << endl;
//             cout << "¡Buena suerte!" << endl;
//             cout << " " << endl;
//             cout << "EMPECEMOS :D : " << endl;
//             cout << " " << endl;
//             cout << "Ingrese su opción: ";
//             cin >> opcion;

//             switch (opcion)
//             {
//             case 1:
//                 Fijas_Picas();
//                 break;
//             case 2:
//                 Tres_en_linea();
//                 break;
//             case 3:
//                 cout << "Saliendo del programa..." << endl;
//                 break;
//             default:
//                 cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
//                 break;
//             }
//         } while (opcion != 3);
//     }
// }

int main()
{
    Usuario usuario;
    set<Usuario> usuarios;
    usuario.registro(usuarios);

    // set<string> titulo_notas;
    // Notas nota1;

    // nota1.setTitulo_notas("prueba 1");
    // titulo_notas.insert("prueba 1");
    // nota1.setAutor_nota("gabs");
    // nota1.agregar_reaccion("prueba 1", "no me gusta .-.", titulo_notas);
    // nota1.agregar_reaccion("prueba 1", "no me gusta x2 .-.", titulo_notas);
    // nota1.mostrar_notas("prueba 1", titulo_notas);

    // Notas nota2;

    // nota2.setTitulo_notas("prueba 2");
    // titulo_notas.insert("prueba 2");
    // nota2.setAutor_nota("santiago");
    // nota2.agregar_reaccion("prueba 2", "si me gusta .-.", titulo_notas);
    // nota2.agregar_reaccion("prueba 2", "si me gusta x2 .-.", titulo_notas);
    // nota1.mostrar_notas("prueba 2", titulo_notas);

    // vector<string> reaccion1 = nota1.getReacciones();
    // vector<string> reaccion2 = nota2.getReacciones();

    // for (int i = 0; i < reaccion1.size(); i++)
    // {
    //     cout << reaccion1[i] << endl;
    // }

    // for (int i = 0; i < reaccion2.size(); i++)
    // {
    //     cout << reaccion2[i] << endl;
    // }

    // Proyecto proyecto1;
    // proyecto1.setNombre("proyecto 1"); // nombre del proyecto
    // proyecto1.setTarea("1. hacer el loguing.");
    // mostrarEstadosTareas(proyecto1);
}
