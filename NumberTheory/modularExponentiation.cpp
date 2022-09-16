#include<bits/stdc++.h>
using namespace std;

#define ll   long long

ll modularExpo(ll a,ll n,ll m){
    ll res=1;
    while(n){
        if(n%2){
            res=(res * a) % m;
            n--;
        }else{
            a=(a * a) % m;
            n/=2;
        }
    }
    return res;
}


int main()
{
    int b,p;
    cin>>b>>p;
    cout<<modularExpo(b,p)<<endl;
}
