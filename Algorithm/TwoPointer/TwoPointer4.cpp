#include <iostream>
#include <fstream>

using namespace std;

int n, s, count;
int N[101];

void input() {
    fstream f("TwoPointer4.inp");
    f >> n >> s;
    for (int i = 0; i < n; i++) {
        f >> N[i];
    } 
}

void numberOfSmallSegment() {
    count = 0;
    int l = 0, r, sum = 0;
    for(int r = 0; r < n; ++r) {
        sum += N[r];
        while(sum > s) {
            sum -= N[l++];
        }
        count += (r - l + 1); // tổng các chuỗi con liên tiếp trong một chuỗi 
    }
}

void numberOfBigSegment() {
    count = 0;
    int l = 0, r, sum = 0;
    for(r = 0; r < n; ++r) {
        sum += N[r];
        while(sum > s) {
            count += (n - 1) - r + 1;
            sum -= N[l++];
        }
    }
}

int main() {
    input();
    numberOfSmallSegment();
    cout << count << "\n"; 
    numberOfBigSegment();
    cout << count << "\n";
    return 1;
}