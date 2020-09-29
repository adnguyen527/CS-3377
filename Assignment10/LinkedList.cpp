#include "LinkedList.h"
template <typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::head = nullptr;

template <typename T>
void LinkedList<T>::deleteList()
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
template <typename T>
void LinkedList<T>::add(T d)
{
    ListNode* newNode;  // point to new node
    ListNode* nodePtr;  // move through list

    // allocate new node to store number there
    newNode = new ListNode;
    newNode->data = d;
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
template <typename T>
void LinkedList<T>::insertNode(int num)
{
    ListNode* newNode;
    ListNode* nodePtr;
    ListNode* previousNode = NULL;

    // allocate new node and store num there
    newNode = new ListNode;
    newNode->data = num;

    // if no nodes in list
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }else{  // otherwise insert newNode
        nodePtr = head;             // position nodePtr at the head of list
        previousNode = NULL;        // initialize previousNode to NULL
        // Skip all nodes with values less than num
        while (nodePtr != NULL && nodePtr->data < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // if new node is at the front of list
        if (previousNode == NULL)
        {
            head = newNode;
            newNode->next = nodePtr;
        }else{  // otherwise insert after previous node
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}
template <typename T>
void LinkedList<T>::deleteNode(int num)
{
    ListNode* nodePtr;      // basically a temp node to traverse with
    ListNode* previousNode;

    // if list is empty
    if (!head) return;
    
    // determine if first node to be deleted
    if (head->data == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }else{
        // initialize nodePtr as head
        nodePtr = head;
        // skip all nodes that have values not equal to num.
        while (nodePtr != NULL && nodePtr->data != num)
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
template <typename T>
void LinkedList<T>::displayList() const
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