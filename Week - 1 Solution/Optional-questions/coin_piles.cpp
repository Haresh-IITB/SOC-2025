#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve()
{
    ll left, right;
    cin >> left >> right;

    
    // type1 + 2type2 = left
    // 2type1 + type2 = right
    // type1 = (2right - left)/3
    // type2 = (2left - right)/3
    if((2*right - left)%3 != 0){
        cout << "NO\n";
        return;
    }
    if((2*left - right)%3 != 0){
      cout << "NO\n";
        return;
    }
    if( (2*left - right < 0) || (2*right - left < 0)){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
int t; 
cin >> t;
while(t--)
{
solve();
}
}