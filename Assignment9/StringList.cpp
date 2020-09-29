#include "StringList.h"
#include <string>
using namespace std;

void StringList::deleteList()
{
    ListNode* nodePtr;  // to traverse the list
    ListNode* nextNode; // points to the next node

    // initialize nodePtr to the head of the list
    nodePtr = head;

    // traverse through list starting at the beginning,
    // deleting the head as you go
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;   // save pointer to next node
        delete nodePtr;             // delete nodePtr now that nothing is linked
        nodePtr = nextNode;
    }
}
void StringList::appendNode(string str)
{
    ListNode* newNode;  // point to new node
    ListNode* nodePtr;  // move through list

    // allocate new node to store number there
    newNode = new ListNode;
    newNode->data = str;
    newNode->next = NULL;

    // if list is empty or no nodes
    if (!head) head = newNode;
    else
    {
        nodePtr = head;             // initialize nodePtr to head of list
        while (nodePtr->next)       // find last node in list
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;    // insert newNode as the last node
    }
}
void StringList::deleteNode(string str)
{
    ListNode* nodePtr;      // basically a temp node to traverse with
    ListNode* previousNode;

    // if list is empty
    if (!head) return;
    
    // determine if first node to be deleted
    if ((head->data).compare(str) == 0)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }else{
        // initialize nodePtr as head
        nodePtr = head;
        // skip all nodes that have values not equal to num.
        while (nodePtr != NULL && (nodePtr->data).compare(str) != 0)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
void StringList::displayList() const
{
    ListNode *temp = new ListNode;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}