#include <iostream>

using namespace std;

typedef int Type;

class Node {
public:
    Type data;
    Node* next;
    ~Node();

};

Node::~Node() {
    delete this->next;
}

void insert(Node*& first, unsigned position, Type data);


int GetLength(Node* first) {
    int length = 0;
    Node* cur = first;
    while (cur != NULL) {
        length++;
        cur = cur->next;
    }
    return length;
}

bool GetElement(Node * first, int position, Type & data) {
    int length = 0;
    Node* cur = first;
    while ((length != position) && (cur!= NULL)) {
        length++;
        cur = cur->next;
    }
    if (cur == NULL) 
        return false;

    if (data == cur->data)
        return true;
    return false;
}

void InsertToSortedLinkedList(Node * &first, Type data) {
    int pos = 0;
    bool inserted;
    
    Node* insert = new Node;
    insert->data = data;
    Node* cur = first;


    while (cur != NULL) {
        pos ++;
        if (cur->next == NULL)
            break;
        if (cur->data > data) {
            inserted = true;
            insert->next = cur;
            first = insert;
            return;
        }
        else if ((cur->data < data) && (data< (cur->next)->data)) {
            inserted = true;
            break;
        }
        cur = cur->next;
    }
    if (!inserted) {
        cur->next = insert;
        insert->data = data;
        insert->next = NULL;
        return;
    } 

    // insert element
    Node* temp;
    temp = cur->next;
    cur->next = insert;
    cur = cur->next;
    cur->next = temp;

    return;
}


void insert(Node*& first, unsigned position, Type data) {
    if (position == 0) {
        Node* temp = first;
        first = new Node;
        first->data = data;
        first->next = temp;
    }
    else {
        Node* prev = first;
        int currentIndex = 1;
        while (currentIndex < position) {
            prev = prev->next;
            currentIndex++;
        }
        Node* temp = prev->next;
        prev->next = new Node;
        prev->next->data = data;
        prev->next->next = temp;
    }
}

void display(Node* first) {
    Node* cur = first;
    while (cur != NULL) {
        cout << (cur->data) << " ";
        cur = cur->next;
    }
    cout << endl;
}

void remove(Node*& first, unsigned position) {
    if (position == 0) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    else {
        Node* prev = first;
        int currentIndex = 1;
        while (currentIndex < position) {
            prev = prev->next;
            currentIndex++;
        }
        Node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }
}

Node* NewLinkedList(Type* arr, unsigned size) {
    Node* first = NULL;
    for (int i = size - 1; i >= 0; i--) {
        insert(first, 0, arr[i]);
    }

    return first;
}


int main() {
    Type data;
    {
        cout << "Given linked list: ";
        Type arr[] = { 10, 4, 2, 6, 42, 50 };
        Node* first = NewLinkedList(arr, 6);

        display(first);
        cout << "The length is " << GetLength(first) << endl;
        if (GetElement(first, 3, data))
            cout << "Element at position " << 3 << " is " << data << endl;
        else
            cout << "Failed to find data at position 3" << endl;
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = { 5, 2, 6, 4, 6 };
        Node* first = NewLinkedList(arr, 5);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        if (GetElement(first, 0, data))
            cout << "Element at position " << 0 << " is " << data << endl;
        else
            cout << "Failed to find data at position 0" << endl;
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = { 1, 3, 5, 7, 9, 11, 53, 70 };
        Node* first = NewLinkedList(arr, 8);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        if (GetElement(first, 7, data))
            cout << "Element at position " << 7 << " is " << data << endl;
        else
            cout << "Failed to find data at position 7" << endl;
        cout << endl;
        
        if (GetElement(first, 8, data))
            cout << "Element at position " << 8 << " is " << data << endl;
        else
            cout << "Failed to find data at position 8" << endl;
        cout << endl;

        cout << "Try to insert 8 into this linked list, the list becomes:" << endl;
        InsertToSortedLinkedList(first, 8);
        display(first);
        cout << endl;

        cout << "Try to insert 0 into this linked list, the list becomes:" << endl;
        InsertToSortedLinkedList(first, 0);
        display(first);
        cout << endl;

        cout << "Try to insert 100 into this linked list, the list becomes:" << endl;
        InsertToSortedLinkedList(first, 100);
        display(first);
        cout << endl;
    }
}
