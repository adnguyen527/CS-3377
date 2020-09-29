#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
    // declare a structure for the list
    struct ListNode 
    {
        int data; // value
        struct ListNode *next; // pointer to the next node
    };
    ListNode *head; // list head pointer
public:
    // constructor
    NumberList()
    {head = NULL;}
    // destructor
    ~NumberList(){};

    // operators for linked list
    void appendNode(int);   // add node to end of list
    void insertNode(int);   // insert node
    void deleteNode(int);   // delete node
    void displayList() const; // display linked list
    void deleteList();
};

#endif