#include <iostream>
using namespace std;
int main()
{
    long n;
    cin>>n;
    long total=1024-n;
    int nums=0;
    while(total>0){
        if(total>=64){
            nums+=(total/64);
            total=(total%64);
        }else if(total<64&&total>=16){
            nums+=(total/16);
            total=(total%16);
        }else if(total<16&&total>=4){
            nums+=(total/4);
            total=(total%4);
        }else if(total<4&&total>=1){
            total+=total;
            total=(total%1);
        }
    }
    cout<<nums;
    return 0;
}
