#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define fo(i,n)             for(ll i=0;i<n;i++)
#define fo_vector(i,G)      for (auto& i : G)
#define INF (ll)10e9

void buildTree(ll index, ll left, ll right, ll Tree[], ll arr[]){

    if (left==right){       // leaf node
        Tree[index] = arr[left];
    }else{
        ll mid = (ll)(right+left)/2;
        buildTree(2*index+1, left, mid, Tree, arr);
        buildTree(2*index+2, mid+1, right, Tree, arr);

        Tree[index] =   Tree[2*index+1] + Tree[2*index+2];     // Property
    }

}

ll lazy_query(ll index, ll left, ll right, ll Q_left, ll Q_right, ll Tree[], ll Lazy[]){

    if (Lazy[index]!=0){

        Tree[index]+=Lazy[index]*(right-left+1);
        
        if (right!=left){
            Lazy[2*index+1] += Lazy[index];
            Lazy[2*index+2] += Lazy[index];
        }
        Lazy[index] = 0;

    }

    if (Q_left>right || Q_right<left ) 
        return 0;        // suitable according to property

    if (left>=Q_left && Q_right>=right){
        return Tree[index];
    }

    ll mid = (ll)(right+left)/2;
    ll l = lazy_query(2*index+1, left, mid, Q_left, Q_right, Tree, Lazy);
    ll r = lazy_query(2*index+2, mid+1, right, Q_left, Q_right, Tree, Lazy);

    return l+r;

}

void lazy_update(ll index, ll left, ll right, ll Q_left, ll Q_right, ll val, ll Tree[], ll Lazy[]){

    if (Lazy[index]!=0){

        Tree[index]+=Lazy[index]*(right-left+1);
        
        if (right!=left){
            Lazy[2*index+1] += Lazy[index];
            Lazy[2*index+2] += Lazy[index];
        }
        Lazy[index] = 0;

    }

    if (Q_left>right || Q_right<left ) 
        return ;        // Just leave it is out of range

    if (left>=Q_left && Q_right>=right){

        Tree[index]+=val*(right-left+1);
        
        if (right!=left){
            Lazy[2*index+1] += val;
            Lazy[2*index+2] += val;
        }
        return;
    }

    ll mid = (ll)(right+left)/2;
    lazy_update(2*index+1, left, mid, Q_left, Q_right, val, Tree, Lazy);
    lazy_update(2*index+2, mid+1, right, Q_left, Q_right, val, Tree, Lazy);
    Tree[index] = Tree[2*index+1] + Tree[2*index+2];
    return;


}


int main(){
    
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    ll A[5]={0};
    ll Tree[20]={0}, Lazy[20]={0};
    buildTree(0,0,4,Tree,A);
    lazy_update(0,0,4,1,4,2,Tree,Lazy);
    lazy_update(0,0,4,0,1,3,Tree,Lazy);
    cout<<lazy_query(0,0,4,0,0,Tree,Lazy)<<" "<<lazy_query(0,0,4,1,1,Tree,Lazy)<<" "<<lazy_query(0,0,4,2,2,Tree,Lazy)<<" "<<lazy_query(0,0,4,3,3,Tree,Lazy)<<" "<<lazy_query(0,0,4,4,4,Tree,Lazy)<<" ";
    return 0;
}