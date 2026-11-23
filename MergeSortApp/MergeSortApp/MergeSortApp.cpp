#include <iostream>
#include <vector>
#include "MergeSort.h"

template <typename T>
void wypiszWektor(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
    MergeSort<int> sorterInt;
    std::vector<int> liczbyInt = { 38, 27, 43, 3, 9, 82, 10, -5 };

    std::cout << "Przed sortowaniem (int): ";
    wypiszWektor(liczbyInt);

    sorterInt.sort(liczbyInt);

    std::cout << "Po sortowaniu (int):     ";
    wypiszWektor(liczbyInt);

    MergeSort<double> sorterDouble;
    std::vector<double> liczbyDouble = { 3.14, -2.5, 0.0, 1.41, 2.71, -0.5 };

    std::cout << "\nPrzed sortowaniem (double): ";
    wypiszWektor(liczbyDouble);

    sorterDouble.sort(liczbyDouble);

    std::cout << "Po sortowaniu (double):     ";
    wypiszWektor(liczbyDouble);

    return 0;
}