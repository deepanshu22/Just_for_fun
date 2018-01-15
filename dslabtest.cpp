#include<iostream>
#include<cmath>
using namespace std;

class BinaryTreeNode {
    public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode*  takeInput(){
  int rootData;
  cin >> rootData;
  if(rootData == -1){
    return NULL;
  }
BinaryTreeNode* root = new BinaryTreeNode(rootData);
  root->left =   takeInput();
  root->right = takeInput();
  return root;
}
int height(BinaryTreeNode *root)
{
     if(root== NULL)
     {
       return 0;
     }
     int h1=height(root->left);
     int h2=height(root->right);
     if(h1>h2)
     {
         return h1+1;
     }
     else
     {
        return  h2+1;
     }
}

int diameter(BinaryTreeNode* root) {

       if(root==NULL)
       {
           return 0;
       }
       int option1=diameter(root->left);
       int option2=diameter(root->right);
       int option3=height(root->left)+height(root->right)+1;
       return max(option3,max(option2,option1));

}

int main(){
  BinaryTreeNode* root = takeInput();
  cout << "diameter " << diameter(root) << endl;
}
