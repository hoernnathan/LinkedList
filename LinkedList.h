#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <iostream>
using namespace std;
class LinkedList;
class Node;
class Node{
public:
    //Node(int data);
    friend LinkedList;
    int data;
    Node* next;
};
class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    void append(int value);
    void display();
    void insert(int value, int index);
    int get(int index);
    void remove(int index);
    void reverse();
private:
    Node *head, *tail;
};
#endif