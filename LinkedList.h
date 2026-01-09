#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head; 

public:
    LinkedList();                 
    ~LinkedList();
    void insert(int val);
    bool isEmpty();               
    void update(int oldVal, int newVal); 
    void remove(int val);         
    void display();               
};

#endif
