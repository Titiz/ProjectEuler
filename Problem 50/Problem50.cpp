#include <vector>
#include <iostream>
#include <math.h> 
#include <time.h>

// This response is edited after viewing responses on the Euler page. 
// Heavily influenced by Vasil Raev's response.

#define N 1000000



void Sieve(std::vector<int> &list_of_primes, bool primes[]) {
    for(int i = 0 ; i < N ; i++) {
        primes[i] = true;
    }
    for(long long j = 2 ; j < N ; j++)
            if (primes[j]){
                list_of_primes.push_back(j);
                for(long long t = j*j ; t<N ; t+=j){
                        primes[t] = false;
               }
        }
}

int main() {   
    std::vector<int> primes; 
    bool prime_bool[N] ;
    Sieve(primes, prime_bool);
    int biggest_sum = 0, biggest_count = 0, sum = 0, count = 0;
    for (int i = 2; i < primes.size(); i++, sum = 0, count = 0) {
        int j = i-1;
        while (sum + primes[j] < N) {
            sum += primes[j];
            count ++;
            j++;
        }
        while (true) {
            if (count < biggest_count || sum < biggest_sum) break;
            if (prime_bool[sum] && sum >= biggest_sum) {
                biggest_sum = sum;
                biggest_count = count;
                break;
            } else {
                count -= 1;
                j -= 1;
                sum -= primes[j];
            }
        }
    }

   
    std::cout << biggest_count << std::endl;
    std::cout << biggest_sum << std::endl;

    return 0;
}