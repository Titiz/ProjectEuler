
#include <vector>
#include <iostream>

#define N 1000000

void Sieve(std::vector<int> &list_of_primes, bool primes[])
{
    for (int i = 0; i < N; i++)
    {
        primes[i] = true;
    }
    for (long long j = 2; j < N; j++)
        if (primes[j])
        {
            list_of_primes.push_back(j);
            for (long long t = j * j; t < N; t += j)
            {
                primes[t] = false;
            }
        }
}

int quadratic(int a, int b, int n)
{
    return int(n * n + a * n + b);
}

int main()
{
    std::vector<int> primes;
    bool prime_bool[N];
    Sieve(primes, prime_bool);
    int g_a = 0, g_b = 0, max_n = 0;
    for (int a = -1000; a < 1000; a++)
    {
        for (int b = -1000; b <= 1000; b++)
        {
            for (int n = 0; prime_bool[quadratic(a, b, n)]; n++)
            {
                if (n > max_n)
                {
                    max_n = n;
                    g_a = a;
                    g_b = b;
                }
            }
        }
    }
    std::cout << "a: " << g_a << "b: " << g_b << std::endl;
    std::cout << "a * b = " << g_a * g_b;
}