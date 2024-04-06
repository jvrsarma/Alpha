//Vector
#include<iostream>
#include<initializer_list>
using namespace std;

// Template class for Vector.
template<class T>
class Vector
{
    T* Ptr;         // Store data
    int capacity;   // Actual capacity of Vector
    int size;       // Size of Vector - eleents entered.

    // Reallocate / Resize memory for data.
    void Reallocate() {
        capacity = capacity + 10;
        T* temp = new T[size];
        for (int i = 0; i < size; i++) temp[i] = Ptr[i];    // Store existing data into temporary location.
        delete[] Ptr;
        Ptr = new T[capacity];                              // Resize with more memory space.
        for (int i = 0; i < size; i++) Ptr[i] = temp[i];    // Restore existing data after resize.
    }
public:
    Vector(int cap = 10) : Ptr(new T[capacity = cap]) {}    // Allocate memory
    Vector(initializer_list<T> v) {                         // Insert data using Initializer list.
        for (auto i : v) {
            this->Insert(i);
        }
    }
    void Insert(T val) {                                    // Insert element by element.
        if (size >= capacity)
            Reallocate();
        Ptr[size++] = val; cout << Ptr[size - 1] << "  ";
    }

    // Print Vector
    void Print() { for (int i = 0; i < size; i++) cout << Ptr[i] << "  "; } 

    // Remove elements from Vector.
    void Remove() { cout << "Removing Vector elements: " << endl; delete[] Ptr; Ptr = nullptr; }

    // Iterator class.
    class iterator {
        T* ptr;
    public:
        iterator(T* p_) : ptr(p_) {}            // Store the elements address for progress.
        T& operator*() { return *this->ptr; }   // Overload operator* to get actual value.

        // Operators == and != overloaded to compare while in move.
        friend bool operator==(const iterator& itl, const iterator& itr) { return itl.ptr == itr.ptr; }
        friend bool operator!=(const iterator& itl, const iterator& itr) { return itl.ptr != itr.ptr; }

        // Operator ++ overladed (Prefix) to get next value
        iterator operator++()
        {
            ++ptr;
            return *this;
        }
        // Operator ++(int) overloaded (Postfix) to get next value
        iterator operator++(int)
        {
            iterator* temp = this;
            ++(*this);
            return *temp;
        }
        // Operator -- overladed (Prefix) to get previous value
        iterator operator--()
        {
            --ptr;
            return *this;
        }
        // Operator --(int) overloaded (Postfix) to get previous value
        iterator operator--(int)
        {
            iterator* temp = this;
            --(*this);
            return *temp;
        }
        // Overload operator + to get forward distance from the given position
        friend iterator operator+(const iterator& it, int i) { return iterator(it.ptr + i); }
        // Overload operator - to get backward distance from the given position
        friend iterator operator-(const iterator& it, int i) { return iterator(it.ptr - i); }
    };
    iterator begin()  { return iterator(&this->Ptr[0])       ; }    // Get the begining of the iterator
    iterator end()    { return iterator(&this->Ptr[size])    ; }    // Get the end of the iterator
    iterator rbegin() { return iterator(&this->Ptr[size - 1]); }    // Get the begining of the iterator from end.
    iterator rend()   { return iterator(&this->Ptr[-1])      ; }    // Get the end of the iterator from end.
};

// To use at multiple places typedef to common name.
typedef int TT;
// typedef char TT;
// typedef string TT;

int Vectors()
{
    Vector<TT> vt; // Create Vector object with default constructor.

    cout << "Inserting Elements: " << endl;
    for (int i = 0; i < 20; i++)
        vt.Insert(i * 10);

    cout << endl;
    cout << "Printing Vector: " << endl;

    vt.Print();
    cout << endl;

    cout << "Printing Vector elements using Prefix iterator: " << endl;
    Vector<TT>::iterator it1 = vt.begin();
    Vector<TT>::iterator it2 = vt.end();
    for (it1; it1 != it2; ++it1) cout << *it1 << "  ";
    cout << endl;

    cout << "Printing Vector elements using Postfix iterator: " << endl;
    it1 = vt.begin();
    for (it1; it1 != it2; it1++) cout << *it1 << "  ";
    cout << endl;

    Vector<TT>::iterator it3 = vt.rbegin();
    Vector<TT>::iterator it4 = vt.rend();
    cout << "Reverse Printing Vector elements using Prefix iterator: " << endl;
    for (it3; it3 != it4; --it3) cout << *it3 << "  ";
    cout << endl;

    cout << "Reverse Printing Vector elements using Postfix iterator: " << endl;
    it3 = vt.rbegin();
    for (it3; it3 != it4; it3--) cout << *it3 << "  ";
    cout << endl;

    it1 = vt.begin();

    Vector<TT>::iterator it5 = it1 + 5;    // Get iterator at 5th position from begining
    Vector<TT>::iterator it6 = it2 - 10;   // Get iterator at 10th position from begining

    cout << "Printing data using iterator (Postfix) and distance: " << endl;
    for (it1; it1 != it5; it1++) { cout << *it1 << "  "; }
    cout << endl;

    cout << "Printing data using iterator (Postfix) with distance: " << endl;
    it1 = vt.begin();
    for (it1; it1 != it6; it1++) { cout << *it1 << "  "; }
    cout << endl;

    vt.Remove();
    cout << endl;

    Vector<TT> vt1 = { 1,2,3,4,5 }; // Create Vector object with initializer list constructor.
    cout << endl;
    cout << "Printing initializer list elements: " << endl;
    vt1.Print();
    cout << endl;

    vt1.Remove();
    cout << endl;

    return 0;
}

int main()
{
    Vectors();
    return 0;
}