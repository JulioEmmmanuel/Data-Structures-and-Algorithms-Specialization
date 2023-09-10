#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

struct DisjointSetsElement {
	int size, parent;
	
	DisjointSetsElement(int size = 0, int parent = -1):
	    size(size), parent(parent) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
	}

	int getParent(int table) {
		// find parent and compress path
		int parent = sets[table].parent;
		if(parent < 0){
			return table;
		}
		while(sets[parent].parent > 0){
			parent = sets[parent].parent;
		}
		sets[table].parent = parent;
		return parent;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
			// merge two components
			// use union by rank heuristic
			// update max_table_size
			if(sets[realDestination].parent <= sets[realSource].parent){
				if (sets[realDestination].parent == sets[realSource].parent)
				{
					sets[realDestination].parent--;
				}
				sets[realSource].parent = realDestination;
			}
			else
			{
				sets[realDestination].parent = realSource;
			}
			sets[realSource].size += sets[realDestination].size;
			sets[realDestination].size = sets[realSource].size;
			max_table_size = max(max_table_size, sets[realSource].size);
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
                --destination;
                --source;
		
		tables.merge(destination, source);
	        cout << tables.max_table_size << endl;
	}

	return 0;
}
