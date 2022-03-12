#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[], int V, int s, vector<bool> &visited, vector<int> &res){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        res.push_back(temp);
        for(auto x: adj[temp]){
            if(visited[x] == false){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

vector<int> bfs(vector<int> adj[], int V, int s){
    vector<int> res;
    
    vector<bool> visited(V, false);
    for(auto x: adj[s]){
        if(visited[x]==false){
            bfs(adj, V, s, visited, res);
        }
    }
    return res;
}

void dfs(vector<int> adj[], int V, int s, vector<bool> &visited, vector<int> &res){
    res.push_back(s);
    visited[s] = true;
    for(auto x: adj[s]){
        if(visited[x]==false){
            visited[x] = true;
            dfs(adj, V, x, visited, res);
        }
    }
}


vector<int> dfs(vector<int> adj[], int V, int s){
    vector<int> res;
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            dfs(adj, V, i, visited, res);
    }    
    return res;
}

int main(){
    int V = 4;
    int s = 2; // root node
    vector<int> adj[V];
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    vector<int> bfsTraversal = bfs(adj, V, s);
    vector<int> dfsTraversal = dfs(adj, V, s);
    for(int i=0;i<bfsTraversal.size();i++){
        cout<<bfsTraversal[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<dfsTraversal.size();i++){
        cout<<dfsTraversal[i]<<" ";
    }
}