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
#define MAX_N 1000005
#define MAX_A 105
#define P 10000000000ll
#define A 100ll

vector<pair<int, int>> digits(100);

void createVectors()
{
    for (int i = 10; i < 100; i++)
    {
        int digit1 = i / 10;
        int digit2 = i % 10;
        digits[i].first = digit1;
        digits[i].second = digit2;
    }
}

set<pair<int, int>> ans;

int main()
{
    createVectors();
    for (int i = 10; i < 100; i++)
    {
        for (int j = 10; j < i; j++)
        {
            if (i == j)
                continue;
            if (digits[i].second == 0 || digits[j].second == 0)
                continue;
            if (digits[i].first == digits[j].second && digits[i].second == digits[j].first)
                continue;
            float frac = (float)(i) / (float)(j);
            if (digits[i].first == digits[j].first)
            {
                if (fabs((float)(digits[i].second) / (float)(digits[j].second) - frac) < 0.00001)
                    ans.insert(make_pair(i, j));
            }
            else if (digits[i].second == digits[j].second)
            {
                if (fabs((float)(digits[i].first) / (float)(digits[j].first) - frac) < 0.00001)
                {
                    ans.insert(make_pair(i, j));
                }
            }
            else if (digits[i].first == digits[j].second)
            {
                if (fabs((float)(digits[i].second) / (float)(digits[j].first) - frac) < 0.00001)
                    ans.insert(make_pair(i, j));
            }
            else if (digits[i].second == digits[j].first)
            {
                if (fabs((float)(digits[i].first) / (float)(digits[j].second) - frac) < 0.00001)
                {
                    ans.insert(make_pair(i, j));
                }
            }
        }
    }
    float s = 1;
    for (set<pair<int, int>>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        cout << it->second << " " << it->first << endl;
        s *= (float)it->second / (float)it->first;
    }
    cout << s << endl;
}