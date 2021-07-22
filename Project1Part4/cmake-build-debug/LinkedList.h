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
        Node *next = nullptr; // pointer to next node
        Node *prev = nullptr; // pointer to previous node (if doubly linked)
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
    void InsertBefore(Node* node, const T& data);
    void InsertAfter(Node* node, const T& data);
    void InsertAt(const T& data, unsigned int index);
    bool operator==(const LinkedList<T>& rhs) const;
    bool RemoveHead();
    bool RemoveTail();
    unsigned int Remove(const T&data);
    bool RemoveAt(unsigned int index);
    void Clear();
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive(const Node* node) const;
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
an exception of type out_of_range if the index is out of range. const version. */
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
// non constructor
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

template<typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
/* Given a pointer to a node, create a new node to store the passed in
value, after the indicated node. */
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = node->next;
    newNode->prev = node;
    newNode->next->prev = newNode;
    node->next = newNode;
}

template<typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
// Ditto, except insert the new node before the indicated node.
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = node->prev;
    newNode->next = node;
    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    }
    else {
        nodeHead = newNode;
    }
    node->prev = newNode;
}

template<typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
/* Inserts a new Node to store the first parameter, at the index-th location.
So if you specified 3 as the index, the new Node should have 3 Nodes before it.
Throws an out_of_range exception if given an invalid index. */
    if (index == NodeCount()) {
        AddTail(data);
    }
    else {
        Node *insertNode = GetNode(index);
        InsertBefore(insertNode, data);
    }
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {
/* Overloaded equality operator. Given listA and listB, is listA equal to listB?
What would make one Linked List equal to another? If each of its nodes were equal
to the corresponding node of the other. (Similar to comparing two arrays, just with
non-contiguous data). */
    Node *currentList = nodeHead;
    const Node *anotherList = rhs.Head();
    while (currentList != nullptr && anotherList != nullptr) {
        if (currentList->data != anotherList->data) {
            return false;
        }
        currentList = currentList->next;
        anotherList = anotherList->next;
    }
    if (NodeCount() != rhs.NodeCount()) {
        return false;
    }
    return true;
}

template<typename T>
bool LinkedList<T>::RemoveHead() {
    if (nodeHead == nullptr) {
        return false;
    }
    Node *removingHead = nodeHead;
    removingHead = removingHead->next;
    delete nodeHead;
    nodeHead = removingHead;
    if (nodeHead == nullptr) {
        nodeTail = nullptr;
    }
    else {
        nodeHead->prev = nullptr;
    }
    return true;
}

template<typename T>
bool LinkedList<T>::RemoveTail() {
    if (nodeTail == nullptr) {
        return false;
    }
    Node *removingTail = nodeTail;
    removingTail = removingTail->prev;
    delete nodeTail;
    nodeTail = removingTail;
    if (nodeTail == nullptr) {
        nodeHead = nullptr;
    }
    else {
        nodeTail->next = nullptr;
    }
    return true;
}

template<typename T>
unsigned int LinkedList<T>::Remove(const T&data) {
    Node *nodeRemoval = nodeHead;
    unsigned int index = 0;
    int counter = 0;
    while (nodeRemoval != nullptr) {
        if (nodeRemoval->data == data) {
            nodeRemoval = nodeRemoval->next;
            RemoveAt(index);
            counter++;
        }
        else {
            nodeRemoval = nodeRemoval->next;
            index++;
        }
    }
    return counter;
}

template<typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
    if (index >= NodeCount()) {
        return false;
    }
    if (index == 0) {
        // head
        RemoveHead();
        return true;
    }
    else if (index == NodeCount()-1) {
        // last index; tail
        RemoveTail();
        return true;
    }
    else {
        // any other value
        Node *otherValue = GetNode(index);
        Node *previousValue = GetNode(index-1);
        Node *futureValue = GetNode(index+1);
        previousValue->next = futureValue;
        futureValue->prev = previousValue;
        delete otherValue;
        return true;
    }
}

template<typename T>
void LinkedList<T>::Clear() {
    Node* temporary = nodeHead;
    while (temporary != nullptr) {
        nodeHead = nodeHead->next;
        delete temporary;
        temporary = nodeHead;
    }
    nodeHead = nullptr;
    nodeTail = nullptr;
}

template<typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
    if (node == nullptr) {
        return;
    }
    cout << node->data << endl;
    PrintForwardRecursive(node->next);
}

template<typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
    if (node == nullptr) {
        return;
    }
    cout << node->data << endl;
    PrintReverseRecursive(node->prev);
}

#endif