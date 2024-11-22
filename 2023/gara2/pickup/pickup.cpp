#include<bits/stdc++.h>

using namespace std;
#define int int64_t

map<int, int> dp[301] [300]; //b rimanenti / mod prec / cifre tot

int mod, k;

int calc(int b, int modprec, int cifre){
    if(b==0){
        if(modprec==0&&cifre==0)
            return 1;
        else 
            return 0;
    }
    auto tmp = dp[b][modprec].find(cifre);
    
    if(tmp!=dp[b][modprec].end()){
        return (*tmp).second;
    }
    if(cifre*9<b||cifre>b) 
        return 0;
    int modi=0;
    for(int a=1;(a<=9)&&(b>=a); a++){
        modi+=calc(b-a, (modprec*10+a)%mod, cifre-1);
    }
    dp[b][modprec][cifre]=modi;
    return modi;
}


void expl(int b, int modprec, int cifre, int low){
    //printf("expl %ld %ld %ld %ld\n", b, modprec, cifre, low);
    
    if(b==0){
        return;
    }
    int modi=0;
    for(int a=1;(a<=9)&&(b>=a); a++){
        int cur=calc(b-a, (modprec*10+a)%mod, cifre -1);
        //printf("%ld %ld %ld/%ld: %ld\n", b, modprec, low, a, cur);
        if(low+modi+cur>=k){
            cout<<a;
            expl(b-a, (modprec*10+a)%mod, cifre-1, low+modi);
            return;
        }
        modi+=cur;
    }
}

signed main(){
    int b;
    cin>>mod>>b>>k;
    int modi=0;
    //erase(b, 0);
    for(int i=1; i<=b; i++){
        
        int cur = calc(b, 0, i);
        //printf("%ld: %ld\n", i, cur);
        if(modi+cur>=k){
            expl(b, 0, i, modi);
            break;
        }
        modi+=cur;
    }
}