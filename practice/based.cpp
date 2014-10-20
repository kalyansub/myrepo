/* Example program to motivate the need for a vaitrual desctructor in the Base class;
 * If you instantiate a base class object via a derived class pointer, the Derived class
 * destructor gets called, but the Base class destructor is never called! This can be
 * fixed by declaring the Base class desctructor as virtual. This is useful as the derived
 * class may need to do some clean up in it's own destructor before calling the Base class destructor.
 * $Author$: Kalyan Subramanian
 * $Date$: Sept 25, 2014
 * $Email$: kalyan dot sub at gmail dot com
 */

#include <iostream>

using std::cout;

class Base
{
    public:
        Base() { cout << "Base Constructor called...\n"; }
       /*virtual*/ ~Base() { cout << "Base Destructor called ...\n";}
};

class Derived: public Base
{
    public:
        Derived() { cout << "Derived Constructor called...\n"; }
        ~Derived() { cout << "*** Derived Descrutctor called ...\n";}
};

int main(int argc, char* argv[])
{
    Base* bObj = new Derived();
    
    delete bObj;

    return 0;
}
