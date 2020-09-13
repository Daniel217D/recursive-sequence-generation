#include <iostream>

using namespace std;

class Generator {
private:
    int amount;
    int zero = 1;
    int one = 0;

    void generate_rec(string str, int zero, int one) {
        if (this->amount == 0) {
            return;
        }

        if (zero > 0) {
            string temp = str;
            temp.push_back('0');
            generate_rec(temp, zero - 1, one);
        }

        if (one > 0) {
            string temp = str;
            temp.push_back('1');
            generate_rec(temp, zero, one - 1);
        }

        if (zero == 0 && one == 0) {
            this->amount--;
            cout << str << "\n";
        }
    }

public:
    void generate(int amount) {
        this->amount = amount;
        while (this->amount > 0) {
            if (this->zero > 0) {
                generate_rec("0", this->zero - 1, this->one);
            }

            if (this->one > 0) {
                generate_rec("1", this->zero, this->one - 1);
            }

            if (this->one - this->zero < 3) {
                this->one++;
            } else {
                this->zero += 2;
                this->one = 0;
            }
        }
    }
};

int main() {
    (new Generator)->generate(5);

    return 0;
}