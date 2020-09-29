#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "LinkedList.cpp"

int main()
{
    LinkedList<int> mylist;

    // create list by adding ints
    mylist.add(1);
    mylist.add(2);
    mylist.add(3);

    // traverse and print LinkedList through iterator
    cout << "Traversing LinkedList through Iterator" << endl;
    for (LinkedList<int>::Iterator iterator = mylist.begin(); 
        iterator != mylist.end(); iterator++)
    {
        cout << *iterator << " ";
    }
    cout << endl;

    return 0;
}