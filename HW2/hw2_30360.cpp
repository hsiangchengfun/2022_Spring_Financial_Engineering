#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#define ll long long
#define ld long double
using namespace std;

class date{
public:
    ll day = 0;
    ll mth = 0;
    ll yr = 0;

};

ll calcu(date date1,date date2){
    ll days = 360*(date2.yr - date1.yr) + 30*(date2.mth - date1.mth) + (date2.day - date1.day);
    return days;
}

int main(){

    ll d1,m1,y1;
    ll d2,m2,y2;
    ld yield ,cprate;
    ll n;
    ld w;
    ll C = 100;
    date date1,date2;
    cout<<"Settlement date \nMaturity date\nBond Yield \nCoupon Rate\n";
    ll tmp;
    cin>>date1.yr;cin>>date1.mth;cin>>date1.day;
    cin>>date2.yr;cin>>date2.mth;cin>>date2.day;
    cin>>yield;
    cin>>cprate;


    ll days = calcu(date1,date2);
    n = days/ (360/2) +1;
    yield/=2;
    w = (ld)(days-(days/180)*180) / 180;
    ld dirtyprice = 0;
    cprate/=2;
    for(ll i=0;i<n;i++){
        dirtyprice += (ld)C*cprate*( pow( (1 + yield), (ld)(-w-i) ) );
    }
    dirtyprice += 100*( pow( (1+yield), -w-n+1) );
    ld accurate = (ld)(cprate)*C*(1-w);
    ld cleanprice = dirtyprice - accurate;
    cout<<"Dirty Price : "<<setprecision(9)<<dirtyprice<<endl;
    cout<<"Clean Price : "<<setprecision(9)<<cleanprice<<endl;

    return 0;
}