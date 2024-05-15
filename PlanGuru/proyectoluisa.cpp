// Proyecto LUISA
// 3. El sistema debe permitir crear las tareas incluyendo nombre de la tarea, 
// estado, prioridad, Responsable, Fecha límite, Resumen (Comentarios).
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task 
{
    string name;
    string status;
    string priority;
    string responsable;
    string deadline;
    string summary;
};

struct Project 
{
    string name;
    vector <Task> tasks;
};

void addTask(Project& project) 
{
    Task newTask;
    cout << "Name of the work: ";
    getline(cin, newTask.name);
    cout << "State: ";
    getline(cin, newTask.status);
    cout << "Prioirity: ";
    getline(cin, newTask.priority);
    cout << "Responsable: ";
    getline(cin, newTask.responsable);
    cout << "Deadline: ";
    getline(cin, newTask.deadline);
    cout << "Resume: ";
    getline(cin, newTask.summary);
    
    project.tasks.push_back(newTask);
    cout << "Work added to the proyect." << endl;
}

void showTasks(const Project& project) 
{
    cout << "TWorks of the proyect '" << project.name << "':" << endl;
    for (const Task& task : project.tasks) 
    {
        cout << "Name: " << task.name << endl;
        cout << "Satet: " << task.status << endl;
        cout << "Priority: " << task.priority << endl;
        cout << "Responsable: " << task.responsable << endl;
        cout << "Deadline: " << task.deadline << endl;
        cout << "Resume: " << task.summary << endl;
        cout << "---------------------------------" << endl;
    }
}

int main() 
{
    Project myProject;
    myProject.name = "My Proyect";

    while (true) {
        cout << "1. Add work" << endl;
        cout << "2. Show work" << endl;
        cout << "3. Get out" << endl;
        cout << "Digit the option you want: ";
        int choice;
        cin >> choice;
        
        switch(choice) 
        {
            case 1:
                addTask(myProject);
                break;
            case 2:
                showTasks(myProject);
                break;
            case 3:
                cout << "Getting out..." << endl;
                return 0;
            default:
                cout << "Invalid option. Please enter a valid option." << endl;
        }
    }

    return 0;
}


// 4. El sistema debe permitir agregar una o más notas a cada proyecto y/o tareas, 
// incluyendo título de la nota, autor de la nota y descripción.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Note 
{
    string title;
    string author;
    string description;
};

struct Task 
{
    string name;
    string status;
    string priority;
    string responsable;
    string deadline;
    string summary;
    vector <Note> notes;
};

struct Project 
{
    string name;
    vector<Task> tasks;
    vector<Note> notes; 
};

void addTask(Project& project) 
{
    Task newTask;
    cout << "Nombre de la tarea: ";
    getline(cin, newTask.name);
    cout << "Estado: ";
    getline(cin, newTask.status);
    cout << "Prioridad: ";
    getline(cin, newTask.priority);
    cout << "Responsable: ";
    getline(cin, newTask.responsible);
    cout << "Fecha límite: ";
    getline(cin, newTask.deadline);
    cout << "Resumen: ";
    getline(cin, newTask.summary);
    
    while (true) {
        Note newNote;
        cout << "Agregar nota a la tarea (S/N)? ";
        char choice;
        cin >> choice;
        
        if (toupper(choice) != 'S')
            break;
        
        cout << "Título de la nota: ";
        getline(cin, newNote.title);
        cout << "Autor de la nota: ";
        getline(cin, newNote.author);
        cout << "Descripción de la nota: ";
        getline(cin, newNote.description);
        
        newTask.notes.push_back(newNote);
    }
    
    project.tasks.push_back(newTask);
    cout << "Tarea agregada al proyecto." << endl;
}

void showTasks(const Project& project) 
{
    cout << "Tareas en el proyecto '" << project.name << "':" << endl;
    for (const Task& task : project.tasks) 
    {
        cout << "Nombre: " << task.name << endl;
        cout << "Estado: " << task.status << endl;
        cout << "Prioridad: " << task.priority << endl;
        cout << "Responsable: " << task.responsible << endl;
        cout << "Fecha límite: " << task.deadline << endl;
        cout << "Resumen: " << task.summary << endl;
        
        if (!task.notes.empty()) 
        {
            cout << "Notas:" << endl;
            for (const Note& note : task.notes) 
            {
                cout << "  - Título: " << note.title << endl;
                cout << "    Autor: " << note.author << endl;
                cout << "    Descripción: " << note.description << endl;
            }
        }
        
        cout << "---------------------------------" << endl;
    }
}

int main() 
{
    Project myProject;
    myProject.name = "Mi Proyecto";

    while (true) 
    {
        cout << "1. Agregar tarea" << endl;
        cout << "2. Mostrar tareas" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opción: ";
        int choice;
        cin >> choice;
        
        switch(choice) 
        {
            case 1:
                addTask(myProject);
                break;
            case 2:
                showTasks(myProject);
                break;
            case 3:
                cout << "Saliendo..." << endl;
                return 0;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
        }
    }

    return 0;
}

// 8. El sistema debe permitir mostrar los proyectos creados con sus detalles.
#include <iostream>
#include <vector>
#include <string>

class Proyecto {
private:
    std::string nombre;
    std::string descripcion;
    std::string fechaInicio;
    std::string fechaFin;

public:
    // Constructor
    Proyecto(std::string nombre, std::string descripcion, std::string fechaInicio, std::string fechaFin) 
        : nombre(nombre), descripcion(descripcion), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

    // Método para mostrar los detalles del proyecto
    void mostrarDetalles() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Descripción: " << descripcion << std::endl;
        std::cout << "Fecha de Inicio: " << fechaInicio << std::endl;
        std::cout << "Fecha de Finalización: " << fechaFin << std::endl;
    }
};

// Función para añadir un nuevo proyecto
void agregarProyecto(std::vector<Proyecto>& proyectos) {
    std::string nombre, descripcion, fechaInicio, fechaFin;

    std::cout << "Ingrese el nombre del proyecto: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese la descripción del proyecto: ";
    std::getline(std::cin, descripcion);
    std::cout << "Ingrese la fecha de inicio del proyecto (YYYY-MM-DD): ";
    std::getline(std::cin, fechaInicio);
    std::cout << "Ingrese la fecha de finalización del proyecto (YYYY-MM-DD): ";
    std::getline(std::cin, fechaFin);

    Proyecto nuevoProyecto(nombre, descripcion, fechaInicio, fechaFin);
    proyectos.push_back(nuevoProyecto);
}

// Función para mostrar los detalles de todos los proyectos
void mostrarProyectos(const std::vector<Proyecto>& proyectos) {
    for (const auto& proyecto : proyectos) {
        proyecto.mostrarDetalles();
        std::cout << "---------------------" << std::endl;
    }
}

int main() {
    std::vector<Proyecto> proyectos;
    int opcion;

    do {
        std::cout << "1. Agregar Proyecto" << std::endl;
        std::cout << "2. Mostrar Proyectos" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el salto de línea después de la opción

        switch (opcion) {
            case 1:
                agregarProyecto(proyectos);
                break;
            case 2:
                mostrarProyectos(proyectos);
                break;
            case 3:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 3);

    return 0;
}


// 9. El sistema debe permitir mostrar las tareas de cada uno de sus proyectos.


// 13. El sistema debe permitir organizar los responsables por nombre.

// 14. El sistema debe permitir hacer consultas de proyectos por nombres y 
// mostrar las tareas que cada uno contiene.