#include <iostream>

int main(){
	volatile bool is_admin = false;
	volatile int buffer[4] = {0, 0, 0, 0};

	std::cout << "=== DIA CHI STACK ===" << std::endl;
	std::cout << "Dia chi cua is_admin:                " << (void*)&is_admin << std::endl;
	std::cout << "Dia chi cua dau mang buffer:         " << (void*)buffer << std::endl;
	std::cout << "Dia chi cua phan tu buffer[4]:             " << (void*)&buffer[4] << std::endl;
	

	std::cout << "\n=== TRUOC KHI TRAN BO DEM ===" << std::endl;
	std::cout << "Trang thai quyen is_admin: " << (is_admin ? "TRUE (ADMIN)" : "FALSE (GUEST)") << std::endl;
    	std::cout << "\n[!] Dang ghi de du lieu ngoai bien: buffer[4] = 1, buffer[5] = 1..." << std::endl;
    	buffer[4] = 1; 
    	buffer[5] = 1; // Ghi thêm đề phòng Compiler tự động căn chỉnh bộ nhớ (Alignment padding)
	
    	std::cout << "\n=== SAU KHI TRAN BO DEM ===" << std::endl;
    	std::cout << "Trang thai quyen is_admin: " << (is_admin ? "TRUE (ADMIN)" : "FALSE (GUEST)") << std::endl;
	
	return 0;
}
