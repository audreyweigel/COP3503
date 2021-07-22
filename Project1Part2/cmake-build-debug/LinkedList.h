#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class LinkedList {
private:
public:
    struct Node {
        T data;
        Node *next; // pointer to next node
        Node *prev; // pointer to previous node (if doubly linked)
    };
    Node *nodeHead;
    Node *nodeTail;
    Node* Head();
    const Node* Head() const;
    Node* Tail();
    const Node* Tail() const;
    Node* GetNode(unsigned int index);
    const Node* GetNode(unsigned int index) const;
    Node* Find(const T& data);
    const Node* Find(const T& data) const;
    void FindAll(vector<Node*>& outData, const T& value) const;
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    T& operator[](unsigned int index);// operator
    const T& operator[](unsigned int index) const;// copy assignment operator
    void AddHead(const T& data);
    void AddTail(const T& data);
    void PrintForward() const;
    ~LinkedList();
    unsigned int NodeCount() const;
    LinkedList<T>& operator=(const LinkedList<T>& rhs);
};

template<typename T>
LinkedList<T>::LinkedList() {
// constructor
    nodeHead = nullptr;
    nodeTail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
// copy constructor
    Node *listNode = list.nodeHead;
    Node *listNode1 = list.nodeTail;

    nodeHead = nullptr;
    nodeTail = nullptr;

    while (listNode != nullptr) {
        AddTail(listNode->data);
        listNode = listNode->next;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
// assignment operator
    Node* temporary = nodeHead;
    while (temporary != nullptr) {
        nodeHead = nodeHead->next;
        delete temporary;
        temporary = nodeHead;
    }
    nodeHead = nullptr;
    nodeTail = nullptr;

    Node *listNode = rhs.nodeHead;
    Node *listNode1 = rhs.nodeTail;

    while (listNode != nullptr) {
        AddTail(listNode->data);
        listNode = listNode->next;
    }
    return *this;
}

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
        nodeHead->prev = nodePtr;
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
        nodePtr->prev = nodeTail;
        nodeTail = nodePtr;
    }
}

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
T& LinkedList<T>::operator[](unsigned int index) {
// assignment operator
    // takes an index
    // returns data from index-th node
    // throws out of range exception for invalid index
    Node *indexNode = nodeHead;
    unsigned int i = 0;
    while (i < index && indexNode != nullptr) {
        indexNode = indexNode->next;
        i++;
    }
    if (i == index) {
        return indexNode->data;
    }
    else {
        throw out_of_range("");
    }
}

template<typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
// copy assignment constructor
    Node *indexNode = nodeHead;
    unsigned int i = 0;
    while (i < index && indexNode != nullptr) {
        indexNode = indexNode->next;
        i++;
    }
    if (i == index) {
        return indexNode->data;
    }
    else {
        throw out_of_range("");
    }
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
// Returns the head pointer. non-const version.
    return nodeHead;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
// Returns the head pointer. Const version.
    return nodeHead;
}

// ways to add info to container:
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
// Returns the tail pointer. non-const version.
    return nodeTail;
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
// Returns the tail pointer. Const version.
    return nodeTail;
}

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

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
/* Given an index, return a pointer to the node at that index. Throws
an exception of type out_of_range if the index is out of range. non-const version. */
    if (index < 0 || index >= NodeCount()) {
        throw out_of_range("");
    }
    else {
        Node* getNode = nodeHead;
        unsigned int j = 0;
        while (j < index) {
            getNode = getNode->next;
            j++;
        }
        return getNode;
    }
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
// constructor
    if (index < 0 || index >= NodeCount()) {
        throw out_of_range("");
    }
    else {
        Node* getNode = nodeHead;
        unsigned int j = 0;
        while (j < index) {
            getNode = getNode->next;
            j++;
        }
        return getNode;
    }
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
/* Find the first node with a data value matching the passed
in parameter, returning a pointer to that node. Returns nullptr
if no matching node found. */
    vector<Node*> firstNode;
    FindAll(firstNode, data);
    Node *firstNodePtr = nullptr;
    if (!firstNode.empty()) {
        firstNodePtr = firstNode.at(0);
    }
    return firstNodePtr;
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
    vector<Node*> firstNode;
    FindAll(firstNode, data);
    Node *firstNodePtr = nullptr;
    if (!firstNode.empty()) {
        firstNodePtr = firstNode.at(0);
    }
   return firstNodePtr;
}

template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
/* Find all nodes which match the passed in parameter value, and store
a pointer to that node in the passed in vector. Use of a parameter like
this (passing a something in by reference, and storing data for later use)
is called an output parameter. */
    Node *nodePtr = nodeHead;
    while (nodePtr != nullptr) {
        if (nodePtr->data == value) {
            outData.push_back(nodePtr);
        }
        nodePtr = nodePtr->next;
        /* if (nodePtr == nullptr) {
            nodePtr = nullptr;
        }
    }
    if (nodePtr == &data) {
        nodePtr = &data; */
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
