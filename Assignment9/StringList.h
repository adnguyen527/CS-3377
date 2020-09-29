#ifndef STRINGLIST_H
#define STRINGLIST_H
#include <string>
using namespace std;

class StringList
{
private:
    struct ListNode 
    {
        string data; // stored string
        struct ListNode *next; // pointer to the next node
    };
    ListNode *head; // list head pointer
public:
    // Constructor
    StringList()
    {head = NULL;}
    // Destructor
    ~StringList(){};

    // operators for linked list
    void appendNode(string);   // add node to end of list
    void deleteNode(string);   // delete node
    void displayList() const; // display linked list
    void deleteList();
};
#endif