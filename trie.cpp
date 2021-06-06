#include<bits/stdc++.h>
using namespace std;

struct Trie {
	Trie *child[26];
	bool isend;
	
	Trie() {
		memset(child,0,sizeof(child));
		isend = false;
	}
};

struct Trie *root;

void insert(string str) {
	struct Trie *cur = root;
	for(char ch: str) {
		int index = ch-'a';
		if(cur->child[index] == NULL) {
			cur->child[index] = new Trie;
		}
		cur = cur->child[index];
	}
	cur->isend = true;
}

bool search(string str) {
	struct Trie *cur = root;
	for(char ch: str) {
		int index = ch-'a';
		if(cur->child[index] == NULL) {
			return false;
		}
		cur = cur->child[index];
	}
	return cur->isend;
}

int main() {
	root = new Trie;
	
	printf("/===INSERT===/\n");
	int n;
	printf("Count: ");
	cin >> n;
	string str;
	while(n--) {
		cin >> str;
		insert(str);
	}
	
	printf("/===SEARCH===/\n");
	printf("Count: ");
	cin >> n;
	while(n--) {
		cin >> str;
		if(search(str))
			cout << str << " is present!\n";
		else 
			cout << str << " is not present!\n";
	}
	return 0;
}
