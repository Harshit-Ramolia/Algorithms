#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define fo(i,n)             for(ll i=0;i<n;i++)
#define fo_vector(i,G)      for (auto& i : G)


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

int main(){

    reset_adjacency_list(Graph);
    addEdge_bidirectional(Graph,0,1);
    addEdge_bidirectional(Graph,3,1);
    addEdge_bidirectional(Graph,4,7);
    addEdge_bidirectional(Graph,4,3);
    addEdge_bidirectional(Graph,2,1);
    
    return 0;
}