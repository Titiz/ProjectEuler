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
string s;
int n;
vector<int> d;

int main()
{
    d.push_back(-1);
    for (int i = 1; i < 10000; i++)
    {
        int s = 0;
        for (int j = 1; j < sqrt(i); j++)
        {
            if (i % j == 0)
            {
                s += j;
                if (j != i / j)
                    s += i / j;
            }
        }
        s -= i;
        d.push_back(s);
    }
    int s = 0;
    for (int i = 1; i < 10000; i++)
    {
        for (int j = 1; j < 10000; j++)
        {
            if (d[i] == j && d[j] == i && i != j)
            {
                s += j;
            }
        }
    }
    cout << s << endl;
}