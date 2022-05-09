#include<iostream>
using namespace std;
class node{
    int cost;
    string city;
    node*next;
    public:
    node(){
        cost=0;
        next=NULL;
    }
    friend class graph;
};
class graph{
    node*t[10];
    int n;
    public:
    graph(){
        for(int i=0;i<n;i++){
            t[i]=NULL;
        }
    }
    void insert(){
        
        cout<<"enter the total no of source city"<<endl;
        cin>>n;
        node *curr;
        char ans;
        
        for(int i=0;i<n;i++){
            t[i]=new node();
            
            cout<<"enter the source city name"<<endl;
            cin>>t[i]->city;
            node*l=NULL;
            node*previous;
            
            cout<<"add city connected to"<<t[i]->city<<"(y/n)?"<<endl;
            cin>>ans;
            while(ans=='Y'|| ans=='y'){
                node *current=new node();
                cout<<"enter the city name"<<endl;
                cin>>current->city;
                cout<<"distance from of"<<t[i]->city<<"to"<<current->city<<endl;
                cin>>current->cost;
                if(l==NULL){
                    l=current;
                    previous=current;
                }
                else{
                    previous->next=current;
                    previous=current;
                }
                cout<<"add city connected to"<<t[i]->city<<"(y/n)?"<<endl;
                cin>>ans;
            }
            t[i]->next=l;
            
        }
        
        
    }
    void display(){
        cout<<"source  destination  cost"<<endl;
        for(int i=0;i<n;i++){
            node*temp=t[i]->next;
            while(temp!=NULL){
                cout<<" "<<t[i]->city<<" "<<temp->city<<" "<<temp->cost<<endl;
                temp=temp->next;
            }
        }
    }
    
};
int main(){
    graph g1;
    g1.insert();
    g1.display();
}
