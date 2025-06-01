#include<bits/stdc++.h>
using namespace std;

#define repeat(i,n) for(int i = 0 ; i<n ; i++)

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    repeat(i,n)
        cin >> arr[i] ; 

    // Observation : If the array is sorted, answer is 0 
    // Think about the last operation if the array is not sorted it must be an operation on (1,n)
    // Now after this operation you will be left with the subarray (2,...,n-1)
    // Now either this is sorted or you need to make a operation of (2,n) at the end which will
    // be earlier followed by sorting of(k,....,n-k+1)

    // How to efficiently find the k such that (k,....,n-k+1) is sorted
    // If you find this then the answer would be k-1 operations

    // We could use binary search, because if we kind a particular k to be sorted then (k+1,...n-k) is also sorted
    // If we get a sorted array for k , then decrease the k to search for a larger sorted array
    // Else , increase the k and search for a shorter array 
    // Base cases : A single element or element of 0 length is sorted 

    // To check the sorted order we would need a way to store the positions 
    map<int,int> pos ;

    for(int i = 0 ; i<n ; i++)  
        pos[arr[i]] = i + 1; 

    int s = 1, e = n/2 , ans = 0 ;
    for(int m = (s+e)/2 ; s<=e ; m = (s+e)/2 ){
        // m -> k
        cout << "Stuck in the while loop with " << m << " " << s << " " << e << " " << endl; 
        bool is_sorted = true ; 
        for(int i = 1 ; i<= (n-2*m+1) ; i++) 
            if(pos[m] > pos[++m]){
                is_sorted = false ; break ; 
            }
        
        if(is_sorted){
            e  = m-1 ; 
            ans = m ; 
        }
        else
            s = m + 1 ; 
    }
    cout << ans - 1 << endl ; 
    return ;  
}

int main(){
    int t ; cin >> t ; 
    while(t--){
        solve() ; 
    }
    return 0 ;
}