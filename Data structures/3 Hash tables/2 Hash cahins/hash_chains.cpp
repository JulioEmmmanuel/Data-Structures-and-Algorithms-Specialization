#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::cin;
using std::list;
using std::string;
using std::vector;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<list<string>> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
        elems.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for(string s: elems[query.ind]){
                std::cout << s << " ";
            }
            std::cout << "\n";
        } else {
            int h = hash_func(query.s);
            auto it = std::find(elems[h].begin(), elems[h].end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems[h].end());
            else if (query.type == "add") {
                if (it == elems[h].end())
                    elems[h].push_front(query.s);
            }
            else if (query.type == "del")
            {
                if (it != elems[h].end())
                    elems[h].erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
