#include <list>
#include <iostream>
#include <math.h> 






std::list<int> Sieve(int n) {
    std::list<int> list_of_primes;
    for (int i = 2; i < n; i++) list_of_primes.push_back(i);
    int p = 2;
    std::list<int>::const_iterator it = list_of_primes.begin();
    while (p < sqrt(list_of_primes.back())){
    list_of_primes.remove_if([p](int n){ return n % p == 0 && n != p; });
    it ++;
    std::cout << "CURRENT PRIME:" << p << std::endl; 
    p = *it;
    }
    return list_of_primes;
}

void find_consecutive_prime_sum(std::list<int>::const_iterator it, std::list<int> primes, int &biggest_count, int &prime, int max_length){
    int sum = 0;
    int count = 0;
    int iteration_count = 0;
    int p = *it;
    std::cout << "CURRENTLY TESTING: " << p << std::endl;
    while(true) {
        iteration_count ++;
        sum += *it;
        if (sum > 1000000) break;
        it++;
        count++;
    }
    sum -= *it;
    while(true) {
        
        

        if (count < biggest_count) {
            return;
        }
        if (std::find(primes.begin(), primes.end(), sum) != primes.end()) {
            p = *it;
            biggest_count = count;
            prime = sum;
            return;
        } else {
            count -= 1;
            it --;
            sum -= *it;
        }
    }
}

int main() {

    std::list<int> primes = Sieve(1000000);
    int biggest_sequence = 0;
    int prime = 0;

    int max_length = 0;
    int summation = 0;
    std::list<int>::const_iterator it = primes.begin();
    while(summation + *it < 1000000) {
        summation += *it;
        it ++;
        max_length += 1;
    }

    for (std::list<int>::const_iterator it = primes.begin(); it != primes.end(); it++) {
        if (*it > 1000000) break;
        find_consecutive_prime_sum(it, primes, biggest_sequence, prime, max_length);
    }
    std::cout << prime;
    return 0;
}