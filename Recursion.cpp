#include <iostream>
#include <vector>
#include <string>

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

long recFibonacci(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;
    return recFibonacci(n-1) + recFibonacci(n-2);

}

long iterFibonacci(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;

    long f0 = 0;
    long f1 = 1;
    long f2;
    for (int i=2; i<=n; i++) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    return f2;

}

long recFibonacci2Helper(int f0, int f1, int n) {

    if (n == 0) return  f0;
    return recFibonacci2Helper(f1, f0 +  f1, n - 1);

}

long recFibonacci2(int n) {

    return recFibonacci2Helper(0, 1, n);

}

bool isPalindrome(string  word) {

    if (word.size() <= 1) return true;
    if (word[0] == word[word.size() - 1]) {
        return isPalindrome(word.substr(1, word.size()-2));
    } else {
        return false;
    }

}

vector<string> permutations(string w) 
{

    vector<string> result;

    if (w.size() <= 1) {
        result.push_back(w);
        return result;
    }

    for (int i=0; i<w.size(); i++) {

        string letterToRemove = w.substr(i,1);
        string shorterWord = w.substr(0,i) + w.substr(i+1,w.size() - i - 1);
        vector<string> shorterPerms = permutations(shorterWord);
        for (string nextString : shorterPerms) {
            result.push_back(letterToRemove + nextString);
        }

    }

    return result;



}

int main() {

    cout << "Hello World" << endl;

    for (int i=0; i<=10; i++) {

        cout << "iterFactorial(" << i << ") = " << iterFactorial(i) << endl;

    }

    for (int i = 0; i <= 10; i++) {

        cout << "recFactorial(" << i << ") = " << recFactorial(i) << endl;
    }

    for (int i = 0; i <= 100; i++) {

        cout << "iterFibonacci(" << i << ") = " << iterFibonacci(i) << endl;
    }

    for (int i = 0; i <= 100; i++) {

        cout << "recFibonacci2(" << i << ") = " << recFibonacci2(i) << endl;
    }

    // for (int i = 0; i <= 100; i++) {

    //     cout << "recFibonacci(" << i << ") = " << recFibonacci(i) << endl;
    // }

    cout << "radar: " << (isPalindrome("radar") ? "TRUE" : "FALSE") << endl;
    cout << "radal: " << (isPalindrome("radal") ? "TRUE" : "FALSE") << endl;
    cout << "acbcba: " << (isPalindrome("acbcba") ? "TRUE" : "FALSE") << endl;

    string w1 = "eat";
    cout << "Permutations for " << w1 << endl;
    vector<string> eatPerms = permutations(w1);
    for (string next : eatPerms) {
        cout << next << endl;
    }

    string w2 = "bienve";
    cout << "Permutations for " << w2 << endl;
    vector<string> bienvePerms = permutations(w2);
    for (string next : bienvePerms) {
        cout << next << endl;
    }
    
}