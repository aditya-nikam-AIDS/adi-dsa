#include<iostream>
using namespace std;
class node{
    string key;
    string meaning;
    node*left;
    node*right;
    public:
    node(){
        left=NULL;
        right=NULL;
    }
  friend class dictionary;  
};
class dictionary{
    node *root;
    public:
    dictionary(){
        root=NULL;
    }
    node*getroot(){
        return root;
    }
void create(){
    int ch;
    do{
        node *temp;
        node *nnode=new node();
        cout<<"enter the keyword ::";
        cin>>nnode->key;
        cout<<"enter the meaning ::";
        cin>>nnode->meaning;
        temp=nnode;
        if(root==NULL)
        root=nnode;
        else
        insert(root,temp);
        cout<<"do you want to insert more node press 1 otherwise 0\n";
        cin>>ch;
    }while(ch==1);
}
void insert(node *root,node*temp){
    if(root->key >temp->key){
        if(root->left==NULL)
        root->left=temp;
        else
        insert(root->left,temp);
    }
    else{
        if(root->right==NULL)
        root->right=temp;
        else
        insert(root->right,temp);
    }
}
void inorder(node *temp){
    if(temp!=NULL){
        inorder(temp->left);
        cout<<temp->key<<"  "<<temp->meaning<<" \n";
        inorder(temp->right);
    }
}
void search(node *temp,string key){
    int c=0;
    int flag=0;
    while(temp!=NULL){
    c++;
    if(temp->key==key){
        cout<<"no of comparision required to find the element"<<endl;
        cout<<c;
        flag=1;
        break;
    }
    else{
        if(temp->key>key){
            temp=temp->left;
        }
        if(temp->key<key){
            temp=temp->right;
        }
        
    }
    
}
if(flag==0){
    cout<<"element not found"<<endl;
}
}
void updated(node *temp,string key){
    while(temp!=NULL)
    if(temp->key==key){
        cout<<"key is found update it meaning";
        cout<<"enter a new meaning"<<endl;
        cin>>temp->meaning;
        
        break;
    }
    else{
        if(temp->key>key){
            temp=temp->left;
        }
        else if(temp->key<key){
            temp=temp->right;
        }
        
    }
    
}
node *del(node *root,string key){
    node *temp;
    if(root==NULL){
        cout<<"element not found";
        return root;
    }
    if(root->key>key){
        root->left=del(root->left,key);
        return root;
    }
    if(root->key<key){
        root->right=del(root->right,key);
        return root;
    }
    if(root->right==NULL && root->left==NULL){
        temp=root;
        delete temp;
        return NULL;
    }
    if(root->right==NULL){
        temp=root;
        root=root->left;
        delete temp;
        return root;
    }
    if(root->right==NULL){
        temp=root;
        root=root->right;
        delete temp;
        return root;
        
    }
    temp=min(root->right);
    node *t;
    t->key=temp->key;
    root->key=t->key;
    root->right=del(root->right,key);
    return root;
    
    
}
node* min(node *temp){
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
};

int main(){
dictionary d1;
int ch;
string a;
while(1){
        cout<<"\n 1.create\n2.display\n3.search\n 4.update\n 5.delete\n";
        cout<<"enter your choice"<<endl;
        cin>>ch;
switch(ch){
    case 1:
        d1.create();
         break;
    case 2:
        d1.inorder(d1.getroot());
        break;
    case 3:
        cout<<"enter the string that should be search"<<endl;
        cin>>a;
        d1.search(d1.getroot(),a);
        break;
    case 4:
        cout<<"enter the string that should be updated"<<endl;
        cin>>a;
        d1.updated(d1.getroot(),a);
        d1.inorder(d1.getroot());
        break;
    case 5:
        cout<<"enter a key you want to be deleted"<<endl;
        cin>>a;
        cout<<endl;
        d1.del(d1.getroot(),a);
        d1.inorder(d1.getroot());
        break;
    }
}
return 0;
}
