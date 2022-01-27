#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(){};
    ListNode(int val){this->val = val; this->next = NULL;}
};

class MyStackLL{
    public:
    ListNode* head;
    int size;
    MyStackLL(){
        this->head = NULL;
        this->size = 0;
    }

    int sizeOfStack(void);
    int topElement(void);
    int pop(void);
    void push(int);
    bool isEmpty(void);
};

bool MyStackLL::isEmpty(){
    return head==NULL;
}

int MyStackLL::pop(){
    if(head==NULL){
        cout<<"stack is empty\n";
        return -1;
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    size--;
    return (head)? head->val : -1;
}

int MyStackLL:: sizeOfStack(){
    return size;
}

void MyStackLL::push(int val){
    size++;
    if(head==NULL){
        head = new ListNode(val);
        return;   
    }
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

int MyStackLL::topElement(){
    if(head==NULL){
        cout<<"stack is empty\n";
        return -1;
    }
    return head->val;
}
