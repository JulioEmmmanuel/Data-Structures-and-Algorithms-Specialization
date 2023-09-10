#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

unsigned long long calculateHash(string s)
{
    unsigned long long p = 999331;
    int x = 263;
    unsigned long long v = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        v = ((v * x) % p + s[i]) % p;
    }
    return v % p;
}

std::vector<unsigned long long> precomputeHashes(string pattern, string text)
{
    std::vector<unsigned long long> hashes;
    int tDif = text.size() - pattern.size();
    hashes.resize(tDif + 1);
    unsigned long long p = 999331;
    int x = 263;
   
    hashes[tDif] = calculateHash(text.substr(tDif));

    unsigned long long pot = 1;
    for (int i = 0; i < pattern.size(); i++)
    {
        pot = (pot * x) % p;
    }

    for (int i = tDif - 1; i >= 0; i--)
    {
        hashes[i] = (((hashes[i+1] * x) % p + text[i]) % p - (text[i + pattern.size()] * pot)%p + p) % p;
    }
    return hashes;
}

std::vector<int> get_occurrences(const Data& input) {
    const string s = input.pattern, t = input.text;
    std::vector<int> ans;
    std::vector<unsigned long long> hashValues = precomputeHashes(s, t);
    unsigned long long targetHash = calculateHash(s);
    for (int i = 0; i + s.size() <= t.size(); ++i)
    {
        if(targetHash == hashValues[i]){
            if (t.substr(i, s.size()) == s)
            {
                ans.push_back(i);
            }
        }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
