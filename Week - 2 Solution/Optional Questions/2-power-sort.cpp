#include<bits/stdc++.h>
using namespace std;

#define repeat(i,n) for(int i = 0 ; i<n ; i++)

void solve(){
    int n , k ; 
    cin >> n >> k ; 
    vector<int> arr(n) ; 
    repeat(i,n)
        cin >> arr[i] ; 
    
    /*
    Goal : To find subarrays of length k+1, that remains strictly 
    increasing even after multiplying with an sequence of (2*0,..,2*k) in a convulational manner.
    */

    /*
    Apporach : We will keep track in a boolean array whether the curr element < 2*next element 
    */

    vector<bool> valid(n-1,0); 
    repeat(i,n-1)
        if(arr[i] < 2*arr[i+1])
            valid[i] = 1 ; 
    
    // Now find the sequences of 1 
    int curr = 0 , ans = 0 ; 
    repeat(i,n-1){
        if(valid[i]){
            curr += 1 ; 
        }else{
            ans += max(0,curr-(k-1)) ; 
            curr = 0 ; 
        }
    }
    ans += max(0,curr-(k-1)) ; // For the case when whole seq is valid .

    cout << ans << endl ; 
    return ; 
    
}

int main(){
    int t ; cin >> t;
    while(t--)
        solve() ; 
    return 0 ; 
}