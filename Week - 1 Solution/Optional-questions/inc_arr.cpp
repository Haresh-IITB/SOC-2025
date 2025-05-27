#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll moves = 0;
    for(int i = 1;i<n;i++){
        moves += (arr[i]-arr[i-1] < 0) ? arr[i-1]-arr[i] : 0;
        arr[i] = (arr[i] < arr[i-1]) ? arr[i-1] : arr[i];
    }
    cout << moves << '\n';

}