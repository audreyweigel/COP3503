#ifndef ABQ_H
#define ABQ_H

#include <iostream>
using namespace std;

template<class T>

class ABQ {
private:
    int maxCapacity;
    int currentSize;
    int rear;
    T *queue;
    const float scaleFactor = 2.0f;
public:
    ABQ() {
        // Default constructor. Maximum capacity should be set to 1, and current size set to 0
        maxCapacity = 1;
        currentSize = 0;
        rear = -1;
        queue = new T[maxCapacity];
    }

    ABQ(int capacity) {
        // Constructor for an ABQ with the specified starting maximum capacity.
        maxCapacity = capacity;
        currentSize = 0;
        rear = -1;
        queue = new T[maxCapacity];
    }

    ABQ(const ABQ &d) {
        // Copy Constructor
        maxCapacity = d.maxCapacity;
        currentSize = d.currentSize;
        rear = d.rear;

        this->queue = new T[maxCapacity];
        for (int i = 0; i < currentSize; i++) {
            this->queue[i] = d.queue[i];
        }
    }

    ABQ &operator=(const ABQ &d) {
        // Assignment operator.
        delete[] this->queue;
        maxCapacity = d.maxCapacity;
        currentSize = d.currentSize;
        rear = d.rear;

        this->queue = new T[maxCapacity];
        for (int i = 0; i < currentSize; i++) {
            this->queue[i] = d.queue[i];
        }
        return *this;
    }

    ~ABQ() {
        // Destructor
        delete[] queue;
    }

    void enqueue(T data) {
        // Add a new item to end of the queue and resizes if necessary.
        if (currentSize == maxCapacity)
        {
            T *tempQueue = new T[maxCapacity];
            for (int i = 0; i < currentSize; i++) {
                tempQueue[i] = queue[i];
            }
            delete[] queue;
            maxCapacity = scaleFactor * maxCapacity;
            queue = new T[maxCapacity];

            for (int i = 0; i < currentSize; i++) {
                queue[i] = tempQueue[i];
            }
            delete[] tempQueue;
        }
        // increment the new data that has been pushed
        rear++;
        currentSize++;
        queue[rear] = data;
    }

    T dequeue() {
        /* Remove the item at front of the queue, resizes if necessary,
        and return the value removed.Throws a runtime_errorif the queue is empty. */
        if (this->currentSize == 0) {
            throw runtime_error("Error.");
        }
        // retrieve beginning of queue
        T data = queue[0];

        for(int i = 0; i < currentSize - 1; i++) {
            queue[i] = queue[i + 1];
        }
        currentSize--;

        //float divisor = currentSize / maxCapacity;
        // if size is less than 1/2 capacity, resize
        if (currentSize < maxCapacity/scaleFactor) {
            T *tempQueue = new T[maxCapacity];
            for (int i = 0; i < currentSize; i++) {
                tempQueue[i] = queue[i];
            }

            delete[] queue;

            maxCapacity = maxCapacity / scaleFactor;
            queue = new T[maxCapacity];

            for (int i = 0; i < currentSize; i++) {
                queue[i] = tempQueue[i];
            }
            delete[] tempQueue;
        }

        return data;
    }

    T peek() {
        T data;
        if (this->currentSize > 0) {
            data = queue[0];
        }
        else {
            throw runtime_error("Error");
        }
        return data;
        /* Return the value of the item at the front of the queue, without removing it.
        Throws a runtime_errorif the queue is empty. */
    }

    unsigned int getSize() {
        // Returns the current number of items in the ABQ.
        return currentSize;
    }

    unsigned int getMaxCapacity() {
        // Returns the current max capacity of the ABQ.
        return maxCapacity;
    }

    T *getData() {
        // Returns the array representing the queue.
        return queue;
    }
};

#endif
