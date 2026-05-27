#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Project.h"
#include <vector>
#include <string>
class TaskManager
{
private:
    std::vector<Project> projects;

public:
    void addProject(std::string name);

    void removeProject(std::string name);

    void addTaskToProject(std::string projectName, Task task);

    void showAllTasks();

    void showTasksInProject(std::string projectName);

    void filterTasks();

    void sortTasks();

    void searchTask();

    void showStatistics();

    std::vector<Project>& getProjects();
};

#endif
