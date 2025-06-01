#include<bits/stdc++.h>
using namespace std;

#define repeat(i,n) for(int i = 0 ; i<n ; i++)

int main(){
    int n , q ; 
    cin >> n >> q ; 

    set<int> blank_x , blank_y ; 
    repeat(i,n){
        blank_x.insert(i+1) ; blank_y.insert(i+1) ;
    }

    vector<int> rooks_x(n,0);
    vector<int> rooks_y(n,0);

    repeat(i,q){
        int t ; 
        cin >> t ; 

        if(t == 1){
            int x, y ; cin >> x >> y ; 
            rooks_x[x-1] ++   ; rooks_y[y-1] ++ ; 
            if(rooks_x[x-1] == 1)
                blank_x.erase(x) ;
            if(rooks_y[y-1] == 1)
                blank_y.erase(y) ;
        }
        
        if(t == 2){
            int x, y ; cin >> x >> y ; 
            rooks_x[x-1] --  ; rooks_y[y-1] -- ; 
            if(rooks_x[x-1] == 0)
                blank_x.insert(x) ;
            if(rooks_y[y-1] == 0)
                blank_y.insert(y) ;

        }

        if(t == 3){

            int x1 , x2 , y1 , y2 ; 
            cin >> x1 >> y1 >> x2 >> y2 ; 
            if(x1 > x2)
                swap(x1,x2) ; 
            if(y1>y2)   
                swap(y1,y2) ; 
            
            bool all_x = 1 ; 
            auto ptr = blank_x.lower_bound(x1) ; 
            if(ptr == blank_x.end() || *ptr <= x2)
                all_x = 0 ;

            bool all_y = 1 ;
            ptr = blank_y.lower_bound(y1) ;
            if(ptr == blank_y.end() || *ptr <= y2)
                all_y = 0 ;

            if(all_x || all_y)
                cout << "Yes\n" ; 
            else
                cout << "No\n" ; 
        }
    }

}