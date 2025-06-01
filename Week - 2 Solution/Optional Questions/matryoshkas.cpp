#include<bits/stdc++.h>
using namespace std;

#define repeat(i,n) for(int i = 0 ; i<n ; i++)

void solve(){
    int n ; cin >> n ;
    multiset<int> arr ;
    repeat(i,n){
        int temp ; cin >> temp ; 
        arr.insert(temp) ;
    }

    // Alternative instead of this you could have also used a hash map to keep track of the same 
    multiset<int> answer ; // This marks the top of every set present till now 
    for(auto itr = arr.begin() ; itr != arr.end() ; itr ++){
        if(answer.find(*itr-1) != answer.end()){
            /*
            Erase by iterator not by value as this , will not erase all 
            the occurence of the values but erasing by value will do so
            */
            answer.erase(answer.find(*itr-1)) ; 
            answer.insert(*itr) ; // Marking the new top  
        }
        else
            answer.insert(*itr) ;
    }

    cout << answer.size() << endl ; 
    return ; 
}

int main(){
    int t ; cin >> t ;
    while(t--){
        solve() ; 
    }
}