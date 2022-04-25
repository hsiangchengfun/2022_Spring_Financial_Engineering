#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;

int main(){

    float yield_rate,n,c,yield_spread;
    vector<float> zerorate(5,0.0);
    vector<float> yield;
    cin>>c;
    cout<<"spread ";
    cin>>yield_spread;
    float a;
    for(ll i=0;i<5;i++){
        cout<<"yield "<<i<<" ";
        cin>>a;
        yield.push_back(a);
    }
    zerorate[0]= (yield[0]);

    for(ll i=1;i<=4;i++){
        float bondval = 0;
        for(ll j=0;j<=i;j++){

            float discount = 1;
            for(ll k=0;k<=j;k++){
                discount /=(1+yield[i]);
            }
            bondval += discount*c;
            if(j == i){
                bondval += discount*100;
            }

        }

        for(ll j=0;j<i;j++){
            float pv = c;
            for(ll k=0;k<=j;k++){
                pv /= (1+zerorate[j]);

            }
            bondval -= pv;
        }    
        zerorate[i] = pow( (c+100)/bondval,1.0/(i+1) ) - 1;

    }
    for(ll i=0;i<5;i++)cout<<"period "<<i<<"  spot rate "<< zerorate[i]<<endl;
    



    float bondvalue;
    for(ll j=0;j<5;j++){

        float discount = 1;
        for(ll k=0;k<=j;k++){
            discount /=(1+yield[4]+yield_spread);
        }
        bondvalue += discount*c;
        if(j == 4){
            bondvalue += discount*100;
        }

    }


    cout<<"bondvalue "<<bondvalue<<endl;


    n=5;
    long double x1=0,x2=0;
    long double fx=0,fx2=0,discount=1;
    while(1){

        fx=0;
        for(ll i=0;i<n;i++){
            discount = 1;
            for(ll j=0;j<=i;j++)discount/=(1 + x1 + zerorate[i]);
            fx += discount*c;
            if(i==n-1)fx+=discount*100*i;
        }
        fx -= bondvalue;
        fx2=0;
        long double tmp=1;
        for(ll i=0;i<n;i++){
            tmp=1;
            for(ll j=0;j<=i+1;j++)tmp/=(1 + x1 + zerorate[i]);
            fx2+=(c*i)*tmp;
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
