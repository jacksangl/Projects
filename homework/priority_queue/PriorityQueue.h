// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Jack Sangl>
// Section: <Lab 003L>
// Assignment: Priority Queue
#pragma once
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

template <typename T>
class PriorityQueue
{

    struct Priority
    {
        T data;
        int priority;
    };

public:
    // max size of queue capacity for this implementation could remove if not using driver file

    PriorityQueue()
    {
        queue_capacity = 1024;
        queue = new Priority[queue_capacity];
        size = 0;
    }

    // big 3
    ~PriorityQueue()
    {
        delete[] queue;
    }

    PriorityQueue(const PriorityQueue &origList)
    {
        queue_capacity = origList.queue_capacity;
        size = origList.size;
        queue = new Priority[queue_capacity];

        for (int i = 0; i < size; i++)
        {
            queue[i].data = origList.queue[i].data;
            queue[i].priority = origList.queue[i].priority;
        }
    }

    PriorityQueue &operator=(const PriorityQueue &origList)
    {
        if (this != &origList)
        {
            delete[] queue;
            queue_capacity = origList.queue_capacity;
            queue = new Priority[queue_capacity];
            this->size = origList.size;

            for (int i = 0; i < size; i++)
            {
                queue[i].data = origList.queue[i].data;
                queue[i].priority = origList.queue[i].priority;
            }
            return *this;
        }
        return *this;
    }

    // big 3

    bool IsEmpty()
    {
        if (size == 0)
            return true;

        return false;
    }
    void Insert(T item, int priorityVal)
    {

        for (int i = 0; i < size; i++)
        {
            if (item == queue[i].data)
            {
                cerr << "NO DUPLICATE OF PRIORITY QUEUE ALLOWED!" << endl;
                return;
            }
        }

        if (size == queue_capacity)
        {
            queue_capacity *= 1.5;
            Priority *bob = new Priority[queue_capacity];
            for (int i = 0; i < size; i++)
            {
                bob[i].data = queue[i].data;
                bob[i].priority = queue[i].priority;
            }
            delete[] queue;
            queue = bob;
        }

        queue[size].data = item;
        queue[size].priority = priorityVal;

        size++;
        return;
    }
    void ChangePriority(T item, int priorityVal)
    {
        for (int i = 0; i < size; i++)
        {
            if (item == queue[i].data)
                queue[i].priority = priorityVal;
        }
        return;
    }
    T Pull()
    {
        if (size == 0)
        {
            cerr << "NO PULL WHEN EMPTY QUEUE" << endl;
            return T();
        }

        int highest = 0, position = 0;
        T high;
        for (int i = 0; i < size; i++)
        {
            if (highest < queue[i].priority)
            {
                highest = queue[i].priority;
                position = i;
                high = queue[i].data;
            }
        }
        for (int i = position; i < size - 1; i++)
        {
            queue[i] = queue[i + 1];
        }

        size--;

        return high;
    }

    T Peek()
    {
        if (size == 0)
        {
            cerr << "NO PEEK WHEN EMPTY QUEUE" << endl;
            return T();
        }
        T high;
        int prio = 0;
        for (int i = 0; i < size; i++)
        {
            if (queue[i].priority > prio)
            {
                prio = queue[i].priority;
                high = queue[i].data;
            }
        }
        return high;
    }

private:
    Priority *queue;
    int size;
    int queue_capacity;
};

/*
Successfully created an empty priority queue for strings.
Insert string "Homework Due Today" to the priority queue with priority value 20.
Insert string "Play Games" to the priority queue with priority value 3.
Insert string "Prepare Dinner" to the priority queue with priority value 30.
Insert string "Exam" to the priority queue with priority value 70.
Insert string "Workout" to the priority queue with priority value 15.
Insert string "Homework Due Today" to the priority queue with priority value 45.
NO DUPLICATE OF PRIORITY QUEUE ALLOWED!
Current item with the highest priority: Exam
Removing the highest priority item...
Current item with the highest priority: Prepare Dinner
Change the priority of item "Homework Due Today" to 50.
Current item with the highest priority: Homework Due Today
Removing the two highest priority item...
Current item with the highest priority: Workout
*/