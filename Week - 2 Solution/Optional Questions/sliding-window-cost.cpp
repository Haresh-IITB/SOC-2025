#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds ;
using namespace std;

template <typename T>
using balanced_bst = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update
> ; 
typedef pair<int,int> pii ;
typedef long long ll ;
#define repeat(i,n) for(int i = 0 ; i<n ; i++)

int main(){
    int n, k ; cin >> n >> k ; 
    vector<int> arr(n) ;

    repeat(i,n)
        cin >> arr[i] ; 

    // We have to make each value the same in the window 
    // And for each window we need a logk way to update

    // We want to minimize sigma[i = 1 to N] (|xi-x|)
    // Where x is the new value of each element 
    // We know that for the sum to be minimum x is the median 
    
    // So the problem in some sense reduces to get the sliding median 
    // window 

    // Let's give a run of our approach 
    // arr : [2, 4, 3, 5, 8, 1, 2, 1]
    // k = 3
    // median : [3,4,5,5,2,1] , cost : [2,2,5,7,7,1] // So this approach is indeed correct 
    
    // For even the median can be anything from [xk-1,xk] // We will chose xk 

    vector<ll> cost(n-k+1,0) ;
    // Maintain 2 bst, we need a lag of 1 element : more clearer see below implementation
    balanced_bst<pii> bst ; 

    // Add the first k elements
    repeat(i,k)
        bst.insert({arr[i],i}) ;
    
    // Calculate the cost for first window 
    int prev_median , curr_median ;
    auto ptr = bst.find_by_order(k/2) ; // Median 
    curr_median = (*ptr).first ; 

    repeat(i,k)
        cost[0] += abs(arr[i]-curr_median) ;

    repeat(i,n-k){
        // Erase the prev _element and add the new element
        bst.erase(bst.find({arr[i],i})) ; 
        bst.insert({arr[i+k],i+k}) ; 
        prev_median = curr_median ; 
        auto ptr = bst.find_by_order(k/2) ; 
        curr_median = (*ptr).second ; 
        
        // Sum wrt to the old median 
        cost[i+1] = cost[i] - abs(arr[i] - prev_median) + abs(arr[i+k] - prev_median) ;  

        int cnt_lo = bst.order_of_key({prev_median + 1 , -1});
        int cnt_high = k - cnt_lo ;

        // Now for all elements who <= cnt_lo and <= 
    }

    repeat(i,n-k+1)
        cout << cost[i] << " " ; 
    cout << endl ; 

    return 0; 
}

// arr : [2,4,3,5,8,1,2,1]
// HEAP : [(2,1),(4,2),(3,3)] -> (4,2) 
// HEAP : push [(5,4)] -> (5,4)
// HEAP -> push (8,5) -> (8,5)
// HEAP -> push (1,6) -> (8,5)
// HEAP -> push (2,7) ->  (8,5) pop -> (5,4) -> pop , (3,3) -> pop , (2,7) 
// HEAP -> push (1,8) -> (2,7) pop

// [2,4,3] -> 4 , [5] , 