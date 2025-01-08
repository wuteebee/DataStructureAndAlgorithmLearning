#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n, s, count = 0;
int N[100];

void input()
{
    fstream f("TwoPointer3.inp");
    f >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        f >> N[i];
    }
}

void output()
{
    for (int i = 0; i < n; ++i)
    {
        cout << N[i] << " ";
    }
    cout << endl;
    cout << count << endl;
}

void smallestSegment() // nhỏ hơn dài nhất 
{
    int l = 0, r, sum = 0;
    count = 0;
    for(r = 0; r < n; ++r) {
        sum += N[r];
        while(sum > s) {
            sum -= N[l++];
        }
        count = max(count, r - l + 1);
    }
}

void biggestSegment() { // lớn hơn ngắn nhất
    int l = 0, r, sum = 0;
    count = n;
    for(r = 0; r < n; ++r) {
        sum += N[r];
        while(sum >= s) {
            count = min(count, r - l + 1);
            sum -= N[l++];
        }
    }
}

int main()
{
    input();
    smallestSegment();
    output();
    biggestSegment();
    output();

    return 0;
}