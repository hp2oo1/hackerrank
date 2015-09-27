/*
Bomb class throwing the exception in the desctructor.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

#include <cstdlib>

class Bomb { // bad class throws exception from destructor
    string name;
public:
     Bomb(string s) : name(s) {cout <<"constructor called for " << name << endl;}
    ~Bomb() {cout <<"destructor called for " << name << endl;}
    
    // new is by default a static member. The "throw()" promises not to
    // throw exceptions from this method
    void * operator new(size_t n) throw()
    {
      cout <<"operator new called\n";
        return malloc(n);
    }
    
    //by default a static member
    void operator delete(void *p) throw()
    {
      cout << "operator delete called\n"; // never gets here
      if (p != 0) 
         free(p);
    }
    
    //
    void close() {
        throw "boom";
        delete this;
    }
    
    //
    string getName() {
        return name;
    }
};

class BombWrapper {
    Bomb* bomb;
    bool closed;
public:
     BombWrapper(string s) : bomb(new Bomb(s)), closed(false) {
         //cout <<"wrapper constructor called for " << bomb.getName() << endl;
     }
    ~BombWrapper() {
        //cout <<"wrapper destructor called for " << bomb->getName() << endl;
        if(!closed) {
            try {
                bomb->close();
            }
            catch (...) {
                cout <<"caught exception from destructor\n";
                delete bomb;
            }
        }
    }
    
    //
    void close() {
        bomb->close();
        closed = true;
    }
};

void f() {
    BombWrapper Bomb1("Bomb1");
//*    
    BombWrapper *pBomb = new BombWrapper("Bomb2");
    try {
        delete pBomb;
    } catch (...) {
        // Gets here but leaks storage.  Print output shows that
        // operator new was called but operator delete was not.
      cout <<"caught exception from destructor\n";
    }
//*/    
    // program dies here: can't throw two exceptions
    // at the same time, so terminates
    //throw "no boom"; // program dies here
}

int main()
{
    try {
        f();
    } catch (char *message) {
      cout << "f threw " << message << endl; // never gets here
    }
}
