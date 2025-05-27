#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool condn_check(vector<ll> &times, ll t, ll time){
    ll num=0;
    for(auto x : times){
        num += time/x;
    }
    return (num >= t);
}


int main(){
    ll n,t;
    cin >> n >> t;
    vector<ll> times;
    for(int i = 0; i < n ; i++){
        ll x;
        cin >> x;
        times.push_back(x);
    }
    sort(times.begin(),times.end());
    ll max_time = times[0]*t;                   // you will certainly take <= time req by fastest machine

    // we will do a binary search from 1 to max_time
    // note that a linear seach may prove to be quite time and computation expensive
    // here we do a modified binary search 
    
    ll left = 1,right = max_time;
    while(left <= right){
        ll mid = (left+right)/2;
        if(!(condn_check(times,t,mid))){
            left = mid+1;
            continue;
        }
        else{
            if(!(condn_check(times,t,mid-1))){
                cout << mid << "\n";
                return 0;
            }
            else{
                right = mid-1;
                continue;
            }
        }
    }

    
}