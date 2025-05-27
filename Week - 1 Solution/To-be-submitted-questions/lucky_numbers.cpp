#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
Brute force is the only way but there is a smart way to 
not exceed the time complexity
Observe that whenever r-l >= 100 there exists a number which has both 9 and 0 in
it. Argue for the logic in this case.
Rest is brute force
*/
vector<int> extract_digits(int x){
    vector<int> dig;
    while(x > 0){
        dig.push_back(x - (x/10)*10);
        x /= 10;
    }
    return dig;
}
void solve()
{
    int l,r;
    cin >> l >> r;
    if(r-l >= 100){
        if(l%100 > 90){
            cout << (l+100) - (l)%100 + 90 << "\n";
        }
        else{
            cout << l+90-l%100 << "\n";
        }
        return;
    }
    int luck_max = INT_MIN;
    int num = l;
    for(int i = l; i < r+1;i++){
        vector<int> tmp;
        tmp = extract_digits(i);
        sort(tmp.begin(),tmp.end());
        // cout << tmp[0] << tmp[1];
        int luck = tmp[tmp.size()-1] - tmp[0];
        if(luck > luck_max){
            luck_max = luck;
            num = i;
        }
        if(luck_max == 9){
            break;
        }
    }
    cout << num << "\n";
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