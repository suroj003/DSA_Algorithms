#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

//Calculating the Height of the Tree/Node
int getHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}

//Calculating the Balance Factor of the Tree/Node
int getBalance(Node* root){
    if(root==NULL){
        return 0;
    }
    return getHeight(root->left)-getHeight(root->right);
}
//Building Rotation Functions

//Right Rotation
Node* rightRotation(Node* root){
    Node* child=root->left;
    Node* childRight=child->right;


    child->right=root;
    root->left=childRight;
    //Update the height

    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));
    return child;
}

//Left Rotation
Node* leftRotation(Node* root){
    Node* child=root->right;
    Node* childLeft=child->left;


    child->left=root;
    root->right=childLeft;
    //Update the height

    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));
    return child;
}

Node* insert(Node* root,int key){
    //Doesnot exist
    if(root==NULL){
        return new Node(key);
    }

    //Existing node
    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else if(key>root->data){
        root->right=insert(root->right,key);
    }
    else{
        return root;   //Duplicate values are not allowed in AVL Tree
    }


    //Update the height
    root->height=1+max(getHeight(root->left),getHeight(root->right));

    //Balancing check
    int balance=getBalance(root);

    //Finding out the Type of Imbalance(LL,RR,LR,RL)
    //Left Left Case
    if(balance>1 && key<root->left->data){
        return rightRotation(root);
    }
    //Right Right Case    
    else if(balance<-1 && key>root->right->data){
        return leftRotation(root);
    }
    //Left Right Case
    else if(balance>1 && key>root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    //Right Left Case
    else if(balance<-1 && key<root->right->data){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    //No Unbalancing
    else{
        return root;
    }
}


//PREORDER TRAVERSAL
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}
//INORDER TRAVERSAL
void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<"  ";
    inOrder(root->right);
}
//POSTORDER TRAVERSAL
void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"  ";
}
int main(){

    //Duplicate values are not allowed in AVL Tree
    Node* root =NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,50);
    root=insert(root,70);
    root=insert(root,5);
    root=insert(root,100);
    root=insert(root,95);
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}