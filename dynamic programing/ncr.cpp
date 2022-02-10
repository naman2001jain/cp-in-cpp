#include<iostream>
#define SIZE 100
using namespace std;

long long int dp[SIZE][SIZE];
//dp[n][r]


long long int find_ncr(long long int n, long long int r){
    if(n<r){
        return 0;
    }
    if(n==0 || n==1){
        return 1;
    }
    
    for(int i=0;i<SIZE;i++){
        dp[i][0] = 1;
    }
    for(int i=0;i<SIZE;i++){
        dp[i][i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][r];
}

int main(){
    long long int n,r;
    cin>>n>>r;
    cout<<find_ncr(n,r);
}