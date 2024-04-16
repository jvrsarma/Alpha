// Doubly Linked List
#include<iostream>
using namespace std;

class DblLnkLst
{
        DblLnkLst* Head;
        DblLnkLst* Next;
        DblLnkLst* Prev;
        int        iVal;
    public:
        DblLnkLst(int ival = 0) : Head(nullptr), Next(nullptr), Prev(nullptr), iVal(ival) {}

		// Insert the element 
        void Insert(int ival)
        {
            if (Next == nullptr)	// Create first node to insert by allocating memory to the firt node
            {
                Next = new DblLnkLst(ival);
                Next->Next = nullptr;
                Next->Prev = nullptr;
                Head = Next;		// At the beginning, Head and Next will point to same node.
            } else
            {
                DblLnkLst* Temp = new DblLnkLst(ival);  // Create Next node and so on, by creating temporary node and assinging to the Next->Next...
                Temp->Next = nullptr;
                Temp->Prev = Next;
                Next->Next = Temp;
                Next = Next->Next;	// Each time Next will advance to point to last created node.
            }
            cout << Next->iVal << " ";
        }
        
		//Print list in Forward direction (Head/Start to End )
        void PrintForward()
        {
            cout <<"Printing Doubly Linked List Forward Direction (Head/Start to End)" << endl;
            DblLnkLst* Temp = Head;
            while(Temp != nullptr) 
            {
                cout << Temp->iVal << " " ;
                Temp = Temp->Next;
            }
            cout << endl;
        }
        
		//Print list in Backward direction (End to Start/Head).
        void PrintBckward()
        {
            cout <<"Printing Doubly Linked List Backward Direction (End to Start/Head)" << endl;
            DblLnkLst* Temp = Next;
            while(Temp != nullptr) 
            {
                cout << Temp->iVal << " " ;
                Temp = Temp->Prev;
            }
            cout << endl;
        }
        
		// Remove entire Doubly linked list from the start position.
        void Remove()
        {
            cout << "Removing elements from Head/Start to End from Doubly Linked List: " << endl;
            while(Head != nullptr)
            {
                DblLnkLst* Temp = Head;
                cout << Temp->iVal << " ";
                Head = Head->Next;
                delete Temp; Temp = nullptr;
            }
        }
        
		// Insert element at given position from the start of Doubly Linked List (Forward move and Insert).
        void InsertElementsAtFwdPos(int fPos, int data)
        {
            DblLnkLst* Temp = Head;

			// Run through the list till we reach the position to insert the element.
            while(--fPos > 0 && Temp != nullptr) { Temp = Temp->Next; }
            
			// Check whether the position is within the boundary, if not exit.
            if (fPos > 0 && Temp == nullptr) { cout << "Given position to insert is bigger than Doubly Linked List size, Exiting. " << endl; return; }
            
            DblLnkLst* T1 = new DblLnkLst(data);	// Create a New Node and assign data.
            T1->Next = Temp;						// New Node's next should point to current node.
            Temp->Prev->Next = T1;					// Attach the New node to the current node.
            T1->Prev = Temp->Prev;					// New Node's previous should point to current Node's previous node.
            Temp->Prev = T1;						// Finally current node's previous should point to New node.
        }

		// Insert element at a given position from the end of Doubly Linked List (Reverse move and Insert).
        void InsertElementsAtBwdPos(int bPos, int data)
        {
            DblLnkLst* Temp = Next;
            while(--bPos > 0 && Temp != nullptr) { Temp = Temp->Prev; }
            
            if (bPos > 0 && Temp == nullptr) { cout << "Given position to insert is bigger than Doubly Linked List size, Exiting. " << endl; return; }
            
            DblLnkLst* T1 = new DblLnkLst(data);	// Create a New Node and assign data.
            T1->Prev = Temp;                    	// New Node's prev should point to current node.
            Temp->Next->Prev = T1;              	// Attach the New node to the current node.
            T1->Next = Temp->Next;              	// New Node's next should point to current Node's Next node.
            Temp->Next = T1;                    	// Finally current node's next should point to New node.
        }
		
		// Remove node at Nth position from the begining.
	        void RemoveNthElementFromStart(int N)
        {
            cout <<"Removing " << N << "th element from the beginning. " << endl;
            DblLnkLst* Temp = Head;

			// Run through the list till we reach the position to insert the element.
            while(--N > 0 && Temp != nullptr) { Temp = Temp->Next; }
            
			// Check the position is within the boundary, if not exit.
            if (Temp == nullptr && N > 0) { cout << "Provided position is greater than the size of DoublyLinkedList, Exiting. " << endl; return; }
            
            DblLnkLst* T1 = Temp;					// Back-up the current node (which should be deleted) to keep the links
            
            Temp->Prev->Next=Temp->Next;			// Current node's previous node's next should point to current node's next.
            Temp->Next->Prev = T1->Prev;			// Current node's next node's previous should point to curren node's previous.
            delete T1; T1 = nullptr;				// After linking delete the current link node.
        }

		// Remove node at Nth position from the end.
        void RemoveNthElementFromEnd(int N)
        {
            cout <<"Removing " << N << "th element from the beginning. " << endl;
            DblLnkLst* Temp = Next;

			// Run through the list till we reach the position to insert the element.
            while(--N > 0 && Temp != nullptr) { Temp = Temp->Prev; }
            
			// Check the position is within the boundary, if not exit.
            if (Temp == nullptr && N > 0) { cout << "Provided position is greater than the size of DoublyLinkedList, Exiting. " << endl; return; }
            
            DblLnkLst* T1 = Temp;					// Back-up the current node (which should be deleted) to keep the links
                                                
            Temp->Next->Prev=Temp->Prev;        	// Current node's next node's previous should point to current node's previous.
            Temp->Prev->Next = T1->Next;        	// Current node's previous node's next should point to curren node's next.
            delete T1; T1 = nullptr;            	// After linking delete the current link node.
        }
		
};

int DoublyLinkedList(int lstsize)
{
    DblLnkLst dl;
    cout << "Inserting Data into Doubly Linked List: " << endl;
    for (int i = 0; i < lstsize; i++)
        dl.Insert(i * 10);
    cout << endl;
    
    dl.PrintForward();
    dl.PrintBckward();
    cout << endl;    
    
    cout << "Inserting element 77777 at position 6 from Head: --------- "<< endl;
    dl.InsertElementsAtFwdPos(6, 77777);
    dl.PrintForward();
    dl.PrintBckward();
    cout << endl;
    
    cout << "Inserting element 88888 at position 8 from End: --------- "<< endl;
    dl.InsertElementsAtBwdPos(8, 88888);
    dl.PrintForward();
    dl.PrintBckward();
    cout << endl;

    cout << "Remove element at position 10 from Head: --------- "<< endl;
    dl.RemoveNthElementFromStart(10);
    dl.PrintForward();
    dl.PrintBckward();
    cout << endl;
    
    cout << "Remove element at position 12 from End: --------- "<< endl;
    dl.RemoveNthElementFromEnd(12);
    dl.PrintForward();
    dl.PrintBckward();
    cout << endl;

    dl.Remove();
    
    return 0;
}

int main()
{
    DoublyLinkedList(20);
    return 0;
}
