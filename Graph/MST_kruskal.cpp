#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSets{
    int* parent;
    int* ranks;
    public:
        DisjointSets(int n){
            parent = new int[n];
            ranks = new int[n];
            for(int i=0;i<n;i++){
                parent[i] = i;
                ranks[i] = 0;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(node);
        }
        void makeUnion(int u, int v){
            u = findParent(u);
            v = findParent(v);

            if(ranks[u] < ranks[v]){
                parent[u] = v;
            }
            else if(ranks[u] > ranks[v]){
                parent[v] = u;
            }else{
                parent[u] = v;
                ranks[v]++;
            }
        }
};


class Edge{
    public:
        int source, destination;
        double weight;
    Edge(int source, int destination, double weight){
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

bool comparator(const Edge &e1, const Edge &e2){
    return e1.weight <= e2.weight;
}

class Graph{
    int V, E;
    vector<Edge> edges;
    public:
    Graph(int V, int E){
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w){
        edges.push_back(Edge(u, v, w));
    }

    pair<vector<Edge>, double> kruskal(){
        double minWeight = 0.0;
        vector<Edge> result;
        //step1 sort the edges according to their weights
        sort(edges.begin(), edges.end(), comparator);

        DisjointSets ds(this->V);
        for(auto edge: edges){
            int u = edge.source, v = edge.destination, w = edge.weight;
            int parentU = ds.findParent(u);
            int parentV = ds.findParent(v);
            if(parentU == parentV){
                //u and v are already connected so adding this edge means introducing the new cycle
            }else{
                minWeight += w;
                result.push_back(edge);
                ds.makeUnion(u, v);
            }
        }
        return {result, minWeight};
    }
};

int main(){
    
}