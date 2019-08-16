#include <iostream>
#include <string>
#include <vector>
using namespace std;
void judge3(string& source){
    for(int i=2;i<source.size();i++){
        int index=source[i]-'a';
        int preindex=source[i-1]-'a';
        int preindex2=source[i-2]-'a';
        if(index==preindex2&&index==preindex){
            string pre=source.substr(0,i);
            string next=source.substr(i+1,source.size()-i-1);
            source=pre+next;
            i--;
        }
    }
}
void judge2(string& source){
    for(int i=3;i<source.size();i++){
        int index=source[i]-'a';
        int preindex1=source[i-1]-'a';
        int preindex2=source[i-2]-'a';
        int preindex3=source[i-3]-'a';
        if(preindex1==index&&preindex2==preindex3&&preindex1!=preindex2){
            string pre=source.substr(0,i);
            string next=source.substr(i+1,source.size()-i-1);
            source=pre+next;
            i--;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<string> arrays;
    for(int i=0;i<n;i++){
        string index;
        cin>> index;
        judge3(index);
        judge2(index);
        arrays.push_back(index);
    }

    for(int i=0;i<n;i++){
        cout<<arrays[i];
        if(i!=n-1){
            cout<<endl;
        }
    }
    return 0;
}
