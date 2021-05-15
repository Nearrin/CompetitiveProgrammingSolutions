#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
namespace vs {
template <typename A, typename B> B convert(A a) {
    std::stringstream ss;
    ss << a;
    B b;
    ss >> b;
    return b;
}
template <typename A> std::string numtoen(A a) {
    std::function<std::string(A)> f = [](A b) {
        if (b == A(0))
            return "zero";
        if (b == A(1))
            return "one";
        if (b == A(2))
            return "two";
        if (b == A(3))
            return "three";
        if (b == A(4))
            return "four";
        if (b == A(5))
            return "five";
        if (b == A(6))
            return "six";
        if (b == A(7))
            return "seven";
        if (b == A(8))
            return "eight";
        if (b == A(8))
            return "eight";
    };
}
} // namespace vs

using namespace std;
string func(int s) {
    if (s == 0)
        return "";
    if (s == 1)
        return "-one";
    else if (s == 2)
        return "-two";
    else if (s == 3)
        return "-three";
    else if (s == 4)
        return "-four";
    else if (s == 5)
        return "-five";
    else if (s == 6)
        return "-six";
    else if (s == 7)
        return "-seven";
    else if (s == 8)
        return "-eight";
    else if (s == 9)
        return "-nine";
}
int main() {
    int s;
    cin >> s;
    s = vs::convert<int, int>(s);
    if (s == 0)
        cout << "zero" << endl;
    else if (s == 1)
        cout << "one" << endl;
    else if (s == 2)
        cout << "two" << endl;
    else if (s == 3)
        cout << "three" << endl;
    else if (s == 4)
        cout << "four" << endl;
    else if (s == 5)
        cout << "five" << endl;
    else if (s == 6)
        cout << "six" << endl;
    else if (s == 7)
        cout << "seven" << endl;
    else if (s == 8)
        cout << "eight" << endl;
    else if (s == 9)
        cout << "nine" << endl;
    else if (s == 10)
        cout << "ten" << endl;
    else if (s == 11)
        cout << "eleven" << endl;
    else if (s == 12)
        cout << "twelve" << endl;
    else if (s == 13)
        cout << "thirteen" << endl;
    else if (s == 14)
        cout << "fourteen" << endl;
    else if (s == 15)
        cout << "fifteen" << endl;
    else if (s == 16)
        cout << "sixteen" << endl;
    else if (s == 17)
        cout << "seventeen" << endl;
    else if (s == 18)
        cout << "eighteen" << endl;
    else if (s == 19)
        cout << "nineteen" << endl;
    else if (s < 30) {
        cout << "twenty" + func(s % 10) << endl;
    } else if (s < 40) {
        cout << "thirty" + func(s % 10) << endl;
    } else if (s < 50) {
        cout << "forty" + func(s % 10) << endl;
    } else if (s < 60) {
        cout << "fifty" + func(s % 10) << endl;
    } else if (s < 70) {
        cout << "sixty" + func(s % 10) << endl;
    } else if (s < 80) {
        cout << "seventy" + func(s % 10) << endl;
    } else if (s < 90) {
        cout << "eighty" + func(s % 10) << endl;
    } else {
        cout << "ninety" + func(s % 10) << endl;
    }

    return 0;
}