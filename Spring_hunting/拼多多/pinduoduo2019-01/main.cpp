#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arrays;
    for(int i=0;i<n;i++){
        int index;
        cin>>index;
        arrays.push_back(index);
    }
    sort(arrays.begin(),arrays.end(),cmp);
    vector<long> arrayResult;
    for(int j=0;j<n/2;j++){
        long resultIndex=arrays[j]+arrays[n-j-1];
        arrayResult.push_back(resultIndex);
    }
    sort(arrayResult.begin(),arrayResult.end(),cmp);
    long max=arrayResult[arrayResult.size()-1];
    long min=arrayResult[0];
    cout<<max-min;
    return 0;
}
