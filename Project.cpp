#include "Project.h"
#include <iostream>
#include <stdexcept>

using namespace std;
Project::Project(string name)
{
    this->name = name;
}

string Project::getName() const
{
    return this->name;
}

void Project::addTask(Task task)
{
    this->tasks.push_back(task);
}

int Project::findTaskIndex(string taskName)
{
    for (int i = 0; i < (int)this->tasks.size(); i++)
    {
        if (this->tasks[i].getName() == taskName)
        {
            return i;
        }
    }
    return -1;
}

bool Project::updateTask(string taskName, string newName, string newDeadline, int newPriority)
{
    int index = findTaskIndex(taskName);
    if (index == -1)
    {
        throw std::out_of_range("Task '" + taskName + "' not found in project '" + this->name + "'.");
    }

    this->tasks[index].setName(newName);
    this->tasks[index].setDeadline(newDeadline);
    this->tasks[index].setPriority(newPriority);
    return true;
}

bool Project::deleteTask(string taskName)
{
    int index = findTaskIndex(taskName);
    if (index == -1)
    {
        throw std::out_of_range("Task '" + taskName + "' not found in project '" + this->name + "'.");
    }

    this->tasks.erase(this->tasks.begin() + index);
    return true;
}

void Project::removeTask(string taskName)
{
    deleteTask(taskName);
}

vector<Task> Project::getTasks() const
{
    return this->tasks;
}

bool Project::markTaskAsCompleted(string taskName)
{
    int index = findTaskIndex(taskName);
    if (index == -1)
    {
        throw std::out_of_range("Task '" + taskName + "' not found in project '" + this->name + "'.");
    }

    this->tasks[index].markAsCompleted();
    return true;
}

void Project::showTasks()
{
    if (this->tasks.empty())
    {
        cout << "No tasks in project '" << this->name << "'." << endl;
        return;
    }

    cout << "Project: " << this->name << endl;
    for (int i = 0; i < (int)this->tasks.size(); i++)
    {
        cout << "--------------------" << endl;
        this->tasks[i].display();
    }
}

void Project::showUncompletedTasks()
{
    if (this->tasks.empty())
    {
        cout << "No tasks in project '" << this->name << "'." << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < (int)this->tasks.size(); i++)
    {
        if (this->tasks[i].getCompleted() == false)
        {
            cout << "--------------------" << endl;
            this->tasks[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "No uncompleted tasks found." << endl;
}

void Project::showCompletedTasks()
{
    if (this->tasks.empty())
    {
        cout << "No tasks in project '" << this->name << "'." << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < (int)this->tasks.size(); i++)
    {
        if (this->tasks[i].getCompleted() == true)
        {
            cout << "--------------------" << endl;
            this->tasks[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "No completed tasks found." << endl;
}

void Project::sortTasksByPriority()
{
    if (this->tasks.empty())
    {
        cout << "No tasks in project '" << this->name << "'." << endl;
        return;
    }

    for (int i = 0; i < (int)this->tasks.size(); i++)
    {
        for (int j = i + 1; j < (int)this->tasks.size(); j++)
        {
            if (this->tasks[i].getPriority() > this->tasks[j].getPriority())
            {
                Task temp = this->tasks[i];
                this->tasks[i] = this->tasks[j];
                this->tasks[j] = temp;
            }
        }
    }
    cout << "Tasks sorted successfully!" << endl;
    showTasks();
}

void Project::FindTaskByName(const string &n)
{
    if (this->tasks.empty())
    {
        cout << "No tasks in project '" << this->name << "'." << endl;
        return;
    }
    bool found = false;
    for (int i = 0; i < (int)this->tasks.size(); i++)
    {
        if (this->tasks[i].getName() == n)
        {
            this->tasks[i].display();
            found = true;
        }
    }
    if (!found)
        cout << "Task '" << n << "' not found." << endl;
}
