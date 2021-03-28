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

void point_update(ll index, ll left, ll right, ll query, ll Tree[], ll arr[]){

    if (left==right){       // leaf node
        Tree[index] = arr[left];
    }else{
        ll mid = (ll)(right+left)/2;
        if (query<=mid){
            point_update(2*index+1,left,mid,query,Tree,arr);
        }else{
            point_update(2*index+2,mid+1,right,query,Tree,arr);
        }

        Tree[index] =   min(Tree[2*index+1],Tree[2*index+2]);     // Property
    }

}

int main(){
    ll A[5]={1,2,3,4,5};
    ll Tree[20]={0};
    buildTree(0,0,4,Tree,A);
    A[0]=5;
    point_update(0,0,4,0,Tree,A);
    fo(i,20){
        cout<<Tree[i]<<" ";
    }
    return 0;
}