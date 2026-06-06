#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

int main(){
	double  a = 0.1;
	double  b = 0.2;
	
	if(a + b == 0.3){
		std::cout << "Ket qua: True (a + b bang 0.3)\n";
	}else{
		std::cout << "Ket qua: False (a + b khong bang 0.3)\n";
	}

	std::cout << "Gia tri thuc te cua a:        " << std::setprecision(20) << a << "\n";
	std::cout << "Gia tri thuc te cua b:        " << std::setprecision(20) << b << "\n";
	std::cout << "Gia tri thuc te cua a + b:    " << std::setprecision(20) << a + b << "\n";
	std::cout << "Gia tri thuc te cua 0.3:      " << std::setprecision(20) << 0.3f << "\n";

	return 0;
} 
