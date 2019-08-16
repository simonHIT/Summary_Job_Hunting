#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
int main()
{
    int x,y;
    scanf("%d,%d",&x,&y);
    int countMulti=0;
    int countPlus=0;
    int countMinus=0;
    ll source=x;
    ll target=y;
    int result=0;
    if(source<target&&source*target>0){
        while(source*2-target+1<=target-source&&source<=target&&source*2<target){
            source=source*2;
            countMulti++;
        }
        int result1=target-source+countMulti;
        int result2=source*2-target+countMulti+1;
        result=(result1<result2)?result1:result2;
    }else if(source>target&&source*target>0){
        result=source-target;
    }else if(source*target<0){
        if(source<target){
            countPlus=source*-1+1;
            source=1;
            while(source*2<target){
                source*=2;
                countMulti++;
            }
            int result1=target-source+countMulti;
            int result2=source*2-target+countMulti+1;
            result=(result1<result2)?result1:result2;
            result+=countPlus;
        }else{
            countMinus=source+1;
            while(source*2>target){
                source*=2;
                countMulti++;
            }
            int result1=source-target+countMulti;
            int result2=target-source*2+countMulti+1;
            result=(result1<result2)?result1:result2;
            result+=countMinus;
        }
    }else{
        ll zero=source==0?source:target;
        result=source-target;
        if(result<0){
            result*=-1;
        }
    }
    cout<<result;
    return 0;
}
