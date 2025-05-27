#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
/*
We sort the input weights 
And then we pair up the heaviest and lightest available kids together
The technique used is called two pointer method
It is a very important and standard technique used
it is highly recommended and you look it up and 
solve some more questions on it as well
*/
int main(){
    int n;
    ll x;
    vector<ll> wts;
    cin >> n >> x;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        wts.push_back(tmp);
    }
    
    sort(wts.begin(),wts.end());
    int right = wts.size()-1, left = 0;
    while(left < right){
        if(wts[left] + wts[right] <= x){
            cnt++;
            left++;
            right--;
            continue;
        }
        else{
            cnt++;
            right--;
        }
    }
    if(left == right){
        cnt++;
    }
    cout << cnt << "\n";
}