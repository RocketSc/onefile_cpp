#include <string>
#include <iostream>

class S
{
    private:
        S() {}
        
    public:
        static S& getInstance()
        {
            static S instance;
            
            instance.i++;
            
            return instance;
        }
        
        int i = 0;
        
        S(S const&) = delete;
        void operator= (S const&) = delete;
};


int main()
{
    std::cout << S::getInstance().i << std::endl;
    std::cout << S::getInstance().i << std::endl;
    std::cout << S::getInstance().i << std::endl;
    std::cout << S::getInstance().i << std::endl;
    
    
    return 0;
}