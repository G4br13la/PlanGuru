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
        cout << "State: " << task.status << endl;
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
    getline(cin, newTask.responsable);
    cout << "Fecha límite: ";
    getline(cin, newTask.deadline);
    cout << "Resumen: ";
    getline(cin, newTask.summary);
    
    while (true) {
        Note newNote;
        cout << "Add note to the work (S/N)? ";
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
    cout << "Task added to project." << endl;
}

void showTasks(const Project& project) 
{
    cout << "Tasks in the project '" << project.name << "':" << endl;
    for (const Task& task : project.tasks) 
    {
        cout << "Name: " << task.name << endl;
        cout << "State: " << task.status << endl;
        cout << "Priority: " << task.priority << endl;
        cout << "Responsable: " << task.responsible << endl;
        cout << "Dead line: " << task.deadline << endl;
        cout << "Resume: " << task.summary << endl;
        
        if (!task.notes.empty()) 
        {
            cout << "Notas:" << endl;
            for (const Note& note : task.notes) 
            {
                cout << "Title: " << note.title << endl;
                cout << "Author: " << note.author << endl;
                cout << "Description: " << note.description << endl;
            }
        }
        
        cout << "---------------------------------" << endl;
    }
}

int main() 
{
    Project myProject;
    myProject.name = "My Proyect";

    while (true) 
    {
        cout << "1. Add work" << endl;
        cout << "2. Show work" << endl;
        cout << "3. Salir" << endl;
        cout << "Get out: ";
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

// 8. El sistema debe permitir mostrar los proyectos creados con sus detalles.
#include <iostream>
#include <vector>
#include <string>

class Proyecto 
{
private:
    string name;
    string description;
    string startDate;
    string endDate;

public:
    Proyecto(string nombre, string descripcion, string fechaInicio, string fechaFin) 
        : name(name), description(description), startDate(startDate), endDate(endDate) {}

    void showDetails() const 
    {
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Start date: " << startDate << endl;
        cout << "Finish date: " << finishDate << endl;
    }
};

void addProyect(vector<Proyect>& proyects) 
    {
    string name, description, startDate, finishDate;
    
    cout << "Enter the project name: ";
    getline(cin, name);
    cout << "Ingrese la descripción del proyecto: ";
    getline(cin, description);
    cout << "Enter the project start date (YYYY-MM-DD): ";
    getline(cin, startDate);
    cout << "Enter the project end date (YYYY-MM-DD): ";
    getline(cin, finishDate);

    Proyect addProyect(name, description, startDate, finishDate);
    proyects.push_back(addProyect);
}

void showProjects (const vector<Proyect>& proyects) 
{
    for (const auto& proyect : proyects) 
    {
        proyect.showDetails();
        cout << "---------------------" << endl;
    }
}

int main() 
    {
    vector<Proyect> proyects;
    int opcion;

    do 
    {
        cout << "1. Add project" << endl;
        cout << "2. Show Projects" << endl;
        cout << "3. Get out" << endl;
        cout << "Select an option: ";
        cin >> option;

        switch (option) 
        {
            case 1:
                addProyect(proyects);
                break;
            case 2:
                showProyects(proyectos);
                break;
            case 3:
                cout << "Getting out..." << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    } 
        while (opcion != 3);

    return 0;
}


// 9. El sistema debe permitir mostrar las tareas de cada uno de sus proyectos.


// 13. El sistema debe permitir organizar los responsables por nombre.

// 14. El sistema debe permitir hacer consultas de proyectos por nombres y 
// mostrar las tareas que cada uno contiene.
