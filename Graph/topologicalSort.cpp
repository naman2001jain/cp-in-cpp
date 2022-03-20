#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    void topologicalSort(vector<bool> &visited, vector<int> &result, int node){
        visited[node] = true;
        for(auto x: adj[node]){
            if(!visited[x]){
                topologicalSort(visited, result, x);
            }
        }
        result.push_back(node);
    }

    vector<int> topologicalSort(){
        vector<int> result;
        vector<bool> visited(V, false);
        for(int i=0;i<this->V;i++){
            if(!visited[i]){
                topologicalSort(visited, result, i);
            }
        }
        //reversing the result
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){

}