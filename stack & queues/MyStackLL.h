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
    MyStackLL(){
        this->head = NULL;
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
    return (head)? head->val : -1;
}

int MyStackLL:: sizeOfStack(){
    if(head==NULL){
        return 0;
    }
    int size=0;
    ListNode* currNode = head;
    while(currNode){
        size++;
        currNode = currNode->next;
    }
    return size;
}

void MyStackLL::push(int val){
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
