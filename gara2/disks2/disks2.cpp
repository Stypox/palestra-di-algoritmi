#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin>>n>>t;
    int prev=24;
    for(int a=0; a<n; a++){
        int s, e;
        cin>>s>>e;
        //printf("%d %d\n", a, 24-prev+s );
        if(24-prev+s>=t){
            cout<<a-1<<endl;
            return 0;
        }
        prev=e;
    }
    cout<<-1<<endl;
}