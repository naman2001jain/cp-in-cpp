#include<bits/stdc++.h>
using namespace std;

int minSwaps(string s) {
        
        int mx = INT_MAX;    // tracker for the most negative value (minimum value) of c
        int c = 0;
        for(auto i:s)    
        {
            if(i=='[') c++;
            else c--; 
            mx = min(mx, c);
        }
        return (abs(mx)+1)/2;
    
    }

int main(){

}
