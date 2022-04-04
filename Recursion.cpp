#include <iostream>

using namespace std;

long iterFactorial(int n) {

    long product = 1;
    for (int i=1; i<=n; i++) {
        product *= i;
    }
    return product;
}

long recFactorial(int n) {

    if (n == 0) {
        return 1;
    } else {
        return n * recFactorial(n - 1);
    }
}

int main() {

    cout << "Hello World" << endl;

    for (int i=0; i<=10; i++) {

        cout << "iterFactorial(" << i << ") = " << iterFactorial(i) << endl;

    }

    for (int i=0; i<=10; i++) {

        cout << "recFactorial(" << i << ") = " << recFactorial(i) << endl;

    }
    
}