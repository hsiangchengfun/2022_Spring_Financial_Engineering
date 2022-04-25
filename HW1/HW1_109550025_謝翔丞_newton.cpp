#include<iostream>
#include<vector>
#include<cmath>
#define ll long long

using namespace std;

int main(){

    vector<long double> C;
    ll n;
    cout<<"input num of period ";
    cin>>n;
    C.resize(n+1);
    long double tmp=0;
    cout<<"input C0 and else "<<endl;
    for(ll i=0;i<n+1;i++){
        cin>>C[i];
    }

    long double x1=0,x2=0;
    long double fx=0,fx2=0,discount=1;
    while(1){//fx >= 0.000000000001 || fx <=-0.00000000001){

        fx=0;
        for(ll i=1;i<=n;i++){
            discount = 1;
            for(ll j=1;j<=i;j++)discount/=(1+x1);
            fx += discount*C[i];

        }
        fx-=C[0];
        fx2=0;
        long double tmp=1;
        for(ll i=1;i<=n;i++){
            tmp=1;
            for(ll j=1;j<=i+1;j++)tmp/=(1+x1);
            fx2+=(C[i]*i)*tmp;
        }
        fx2*=-1;
        
        if(fx==0)break;
        cout<<"fx "<<fx<<" fx2 "<<fx2<<" ";
        
        x2=x1-(fx/fx2);
        cout<<x2<<endl;
        x1=x2;

    }

    cout<<x2;



    return 0;
}
