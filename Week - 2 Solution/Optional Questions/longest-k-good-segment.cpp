#include<bits/stdc++.h>
using namespace std;

#define repeat(i,n) for(int i = 0 ; i<n ; i++)

int main(){
    int n , k ; 
    scanf("%d %d", &n , &k) ;

    // k-good-segment => <=k distinct elements 
    vector<int> arr(n) ; 
    repeat(i,n)
        scanf("%d",&arr[i]) ;

    // Using unorederd , because avg cost is O(1)
    unordered_set<int> s; 
    unordered_map<int,int> mp ; pair<int,int> bp ;
    
    int curr = 0 , best = - 1 , start = 0 ; 

    repeat(i,n){

        s.insert(arr[i]) ;
        mp[arr[i]] += 1;

        if(s.size() > k){
            // Update the length 
            curr = (i-start) ; 
            if(best < curr){
                bp = {start,i-1} ; 
                best = max(best,curr) ;
            }

            // Find the index removing which will make your number of unique element <= k ;
            // Basically moving your start pointer unless you land at a position which is count no more than one in the set   
            while(mp[arr[start]]>1){
                mp[arr[start]] -- ; start ++ ;
            }

            // Remove this element and mark the index after it as a new start 
            s.erase(arr[start]) ; mp[arr[start]] -- ; 
            start ++ ; 
        }
    }

    // Last update in case whole array had <= k distinct elements 
    curr = (n-start) ; 
    if(best < curr){
        bp = {start,n-1} ; 
        best = max(best,curr) ;
    }

    printf("%d %d\n",bp.first+1,bp.second+1) ; 

    // Overall complexity : O(n) as the each element is added and removed at most once in the set and in the map
    // Space : O(n)

    return 0 ; 
}