#include<bits/stdc++.h>
using namespace std;

#define repeat(i,n) for(int i = 0 ; i< n ; i++)

int main(){
    int n , x ; cin >> n >> x ; 
    vector<int> arr(n) ; 

    repeat(i,n)
        cin >> arr[i]  ;

    // We know we can solve the 2 sum problem in O(n) [unordered map] , 3 sum in O(n**2) and 4-sum thus in O(n**3)
    // But we will use to solve in O(n**2) 

    // Approach : Pair -> O(n**2*log(N))
    // Iterate over sum of all pair in the map to find the 2 pair desired

    // Storing vector , because mutiple pair with same sum 
    map<int,vector<pair<int,int>>> mp ;

    repeat(i,n)
        for(int j = i+1 ; j<n ; j++)
            mp[arr[i]+arr[j]].push_back({i,j}) ;
    
    for(auto p : mp){
        auto ptr = mp.find(x-p.first) ;
        if(ptr != mp.end()){
            for(auto v1 : p.second){
                int a1 = v1.first , a2 = v1.second ; 
                for(auto p2 : ptr->second){
                    int a3 = p2.first , a4 = p2.second ; 
                    bool c1 = (a3 == a1 || a3 == a2) , c2 = (a4 == a1 || a4 == a2) ;
                    if(c1 || c2)
                        continue ; 
                    cout << a1+1 << " " << a2+1 << " " << a3+1 << " " << a4+1 << endl ;
                    return 0 ; 
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n" << endl ; 
}