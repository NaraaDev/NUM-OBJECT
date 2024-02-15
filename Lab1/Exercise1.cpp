// Бодлого 1
#include<iostream>

using namespace std;

// 3 Тооны хамгийн их тоо буцаах макро функц.
#define MaxOfThreeVal(a, b, c) ((a >= b && a >= c) ? (a) : ((b >= a && b >= c) ? (b) : (c) ))


int main() {
    // Хувьсагч зарлах
    int a, b, c;
    // Гараас утга авах
    cin >> a >> b >> c;
    
    cout << "3 тооны хамгийн их тоо :" << MaxOfThreeVal(a, b, c) << '\n';
}