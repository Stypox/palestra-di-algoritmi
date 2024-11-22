#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    if (n>m){
        cout<<-1<<endl;
        return 0;
    }
    for (int y=0; y<n; y++){
        for (int x=0; x<m; x++){

           if(y<=x){
                cout<<".";
           }else{
                cout<<"#";
           }
        }
        cout<<endl;
    }
    return 0;
}