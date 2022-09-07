#include "LinkedList.h"
#include <exception>
#include <iostream>
using namespace std;
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
    Node* curr = head;
    while(curr != nullptr){
        head = curr;
        curr = curr->next;
        delete head;
    }
    head = nullptr;
    tail = nullptr;
}

void LinkedList::append(int value) {
    Node *curr = new Node();
    curr->data = value;
    Node *temp = head;
    if(head == nullptr){
        head = curr;
        tail = curr;
    }else{
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = curr;
        tail = curr;
    }
}

void LinkedList::display() {
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << endl;
}

void LinkedList::remove(int index) {
    Node* prev = head;
    Node* curr = head;
    Node* temp;
    int counter = 0;
    if(index < 0)
        throw range_error("Index too small");
    if(head == nullptr)
        throw range_error("List is empty!");
    if(index == 0){
        curr = curr->next;
        delete head;
        head = curr;
        return;
    }
    while(curr != nullptr){
        if(counter == index){
            temp = curr;
            curr = curr->next;
            prev->next = curr;
            if(temp->next == nullptr)
                tail = prev;
            delete temp;
            return;
        }
        prev = curr;
        curr = curr->next;
        counter++;
    }
    throw range_error("Index too large");
}

void LinkedList::insert(int value, int index) {
    Node* newNode = new Node();
    newNode->data = value;
    Node* prev = head;
    Node* curr = head;
    Node* temp;
    int counter = 0;
    if (index < 0)
        throw range_error("Index too small");
    if(head == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }
    if(index == 0) {
        head = newNode;
        newNode->next = prev;
    }
    while (curr != nullptr) {
        prev = curr;
        curr = curr->next;
        counter++;
        if (index == counter) {
            temp = newNode;
            temp->next = curr;
            prev->next = temp;
        }
    }
    if (index > counter)
        throw range_error("Index too large");
    if(prev->next == nullptr)
        tail = prev;
    else
        tail = temp;
}

int LinkedList::get(int index) {
    Node* curr = head;
    int counter = 0;
    if(index < 0)
        throw range_error("Index too small");
    while(curr != nullptr){
        if(counter == index)
            return curr->data;
        counter++;
        curr = curr->next;
    }
    throw range_error("Index too large");
}

void LinkedList::reverse() {
    Node *curr = head;
    Node *temp = nullptr;
    Node *prev = nullptr;
    while(curr != nullptr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}