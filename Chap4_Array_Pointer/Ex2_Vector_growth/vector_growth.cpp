#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    std::cout << "=== KHAO SAT DONG LUC TANG TRUONG VECTOR ===" << std::endl;
    std::cout << "Trang thai dau: Size = " << vec.size() << ", Capacity = " << vec.capacity() << "\n\n";

    size_t previous_capacity = 0;

    for (int i = 1; i <= 20; ++i) {
        vec.push_back(i);
        
        size_t current_capacity = vec.capacity();
        std::cout << "Chen phan tu " << i << " -> Size = " << vec.size() << ", Capacity = " << current_capacity;

        if (current_capacity != previous_capacity) {
            std::cout << "   <-- [REALLOCATED!  " 
                      << (previous_capacity == 0 ? 0 : (double)current_capacity / previous_capacity) 
                      << " lan]";
            previous_capacity = current_capacity;
        }
        std::cout << std::endl;
    }

    return 0;
}
