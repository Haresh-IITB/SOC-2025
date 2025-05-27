#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;       // this is a way to define "aliases in C++
                            // check the use of keyword "typedef" if you don't know already


/*
This is a simple problem
Get yourself familiar with such problems
as further complex problems will include such sub-problems
Also check out the "string" library and it's functions they come in handy

*/
int main(){
    string s;
    cin >> s;
    ll count_max = 0;
    ll count = 1;

    // iterate over the string-

    for(ll i = 1 ; i < s.size(); i++){
        if(s[i-1] == s[i]){                         //check if current char is same as it's previous one
            count++;                                // increment counter if it is
        }
        else{
            count_max = max(count_max,count);          // if not then reset the counter and set count_max appropriately
            count = 1;
        }
    }
    count_max = max(count_max,count);               // this takes care of case where we have a string of all same chars
    cout <<  count_max << "\n";
}