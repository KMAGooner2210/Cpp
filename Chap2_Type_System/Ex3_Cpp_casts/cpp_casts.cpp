#include <iostream>

int main(){
	std::cout << "=== 1. static_cast (Ep kieu an toan)===" << std::endl;
	double pi = 3.14159;
	
	//static kiem tra 2 kieu co tuong thich khong
	int pi_int = static_cast<int>(pi);
	std::cout << "Double to Int: " << pi_int << std::endl;

	std::cout << "=== 2. const_cast === (Loai bo tinh chat const)" << std::endl;
	int x = 50;
	const int* const_ptr = &x;
	int * modify_ptr = const_cast<int*>(const_ptr);
	*modify_ptr = 100;
	std::cout << "Gia tri x sau khi ghi de qua const_cast: " << x << std::endl;
	
	std::cout << "=== 3. reinterpret_cast (Ep kieu muc bit/con tro)===" << std::endl;
	long long address_val = 0x7FFEEDDCCBBA;
	int* fake_ptr = reinterpret_cast<int*>(address_val);
	std::cout << "Bien so nguyen bi ep thanh con tro mang dia chi: " << fake_ptr << std::endl;
	return 0;
}
