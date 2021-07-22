#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
private:
public:
    struct Node {
        T data;
        Node *next; // pointer to next node
        Node *previous; // pointer to previous node (if doubly linked)
    };
    Node *nodeHead;
    Node *nodeTail;
    LinkedList();
    LinkedList(const LinkedList<T> &list);
    void AddHead(const T& data);
    void AddTail(const T& data);
    void AddNodesHead(const T* data, unsigned int count);
    void AddNodesTail(const T* data, unsigned int count);
    unsigned int NodeCount() const;
    void PrintForward() const;
    void PrintReverse() const;
    ~LinkedList();
};

template<typename T>
LinkedList<T>::LinkedList() {
    nodeHead = nullptr;
    nodeTail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    /* Sets "this" to a copy of the passed in LinkedList. For example, if the other
    list has 10 nodes, with values of 1-10? "this" should have a copy of that same data. */
    nodeHead = list.nodeHead;
    nodeTail = list.nodeTail;

    while (nodeHead != nullptr) {
        nodeHead->next;
        nodeTail->next;
    }
}

// ways to add info to container:
template<typename T>
void LinkedList<T>::AddHead(const T &data) {
    // Create a new Node at the front of the list to store the passed in parameter.
    if (nodeHead == nullptr) {
        // adds new node to node head
        nodeHead = new Node;
        nodeTail = nodeHead;
        nodeHead->data = data;
    }
    else {
        Node* nodePtr = new Node;
        nodePtr->data = data;
        nodeHead->previous = nodePtr;
        nodePtr->next = nodeHead;
        nodeHead = nodePtr;
    }
}

template<typename T>
void LinkedList<T>::AddTail(const T &data) {
    // Create a new Node at the end of the list to store the passed in parameter.
    if (nodeTail == nullptr) {
        // adds new node to node head
        nodeTail = new Node;
        nodeTail->data = data;
        nodeHead = nodeTail;
    }
    else {
        Node* nodePtr = new Node;
        nodePtr->data = data;
        nodeTail->next = nodePtr;
        nodePtr->previous = nodeTail;
        nodeTail = nodePtr;
    }
}

template<typename T>
void LinkedList<T>::AddNodesHead(const T *data, unsigned int count) {
    /* Given an array of values, insert a node for each of those at the beginning
     of the list, maintaining the original order. */
    for (int i = count-1; i >= 0; i--) {
        AddHead(data[i]);
    }
}

template<typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count) {
    // Ditto, except adding to the end of the list.
    for (unsigned int i = 0; i < count; i++) {
        AddTail(data[i]);
    }
}

// way to get more info about container
template<typename T>
unsigned int LinkedList<T>::NodeCount() const {
    // How many things are stored in this list?
    unsigned int count = 0;
    Node *counterNode = nodeHead;
    while (counterNode != nullptr) {
        count++;
        counterNode = counterNode->next;
    }
    return count;
}

// ways to see data in container
template<typename T>
void LinkedList<T>::PrintForward() const {
    // Iterator through all of the nodes and print out their values, one a time.
    Node *tempNode = nodeHead;
    while (tempNode != nullptr) {
        cout << tempNode->data << endl;
        tempNode = tempNode->next;
    }
}

template<typename T>
void LinkedList<T>::PrintReverse() const {
    // Exactly the same as PrintForward, except completely the opposite.
    Node *tempNode = nodeTail;
    while (tempNode != nullptr) {
        cout << tempNode->data << endl;
        tempNode = tempNode->previous;
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    // destructor, delete all the nodes created by the list
    Node* temporary = nodeHead;
    while (temporary != nullptr) {
        nodeHead = nodeHead->next;
        delete temporary;
        temporary = nodeHead;
    }
    nodeHead = nullptr;
    nodeTail = nullptr;
}

#endif