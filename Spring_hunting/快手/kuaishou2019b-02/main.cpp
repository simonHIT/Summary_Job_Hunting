#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int index=n;
    ll result=1;
    while(index>=1){
        result*=index;
        index--;
    }
    while(result%10==0){
        result=result/10;
    }
    int num=result%10;
    cout<<num;
    return 0;
}
