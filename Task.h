#ifndef TASK_H
#define TASK_H

#include "TaskItem.h"
#include <string>
class Task : public TaskItem
{
private:
    std::string deadline;
    int priority;
    bool isCompleted;

public:
    Task(std::string name = "Unknown", std::string deadline = "", int priority = 0, bool isCompleted = false);

    void setDeadline(std::string newDeadline);
    void setPriority(int newPriority);
    void setCompleted(bool completed);
    void markAsCompleted();

    std::string getDeadline();
    int getPriority();
    bool getCompleted();

    void display() override;
};

#endif
