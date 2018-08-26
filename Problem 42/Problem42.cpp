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

set<int> triNumbers;

void createTriNumbers()
{
    for (int i = 1; i < 100; i++)
    {
        triNumbers.insert((i * (i + 1) / 2));
    }
}

string getWord(string s, int &index)
{
    while (s[index] != '"')
        index++;
    index++;
    if (index >= s.length())
    {
        return "###";
    }
    string to_return = "";
    while (s[index] != '"')
    {
        to_return += s[index];
        index++;
    }
    index++;
    return to_return;
}

int getValue(string s)
{
    int summation = 0;
    for (char letter : s)
    {
        summation += letter - 64;
    }
    return summation;
}

int main()
{
    createTriNumbers();
    string s;
    cin >> s;
    cout << s << endl;
    int index = 0;
    int count = 0;
    string word = getWord(s, index);
    while (word != "###")
    {
        cout << word << " " << getValue(word);
        if (triNumbers.find(getValue(word)) != triNumbers.end())
        {
            cout << " YES";
            count++;
        }
        cout << endl;
        word = getWord(s, index);
    }
    cout << count << endl;
}