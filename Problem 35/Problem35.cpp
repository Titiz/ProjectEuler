#include <vector>
#include <math.h>
#include <iostream>
#include <string>

void Sieve(std::vector<int> &list_of_primes, bool primes[], int N) {
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

int get_length_of_number(int n) {
    int num_digits = 0;
    if (n > 0)
    num_digits = int(log10(n))+1;
    else if (n == 0)
    num_digits = 1;
    else
    num_digits = int(log10(-n))+2;

    return num_digits;
}

void shift_by_one(int *array, int length) {
    int tmp = array[0];
    int tmp2 = array[1];
    array[0] = array[length-1];
    for (int i = 1; i < length; i++) {
        tmp2 = array[i];
        array[i] = tmp;
        tmp = tmp2;
    }
}

bool is_circular_prime(long long prime, bool primes_bools[])
{
    int length = get_length_of_number(prime);
    int *digits = new int[length];
    int divisor = 1;
    for (int k = 0; k < length; k++) {
        divisor = pow(10, length-k-1);
        int result = int(prime/divisor);
        digits[k] = result;
        prime -= result * pow(10, length-k-1);
    }
    
    for (int i = 0; i < length; i++) {
        shift_by_one(digits, length);
        int value = 0;
        for (int j = 0; j < length; j++) {
            value += digits[j] * pow(10, length - j - 1);
        }
        if (!primes_bools[value]){
            delete[] digits;
            return false;
        }
    }
    delete[] digits;
    return true;

}

int main() {
    bool prime_bools[1000000];
    std::vector<int> primes;
    Sieve(primes, prime_bools, 1000000);
    int count = 0;
    for (int i = 0; i < primes.size(); i++) {
        if(is_circular_prime(primes[i], prime_bools)) count++;
    }
    std::cout << count;
}