#include <iostream>

using namespace std;

void f();
void g();
void (*pf)();

int main(int argc, char ** argv)
{
    int c;
    cin >> c;
    if (c < 5) {
        pf = &f;
    } else {
        pf = &g;
    }
    
    pf();
    return 0;
}

void f()
{
    cout << "I am f" << endl;
}

void g()
{
    cout << "I am g" << endl;
}