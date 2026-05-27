#include "TaskItem.h"

using namespace std;
TaskItem::TaskItem(string name)
{
    this->name = name;
}

TaskItem::~TaskItem()
{
}

string TaskItem::getName()
{
    return this->name;
}

void TaskItem::setName(string newName)
{
    this->name = newName;
}
