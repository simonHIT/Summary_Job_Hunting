#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct{
    long a;
    int num;
}node;
bool cmp(node a,node b){
    return a.a<b.a;
}
int main()
{
    int n;
    cin>>n;
    vector<node> ai;
    for(int i=0;i<n;i++){
        long index;
        cin>>index;
        if(ai.size()>0){
            bool flag=false;
            for(int j=0;j<ai.size();j++){
                if(ai[j].a==index){
                    ai[j].num++;
                    flag=true;
                    break;
                }
            }
            if(!flag){
                node newNode;
                newNode.a=index;
                newNode.num=1;
                ai.push_back(newNode);
            }

        }else{
            node newNode;
            newNode.a=index;
            newNode.num=1;
            ai.push_back(newNode);
        }

    }
    sort(ai.begin(),ai.end(),cmp);
    int countIndex=0;
    int total=0;
    int first=0;
    int next=0;
    while(first>=0&&next>-1&&next>=first){
        for(int i=0;i<ai.size()-1;i++){
        if(ai[i].num>0){
            first=i;
            break;
        }
        }
    while(next<ai.size()){
        int j;
        for(j=first;j<ai.size();j++){
        if(ai[j].num>0){
            next=j;
            break;
        }
        }
        if(j==ai.size()){
            next=-1;
        }
    if(ai[first].num<=ai[next].num){
        countIndex=ai[first].num;
        ai[first].num=0;
        ai[next].num=ai[next].num-ai[first].num;
    }else{
        countIndex=ai[next].num;
        ai[first].num=ai[first].num-ai[next].num;
        ai[next].num=0;
    }
    first=next;
    }
        total+=countIndex;
    }
    for(int i=0;i<ai.size();i++){
        if(ai[i].num>0){
            total+=ai[i].num;
        }
    }

    cout<<total;
    return 0;
}
