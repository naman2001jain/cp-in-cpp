//problem link https://leetcode.com/problems/top-k-frequent-elements/

#include<bits/stdc++.h>
using namespace std;

class comparator{
        public:
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            return a.second>b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator>  pq;
        for(auto x: mp){
            if(pq.size()<k){
                pq.push(make_pair(x.first, x.second));
            }else{
                if(pq.top().second < x.second){
                    pq.pop();
                    pq.push(make_pair(x.first, x.second));
                }
            }
        }
        for(int i=0;i<k;i++){
            res.push_back(pq.top().first);
            pq.pop();    
        }
        return res;
    }

int main(){

  
}
