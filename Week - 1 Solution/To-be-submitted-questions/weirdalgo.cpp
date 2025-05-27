#include <iostream>
using namespace std;
/*
Check out the veritasium video on Collatz conjecture
This is a fairly simple question, but there is one catch
The input you take must be of type long long
This is point you should remember always and 
this catch will be repeated in a lot of future questions

*/
int main(){
    long long n;
    cin >> n;
    cout << n << " ";
    while( n != 1){
        if(n % 2 == 0){
            n /= 2;
            cout << n << " ";
        }
        else{
            n = 3*n + 1;
            cout << n << " ";
        }

    }
    cout << "\n";
}