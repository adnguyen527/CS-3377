#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList<int> mylist;

    // Add few items to the end of LinkedList
    mylist.add(3);
    mylist.add(5);
    mylist.add(2);

    // original print
    cout << "Printing original order" << endl;
    for ( LinkedList<int>::Iterator iterator1 = mylist.begin(); 
            iterator1 != mylist.end(); iterator1++)
    {
        cout << *iterator1 << " ";
    }

    cout << endl;
    // post quicksort print
    mylist.quicksort();
    cout << "Printing correct order" << endl;
    for ( LinkedList<int>::Iterator iterator2 = mylist.begin(); 
            iterator2 != mylist.end(); iterator2++)
    {
        cout << *iterator2 << " ";
    }
}
