#include<iostream>
using namespace std;

class DLnkLst {
    int iVal;
    DLnkLst* Head;
    DLnkLst* Next;
    DLnkLst* Prev;
public:
    DLnkLst() : Head(nullptr), Next(nullptr), Prev(nullptr) {}

    // Insert the element 
    void Insert(int data) {
        if (Next == nullptr) { // Create first node to insert by allocating memory to the firt node
            Next = new DLnkLst();
            Next->Next = nullptr;
            Next->Prev = nullptr;
            Next->iVal = data;
            Head = Next;  // At beginning Head and Next will point to same node.
        }
        else {
            DLnkLst* Temp = new DLnkLst();  // Create Next node and so on, by creating temporary node and assinging to the Next->Next...
            Temp->Next = nullptr;
            Temp->Prev = Next;
            Temp->iVal = data;
            Next->Next = Temp;
            Next = Next->Next;  // Each time Next will advance to point to last created node.
        }
    }

    //Print list in Forward direction (Head to End/Tail/Rear)
    void PrintForward() {
        DLnkLst* Temp = Head;
        cout << "Printing Doubly Linked List Forward directioin." << endl;
        while (Temp != nullptr) {
            cout << Temp->iVal << " ";
            Temp = Temp->Next;
        }
        cout << endl;
    }

    //Print list in Backward direction (End/Tail/Rear to Head).
    void PrintReverse() {
        cout << "Printing Doubly Linked List in Reverse Order. " << endl;
        DLnkLst* Temp = Next;
        while (Temp != nullptr) {
            cout << Temp->iVal << " ";
            Temp = Temp->Prev;
        }
        cout << endl;
    }

    // Insert element from the start of Doubly Linked List.
    void InsertAtFPos(int fPos, int data) {
        DLnkLst* Temp = Head;

        // Run through the list till we reach the position to insert the element.
        while (--fPos > 0 && Temp != nullptr) {
            Temp = Temp->Next;
        }

        // Check the position is within the boundary, if not exit.
        if (Temp == nullptr && fPos > 0) { cout << "Position provided is greater than Doubly Linked List." << endl; return; }

        // Store the links
        DLnkLst* PosL = Temp->Prev;
        DLnkLst* PosR = Temp->Prev->Next;

        // Create a temporary link
        DLnkLst* T1 = new DLnkLst();
        T1->iVal = data;
        T1->Prev = PosL;
        T1->Next = PosR;

        // Insert the temporary link to comlete the insertion.
        PosL->Next = T1;
        PosR->Prev = T1;
    }

    // Insert element from the end of Doubly Linked List.
    void InsertAtRPos(int bPos, int data) {
        DLnkLst* Temp = Next;

        // Run through the list till we reach the position to insert the element.
        while (--bPos > 0 && Temp != nullptr) {
            Temp = Temp->Prev;
        }

        // Check the position is within the boundary, if not exit.
        if (Temp == nullptr && bPos > 0) { cout << "Position provided is greater than Doubly Linked List." << endl; return; }

        // Store the links
        DLnkLst* PosL = Temp;
        DLnkLst* PosR = Temp->Next;

        // Create a temporary link
        DLnkLst* T1 = new DLnkLst();
        T1->iVal = data;
        T1->Prev = PosL;
        T1->Next = PosR;

        // Insert the temporary link to comlete the insertion.
        PosL->Next = T1;
        PosR->Prev = T1;
    }

    // Remove entire Doubly linked list.
    void RemoveLnkLst() {
        cout << " Deleting all elements from Doubly Linked List: " << endl;
        while (Head != nullptr) {
            DLnkLst* Temp = Head;
            Head = Head->Next;
            cout << Temp->iVal << " ";
            delete Temp; Temp = nullptr;
        }
        Head = Next = Prev = nullptr;
    }

    // Remove node at Nth position from the begining.
    void RemoveNthElementFromStart(int fPos1) {
        DLnkLst* Temp = Head;

        // Run through the list till we reach the position to insert the element.
        while (--fPos1 > 0 && Temp != nullptr) {
            Temp = Temp->Next;
        }

        // Check the position is within the boundary, if not exit.
        if (Temp == nullptr && fPos1 > 0) { cout << "Position provided is greater than Doubly Linked List." << endl; return; }

        // Store the links
        DLnkLst* T = Temp;
        DLnkLst* PosL = Temp->Prev;
        DLnkLst* PosR = Temp->Next;
        Temp = Temp->Next;

        //Now remove the link
        delete T; T = nullptr;

        // Rejoin the links after deletion.
        PosL->Next = PosR;
        Temp->Prev = PosL;
        PrintForward();
    }

    // Remove node at Nth position from the end.
    void RemoveNthElementFromEnd(int bPos1) {
        DLnkLst* Temp = Next;

        // Run through the list till we reach the position to delete the element.
        while (--bPos1 > 0 && Temp != nullptr) {
            Temp = Temp->Prev;
        }

        // Check the position is within the boundary, if not exit.
        if (Temp == nullptr && bPos1 > 0) { cout << "Position provided is greater than Doubly Linked List." << endl; return; }

        // Store the links
        DLnkLst* T = Temp;
        DLnkLst* PosL = Temp->Prev;
        DLnkLst* PosR = Temp->Next;

        // Now remove the link
        Temp = Temp->Next;
        delete T; T = nullptr;

        // Rejoin the links after deletion.
        PosL->Next = PosR;
        Temp->Prev = PosL;
        PrintReverse();
    }


};

int DoublyLinkedList(int lstsize) {
    DLnkLst dl;

    for (int i = 0; i < lstsize; i++) {
        dl.Insert(i * 5);
    }
    dl.PrintForward();
    dl.PrintReverse();
    cout << endl;

    int fPos1 = 10; int elem1 = 5500;
    cout << "Inserting element " << elem1 << " at " << fPos1 << "th position from the start : " << endl;
    dl.InsertAtFPos(fPos1, elem1);
    cout << "Priting list forward direction after inserting element " << elem1 << " at " << fPos1 << "th position from the start: " << endl;
    dl.PrintForward();
    cout << "Priting list backword direction after inserting element " << elem1 << " at " << fPos1 << "th position from the start : " << endl; 
    dl.PrintReverse();
    cout << endl;

    int bPos1 = 20; int elem2 = 5600;
    cout << "Inserting element " << elem2 << " at " << bPos1 << "th position from the end: " << endl;
    dl.InsertAtRPos(bPos1, elem2);
    cout << "Priting list forward direction after inserting element " << elem2 << " at " << bPos1 << "th position from the end: " << endl;
    dl.PrintForward();
    cout << "Priting list backword direction after inserting element " << elem2 << " at " << bPos1 << "th position from the end: " << endl;
    dl.PrintReverse();
    cout << endl;

    fPos1 = 8;
    cout << "Delete an element at " << fPos1 << " from the begining/start. " << endl;
    dl.RemoveNthElementFromStart(fPos1);
    cout << endl;

    bPos1 = 3;
    cout << "Delete an element at: " << bPos1 << " from the end." << endl;
    dl.RemoveNthElementFromEnd(bPos1);
    cout << endl;

    dl.RemoveLnkLst();

    return 0;
}

int main()
{
    DoublyLinkedList(30);
    return 0;
}