



primeCount = 1000000

primes = [True for _ in range(primeCount)]
primeDivisors = [set() for _ in range(primeCount)]

def sieve():
    primes[0] = False
    primes[1] = False
    for i in range(2, primeCount):
        if not primes[i]:
            continue
        primeDivisors[i].add(i)
        for j in range(i+i, primeCount, i):
            primes[j] = False
            primeDivisors[j].add(i)


def checkFourCons(n):
    s = set()
    s1 = primeDivisors[n]
    if (len(s1) != 4):
        return False
    s2 = primeDivisors[n+1]
    if (len(s2) != 4):
        return False
    s3 = primeDivisors[n+2]
    if (len(s3) != 4):
        return False
    s4 = primeDivisors[n+3]
    if (len(s4) != 4):
        return False

    return True

if __name__ == "__main__":
    sieve()
    for i in range(1, primeCount - 3):
        if (checkFourCons(i)):
            print(i)
            break

