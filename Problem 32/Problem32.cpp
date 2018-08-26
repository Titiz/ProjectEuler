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

int digit_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
set<ll> s;

void countDigits(ll number)
{
    ll place = 0;
    ll temp = number;
    while ((number % (int)pow(10, place)) != number)
    {
        int digit = temp % 10;
        // cout << digit << endl;
        digit_count[digit]++;
        temp /= 10;
        place++;
    }
    // cout << endl;
}

bool checkPandigital(ll a1, ll a2)
{
    for (int i = 0; i < 10; i++)
        digit_count[i] = 0;
    ll product = a1 * a2;
    if (product > 100000000)
        return false;
    countDigits(a1);
    countDigits(a2);
    countDigits(product);
    if (digit_count[0] != 0)
        return false;
    for (int i = 1; i < 10; i++)
        if (digit_count[i] != 1)
            return false;
    return true;
}

int main()
{

    for (ll i = 1; i < 50; i++)
    {
        for (ll j = i; j < 2000; j++)
        {
            if (checkPandigital(i, j))
            {
                cout << i << " * " << j << " = " << i * j << endl;
                s.insert(i * j);
            }
        }
    }
    ll sum = 0;
    for (ll number : s)
    {
        sum += number;
    }
    cout << sum << endl;
}
