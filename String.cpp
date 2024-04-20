// String class implementation 
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// New String class.
class String
{
        char* cPtr;             // Char pointer to store data.
        int capacity;           // Capacity required to store data character by character.
        void reallocate()       // Resize the cPtr (character storgate) variable to store data character by character.
        {
            char *cTemp = nullptr;      // Temporary storage location before resize cPtr.
            if (this->cPtr != nullptr)  // If cPtr has data 
            {
                cTemp = new char[strlen(this->cPtr)+1];     // Allocate the same size of memeory as cPtr 
                strcpy(cTemp, this->cPtr);                  // Copy cPtr data into temporary cTemp location.
                delete[] this->cPtr; this->cPtr = nullptr;  // Delete cPtr.
            }
            this->cPtr = new char[capacity];    // Now resize cPtr to new extnded size.
            strcpy(this->cPtr, cTemp );         // Copy the old data back to cPtr.
        }
    public:
        String() : cPtr(nullptr), capacity(0) {}        // Default constructor to create an empty object and initialize cPtr and capacity.
        String(const char* cDat) : cPtr(new char[strlen(cDat) + 1]), capacity(0)  { strcpy(this->cPtr, cDat); }  // Construct object during declaration with data.
        ~String() { if (cPtr != nullptr) delete[] cPtr; cPtr = nullptr; } // Destructor to deallocate memory allocated to cPtr
        friend ostream& operator<<(ostream& os, const String& str)  // Overloading operator << to print object.
        {
            os << str.cPtr<< ends;      // Redirect cPtr into ostream object and 
            return os;                  // return the ostream object.
        }
        String(String& str)         // Copy constructor to initialize this object with the existing object.
        {
            this->cPtr = new char[strlen(str.cPtr) + 1];
            strcpy(this->cPtr, str.cPtr);
        }
        String& operator=(String& str)  // Assignment operator to transfer data from another object into this object.
        {
            if (this->cPtr != nullptr) delete[] this->cPtr; // First clear the existing data (if any) by deallocating the memory
            this->cPtr = new char[strlen(str.cPtr)+1];      // Allocate the memory for cPtr with the same size as other object's cPtr.
            strcpy(this->cPtr, str.cPtr);                   // Copy the other object's cPtr data into this cPtr.
            return *this;                                   // Return the current object.
        }
        String& operator+=(const char* cDat)                // Overloading += operator to append this object with supplied characters data. 
        {
            char* cTemp = nullptr;      // Declare a Temp pointer variable
            if (this->cPtr != nullptr)  // If cPtr has data
            {
                cTemp = new char[strlen(this->cPtr) +  strlen(cDat) + 1];   // Then allocate equivalent memory size to a temporary variable with the total size of cPtr+cDat
                strcpy(cTemp, this->cPtr);          // Copy the cPtr's data into temporary memory cTemp
                strcat(cTemp, cDat);                // Concatenate the cDat (new data) to the temporary (cTemp) variable.
                delete[] this->cPtr; this->cPtr = nullptr;  // deallocate cPtr's memory with delete operator.
            } else          // If this cPtr is empty
            {
                cTemp = new char[strlen(cDat) + 1];     // Allocate equal memory size to a temporary variable with the size of cDat
                strcpy(cTemp, cDat);                    // Copy the cDat (new data) to the temporary (cTemp) variable.
            }
            this->cPtr = new char[strlen(cTemp) + 1];   // Now reallocate memory for this cPtr same as temporary (cTemp) variable.
            strcpy(this->cPtr, cTemp);                  // Copy the data from temporary (cTemp) memory into this cPtr.
            delete[] cTemp; cTemp = nullptr;            // Deallocate temporary memory
            return *this;                               // Return this.
        }
        
        String& operator+=(const char ch)               // Overloade operator += to sore character by character.
        {
            if (this->capacity < strlen(this->cPtr) + 1)    // If the capacity of cPtr is less than data stored (length of cPtr)
            {
                this->capacity = strlen(this->cPtr) + 10;   // increase the capacity by 10.
                reallocate();                               // and resize the cPtr's memory.
            }
            
            if (this->cPtr != nullptr)          // If the reallocation / resize is succssful
            {
                this->cPtr[strlen(this->cPtr)]=ch;  // Then store the character.
            }
            return *this;                       // Return the updated this object.
        }
        
        // Iterator
        class Iterator 
        {
                char* ptr;      // Local pointer object to hold the address of the memory location.
            public:
                Iterator(char* p) : ptr(p) {}   // Store address of the element
                Iterator operator++()           // Overload prefix operator ++ to move forward.
                {
                    ++ptr;                      // Advance the address by one whenever operator ++ is called.
                    return *this;               // Return this iterator object after increment.
                }
                // Overload postfix operator ++ to move forward
                Iterator& operator++(int)
                {
                    Iterator* temp = this;  // Copy this iterator to temporary iterator to hold status before the change.
                    ++(*this);              // Increment this iterator
                    return *temp;           // Return the old iterator data.
                }
                char& operator*() { return *this->ptr; }    // Overload operator * to retrieve the value of the current memory pointed by this iterator object.
                // Overload operators == or != for iterator movements
                friend bool operator==(const Iterator& it1, const Iterator& it2) { return it1.ptr == it2.ptr; }
                friend bool operator!=(const Iterator& it1, const Iterator& it2) { return it1.ptr != it2.ptr; }
                friend const Iterator operator+(const Iterator& it, int length) // Overload operator + to get the distance of the Iterator position from the pointing position.
                {
                    char* ptr1 = it.ptr+length;
                    return Iterator(&ptr1[0]);  // return the distnace Iterator.
                }
        };
        Iterator begin() { return Iterator(&this->cPtr[0]); }       // Get the beginning of the Iterator.
        Iterator end()   { return Iterator(&this->cPtr[strlen(this->cPtr)]); }  // Get the end of the Iterator.
        String Substr(int start, int noofchars) // Get the sub-string of the string.
        {
            char str[noofchars+1] = {" "};
            int index = 0;
            while(index < noofchars)
            {
                str[index] = cPtr[start+index-1];
                index++;
            }
            
            return String(str);
        }
};

int StringTest()
{
    String str1;
    String str2("I am a new and simple String class.");
    cout << "str2: " << str2 << endl;
    String str3(str2);
    cout << "str3: " << str3 << endl;
    str1 = str3;
    cout <<"str1: "<< str1 << endl;
    str1 += " Appending new string.";
    cout << "str1: " << str1 << endl;
    
    cout <<"Display String data with Iterator: " << endl;
    String::Iterator it1 = str1.begin();
    String::Iterator it2 = str1.end();
    
    for(it1; it1 != it2; ++it1) {  cout << *it1 << " "; }
    cout << endl;

    it1 = str1.begin();
    it2 = str1.begin() + 16;
    for(it1; it1 != it2; ++it1) {  cout << *it1 << " "; }
    cout << endl;
    
    String str4 = str1.Substr(8,5);
    cout <<"str4: " << str4 << endl;
    
    return 0;
}
int main()
{
    StringTest();
    return 0;
}
