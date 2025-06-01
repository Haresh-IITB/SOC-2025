#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ; 
using namespace std;

typedef pair<int,int> pii ; 

template <class T>
using ordered_multiset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define repeat(i,n) for(int i = 0 ; i<n ; i++)

int main(){
    int n ; cin >> n ; 
    // Approach , consider the intervals in increasing order of finish time 
    // This gaurantess that if we are processing the ith interval then it is not contained in any other interval 
    // So we only need to update the count of the ith interval 
    // To do , we can have a multiset of the start time of intervals (1,...i-1) and see how many have start time >= our start time 
    // Now we certainely know that there finish time <= our finish time, thus they are contained in our interval
    // In case of same start time we will first consider the one with greater start time 

    vector<pair<int,int>> intervals(n) ; 
    repeat(i,n)
        cin >> intervals[i].first >> intervals[i].second ; 
    
    // Solving for how many ranges are contained in this interval 

    // This maps the original indices to the sorted indices used for printing purpose
    vector<int> indices(n) ; 
    iota(indices.begin(),indices.end(),0) ; 
    auto cmp = [&](const int a_idx , const int b_idx){
        pair<int,int> & a = intervals[a_idx] ;  
        pair<int,int> & b = intervals[b_idx] ;  
        if(a.second == b.second) 
            return a.first > b.first ; 
        return a.second < b.second ; 
    };
    sort(indices.begin(),indices.end(),cmp) ; 

    // Sorting of intervals using sorted indices, better than calling sort again as it is O(n)
    vector<pair<int,int>> sorted_intervals(n) ; 
    repeat(i,n)
        sorted_intervals[i] = intervals[indices[i]] ; 

    ordered_multiset<pii> s; 
    vector<int> nested_count(n) ; 
    repeat(i,n){
        nested_count[indices[i]] =  (int)s.size() - s.order_of_key({sorted_intervals[i].first,-1}); 
        s.insert({sorted_intervals[i].first,i}) ; 
    } 

    repeat(i,n)
        cout  << nested_count[i] << " " ; 
    cout << endl ; 
    
    
    // Counting in how many ranges the given intervals is contained in 
    iota(indices.begin(),indices.end(),0) ; 
    auto cmp2 = [&](const int a_idx , const int b_idx){
        pair<int,int> & a = intervals[a_idx] ;  
        pair<int,int> & b = intervals[b_idx] ;  
        if(a.first == b.first) 
            return a.second > b.second ; 
        return a.first < b.first ; 
    };
    sort(indices.begin(),indices.end(),cmp2) ; 

    // Sorting of intervals using sorted indices, better than calling sort again as it is O(n)
    repeat(i,n)
        sorted_intervals[i] = intervals[indices[i]] ; 

    ordered_multiset<pii> s2 ; 
    repeat(i,n){
        nested_count[indices[i]] =(int) s2.size() - (s2.order_of_key({sorted_intervals[i].second,-1}));  
        s2.insert({sorted_intervals[i].second,i}) ; 
    } 

    repeat(i,n)
        cout  << nested_count[i] << " " ; 
    cout << endl ; 
    return 0 ; 

}