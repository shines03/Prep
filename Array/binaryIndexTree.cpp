#include<bits/stdc++.h>
using namespace std;
int getChild(int index){
  return index+(index & (-index));
}
void updateBIT(int BIT[],int index, int m, int n){
  while(index<=n){
    BIT[index] += m;
    index = getChild(index);
  }
}
int getParent(int index){
  return index-(index&(-index));
}
int sumQuery(int BIT[], int index){
  int sum=0;
  while(index>0){
    sum+=BIT[index];
    index = getParent(index);
  }
  return sum;
}
void printArr(int arr[], int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int main(){
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements: ";
  for(int i= 0;i<n; i++)
    cin>>arr[i];
  int BIT[n+1] = {0};
  for(int i=0;i<n;i++){
    updateBIT(BIT,i+1,arr[i],n);
  }
  int t=1;
  while(t){
    int c;
    cout<<"Enter 1 for update element\nEnter 2 for getting range sum: ";
    cin>>c;
    switch (c) {
      case 1:
        int m, newValue;
        cout<<"Enter the index: ";
        cin>>m;
        cout<<"Enter the new value: ";
        cin>>newValue;
        updateBIT(BIT,m+1,newValue-arr[m],n);
        arr[m]=newValue;
        printArr(arr,n);
        break;
      case 2:
        int l,r;
        cout<<"Enter the left and right index for sum: ";
        cin>>l>>r;
        printArr(BIT,n+1);
        cout<<"Required sum is: "<<sumQuery(BIT,r+1) - sumQuery(BIT,l )<<endl;
        break;
      default:
        cout<<"Enter the appropriate choice: "<<endl;
    }
    cout<<"Do you want to continue (0/1): ";
    cin>>t;
  }
  return 0;
}
