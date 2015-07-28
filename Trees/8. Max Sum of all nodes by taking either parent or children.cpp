#include<iostream>
using namespace std ;


#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
};

//---------------------------------------Build Level Order
struct node*build(){
struct node*root = new node;
cout<<"Enter Root's Data";
cin>>root->data;

queue<node*> q;
q.push(root);

while(!q.empty()){

    struct node*temp = q.front();
    q.pop();
    cout<<"Enter the children (or -1) for node with data as "<<temp->data<<" : ";
    int data1;
    int data2;
    cin>>data1>>data2;

    if(data1!=-1){
          temp->left  = new node;
          temp->left->data = data1;
         q.push(temp->left);
    }
    else{
    temp->left = NULL;
    }

    if(data2!=-1){
        temp->right = new node;
        temp->right->data = data2;
        q.push(temp->right);
    }
    else{
    temp->right = NULL;
    }
  }
return root;
}
//--------------------------------------------------Print Level Order
void printLevelOrder(node*root){

queue<node*> q;
q.push(root);
q.push(NULL);

while(!q.empty()){
    node*temp = q.front();
    q.pop();

    if(q.empty())
        {
        cout<<endl;
        break;
        }

    else if(temp==NULL)
    {
        q.push(NULL);
        cout<<endl;
    }
    else{
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
}

//---------------------------------------------------Print Inorder
void printInorder(struct node*node){
if(node==NULL)
    return;
printInorder(node->left);
cout<<node->data<<" ";
printInorder(node->right);

}
//--------------------------------------------------Find Max Sum


struct output{
int inc;
int exc;
};

output findMaxSumChildOrParent( struct node*root ){
output ans ;
if(root ==NULL)
{
    ans.inc =0;
    ans.exc =0;
    return ans;
}
output left = findMaxSumChildOrParent(root->left);
output right = findMaxSumChildOrParent(root->right);

ans.inc = root->data + left.exc + right.exc ;
ans.exc = max(left.exc,left.inc) + max(right.exc,right.inc);
return ans;
}








int main(){
struct node*root = build();
cout<<"Level Order :"<<endl;
//printLevelOrder(root);
cout<<"Inorder : "<<endl;
//printInorder(root);
output ans = findMaxSumChildOrParent(root);
cout<<endl<<"Max Possible Sum is  : "<<max(ans.inc,ans.exc);
return 0;
}
