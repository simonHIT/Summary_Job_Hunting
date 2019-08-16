#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    long nums;
    cin>>nums;
    vector<ll> results;
    for(int i=0;i<nums;i++){
        long n;
        vector<long> scores;
        cin>>n;
        long prizes[n];
        for(int j=0;j<n;j++){
            long score;
            cin>>score;
            scores.push_back(score);
            prizes[j]=0;
        }
        long minNode=scores[0];
        int first=0;
        for(int j=0;j<n;j++){
            if(scores[j]<minNode){
                minNode=scores[j];
                first=j;
            }
        }
        prizes[first]=1;
        ll total=0;
        total+=1;
        long minusValue=minNode-1;
        for(int j=0;j<n;j++){
            if(j!=first){

                total+=(scores[j]-minusValue);
            }
        }
        results.push_back(total);
    }
    for(int i=0;i<nums;i++){
        cout<<results[i];
        if(i!=(results.size()-1)){
            cout<<endl;
        }
    }
    return 0;
}
