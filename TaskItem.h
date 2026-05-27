#ifndef TASKITEM_H
#define TASKITEM_H

#include <string>
class TaskItem
{
protected:
    std::string name;

public:
    TaskItem(std::string name = "Unknown");

    virtual ~TaskItem();

    virtual void display() = 0;

    std::string getName();

    void setName(std::string newName);
};

#endif
