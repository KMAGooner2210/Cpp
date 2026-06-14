#include <iostream>
int get_status(){
	return 404;
}

int main(){
	std::cout << "=== Khoi chay kiem tra C++17 If-with-Initializer  ===" << std::endl;

	if(int code = get_status(); code != 0){
		std::cout << "[IF] Phat hien loi! Ma loi: " << code << std::endl;
	}else{
		std::cout << "[ELSE] He thong an toan! Code: " << code << std::endl;
	}
    std::cout << "Co truy cap code: " << code << std::endl;
	return 0;
}
