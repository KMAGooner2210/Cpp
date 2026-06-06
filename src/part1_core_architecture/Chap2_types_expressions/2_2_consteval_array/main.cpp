#include <iostream>
#include <array>

consteval std::array<int, 10> generate_squares(){
	std::array<int, 10> arr {};
	for (size_t i = 0; i < 10; ++i){
		int val = static_cast<int>(i+1);
		arr[i] = val * val;
	}
	return arr;
}

int main(){
	constexpr auto squares = generate_squares();
	for (int x : squares){
		std::cout << x << " ";
	}
	std::cout << "\n";
	return 0;
}
