#include <iostream>

// 1. constexpr: co the tinh luc bien dich hoac run-time
constexpr int factorial(int n){
	return (n <= 1) ? 1 : (n * factorial(n-1));
}

// 2. consteval: chi duoc tinh luc bien dich
consteval int strict_factorial(int n){
	return (n <= 1) ? 1 : (n * strict_factorial(n - 1));
}

int main(){
	int static_array[strict_factorial(5)];
	int array_size = sizeof(static_array) / sizeof(static_array[0]);
	std::cout << "Kich thuoc mang tinh da duoc tao: " << array_size << "phan tu." << std::endl;
	
	int dynamic_val = 6;
	std::cout << "constexpr factorial(6) tai run-time: " << factorial(dynamic_val) << std::endl;
    int run_time_var = 5;
    int result = strict_factorial(run_time_var);
	return 0;
}

