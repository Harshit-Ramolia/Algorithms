#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define fo(i,n)             for(ll i=0;i<n;i++)
#define fo_vector(i,G)      for (auto& i : G)
#define vi                  vector<ll>
#define pb                  push_back

#define N 10
vector<ll> Graph[N];

void addEdge_bidirectional(vector<ll> Graph[], ll a, ll b){

    Graph[a].push_back(b);
    Graph[b].push_back(a);

}

void addEdge_unidirectional(vector<ll> Graph[], ll a, ll b){

    Graph[a].push_back(b);

}

void reset_adjacency_list(vector<ll> Graph[]){

    fo(i,N){
        Graph[i].clear();
    }

}

void print_adjacency_list(vector<ll> Graph[]){

    fo(i,N){
        cout<<i<<" -> ";
        fo_vector(vertex,Graph[i]){
            cout<<vertex<<" -> ";
        }
        cout<<"\n";
    }   

}

void DFS_recursive(ll root, vi Graph[], bool visited[]){
    visited[root] = true;
    cout<<root<<" ";

    fo_vector(i,Graph[root]){
        if(!visited[i]){
            DFS_recursive(i,Graph,visited);
        }
    }
}

void Depth_First_Search(ll root, vi Graph[]){

    bool visited[N] = {false};    
    DFS_recursive(root,Graph,visited);
}

int main(){

    reset_adjacency_list(Graph);
    addEdge_bidirectional(Graph,0,1);
    addEdge_bidirectional(Graph,0,2);
    addEdge_bidirectional(Graph,1,2);
    addEdge_bidirectional(Graph,2,3);
    addEdge_bidirectional(Graph,3,3);
    Depth_First_Search(2, Graph);
    return 0;
}