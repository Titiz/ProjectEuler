

class Prime():
    def __init__(self, value):
        self.permutations = []
        self.value = value
        self.next = None
        self.previous = None




# Define a function that checks whether two numbers are permutations of each other:

def is_permutation(prime1, prime2):
    primel1 = list(str(prime1.value))
    primel2 = list(str(prime2.value))
    primel1.sort()
    primel2.sort()
    if (primel1 == primel2):
        return True
    return False

# Define a function to find all the permutations of a given prime

def find_permutable_primes(primes):
    for i in range(len(primes)):
        print("finding permutable primes", i)
        for j in range(i+1, len(primes)):
            if is_permutation(primes[i], primes[j]):
                primes[i].permutations.append(primes[j])
                primes[j].permutations.append(primes[i])
        primes[i].permutations.append(primes[i])
        primes[i].permutations.sort(key=lambda x: x.value, reverse=False)
        string =  ""
        for item in primes[i].permutations:
            string += str(item.value) +  ", " 
        print(string)


# Define a function to remove all primes that have less than 3 primes:
def remove_unpermutable_primes(primes):
    for prime in primes:
        if len(prime.permutations) < 3:
            primes.remove(prime)

# Define find all primes that fit our criteria using the remaining primes
def find_candidates(primes):
    candidates = []
    for prime in primes:
        for i in range(len(prime.permutations)):
            for j in range(i+2, len(prime.permutations)):
                middle_value = int((prime.permutations[j].value - prime.permutations[i].value)/2 + prime.permutations[i].value)
                candidate = next((x for x in prime.permutations if x.value == middle_value), None)
                if candidate is not None:
                    if candidate not in candidates:
                        candidate.next = prime.permutations[j].value
                        candidate.previous = prime.permutations[i].value
                        candidates.append(candidate)
    return candidates






if __name__ == "__main__":
    primes = []

    # Use a lazy way to find all primes
    i = 1001
    j = 3
    while (i < 10000):
        is_prime = True
        print(i)
        if i % 2 == 0:
            i +=1 
            continue
        for j in range(3, i, 2):
            if i % j == 0:
                i += 1
                j = 2
                is_prime = False
                continue
        if is_prime:
            print("was added")
            primes.append(Prime(i))
            j = 2
            i+= 1

    find_permutable_primes(primes)
    remove_unpermutable_primes(primes)
    candidates = find_candidates(primes)
    for candidate in candidates:
        print("VALUE:", candidate.value)
        print("BEFORE:", candidate.previous)
        print("AFTER: ", candidate.next)
        print("STRING:", str(candidate.previous) + str(candidate.value) + str(candidate.next)) #Final answer is printed here.






















