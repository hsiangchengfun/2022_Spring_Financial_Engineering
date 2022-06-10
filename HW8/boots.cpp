#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;

int main(){

    vector<ld> f(10,0);
    cout<<"N :";
    ll n = 0;cin>>n;
    for(ll i=1;i<=7;i++){

        cout<<"cin "<<i<<" th swap rate : ";
        cin>>f[i];
        cout<<endl;
    }
    vector<ld> sigmae(10,0);
    

    vector<ld> s(10,0);
    for(ll i=1;i<=7;i++){
        for(ll j = 1;j<=i-1;j++){
            sigmae[i] += f[i]*exp(-1*j*s[j]);
        }
        cout<<sigmae[i]<<endl;
        // s[i] = 1 * log( (1+f[i])/(1 - sigmae[i]) ) / i;
        s[i] = -1 * log( (1 - sigmae[i])/(1+f[i]) ) / i;
    }


    for(ll i=1;i<=7;i++){
        cout<<"spot rate "<<i<<" : "<<s[i]<<endl;
    }


    return 0;
}