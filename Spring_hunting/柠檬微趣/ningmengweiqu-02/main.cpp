#include <iostream>
using namespace std;
typedef struct Node{
    Node* pLeftChild;
    Node* pRightChild;
    Node* pParent;
}Node;
int getHeight(Node* pTree){
    int height;
    if(pTree==nullptr){
        height=0;
    }else{
        if(pTree->pLeftChild==nullptr&&pTree->pRightChild==nullptr){
            return 1;
        }else{
            int leftHeight=0;
            int rightHeight=0;
            if(pTree->pLeftChild!=nullptr){
                leftHeight=getHeight(pTree->pLeftChild);
            }
            if(pTree->pRightChild!=nullptr){
                rightHeight=getHeight(pTree->pRightChild);
            }
            height=leftHeight>rightHeight?(leftHeight+1):(rightHeight+1);
        }
    }
    return height;
}
Node* initTree(){
    int n=0;
    cin>>n;
    if(n==0){
        return nullptr;
    }
    Node* p=new Node();
    p->pLeftChild=initTree();
    if(p->pLeftChild){
        p->pLeftChild->pParent=p;
    }
    p->pRightChild=initTree();
    if(p->pRightChild){
        p->pRightChild->pParent=p;
    }
    return p;
}
int main()
{
    int p=0;
    Node * pTree=initTree();
    p=getHeight(pTree);
    cout<<p<<endl;
    return 0;
}
