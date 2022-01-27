#include<bits/stdc++.h>
using namespace std;

bool isMatching(char a, char b){
        return (a=='(' && b==')') ||
            (a=='{' && b=='}') ||
            (a=='[' && b==']');
    }
    
    bool isOpening(char a){
        return (a=='(' || a=='{' || a=='[');
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(isOpening(s[i])){
                st.push(s[i]);
            }else if(st.empty()){
                    return false;
            }else{
                  if(isMatching(st.top(), s[i])){
                      st.pop();
                  }else{
                      return false;
                  } 
            }
            
        }
        return st.empty();
    }

int main(){

}
