

if __name__ == "__main__":
    s = "."
    number = 1
    while(len(s) < 1e6):
        s += str(number)
        number += 1
    print(len(s))
    product = 1
    for i in range(6):
        p = pow(10, i)
        product *= int(s[p])
    print(s[1], s[10])
    print(product)

