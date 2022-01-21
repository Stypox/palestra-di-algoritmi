#include<bits/stdc++.h>

using namespace std;

int n;
string s;

bool test(int k){
    int gruppi=n/k;
    for(int a=0;a<gruppi/2;a++){
        
        int s1=a*k;
        int s2=(gruppi-a-1)*k;
        //printf("%d %d %d\n",k, s1, s2);
        for(int b=0;b<k;b++){
            if(s[s1+b]!=s[s2+b]){
                return false;
            }
        }
    }
    return true;
    
}

int main(){
    
    cin>>n>>s;
    for(int a=1;a<n;a++){
        if(n%a==0){
            if(test(a)){
                cout<<a<<endl;
                return 0;
            }
        }
    }
    cout<<n<<endl;
}