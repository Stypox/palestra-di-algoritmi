#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin>>n;

    int val[n];
    
    for(int a=0;a<n;a++){
        cin>>val[a];
    }
    int prec=0;
    int cur=0;
    int maxi=0;
    for(int a=0;a<n;a++){
        int tmp;
        cin>>tmp;

        if(tmp==1&&prec<=val[a]){
            cur+=val[a];
        }else{
            if(tmp==0){
                cur=0;
            }else{
                cur=val[a];
            }
            
        }

        maxi=max(cur, maxi);
        prec=val[a];
    }
    cout<<maxi;
}