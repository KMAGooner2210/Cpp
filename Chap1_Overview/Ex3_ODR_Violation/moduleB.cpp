#include<iostream>
#include "global.h"

void process_B(){
	app_state += 5;
	std::cout << "Gia tri app_state tai module B: " << app_state << std::endl;
}
