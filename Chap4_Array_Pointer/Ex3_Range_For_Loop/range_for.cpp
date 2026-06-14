#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec_modern = {10, 20, 30, 40, 50};
    std::vector<int> vec_under_the_hood = {10, 20, 30, 40, 50};

    // ==========================================
    // CACH 1: Dung cu phap range for (C++11)
    // ==========================================
    std::cout << "--- CACH 1: Range-based For (C++11) ---" << std::endl;
    for (auto& item : vec_modern) {
        item *= 2; 
    }

    for (const auto& item : vec_modern) {
        std::cout << item << " ";
    }
    std::cout << "\n\n";

    // ==========================================
    // CÁCH 2: Mo phong cach compiler bien 
    // ==========================================
    std::cout << "--- CÁCH 2: Trình biên dịch phân rã (Under the hood) ---" << std::endl;
    
    {
        auto&& __range = vec_under_the_hood; 
        
        auto __begin = __range.begin();
        auto __end = __range.end();
        for (; __begin != __end; ++__begin) {
            auto& item = *__begin; 
            item *= 2;             
        }
    }

    {
        auto&& __range = vec_under_the_hood;
        auto __begin = __range.begin();
        auto __end = __range.end();
        for (; __begin != __end; ++__begin) {
            const auto& item = *__begin;
            std::cout << item << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
