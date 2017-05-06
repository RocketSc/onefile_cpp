#include <iostream>

class SingleList
{
private:
    int value;
    SingleList* next;
    
    //private Copy constructor
    SingleList(const SingleList& list) {};
    
    bool deleteLast()
    {
        SingleList* current = this;
        SingleList* prev = 0;
        
        while(current->next != 0) {
            prev = current;
            current = current->next;
        }
        
        if (prev == 0) {
            return false;
        }
        
        std::cout << current->value << " deleted" << std::endl;
        
        delete current;
        prev->next = 0;
        
        return true;
    }
    
public:
    
    //constructor
    SingleList(int value)
    {
        this->value = value;
        this->next = 0;
    }
    
    //destructor
    ~SingleList()
    {
        while ( this->deleteLast() );
    }
    
    //adding value to the end of the list
    void addValue(int value)
    {
        SingleList* current = this;
        
        while(current->next != 0) {
            current = current->next;
        }
        
        current->next = new SingleList(value);
    }
    
    //get length of the list
    int length()
    {
        int counter = 0;
        
        for (SingleList* current = this; current != 0; current = current->next) {
            counter++;
        }
        
        return counter;
    }
};

int main()

{
    SingleList list(1);
    
    list.addValue(2);
    list.addValue(3);
    list.addValue(4);
    list.addValue(5);
    list.addValue(6);
    list.addValue(7);
    
    return 0;
}