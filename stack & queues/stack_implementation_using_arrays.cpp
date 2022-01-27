#include <bits/stdc++.h>
#include "MyStack.h"
using namespace std;

int main() {
    MyStack ms(5);
    ms.push(1);
    ms.push(5);
    cout<<ms.top<<"\n";
    cout<<ms.topElement()<<"\n";
    
    cout<<"element popped: "<<ms.pop()<<"\n";
    cout<<ms.topElement()<<"\n";
   
}
