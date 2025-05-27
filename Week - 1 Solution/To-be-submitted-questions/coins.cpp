/*
The following code format is quite common for codeforces contests
I suggest you to make your own boiler plate as it comes in handy
Using this code you just have to write all your code up as a function solve()
which will be called appropriate number of times
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
This is a basic number theory problem
The key concept is-
sum of two evens is always even
sun of two odds is always even
sun of an even and an odd is odd
*/

void solve()
{
    ll n,k;
    cin >> n >> k;
    if(n % 2 == 0){
        cout << "YES\n";                // if n is even, k is irrelevant you can take appropriate x
        return;
    }
    else{
        if(k % 2 == 0){
            cout << "NO\n";                 // if n is odd but k is even there is definitely no possible soln (why?)
            return;
        }
        else{
            if(k > n) cout << "NO\n";       // this isn't particularly necessary as the question already mentions k <= n
            else cout << "YES\n";               // if k and n both are odd take y = 1 and choose appropriate x
        }
    }

}
/*
Sometimes we try to find a solution when all
we are required to do is to comment on the existence of it
Checking all possible (x,y) pairs is a common mistake we tend to do
*/
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