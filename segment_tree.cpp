//~ Range queries on a sub-array
//~ Query:- 1 i x (Update ith index with x)
		//~ 2 i j (Fetch max elem. in sub-array[i...j])
		
#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
	private: int* segTree;
	public: 
	SegmentTree(int arraySize) {
		segTree = (int*) malloc(4*arraySize*sizeof(int));
	}
	void build(int,int,int,vector<int>&);
	void update(int,int,int,int,int);
	int fetch(int,int,int,int,int);
	~SegmentTree() {
		free(segTree);
	}
};
void SegmentTree::build(int node, int l, int h, vector<int>& nums) {
	if(h==l) {
		segTree[node] = nums[l];
		return;
	}
	
	int mid = l + (h-l)/2;
	build(node*2+1, l, mid, nums);
	build(node*2+2, mid+1, h, nums);
	
	segTree[node] = max(segTree[node*2+1], segTree[node*2+2]);
}
void SegmentTree::update(int node, int pos, int val, int l, int h) {
	if(pos<l || pos>h) return;
	
	if(l==h && pos==l) {
		segTree[node] = val;
		return;
	}
	
	int mid = l + (h-l)/2;
	update(node*2+1, pos, val, l, mid);
	update(node*2+2, pos, val, mid+1, h);
	segTree[node] = max(segTree[node*2+1], segTree[node*2+2]);
}
int SegmentTree::fetch(int node, int i, int j, int l, int h) {
	if(i>h || j<l) return INT_MIN;
	if(l>=i && h<=j) return segTree[node];
	
	int mid = l + (h-l)/2;
	return max(fetch(node*2+1,i,j,l,mid), fetch(node*2+2,i,j,mid+1,h));
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; ++i) cin >> nums[i];
	
	SegmentTree tree = SegmentTree(n);
	tree.build(0,0,n-1,nums);
	
	int q;
	cin >> q;
	int type, val1, val2;
	for(int i=0; i<q; ++i) {
		cin >> type >> val1 >> val2;
		switch(type) {
			case 1: 
				tree.update(0,val1,val2,0,n-1);
				break;
			default:
				cout << tree.fetch(0,val1,val2,0,n-1) << "\n";
		}
	}
	
	return 0;
}
