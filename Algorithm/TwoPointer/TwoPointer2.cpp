#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

int n, m, k = 0;
int N[100], M[100];
int re[200];

void input()
{
    fstream f("TwoPointer2.inp");
    f >> n >> m;
    // for (int &i : N) // nếu mảng kích thước của mảng fit với số phần tử thì có thể dùng cái này
    for (int i = 0; i < n; i++)
    {
        f >>  N[i];
    }
    for (int i = 0; i < m; i++)
    {
        f >>  M[i];
    }
}

void output()
{
    cout << n << " " << m << endl;
    for(int i = 0; i < n; ++i) {
        cout << N[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < m; ++i) {
        cout << M[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < k; ++i) {
        cout << re[i] << " ";
    }
    cout << endl;
}

void reset() {
    memset(re , 0 , sizeof(re));
    k = 0;
}

void countSmaller()
{
    int j = 0;
    int count;
    while(j < m) {
        count = 0;
        for(int i = 0; N[i] < M[j] && i < n; ++i) {
            ++count;
        }
        re[j++] = count; 
    }
    k = j - 1;
}

void countEqual() {
    int j = 0;
    int count = 0;
    while(j < m) {
        for(int i = 0; i < n; ++i) {
            if(N[i] == M[j]) ++count;
        }
        ++j;
    }
    cout << count << endl;
}
int main()
{
    input();
    countSmaller();
    output();
    countEqual();
    return 0;
}