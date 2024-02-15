// Бодлого 4
#include<iostream>

using namespace std;

// Сондгой тоонуудын нийлбэр болон арифметик дундаж олох дотоод функц
inline void ArithmeticOdds(int N, int a[]) {

    // Нийлбэр болон тоолуур хувьсагч
    int sumOfOdds = 0, countOfOdds = 0;

    for(int i = 0; i < N; i++)
        /* 
        Аливаа сондгой тоо 2-т ийн тооллын системд үргэлж 1 - ээр төгсдөг учир 
        Логик AND(&) оператор ашиглана 1-т AND хийвэл сондгой бол 1
        Тэгш бол 0 гардаг.
        */
        if(a[i] & 1) {
            sumOfOdds += a[i];
            countOfOdds++;
        }
    
    cout << "Сондгой тоонуудын арифметик дундаж: " << sumOfOdds / countOfOdds;

}

int main() {

    // Хувьсагч зарлах
    int N;

    cout << "N: ";
    // N-г гараас авах
    cin >> N;

    // N Ширхэг элемент авах хүснэгт зарлах
    int a[N];

    // N Ширхэг элементийг гараас авах
    for(int i = 0; i < N; i++)
        cin >> a[i];

    // Дотоод функцийг дуудах
    ArithmeticOdds(N, a);

}