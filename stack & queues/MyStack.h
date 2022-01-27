#include <bits/stdc++.h>
using namespace std;

class MyStack{
    
    public:
    int *arr, top=-1,size;
    MyStack(int size){
        arr = (int*) malloc(size*sizeof(int));
        this->size = size;
    }
    int sizeOfStack(void);
    int topElement(void);
    int pop(void);
    void push(int);
    bool isEmpty(void);
};

void MyStack :: push(int val){
    if(top==size-1){
        cout<<"stack overflow\n";
        return;
    }
    arr[++top] = val;
}

int MyStack::pop(){
    if(top==-1){
        cout<<"stack is already empty\n";
        return -1;
    }
    return arr[top--];
}

int MyStack::sizeOfStack(){
    return top+1;
}

int MyStack::topElement(){
    return (top>=0 && top<size) ? arr[top] : -1 ;
}

bool MyStack::isEmpty(){
    return top==-1;
}
