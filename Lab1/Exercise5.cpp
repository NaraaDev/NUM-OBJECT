// Бодлого 5
#include<iostream>

using namespace std;

// Орон болон цифр олох дотоод функц
inline [] NumberOfDigit(int N) {

    int countOfDigits = 0, copyNum = N;
    // Тоог 10-т хуваах зарчмаар оронг нэгээр багасгах
    while(N > 0) {
        N /= 10;
        countOfDigits++;
    }
    // Цифр хадгалах хүснэгт үүсгэх
    int digits[countOfDigits], index = countOfDigits - 1;

    // Модулар арифметик ашиглана сүүлийн цифрийг салгаж авах
    while(copyNum > 0) {
        digits[index] = copyNum % 10;
        copyNum /= 10;
        index--;
    }

    cout << "Орон: " << countOfDigits << '\n';
    cout << "Цифрүүд: ";

    for(int i = 0; i < countOfDigits; i++)
        cout << digits[i] << ' ';

}

int main() {
    // Хувьсагч зарлах
    int N;

    cout << "Натурал тоо: ";
    // Натурал тоог гараас авах
    cin >> N;

    int digits[] = NumberOfDigit(N);

}