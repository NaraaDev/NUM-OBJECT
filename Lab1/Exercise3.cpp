// Бодлого 3
#include<iostream>

using namespace std;

// Тэгш тоог тоолох дотоод функц
inline void countOfEvenNumber(int N, int a[]) 
    {
        // Тоолуур хувьсагч
        int count = 0;  

        for(int i = 0; i < N; i++)
            // Хэрэв a[i] тоог 2-т үлдэгдэлтэй хуваахад 0 байвал тэгш эсвэл сондгой
            count += (a[i] % 2 == 0);

        cout << count << " ширхэг тэгш тоо байна";
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
    
    // Тэгш тоог тоолох дотоод функцыг дуудах
    countOfEvenNumber(N, a);

}