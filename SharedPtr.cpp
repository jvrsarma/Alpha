// SharedPtr
#include<iostream>
using namespace std;

template <typename T>
class SharedPtr {
	T *Ptr;
	uint *useCount;
public:
	SharedPtr() : Ptr(nullptr), useCount(nullptr) 	{}   // default constructor
	SharedPtr(T* ptr_) : Ptr(ptr_), useCount(new uint(1)) {}    //  constructor

	SharedPtr(const SharedPtr& sp) {					// Copy constructor
		this->Ptr = sp.Ptr;
		this->useCount = sp.useCount;

		if (nullptr != this->Ptr) { (*this->useCount)++;}
	}

	SharedPtr& operator=(const SharedPtr& sp) {     // Assignment operator
		this->Ptr = sp.Ptr;
		this->useCount = sp.useCount;

		if (nullptr != sp.Ptr) { (*this->useCount)++; }
		return *this;
	}
	
	SharedPtr(SharedPtr&& sp) = delete;					// Move copy constructor -- move semantics.
	SharedPtr& operator=(SharedPtr&& sp) = delete;		// Move assignement operator -- move semantics.

	T* operator->() { return this->Ptr; }
	T& operator*()  { return *this->Ptr; }
	bool operator==(T* ptr_) { return this->Ptr == ptr_; }
	bool operator!=(T* ptr_) { return this->Ptr != ptr_; }

	uint get()
	{
		return *useCount;
	}

	~SharedPtr() {										// Destructor to destroy pointer when there is no reference found.
	    cout <<*useCount << " " << *Ptr << endl;
		if (--(*useCount) == 0) {
			if (Ptr)
				delete Ptr;
			delete useCount;
		}
	}

};
int sharedptrTest()
{
    SharedPtr<int> sp1(new int(122));
    cout << sp1.get() << " " << *sp1 << endl;
    
    SharedPtr<int> sp2 = sp1;
    cout << sp2.get() << " " << *sp2 << endl;
    
    SharedPtr<int> sp3 = sp2;
    cout << sp3.get() << " " << *sp3 << endl;
    
    SharedPtr<int> sp4;
    sp4 = sp1;
    cout << sp4.get() << " " << *sp4 << endl;

    cout << endl;

    return 0;
}
int main()
{
    sharedptrTest();
    return 0;
}