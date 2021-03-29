#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define fo(i,n)             for(ll i=0;i<n;i++)
#define fo_vector(i,G)      for (auto& i : G)
#define vi                  vector<int>
#define pb                  push_back
#define INF                 (ll)10e9

void buildTree(ll index, ll left, ll right, vi Tree[], ll arr[]){

    if (left==right){       // leaf node
        Tree[index].pb(arr[left]);
    }else{
        ll mid = (ll)(right+left)/2;
        buildTree(2*index+1, left, mid, Tree, arr);
        buildTree(2*index+2, mid+1, right, Tree, arr);

        ll i=0, j=0;
        while (i<Tree[2*index+1].size() && j<Tree[2*index+2].size()){

            if (Tree[2*index+1][i]<Tree[2*index+2][j]){
                Tree[index].pb(Tree[2*index+1][i++]);
            }else{
                Tree[index].pb(Tree[2*index+2][j++]);
            }

        }
        while (i<Tree[2*index+1].size())
        {
            Tree[index].pb(Tree[2*index+1][i++]);
        }
        while (j<Tree[2*index+2].size())
        {
            Tree[index].pb(Tree[2*index+2][j++]);
        }
        
    }

}

int main(){
    
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    ll A[5]={1,2,3,4,5};
    vi Tree[20];
    buildTree(0,0,4,Tree,A);
    fo(i,20){
        if (Tree[i].size()>0){
            cout<<i<<"->";
            fo_vector(j,Tree[i]){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}