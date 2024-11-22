#include<bits/stdc++.h>

using namespace std;

int n,mod;
vector<int> output;
int prec=0;
int point=0;

void add(int val){
    point+=abs(val -prec);
    prec=val;
    output.push_back(val);
    //cout<<point<<" ";
}

int round(int val, int res){
    return ((val-res)/mod)*mod+res;
}

int exp(int cur, int pos){
    int last;
    if(round(pos+2*mod, cur)<n){
        int start = pos = round(pos+2*mod, cur);
        while(pos>0){
            add(pos);
            last=pos;
            pos-=mod;
        }
        pos=start+mod;
        while(pos<n){
            add(pos);
            last=pos;
            pos+=mod;
        }
    }else{
        int start = pos = round(pos-mod, cur);
        while(pos<n){
            add(pos);
            last=pos;
            pos+=mod;
        }
        pos=start-mod;
        while(pos>0){
            add(pos);
            last=pos;
            pos-=mod;
        }
    }
    return last;
}

int main(){
    
    cin>>n>>mod;
    for(int a=0; a<n; a+=mod){
        add(a);
    }
    
        
    int last=round(n-1, 0);
    for(int a=mod-1; a>0; a--){
        last=exp(a, last);
    }
    
    
    cout<<point<<endl;
    for(int a=0; a<n; a++){
        cout<<output[a]<<" ";
    }
}