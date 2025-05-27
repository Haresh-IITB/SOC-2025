#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <cmath>
vector<ll> extract_digits(ll x){
    vector<ll> dig;
    while(x > 0){
        dig.push_back(x - (x/10)*10);
        x /= 10;
    }
    return dig;
}

/*
We first find the number of digits of the number in question
This can be easily done by noting that 
there are
9 - 1 digit numbers
90 - 2 digit numbers
.
.
.
.....
By noting this pattern a simple while loop gives us the number of digits of
the number in question
Then we simply find how many numbers of these many digits are further completely passed
and then which digit is to be reported by using the modulus function

A sample run for input 401 is shown using comments
*/
void solve()
{
    ll k;
    cin >> k;           // k = 401
    
    ll i = 1;
    ll p = 9;
    ll dig = 0;
    while((k - i*p) > 0){
        k -= i*p;
        i++;
        p *= 10;
        dig++;

    }
                        // After this while loop k = 212 and dig = 2 (that is all one and 2 digit numbers
                        // have been passed and now we want 212th digit starting from the first 3 digit number)


        // cout << k << dig << endl;
    ll first = pow(10,dig)+0.5;         // first 3 digit number = 100
    ll passed_nums = k/(dig+1);     // how many of 3 digit numbers are further passed = 212/3 = 70
    ll curr = first + passed_nums - 1;      // After passing them which number are we currently at = 169
    ll residue = k%(dig+1);                 // new value of k = 2
    
    if(residue == 0){                   // if we have exactly passed all numbers our answer is unit digit of curr
        vector<ll> ans;
        ans = extract_digits(curr);
        cout << ans[0] << "\n";
        return;
    }
    else{
        vector<ll> ans;                     // else the answer is residueth digit from left of curr+1
        ans = extract_digits(curr+1);
        cout << ans[ans.size()-residue] << "\n";    // our output is 2nd digit of 170
        return;
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