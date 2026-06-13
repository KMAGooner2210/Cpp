
<details>
    <summary><strong>BÀI 1: CƠ SỞ NGÔN NGỮ VÀ CHU TRÌNH BIÊN DỊCH</strong></summary>
	
## **BÀI 1: CƠ SỞ NGÔN NGỮ VÀ CHU TRÌNH BIÊN DỊCH**

### **I.  CÁC CHUẨN C++ VÀ TRIẾT LÝ THIẾT KẾ**

#### **1.1. Quá trình phát triển**

##### **1.1.1. Classic C++:** 
	
*  **C++98:**
		
		* C++98 (ISO/IEC 14882:1998) là phiên bản chuẩn hóa đầu tiên, thiết lập các nền tảng cốt lõi:
			
			*  Lập trình hướng đối tượng: Classes, Inheritance, Polymorphism, Encapsulation.
			
			* Lập trình tổng quát: Templates.
				
			* Thư viện khuôn mẫu chuẩn (STL): các container `vector`, `map`, `list` cùng các thuật toán đi kèm.
				
*  **C++03:**
		
		* Bản sửa chữa lỗi (bug-fix release) nhằm hoàn thiện C++98, không giới thiệu các tính năng ngôn ngữ lớn mới.
				
##### **1.1.2.Modern C++:**
	
*  **C++11:**
		
	* Phiên bản này giới thiệu hàng loạt tính năng then chốt thay đổi cách viết code:
			
		* **Con trỏ thông minh (Smart Pointers):** 
				
			* `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`.
					
			*  Tự động hóa giải phóng bộ nhớ thông qua cơ chế RAII, loại bỏ phần lớn nguyên nhân gây rò rỉ bộ nhớ.
				
		* **Suy luận kiểu tự động (Type Inference):**
				
			* Từ khóa `auto` và `decltype` cho phép compiler tự suy luận kiểu dữ liệu, giảm cú pháp dài dòng.
					
		* **Ngữ nghĩa di chuyển (Move Semantics):**
				
			* Toán tử `&&` (rvalue reference) và `std::move` cho phép chuyển giao quyền sở hữu tài nguyên thay vì sao chép tốn kém.

		* **Biểu thức Lambda**
				
			* Các hàm ẩn danh được định nghĩa trực tiếp tại vị trí sử dụng, cho phép viết mã ngắn gọn 
					
		* **Đa luồng:**
				
			* `std::thread`, `std::mutex`, `std::atomic`
								
*  **C++14 và C++17:**
		
	* Hoàn thiện nền tảng bằng bổ sung các tính năng quan trọng như:
			
		* `std::optional`, `std::variant`, `std::any` — xử lý giá trị tùy chọn và kiểu đa hình an toàn.
				
		* Structured bindings: `auto [key, value] = pair;`
				
		* `if constexpr` — rẽ nhánh tại thời điểm biên dịch.
				
		* Thư viện hệ thống tệp chuẩn hóa: `std::filesystem`. 
				
*  **C++20:**
		
	* Giới thiệu bốn tính năng lớn mang tính kiến trúc:
			
		* **Concepts:** 
				
			* Ràng buộc kiểu cho Templates, biến lỗi Template từ thông báo dài hàng trăm dòng thành thông báo rõ ràng, có ý nghĩa.
				
		* **Modules:** 
		
			* Thay thế cơ chế `#include` bằng cú pháp `import`
				
		* **Coroutines:**
				
			* Nền tảng cho lập trình bất đồng bộ (async/await) tại mức ngôn ngữ.

		* **Ranges**
				
			* Thư viện xử lý dãy dữ liệu theo phong cách hàm, có thể kết hợp pipeline.
							
#### **1.2. Multi-paradigm Programming**	

##### **1.2.1. Định nghĩa**	
	
*  Khác với Java hay C# – những ngôn ngữ hướng đối tượng thuần túy, C++ theo triết lý “cung cấp công cụ, không áp đặt cách sử dụng”.

* C++ là ngôn ngữ đa mô hình (multi-paradigm), cho phép lập trình viên linh hoạt kết hợp nhiều phong cách lập trình trong cùng một dự án:
	
##### **1.2.2.Lập trình thủ tục (Procedural Programming):**
	
*  Tổ chức mã thành các hàm tuần tự, tương tự ngôn ngữ C.

*  Dữ liệu và hành vi tách biệt nhau.

*   Phù hợp cho các tác vụ tuyến tính, kịch bản hệ thống cấp thấp.

		int add(int a, int b) { 
			return a + b; 
		}
		int result = add(3, 5);
	
##### **1.2.3.Lập trình hướng đối tượng (Object Oriented Programming)**
	
*  Đóng gói dữ liệu (data) và hành vi (behavior) vào các thực thể (Objects).

*  Bốn trụ cột: Encapsulation, Inheritance, Polymorphism, Abstraction.
		
*  Phù hợp cho các hệ thống lớn, có mô hình hóa thực thể rõ ràng.

			class Animal {
			public:
			    virtual void speak() = 0; // Giao diện trừu tượng
			};

			class Dog : public Animal {
			public:
			    void speak() override { /* Cài đặt cụ thể */ }
			};
				
##### **1.2.4.Mô hình tổng quát (Generic Programming)**
	
*  Viết mã độc lập với kiểu dữ liệu cụ thể thông qua Templates.

*  Compiler sinh ra mã máy chuyên biệt cho từng kiểu tại thời điểm biên dịch

		template<typename T>
		T maximum(T a, T b) { 
			return (a > b) ? a : b; 
		}

		maximum(3, 5);       // Compiler sinh ra phiên bản int
		maximum(3.14, 2.71); // Compiler sinh ra phiên bản double

##### **1.2.5.Mô hình hàm (Functional Programming)**
	
*  Sử dụng hàm như một thực thể dữ liệu — có thể truyền vào hàm khác, lưu vào biến.

*  Thực hiện qua `std::function`, Lambda expressions, và thư viện Ranges (C++20).

		auto square = [](int x) { 
			return x * x; 
		};
		std::vector<int> nums = {1, 2, 3, 4};
		std::transform(nums.begin(), nums.end(), nums.begin(), square);



#### **1.3. Nguyên lý Zero-overhead Abstraction**	
		
*  Hai quy tắc chính:

	*  **“What you don’t use, you don’t pay for”**
	
		*  Nếu không sử dụng đa hình, trình biên dịch sẽ không sinh ra bảng hàm ảo (vtable)
		
		* Kích thước đối tượng sẽ bằng đúng tổng kích thước các thành viên dữ liệu, tương đương với một struct trong C.  
		
	*  **“What you do use, you couldn’t hand code any better"**
	
		*  Những gì bạn sử dụng, trình biên dịch sẽ tạo ra mã tối ưu đến mức không thể viết tay tốt hơn
		
		*  VD `std::unique_ptr`: 
		
			* Ở mức trừu tượng, nó cung cấp cơ chế quản lý bộ nhớ an toàn tự động; 
			
			* Nhưng ở mức Assembly, trình biên dịch inline toàn bộ logic, khiến hiệu năng và kích thước bằng hoàn toàn với con trỏ thô (raw pointer), không phát sinh chi phí chạy thời gian (run-time overhead).
			
### **II.  BỘ CÔNG CỤ HỖ TRỢ PHÁT TRIỂN**

#### **2.1. Trình biên dịch (Compiler)** 

##### **2.1.1. Định nghĩa**
 
* Phần mềm dịch mã nguồn C++ (ngôn ngữ bậc cao, con người đọc được) sang mã đối tượng (Object code — mã máy nhị phân phụ thuộc kiến trúc vi xử lý).

##### **2.1.2. Các trình biên dịch phổ biến**

* GCC (GNU Compiler Collection)
	
* Clang/LLVM
	
* MSVC (Microsoft Visual C++)
	
##### **2.1.3. Quá trình biên dịch cơ bản**

		# Biên dịch một tệp nguồn thành tệp thực thi
		g++ -std=c++17 -O2 -Wall main.cpp -o my_program

		# Trong đó:
		# -std=c++17 : Sử dụng tiêu chuẩn C++17
		# -O2        : Mức tối ưu hóa 2 (khuyến nghị cho production)
		# -Wall      : Bật toàn bộ cảnh báo (warning)
		# -o         : Chỉ định tên tệp thực thi đầu ra


#### **2.2. Trình liên kết (Linker)** 

##### **2.2.1. Định nghĩa**
 
* Công cụ nối các tệp mã đối tượng riêng lẻ và các thư viện tĩnh/động lại với nhau để tạo thành một tệp thực thi duy nhất.

##### **2.2.2. Đặc điểm**

* Đầu vào của Linker: 

	* Một hoặc nhiều tệp `.o` (object files) và các thư viện `.a` (static) hoặc `.so`/`.dll` (dynamic).  
	
* Đầu ra của Linker: 

	* Tệp thực thi `.exe` (Windows) hoặc tệp ELF không có phần mở rộng (Linux/Unix).	

* Trong thực tế, khi gọi lệnh `g++ main.cpp -o program`, GCC ngầm định thực hiện cả bước biên dịch lẫn liên kết.

* Để tách riêng hai bước:

		g++ -c main.cpp -o main.o      # Chỉ biên dịch → sinh ra object file
		g++ main.o -o program           # Chỉ liên kết → sinh ra executable


#### **2.3. Dynamic Library và Static Library**

##### **2.3.1. Dynamic Library (.so/.dll)**
			
*  Mã thư viện nằm tách biệt, được tải vào bộ nhớ tại thời điểm chạy (runtime).

*  Nhiều chương trình có thể dùng chung một thư viện động
	
* Kích thước tệp nhỏ hơn nhưng phụ thuộc môi trường cài đặt.
	
##### **2.3.2. Static Library (.a/.lib)**
			
*  Mã thư viện được sao chép trực tiếp vào tệp thực thi tại thời điểm liên kết.

*  Tệp thực thi có thể chạy độc lập mà không phụ thuộc vào runtime.
	
* Kích thước tệp lớn hơn.


### **III.  CẤU TRÚC TỆP MÃ NGUỒN C++**

#### **3.1. Đặc tả thư viện chuẩn**
 
##### **3.1.1. Khái niệm**
 
* Mã nguồn C++ tận dụng lại các chức năng đã được tối ưu hóa từ Thư viện chuẩn C++ (C++ Standard Library)


##### **3.1.2. Cú pháp `#include` (Legacy — Tiền xử lý)** 

		#include <iostream>
		#include <vector>
		#include <string>


* **Cơ chế hoạt động:**
 
	* Tiền xử lý (Preprocessor) thay thế dòng `#include <iostream>` bằng cách sao chép toàn bộ nội dung văn bản của tệp header `iostream` vào vị trí đó trong mã nguồn.
	
	* Quá trình này diễn ra trước khi compiler thực sự phân tích mã.


* **Nhược điểm:**
 
	* Mỗi tệp nguồn `.cpp` đều phải biên dịch lại toàn bộ nội dung header, dù header đó không thay đổi.
	
	* Trong dự án lớn, cùng một header có thể được xử lý hàng nghìn lần, gây thời gian biên dịch kéo dài.
	
	* Header Guard (`#ifndef`, `#pragma once`) là biện pháp phòng tránh khai báo trùng lặp, nhưng vẫn không giải quyết triệt để vấn đề tốc độ.
	
##### **3.1.3. Cú pháp `import` (C++20 Modules)** 

		import <iostream>;
		import <vector>;


