#include<bits/stdc++.h>
using namespace std;
struct query{
  int L, R;
};
void printArr(int arr[], int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int findSum(int left, int right, int arr[], int blockSum[], int blockSize, int n ,int blocks){
  int sum = 0;
  for(int i=left; i<ceil(left*1.0/blockSize)*blockSize;i++){
    sum+=arr[i];
  }
  for(int i= ceil(left*1.0/blockSize); i<floor(right*1.0/blockSize) && i<n ;i++)
  {
    sum+=blockSum[i];
  }
  for(int i=(floor(right*1.0/blockSize)*blockSize);i<=right;i++)
  {
    sum+=arr[i];
  }
  return sum;
}
int main(){
  int n;
  cout<<"Enter the number of elements: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements: ";
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int blockSize = floor(sqrt(n));
  int blocks = n/blockSize;
  int blockSum[blocks]={0};
  for(int i=0;i<blockSize*blockSize;i++){
    blockSum[i/blockSize]+=arr[i];
  }
  cout<<"Enter the number of queries: ";
  int t;
  cin>>t;
  while(t--){
    query q;
    int l,r;
    cout<<"Enter left and right index (Starting with 0): ";
    cin>>q.L;
    cin>>q.R;
    cout<<"Sum is: "<<findSum(q.L, q.R, arr, blockSum, blockSize, n, blocks)<<endl;
  }
  return 0;
}
