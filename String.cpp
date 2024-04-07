// String class implementation 
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// New String class.
class String {
    char* cPtr;         // Char pointer to store data.
public:
    String() : cPtr(nullptr) {};   // Default constructor.
    String(const char* ch) : cPtr(new char[strlen(ch) + 1]) { strcpy(cPtr, ch); }    // Patameter constructor to store data.
    String(String& st)      // Copy constructor to copy the data from one object to this object.
    {
        this->cPtr = new char[strlen(st.cPtr) + 1];
        strcpy(this->cPtr, st.cPtr);
    }
    friend ostream& operator<<(ostream& os, const String& st)   // Operator to display data.
    {
        os << st.cPtr << ends;
        return os;
    }
    ~String() { if (cPtr != nullptr) delete[] cPtr; cPtr = nullptr; }   // Destructor to clear data.
    String& operator=(String& st)   // Assignment operator to assign this object with existing other object.
    {
        if (this->cPtr == nullptr) { delete[] this->cPtr; this->cPtr = nullptr; }
        this->cPtr = new char[strlen(st.cPtr) + 1];
        strcpy(this->cPtr, st.cPtr);
        return *this;
    }

    String& operator+=(const String& st)    // Append new string to
    {
        char* cTemp = nullptr;
        if (this->cPtr != nullptr)
        {
            cTemp = new char[strlen(this->cPtr) + strlen(st.cPtr) + 1];
            strcpy(cTemp, this->cPtr);
            strcat(cTemp, st.cPtr);
            delete[] this->cPtr; this->cPtr = nullptr;
        }
        else
        {
            cTemp = new char[strlen(st.cPtr) + 1];
            strcpy(cTemp, st.cPtr);
        }
        this->cPtr = new char[strlen(cTemp) + 1];
        strcpy(this->cPtr, cTemp);
        delete[] cTemp, cTemp = nullptr;
        return *this;
    }

    class iterator {
        char* ptr;
    public:
        iterator(char* pd) : ptr(pd) {};        // Store add ress of the element;
        // Overload operators == or != for iterator movements
        friend bool operator==(const iterator& it1, const iterator& it2) { return strcmp(it1.ptr, it2.ptr); }
        friend bool operator!=(const iterator& it1, const iterator& it2) { return strcmp(it1.ptr, it2.ptr); }

        // Overload prefix operator ++ to move forward.
        iterator& operator++()
        {
            ++ptr;
            return *this;
        }
        // Overload postfix operator ++ to move forward
        iterator& operator++(int)
        {
            iterator* temp = this;
            ++(*this);
            return *temp;
        }
        // Overload operator * to provide actual value at the address
        char& operator*() { return *this->ptr; }
        friend iterator operator+(const iterator& it, int iPos) { return iterator(it.ptr + iPos); }
        friend iterator operator-(const iterator& it, int iPos) { return iterator(it.ptr - iPos); }
    };

    // Get the begining of the character data memory loation.
    iterator begin() { return iterator(&this->cPtr[0]); }
    // Get the end of the character data memory loation.
    iterator end() { return iterator(&this->cPtr[strlen(cPtr)]); }
};

int Strings()
{
    String str1;    // Declare obect - uses default constror.
    String str2("I am a new String class.");  // Declare object with data - use of Patameterized constror.
    cout << "str2: " << str2 << endl;       // Uses overloaded operator (<<) to print str2.

    String str3 = str2; // Copy data from str2 into str1 using copy constructor.
    cout << "str3: " << str2 << endl;

    str1 = str3;        // Assign data from str3 to str1 using assignment operator.
    cout << "str1: " << str1 << endl;

    str1 += " Appending more data to String object.";
    cout << "str1: " << str1 << endl;

    // Display String data using iterator
    String::iterator it1 = str1.begin();
    String::iterator it2 = str1.end();

    // Print data using iterator with Prefix ++ increment.
    for (it1; it1 != it2; ++it1) { cout << *it1 << " "; }
    cout << endl;

    it1 = str1.begin();
    // Print data using iterator with Postfix ++ increment.
    for (it1; it1 != it2; it1++) { cout << *it1 << " "; }
    cout << endl;

    // Print data certain length;
    it1 = str1.begin();
    it2 = str1.begin() + 10;   // 10 characters to be printed
    for (it1; it1 != it2; ++it1) { cout << *it1 << " "; }
    cout << endl;

    // Print data until the position from end.
    it1 = str1.begin();
    it2 = str1.end() - 10;   // 10 characters to be printed
    for (it1; it1 != it2; ++it1) { cout << *it1 << " "; }
    cout << endl;

    return 0;
}

int main()
{
	Strings();
	return 0;
}