* **Cơ chế hoạt động:**
 
	* Compiler tải thư viện dưới dạng nhị phân đã biên dịch sẵn (Binary Module Interface — BMI), thay vì xử lý lại văn bản từ đầu mỗi lần.
	
	* Tốc độ biên dịch tăng đáng kể (có thể gấp nhiều lần so với `#include`).
	
	* Loại bỏ hoàn toàn sự phụ thuộc vào thứ tự khai báo và Header Guard. 
	
	* Tách biệt giao diện (interface) và cài đặt (implementation) rõ ràng hơn.  
						
#### **3.2. Namespace**	
		
##### **3.2.1. Vấn đề xung đột tên (Name collision)**	

*  Trong dự án lớn, nhiều thư viện khác nhau có thể định nghĩa các hàm hoặc lớp có cùng tên.

##### **3.2.2. Định nghĩa**	

*  `namespace` là cơ chế nhóm các thực thể (biến, hàm, lớp, kiểu dữ liệu) vào một phạm vi tên cụ thể, tạo ra một "vùng đặt tên" riêng biệt.
	
		namespace Graphics {
		    void init() { /* Khởi tạo hệ thống đồ họa */ }
		    class Renderer { /* ... */ };
		}

		namespace Network {
		    void init() { /* Khởi tạo kết nối mạng */ }
		    class Socket { /* ... */ };
		}



##### **3.2.3. Toán tử phân giải tên (Scope Resolution Operator `::`)**	

*  Để truy cập một thực thể trong namespace, sử dụng toán tử `::`:
	
			Graphics::init();   // Gọi hàm init của Graphics
			Network::init();    // Gọi hàm init của Network — không xung đột

			Graphics::Renderer renderer;
			Network::Socket socket;

##### **3.2.4. Namespace lồng nhau**	

		namespace Company::Project::Module {
		    void execute() { /* ... */ }
		}

		// Truy cập:
		Company::Project::Module::execute();

##### **3.2.5. Chỉ thị using**	

		// Đưa toàn bộ std vào phạm vi hiện tại
		using namespace std;     // Dùng được: cout thay vì std::cout

		// Chỉ đưa một thực thể cụ thể vào phạm vi
		using std::cout;         // Chỉ cout không cần prefix, các thứ khác vẫn cần std::

* **Lưu ý:**

	*  `using namespace std;` trong phạm vi toàn cục (đặc biệt trong tệp header) là **phản khuôn mẫu (anti-pattern)** nghiêm trọng.
	
	*  Nó phá vỡ toàn bộ mục đích bảo vệ của namespace, có thể gây xung đột tên âm thầm và khó phát hiện.
	
	*  Chỉ dùng `using` trong phạm vi hàm cụ thể, hoặc luôn viết đầy đủ `std::cout`, `std::vector`.
					
#### **3.3. Hàm main và mã trạng thái trả về**	
		
##### **3.2.1. Vai trò**
	
*  `main()` là điểm nhập (Entry point) của mọi chương trình C++ độc lập.

* Hệ điều hành nạp chương trình vào bộ nhớ và chuyển quyền điều khiển đến hàm `main`.

* Không có hàm nào khác trong C++ được gọi tự động trước `main` (ngoại trừ constructor của các đối tượng toàn cục)  
	
##### **3.2.2. Hai dạng khai báo chuẩn**
	
		// Dạng 1: Không nhận đối số
		int main() {
		    return 0;
		}

		// Dạng 2: Nhận đối số từ dòng lệnh
		int main(int argc, char* argv[]) {
		    // argc: số lượng đối số (argument count)
		    // argv: mảng chuỗi chứa các đối số (argument values)
		    // argv[0]: luôn là tên chương trình
		    return 0;
		}
	
##### **3.2.3. Exit Code**

* Giá trị nguyên `int` trả về từ `main` được gửi trực tiếp cho hệ điều hành, gọi là Exit Code (mã thoát).

		return 0;             // Thành công — tương đương EXIT_SUCCESS (định nghĩa trong <cstdlib>)
		return 1;             // Lỗi tổng quát
		return EXIT_FAILURE;  // Thất bại — giá trị cụ thể phụ thuộc nền tảng (thường là 1)

* Tiêu chuẩn C++ quy định rằng nếu không có câu lệnh `return` tường minh trong `main`, compiler tự động chèn `return 0;` ở cuối.

* Đây là trường hợp ngoại lệ duy nhất — các hàm khác có kiểu trả về khác `void` mà thiếu `return` là Undefined Behavior.

### **IV.  CƠ CHẾ DỊCH MÃ VÀ PHÂN TÍCH CÚ PHÁP**

#### **4.1. Tiền xử lý, biên dịch và sinh mã hợp ngữ**
 
##### **4.1.1. Bước 1: Tiền xử lý (Preprocessing)**
 
* Công cụ thực hiện: 

	* Preprocessor (thường là một giai đoạn trong compiler, có thể gọi độc lập qua `g++ -E`).
	
*  Xử lý toàn bộ các chỉ thị bắt đầu bằng dấu `#` — đây là các lệnh cho preprocessor, không phải cho compiler.

		#include <vector>       // Sao chép nội dung tệp vector vào đây
		#define MAX_SIZE 1024   // Thay thế toàn bộ MAX_SIZE bằng 1024 trong mã nguồn
		#ifdef DEBUG            // Biên dịch có điều kiện — chỉ khai báo nếu DEBUG được định nghĩa
		    #define LOG(x) std::cout << x
		#else
		    #define LOG(x)      // LOG không làm gì trong bản release
		#endif

*  Đầu ra của bước này: Một tệp văn bản thuần túy (Translation Unit) không còn chứa bất kỳ chỉ thị `#` nào.


##### **4.1.2. Bước 2: Biên dịch (Compilation)**
 
* **Phân tích từ vựng (Lexical Analysis):**

	* Tách mã nguồn thành các token (từ khóa, định danh, toán tử, hằng số).
	
*  **Phân tích cú pháp (Syntax Analysis / Parsing):**

	* Xây dựng cây cú pháp trừu tượng (AST — Abstract Syntax Tree) từ các token, kiểm tra mã có tuân thủ ngữ pháp C++ không. 

*  **Phân tích ngữ nghĩa (Semantic Analysis):**

	* Kiểm tra kiểu dữ liệu, phân giải tên, xác minh tính hợp lệ logic (ví dụ: không thể cộng một `int` với một `struct` không có toán tử `+`).
	
* **Tối ưu hóa (Optimization):**

	* Compiler áp dụng hàng loạt kỹ thuật biến đổi mã để tăng hiệu năng — loại bỏ mã chết (dead code elimination), nội tuyến hàm (function inlining), cuộn vòng lặp (loop unrolling).

* **Sinh mã hợp ngữ (Code Generation):**

	* Xuất ra mã hợp ngữ (Assembly) đặc thù cho kiến trúc đích (x86-64, ARM, RISC-V...).
	
	*  Để quan sát mã Assembly được sinh ra:

			g++ -S -O2 main.cpp -o main.s    # Sinh ra tệp Assembly .s

##### **4.1.3. Bước 3: Assembly**
 
* Trình Assembler chuyển mã hợp ngữ `.s` thành mã máy nhị phân (Binary Machine Code) — chuỗi các byte `0` và `1` mà CPU có thể thực thi trực tiếp.

* Kết quả là tệp đối tượng `.o` (Object file).

		g++ -c main.cpp -o main.o    # Dừng sau bước lắp ráp, sinh ra object file
	
*  Để quan sát nội dung nhị phân của object file:

		objdump -d main.o    # Disassemble — hiển thị lại dạng Assembly từ mã máy
								
#### **4.2. Symbol Table và Name Mangling**	
		
##### **4.2.1. Symbol Table**	

*  Cấu trúc dữ liệu nội bộ được compiler xây dựng và duy trì trong suốt quá trình biên dịch, lưu trữ thông tin về mọi định danh trong chương trình.

*  Mỗi mục trong Symbol Table bao gồm: 

	* Tên định danh
	
	* Kiểu dữ liệu
	
	* Địa chỉ bộ nhớ (hoặc offset)
	
	* Phạm vi (scope)
	
	* Trạng thái (đã định nghĩa hay chỉ khai báo).

*  Để xem Symbol Table của object file: 

		nm main.o           # Liệt kê các symbol trong object file
		nm --demangle main.o  # Hiển thị tên đã được giải mã (demangled)
	
##### **4.2.2. Name Mangling**	

*  C++ cho phép nạp chồng hàm (Function Overloading) — nhiều hàm có cùng tên nhưng khác danh sách tham số.

*  Tuy nhiên, ở cấp độ mã máy, mỗi hàm phải có một địa chỉ duy nhất và một tên định danh duy nhất trong Symbol Table.

*  Compiler "băm" (mangle) tên hàm ban đầu bằng cách nối thêm thông tin về kiểu tham số vào tên hàm, tạo ra một tên nhị phân duy nhất.

		// Mã nguồn C++:
		void print(int x)    { /* ... */ }
		void print(double x) { /* ... */ }
		void print(int x, int y) { /* ... */ }

		// Tên trong Symbol Table (GCC/Clang ABI):
		// void print(int)       → _Z5printi
		// void print(double)    → _Z5printd
		// void print(int, int)  → _Z5printii

#### **4.3. Qúa trình liên kết và quy tắc ODR**	
		
##### **4.3.1. Quá trình liên kết (Linking)**	

*  Sau khi tất cả các tệp `.cpp` được biên dịch thành các tệp `.o` tương ứng, Linker thực hiện bước cuối cùng:

	*  Duyệt qua Symbol Table của từng object file.
	
	*  Với mỗi tham chiếu chưa được giải quyết (undefined reference), tìm kiếm định nghĩa tương ứng trong các object file khác hoặc trong thư viện.
	
	*  Khớp địa chỉ (Address Resolution): gán địa chỉ bộ nhớ thực tế cho từng hàm và biến.
	
	*  Tạo tệp thực thi hoàn chỉnh.  

*  Lỗi Linker thường gặp và nguyên nhân:

		undefined reference to `MyClass::init()'
	
	*  Nguyên nhân: Hàm `init()` được khai báo trong header nhưng chưa có định nghĩa (implementation) trong bất kỳ tệp `.cpp` nào được đưa vào quá trình liên kết.

			multiple definition of `globalVar'

	*  Nguyên nhân: Biến `globalVar` được định nghĩa (không chỉ khai báo) trong nhiều tệp `.cpp`.

##### **4.3.1. Quy tắc ODR**	

*  ODR là một trong những quy tắc cơ bản nhất của C++, phát biểu như sau:

	*  Một biến, hàm, hoặc lớp có thể được **khai báo (declared)** vô số lần trong chương trình.
	
	*  Tuy nhiên, nó chỉ được **định nghĩa (defined)** duy nhất **MỘT LẦN** trên toàn bộ chương trình.
	
* Phân biệt khai báo và định nghĩa:

		// Khai báo (Declaration) — thông báo sự tồn tại, không cấp phát bộ nhớ:
		extern int globalVar;        // Khai báo biến — không cấp phát
		void calculate(int x);       // Khai báo hàm (function prototype)
		class Engine;                // Khai báo tiền phương (forward declaration)

		// Định nghĩa (Definition) — cấp phát bộ nhớ hoặc cài đặt logic:
		int globalVar = 42;          // Định nghĩa biến — cấp phát 4 byte
		void calculate(int x) {      // Định nghĩa hàm — cài đặt cụ thể
		    /* implementation */
		}
		class Engine {               // Định nghĩa lớp — khai báo đầy đủ thành viên
		    int cylinders;
		};				    	 		

