#include <array>
#include <iostream>

// Helper function to swap two elements at compile time
template <typename T>
constexpr void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Recursive compile-time sorting function (bubble sort)
template <typename T, std::size_t N, std::size_t I = 0>
constexpr void bubble_sort(std::array<T, N>& arr) {
    if constexpr (I < N - 1) {
        for (std::size_t j = 0; j < N - I - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        bubble_sort<T, N, I + 1>(arr);
    }
}

int main() {
    constexpr std::array<int, 6> unsortedArray = {5, 2, 9, 1, 5, 6};
    std::array<int, 6> sortedArray = unsortedArray;

    // Sorting at compile time
    bubble_sort(sortedArray);

    std::cout << "Unsorted Array: ";
    for (int value : unsortedArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted Array: ";
    for (int value : sortedArray) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
