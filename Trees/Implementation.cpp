#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* build(Node* root){
    int data;
    cin>>data;
    root= new Node(data);

    if(data == -1){
        return NULL;
    }
    cout<<"left"<<endl;
    root->left = build(root->left);
    cout<<"right"<<endl;
    root->right = build(root->right);
    return root;
}

void lot(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        cout<<front->data<<" ";
        q.pop();
        if(front->left){
            q.push(front->left);
        }if(front->right){
            q.push(front->right);
        }
    }
}

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

void buildlot(Node* &root){
    queue<Node*> q;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();
        int ldata;
        cin>>ldata;
        if(ldata!=-1){
            front->left=new Node(ldata);
            q.push(front->left);
        }
        int rdata;
        cin>>rdata;
        if(rdata!=-1){
            front->right=new Node(rdata);
            q.push(front->right);
        }
    }    

}

int main()
{
    Node* root = NULL;
    buildlot(root);
    // root=build(root);
    lot(root);
}