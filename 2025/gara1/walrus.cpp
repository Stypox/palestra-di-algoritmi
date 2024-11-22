#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        string s;
        cin>>n>>s;

        vector<int> awake;
        int strike=0;
        for(int j=0; j<n; j++){
            if(s[j]=='.'){
                strike++;
            }else{
                if(strike>0){
                    awake.push_back(strike);
                    strike=0;
                }
            }
        }
        if(strike>0){
            awake.push_back(strike);
        }
        sort(awake.begin(), awake.end());
        int total=awake.size();
        int time=0;
        for (int j=total-1; j>=0; j--){
            time=max(time, total-j+awake[j]/2);
        }
        cout<<total<<" "<<time<<endl;
    }
    return 0;
}