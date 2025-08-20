#include <bits/stdc++.h>
using namespace std;

class BloomFilter {
private:
    int m;                 // Size of the bit array
    int k;                 // Number of hash functions
    vector<bool> bitArray; // Bit array
    mutex mtx;             // Mutex for thread safety

    // Simple hash function 1: sum of ASCII values, mod m
    int hash1(const string& s) const {
        int hash = 0;
        for (char c : s) hash += c;
        return hash % m;
    }

    // Simple hash function 2: rolling hash with prime base, mod m
    int hash2(const string& s) const {
        int hash = 0, prime = 31;
        for (char c : s) hash = hash * prime + c;
        return hash % m;
    }

    // Generate k hash values using double hashing
    vector<int> getHashes(const string& s) const {
        vector<int> hashes;
        int h1 = hash1(s);
        int h2 = hash2(s);
        for (int i = 0; i < k; ++i) {
            hashes.push_back((h1 + i * h2) % m);
        }
        return hashes;
    }

public:
    BloomFilter(int bitArraySize, int numHashFuncs)
        : m(bitArraySize), k(numHashFuncs), bitArray(bitArraySize, false) {}

    void add(const string& s) {
        auto hashes = getHashes(s);
        lock_guard<mutex> lock(mtx);
        for (auto idx : hashes) bitArray[idx] = true;
    }

    bool mightContain(const string& s) {
        auto hashes = getHashes(s);
        lock_guard<mutex> lock(mtx);
        for (auto idx : hashes) {
            if (!bitArray[idx]) return false;
        }
        return true;
    }
};

int main() {
    BloomFilter bf(1000, 5);

    bf.add("hello");
    bf.add("world");

    cout << "hello: " << bf.mightContain("hello") << endl;
    cout << "welcome: " << bf.mightContain("welcome") << endl;
    cout << "world: " << bf.mightContain("world") << endl;

    return 0;
}
