// Thread Safe Singleton class.
#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
using namespace std;

// Singleton Class implementation.
class Singleton
{
    static atomic<Singleton*> m_atSingleton;	// Atomic for thread safe.
    static int iNmbrOfElements;					// To make sure only 1 object exists.
    static mutex mtx;							// Thread safe operations to Create Singleton object 
public:
    Singleton() = default;						// Default constructor.
    Singleton(Singleton&) = delete;				// Delete copy constructor
    Singleton& operator=(Singleton&) = delete;	// Delete assignement operator.

    static Singleton* getInstance()				// Static method to create & return created object.
    {
        lock_guard<mutex> mt(mtx);				// lock these operations for thread safe.
        Singleton* st = m_atSingleton.load();	// Aquire memory.
        if (st == nullptr)						// If Singleton object not create create it
        {
            iNmbrOfElements++;					// Increment the object count (it should be 1 always).
            st = new Singleton();				// Actual creation of Singleton object.
        }
        m_atSingleton.store(st);				// Store the Singleton object.
        return m_atSingleton;					// Return the Atomic Singleton object.
    }
    int Print() { return iNmbrOfElements; }		// Get the count of objects created (should be 1)
};

int Singleton::iNmbrOfElements = 0;				// Instatiate static variable.
atomic<Singleton*> Singleton::m_atSingleton;	// Instatiate static atomic variable.
mutex Singleton::mtx;							// Instatiate static mutex variable.

int singletonTest()
{
    {
        Singleton* st1 = Singleton::getInstance();	// Get the instatce of the Singleton object.
        cout << st1->Print() << endl;				// Print the object count.
        Singleton* st2 = Singleton::getInstance();	// Get the instatce of the Singleton object - Try to create next object.
        cout << st2->Print() << endl;				// Print the object count, it should be 1.
    }
    return 0;
}

int main()
{
    singletonTest();
    return 0;
}