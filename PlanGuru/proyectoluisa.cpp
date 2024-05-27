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
    cout << "Works of the proyect '" << project.name << "':" << endl;
    for (const Task& task : project.tasks) 
    {
        cout << "Name: " << task.name << endl;
        cout << "State: " << task.status << endl;
        cout << "Priority: " << task.priority << endl;
        cout << "Responsable: " << task.responsable << endl;
        cout << "Deadline: " << task.deadline << endl;
        cout << "Resume: " << task.summary << endl;
    }
}

int main() 
{
    Project myProject;
    myProject.name = "My Project";

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
    cout << "Name of the homework: ";
    getline(cin, newTask.name);
    cout << "Status: ";
    getline(cin, newTask.status);
    cout << "Priority: ";
    getline(cin, newTask.priority);
    cout << "Responsable: ";
    getline(cin, newTask.responsable);
    cout << "Dead line: ";
    getline(cin, newTask.deadline);
    cout << "Resume: ";
    getline(cin, newTask.summary);
    
    while (true) {
        Note newNote;
        cout << "Add note to the work (Y/N)? ";
        char choice;
        cin >> choice;
        
        if (toupper(choice) != 'Y')
            break;
        
        cout << "Note title: ";
        getline(cin, newNote.title);
        cout << "Author of the note: ";
        getline(cin, newNote.author);
        cout << "Note Description: ";
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
        cout << "Responsable: " << task.responsable << endl;
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
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task 
{

private:
    string name;
    string description;

public:
    Task(const string& name, const string& description)
        : name(name), description(description) {}

    void showTask() const {
        cout << "Name: " << name << ", Description: " << description << endl;
    }
};

class Project {

private:
    string name;
    vector<Task> tasks;

public:
    Project(const string& name) : name(name) {}

    void addTask(const Task& task) 
    {
        tasks.push_back(task);
    }

    void showTasks() const 
    {
        cout << "Project: " << name << endl;
        for (const auto& task : tasks) 
        {
            task.showTask();
        }
    }
};

class ProjectSystem 
{
private:
    vector<Project> projects;
public:
    void addProject(const Project& project) 
    {
        projects.push_back(project);
    }

    void showProjectTasks() const 
    {
        for (const auto& project : projects) 
        {
            project.showTasks();
        }
    }
};

int main() 
{
    Task task1("Create Trello", "Add the tasks you need to complete during all the proyect.");
    Task task2("Create the codes of the proyect", "Develop the first 8 point of the proyect.");
    Task task3("Join all the codes", "Joint in the order that the program runse.");

    Project project1("Development Project");
    project1.addTask(task1);
    project1.addTask(task2);

    Project project2("Design Project");
    project2.addTask(task3);

    ProjectSystem system;
    system.addProject(project1);
    system.addProject(project2);

    system.showProjectTasks();

    return 0;
}



// 13. El sistema debe permitir organizar los responsables por nombre.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task 
{
private:
    string name;
    string description;

public:
    Task(const string& name, const string& description)
        : name(name), description(description) {}

    void showTask() const 
    {
        cout << "Name: " << name << ", Description: " << description << endl;
    }
};

class Project 
{
private:
    string name;
    vector<Task> tasks;

public:
    Project(const string& name) : name(name) {}

    void addTask(const Task& task) 
    {
        tasks.push_back(task);
    }

    void showTasks() const 
    {
        cout << "Project: " << name << endl;
        for (const auto& task : tasks) 
        {
            task.showTask();
        }
    }
};

class ProjectSystem 
{
private:
    vector<Project> projects;

public:
    void addProject(const Project& project) 
    {
        projects.push_back(project);
    }

    void showProjectTasks() const 
    {
        for (const auto& project : projects) 
        {
            project.showTasks();
        }
    }
};

int main() 
{
    Task task1("Create Trello", "Add the tasks you need to complete during all the proyect.");
    Task task2("Create the codes of the proyect", "Develop the first 8 point of the proyect.");
    Task task3("Join all the codes", "Joint in the order that the program runse.");

    Project project1 ("Development Project");
    project1.addTask (task1);
    project1.addTask (task2);

    Project project2 ("Design Project");
    project2.addTask (task3);

    ProjectSystem system;
    system.addProject(project1);
    system.addProject(project2);

    system.showProjectTasks();

    return 0;
}


// 14. El sistema debe permitir hacer consultas de proyectos por nombres y 
// mostrar las tareas que cada uno contiene.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task 
{
private:
    string name;
    string description;

public:
    Task(const string& name, const string& description)
        : name(name), description(description) {}

    void showTask() const 
    {
        cout << "Name: " << name << ", Description: " << description << endl;
    }
};

class Project 
{
private:
    string name;
    vector<Task> tasks;

public:
    Project(const string& name) : name(name) {}

    void addTask(const Task& task) 
    {
        tasks.push_back(task);
    }

    void showTasks() const 
    {
        cout << "Project: " << name << endl;
        for (const auto& task : tasks) 
        {
            task.showTask();
        }
    }

    string getName() const 
    {
        return name;
    }
};

class ProjectSystem 
{
private:
    vector<Project> projects;

public:
    void addProject(const Project& project) 
    {
        projects.push_back(project);
    }

    void showProjectTasks() const 
    {
        for (const auto& project : projects) 
        {
            project.showTasks();
        }
    }

    void findProjectByName(const string& name) const 
    {
        bool found = false;
        for (const auto& project : projects) 
        {
            if (project.getName() == name) 
            {
                project.showTasks();
                found = true;
                break;
            }
        }
        if (!found) 
        {
            cout << "Project not founded: " << name << endl;
        }
    }
};

int main() 
{
    Task task1("Create Trello", "Add the tasks you need to complete during the project.");
    Task task2("Create the codes of the project", "Develop the first 8 points of the project.");
    Task task3("Join all the codes", "Joint in the order that the program runs.");

    Project project1 ("Development Project");
    project1.addTask (task1);
    project1.addTask (task2);

    Project project2 ("Design Project");
    project2.addTask (task3);

    ProjectSystem system;
    system.addProject(project1);
    system.addProject(project2);

    system.showProjectTasks();

    return 0;
   
    cout << "All the projects and their tasks:" << endl;
    system.showProjectTasks();

    cout << "Finding project by name 'Development Project':" << endl;
    system.findProjectByName("Development Project");

    cout << "Searching for the project by the name 'Non-existent Project':" << endl;
    system.findProjectByName("Non-existent Project");

    return 0;
}

//19. El sistema debe mostrar los proyetos por fechas
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Project 
{
    string name;
    string date; 
};

bool compareProjectsByDate(const Project& a, const Project& b) 
{
    return a.date < b.date;
}

int main() 
{
    vector<Project> projects = 
    {
        {"Project A", "2024-05-10"},
        {"Project B", "2024-07-14"},
        {"Project C", "2024-04-20"}
    };

    sort(projects.begin(), projects.end(), compareProjectsByDate);

    cout << "Proyectos ordenados por fecha:" << endl;
    for (const auto& project : projects) 
    {
        cout << "Name: " << project.name << ", Date: " << project.date << endl;
    }

    return 0;
}
