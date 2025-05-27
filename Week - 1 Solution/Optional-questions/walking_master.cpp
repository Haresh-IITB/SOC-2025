#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Say we make 't' top-right steps and 'l' left steps
then 
x_net = t - l
y_net = t

what remains is to see if none of t and l is negative, which would mean such a transition is impossible
with the given constraints

*/
void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int x_net = c - a;
    int y_net = d - b;
    int t = y_net;
    int l = t - x_net;
    if((t < 0) || (l < 0)){
        cout << -1 << "\n";
    }
    else{
        cout << t + l << "\n";
    }
    
    
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