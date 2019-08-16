#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> grayCodeGenerator(vector<string>& grayCode,int index){
    vector<string> newCodeArray;
    for(int j=0;j<grayCode.size();j++){
        string pre=grayCode[j];
        string newCode="0"+pre;
        newCodeArray.push_back(newCode);
    }
    for(int j=grayCode.size()-1;j>=0;j--){
        string pre=grayCode[j];
        string newCode="1"+pre;
        newCodeArray.push_back(newCode);
    }
    grayCode.clear();
    return newCodeArray;
}
int main()
{
    int n,index;
    cin>>n>>index;
    vector<string> grayCode;
    for(int i=1;i<=n;i++){
        if(i==1){
            grayCode.push_back("0");
            grayCode.push_back("1");
        }else{
            if(grayCode.size()*2<=index){
                grayCode=grayCodeGenerator(grayCode);
            }else{

            }

        }
    }
    cout<<grayCode[index];
    return 0;
}
