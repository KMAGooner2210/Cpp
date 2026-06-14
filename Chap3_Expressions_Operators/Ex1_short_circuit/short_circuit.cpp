#include <iostream>

int global_counter = 0;

bool check_first(){
	std::cout << "[X] Ham check_first() dang duoc goi!" << std::endl;
	return false;
}

bool check_second(){
	std::cout << "[V] Ham check_second() dang duoc goi" << std::endl;
	global_counter++;
	return true;
}

int main(){
	std::cout << "=== Kiem tra phep AND (&&) ===" << std::endl;
	
	if(check_first() && check_second()){
		std::cout << "Thoa man dieu kien" << std::endl;
	} else {
		std::cout << "Khong thoa man dieu kien" << std::endl;
	}
	std::cout << "Gia tri global_counter hien tai: " << global_counter << std::endl;
	
	std::cout << "=== Kiem tra phpe OR (|) ===" << std::endl;
	if(true || check_second()){
		std::cout <<"Dieu kien thoa man" << std::endl;
	}
	std::cout << "Gia tri global_counter cuoi cung: " << global_counter << std::endl;
	return 0;
}
