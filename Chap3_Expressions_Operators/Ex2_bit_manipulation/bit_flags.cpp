#include<iostream>
#include<bitset>

const uint8_t PERM_READ = 1 << 0;      //0000 0001
const uint8_t PERM_WRITE = 1 << 1;     //0000 0010
const uint8_t PERM_EXECUTE = 1 << 2;   //0000 0100

int main(){
	uint8_t system_flags = 0;
	std::cout << "Flags ban dau (nhi phan): " << std::bitset<8>(system_flags) << std::endl;
	
	system_flags = PERM_READ | PERM_WRITE;
	std::cout << "Sau khi cap quyen READ & WRITE: " << std::bitset<8>(system_flags) << std::endl;
	
	bool has_execute = (system_flags & PERM_EXECUTE) != 0;
	std::cout << "He thong co quyen EXECUTE khong? -> " << (has_execute ? "YES" : "NO") << std::endl;
	
	bool has_read = (system_flags & PERM_READ) != 0;
	std::cout << "He thong co quyen READ khong? -> " << (has_read ? "YES" : "NO") << std::endl;
	
	system_flags = system_flags ^ PERM_WRITE;
	std::cout << "Sau khi tat WRITE: " << std::bitset<8>(system_flags) << std::endl;
	
	system_flags = system_flags ^ PERM_WRITE;
	std::cout << "Sau khi bat WRITE: " << std::bitset<8>(system_flags) << std::endl;
	return 0;
}
