#include<iostream>
#include<vector>
#include<cmath>
#define ll long long

using namespace std;

int main(){

    vector<float> C;
    ll n;
    cout<<"input num of period ";
    cin>>n;
    C.resize(n+1);
    ll tmp=0;
    cout<<"input C0 and else "<<endl;
    for(ll i=0;i<n+1;i++){
        cin>>C[i];

    }
    float discount = 1;
    float low=0.009,high=0.011;
    while(high - low >= 0.00001){
        float mid = (high + low )/2;
        float val = 0;
        
        for(ll i=1;i<=n;i++){
            discount = 1;
            // discount *= pow( (1+mid) , -1 );

            for(ll j=1;j<=i;j++)discount/=(1+mid);
            val += discount*C[i];

        }
        cout<<"with rate "<<mid<<" val = ";
        val -= C[0];
        cout<<val<<endl;

        if(val > 0)low = mid;
        else high = mid;
    
        cout<<"h "<<high<<" l "<<low<<endl;
    }

    cout<<"IRR "<<high;
    return 0;
}
