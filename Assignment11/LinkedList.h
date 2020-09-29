#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

template <typename T>
class LinkedList
{
private:
    struct ListNode
    {
        T data;
        ListNode* next;
    };
    static ListNode *head;  // list head pointer
public:
    // Constructor
    LinkedList<T>() noexcept
    {
        head = NULL;
    }
    // Destructor
    ~LinkedList<T>(){};
    // forward declaration must be done in same access scope before the members
    class Iterator;
    Iterator begin()    // root of LinkedList as Iterator type
    {   return Iterator(head);  }
    Iterator end()      // end of LinkedList as Iterator type
    {   return Iterator(nullptr);   }

    // Operators
    void add(T);            // add data of end of list
    void insertNode(int);   // insert node
    void deleteNode(int);   // delete node
    void displayList() const; // display linked list
    void deleteList();      // delete list by empty

    // Quick Sort Functions
    ListNode* quicksortRec(ListNode*, ListNode*);
            // partitions the list taking the last element as the pivot
    ListNode* partition(struct ListNode*, struct ListNode*,
                         struct ListNode**, struct ListNode**);
    void quicksort();
    ListNode* getTail(ListNode*);
    
    // Iterator class to help access nodes of linked list
    class Iterator
    {
    private:
        const ListNode* currentNode;
    public:
        Iterator() noexcept : currentNode(head){}
        Iterator(const ListNode* pNode) noexcept : currentNode(pNode){}
        
        // Operators for Iterator class
        Iterator& operator=(ListNode* pNode)
        {
            this->currentNode = pNode;
            return *this;
        }
        // prefix++
        Iterator& operator++()
        {
            if (currentNode) currentNode = currentNode->next;
            return *this;
        }
        // postfix++
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }
        bool operator!=(const Iterator& iterator)
        {
            return currentNode != iterator.currentNode;
        }
        int operator*()
        {return currentNode->data;}
    };
};
#endif