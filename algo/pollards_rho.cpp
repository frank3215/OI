#include <iostream>
using namespace std;

int gcd(int a, int b) {
        int rem;
        while (b != 0) {
                rem = a % b;
                a = b;
                b = rem;
        }
        return a;
}

int main () {
        int number = 10403, x_fixed = 2, cycle_size = 2, x = 2, factor = 1;

        while (factor == 1) {
                for (int count=1;count <= cycle_size && factor <= 1;count++) {
                        x = (x*x+1)%number;
                        factor = gcd(x - x_fixed, number);
                }

                cycle_size *= 2;
                x_fixed = x;
        }
        cout << "\nThe factor is  " << factor;
}
