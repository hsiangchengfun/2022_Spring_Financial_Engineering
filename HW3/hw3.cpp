#include<iostream>
#include<vector>

#define ld long double
using namespace std;

int main(){

    int n;
    ld c,r,val = 0,discount ,duration = 0;
    cout<<"n,c,r\n";
    cin>>n>>c>>r;
    // c/=2;

    for(int i=1;i<=n;i++){
        discount = 1;
        for(int j = 1;j<=i;j++){
            discount/=(1+r);
        }
        duration += i*discount*c;
        val += discount * c;
        if(i == n){
            val += discount*100;
            duration += n*discount*100;
        }
    }
    duration/=val;
    cout<<"Duration: "<<duration<<endl;
    cout<<"Modified Duration: "<<duration/(1+r)<<endl;
    cout<<"Delta P: "<<0.0001*val*duration/(1+r)<<endl;

    return 0;
}
