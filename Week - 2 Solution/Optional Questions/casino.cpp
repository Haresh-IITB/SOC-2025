#include<bits/stdc++.h>
using namespace std;

#define repeat(i,n) for(int i = 0; i<n ; i++)
const int INF = 1e9 ; 

long long solve(){
    int n , m ; 
    cin >> n >> m ; 
    vector<vector<int>> cards(n,vector<int>(m)) ;
    repeat(i,n)
        repeat(j,m)
            cin >> cards[i][j] ;
    
    if(n == 1)
        return 0 ; // Only one player

    // Naive Solution : O(n**2*m) -> just go over all the pairs 1e5*1e5 => 1e10
    // Naive solution will exceed the time limit 
    
    // Observation : We have to add all the values at the end 
    // So, sorting individuallt the columns and then adding up for pairs also works
    // So you can once sort individually and will see a pattern evolve, let's sort in decreaing order
    // Sum :
    // a1 - a2 , a1 - a3 , ... a1 - ak 
    // a2 - a3 , a2 - a4 , a2 - a5 , ... a2 - ak
    // ...
    // ak-1 - ak 

    // All these pattern column wise and you will see
    // a1-ak + (a1+a2 - ak-1-ak-2) + (a1+a2+a3 - ak - ak-1 - ak-2) + ... (a1+a2+....ak-1 - (ak + ak-1+ ... a2))
    // (k-1)*(a1-ak) + (k-3)*(a2-a[k-1]) + (k-5)*(a3-a[k-2]) + ... + (k-(2*i-1))*(ai - a(k-i+1)) until 
    // k > (2*i-1) => i < k/2  [in 0 based indexing]    
    long long sum = 0 ; 

    // Sorting column wise with a set 
    vector<multiset<int>> ms(m) ; 
    repeat(i,n)
        repeat(j,m)
            ms[j].insert(cards[i][j]) ; 

    repeat(i,m){
        auto ptr = ms[i].begin() ;
        auto ptr_end = ms[i].rbegin() ;
        for(int j = 0 ; j<n/2 ; j++){
            int v1 = *ptr , v2 = *ptr_end ; 
            long long temp = (v2-v1) ;
            temp *= (n-(2*j+1)) ;
            sum += temp ;
            ptr = next(ptr) ; ptr_end = next(ptr_end) ; // Increment the pointers 
        }
    }

    return sum ; 

}   

int main(){
    int t ; cin >> t ; 
    while(t--){
        cout << solve() << endl ; 
    }
}