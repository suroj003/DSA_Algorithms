
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
    Node* root;

    public:
    BST(int val){
        root = NULL;
    }

    //Insert Function
    Node* insert(Node* root,int val){
        if(root==NULL){
            root=new Node(val);
            return root;
        }
        if(val<root->data){
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    //Delete Function
    Node* deleteNode(Node* root,int val){
        if(root==NULL){
            return NULL;
        }
        if(val<root->data){
            root->left=deleteNode(root->left,val);
        }
        else if(val>root->data){
            root->right=deleteNode(root->right,val);
        }
        else{
            //Leaf Node;
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //Only Left Child Exists
            else if(root->left!=NULL && root->right==NULL){
                Node* temp=root->left;
                delete root;
                return temp;
            }
            //Only Right Child Exists
            else if(root->left==NULL && root->right!=NULL){
                Node* temp=root->right;
                delete root;
                return temp;
            }

            //Both Children Exists
            else{
                Node* temp=root->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
            }
        }
        return root;
    }

    //Search Function
    void search(Node* root,int val){
        if(root==NULL){
            cout<<"Value Not Found"<<endl;
            return;
        }
        if(val<root->data){
            search(root->left,val);
        }
        else if(val>root->data){
            search(root->right,val);
        }
        else{
            cout<<"Value Found"<<endl;
            return;
        }
    }

    //Traversal Functions
    void inorder(Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    //Public Wrapper Functions
    void insertValue(int val){
        root=insert(root,val);
    }

    void deleteValue(int val){
        root=deleteNode(root,val);
    }

    void searchValue(int val){
        search(root,val);
    }

    void showInorder(){
        inorder(root);
        cout<<endl;
    }

    void showPreorder(){
        preorder(root);
        cout<<endl;
    }

    void showPostorder(){
        postorder(root);
        cout<<endl;
    }
};

int main(){
    int choice,val;
    BST bst(0);

    while(true){
        cout<<"Enter your choice : 1. Insert 2. Delete 3. Search 4. Inorder Traversal 5. Preorder Traversal 6. Postorder Traversal 0. Exit"<<endl;

        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value to insert : ";
                cin>>val;
                bst.insertValue(val);
                break;

            case 2:
                cout<<"Enter value to delete : ";
                cin>>val;
                bst.deleteValue(val);
                break;

            case 3:
                cout<<"Enter value to search : ";
                cin>>val;
                bst.searchValue(val);
                break;

            case 4:
                cout<<"Inorder Traversal : ";
                bst.showInorder();
                break;

            case 5:
                cout<<"Preorder Traversal : ";
                bst.showPreorder();
                break;

            case 6:
                cout<<"Postorder Traversal : ";
                bst.showPostorder();
                break;

            case 0:
                return 0;

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
