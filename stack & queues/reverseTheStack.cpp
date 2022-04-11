#include <bits/stdc++.h>

using namespace std;

void reverse(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
    }else{
        int temp = s.top();
        s.pop();
        reverse(s, x);
        s.push(temp);
    }
}

void reverseTheStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    
    int temp = s.top();
    s.pop();
    reverseTheStack(s);
    reverse(s, temp);
}

void printStack(stack<int> s){
    if(s.empty()){
        return;
    }
    cout<<s.top()<<" ";
    s.pop();
    printStack(s);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    printStack(s);
    cout<<endl;
    reverseTheStack(s);
    printStack(s);
    
}
