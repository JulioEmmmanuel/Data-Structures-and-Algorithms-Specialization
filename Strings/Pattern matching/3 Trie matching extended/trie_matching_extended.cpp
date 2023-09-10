#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	bool isEnd = false;

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;
	vector <Node> trie;

	trie.push_back(Node());

	// create trie
	for(int i = 0; i < patterns.size(); i++){
		string pat = patterns[i];
		int curr = 0;

		for(int j = 0; j < pat.size(); j++){
			int idx = letterToIndex(pat[j]);
			if(trie[curr].next[idx] != NA){
				curr = trie[curr].next[idx];
			} else {
				trie[curr].next[idx] = trie.size();
				trie.push_back(Node());
				curr = trie[curr].next[idx];
      		}
    	}

		trie[curr].isEnd = true;
	}

	//search in pattern trie for each position in the text
	for(int i = 0; i < text.size(); i++){
		int curr = 0;
		for(int j = i; j < text.size(); j++){
			int idx = letterToIndex(text[j]);
			if(trie[curr].next[idx] != NA){
				curr = trie[curr].next[idx];
				if(trie[curr].isEnd){
					result.push_back(i);
					break;
				}
			} else {
				break;
      		}
    	}
	}

	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
