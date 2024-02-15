// Бодлого 2
#include<iostream>

using namespace std;

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
    
    // Хамгийн бага болон их тоонуудын хувьсагчийг зарлах мөн хүснэгтийн эхний тоог оноох
    int minValue = a[0], maxValue = a[0];
    // 1 - N хүртэл давталт гүйх
    for(int i = 1; i < N; i++) {

        // minValue нь тухайн a[i] тооноос их үед minValue-д a[i]-г оноох
        minValue = minValue > a[i] ? a[i] : minValue;
        // maxValue нь тухайн a[i] тооноос бага үед maxValue-д a[i]-г оноох
        maxValue = maxValue < a[i] ? a[i] : maxValue;

    }

    cout << "Хамгийн их тоо: " << maxValue << '\n';
    cout << "Хамгийн бага тоо: " << minValue << '\n';

}