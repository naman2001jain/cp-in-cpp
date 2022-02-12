#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        //for undirected graphs one extra line should be added as follows
        adj[v].push_back(u);
    }

    void DFSUtil(int u,vector<bool> &visited){
        visited[u] = true;
        cout<<u<<" ";
        list<int>::iterator itr;
        for(itr=adj[u].begin(); itr != adj[u].end();itr++){
            if(!visited[*itr]){
                DFSUtil(*itr, visited);
            }
        }
    }


    void DFS(){
        vector<bool> visited(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFSUtil(i, visited);
            }
        }
    }


    void BFS(int u){
        list<int> q;
        vector<bool> visited(V, false);
        q.push_back(u);
        visited[u] = true;
        while(!q.empty()){
            int temp = q.front();
            cout<<temp<<" ";
            q.pop_front();
            list<int>::iterator itr;
            for(itr = adj[temp].begin(); itr!=adj[temp].end();itr++){
                if(visited[*itr]==false){
                    q.push_back(*itr);
                    visited[*itr] = true;
                }
            }
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    g.addEdge(1,4);
    g.BFS(0);
    
}