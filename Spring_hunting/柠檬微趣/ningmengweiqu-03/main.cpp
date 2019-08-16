#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int findIndex(char target,char* str,int length){
    int result=-1;
    for(int i=0;i<length;i++){
        if(str[i]==target){
            result=i;
            break;
        }
    }
    return result;
}
bool isDigit(char src){
    bool result=false;
    if(src>='0'&&src<='9'){
        result=true;
    }
    return result;
}
double StringToDouble(char* pFloatStr){
    int point=findIndex('.',pFloatStr,20);
    double result=0;
    double z=0;
    double d=0;
    if(point>-1){
        for(int i=0;i<point;i++){
            if(isDigit(pFloatStr[i])){
                z=z*10+(pFloatStr[i]-'0');
            }
        }
        for(int j=19;j>point;j--){
            if(isDigit(pFloatStr[j])){
                double index=static_cast<double>(pFloatStr[j]-'0');
                d=d/10+(index)/10;
            }
        }
        result=z+d;
    }else{
        for(int i=0;i<20;i++){
            if(isDigit(pFloatStr[i])){
                z=z*10+(pFloatStr[i]-'0');
            }
        }
        result=z;
    }
    return result;
}
int main(int argc,const char * argv[])
{
    char* pFloatStr=new char[20];
    cin>>pFloatStr;
    cout<<setprecision(16)<<StringToDouble(pFloatStr)<<endl;
    return 0;
}
