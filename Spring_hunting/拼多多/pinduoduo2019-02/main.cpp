#include <iostream>
#include <vector>
using namespace std;
long getNum(vector<int> arrays){
    long result=0;
    for(int i=0;i<arrays.size();i++){
        result=result*10+arrays[i];
    }
    return result;
}
int main()
{
    vector<int> nums;
    for(int i=0;i<10;i++){
        int indexNum;
        cin>>indexNum;
        nums.push_back(indexNum);
    }
    int alength,blength;
    cin>>alength>>blength;
    long a,b;
    int countNum=0;
    vector<int> aarray,barray;
    for(int i=0;i<alength;i++){
        while(nums[countNum]==0&&countNum<10){
            countNum++;
        }
        aarray.push_back(countNum);

        nums[countNum]=nums[countNum]-1;
    }

    for(int i=0;i<blength;i++){
        while(nums[countNum]==0&&countNum<10){
            countNum++;
        }
        barray.push_back(countNum);

        nums[countNum]=nums[countNum]-1;
    }

    a=getNum(aarray);
    b=getNum(barray);
    long long result=a*b;
    cout<<result;
    return 0;
}
