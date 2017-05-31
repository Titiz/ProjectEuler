#include <ostream>
#include <sstream>
#include <iostream>
#include <string>



// First we will have all words written out in arrays:

std::string ones[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::string tens[9] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
std::string hundred = "hundred";
std::string tenths[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};


int give_letter_length(int n){
    int length = 0;
    std::ostringstream os;
    os << n;
    std::string digits = os.str();
    std::string::iterator it = digits.begin();
    int num_of_digits = digits.length();
    std::cout << "THE STRING IS " << digits << "AND THE LENGTH IS: " << num_of_digits << std::endl;
    if (num_of_digits > 2){
        length += ones[(int) *it - 49].length(); // ex: three
        std:: cout << ones[(int) *it - 49] << " hundred " << std::endl;
        length += hundred.length(); //hundred
        std::cout << "LENGTH UP TO NOW: " <<length << std::endl;
        it ++;
        std::string::iterator it2 = it;
        it2 ++;
        if (*it != '0' || *it2 != '0') {
            length += 3; // and
            std::cout <<  "and" << std::endl;
            std::cout << "LENGTH UP TO NOW: " << length << std::endl;
        }
    }
    if (num_of_digits > 1) {
    if (*it == '1') {
        it ++;
        length += tenths[(int) *it - 48].length();
        std:: cout << tenths[(int) *it - 48] << std::endl;
        return length;
    } else if (*it != '0') {
        length += tens[(int) *it - 49].length();
        std:: cout << tens[(int) *it - 49] << std::endl;
        it++;
    } else it ++; } 

    std::cout << "LENGTH UP TO NOW: " <<length << std::endl;

    if (*it != '0') {
        std:: cout << "called with index = " << (int)*it - 49 << std::endl;
        length += ones[(int) *it - 49].length();
        std:: cout << ones[(int) *it - 49] << std::endl;
    }
    
    return length;
}




int main() {
    int total_length = 0;
    for (int i = 1; i < 1000; i++) {
        int length = give_letter_length(i);
        std::cout << "length of " << i <<" was: " << length << std::endl;
        total_length += length;
    }
    std::string one_thousand = "onethousand";
    std::cout <<"TOTAL LENGTH: " << total_length + one_thousand.length();
    return 0;
}