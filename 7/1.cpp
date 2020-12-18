#include <iostream>
#include <array>

int main() {
    const std::size_t size = 10;
    std::array<int, size> a{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Size of element: " << sizeof(a[0]) << std::endl;
    
    for (std::size_t i = 0; i < size - 1; ++i) {
        std::cout << "Differns between addres of elements "
        << i+1 << ", " << i
        << " = " << &a[i+1] << " - "  << &a[i]
        << " = " << (&a[i+1] - &a[i]) * sizeof(a[0]) << std::endl;
    }

    std::cout << "Size of array: " << sizeof(a) << std::endl;
    std::cout << "Addres of element = addres of begin + n * sizeof(element)" << std::endl;

    return 0;
}
