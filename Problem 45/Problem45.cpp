#include <iostream>

long long triagonal(long long n)
{
    return n * (n + 1) / 2;
}

long long pentagonal(long long n)
{
    return n * (3 * n - 1) / 2;
}

long long hexagonal(long long n)
{
    return n * (2 * n - 1);
}

int main()
{
    long long tri = 285, pen = 165, hexa = 144;
    while (triagonal(tri) != pentagonal(pen) ||
           pentagonal(pen) != hexagonal(hexa) ||
           hexagonal(hexa) != triagonal(tri))
    {
        if (hexagonal(hexa) < pentagonal(pen) &&
             hexagonal(hexa) < triagonal(tri))
        {
            hexa++;
        }
        else if (pentagonal(pen) < triagonal(tri))
        {
            pen++;
        }
        else
        {
            tri++;
        }
    }
    std::cout << tri << " " << pen << " " << hexa << " " << std::endl;
    std::cout << triagonal(tri) << " " << pentagonal(pen) << " " << hexagonal(hexa) << " " << std::endl;
    return 0;
}