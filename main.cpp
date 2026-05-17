#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

string normalizeDate(const string &input)
{
    if (input.empty())
        return string();

    int y, m, d;
    char sep1, sep2;
    istringstream iss(input);
    if (!(iss >> y >> sep1 >> m >> sep2 >> d))
        return string();
    if (sep1 != '-' || sep2 != '-')
        return string();
    if (y < 0 || m < 1 || m > 12 || d < 1)
        return string();

    int mdays = 31;
    if (m == 2)
    {
        bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        mdays = leap ? 29 : 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        mdays = 30;

    if (d > mdays)
        return string();

    ostringstream out;
    out << setw(4) << setfill('0') << y << '-' << setw(2) << setfill('0') << m << '-' << setw(2) << setfill('0') << d;
    return out.str();
}

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

    void showUncompletedTasks()
    {
        if (this->tasks.empty())
        {
            cout << "No tasks in project '" << this->name << "'." << endl;
            return;
        }

        for (int i = 0; i < (int)this->tasks.size(); i++)
        {
            if (tasks[i].getCompleted() == false)
            {
                cout << "--------------------" << endl;
                this->tasks[i].display();
            }
            
        }
    }
       void showCompletedTasks()
    {
        if (this->tasks.empty())
        {
            cout << "No tasks in project '" << this->name << "'." << endl;
            return;
        }

        for (int i = 0; i < (int)this->tasks.size(); i++)
        {
            if (tasks[i].getCompleted() == true)
            {
                cout << "--------------------" << endl;
                this->tasks[i].display();
            }
            
        }
    }
    void sortTasksByPriority(){
        if (this->tasks.empty())
        {
            cout << "No tasks in project '" << this->name << "'." << endl;
            return;
        }
        for (int i = 0; i < (int)this->tasks.size(); i++)
        {
            for (int j = i+1; j < (int)this->tasks.size(); j++)
            {
                if (this->tasks[i].getPriority()>this->tasks[j].getPriority())
                {
                    Task t=this->tasks[i];
                    this->tasks[i]=this->tasks[j];
                    this->tasks[j]=t;
                }
                
            }
            
        }
        cout<<"Tasks sorted successfully!"<<endl;
        showTasks();
        
        
    }
};

string readDeadlineSimple(const string &prompt)
{
    string s;
    while (true)
    {
        cout << prompt;
        if (!getline(cin, s))
            return string();
        string norm = normalizeDate(s);
        if (!norm.empty())
            return norm;
        cout << "Invalid date. Please enter in YYYY-MM-DD (e.g. 2026-05-10)." << endl;
    }
}

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
        cout << "6. Filter Uncompleted Tasks" << endl;
        cout << "7. Filter Completed Tasks" << endl;
        cout << "8. Sort tasks by priority" << endl;
        cout << ". Exit" << endl;

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
            deadline = readDeadlineSimple("Deadline (YYYY-MM-DD format): ");
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
            newDeadline = readDeadlineSimple("New deadline (YYYY-MM-DD format): ");
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
        else
        {
            return 0;
        }
    } while (1);

    return 0;
}