* Quy tắc thực hành để tuân thủ ODR:

	* Chỉ đặt khai báo trong tệp header (`.h`/`.hpp`).
	
	* Chỉ đặt định nghĩa trong tệp nguồn (`.cpp`).
	
	* Sử dụng Header Guard hoặc `#pragma once` để ngăn header bị `#include` nhiều lần trong cùng một translation unit. 


			// engine.h
			#pragma once                  // Ngăn include lặp — thay thế hiện đại cho ifndef guard

			class Engine {
			public:
			    void start();             // Khai báo — không có thân hàm
			    int getCylinders() const;
			private:
			    int cylinders_ = 4;
			};

			// engine.cpp
			#include "engine.h"
			void Engine::start() { /* ... */ }        // Định nghĩa — chỉ ở đây
			int Engine::getCylinders() const { return cylinders_; }

### **V.  MÔ HÌNH CẤP PHÁT BỘ NHỚ HỆ THỐNG**

#### **5.1. Phân mảnh không gian nhớ**
 
##### **5.1.1. Text / Code Segment**
 
* Phần thấp nhất của không gian địa chỉ.

* Các lệnh mã máy đã biên dịch — chính là nội dung của tệp `.o` sau khi được Linker ánh xạ vào bộ nhớ.
	
* Phân đoạn này có thuộc tính **chỉ đọc (Read-only)** và **thực thi được (Executable)**, do hệ điều hành thiết lập thông qua cơ chế bảo vệ bộ nhớ (Memory Protection).

*  Mục đích:

	*  Ngăn chương trình vô tình ghi đè lên mã lệnh của chính nó.
	
	*  Bảo vệ trước một số loại tấn công bảo mật
	
	*  Cho phép nhiều tiến trình chạy cùng một chương trình chia sẻ một bản sao duy nhất của Text segment trong RAM (shared pages).  


##### **5.1.2. Data Segment và BSS Segment**
 
* Lưu trữ các biến có vòng đời tĩnh (Static Storage Duration) — tồn tại trong suốt vòng đời của chương trình.
	
*  **Data Segment (Initialized Data):**

	* Chứa các biến toàn cục (global) và biến tĩnh (static) đã được khởi tạo tường minh với giá trị khác 0.

			int globalCounter = 100;          // → Data segment
			static double PI = 3.14159;       // → Data segment
	
* **BSS Segment (Block Started by Symbol — Uninitialized Data)::**

	* Chứa các biến toàn cục/tĩnh chưa được khởi tạo hoặc được khởi tạo bằng 0.

			int uninitGlobal;                 // → BSS segment (mặc định = 0)
			static char buffer[4096];         // → BSS segment (4096 byte, tất cả = 0)	

	* Vì BSS chỉ chứa các byte bằng 0, tệp thực thi chỉ cần lưu kích thước của BSS, không cần lưu toàn bộ nội dung.
	
	* Khi nạp vào RAM, hệ điều hành tự cấp phát và điền 0. Điều này làm giảm kích thước tệp thực thi đáng kể.  

* **Stack Segment:**

	* Stack hoạt động theo nguyên tắc LIFO (Last In, First Out — Vào sau Ra trước).
	
	* CPU duy trì một thanh ghi đặc biệt gọi là Stack Pointer (SP) trỏ đến đỉnh hiện tại của Stack. 
	
	* Việc cấp phát và thu hồi bộ nhớ Stack được thực hiện bởi CPU thông qua các lệnh `PUSH` và `POP` (hoặc tương đương), không cần can thiệp của lập trình viên. 

	* **Ưu điểm:**
	
		*  Tốc độ cấp phát/thu hồi cực nhanh (chỉ là phép tính số học trên SP).
		
		*   Dữ liệu nằm liên tiếp trong bộ nhớ → tối ưu cho CPU cache.

	* **Hạn chế:**
	
		*  Dung lượng Stack cố định và rất nhỏ
		
		*   Vượt quá giới hạn này (thường do đệ quy vô hạn hoặc mảng cục bộ quá lớn) sẽ gây lỗi Stack Overflow

				void dangerous() {
				    int hugeArray[10000000]; // ~40MB trên stack → Stack Overflow ngay lập tức
				    dangerous();             // Đệ quy vô hạn → Stack Overflow sau vài nghìn lần
				}

* **Heap Segment:**

	* Vùng nhớ tự do, dung lượng khổng lồ (có thể lên đến hàng GB, giới hạn bởi RAM vật lý và bộ nhớ ảo của hệ điều hành).
	
	* Lập trình viên yêu cầu bộ nhớ tại thời điểm chạy (Runtime) thông qua toán tử `new` (C++) hoặc `malloc` (C).
	
	* Hệ điều hành/runtime tìm vùng nhớ trống phù hợp và trả về con trỏ.

			// Cấp phát trên Heap
			int* dynamicArray = new int[10000];  // 40,000 byte trên Heap — hoàn toàn hợp lệ
			MyObject* obj = new MyObject();

			// Lập trình viên PHẢI tự thu hồi
			delete[] dynamicArray;               // Thu hồi mảng
			delete obj;                          // Thu hồi đối tượng đơn

	* **Ưu điểm:**
	
		*  Có thể cấp phát kích thước tùy ý tại thời điểm chạy, kích thước không cần biết trước lúc biên dịch.

	* **Hạn chế:**
	
		*  Tốc độ cấp phát chậm hơn Stack (hệ điều hành phải tìm kiếm vùng trống, cập nhật cấu trúc quản lý heap).
		
		*   Lập trình viên hoàn toàn chịu trách nhiệm thu hồi bộ nhớ.

		*  Quên gọi `delete` → **Rò rỉ bộ nhớ (Memory Leak)**: bộ nhớ bị chiếm dụng vĩnh viễn cho đến khi chương trình kết thúc.
		
		*   Gọi `delete` hai lần (double-free) → Undefined Behavior

#### **5.2. Vòng đời lưu trữ và phạm vi**
 
##### **5.2.1. Phạm vi**
 
* Phạm vi mã nguồn mà trong đó một tên định danh có thể được trình biên dịch "nhìn thấy" và truy cập.

* Phạm vi là khái niệm thuộc không gian (thời điểm biên dịch).
	
* Các loại phạm vi trong C++:

	*  **Block Scope:**
	
		* Biến được khai báo bên trong một khối lệnh `{ }` chỉ tồn tại trong khối đó.

				#include <iostream> 
				using namespace std; 
				int main() { 
					{ 
						int a = 5; // block scope 
						cout << a << endl; 
					} 
					// cout << a; // Lỗi: a không còn tồn tại 
					return 0; 
				}

	*  **Function Scope:**
	
		* Chỉ áp dụng cho nhãn (`label`) dùng với lệnh `goto`.

				#include <iostream> using namespace std; 
				void test() { 
				start: // nhãn có function scope 						
					cout << "Hello\n"; 
					goto end; 
					cout << "Dong nay khong duoc thuc hien\n"; 
				end: 
					cout << "Ket thuc\n"; 
				} 
				int main() { 
				test(); 
				}

	*  **Namespace Scope:**
	
		* Các biến, hàm, lớp được khai báo trực tiếp bên trong một namespace có namespace scope.

				#include <iostream> using namespace std;
				 namespace Math { 
					 int x = 10; // namespace scope 
					 void show() { // namespace scope 
						 cout << x << endl; 
					 } 
				 } 
				 int main() { 
					 Math::show(); 
			     }

	*  **Class Scope:**
	
		* Các thành viên của lớp có class scope.

				#include <iostream> 
				using namespace std; 
				class Student { 
					public: 
						string name; // class scope 
						int age; // class scope 
					void display() { // class scope 
						cout << name << " - " << age << endl; 
						} 
					}; 
				int main() { 
					Student s; 
					s.name = "An"; 
					s.age = 20; 
					s.display(); 
				}


	*  **Global Scope:**
	
		* Các biến hoặc hàm được khai báo bên ngoài mọi hàm, lớp và namespace có global scope.

				#include <iostream> 
				using namespace std; 
				int x = 100; // global scope 
				void show() { // global scope 
					cout << x << endl; 
				} 
				int main() { 
					show(); 
				}

##### **5.2.2. Vòng đời lưu trữ**
 
* Vòng đời lưu trữ là khái niệm thuộc thời gian — xác định khi nào bộ nhớ được cấp phát và khi nào được thu hồi.

* **Automatic Storage Duration (Tự động):**

	* Áp dụng cho biến cục bộ trong khối lệnh.
	
	*  Bộ nhớ được cấp phát trên Stack khi luồng thực thi đi vào khối `{`.
	
	*   Bộ nhớ được thu hồi hoàn toàn (và destructor được gọi nếu là object) khi luồng thực thi thoát khỏi khối `}`.

			void func() {
			    int x = 5;              // Cấp phát khi vào func()
			    std::string s = "hello"; // Constructor được gọi
			}                            // Destructor của s được gọi, x bị thu hồi
	
* **Static Storage Duration (Tĩnh):**

	*  Áp dụng cho: biến toàn cục, biến khai báo với `static`.
	
	*  Bộ nhớ được cấp phát khi chương trình khởi động (trước khi `main` chạy).
	
	* Bộ nhớ tồn tại đến khi chương trình kết thúc hoàn toàn. 

int globalCounter = 0;          // Static duration — tồn tại suốt chương trình

		void countCalls() {
		    static int callCount = 0;   // Static duration — khởi tạo chỉ MỘT LẦN
		    ++callCount;                // Giá trị được giữ lại giữa các lần gọi hàm
		}

* **Dynamic Storage Duration (Động):**

	*  Áp dụng cho bộ nhớ cấp phát trên Heap qua `new`/`malloc`.
	
	*  Bộ nhớ được cấp phát khi lập trình viên gọi `new`.
	
	* Bộ nhớ tồn tại cho đến khi lập trình viên gọi `delete` (hoặc chương trình kết thúc — trường hợp rò rỉ bộ nhớ).

			int* p = new int(42);   // Cấp phát — dynamic duration bắt đầu
			// ... sử dụng p ...
			delete p;               // Thu hồi — dynamic duration kết thúc
			p = nullptr;            // Thực hành tốt: tránh dangling pointer


* **Thread Storage Duration (C++11 — Luồng):**

	*  Khai báo với `thread_local`.
	
	*  Mỗi luồng (thread) có bản sao riêng của biến.
	
	* Vòng đời gắn với vòng đời của luồng tương ứng.

			thread_local int threadID = 0;  // Mỗi thread có threadID riêng

#### **5.3. Undefined Behavior**
 
##### **5.2.1. Định nghĩa**
 
* Undefined Behavior là tình huống mà chương trình thực hiện một thao tác mà Tiêu chuẩn C++ (ISO/IEC 14882) **không quy định kết quả**.

* Khi UB xảy ra, Tiêu chuẩn C++ không đưa ra bất kỳ yêu cầu nào về kết quả hay cách thức thực thi.
	
* Vì vậy, chương trình có thể biểu hiện theo nhiều cách khác nhau, bao gồm việc cho ra kết quả có vẻ đúng, cho ra kết quả sai, hoạt động không ổn định hoặc thậm chí bị dừng đột ngột.

##### **5.2.2. Các dạng UB phổ biến**
 
* **Chia cho 0:**

		int x = 10;
		int y = 0;
		int z = x / y;    // UB — kết quả không xác định (không phải luôn crash)
	
* **Giải tham chiếu con trỏ null (Null pointer dereference):**

		int* p = nullptr;
		*p = 42;          // UB — thường gây Segmentation Fault, nhưng không đảm bảo

* **Truy cập mảng ngoài giới hạn:**

		int arr[5] = {1, 2, 3, 4, 5};
		arr[5] = 10;      // UB — chỉ có chỉ số 0..4 hợp lệ
		arr[-1] = 20;     // UB

