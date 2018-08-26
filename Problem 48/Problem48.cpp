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
string s;

long long int power(long long int x)
{
    long long int answer = x;
    for (int i = 1; i < x; i++)
    {
        answer = ((answer % P) * (x % P)) % P;
    }
    return answer % P;
}

long long int evalPower(int upper)
{
    long long int s = 0;
    for (int i = 1; i <= upper; i++)
        s = (s + power(i) % P) % P;
    return s % P;
}

int main()
{
    cout << evalPower(1000) << endl;
}
