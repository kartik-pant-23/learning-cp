// Given a 2-d array and row window limits
// Find if in the window there exists a column with sorted values

#include<bits/stdc++.h>
using namespace std;

int main() {
	int m,n; // Count of rows and columns
	cin >> m >> n;
	int arr[m][n];
	
	// Taking array input
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++)
		cin >> arr[i][j];
	}
	
	// Approach: Put length of max non decreasing array ending at current index
	// When queries are made, check if length stored at arr[hr] is greater than window size
	int currMax[n], maxRow[m];
	for(int i=0; i<m; i++) {
		maxRow[i]=1;
		for(int j=0; j<n; j++) {
			if(i==0) currMax[j]=1;
			else {
				if(arr[i][j]>=arr[i-1][j])
					currMax[j]++;
				else
					currMax[j] = 1;
					
				maxRow[i] = max(maxRow[i],currMax[j]);
			}
		}
	}
	
	int q; // Number of queries
	cin >> q;
	
	int lr, hr; // Lower and higher row index of window
	for(int i=0; i<q; i++) {
		cin >> lr >> hr;
		if(maxRow[hr]>(hr-lr))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
	return 0;
}
