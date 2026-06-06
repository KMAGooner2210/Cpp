#include "config.h"
#include <iostream>

void print_config_from_B();

int main(){
	std::cout << "[Module A] global_config address: " << &global_config << " | value: " << global_config <<"\n";
	print_config_from_B();
	return 0;
}
