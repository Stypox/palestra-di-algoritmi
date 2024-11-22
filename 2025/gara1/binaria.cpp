#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unsigned long long int total=0;
    for(int i=0; i<n; i++){
        unsigned long long int cur;
        cin>>cur;
        int h=0;
        unsigned long long int copy = cur;
        while(copy>0){
            h=h+1;
            copy=copy/2;
        }

        unsigned long long int pow = ((unsigned long long int) 1)<<h;
        
        total+=pow-1-cur;
        
    }
    cout<<total<<endl;
    return 0;
}