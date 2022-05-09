#include<iostream>
using namespace std;
class heapsort{
  int n;    
  int arr[10];
  public:
  void accept();
  void display();
  void heapify(int * ,int,int);
  void heap_sort(int *,int);
};
void heapsort::accept(){
    cout<<"enter the no of students\n"<<endl;
    cin>>n;
    cout<<"enter the marks of students\n"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heap_sort(arr,n);

}
void heapsort::display(){
    cout<<"the marks in the ascending order"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"the minimum marks obatined by the students is"<<arr[0]<<endl;
    cout<<"the maximum marks obtained by the student is"<<arr[n-1];
}
    
void heapsort:: heapify(int arr[],int n,int i){
    int largest=i;
    int l=(2*i);
    int r=(2*i)+1;
    while(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    while(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort::heap_sort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);//build the max heap
    }
    for(int i=n-1;i>0;i--){//delete operation on heap
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}

int main(){
    heapsort h1;
    h1.accept();
    h1.display();
    return 0;
}
