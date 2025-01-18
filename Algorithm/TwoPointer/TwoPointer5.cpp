#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int N[101];
int n, k, Count;
multiset<int> mts;



void input() {
    fstream f("TwoPointer5.inp");
    f >> n >> k;
    for(int i = 0; i < n; ++i) {
        f >> N[i];
    }
}

void segmentWithSmallSpread() {
    int l = 0, r;
    Count = 0; 
    int Min = N[0], Max = 0;
    for(r = 0; r < n; ++r) {
        mts.insert(N[r]);
        while(*mts.rbegin() - *mts.begin() > k) {
            auto it = mts.find(N[l++]);
            mts.erase(it);
        }
        Count += r - l + 1;
    }
}

int main() {
    input();
    segmentWithSmallSpread();
    cout << Count << endl;
    return 0;
}