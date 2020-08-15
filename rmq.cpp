#include <bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=c5O7E_PDO4U

#define n 1000

int array[n];
int table[n][n]; //actually the size is n*log(n)

void preprocess()
{
    for (int i = 0; i < n; ++i)
    {
        table[0][i] = array[i];
    }
    for (int j = 1; j <= log(n); ++j)
    {
        for (int i = 0; i + 1 << (j - 1); ++i)
        {
            table[j][i] = min(table[j - 1][i], table[j - 1][i + 1 << (j - 1)]);
        }
    }
}

void query(int l, int r)
{
    int len = r - l + 1;
    int k = log2(len);
    return min(table[k][l], table[k][y + 1 - (1 << k)]);
}