* **Sử dụng biến chưa khởi tạo:**

		int x;            // Biến cục bộ — không tự động = 0
		int y = x + 1;    // UB — x chứa giá trị rác từ Stack

* **Tràn số nguyên có dấu:**

		int max = INT_MAX;     // Giá trị lớn nhất của int (thường 2,147,483,647)
		int overflow = max + 1; // UB — không đảm bảo wrap around

* **Sử dụng bộ nhớ sau khi giải phóng:**

		int* p = new int(42);
		delete p;
		*p = 100;         // UB — p là "dangling pointer", vùng nhớ có thể đã được tái sử dụng

* **Đọc/ghi đồng thời không đồng bộ:**

		// Thread 1:          Thread 2:
		counter++;            counter++;  // UB nếu không có đồng bộ hóa (mutex/atomic)

##### **5.2.3.Phụ thuộc nền tảng**
 
* Tiêu chuẩn C++ phân loại hành vi không hoàn toàn xác định thành ba mức:

	* **Undefined Behavior (UB):**
	
		* Tiêu chuẩn không quy định gì — mọi kết quả đều có thể xảy ra. 

	* **Unspecified Behavior:**
	
		* Tiêu chuẩn cho phép nhiều kết quả khác nhau, compiler chọn một nhưng không cần tài liệu hóa.
	
	* **Implementation-defined Behavior:**

		* Compiler chọn kết quả và phải tài liệu hóa lựa chọn đó.

				sizeof(int)    // 4 byte trên x86-64, nhưng có thể 2 byte trên một số MCU nhúng
				sizeof(long)   // 4 byte trên Windows x64, 8 byte trên Linux x64

##### **5.2.4. Công cụ phát hiện UB**
 
		# AddressSanitizer — phát hiện out-of-bounds, use-after-free
		g++ -fsanitize=address -g main.cpp -o main

		# UndefinedBehaviorSanitizer — phát hiện signed overflow, null deref...
		g++ -fsanitize=undefined -g main.cpp -o main

		# Valgrind — phân tích bộ nhớ toàn diện (chậm hơn, không cần biên dịch lại)
		valgrind --leak-check=full ./main
																							
   </details> 



<details>
    <summary><strong>BÀI 2: BIẾN VÀ KIỂU DỮ LIỆU</strong></summary>
	
## **BÀI 2: BIẾN VÀ KIỂU DỮ LIỆU**

### **I.  KIỂU NGUYÊN THỦY (PRIMITIVE TYPES)**

#### **1.1. Biến và quy tắc định danh**

##### **1.1.1. Định nghĩa** 
	
*  Biến là một danh xưng (identifier) đại diện cho một vùng nhớ cụ thể trong hệ thống — thường là trên ngăn xếp (Stack) hoặc phân đoạn dữ liệu (Data segment).
		
* Mỗi biến phải được gắn chặt với một kiểu dữ liệu duy nhất trong suốt vòng đời của nó.
			
*  Kiểu dữ liệu xác định ba thuộc tính căn bản:

	* Kích thước vùng nhớ được cấp phát (số byte).
			
	* Cách diễn giải chuỗi bit nhị phân trong vùng nhớ đó.
				
	* Tập hợp các phép toán hợp lệ có thể thực hiện trên biến.

				
##### **1.1.2.Quy tắc định danh**
	
*  Chỉ bao gồm chữ cái (A–Z, a–z), chữ số (0–9) và dấu gạch dưới `_`.
		
* Không được bắt đầu bằng chữ số.
			
* Phân biệt chữ hoa và chữ thường (Case-sensitive): `studentAge` và `studentage` là hai biến hoàn toàn khác nhau. 
				
* Tuyệt đối không trùng với các từ khóa dự trữ (Keywords) của C++ như `int`, `class`, `return`, `namespace`...
				
		int 3students = 0;     // LỖI: Bắt đầu bằng chữ số
		int class = 0;         // LỖI: Trùng với từ khóa
		int student_age = 0;   // HỢP LỆ
		int studentAge = 0;    // HỢP LỆ

##### **1.1.3.Khuôn mẫu đặt tên (Naming Conventions)**
	
*  **camelCase:** 

	* Ký tự đầu chữ thường, mỗi từ tiếp theo viết hoa chữ đầu. Ví dụ: `studentAge`, `engineSpeed`.
		
*  **snake_case:** 

	* Tất cả chữ thường, các từ nối nhau bằng dấu gạch dưới. Ví dụ: `student_age`, `engine_speed`.
			
*  **UPPER_SNAKE_CASE:** 

	* Dành riêng cho hằng số và macro. Ví dụ: `MAX_BUFFER_SIZE`, `PI_VALUE`.`engineSpeed`.
		
*  **PascalCase:** 

	* Dành cho tên lớp (Class) và kiểu dữ liệu tự định nghĩa. Ví dụ: `MotorController`, `SensorData`.
							
#### **1.2. Nhóm kiểu dữ liệu nguyên thủy và Thư viện `<cstdint>`**	

##### **1.2.1.Các kiểu dữ liệu nguyên thủy cơ bản**	
	
