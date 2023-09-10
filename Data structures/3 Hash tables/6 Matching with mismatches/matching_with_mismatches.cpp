#include <iostream>
#include <vector>

using namespace std;

long long m1 = 1000000007;
long long x = 3329402132;
std::vector<unsigned long long> hashesS;
std::vector<unsigned long long> hashesP;
std::vector<unsigned long long> powers;

void precalculate(string s, string p){
	hashesS.resize(s.size() + 1);
	hashesP.resize(s.size() + 1);
	powers.resize(s.size() + 1);
	hashesS[0] = 0;
	hashesP[0] = 0;
	powers[0] = 1;
	for (int i = 1; i <= s.size(); i++)
	{
		hashesS[i] = (x * hashesS[i - 1] % m1 + s[i - 1]) % m1;
		powers[i] = powers[i - 1] * x % m1;
	}
	for (int i = 1; i <= p.size(); i++){
		hashesP[i] = (x * hashesP[i - 1] % m1 + p[i - 1]) % m1;
	}
}

unsigned long long hashValueS(int low, int high){
	return (hashesS[high] - powers[high - low] * hashesS[low] % m1 + m1) % m1;
}

unsigned long long hashValueP(int low, int high)
{
	return (hashesP[high] - powers[high - low] * hashesP[low] % m1 + m1) % m1;
}

vector<int> solve(int k, const string &text, const string &pattern)
{
	vector<int> pos;
	precalculate(text, pattern);
	for (int i = 0; i < text.size() - pattern.size() + 1; i++)
	{
		int C = k;
		int low = i;
		int high = i + pattern.size() - 1;
		int startS = 0;
		while (low <= high)
		{
			int m = (low + high) / 2;

			if(m == low){
				if(text[m] == pattern[startS]){
					m++;
					if(m > high){
						break;
					}
				} else {
					low = m + 1;
					high = i + pattern.size() - 1;
					C--;
					startS++;
					if(C < 0){
						break;
					}
					continue;
				}
			}

			unsigned long long hashBeforeS = hashValueS(low, m);
			unsigned long long hashBeforeP = hashValueP(startS, startS + m-low);

			if (hashBeforeS != hashBeforeP)
			{
				high = m - 1;
			} else
			{
				if (text[m] == pattern[startS + m - low])
				{
					startS += m - low + 1;
					low = m + 1;
				}
				else
				{
					startS += m - low + 1;
					low = m + 1;
					high = i + pattern.size() - 1;
					C--;

					if (C < 0)
					{
						break;
					}
				}
			}
		}

		if(C >= 0){
			pos.push_back(i);
		}
	}

	return pos;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int k;
	string t, p;
	while (cin >> k >> t >> p) {
		auto a = solve(k, t, p);
		cout << a.size();
		for (int x : a)
			cout << " " << x;
		cout << "\n";
	}
}
