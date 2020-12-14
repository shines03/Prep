#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n],  rightMax[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int maxm = arr[n-1];
	rightMax[n-1] = maxm;
	for(int i=n-2;i>=0; i--){
		maxm = max(maxm,arr[i]);
		rightMax[i]=maxm;
	}
	for(int i=0;i<n;i++){
		if(arr[i]==rightMax[i])
			cout<<arr[i]<<" ";
	}
}
