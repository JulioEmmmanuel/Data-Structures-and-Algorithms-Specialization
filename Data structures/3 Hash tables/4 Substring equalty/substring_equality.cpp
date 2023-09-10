#include <iostream>
#include <vector>

using namespace std;

class Solver {
	string s;
	long long m1 = 1000000007;
	long long m2 = 1000000009;
	long long x = 3329402132;
	std::vector<unsigned long long> hashes;
	std::vector<unsigned long long> powers;
public:
	Solver(string s) : s(s) {	
		// initialization, precalculation
		hashes.resize(s.size()+1);
		powers.resize(s.size()+1);
		hashes[0] = 0;
		powers[0] = 1;
		for (int i = 1; i <= s.size(); i++)
		{
			hashes[i] = (x * hashes[i - 1] % m1 + s[i - 1]) % m1;
			powers[i] = powers[i-1] * x % m1;
		}
	}
	bool ask(int a, int b, int l) {
		long long h1 = (hashes[a + l] - (powers[l] * hashes[a]) % m1 + m1) % m1 % m2;
		long long h2 = (hashes[b + l] - (powers[l] * hashes[b]) % m1 + m1) % m1 % m2;
		return h1 == h2 && h1 % m2 == h2 % m2;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
