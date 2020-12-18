#include <iostream>
#include <array>

struct pair {
    int first;
    double second;
};

int main() {
    const std::size_t size = 5;
    std::array<pair, size> b;
    for (std::size_t i = 0; i < size; ++i) {
        b[i].first = static_cast<int>(i);
        b[i].second = static_cast<double>(i/10) + static_cast<double>(i);
    }

    std::cout << "Size of pair: " << sizeof(pair) << std::endl;
    std::cout << "Size of pair.first: " << sizeof(b[0].first) << std::endl;
    std::cout << "Size of pair.second: " << sizeof(b[0].second) << std::endl;
    std::cout << "Difference between neighborhood"
        << " = " << &b[1] << " - "  << &b[0]
        << " = " << (&b[1] - &b[0]) * sizeof(b[0]) << std::endl; 
    
    std::cout << "Size of array: " << sizeof(b) << std::endl;
    std::cout << "Addres of el.first = addres of begin + n * sizeof(el)" << std::endl;
    std::cout << "Addres of el.second  = addres of begin + n * sizeof(el) + sizeof(el.key)" << std::endl;

    return 0;
}
