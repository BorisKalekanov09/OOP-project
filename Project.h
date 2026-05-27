#ifndef PROJECT_H
#define PROJECT_H

#include "Task.h"
#include <string>
#include <vector>
class Project
{
private:
    std::string name;
    std::vector<Task> tasks;

public:
    Project(std::string name = "Unknown");

    std::string getName() const;

    void addTask(Task task);

    int findTaskIndex(std::string taskName);

    bool updateTask(std::string taskName, std::string newName, std::string newDeadline, int newPriority);

    bool deleteTask(std::string taskName);

    void removeTask(std::string taskName);

    std::vector<Task> getTasks() const;

    bool markTaskAsCompleted(std::string taskName);

    void showTasks();

    void showUncompletedTasks();

    void showCompletedTasks();

    void sortTasksByPriority();

    void FindTaskByName(const std::string &n);
};

#endif
