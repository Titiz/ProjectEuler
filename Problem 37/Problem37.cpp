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
#define P 1000000007ll
#define A 100ll
string s;

bool primes[MAX_N];

void sieve()
{
    fill(begin(primes), end(primes), true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < MAX_N; i++)
    {
        if (!primes[i])
            continue;
        for (int j = i + i; j < MAX_N; j += i)
        {
            primes[j] = false;
        }
    }
}

int getLength(int n)
{
    int length = 1;
    while (n > 10)
    {
        n /= 10;
        length++;
    }
    return length;
}

bool checkLRPrime(int p)
{
    if (!primes[p])
        return false;
    int length = getLength(p);
    for (int i = length; i > 0; i--)
    {
        int power = pow(10, i);
        if (!primes[p % power])
            return false;
    }
    for (int i = length - 1; i >= 0; i--)
    {
        int power = pow(10, i);
        if (!primes[(p - (p % power)) / power])
            return false;
    }
    return true;
}

int main()
{
    sieve();
    long long int s = 0;
    int prime = 11;
    int cnt = 0;
    while (cnt != 11)
    {
        if (checkLRPrime(prime))
        {
            cnt++;
            s += prime;

            cout << prime << " ";
        }
        prime += 2;
    }
    cout << endl
         << s << endl;
}
