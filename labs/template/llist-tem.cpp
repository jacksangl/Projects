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
// Assignment: template
#include <iostream>
using namespace std;
// Declation of Node class template
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
};
// Insert. Fill in your code here...

template <typename T>
void insert(Node <T> *&first, int pos, T data) {
    if (first == NULL) {
        first = new Node <T>; 
        first->data = data;
        first->next = NULL;
        return;
    }
    Node<T> *bob = new Node <T>; 
    bob->data = data;
    bob->next = NULL;

    if (pos == 0) {
        bob->data = data;
        bob->next = first;
        first = bob;
        return;
    }

    Node <T> *current = first, *store = current; 

    int count = 0;
    while (count < pos) {
        if (current != NULL) {
            store = current;
            current=current->next;
        }
        else 
            break;
        count++;
    }
    store->next = bob;
    bob->next = current;

    return;
    
}

template <typename T>
void clear(Node<T> *&first) {
    Node<T> *cur = first;
    while (cur != NULL) {
        Node<T> *temp = cur;
        cur = cur->next;
        delete temp;
    }
    first = NULL;
}

// Display
template <typename T>
void display(Node<T> *first)
{
    Node<T> *cur = first;
    while (cur != NULL)
    {
        cout << (cur->data) << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main()
{
    Node<int> *ifirst = NULL; // Empty linked list of integer
    insert<int>(ifirst, 0, 5);
    insert<int>(ifirst, 0, 6);
    insert<int>(ifirst, 0, 7);
    insert<int>(ifirst, 1, 8);
    insert<int>(ifirst, 4, 100);
    cout << "A Linked List of Integers: " << endl;
    display<int>(ifirst);
    Node<double> *dfirst = NULL; // Empty linked list of doubles
    insert<double>(dfirst, 0, 5.4);
    insert<double>(dfirst, 0, 23.4);
    insert<double>(dfirst, 0, 7.253);
    insert<double>(dfirst, 1, 100.45);
    insert<double>(dfirst, 4, 15.84);
    cout << "A Linked List of Doubles: " << endl;
    display<double>(dfirst);

    clear (ifirst);
    clear (dfirst);
    return 0;
}

/*
A Linked List of Integers: 
7 8 6 100 5 
A Linked List of Doubles: 
7.253 100.45 23.4 5.4 15.84 
*/