#include <iostream>
#include <string>

using namespace std;

class TaskItem
{
private:
    string name;

public:
    TaskItem()
    {
        this->name = "Unknown";
    }

    virtual void display() = 0;

    string getName()
    {
        return this->name;
    }
    ~TaskItem();
};

class Task : TaskItem
{
private:
    string deadline;
    int priority;
    bool isCompleted;

public:
    Task(){
        this->deadline="";
        this->priority=0;
        this->isCompleted=false;
    }
    Task(string d,int p,bool c){
        this->deadline=d;
        this->priority=p;
        this->isCompleted=c;
    }
    ~Task();
};

int main()
{
    std::string input;

    std::cout << "Enter something: ";
    std::getline(std::cin, input);

    std::cout << "You entered: " << input << std::endl;

    return 0;
}