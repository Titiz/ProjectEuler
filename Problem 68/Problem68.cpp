#include <algorithm>
#include <string>
#include <iostream>

// Here the hope is first that the number 6 is the starting number of the string.



bool summation(int array[])
{
            // std::cout << array[0] << array[1] << array[2];
            // std::cout << array[3] << array[2] << array[4];
            // std::cout << array[5] << array[4] << array[7];
            // std::cout << array[6] << array[7] << array[8];
            // std::cout << array[9] << array[8] << array[1];
            // std::cout << std::endl;
    int sum1 = array[0] + array[1] + array[2];
    int sum2 = array[3] + array[2] + array[4];
    int sum3 = array[5] + array[4] + array[7];
    int sum4 = array[6] + array[7] + array[8];
    int sum5 = array[9] + array[8] + array[1];
    //std::cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << " " << sum5 << " "<< std::endl;
    if (sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum5)
        return true;
    return false;
}

int main()
{
    std::string s = "12345";
    int s2[5] = {7, 8, 9, 10};
    int array[10] = {6, 1, 2, 7, 3, 8, 9, 4, 5, 10};
    std::sort(s.begin(), s.end());
    do{
        array[3] = s2[0];
        array[5] = s2[1];
        array[6] = s2[2];
        array[9] = s2[3];
    do
    {
        array[1] = (int) s[0] - 48;
        array[2] = (int) s[1] - 48;
        array[4] = (int) s[2] - 48;
        array[7] = (int) s[3] - 48;
        array[8] = (int) s[4] - 48;
        if (summation(array)) {
            std::cout << "POSSIBILITY: " << std::endl;
            std::cout << array[0] << array[1] << array[2];
            std::cout << array[3] << array[2] << array[4];
            std::cout << array[5] << array[4] << array[7];
            std::cout << array[6] << array[7] << array[8];
            std::cout << array[9] << array[8] << array[1];
            std::cout << std::endl;
        } 
    } while(std::next_permutation(s.begin(), s.end()));
    } while(std::next_permutation(s2, s2+5) );
    

    return 0;
}
