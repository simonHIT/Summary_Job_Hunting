#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string word1,word2;
    cin>>word1>>word2;
    if(word1.size()>word2.size()){
        cout<<word1.size()-word2.size();
    }else if(word1.size()<word2.size()){
        cout<<word2.size()-word1.size();
    }else{
        int count1=0;
        for(int i=0;i<word1.size();i++){
            if(word1[i]!=word2[i]){
                count1++;
            }
        }
        cout<<count1;
    }
    return 0;
}
