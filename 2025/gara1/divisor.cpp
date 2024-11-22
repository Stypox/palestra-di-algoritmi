#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    //compute primes
    vector<unsigned int> primes;
    primes.push_back(2);
    for(int i=3; i<330000; i++){
        int j=0;
        bool is_prime=true;
        while(j<primes.size() && primes[j]*primes[j]<=i){
            if(i%primes[j]==0){
                is_prime=false;
                break;
            }
            j++;
        }
        if(is_prime){
            primes.push_back(i);
        }
    }
    for(int i=0; i<t; i++){
        int a, b, k;
        cin>>a>>b>>k;
        unsigned int sum=a+b+k;
        unordered_set<unsigned int> divisors;
        divisors.insert(1);
        for(int j=0; j<primes.size()&&primes[j]*primes[j]<=sum; j++){
            while(sum%primes[j]==0){
                unordered_set<unsigned int> to_add;
                for (auto& it: divisors){
                    to_add.insert(it*primes[j]);
                }
                for (auto& it: to_add){
                    divisors.insert(it);
                }
                //divisors.insert(primes[j]);
                sum=sum/primes[j];
            }
            
        }
        if (sum!=1){
            unordered_set<unsigned int> to_add;
            for (auto& it: divisors){
                to_add.insert(it*sum);
            }
            for (auto& it: to_add){
                divisors.insert(it);
            }
            //divisors.insert(primes[sum]);
        }
        unsigned int maximum=0;
        for (auto& it: divisors){
            //printf("s %d\n", it);
            int cost=0;
            if(a%it!=0){
                cost+=it-(a%it);
            }
            if(b%it!=0){
                cost+=it-(b%it);
            }
            if (cost<=k&&(k-cost)%it==0){
                maximum=max(maximum, it);
            }
        }
        cout<<maximum<<endl;
    }
    return 0;
}