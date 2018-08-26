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
long long int facts[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main()
{
    for (int i = 0; i < 9999999; i++)
    {
        int k = i;
        int length = 1;
        long long int s = 0;
        while (k > 10)
        {
            k /= 10;
            length++;
        }
        int place = pow(10, length - 1);
        k = i;
        for (int j = 0; j < length; j++)
        {
            int index = k / place;
            // cout << index << endl;
            s += facts[index];
            k %= place;
            place /= 10;
        }
        if (i == s)
        {
            cout << s << endl;
        }
    }
}