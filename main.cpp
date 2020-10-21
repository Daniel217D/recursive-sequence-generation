#include <iostream>

using std::cin;
using std::cout;
using std::string;

/**
 10. Написать программу генерации m-последовательностей 0 и 1, удовлетворяющих обоим требованиям:
    1) число нулей должно быть нечётно;
    2) число нулей должно быть меньше числа единиц, но не больше, чем на 3.
 */
unsigned int count (string str, char c) {
    unsigned int result = 0;

    for (char i : str) {
        result += i == c;
    }

    return result;
}

class Generator {
private:
    unsigned int r;

    void genetate_r(unsigned int k, string arr = "") {
        if(k == r) {
            unsigned int zeros = count(arr, '0');
            unsigned int ones = count(arr, '1');
            if(zeros % 2 == 0 || ones - zeros > 3) {
                return;
            }
            cout << arr << "\n";
        } else {
            for (unsigned int i = 0; i <= 1; ++i) {
                string temp = arr;
                temp.push_back('0' + i);
                genetate_r(k+1, temp);
            }
        }
    }
public:
    void generate(unsigned int _r) {
        r = _r;
        genetate_r(0);
    }
};

int main() {
    unsigned int r;
    cin >> r;
    (new Generator)->generate(r);

    return 0;
}