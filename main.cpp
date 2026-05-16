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

int main()
{
    std::string input;

    std::cout << "Enter something: ";
    std::getline(std::cin, input);

    std::cout << "You entered: " << input << std::endl;

    return 0;
}