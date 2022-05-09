#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
class node{
    int data;
    node*left;
    node*right;
    public:
    node(){
        left=NULL;
        right=NULL;
        data=0;
    }
    friend class tree;
    friend class stac_k;
    
};
class tree{
    node *root;
    
    public:
   // friend class stac_k;
    tree(){
        root=NULL;
    }
    node*getroot(){
        return root;
    }
    node *create(int d){
        node*nnode=new node();
        nnode->data=d;
        return nnode;
    }
    node *insert(node *root,int data){
        if(root==NULL){
            return create(data);
        }
        else if(data>root->data){
            root->right=insert(root->right,data);
       }
       else if(data<root->data){
           root->left=insert(root->left,data);
       }
       return root;
}

void preorder(node *temp){
if(temp!=NULL){
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
}

void inorder(node *temp){
    if(temp==NULL)
    return ;
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    
}
void postorder(node *temp){
if(temp!=NULL){
  
    postorder(temp->left);
postorder(temp->right);
    cout<<temp->data<<" ";
}
}

void input(){
    int n, data;
    cout<<"enter the number of element"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter the data";
        cin>>data;
        root=insert(root,data);
    }
}
int minvalue(node *temp){
    while(temp->left!=NULL){
        temp=temp->left;
    }
    
    return temp->data;
    
}
void nonpreorder(node *temp){
    stack<node *>s1;
   // node*temp=t;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        s1.push(temp);
        temp=temp->left;
    }
    while(!s1.empty()){
        temp=s1.top();
        s1.pop();
        temp=temp->right;
        while(temp!=NULL){
        cout<<temp->data<<" ";
        s1.push(temp);
        temp=temp->left;
    }
     }
     
    }
  void noninorder(node *t){
    stack<node *>s1;
    node*temp=t;
    while(temp!=NULL){
       
        s1.push(temp);
        temp=temp->left;
    }
    while(!s1.empty()){
        temp=s1.top();
        s1.pop();
        cout<<temp->data<<"";
        temp=temp->right;
        while(temp!=NULL){
        s1.push(temp);
        temp=temp->left;
    }
     }
     
    }
    void nonpostorder(node *temp){
        stack<node *>s1,s2;
        s1.push(temp);
        while(!s1.empty()){
            temp=s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left!=NULL)
            s1.push(temp->left);
            else
            s1.push(temp->right);
        }
        while(!s2.empty()){
            temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
        }
    }
    int height(node *temp){
        if(temp==NULL){
            return 0;
        }
        int l=height(temp->left);
        int r=height(temp->right);
        return(1+max(l,r));
    }
    int search(node *temp,int data){
        while(temp!=NULL){
            if(temp->data==data){
                return 1;
            }
            else{
                if(temp->data>data){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return 0;
    }
    void swap(node *temp){
        if(temp->left!=NULL)
         swap(temp->left);
        if(temp->right!=NULL)
         swap(temp->left);
         node*s=temp->left;
         temp->left=temp->right;
         temp->right=s;
         
    }
};

int main(){
tree t1;
int ch;
while(1){
    cout<<"\n1.create\n2.traverse\n3.height\n4swap\n 5.min\n 6.search\n";
    cout<<"enter your choice"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
       t1.input();
       break;
       case 2:
            cout<<"the inorder sequence"<<endl;
            t1.inorder(t1.getroot());
            cout<<endl;
            cout<<"the preorder sequence"<<endl;
            t1.preorder(t1.getroot());
            cout<<endl;
            cout<<"the postorder sequence"<<endl;
            t1.postorder(t1.getroot());
            cout<<endl;
            cout<<"the nonrecursive preorder"<<endl;
            t1.nonpreorder(t1.getroot());
            
            cout<<endl;
            cout<<"the nonrecursive ineorder"<<endl;
            t1.noninorder(t1.getroot());
            cout<<endl;
            cout<<"the nonrecursive postorder"<<endl;
            t1.postorder(t1.getroot());
            cout<<endl;
          break;
        case 5:
                cout<<"the minimum value is="<<endl;
                int min;
                min=t1.minvalue(t1.getroot());
                cout<<min<<endl;
                
             break;
        case 3:
            int h;
            cout<<"height of the tree"<<endl;
            
            h=t1.height(t1.getroot());
             cout<<h;
          break;
        case 6:
            cout<<"search the element in a tree";
            cout<<"enter the element";
            int d;
            cin>>d;
            if(t1.search(t1.getroot(),d))
            cout<<"element is found";
            else
            cout<<"not found";
            break;
        case 4:
            cout<<"swap the node";
            t1.swap(t1.getroot());
            break;
}
}

}
