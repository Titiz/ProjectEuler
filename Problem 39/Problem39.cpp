#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <set>
#include <bitset>
#include <unordered_set>
#include <string.h>
#include <math.h>

using namespace std;
typedef long long int ll;
#define REP0(i, n) for (int i = 0; i < n; i++)
#define REP1(i, n) for (int i = 1; i <= n; i++)
#define MAX_LL 9223372036854775807ll
#define MAX_INT 2147483647
#define MAX_N 100005
#define MAX_A 105
#define P 1000000007ll
#define A 100ll

int pCounts[1001] = {0};

int main()
{
    for (int i = 1; i < 1000; i++)
    {
        for (int j = i; j < 1000; j++)
        {
            for (int k = j; k < 1000; k++)
            {
                if (i + k >= j && j + k >= i && j + i >= k && i + j + k <= 1000)
                {
                    if (i * i + j * j == k * k)
                    {
                        if (i + j + k == 120)
                        {
                            cout << i << " " << j << " " << k << endl;
                        }
                        pCounts[i + j + k]++;
                    }
                }
            }
        }
    }

    pair<int, int> indexMax = make_pair(0, 0);
    for (int i = 1; i <= 1000; i++)
    {
        if (indexMax.second < pCounts[i])
        {
            indexMax = make_pair(i, pCounts[i]);
        }
    }
    cout << indexMax.first << " : " << indexMax.second << endl;
}