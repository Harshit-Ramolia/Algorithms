#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define fo(i,n)             for(ll i=0;i<n;i++)
#define fo_vector(i,G)      for (auto& i : G)

void buildTree(ll index, ll left, ll right, ll Tree[], ll arr[]){

    if (left==right){       // leaf node
        Tree[index] = arr[left];
    }else{
        ll mid = (ll)(right+left)/2;
        buildTree(2*index+1, left, mid, Tree, arr);
        buildTree(2*index+2, mid+1, right, Tree, arr);

        Tree[index] =   min(Tree[2*index+1],Tree[2*index+2]);     // Property
    }

}

ll query(ll index, ll left, ll right, ll Q_left, ll Q_right, ll Tree[]){

    if (Q_left>right || Q_right<left ) 
        return 20;        // suitable according to property
    if (left>=Q_left && Q_right>=right){
        return Tree[index];
    }

    ll mid = (ll)(right+left)/2;
    ll l = query(2*index+1, left, mid, Q_left, Q_right, Tree);
    ll r = query(2*index+2, mid+1, right, Q_left, Q_right, Tree);

    return min(l,r);
}

int main(){
    ll A[5]={1,2,3,4,5};
    ll Tree[20]={0};
    buildTree(0,0,4,Tree,A);
    cout<<query(0,0,4,2,4,Tree)<<" "<<query(0,0,4,1,2,Tree)<<" "<<query(0,0,4,3,3,Tree)<<" ";
    return 0;
}