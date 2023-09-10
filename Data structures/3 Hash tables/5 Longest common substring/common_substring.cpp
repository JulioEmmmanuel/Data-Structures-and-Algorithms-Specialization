#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Answer {
	size_t i, j, len;
};

unsigned long long calculateHash(string s)
{
	unsigned long long m1 = 1000000271;
	unsigned long long m2 = 1000003919;
	unsigned long long x = 332940;
	unsigned long long v = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		v = ((v * x) % m1 + s[i]) % m1;
	}
	return v % m1;
}

std::vector<unsigned long long> precomputeHashes(int k, string text)
{
	std::vector<unsigned long long> hashes;
	int tDif = text.size() - k;
	hashes.resize(tDif + 1);
	unsigned long long m1 = 1000000271;
	unsigned long long m2 = 1000003919;
	unsigned long long x = 332940;

	hashes[tDif] = calculateHash(text.substr(tDif));

	unsigned long long pot = 1;
	for (int i = 0; i < k; i++)
	{
		pot = (pot * x) % m1;
	}

	for (int i = tDif - 1; i >= 0; i--)
	{
		hashes[i] = (((hashes[i + 1] * x) % m1 + text[i]) % m1 - (text[i + k] * pot) % m1 + m1) % m1 % m2;
	}
	return hashes;
}

Answer solve(const string &s, const string &t) {

	Answer ans;
	ans.len = 0;
	ans.i = 0;
	ans.j = 0;

	unsigned long long m1 = 1000000271;
	unsigned long long m2 = 1000003919;

	int lo = 1;
	int hi = std::min(s.size(), t.size());
	while(lo <= hi){
		int m = (lo + hi) / 2;
		std::vector<unsigned long long> sHashes = precomputeHashes(m, s);
		std::unordered_map<unsigned long long, int> hashesMap;
		for (int i = 0; i < sHashes.size(); i++)
		{
			hashesMap[sHashes[i]] = i;
		}
		std::vector<unsigned long long> tHashes = precomputeHashes(m, t);
		bool found = false;
		for (int i = 0; i < tHashes.size(); i++)
		{
			auto it = hashesMap.find(tHashes[i]);
			if (it != hashesMap.end())
			{
				if (tHashes[i] % m1 == it->first % m1 && tHashes[i] % m2 == it->first % m2){
					bool equal = true;
					for (int k = 0; k < m; k++)
					{
						if (t[i + k] != s[it->second + k])
						{
							equal = false;
							break;
						}
					}
					if(equal){
						ans.len = m;
						ans.j = i;
						ans.i = it->second;
						lo = m + 1;
						found = true;
						break;
					}
				}
			}
		}

		if(!found){
			hi = m - 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
