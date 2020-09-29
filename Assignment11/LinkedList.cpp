#include "LinkedList.h"
using namespace std;

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
template <typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::quicksortRec
    (ListNode* pHead, ListNode* pEnd)
{
    // base
    if (!pHead || pHead == pEnd) return pHead;

    ListNode* newHead = NULL, *newEnd = NULL;

    ListNode *pivot = partition(pHead, pEnd, &newHead, &newEnd);
    if (newHead != pivot)
    {
        // set node before pivot node as NULL
        ListNode* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;

        // recur for the list before pivot
        newHead = quicksortRec(newHead, temp);

        // change next of last node to left half of pivot
        temp = getTail(newHead);
        temp->next = pivot;
    }
    // recur for the list after the pivot
    pivot->next = quicksortRec(pivot->next, newEnd);

    return newHead;
}
template <typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::partition
    (struct ListNode* pHead, struct ListNode* pEnd,
     struct ListNode** newHead, struct ListNode** newEnd)
{
    ListNode *pivot = pEnd;
    ListNode *prev = NULL, *current = pHead, *tail = pivot;

    while (current != pivot)
    {
        if (current->data < pivot->data)
        {
            // first node has less value than the pivot becomes new HEAD
            if (*newHead == NULL) *newHead = current;

            prev = current;
            current = current->next;
        }else{ // if current node is greater than pivot
            // move current node to next of tail and change tail
            if (prev)
                prev->next = current->next;
            ListNode *temp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    // if pivot data is smallest in linked list, pivot becomes head
    if (*newHead == NULL) *newHead = pivot;

    // update newEnd to current last node
    *newEnd = tail;

    return pivot;
}
template <typename T>
void LinkedList<T>::quicksort()
{
    head = quicksortRec(head, getTail(head));
    return;
}
template <typename T>
typename LinkedList<T>::ListNode* LinkedList<T>::getTail(ListNode* p)
{
    while (p != NULL && p->next != NULL)
        p = p->next;
    return p;
}