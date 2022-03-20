#include<iostream>
using namespace std;

int parent[100000];
int rankArray[100000];

void makeSet(int n){
    for(int i=0;i<n;i++){
        rankArray[i] = 0;
        parent[i] = i;
    }
}


int findParent(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(node);   //path compression
}

void makeUnion(int u, int v){
    u = findParent(u);
    v = findParent(v);

    if(rankArray[u] < rankArray[v]){
        parent[u] = v;
    }
    else if(rankArray[u] > rankArray[v]){
        parent[v] = u;
    }
    else{
        parent[u] = v;
        rankArray[v]++;
    }
}

int main(){
    makeSet(5);
}