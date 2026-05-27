#include "Task.h"
#include <iostream>

using namespace std;
Task::Task(string name, string deadline, int priority, bool isCompleted)
    : TaskItem(name)
{
    this->deadline = deadline;
    this->priority = priority;
    this->isCompleted = isCompleted;
}

void Task::setDeadline(string newDeadline)
{
    this->deadline = newDeadline;
}

void Task::setPriority(int newPriority)
{
    this->priority = newPriority;
}

void Task::setCompleted(bool completed)
{
    this->isCompleted = completed;
}

void Task::markAsCompleted()
{
    this->isCompleted = true;
}

string Task::getDeadline()
{
    return this->deadline;
}

int Task::getPriority()
{
    return this->priority;
}

bool Task::getCompleted()
{
    return this->isCompleted;
}

void Task::display()
{
    cout << "Task name: " << getName() << endl;
    cout << "Deadline: " << this->deadline << endl;
    cout << "Priority: " << this->priority << endl;
    cout << "Status: " << (this->isCompleted ? "completed" : "not completed") << endl;
}
