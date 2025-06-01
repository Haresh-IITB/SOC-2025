#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds ; 

template<typename T>
using balanced_bst = tree<
    T, // key type
    null_type, // value type (used for maps)
    less<T>, // comparator type
    rb_tree_tag, // Tree type rb tree [It is a balanced tree]
    tree_order_statistics_node_update
>;
#define repeat(i,n) for(int i = 0 ; i< n ; i++)
typedef pair<int,int> pii ; 

int main(){
    int n , k ; cin >> n >> k ;
    vector<int> arr(n) ; 
    repeat(i,n)
        cin >> arr[i] ; 
    // Even -> Median smaller of two 
    // Odd -> Median middle value in that window

    // We can use a policy based structure here a RB tree with find_by_order function 
    // This will allow to retain the median in O(n*logn)

    balanced_bst<pii> bst ; 

    repeat(i,k)
        bst.insert({arr[i],i}) ; 
    
    vector<int> median ; 

    for(int i = 0 ; i<n-k+1 ; i++){
        if(k%2){
            auto ptr = bst.find_by_order(k/2) ; 
            int v1 = (*ptr).first ;
            median.push_back(v1) ; 
        }
        else{
            auto p1 = bst.find_by_order(k/2) ; 
            auto p2 = bst.find_by_order((k/2)-1) ; 
            int v1 = (*p1).first , v2 = (*p2).first ;
            median.push_back(min(v1,v2)) ; 
        }
        bst.erase(bst.find({arr[i],i})) ; // Erase the element going from the window
        if(i<n-k)
            bst.insert({arr[i+k],i+k}) ;
    }

    for(auto med : median)
        cout << med << " " ; 

    cout << endl ; 
}   