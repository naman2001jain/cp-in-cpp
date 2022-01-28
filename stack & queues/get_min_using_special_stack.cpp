#include <bits/stdc++.h>
using namespace std;

class ss{
    public:
    int *hash, *aux;
    int size,top;
    ss(int size){
        this->hash = (int* )malloc(size*sizeof(int));
        this->aux = (int* )malloc(size*sizeof(int));
        this->size = size;
        this->top = -1;
    }
    bool isEmpty(void);
    int pop(void);
    int findMin(void);
    void push(int);
    int getSize(void);
    int getTopElement(void);

};

int ss::getTopElement(){
    if(top==-1){
        cout<<"stack is empty\n";
        return -1;
    }
    return hash[top];
}

int ss::getSize(){
    return top+1;
}

bool ss::isEmpty(){
    return top==-1;
}

int ss::pop(){
    if(top==-1){
        cout<<"stack is empty\n";
        return -1;
    }
    
    return hash[top--];
}

int ss::findMin(){
    if(top==-1){
        cout<<"stack is empty\n";
        return -1;
    }
    return aux[top];
}

void ss::push(int val){
    if(top==size-1){
        cout<<"stack overflow\n";
    }else if(top==-1){
        hash[++top] = val;
        aux[top] = hash[top];
    }else{
        hash[++top] = val;
        aux[top] = min(hash[top], aux[top-1]);
    }
}

int main() {
    ss s(5);
    cout<<s.findMin()<<"\n";
    s.push(10);
    s.pop();
    s.pop();
    s.push(20);
    s.push(15);
    s.push(30);
    cout<<s.findMin();
}
