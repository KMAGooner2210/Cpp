#include "config.h"
#include <iostream>

void print_config_from_B(){
	std::cout << "[Module B] global_config address: " << &global_config << " | value: " << global_config << "\n";
}

