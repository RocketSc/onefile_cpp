#include <iostream>

class Object
{
private:
    int i;
    
public:
    //contstructors
    Object(int i)
    {
        this->i = i;
    }
    
    Object()
    {
        this->i = 42;
    }
    
    //destructor
    ~Object()
    {
        std::cout << "Goodbye" << std::endl;
    }
    
    //getters and setters
    void set(int i)
    {
        this->i = i;
    }
    
    int get()
    {
        return this->i;
    }
};

class ScopedPointer
{
private:
    //contained object
    Object * pObject;
    
    //private copy constructor
    ScopedPointer(const ScopedPointer& p) {}
    
    //private assingment operator
    ScopedPointer& operator= (const ScopedPointer p) {}
    
public:
    //constructor - storing object inside container
    ScopedPointer(Object * pObject)
    {
        this->pObject = pObject;
    }
    
    //destructor - delete contained object
    ~ScopedPointer()
    {
        if (this->pObject) {
            delete this->pObject;
        }
    }
    
    //reference to contained object
    Object * ptr()
    {
        return this->pObject;
    }
    
};




int main()
{
    {
        ScopedPointer container( new Object() );
        std::cout << container.ptr()->get() << std::endl;
    }
    
    {
        ScopedPointer container( new Object(5) );
        std::cout << container.ptr()->get() << std::endl;
    }
    
    {
        ScopedPointer container( new Object(1) );
        std::cout << container.ptr()->get() << std::endl;
        
        container.ptr()->set(3);
        std::cout << container.ptr()->get() << std::endl;
    }
    return 0;
}