#include <cstddef>  // Include for size_t
#include <array>
template <typename T, size_t Size>
constexpr int binary_search(const T& t, const std::array<T, Size>& arr, int low = 0, int high = -1) {
    if (high == -1) {
        high = Size - 1;
}
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == t)
            return mid;
        if (arr[mid] < t)
            low = mid + 1;
        else
            high = mid - 1;
    return -1;
} }
int main() {
    constexpr std::array<int, 10> intArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    constexpr int result = binary_search(5, intArray);
    static_assert(result != -1, "Element not found at compile-time");
    constexpr std::array<double, 5> doubleArray = {1.1, 2.2, 3.3, 4.4, 5.5};
    constexpr int doubleResult = binary_search(3.3, doubleArray);
    static_assert(doubleResult != -1, "Element not found at compile-time");
    constexpr std::array<char, 5> charArray = {'a', 'b', 'c', 'd', 'e'};
    constexpr int charResult = binary_search('o', charArray);
    static_assert(charResult == -1, "Element found at compile-time");
return 0;
 }

