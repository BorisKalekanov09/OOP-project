#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TaskItem
{
protected:
    string name;

public:
    TaskItem(string name = "Unknown")
    {
        this->name = name;
    }

    virtual ~TaskItem() {}

    virtual void display() = 0;

    string getName()
    {
        return this->name;
    }

    void setName(string newName)
    {
        this->name = newName;
    }
};

class Task : public TaskItem
{
private:
    string deadline;
    int priority;
    bool isCompleted;

public:
    Task(string name = "Unknown", string deadline = "", int priority = 0, bool isCompleted = false)
        : TaskItem(name)
    {
        this->deadline = deadline;
        this->priority = priority;
        this->isCompleted = isCompleted;
    }

    void setDeadline(string newDeadline)
    {
        this->deadline = newDeadline;
    }

    void setPriority(int newPriority)
    {
        this->priority = newPriority;
    }

    void setCompleted(bool completed)
    {
        this->isCompleted = completed;
    }

    void markAsCompleted()
    {
        this->isCompleted = true;
    }

    string getDeadline()
    {
        return this->deadline;
    }

    int getPriority()
    {
        return this->priority;
    }

    bool getCompleted()
    {
        return this->isCompleted;
    }

    void display() override
    {
        cout << "Task name: " << getName() << endl;
        cout << "Deadline: " << this->deadline << endl;
        cout << "Priority: " << this->priority << endl;
        cout << "Status: " << (this->isCompleted ? "completed" : "not completed") << endl;
    }
};

class Project
{
private:
    string name;
    vector<Task> tasks;

public:
    Project(string name = "Unknown")
    {
        this->name = name;
    }

    void addTask(Task task)
    {
        this->tasks.push_back(task);
    }

    int findTaskIndex(string taskName)
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

    bool updateTask(string taskName, string newName, string newDeadline, int newPriority)
    {
        int index = findTaskIndex(taskName);
        if (index == -1)
        {
            return false;
        }

        this->tasks[index].setName(newName);
        this->tasks[index].setDeadline(newDeadline);
        this->tasks[index].setPriority(newPriority);
        return true;
    }

    bool deleteTask(string taskName)
    {
        int index = findTaskIndex(taskName);
        if (index == -1)
        {
            return false;
        }

        this->tasks.erase(this->tasks.begin() + index);
        return true;
    }

    bool markTaskAsCompleted(string taskName)
    {
        int index = findTaskIndex(taskName);
        if (index == -1)
        {
            return false;
        }

        this->tasks[index].markAsCompleted();
        return true;
    }

    void showTasks()
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
};

int main()
{
    Project project("Default Project");

    int choice = 0;
    do
    {
        cout << endl;
        cout << "1. Add task" << endl;
        cout << "2. Show all tasks" << endl;
        cout << "3. Update task" << endl;
        cout << "4. Delete task" << endl;
        cout << "5. Mark task as completed" << endl;
        cout << "6. Exit" << endl;
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
            cout << "Deadline: ";
            getline(cin, deadline);
            cout << "Priority: ";
            cin >> priority;
            cin.ignore();

            project.addTask(Task(name, deadline, priority, false));
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
            cout << "New deadline: ";
            getline(cin, newDeadline);
            cout << "New priority: ";
            cin >> newPriority;
            cin.ignore();

            if (project.updateTask(taskName, newName, newDeadline, newPriority))
            {
                cout << "Task updated." << endl;
            }
            else
            {
                cout << "Task not found." << endl;
            }
        }
        else if (choice == 4)
        {
            string taskName;
            cout << "Task name to delete: ";
            getline(cin, taskName);

            if (project.deleteTask(taskName))
            {
                cout << "Task deleted." << endl;
            }
            else
            {
                cout << "Task not found." << endl;
            }
        }
        else if (choice == 5)
        {
            string taskName;
            cout << "Task name to mark as completed: ";
            getline(cin, taskName);

            if (project.markTaskAsCompleted(taskName))
            {
                cout << "Task marked as completed." << endl;
            }
            else
            {
                cout << "Task not found." << endl;
            }
        }
    } while (choice != 6);

    return 0;
}