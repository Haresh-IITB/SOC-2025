#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
/*
This is counting question
Please look up the solution if you want to 
know about the logic behind this expression
*/
int main()
{
   ll n;
   cin >> n;
   for(ll i = 1; i <= n; i++){
    ll ans = ((i*i*(i*i - 1))/2 - 4*(i-1)*(i-2));
    cout << ans << "\n";
   }
}