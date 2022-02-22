#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//dp[coin][sum]

//{1,2,5,9}, 11
int coinChange(vector<int> &coins, int sum){
    int N = coins.size();
    vector<vector<int> > dp(N+1, vector<int>(sum+1, 0));
    for(int i=1;i<=sum;i++){
        dp[0][i] = INT_MAX;
    }
    for(int i=0;i<=N;i++){
        dp[i][0] = 0;
    }
    for(int s=1;s<=sum;s++){
        for(int j=1;j<=N;j++){
            if(s>=coins[j-1]){
                if(dp[j][s-coins[j-1]] < INT_MAX){
                    dp[j][s] = min(1+dp[j][s-coins[j-1]],dp[j-1][s]);
                }
            }else{
                dp[j][s] = dp[j-1][s];
            }
                
        }
    }
    return dp[N][sum];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<coinChange(arr, sum);
}