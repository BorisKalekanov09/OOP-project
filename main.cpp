#include <iostream>
#include <string>
#include <vector>
#include "TaskManager.h"
#include "Utils.h"

using namespace std;
int main()
{
    TaskManager manager;

    manager.addProject("Default Project");

    int mainChoice = 0;
    do
    {
        cout << endl;
        cout << "=== Project Management ===" << endl;
        cout << "1. List all projects" << endl;
        cout << "2. Create a new project" << endl;
        cout << "3. Delete a project" << endl;
        cout << "4. Select a project" << endl;
        cout << "5. View tasks in a specific project" << endl;
        cout << "6. Filter/Show tasks (Completed/Uncompleted)" << endl;
        cout << "7. Task Statistics (Completed/Uncompleted count)" << endl;
        cout << "8. Exit" << endl;
        cout << "Choose an option: ";
        cin >> mainChoice;
        cin.ignore();

        if (mainChoice == 1)
        {
            if (manager.getProjects().empty())
            {
                cout << "No projects available." << endl;
            }
            else
            {
                cout << "Projects list:" << endl;
                for (int i = 0; i < (int)manager.getProjects().size(); i++)
                {
                    cout << "- " << manager.getProjects()[i].getName() << endl;
                }
            }
        }
        else if (mainChoice == 2)
        {
            string projName;
            cout << "Enter new project name: ";
            getline(cin, projName);
            manager.addProject(projName);
            cout << "Project '" << projName << "' created successfully." << endl;
        }
        else if (mainChoice == 3)
        {
            string projName;
            cout << "Enter project name to delete: ";
            getline(cin, projName);

            bool exists = false;
            for (int i = 0; i < (int)manager.getProjects().size(); i++)
            {
                if (manager.getProjects()[i].getName() == projName)
                {
                    exists = true;
                    break;
                }
            }
            if (exists)
            {
                manager.removeProject(projName);
                cout << "Project '" << projName << "' deleted successfully." << endl;
            }
            else
            {
                cout << "Project not found." << endl;
            }
        }
        else if (mainChoice == 4)
        {
            string projName;
            cout << "Enter project name to select: ";
            getline(cin, projName);
            int index = -1;
            for (int i = 0; i < (int)manager.getProjects().size(); i++)
            {
                if (manager.getProjects()[i].getName() == projName)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Project not found." << endl;
                continue;
            }

            Project &project = manager.getProjects()[index];
            int choice = 0;
            do
            {
                cout << endl;
                cout << "=== Project: " << project.getName() << " ===" << endl;
                cout << "1. Add task" << endl;
                cout << "2. Show all tasks" << endl;
                cout << "3. Update task" << endl;
                cout << "4. Delete task" << endl;
                cout << "5. Mark task as completed" << endl;
                cout << "6. Filter Uncompleted Tasks" << endl;
                cout << "7. Filter Completed Tasks" << endl;
                cout << "8. Sort tasks by priority" << endl;
                cout << "9. Search task by name" << endl;
                cout << "10. Back to Project Management" << endl;

                cout << "Choose an option: ";
                cin >> choice;
                cin.ignore();

                if (choice == 1)
                {
                    string name;
                    string deadline;
                    int priority;

                    cout << "Task name: ";
                    getline(cin, name);

                    deadline = readDeadline("Deadline (YYYY-MM-DD format): ");
                    cout << "Priority: ";
                    cin >> priority;
                    cin.ignore();

                    manager.addTaskToProject(project.getName(), Task(name, deadline, priority, false));
                    cout << "Task added." << endl;
                }
                else if (choice == 2)
                {
                    project.showTasks();
                }
                else if (choice == 3)
                {
                    string taskName;
                    string newName;
                    string newDeadline;
                    int newPriority;

                    cout << "Current task name: ";
                    getline(cin, taskName);
                    cout << "New task name: ";
                    getline(cin, newName);
                    newDeadline = readDeadline("New deadline (YYYY-MM-DD format): ");
                    cout << "New priority: ";
                    cin >> newPriority;
                    cin.ignore();

                    try
                    {
                        project.updateTask(taskName, newName, newDeadline, newPriority);
                        cout << "Task updated." << endl;
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << endl;
                    }
                }
                else if (choice == 4)
                {
                    string taskName;
                    cout << "Task name to delete: ";
                    getline(cin, taskName);

                    try
                    {
                        project.deleteTask(taskName);
                        cout << "Task deleted." << endl;
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << endl;
                    }
                }
                else if (choice == 5)
                {
                    string taskName;
                    cout << "Task name to mark as completed: ";
                    getline(cin, taskName);

                    try
                    {
                        project.markTaskAsCompleted(taskName);
                        cout << "Task marked as completed." << endl;
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << endl;
                    }
                }
                else if (choice == 6)
                {
                    project.showUncompletedTasks();
                }
                else if (choice == 7)
                {
                    project.showCompletedTasks();
                }
                else if (choice == 8)
                {
                    project.sortTasksByPriority();
                }
                else if (choice == 9)
                {
                    string n;
                    cout << "Enter task name to search: ";
                    getline(cin, n);
                    project.FindTaskByName(n);
                }
                else
                {
                    break;
                }
            } while (true);
        }
        else if (mainChoice == 5)
        {
            string projName;
            cout << "Enter project name to view tasks: ";
            getline(cin, projName);
            manager.showTasksInProject(projName);
        }
        else if (mainChoice == 6)
        {
            manager.filterTasks();
        }
        else if (mainChoice == 7)
        {
            manager.showStatistics();
        }
        else if (mainChoice == 8)
        {
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (true);

    return 0;
}