#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int getNum(string numstr){
    int result=0;
    for(int i=0;i<numstr.size();i++){
        result=result*10+(numstr[i]-'0');
    }
    return result;
}
bool isdigit(char index){
    if(index>='0'&&index<='9'){
        return true;
    }else{
        return false;
    }
}
int main()
{

    string s;
    getline(cin,s);
    int d;
    cin>>d;
    vector<int> colors;
    int pre=s.find('{');
    int next=s.find('}');
    s=s.substr(pre+1,s.size()-2);
    pre=next=0;
    string numstr;
    while(s.size()>0){
        while((!isdigit(s[pre]))&&pre<s.size()){
            pre++;
        }
        next=pre;
        while(isdigit(s[next])&&next<s.size()){
            next++;
        }

        numstr=s.substr(pre,next-pre);
        s=s.substr(next,s.size()-next);

        int num=getNum(numstr);
        colors.push_back(num);
    }

    int countResult=0;
    for(int i=0;i<colors.size();i++){
        int currentx=colors[i];
        for(int j=0;j<colors.size();j++){
            if(j!=i){
                int currenty=colors[j];
                int indexd=currentx-currenty;
                if(indexd<0){
                    indexd=indexd*-1;
                }
                if(indexd<=d){
                    countResult++;
                }
            }
        }
    }
    int l=colors.size();
    double result=static_cast<double>(countResult)/(l*(l-1));
    cout<<fixed<<setprecision(6)<<result;
    return 0;
}
