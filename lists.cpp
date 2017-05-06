#include <iostream>

class SingleList
{
private:
    int value;
    
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

protected:
    SingleList* next;

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
    virtual void addValue(int value)
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
}; //end of SingleList class

class DoubleList: public SingleList
{
private:
    SingleList* prev;
    
public:
    DoubleList(int value) : SingleList(value)
    {
        prev = 0;
    }
    
    void addValue(int value)
    {
        DoubleList* current = this;
        while(current->next != 0) {
            current = (DoubleList*) current->next;
        }
        
        current->next = new DoubleList(value);
        ((DoubleList*) current->next)->prev = current;
    }
};

int main()

{
    DoubleList list(1);
    
    list.addValue(2);
    list.addValue(3);
    list.addValue(4);
    list.addValue(5);
    list.addValue(6);
    list.addValue(7);
    
    return 0;
}