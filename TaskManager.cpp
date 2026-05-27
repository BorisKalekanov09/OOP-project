#include "TaskManager.h"
#include <iostream>

using namespace std;
void TaskManager::addProject(string name)
{
    this->projects.push_back(Project(name));
}

void TaskManager::removeProject(string name)
{
    for (int i = 0; i < (int)this->projects.size(); i++)
    {
        if (this->projects[i].getName() == name)
        {
            this->projects.erase(this->projects.begin() + i);
            return;
        }
    }
}

void TaskManager::addTaskToProject(string projectName, Task task)
{
    for (int i = 0; i < (int)this->projects.size(); i++)
    {
        if (this->projects[i].getName() == projectName)
        {
            this->projects[i].addTask(task);
            return;
        }
    }
}

void TaskManager::showAllTasks()
{
    if (this->projects.empty())
    {
        cout << "No projects available." << endl;
        return;
    }
    for (int i = 0; i < (int)this->projects.size(); i++)
    {
        this->projects[i].showTasks();
    }
}

void TaskManager::showTasksInProject(string projectName)
{
    for (int i = 0; i < (int)this->projects.size(); i++)
    {
        if (this->projects[i].getName() == projectName)
        {
            this->projects[i].showTasks();
            return;
        }
    }
    cout << "Project not found." << endl;
}

void TaskManager::filterTasks()
{
    cout << "1. Filter Uncompleted Tasks" << endl;
    cout << "2. Filter Completed Tasks" << endl;
    cout << "Choose an option: ";
    int choice;
    cin >> choice;
    cin.ignore();
    
    for (int i = 0; i < (int)this->projects.size(); i++)
    {
        if (choice == 1)
        {
            this->projects[i].showUncompletedTasks();
        }
        else if (choice == 2)
        {
            this->projects[i].showCompletedTasks();
        }
    }
}

void TaskManager::sortTasks()
{
    for (int i = 0; i < (int)this->projects.size(); i++)
    {
        this->projects[i].sortTasksByPriority();
    }
}

void TaskManager::searchTask()
{
    string n;
    cout << "Enter task name to search: ";
    getline(cin, n);
    for (int i = 0; i < (int)this->projects.size(); i++)
    {
        this->projects[i].FindTaskByName(n);
    }
}

void TaskManager::showStatistics()
{
    int completedCount = 0;
    int uncompletedCount = 0;
    
    for (int i = 0; i < (int)this->projects.size(); i++)
    {
        vector<Task> tasks = this->projects[i].getTasks();
        for (int j = 0; j < (int)tasks.size(); j++)
        {
            if (tasks[j].getCompleted())
            {
                completedCount++;
            }
            else
            {
                uncompletedCount++;
            }
        }
    }
    cout << "=== Task Statistics ===" << endl;
    cout << "Total completed tasks: " << completedCount << endl;
    cout << "Total uncompleted tasks: " << uncompletedCount << endl;
    cout << "Total tasks: " << (completedCount + uncompletedCount) << endl;
}

vector<Project>& TaskManager::getProjects()
{
    return this->projects;
}
