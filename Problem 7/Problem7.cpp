/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?*/

// We will attempt to use the sieve of Eratosthenes for this problem

#include <vector>
#include <iostream>

void Sieve(std::vector<int> &list_of_primes, bool primes[], int N)
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

int main()
{
    std::vector<int> list_of_primes;
    bool primes[150000];
    Sieve(list_of_primes, primes, 150000); // generate enough primes to have 10001 in there
    std::cout << list_of_primes.size() << std::endl;
    std::cout << list_of_primes[10001] << std::endl;
    return 0;
}