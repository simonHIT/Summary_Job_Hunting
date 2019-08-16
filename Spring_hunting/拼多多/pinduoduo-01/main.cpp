#include <iostream>
#include <vector>
using namespace std;
int getNum(string numstr){
    int num=0;
    for(int i=0;i<numstr.size();i++){
        num=num*10+numstr[i]-'0';
    }
    return num;
}
int main()
{
    vector<int> version1;
    vector<int> version2;
    string str1,str2;
    cin>>str1>>str2;

    int pointIndex=-1;
    while(str1.size()>0){

        pointIndex=str1.find('.');
        string num;
        if(pointIndex>-1){
            num=str1.substr(0,pointIndex);
            str1=str1.substr(pointIndex+1,str1.size()-pointIndex-1);

        }else{
            num=str1;
            str1="";
        }
        int number=getNum(num);
        version1.push_back(number);
    }

    pointIndex=-1;
    while(str2.size()>0){
        pointIndex=str2.find('.');
        string num;
        if(pointIndex>-1){
            num=str2.substr(0,pointIndex);
            str2=str2.substr(pointIndex+1,str2.size()-pointIndex-1);

        }else{
            num=str2;
            str2="";
        }
        int number=getNum(num);
        version2.push_back(number);
    }
    if(version1.size()>version2.size()){
        cout<<1;
    }else if(version1.size()<version2.size()){
        cout<<-1;
    }else{

        int temp=-1;
        for(int j=0;j<version1.size();j++){

            if(version1[j]!=version2[j]){
                temp=j;
                break;
            }
        }
        if(temp==-1){
            cout<<0;
        }else{
            if(version1[temp]>version2[temp]){
                cout<<1;
            }else{
                cout<<-1;
            }
        }
    }


    return 0;
}
