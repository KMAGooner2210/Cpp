#include<iostream>
#include<chrono>
#include<string>

int main(int argc, char* argv[]){
	bool fast_mode = false;
	
	//kiem tra tham so truyen vao tu terminal
	if(argc > 1 && std::string(argv[1]) == "fast"){
		fast_mode = true;
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
	}

	auto start = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000000; ++i){
		std::cout << "Testing line output number: " << i << "\n";
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;

	std::cerr << "\n" << (fast_mode ? "[FAST MODE ON] " : "[SLOW MODE DEFAULT] ")
		  << "Thoi gian thuc thi 1 trieu line: " << diff.count() << "seconds.\n";
	return 0;
}
