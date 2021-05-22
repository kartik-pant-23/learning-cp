// Find maximum subarray

#include<bits/stdc++.h>
using namespace std;

// Find max subarray ending at current index
// max[index] = max(max[index-1]+arr[index], arr[index])

int main() {
	int arr[10] = {2,6,-2,5,-8,3,6,2,-1,-5};
	int maxArray[10];
	
	maxArray[0] = arr[0];
	
	for(int i=1; i<10; i++) {
		maxArray[i] = max(maxArray[i-1]+arr[i], arr[i]);
	}
	
	sort(maxArray, maxArray+10);
	
	for(int a: arr)
		cout << a << " ";
	cout << "\n";
	cout << "Maximum subarray: " << maxArray[9] << "\n";
}
