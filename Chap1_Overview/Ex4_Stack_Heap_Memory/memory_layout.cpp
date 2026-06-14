#include<iostream>

int main(){
	int stack_var1 = 10;
	int stack_var2 = 20;
	
	std::cout <<"=== VUNG NHO STACK ===" << std::endl;
	std::cout <<"Dia chi stack_var1: " << &stack_var1 << std::endl;
	std::cout <<"Dia chi stack_var2: " << &stack_var2 << std::endl;
	
	//Ep kieu con tro ve so nguyen (long) de tinh khoang cach theo byte
	long stack_diff = reinterpret_cast<long>(&stack_var2) - reinterpret_cast<long>(&stack_var1);
	std::cout << "Chieu dich chuyen Stack (var2 - var1): " << stack_diff << " bytes\n\n";
	
	int* heap_var1 = new int(10);
	int* heap_var2 = new int(20);

	std::cout << "=== VUNG NHO HEAP ===" << std::endl;
	std::cout << "Dia chi heap_var1:   " << heap_var1 << std::endl;
	std::cout << "Dia chi heap_var2:   " << heap_var2 << std::endl;

	long heap_diff = reinterpret_cast<long>(heap_var2) - reinterpret_cast<long>(heap_var1);
	std::cout << "Chieu dich chuyen Heap (var2 - var1): " << heap_diff << "bytes\n";
	
	delete heap_var1;
	delete heap_var2;

	return 0;
}