*  C++ cung cấp hai nhóm kiểu nguyên thủy chính:

	* Nhóm số nguyên (Integer types):

			┌──────────────┬────────────────────────────────┬──────────────────────────┐
			│ Kiểu         │ Kích thước điển hình           │ Phạm vi (có dấu)         │
			├──────────────┼────────────────────────────────┼──────────────────────────┤
			│ short        │ 2 bytes (16 bit)               │ -32,768 → 32,767         │
			│ int          │ 4 bytes (32 bit) — thông thường│ -2,147,483,648 → ...     │
			│ long         │ 4 byte (Windows) / 8 byte(Linux│ Phụ thuộc nền tảng       │
			│ long long    │ 8 bytes (64 bit)               │ ±9.2 × 10¹⁸              │
			└──────────────┴────────────────────────────────┴──────────────────────────┘

	* Nhóm số thực dấu phẩy động (Floating-point types):

						┌──────────────┬──────────────┬──────────────────────┬──────────────────┐
			│ Kiểu         │ Kích thước   │ Độ chính xác         │ Tiêu chuẩn       │
			├──────────────┼──────────────┼──────────────────────┼──────────────────┤
			│ float        │ 4 bytes      │ ~7 chữ số thập phân  │ IEEE 754 Single  │
			│ double       │ 8 bytes      │ ~15 chữ số thập phân │ IEEE 754 Double  │
			│ long double  │ 8-16 bytes   │ Phụ thuộc nền tảng   │ Mở rộng          │
			└──────────────┴──────────────┴──────────────────────┴──────────────────┘
	
##### **1.2.2.Vấn đề phụ thuộc kiến trúc**	
	
*  Tiêu chuẩn C++ không quy định cứng kích thước byte của kiểu `int` hay `long` — chúng phụ thuộc vào kiến trúc phần cứng và trình biên dịch.

*  Điều này gây rủi ro nghiêm trọng trong lập trình nhúng đa nền tảng (cross-platform embedded development):

		// Trên Linux x86-64:  sizeof(long) = 8 bytes
		// Trên Windows x64:   sizeof(long) = 4 bytes
		// Trên AVR 8-bit MCU: sizeof(int) = 2 bytes

		int sensorValue = 100000; // Hợp lệ trên x86, tràn số trên AVR!
	
##### **1.2.3.Thư viện `<cstdint>` (C++11)**
	
*  Thư viện này cung cấp các kiểu dữ liệu có kích thước bit cố định, xác định hoàn toàn bất kể nền tảng, trình biên dịch, hay kiến trúc vi xử lý.

		#include <cstdint>

		int8_t   a;   // Chính xác  8-bit có dấu  (-128 → 127)
		uint8_t  b;   // Chính xác  8-bit không dấu (0 → 255)
		int16_t  c;   // Chính xác 16-bit có dấu
		uint16_t d;   // Chính xác 16-bit không dấu
		int32_t  e;   // Chính xác 32-bit có dấu
		uint32_t f;   // Chính xác 32-bit không dấu
		int64_t  g;   // Chính xác 64-bit có dấu
		uint64_t h;   // Chính xác 64-bit không dấu
				



#### **1.3. Kiểu ký tự, Boolean và hậu tố hằng số (Literal Suffixes)**	
		
*  **Kiểu ký tự `char`:**

	*  `char` chiếm đúng 1 byte (8 bit) và về bản chất lưu trữ một giá trị số nguyên nhỏ.
	
	*  Giá trị số nguyên đó được ánh xạ sang ký tự hiển thị thông qua bảng mã ASCII (hoặc UTF-8).
		
			char letter = 'A';        // Lưu giá trị số nguyên 65
			char digit  = '0';        // Lưu giá trị số nguyên 48
			char newline = '\n';      // Escape character — ký tự đặc biệt ngắt dòng

			// Minh họa bản chất số nguyên:
			std::cout << (int)'A';    // In ra: 65
			std::cout << (char)66;    // In ra: B
		
	*  Phân biệt `char` và `char*` / `std::string`:
	
		*  `char c = 'A';` — Kiểu nguyên thủy, lưu **một** ký tự duy nhất, dùng dấu nháy đơn `' '`
		
		*  `const char* s = "Hello";` — Con trỏ đến mảng ký tự kiểu C, dùng dấu nháy kép `" "`.
		
		* `std::string str = "Hello";` — Đối tượng chuỗi hiện đại
			
*  **Kiểu Boolean `bool`:**

	*  `bool` lưu trữ trạng thái logic: `true` (biểu diễn nội bộ bằng giá trị `1`) hoặc `false` (biểu diễn bằng `0`).
	
			bool isRunning = true;
			bool hasError  = false;

			// Chuyển đổi ngầm định (Implicit conversion):
			bool fromInt = 42;     // true — mọi giá trị khác 0 đều là true
			bool fromZero = 0;     // false

			// In ra giá trị bool:
			std::cout << std::boolalpha << isRunning; // In ra "true" thay vì "1"

*  **Hậu tố hằng số (Literal Suffixes):**

	*  Ký tự hoặc chuỗi ký tự đặt ngay sau một giá trị hằng số (literal) để ép trình biên dịch hiểu định dạng bộ nhớ chính xác của giá trị đó.
	
	*  Nếu không có hậu tố, trình biên dịch áp dụng quy tắc mặc định:
	
		* Hằng số nguyên không có hậu tố → kiểu `int`.
		
		* Hằng số thực không có hậu tố → kiểu `double`.  

				auto a = 3.14;      // double  (8 bytes) — mặc định
				auto b = 3.14f;     // float   (4 bytes) — hậu tố f hoặc F
				auto c = 3.14L;     // long double      — hậu tố L

				auto d = 100;       // int              — mặc định
				auto e = 100U;      // unsigned int     — hậu tố U
				auto f = 100L;      // long             — hậu tố L
				auto g = 100UL;     // unsigned long    — hậu tố UL
				auto h = 100LL;     // long long        — hậu tố LL
				auto i = 100ULL;    // unsigned long long — hậu tố ULL

#### **1.4. Cấu trúc đối tượng chuỗi văn bản `std::string`**	
		
*  **Cơ sở:**

	*  `std::string` (thuộc thư viện `<string>`) là một đối tượng lớp (Class Object) — không phải kiểu nguyên thủy.
	
	*  Nó đóng gói và tự động hóa hoàn toàn việc quản lý vùng nhớ động (Heap) cho chuỗi ký tự.
		
*  **Cú pháp và thao tác:**

		#include <string>

		std::string name = "Embedded Systems";  // Khởi tạo
		std::string empty;                       // Chuỗi rỗng — hợp lệ

		// Nối chuỗi — trực quan, không tràn bộ nhớ
		std::string greeting = "Hello, " + name + "!";

		// Lấy độ dài
		std::size_t len = name.length();   // Trả về số ký tự: 16
		std::size_t sz  = name.size();     // Tương đương length()

		// Truy cập ký tự
		char first = name[0];              // 'E' — không kiểm tra giới hạn
		char safe  = name.at(0);          // 'E' — có kiểm tra, ném ngoại lệ nếu OOB

		// Chuỗi con (Substring)
		std::string sub = name.substr(9, 7);  // "Systems" — bắt đầu từ index 9, dài 7 ký tự

		// Tìm kiếm
		std::size_t pos = name.find("Systems"); // Trả về index, hoặc std::string::npos nếu không tìm thấy
			
### **II.  KHỞI TẠO VÀ ĐÁNH GIÁ TẠI THỜI GIAN BIÊN DỊCH**

#### **2.1. Cú pháp khởi tạo đồng nhất (Uniform Initialization)** 

##### **2.1.1.Vấn đề của cú pháp khởi tạo cũ**
 
* Trước C++11, C++ có nhiều cú pháp khởi tạo không nhất quán:

		int a = 5;           // Copy initialization (C truyền thống)
		int b(5);            // Direct initialization (gọi constructor)
		int arr[] = {1,2,3}; // Aggregate initialization (chỉ cho mảng/struct)

##### **2.1.2.Cú pháp khởi tạo đồng nhất bằng `{}`**

* C++11 giới thiệu cú pháp `{}` (braced initialization / list initialization) như một cú pháp khởi tạo thống nhất cho mọi loại: biến nguyên thủy, mảng, struct, và đối tượng lớp.
	
		// Tất cả đều dùng cùng cú pháp {}:
		int x{5};
		double pi{3.14159};
		int arr[]{1, 2, 3, 4, 5};

		struct Point { int x; int y; };
		Point p{10, 20};

		std::vector<int> v{1, 2, 3, 4};
		std::string s{"Hello"};
	
##### **2.1.3. Đặc tính**

* Khởi tạo bằng `{}` báo **lỗi biên dịch** ngay lập tức khi lập trình viên cố gán một giá trị vào kiểu không đủ khả năng biểu diễn — thay vì âm thầm cắt bớt dữ liệu.

		// Cú pháp cũ — nguy hiểm, im lặng:
		int x = 3.99;       // Hợp lệ: x = 3 (mất phần thập phân .99)
		int y = 300;
		char c = y;         // Hợp lệ: cắt bớt âm thầm, c = 44 (300 mod 256)

		// Cú pháp {} — an toàn, rõ ràng:
		int x{3.99};        // LỖI BIÊN DỊCH: narrowing conversion từ double sang int
		char c{300};        // LỖI BIÊN DỊCH: 300 không vừa trong 1 byte

 * Giải quyết bằng Most Vexing Parse

	* C++ có một hiện tượng nổi tiếng gọi là "Most Vexing Parse": cú pháp `()` đôi khi bị trình biên dịch diễn giải nhầm thành khai báo hàm thay vì khởi tạo đối tượng.

			// Most Vexing Parse — trình biên dịch hiểu đây là khai báo hàm, không phải object!
			std::vector<int> v();    // LỖI LOGIC: khai báo hàm trả về vector, không phải tạo vector rỗng

			// Giải pháp với {}:
			std::vector<int> v{};   // Rõ ràng: tạo vector rỗng

#### **2.2. Tính hằng số và tính toán tại thời gian biên dịch** 

##### **2.2.1. Từ khóa `const`**
 
* `const` đảm bảo biến mang tính "chỉ đọc" (read-only) trong quá trình thực thi — không thể bị gán lại sau khi khởi tạo.

* Giá trị của biến `const` có thể được tính toán tại thời gian chạy (runtime).

		const int bufferSize = 1024;        // Giá trị biết trước lúc biên dịch
		bufferSize = 2048;                  // LỖI BIÊN DỊCH: không thể gán lại const

		// Const với giá trị runtime — hoàn toàn hợp lệ:
		int userInput;
		std::cin >> userInput;
		const int threshold = userInput * 2; // Tính tại runtime, nhưng không đổi sau đó

##### **2.2.2. Từ khóa `constexpr`**

* `constexpr` yêu cầu trình biên dịch đánh giá (tính toán) giá trị ngay trong quá trình biên dịch.

* Nếu thành công, giá trị được nhúng thẳng vào mã máy dưới dạng hằng số — không có bất kỳ chi phí thời gian chạy nào (zero-runtime cost).
	
		constexpr int MAX_NODES = 256;
		constexpr double TAX_RATE = 0.08;

		// Hàm constexpr — tính toán tại compile-time nếu đầu vào là hằng số
		constexpr int square(int x) { return x * x; }

		constexpr int area = square(10);   // Tính tại compile-time → mã máy chứa hằng 100
		int runtime_val = 5;
		int dynamic_area = square(runtime_val); // Tính tại runtime — vẫn hợp lệ

##### **2.2.3. Từ khóa `consteval`**

* `consteval` là phiên bản nghiêm ngặt hơn `constexpr`.

* Hàm `consteval` **bắt buộc** phải được đánh giá tại thời gian biên dịch — nếu được gọi với đối số runtime, chương trình từ chối biên dịch ngay lập tức.
	
		consteval int computeCRC(int polynom) {
		    return polynom * 0x1021; // Tính toán bảng CRC — phải xong lúc biên dịch
		}

		constexpr int crc = computeCRC(0xFF);  // HỢP LỆ: đầu vào là hằng compile-time

		int userPoly = 0xFF;
		int bad = computeCRC(userPoly);        // LỖI BIÊN DỊCH: đầu vào không phải hằng
		
#### **2.3. auto**

##### **2.3.1. Định nghĩa**
			
*  Từ khóa `auto` hướng dẫn trình biên dịch tự động suy luận (deduce) kiểu dữ liệu của biến dựa vào biểu thức khởi tạo ở vế phải.

##### **2.3.2. Bản chất**
			
*  C++ là ngôn ngữ định kiểu tĩnh (Statically typed).

*  Từ khóa `auto` **không** biến C++ thành ngôn ngữ gán kiểu động như Python hay JavaScript.
	
* Kiểu của biến `auto` được chốt chặt tại thời điểm biên dịch và **không bao giờ thay đổi** sau đó.

		auto count   = 10;        // Compiler chốt: int
		auto price   = 99.99;     // Compiler chốt: double
		auto ratio   = 3.14f;     // Compiler chốt: float
		auto name    = std::string{"Alice"};  // Compiler chốt: std::string
		auto flag    = true;      // Compiler chốt: bool

		count = "Hello";          // LỖI BIÊN DỊCH: không thể gán string cho int

##### **2.3.3. Trường hợp cần thiết**
			
*  `auto` không chỉ là tiện lợi — có những trường hợp kiểu dữ liệu quá dài hoặc thậm chí không thể viết tường minh:

		// Kiểu iterator dài dòng — auto cứu trợ:
		std::map<std::string, std::vector<int>>::iterator it = myMap.begin(); // Cũ
		auto it = myMap.begin();   // Hiện đại, rõ ràng hơn

		// Kiểu Lambda — không thể viết tường minh:
		auto square = [](int x) { return x * x; };  // Kiểu thực sự là closure type ẩn danh

		// Kiểu trả về phức tạp từ Template:
		auto result = std::make_pair(42, std::string{"answer"});  // std::pair<int, std::string>

*  `auto` với tham chiếu và con trỏ:

		int value = 42;
		auto  a = value;   // a là int — sao chép
		auto& b = value;   // b là int& — tham chiếu đến value
		auto* c = &value;  // c là int* — con trỏ đến value

#### **2.4. Các toán tử ép kiểu an toàn**

##### **2.4.1. Vấn đề**
			
*  Cú pháp ép kiểu C `(type)value` quá mạnh bạo, thực hiện ép kiểu mù quáng bất kể có an toàn hay không, bỏ qua mọi cơ chế bảo vệ của C++, và không cung cấp thông tin ngữ nghĩa về mục đích ép kiểu.

		double pi = 3.14159;
		int bad = (int)pi;   // Cú pháp C: hoạt động nhưng không rõ ngữ nghĩa

		// Vấn đề nghiêm trọng hơn:
		const int constVal = 42;
		int* ptr = (int*)&constVal;  // C-cast xóa bỏ const — nguy hiểm, compiler không cảnh báo

##### **2.4.2. static_cast**
			
*  `static_cast` 

	* Là toán tử ép kiểu chuẩn mực nhất, thực hiện kiểm tra tính hợp lệ của chuyển đổi tại thời gian biên dịch.

		double pi = 3.14159;
		int intPi = static_cast<int>(pi);       // Rõ ràng: cắt phần thập phân, lập trình viên chủ động
		float f = static_cast<float>(pi);       // double → float — hợp lệ, có thể mất độ chính xác

		// Ép kiểu số nguyên:
		uint32_t regValue = 0xDEADBEEF;
		int32_t  signed_v = static_cast<int32_t>(regValue); // Tường minh về ý định

		// static_cast KHÔNG thể xóa const:
		const int c = 10;
		int* p = static_cast<int*>(&c);  // LỖI BIÊN DỊCH — static_cast bảo vệ const

*  `dynamic_cast`

	* `dynamic_cast` dùng để chuyển đổi giữa các kiểu trong cây kế thừa (inheritance hierarchy).
	
	* Thực hiện kiểm tra kiểu tại thời gian chạy — trả về `nullptr` nếu chuyển đổi không hợp lệ 

			class Base { virtual void func() {} }; // Cần ít nhất một virtual function
			class Derived : public Base {};

			Base* basePtr = new Derived();
			Derived* derived = dynamic_cast<Derived*>(basePtr); // An toàn: kiểm tra runtime
			if (derived != nullptr) {
			    // Chuyển đổi thành công
			}

*  `reinterpret_cast`

	* `reinterpret_cast` không thực hiện chuyển đổi giá trị — nó giữ nguyên chuỗi bit và diễn giải lại chúng theo kiểu mới.
	
	* Thường dùng  khi cần ánh xạ địa chỉ thanh ghi phần cứng.

			// Truy cập thanh ghi phần cứng qua địa chỉ tuyệt đối:
			uint32_t* GPIOA_ODR = reinterpret_cast<uint32_t*>(0x40020014);
			*GPIOA_ODR = 0x0001; // Ghi trực tiếp vào thanh ghi

			// Diễn giải lại cấu trúc byte:
			float fval = 3.14f;
			uint32_t bits = *reinterpret_cast<uint32_t*>(&fval); // Xem biểu diễn IEEE 754
			
### **III.  NHẬP XUẤT DỮ LIỆU**

#### **3.1. std::cout**
 
##### **3.1.1. Khái niệm**
 
* `std::cout` là một đối tượng toàn cục kiểu `std::ostream`, được định nghĩa trong `<iostream>`.

* Nó đại diện cho **luồng xuất chuẩn (standard output stream)**, được liên kết mặc định với thiết bị hiển thị console của hệ điều hành.

		Chương trình C++          Luồng               Hệ điều hành
		┌───────────────┐    ┌────────────┐    ┌─────────────────────┐
		│ std::cout <<  │───▶│  Buffer    │───▶│  stdout (console)   │
		│ "Hello"       │    │  (đệm)     │    │  hoặc file, pipe... │
		└───────────────┘    └────────────┘    └─────────────────────┘

##### **3.1.2. Toán tử chèn `<<` (Insertion Operator)** 

* Toán tử `<<` được nạp chồng (overloaded) cho mọi kiểu dữ liệu cơ bản — không cần chỉ định định dạng như `%d`, `%f` trong C:
 
		int age = 25;
		double pi = 3.14159;
		std::string name = "Lucas";
		bool flag = true;

		std::cout << "Name: " << name << "\n";   // Name: Lucas
		std::cout << "Age: "  << age  << "\n";   // Age: 25
		std::cout << "Pi: "   << pi   << "\n";   // Pi: 3.14159
		std::cout << "Flag: " << std::boolalpha << flag << "\n"; // Flag: true
		
	* Chuỗi `<<` hoạt động được vì mỗi lời gọi `<<` trả về tham chiếu đến `std::cout` — cho phép nối tiếp vô hạn.



##### **3.1.3. Buffering & Flushing** 

* Để tối ưu hiệu suất, `std::cout` không ghi trực tiếp ra màn hình sau mỗi ký tự mà tích lũy vào **bộ đệm nội bộ (internal buffer)** trước.
 
* Bộ đệm được xả (flush) ra thiết bị đầu ra khi:
	
	* Bộ đệm đầy.
	
	* Chương trình gọi tường minh `std::flush` hoặc `std::endl`.
	
	* Chương trình kết thúc bình thường.

* So sánh hai cơ chế ngắt dòng:
	
		// Cách 1: Ký tự ngắt dòng \n — KHUYẾN NGHỊ cho vòng lặp lớn
		std::cout << "Processing...\n";    // Chỉ thêm '\n' vào buffer, không flush

		// Cách 2: std::endl — TRÁNH LẠM DỤNG trong vòng lặp
		std::cout << "Processing..." << std::endl;  // Thêm '\n' VÀ flush buffer ngay lập tức

* **Lưu ý:**

	* `std::endl` thực hiện một lần ghi hệ thống (system call) mỗi khi được gọi.
	
	*  Trong vòng lặp hàng triệu lần, lạm dụng `std::endl` có thể làm giảm hiệu suất I/O **hàng chục đến hàng trăm lần** so với dùng `'\n'`.

* **Các bộ điều chỉnh định dạng:**

		#include <iomanip>

		double value = 3.14159265;

		std::cout << std::fixed << std::setprecision(2) << value;  // 3.14
		std::cout << std::scientific << value;                      // 3.141593e+00
		std::cout << std::setw(10) << std::right << 42;            // "        42"
		std::cout << std::hex << 255;                               // ff
		std::cout << std::oct << 255;                               // 377
						
#### **3.2. std::cin**	
		
##### **3.2.1. Khái niệm**	

*  `std::cin` (viết tắt của "Character Input") là đối tượng toàn cục kiểu `std::istream`, đại diện cho **luồng nhập chuẩn (standard input stream)**, mặc định liên kết với bàn phím.

		Người dùng gõ         Bộ đệm OS           Bộ đệm cin         Biến C++
		┌─────────────┐    ┌───────────┐    ┌───────────────┐    ┌──────────┐
		│ "25 Alice\n"│───▶│  stdin    │───▶│ std::cin buf  │───▶│ int, str │
		└─────────────┘    └───────────┘    └───────────────┘    └──────────┘

##### **3.2.2. Toán tử trích xuất `>>` (Extraction Operator)**	

		int age;
		double salary;
		std::string lastName;

		std::cin >> age >> salary >> lastName;
		// Nếu người dùng nhập: "25 75000.5 Nguyen"
		// Kết quả: age=25, salary=75000.5, lastName="Nguyen"


##### **3.2.3. Đặc điểm phân tách token (Tokenization)**	

*  `std::cin` với toán tử `>>` mặc định coi các ký tự khoảng trắng (Space, Tab, Enter `\n`) là ký tự **phân cách (delimiter)** giữa các token.

* Hệ quả:

	*  Toán tử `>>` tự động bỏ qua khoảng trắng dẫn đầu trước khi đọc.
	
	*  Toán tử `>>` dừng đọc khi gặp khoảng trắng đầu tiên.
	
	*  Do đó, `std::cin >> str` **không thể đọc chuỗi có chứa dấu cách**.   
	
			std::string fullName;
			std::cin >> fullName;
			// Người dùng nhập: "Nguyen Van An"
			// fullName chỉ chứa: "Nguyen" — phần sau bị bỏ lại trong buffer!

##### **3.2.4. std::getline() cho chuỗi chứa dấu cách**	

		std::string fullName;
		std::getline(std::cin, fullName);
		// Người dùng nhập: "Nguyen Van An"
		// fullName chứa: "Nguyen Van An" — đọc toàn bộ đến Enter

##### **3.2.5. `>` và `getline`**	

		int age;
		std::string name;

		std::cin >> age;           // Đọc số, nhưng '\n' (Enter) còn nằm trong buffer!
		std::getline(std::cin, name); // Đọc ngay '\n' còn sót — name nhận chuỗi rỗng!

* Giải pháp: Xả ký tự `\n` còn sót bằng `std::cin.ignore()`:

		int age;
		std::string name;

		std::cin >> age;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Xả '\n' còn sót
		std::getline(std::cin, name); // Hoạt động đúng

##### **3.2.6. Kiểm tra trạng thái luồng (Stream State)**
	
*  Luồng `std::cin` có thể rơi vào trạng thái lỗi khi dữ liệu nhập không khớp với kiểu mong đợi:

		int number;
		std::cin >> number;

		if (std::cin.fail()) {            // Kiểm tra có lỗi không
		    std::cin.clear();             // Xóa cờ lỗi
		    std::cin.ignore(1000, '\n'); // Bỏ qua dữ liệu sai trong buffer
		    std::cerr << "Invalid input!\n";
		}

##### **3.2.7. Luồng lỗi chuẩn `std::cerr` và `std::clog`**
	
*  `std::cerr`: 

	* Luồng xuất lỗi chuẩn (standard error). **Không có bộ đệm** — ghi ngay lập tức ra thiết bị. Dùng để thông báo lỗi nghiêm trọng.

*  `std::clog`: 

	* Luồng ghi nhật ký (logging). Có bộ đệm — hiệu suất cao hơn `cerr`. Dùng để ghi log.

			std::cout << "Normal output\n";         // Luồng stdout — có buffer
			std::cerr << "Critical error!\n";       // Luồng stderr — không buffer, ngay lập tức
			std::clog << "Debug: value = " << x;    // Luồng stderr — có buffer
																							
   </details> 


<details>
    <summary><strong>BÀI 3: BIỂU THỨC VÀ TOÁN TỬ</strong></summary>
	
## **BÀI 3: BIỂU THỨC VÀ TOÁN TỬ**

### **I.  TOÁN TỬ VÀ TRẬT TỰ ĐÁNH GIÁ BIỂU THỨC**

#### **1.1. Biểu thức (Expressions)**

##### **1.1.1. Định nghĩa** 
	
*  Biểu thức là một tổ hợp các toán hạng (operands) và toán tử (operators) mà trình biên dịch đánh giá để tính toán và trả về một giá trị duy nhất.

##### **1.1.2. Thuộc tính** 
		
* Mọi biểu thức trong C++ đều có hai thuộc tính:
			
	*  **Giá trị (Value):** Kết quả tính toán của biểu thức.
	
	* **Kiểu (Type):** Kiểu dữ liệu của giá trị trả về — xác định tại thời gian biên dịch.

							
#### **1.2. Nhóm toán tử số học**	

##### **1.2.1.Các toán tử số học cơ bản**	
	
*  C++ cung cấp năm toán tử số học nhị phân: 

	* `+` (cộng)
	
	* `-` (trừ)
	
	* `*` (nhân)
	
	* `/` (chia)
	
	* `%` (chia lấy dư).
	
##### **1.2.2. Implicit Type Promotion**	
	
*  Khi thực hiện phép tính giữa hai toán hạng có kiểu khác nhau, trình biên dịch tự động "thăng cấp" (promote) kiểu nhỏ hơn lên kiểu lớn hơn để bảo toàn độ chính xác.

*  Quy tắc chung: `int` → `long` → `float` → `double`.

		int   a = 5;
		double b = 2.0;
		auto  c = a + b;   // a được thăng cấp thành double trước khi cộng
		                   // c có kiểu double, giá trị 7.0
	
##### **1.2.3.Integer Truncation**
	
* Phép chia `/` giữa hai số nguyên luôn trả về số nguyên — phần thập phân bị loại bỏ hoàn toàn ở cấp độ phần cứng.

* Đây không phải làm tròn toán học mà là **cắt cụt về phía 0 (truncation toward zero)**.

		int result1 = 5 / 2;    // 2  — không phải 2.5
		int result2 = 7 / 2;    // 3  — không phải 3.5
		int result3 = -7 / 2;   // -3 — cắt về phía 0, không phải -4

		// Để có kết quả số thực: ít nhất một toán hạng phải là số thực
		double r1 = 5.0 / 2;    // 2.5
		double r2 = 5 / 2.0;    // 2.5
		double r3 = static_cast<double>(5) / 2;  // 2.5 — ép kiểu tường minh

##### **1.2.4. Toán tử chia lấy dư `%` (Modulo)**
	
* Toán tử `%` chỉ hoạt động trên kiểu số nguyên

* Kết quả mang dấu của toán hạng bên trái.

		int r1 =  7 %  3;   //  1  (7 = 2×3 + 1)
		int r2 = -7 %  3;   // -1  (dấu theo toán hạng trái: -7)
		int r3 =  7 % -3;   //  1  (dấu theo toán hạng trái: 7)
		
* Ứng dụng thực tiễn trong lập trình nhúng:

	* Kiểm tra chẵn/lẻ (`n % 2`)
	
	* Vòng tròn bộ đệm vòng (`index % BUFFER_SIZE`)
	
	* Chuyển đổi giây sang phút/giây.

##### **1.2.5. Toán tử tăng giảm**
	
	int x = 5;

	// Tiền tố (prefix): tăng TRƯỚC, trả về giá trị đã tăng
	int a = ++x;   // x = 6, a = 6

	// Hậu tố (postfix): trả về giá trị CŨ, tăng SAU
	int b = x++;   // b = 6, x = 7 (sau phép gán)

#### **1.3. Nhóm toán tử gán**	

##### **1.3.1. Định nghĩa và cú pháp**	
		
*  Các toán tử gán phức hợp kết hợp một phép tính số học (hoặc bit) với phép gán vào một thao tác đơn nhất:

		int x = 10;

		x += 5;    // Tương đương x = x + 5  → x = 15
		x -= 3;    // Tương đương x = x - 3  → x = 12
		x *= 2;    // Tương đương x = x * 2  → x = 24
		x /= 4;    // Tương đương x = x / 4  → x = 6
		x %= 4;    // Tương đương x = x % 4  → x = 2

		// Toán tử bit phức hợp:
		x &= 0xFF; // AND bit
		x |= 0x01; // OR bit
		x ^= 0xF0; // XOR bit
		x <<= 2;   // Dịch trái 2 bit
		x >>= 1;   // Dịch phải 1 bit

##### **1.3.2. Hiệu suất mã máy**	
		
*  `a += b` hiệu quả hơn `a = a + b` vì:

	*  `a = a + b`: Trình biên dịch đánh giá địa chỉ bộ nhớ của `a` **hai lần** (một lần để đọc, một lần để ghi).
	
	*  `a += b`: Trình biên dịch đánh giá địa chỉ bộ nhớ của `a` chỉ **một lần**.

#### **1.4. Nhóm toán tử quan hệ và cấu trúc logic nhị phân**	
		
##### **1.4.1. Nhóm toán tử quan hệ**

		int a = 5, b = 10;

		bool r1 = (a == b);  // false — đẳng thức
		bool r2 = (a != b);  // true  — bất đẳng thức
		bool r3 = (a <  b);  // true  — nhỏ hơn
		bool r4 = (a >  b);  // false — lớn hơn
		bool r5 = (a <= b);  // true  — nhỏ hơn hoặc bằng
		bool r6 = (a >= b);  // false — lớn hơn hoặc bằng
		
*  **Nhầm `=` (gán) với `==` (so sánh)**

		int x = 5;
		if (x = 10) { }   // LỖI LOGIC: Gán 10 vào x, điều kiện luôn true!
		if (x == 10) { }  // ĐÚNG: So sánh x với 10

		// Kỹ thuật "Yoda condition" tránh lỗi này:
		if (10 == x) { }  // Nếu nhầm = thay vì ==, compiler báo lỗi ngay

##### **1.4.2. Nhóm toán tử logic nhị phân**

		bool a = true, b = false;

		bool r1 = (a && b);  // false — AND: cả hai phải true
		bool r2 = (a || b);  // true  — OR: ít nhất một true
		bool r3 = (!a);      // false — NOT: đảo ngược

		// So sánh: Toán tử bit tương ứng (& | ^) — KHÔNG dùng cho logic!
		// & và | KHÔNG có short-circuit, luôn đánh giá cả hai vế	

##### **1.4.3. Toán tử so sánh ba chiều (Spaceship Operator `<=>`)**

		#include <compare>

		int a = 5, b = 10;
		auto result = (a <=> b);  // std::strong_ordering::less

		if (result < 0)  { /* a < b */ }
		if (result == 0) { /* a == b */ }
		if (result > 0)  { /* a > b */ }

#### **1.5. Độ ưu tiên và trật tự**	
		
##### **1.5.1. Độ ưu tiên**

* Khi một biểu thức chứa nhiều toán tử, độ ưu tiên xác định toán tử nào được đánh giá trước.

* Bảng độ ưu tiên từ cao đến thấp (trích dẫn các mức quan trọng):

		Mức 1 (Cao nhất): ()  []  .  ->  ++/--(hậu tố)
		Mức 2:            !  ~  ++(tiền tố)  --(tiền tố)  sizeof  &  *  (cast)
		Mức 3:            *  /  %
		Mức 4:            +  -
		Mức 5:            <<  >>
		Mức 6:            <  <=  >  >=
		Mức 7:            ==  !=
		Mức 8:            &  (Bitwise AND)
		Mức 9:            ^  (Bitwise XOR)
		Mức 10:           |  (Bitwise OR)
		Mức 11:           &&
		Mức 12:           ||
		Mức 13:           ?:  (Ternary)
		Mức 14 (Thấp):   =  +=  -=  ...  (Gán)
		
*  **VD:**

		int result = 2 + 3 * 4;      // 14 — nhân trước cộng
		int result = (2 + 3) * 4;    // 20 — ngoặc đơn cao nhất

		bool test = 5 > 3 && 2 < 4;  // true — > và < trước &&
		bool mask = 0x0F & 0xFF == 0x0F;  // SAI Ý! == cao hơn & → 0x0F & true
		                                   // Đúng phải là: (0x0F & 0xFF) == 0x0F

##### **1.5.2. Trật tự**

* Khi nhiều toán tử có **cùng mức độ ưu tiên** xuất hiện liên tiếp, trật tự kết hợp xác định hướng đánh giá:

	*  **Trái sang phải (Left-to-Right):** Phổ biến nhất — áp dụng cho hầu hết toán tử số học và quan hệ.

			int r = 100 / 10 / 2;   // (100 / 10) / 2 = 5  — không phải 100 / (10/2) = 20
			int s = 10 - 3 - 2;     // (10 - 3) - 2 = 5

	*  **Phải sang trái (Right-to-Left):** Áp dụng cho toán tử gán và toán tử một ngôi.

			int a, b, c;
			a = b = c = 5;   // a = (b = (c = 5)) — gán từ phải sang trái
			int x = -(-5);   // -(-5) = 5 — toán tử một ngôi từ phải sang trái

#### **1.6. Bitwise Operations**	
		
##### **1.6.1. Khái niệm**

* Toán tử bitwise thực hiện phép tính trực tiếp trên từng bit nhị phân của toán hạng.

* Đây là nhóm toán tử có tốc độ thực thi nhanh nhất ở cấp độ CPU — ánh xạ trực tiếp sang các lệnh máy AND, OR, XOR, NOT, SHL, SHR.

##### **1.6.2. Toán tử Bitwise cơ bản**

		Toán tử   Tên           Quy tắc từng bit
		&         Bitwise AND   1 & 1 = 1 ; 1 & 0 = 0 ; 0 & 0 = 0
		|         Bitwise OR    1 | 1 = 1 ; 1 | 0 = 1 ; 0 | 0 = 0
		^         Bitwise XOR   1 ^ 1 = 0 ; 1 ^ 0 = 1 ; 0 ^ 0 = 0
		~         Bitwise NOT   ~1 = 0    ; ~0 = 1

* **VD:**

			uint8_t a = 0b10110101;   // 0xB5 = 181
			uint8_t b = 0b11001100;   // 0xCC = 204

			uint8_t r1 = a & b;   // 0b10000100 = 0x84 — Chỉ bit nào cả hai đều 1
			uint8_t r2 = a | b;   // 0b11111101 = 0xFD — Bit nào ít nhất một là 1
			uint8_t r3 = a ^ b;   // 0b01111001 = 0x79 — Bit nào khác nhau
			uint8_t r4 = ~a;      // 0b01001010 = 0x4A — Đảo ngược toàn bộ

##### **1.6.3. Kỹ thuật bitmask**

* Kỹ thuật 1: Bật một bit (Set a bit)

		uint32_t reg = 0x00000000;
		uint32_t bit_mask = (1U << 5);  // Bật bit số 5
		reg |= bit_mask;                // reg = 0x00000020

* Kỹ thuật 2: Tắt một bit (Clear a bit)

		uint32_t reg = 0xFFFFFFFF;
		uint32_t bit_mask = (1U << 5);  // Tắt bit số 5
		reg &= ~bit_mask;               // reg = 0xFFFFFFDF

* Kỹ thuật 3: Kiểm tra trạng thái một bit (Test a bit)

		uint32_t STATUS_REG = 0b00100000;
		bool bit5_is_set = (STATUS_REG & (1U << 5)) != 0;  // true

* VD:

		// Giả lập thanh ghi GPIO của STM32
		volatile uint32_t* GPIOA_ODR = reinterpret_cast<uint32_t*>(0x40020014);

		constexpr uint32_t LED_PIN = 5;  // PA5

		// Bật LED:  *GPIOA_ODR |= (1U << LED_PIN);
		// Tắt LED:  *GPIOA_ODR &= ~(1U << LED_PIN);
		// Toggle:   *GPIOA_ODR ^= (1U << LED_PIN);

##### **1.6.4. Toán tử dịch bit (Bitwise Shift)**

* Dịch trái `<<`: Dịch tất cả bit sang trái `n` vị trí, điền `0` vào bên phải.

	*  Tương đương nhân với 2ⁿ — nhưng nhanh hơn toán tử `*` nhiều lần.

			int x = 3;
			int r1 = x << 1;   // 6  (3 × 2¹)
			int r2 = x << 2;   // 12 (3 × 2²)
			int r3 = x << 3;   // 24 (3 × 2³)

			// Tạo bitmask nhanh:
			uint32_t mask = 1U << 15;  // Bit 15 bật

* Dịch phải `>>`: Dịch tất cả bit sang phải `n` vị trí.

	*  Tương đương chia cho 2ⁿ (với số nguyên không dấu).
	
			int x = 32;
			int r1 = x >> 1;   // 16 (32 ÷ 2¹)
			int r2 = x >> 2;   // 8  (32 ÷ 2²)
			int r3 = x >> 3;   // 4  (32 ÷ 2³)

* **Lưu ý:**

	* Dịch phải số nguyên **có dấu** âm là hành vi phụ thuộc cài đặt (implementation-defined) trong C++.
	
	* Luôn dùng kiểu không dấu (`uint32_t`, `uint8_t`...) khi thao tác bitwise để đảm bảo tính xác định.   
				
### **II.  BRANCHING**

#### **2.1. IF/ELSE** 

##### **2.1.1.Cú pháp cơ bản**
 
		if (điều_kiện_1) {
		    // Thực thi khi điều_kiện_1 là true
		} else if (điều_kiện_2) {
		    // Thực thi khi điều_kiện_1 là false VÀ điều_kiện_2 là true
		} else {
		    // Thực thi khi tất cả điều kiện trên đều false
		}

* Trình biên dịch đánh giá các điều kiện tuần tự từ trên xuống và dừng lại tại điều kiện đầu tiên là `true`.

* Một khi đã khớp, các nhánh còn lại bị bỏ qua hoàn toàn — không kiểm tra thêm. 

##### **2.1.2.Toán tử điều kiện ba ngôi (Ternary Operator)**

		// Cú pháp: điều_kiện ? giá_trị_nếu_true : giá_trị_nếu_false
		int max = (a > b) ? a : b;
		std::string status = (errorCode == 0) ? "OK" : "Error";

		// Tương đương với:
		int max;
		if (a > b) max = a;
		else max = b;
	
##### **2.1.3. Khối khởi tạo trong `if` — Init-statement (C++17)**

* C++17 cho phép khai báo và khởi tạo biến ngay bên trong dấu ngoặc đơn của lệnh `if`, trước điều kiện, ngăn cách bởi dấu chấm phẩy `;`.


		// Cú pháp: if (khởi_tạo; điều_kiện)
		if (int status = checkSystemStatus(); status == 0) {
		    std::cout << "Hệ thống bình thường.\n";
		} else {
		    std::cout << "Mã lỗi: " << status << "\n";
		}
		// Biến status KHÔNG tồn tại ở đây — đã bị hủy khi ra khỏi if/else

##### **2.1.4. `if constexpr` — Rẽ nhánh tại thời gian biên dịch (C++17)**

	template<typename T>
	void process(T value) {
	    if constexpr (std::is_integral_v<T>) {
	        // Nhánh này chỉ được biên dịch khi T là kiểu số nguyên
	        std::cout << "Integer: " << value << "\n";
	    } else {
	        // Nhánh này chỉ được biên dịch khi T không phải số nguyên
	        std::cout << "Other: " << value << "\n";
	    }
	}

#### **2.2. SWITCH-CASE** 

##### **2.2.1. Khái niệm**
 
* `switch` là cấu trúc rẽ nhánh tối ưu cho việc so sánh đẳng thức (equality comparison) một biến với nhiều giá trị hằng số rời rạc.

* Điều kiện sử dụng `switch`:

	*  Biểu thức điều kiện phải có kiểu số nguyên (`int`, `char`, `enum`) hoặc kiểu chuyển đổi ngầm được sang số nguyên.
	
	*  Mỗi `case` phải là một **hằng số** biết trước lúc biên dịch — không thể dùng biến.
	
	*  Không thể dùng cho điều kiện phạm vi (`> 10`, `< 5`) hay so sánh chuỗi — đó là nhiệm vụ của `if/else`.

##### **2.2.2. Cú pháp**

		int errorCode = getErrorCode();

		switch (errorCode) {
		    case 0:
		        std::cout << "Success\n";
		        break;             // QUAN TRỌNG: Thoát khỏi switch

		    case 1:
		        std::cout << "Warning\n";
		        break;

		    case 2:               // Fall-through có chủ ý
		    case 3:               // Case 2 và 3 dùng chung xử lý
		        std::cout << "Minor Error\n";
		        break;

		    case 4:
		        logError();
		        [[fallthrough]];  // C++17: Báo compiler fall-through là chủ ý
		    case 5:
		        std::cout << "Critical Error\n";
		        break;

		    default:
		        std::cout << "Unknown error: " << errorCode << "\n";
		        break;
		}

##### **2.2.3. Đặc điểm kiến trúc: Jump Table**

	if/else chain:        switch (Jump Table):
	  if x == 0?   ──┐     index = x
	  if x == 1?   ──┤     jump to table[index]
	  if x == 2?   ──┤     ┌── case 0: addr_A
	  if x == 3?   ──┤     ├── case 1: addr_B
	  ...          ──┘     ├── case 2: addr_C
	  (O(n) so sánh)       └── ...
	                        (O(1) nhảy trực tiếp)

* **VD:**
		
		enum class SystemState { IDLE, RUNNING, ERROR, SHUTDOWN };

		SystemState state = SystemState::RUNNING;

		switch (state) {
		    case SystemState::IDLE:     handleIdle();     break;
		    case SystemState::RUNNING:  handleRunning();  break;
		    case SystemState::ERROR:    handleError();    break;
		    case SystemState::SHUTDOWN: handleShutdown(); break;
		    // Không cần default — compiler cảnh báo nếu thiếu case
		}
			

			
### **III.  KHỐI CHU TRÌNH LẶP**

#### **3.1. while và do-while**
 
##### **3.1.1. while (Pre-condition)**
 
* Đánh giá biểu thức điều kiện **trước** khi thực thi thân vòng lặp.

* Số lần thực thi tối thiểu là **0** — nếu điều kiện sai ngay từ đầu, thân vòng lặp không bao giờ chạy.

		// Cú pháp:
		while (điều_kiện) {
		    // Thực thi khi điều_kiện là true
		}

* Khi không biết trước số lần lặp — phụ thuộc vào trạng thái dữ liệu hoặc sự kiện bên ngoài.

		// Đọc dữ liệu cho đến khi nhận được ký tự kết thúc:
		char ch;
		while (std::cin.get(ch) && ch != '\n') {
		    processChar(ch);
		}

		// Chờ thiết bị sẵn sàng (polling trong embedded):
		while ((UART_STATUS_REG & UART_TX_READY_BIT) == 0) {
		    // Busy-wait cho đến khi UART sẵn sàng gửi
		}

##### **3.1.2. do-while (Post-condition)** 

* Thực thi thân vòng lặp **trước**, sau đó mới đánh giá điều kiện.

* Số lần thực thi tối thiểu luôn là **1** — thân vòng lặp chạy ít nhất một lần bất kể điều kiện. 
 
		// Cú pháp:
		do {
		    // Thực thi ít nhất một lần
		} while (điều_kiện);    // Chú ý: dấu ; sau ngoặc đơn là bắt buộc
		
* VD: vòng lặp nhập dữ liệu — cần nhập ít nhất một lần trước khi kiểm tra

		int value;
		do {
		    std::cout << "Nhap so nguyen duong (> 0): ";
		    std::cin >> value;
		    if (value <= 0) {
		        std::cout << "Gia tri khong hop le. Vui long nhap lai.\n";
		    }
		} while (value <= 0);
		// Đảm bảo value > 0 sau khi thoát vòng lặp


#### **3.2. FOR**	
		
##### **3.2.1. Cú pháp và luồng thực thi**	

*  Vòng lặp `for` đóng gói toàn bộ cấu trúc điều khiển lặp vào một dòng duy nhất:

		for (khởi_tạo; điều_kiện; bước_nhảy) {
		    // Thân vòng lặp
		}

*  Thứ tự thực thi:

		for (int i = 0; i < 10; ++i) {
		    std::cout << i << " ";
		}
		// i được khởi tạo một lần (i=0), kiểm tra (i<10), thực thi, tăng (++i), kiểm tra lại...
		// Biến i chỉ tồn tại trong phạm vi vòng lặp — không truy cập được bên ngoài

##### **3.2.2. Phạm vi biến đếm**	

*  Biến khai báo trong phần khởi tạo của `for` chỉ tồn tại trong **phạm vi vòng lặp**.

		for (int i = 0; i < 5; ++i) { /* ... */ }
		// std::cout << i; // LỖI BIÊN DỊCH: i không tồn tại ở đây

		// Trường hợp cần biến đếm sau vòng lặp — khai báo bên ngoài:
		int i = 0;
		for (; i < 5; ++i) { /* ... */ }
		std::cout << "Dừng tại: " << i;  // Hợp lệ


##### **3.2.3. Các biến thể của vòng lặp `for`**	

* Vòng lặp `for` với nhiều biến đếm:

		for (int i = 0, j = 10; i < j; ++i, --j) {
		    std::cout << i << " " << j << "\n";
		}

* Vòng lặp vô hạn (Infinite loop):

		for (;;) {
		    // Vòng lặp vô hạn — phổ biến trong main loop của embedded systems
		    processEvents();
		    if (shouldExit()) break;
		}

* Vòng lặp `for` với bước nhảy không đều:

		for (int i = 0; i < 100; i = i * 2 + 1) {
		    std::cout << i << " ";
		}
		// 0 1 3 7 15 31 63

#### **3.3. Range-based `for` loop**	
		
##### **3.3.1. Khái niệm**	

*  Range-based `for` (C++11) loại bỏ hoàn toàn việc quản lý biến đếm và biên giới mảng thủ công:

		// Cú pháp:
		for (khai_báo_biến : biểu_thức_dải) {
		    // thân vòng lặp
		}

*  VD:

		int arr[] = {10, 20, 30, 40, 50};

		// Cách cũ — dễ mắc lỗi off-by-one:
		for (int i = 0; i < 5; ++i) {
		    std::cout << arr[i] << " ";
		}

		// Range-based for — an toàn, rõ ràng:
		for (int val : arr) {
		    std::cout << val << " ";
		}

		// Với std::vector, std::string, std::map...:
		std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
		for (const auto& name : names) {
		    std::cout << name << "\n";
		}

##### **3.3.2. Syntactic Sugar với Iterator**	

*  Range-based `for` là cú pháp (syntactic sugar).

*  Trình biên dịch tự động biến đổi:

		for (auto x : container) { body; }

	*  thành tương đương:

			{
			    auto&& __range = container;
			    auto __begin = begin(__range);   // Gọi container.begin() hoặc begin(container)
			    auto __end   = end(__range);     // Gọi container.end()   hoặc end(container)
			    for (; __begin != __end; ++__begin) {
			        auto x = *__begin;
			        body;
			    }
			}

		*  Bất kỳ kiểu dữ liệu nào cung cấp hàm `begin()` và `end()` (trả về iterator) đều có thể dùng với range-based `for` — bao gồm cả các lớp tự định nghĩa.

##### **3.3.3. Ba chế độ truy cập biến trong range-based `for`**	

		std::vector<int> nums = {1, 2, 3, 4, 5};

		// Chế độ 1: Sao chép (Copy) — thay đổi không ảnh hưởng đến container gốc
		for (auto val : nums) {
		    val *= 2;  // nums không thay đổi
		}

		// Chế độ 2: Tham chiếu (Reference) — thay đổi TRỰC TIẾP container gốc
		for (auto& val : nums) {
		    val *= 2;  // nums bị thay đổi
		}

		// Chế độ 3: Tham chiếu hằng (Const reference) — đọc hiệu quả, không thay đổi
		for (const auto& val : nums) {
		    std::cout << val;  // Không sao chép, không cho phép thay đổi
		}

* Dùng `const auto&` khi chỉ đọc — tránh sao chép không cần thiết, đặc biệt với các đối tượng lớn (`std::string`, `std::vector`...).

#### **3.4. Tối ưu hóa vòng lặp (Loop Unrolling) từ trình biên dịch**	
		
##### **3.3.1. Vấn đề chi phí điều khiển vòng lặp**	

*  Mỗi lần lặp của vòng lặp thông thường, CPU phải thực hiện các thao tác điều khiển có chi phí:

	*  Thực thi thân vòng lặp (công việc thực sự)
	
	*  Tăng biến đếm (++i)
	
	*  Kiểm tra điều kiện (i < N)
	
	*   Lệnh nhảy có điều kiện (branch) trở về đầu vòng lặp
	
		*  Branch penalty: pipeline bị gián đoạn (4-20 chu kỳ CPU tùy kiến trúc)   

##### **3.3.2. Kỹ thuật Loop Unrolling**	

*  Loop Unrolling (trải phẳng vòng lặp) là kỹ thuật tối ưu hóa mà trình biên dịch thực hiện tự động ở cờ `-O2`, `-O3`:

	*  Compiler sao chép thân vòng lặp nhiều lần, giảm số lần kiểm tra điều kiện và nhảy.
	
	*  VD:
	
			// Mã nguồn gốc:
			for (int i = 0; i < 8; ++i) {
			    arr[i] = arr[i] * 2;
			}

			// Trình biên dịch tự sinh ra (tương đương mã máy):
			arr[0] = arr[0] * 2;
			arr[1] = arr[1] * 2;
			arr[2] = arr[2] * 2;
			arr[3] = arr[3] * 2;
			arr[4] = arr[4] * 2;
			arr[5] = arr[5] * 2;
			arr[6] = arr[6] * 2;
			arr[7] = arr[7] * 2;
			// Kết quả: 0 lần nhảy, 0 lần kiểm tra điều kiện

##### **3.3.3. Vectorization — Tối ưu hóa SIMD**	

*  Ở cờ `-O3`, trình biên dịch còn thực hiện auto-vectorization:

	*  Kết hợp nhiều phép tính thành một lệnh SIMD (Single Instruction, Multiple Data) của CPU.

			// Mã nguồn:
			for (int i = 0; i < 4; ++i) {
			    result[i] = a[i] + b[i];
			}

			// Trình biên dịch sinh ra lệnh SIMD (ví dụ SSE/AVX trên x86):
			// _mm_add_ps(a_vec, b_vec) — cộng 4 float cùng lúc trong một lệnh CPU duy nhất

##### **3.3.4. Pragma và Attribute**	

		// Gợi ý trình biên dịch unroll toàn bộ:
		#pragma GCC unroll 4
		for (int i = 0; i < 16; ++i) {
		    process(arr[i]);
		}

		// Ngăn tối ưu hóa một vòng lặp cụ thể (ví dụ: delay loop trong embedded):
		#pragma GCC optimize("O0")
		void delay(volatile uint32_t count) {
		    while (count--) { } // Compiler không được tối ưu hóa bỏ vòng lặp này
		}

##### **3.3.5. Câu lệnh điều hướng vòng lặp: `break` và `continue`**	

		for (int i = 0; i < 100; ++i) {
		    if (i == 50) break;     // Thoát ngay lập tức khỏi vòng lặp — i dừng tại 49
		    if (i % 2 == 0) continue;  // Bỏ qua lần lặp hiện tại — nhảy đến bước_nhảy
		    std::cout << i << " ";  // Chỉ in số lẻ từ 1 đến 49
		}

* `break`: Thoát khỏi **vòng lặp trong cùng** hoặc `switch` đang thực thi.

*  `continue`: Bỏ qua phần còn lại của **lần lặp hiện tại**, nhảy đến bước kiểm tra điều kiện tiếp theo.

* **Lưu ý với vòng lặp lồng nhau:** `break` và `continue` chỉ tác động đến vòng lặp **trong cùng** trực tiếp bao quanh chúng.

			for (int i = 0; i < 3; ++i) {
			    for (int j = 0; j < 3; ++j) {
			        if (j == 1) break;  // Chỉ thoát vòng lặp j — vòng lặp i tiếp tục
			        std::cout << i << "," << j << " ";
			    }
			}
			// In ra: 0,0  1,0  2,0
																										
   </details> 

