<details>
    <summary><strong>BÀI 1: TỔNG QUAN VỀ NGÔN NGỮ LẬP TRÌNH VÀ QUY TRÌNH BIÊN DỊCH</strong></summary>
## **BÀI 1: TỔNG QUAN VỀ NGÔN NGỮ LẬP TRÌNH**
### **I.  CÁC CHUẨN C++ VÀ TƯ TƯỞNG THIẾT KẾ**
#### **1.1. Quá trình phát triển** 
*  Quá trình này có thể được chia thành hai giai đoạn chính: 
	* **Classic C++:** 
	
		*  **C++98:**
		
			* Là tiêu chuẩn ISO đầu tiên của ngôn ngữ, đánh dấu bước trưởng thành quan trọng.
			
			*  Đưa vào thư viện mẫu chuẩn (Standard Template Library – STL)
			
			* Cung cấp các cấu trúc dữ liệu và thuật toán generic mạnh mẽ dựa trên cơ chế template. 
		*  **C++03:**
		
			* Bản sửa chữa lỗi (bug-fix release) nhằm hoàn thiện C++98, không giới thiệu các tính năng ngôn ngữ lớn mới.
				
	* **Modern C++:**
		*  **C++11:**
		
			* Phiên bản này giới thiệu hàng loạt tính năng then chốt thay đổi cách viết code:
			
				* **move semantics**
				
				* **smart pointers**
				
				* **lambda expressions**  
				
				* **auto keyword** 
			
		*  **C++14 và C++17:**
		
			* Hoàn thiện nền tảng bằng bổ sung các tính năng quan trọng như:
			
				* **structured bindings**
				
				* **std::optional**
				
				* **std::variant**  
		*  **C++20:**
		
			* Giai đoạn chuyển đổi với 4 thành phần chính
			
				* **Modules**
				
				* **Concepts**
				
				* **Coroutines**
				
				* **Ranges**   
				
#### **1.2. Multi-paradigm Programming**			
*  Khác với Java hay C# – những ngôn ngữ hướng đối tượng thuần túy, C++ theo triết lý “cung cấp công cụ, không áp đặt cách sử dụng”.
* C++ là ngôn ngữ đa mô hình (multi-paradigm), cho phép lập trình viên linh hoạt kết hợp nhiều phong cách lập trình trong cùng một dự án:
	
	* **Lập trình thủ tục (Procedural Programming):**
	
		*  Cho phép sử dụng các hàm không thuộc đối tượng cùng các thao tác bộ nhớ cấp thấp.
	
	* **Lập trình hướng đối tượng (Object Oriented Programming):**
	
		*  Hỗ trợ đầy đủ đóng gói (encapsulation), kế thừa (inheritance) và đa hình (polymorphism) thông qua hàm ảo (virtual functions).
	* **Lập trình tổng quát (Generic Programming):**
	
		*  Là một trong những điểm mạnh cốt lõi của C++.
		
		*  Thông qua template, lập trình viên có thể viết thuật toán và cấu trúc dữ liệu độc lập với kiểu dữ liệu mà không mất chi phí hiệu năng.
				
	* **Lập trình hàm (Functional Programming):**
	
		*  Được hỗ trợ mạnh mẽ nhờ biểu thức lambda, thư viện và các công cụ lập trình khai báo (declarative).
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
### **II.  CƠ CHẾ DỊCH MÃ VÀ PHÂN TÍCH CÚ PHÁP**
#### **2.1. Quá trình biên dịch** 
##### **2.1.1.  Giai đoạn 1: Tiền xử lý (Preprocessing)** 
* Trình tiền xử lý (Preprocessor) là bước đầu tiên và hoạt động ở mức văn bản thuần túy, không hiểu cú pháp C++. 
* Nó xử lý các chỉ thị bắt đầu bằng dấu `#`.
* Các công việc chính:
	* Loại bỏ toàn bộ chú thích (`//` và `/* */)`.
	
	*  Thay thế các macro (`#define`).
	
	* Xử lý chỉ thị `#include`: chèn toàn bộ nội dung của các tệp tiêu đề (header files) vào vị trí tương ứng.
	
*  Kết quả:
	*  Tạo ra một Translation Unit (Đơn vị dịch) – một tệp văn bản C++ khổng lồ, đã được mở rộng hoàn chỉnh, chứa toàn bộ mã nguồn cần thiết để biên dịch một tệp `.cpp`.
##### **2.1.2.  Giai đoạn 2: Biên dịch (Compilation)** 
* Trình biên dịch (Compiler) nhận Translation Unit và thực hiện phân tích cú pháp, ngữ nghĩa:
	* Phân tích từ vựng (lexical analysis).
	
	* Phân tích cú pháp và xây dựng cây cú pháp trừu tượng (Abstract Syntax Tree – AST).
	* Kiểm tra kiểu dữ liệu (type checking) và các quy tắc ngữ nghĩa.
	
	*  Thực hiện tối ưu hóa mã (code optimization).
	
*  Kết quả:
	*  Mã nguồn C++ được dịch sang mã hợp ngữ (Assembly code), thường có đuôi `.s ` hoặc `.asm`, đặc thù cho từng kiến trúc CPU (x86-64, ARM…).
##### **2.1.3.  Giai đoạn 3: Dịch Assembly (Assembly)** 
* Trình dịch hợp ngữ (Assembler) chuyển đổi mã Assembly thành mã máy (machine code).
*  Kết quả:
	*  Tạo ra các tệp đối tượng (object files) với đuôi `.o` (Linux/macOS) hoặc `.obj` (Windows).
	
*  Tệp đối tượng chứa mã máy nhưng chưa thể thực thi độc lập vì vẫn còn các tham chiếu đến các hàm và biến nằm ở các tệp khác (unresolved symbols).
#### **2.2. Bảng ký hiệu (Symbol Table) và cơ chế Name Mangling**			
*  Mỗi tệp đối tượng đều chứa một Symbol Table (Bảng ký hiệu), liệt kê:
	* Các hàm và biến toàn cục được định nghĩa trong tệp đó.
	
	* Các hàm và biến được sử dụng nhưng chưa có định nghĩa (unresolved external symbols).
	
*  C++ hỗ trợ nạp chồng hàm (function overloading), cho phép nhiều hàm cùng tên nhưng khác tham số.
	* Tuy nhiên, ở mức mã máy, mọi hàm phải có tên duy nhất.
	
	* Do đó, trình biên dịch C++ áp dụng cơ chế Name Mangling (biến đổi tên):
	
		*  Tên hàm được mã hóa tự động, kết hợp thông tin về không gian tên (namespace), tên lớp, và kiểu dữ liệu của tham số.
		
		*  Ví dụ: `void print(int x)` có thể được biến đổi thành `_Z5printi`, còn `void print(double x)` thành `_Z5printd`.
		
* Để gọi hàm từ thư viện C trong chương trình C++, lập trình viên sử dụng chỉ thị:
		extern "C" {
		    // Khai báo hàm C
		}
	
#### **2.3. Giai đoạn liên kết (Linking) và quy tắc ODR (One Definition Rule)**			
*  Giai đoạn Liên kết (Linking) là bước cuối cùng, trình liên kết (Linker) thực hiện:
	* Gom tất cả các tệp đối tượng và thư viện (`.lib, .a, .dll, .so…`).
	
	* Giải quyết các unresolved symbols bằng cách ghép địa chỉ thực sự của các hàm và biến.
	
	* Tạo ra tệp thực thi cuối cùng (`.exe` trên Windows hoặc ELF trên Linux/macOS).
	
*  Nếu trình liên kết không tìm thấy định nghĩa của một ký hiệu, sẽ báo lỗi Unresolved external symbol
* Để quá trình liên kết thành công, chương trình C++ phải tuân thủ nghiêm ngặt quy tắc ODR
	
	* **Khai báo (Declaration):**
	
		*  Có thể lặp lại nhiều lần
		
		*  Chỉ thông báo sự tồn tại của thực thể (hàm, biến, lớp) mà không cấp phát bộ nhớ hay cung cấp thân hàm.
		* VD: `extern int x;` hoặc `void foo();`
		
	* **Định nghĩa (Definition):**
	
		*  Phải chỉ xuất hiện đúng một lần trên toàn bộ chương trình.
		
		*  Đây là nơi cấp phát bộ nhớ (với biến) hoặc cung cấp thân hàm.
		* VD: `int x = 5;` hoặc `void foo() { ... }`
*  Ngoại lệ của ODR:
	* Các hàm được khai báo `inline`.
	
	* Các hàm mẫu (template functions) và lớp mẫu (template classes).
	
	* Các biến `constexpr` (trong một số trường hợp). 
### **III.  MEMORY LAYOUT**
#### **3.1. Cấu trúc không gian nhớ của tiến trình** 
##### **3.1.1. Text Segment (Phân đoạn mã)** 
* Chứa mã máy (machine code) đã được biên dịch.
* Phân đoạn này thường được ánh xạ với thuộc tính chỉ đọc (Read-Only) để ngăn chặn việc tự ghi đè lên chính mã thực thi, giúp tăng tính bảo mật và ổn định. 
##### **3.1.2. Data Segment và BSS Segment (Phân đoạn dữ liệu toàn cục)** 
* **Data Segment (Initialized Data):** 
	* Lưu trữ các biến toàn cục và biến tĩnh đã được khởi tạo với giá trị cụ thể (ví dụ: `int x = 100;`).
* **BSS Segment (Block Started by Symbol):** 
	* Chứa các biến toàn cục và biến tĩnh chưa được khởi tạo hoặc được khởi tạo bằng zero (ví dụ: `int y;`)
	* Hệ điều hành tối ưu hóa bằng cách chỉ ghi nhận kích thước vùng nhớ cần thiết trong tệp thực thi, thay vì lưu trữ các giá trị zero, giúp giảm dung lượng file.
* **Stack (Ngăn xếp):** 
	* Hoạt động theo nguyên tắc LIFO (Last-In-First-Out).
	* Được quản lý tự động bởi CPU thông qua thanh ghi Stack Pointer, nên tốc độ truy cập cực kỳ nhanh.
	
	* Dùng để lưu trữ: biến cục bộ, tham số hàm, và địa chỉ trả về.
	
	* Mỗi lần gọi hàm, một stack frame mới được tạo; khi hàm kết thúc, stack frame tự động được giải phóng.
	
	* Hạn chế: 
	
		* Kích thước stack thường bị giới hạn (thường từ 1MB đến 8MB tùy hệ điều hành).
		
		*  Việc sử dụng mảng lớn hoặc đệ quy sâu có thể dẫn đến Stack Overflow.    
* **Heap (Vùng nhớ động):** 
	* Vùng nhớ có kích thước lớn và linh hoạt, được quản lý bởi hệ điều hành.
	* Dùng cho các dữ liệu có kích thước chỉ biết tại thời điểm chạy (runtime), chẳng hạn như mảng động, cấu trúc dữ liệu lớn, hoặc dữ liệu nhận từ người dùng/mạng.
	
	* Lập trình viên chịu trách nhiệm cấp phát (`new, malloc`) và giải phóng (`delete, free`).
	
	* Việc quên giải phóng dẫn đến rò rỉ bộ nhớ (Memory Leak).  
						
#### **3.2. Storage Duration và Scope**			
##### **3.2.1. Scope**	
*  Xác định vùng mã nguồn mà tên (identifier) của biến/hàm có thể được truy cập (compile-time concept).
* Các loại scope chính trong C++:
	* **Block scope:** Giới hạn trong cặp ngoặc nhọn {} (thân hàm, khối lệnh, vòng lặp…).
	
	* **Global / Namespace scope:** Khai báo ngoài mọi hàm và lớp.
	* **Class scope:** Bên trong định nghĩa lớp (class hoặc struct).
##### **3.2.2. Storage Duration**	
*  Xác định thời điểm vùng nhớ được cấp phát và giải phóng (runtime concept), C++ hỗ trợ bốn loại:
	* **Automatic storage duration:**
	
		*  Áp dụng cho biến cục bộ thông thường.
		
		*  Vùng nhớ nằm trên Stack, được cấp phát khi luồng thực thi vào block scope và tự động hủy khi thoát khỏi scope đó.
	* **Static storage duration:**
	
		*  Vùng nhớ nằm trên Data/BSS segment.
		
		*  Biến được khởi tạo khi chương trình bắt đầu và tồn tại suốt vòng đời chương trình.
		
		*  Từ khóa `static` có thể áp dụng cho biến cục bộ để thay đổi storage duration mà không thay đổi scope.
	
	* **Dynamic storage duration:** 
	
		* Vùng nhớ nằm trên Heap.
		* Vòng đời hoàn toàn do lập trình viên kiểm soát thông qua `new/delete` (hoặc `malloc/free`).
	* **Thread-local storage duration:** 
	
		* Mỗi luồng (thread) có một bản sao riêng biệt của biến, tương tự static storage nhưng an toàn trong môi trường đa luồng.
#### **3.3. Undefined Behavior (UB) và Implementation-defined Behavior**			
##### **3.2.1. Implementation-defined Behavior**	
*  Những hành vi mà tiêu chuẩn không quy định cụ thể mà giao cho từng trình biên dịch quyết định, miễn là được ghi chép rõ ràng.
* VD:
	* Kích thước của các kiểu dữ liệu cơ bản (sizeof(int), sizeof(long)…) có thể khác nhau giữa các nền tảng (32-bit và 64-bit).
	
##### **3.2.2. Undefined Behavior (UB) – Hành vi không xác định**	
*  Khi chương trình chứa UB, tiêu chuẩn C++ không đảm bảo bất kỳ hành vi nào: chương trình có thể crash, chạy sai, hoặc hoạt động bình thường trong môi trường test nhưng thất bại trong môi trường thực tế.
*  Một số UB phổ biến cần tránh tuyệt đối:
	*  Truy cập mảng ngoài giới hạn (array out-of-bounds).
	
	*   Giải tham chiếu con trỏ null hoặc con trỏ lơ lửng (dangling pointer).
	
	*    Sử dụng biến cục bộ chưa được khởi tạo.
	
	*    Tràn số nguyên có dấu (signed integer overflow).
	
	*    Vi phạm quy tắc ODR.
	
	*   Truy cập đối tượng sau khi đã bị hủy (use-after-free).  
		    	 			
   </details> 


<details>
    <summary><strong>BÀI 2: HỆ THỐNG KIỂU DỮ LIỆU VÀ PHÂN LOẠI BIỂU THỨC</strong></summary>

## **BÀI 2: HỆ THỐNG KIỂU DỮ LIỆU VÀ PHÂN LOẠI BIỂU THỨC**

### **I.  PRIMITIVE TYPES VÀ MEMORY LAYOUT**

#### **1.1. Kiểu số nguyên, kích thước kiến trúc và `<cstdint>`** 

##### **1.1.1. Các kiểu số nguyên truyền thống** 

* C++ kế thừa từ C các kiểu số nguyên: `short, int, long, long long`.

* Để đảm bảo tính di động đa nền tảng, tiêu chuẩn C++ không quy định kích thước tuyệt đối mà chỉ đưa ra mối quan hệ tương đối:

		sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long) 

* Do đó, kích thước thực tế phụ thuộc vào Data Model của từng hệ điều hành:

	* **LP64 (Linux, macOS):** `int` là 32-bit, `long` và con trỏ là 64-bit.

	* **LLP64 (Windows):** `int` và `long` đều là 32-bit, chỉ `long long` và con trỏ là 64-bit. 

##### **1.1.2. `<cstdint>`** 

* Từ C++11, thư viện chuẩn cung cấp header (và `<stdint.h>` trong C) với các kiểu số nguyên có kích thước cố định

	* Có dấu: `int8_t, int16_t, int32_t, int64_t`

	* Không dấu: `uint8_t, uint16_t, uint32_t, uint64_t`

##### **1.1.3. Kiểu `size_t`** 

* `size_t` là kiểu số nguyên không dấu đặc biệt, có kích thước đủ lớn để biểu diễn kích thước bộ nhớ tối đa mà nền tảng hỗ trợ.

	* Kích thước mảng và bộ nhớ (`sizeof`).

	* Chỉ số khi duyệt container (ví dụ: `std::vector::size()`).

	* Các hàm liên quan đến bộ nhớ trong thư viện chuẩn.  

#### **1.2. Biểu diễn số thực dấu phẩy và kiểm soát sai số**			

##### **1.2.1. Chuẩn IEEE 754**		

*  C++ hỗ trợ hai kiểu số thực chính:

	* `float` (single precision – thường 32-bit)

	* `double` (double precision – thường 64-bit)

*  Cả hai đều tuân thủ chuẩn IEEE 754, một số thực được biểu diễn dưới dạng:

	<img width="452" height="48" alt="Image" src="https://github.com/user-attachments/assets/4e8f50af-5b4c-4807-9a65-fa632456c4f3" />

	* Sign bit: 1 bit (dấu).

	* Exponent: Phần mũ (8 bit với float, 11 bit với double).

	*  Mantissa (Fraction): Phần định trị (23 bit với float, 52 bit với double).
		
##### **1.2.2. Vấn đề sai số làm tròn (Floating-point Precision)**		

*  Do sử dụng cơ số 2, nhiều số thập phân không thể được biểu diễn chính xác (ví dụ: 0.1, 0.2).

*  Do đó, so sánh trực tiếp bằng toán tử `== `thường không an toàn:

		double a = 0.1 + 0.2;
		bool isEqual = (a == 0.3);  // Thường trả về false

#### **1.3. Kiểu ký tự, boolean và hậu tố hằng số (Literal Suffixes)**			

##### **1.3.1. Kiểu ký tự char**	

*  `char` trong C++ bản chất là một kiểu số nguyên 1 byte.

	*  Ví dụ: `char c = 'A'`; thực chất lưu giá trị số nguyên 65 (ASCII).
		
* Tiêu chuẩn quy định `sizeof(char) == 1` trên mọi nền tảng.

* Từ C++11 trở lên, ngôn ngữ bổ sung:

	*  `char16_t`(UTF-16)
		
	*  `char32_t` (UTF-32)
		
	* `char8_t` (UTF-8, từ C++20)
			
##### **1.3.2. Kiểu Boolean bool**	

*  Kiểu `bool` biểu diễn hai giá trị `true` và `false`.

*  Mặc dù chỉ cần 1 bit về mặt logic, nhưng do hạn chế địa chỉ hóa của CPU, `sizeof(bool)` luôn bằng 1 byte.

##### **1.3.3. Hậu tố hằng số (Literal Suffixes)**	

*  Trình biên dịch suy luận kiểu của hằng số (literal) dựa trên giá trị và hậu tố:

	| Literal | Kiểu suy luận mặc định | Hậu tố | Kiểu sau khi ép |
	|----------|------------------------|---------|------------------|
	| `10` | `int` | `U` | `unsigned int` |
	| `10` | `int` | `LL` | `long long` |
	| `3.14` | `double` | `f` | `float` |
	| `3.14` | `double` | `L` | `long double` |

### **II.  KHỞI TẠO VÀ ĐÁNH GIÁ TẠI THỜI GIAN BIÊN DỊCH**

#### **2.1. Uniform Initialization và Narrowing Conversion** 

##### **2.1.1.  Vấn đề C++ Classic** 

* Trước C++11, C++ hỗ trợ nhiều cách khởi tạo khác nhau (`=, (), {}`), dẫn đến nhiều vấn đề, nổi bật trong đó là lỗi Most Vexing Parse:

		Timer t();  // Không tạo đối tượng Timer bằng constructor mặc định
		            // mà là khai báo một hàm tên t, trả về kiểu Timer, không tham số


##### **2.1.2.  Cú pháp khởi tạo đồng nhất (Brace Initialization)** 

* C++11 giới thiệu Uniform Initialization (khởi tạo đồng nhất) sử dụng cặp ngoặc nhọn `{}` làm cú pháp chuẩn duy nhất:

		int a{5};                    // Khởi tạo biến nguyên thủy
		int arr[]{1, 2, 3};          // Khởi tạo mảng
		std::vector<int> v{1, 2, 3}; // Khởi tạo container
		Timer t{};                   // Khởi tạo đối tượng an toàn (default constructor)

##### **2.1.3.  Narrowing Conversion** 

* Một trong những lợi ích quan trọng nhất của khởi tạo đồng nhất là loại bỏ hoàn toàn chuyển đổi hẹp kiểu (narrowing conversion) tại thời điểm biên dịch:

			// Cú pháp cũ - nguy hiểm
			int x = 3.14;     // Hợp lệ, mất dữ liệu phần thập phân
			char c = 1000;    // Hợp lệ, gây tràn (overflow)

			// Cú pháp đồng nhất - an toàn
			int x{3.14};      // LỖI biên dịch: narrowing conversion từ double sang int
			char c{1000};     // LỖI biên dịch: giá trị ngoài phạm vi của char


#### **2.2. Tính hằng số (const) và tính toán tại thời gian biên dịch (constexpr, consteval)**			

##### **2.2.1. Từ khóa const**

* `const` thể hiện cam kết của lập trình viên rằng giá trị của biến sẽ không thay đổi sau khi được khởi tạo

* Giá trị có thể được xác định tại thời điểm chạy:

		const int userAge = getUserInput();  // Hợp lệ
		// userAge = 20;                     // Lỗi biên dịch	

##### **2.2.2. constexpr**

* `constexpr` yêu cầu trình biên dịch tính toán giá trị hoàn toàn tại thời điểm biên dịch nếu tất cả đầu vào đều là hằng số:

		constexpr int square(int x) {
		    return x * x;
		}

		constexpr int result = square(5);  // Được tính tại compile-time → result = 25

##### **2.2.3. consteval (C++20)**

* `consteval` là phiên bản mạnh hơn của constexpr.

* Hàm `consteval` bắt buộc phải được thực thi hoàn toàn tại thời điểm biên dịch.

* Nếu không thể, trình biên dịch sẽ báo lỗi:

		consteval int square(int x) {
		    return x * x;
		}

		// int n = square(5);     // OK
		// int a; cin >> a;
		// int b = square(a);     // LỖI biên dịch: không thể tính tại compile-time


#### **2.3. Các toán tử ép kiểu an toàn**			

*  C++ thay thế kiểu ép kiểu C truyền thống bằng bốn toán tử ép kiểu có mục đích rõ ràng, dễ kiểm soát và dễ tìm kiếm trong mã nguồn.

	* `static_cast(value)`

		* Toán tử ép kiểu tĩnh, an toàn nhất.

		* Thực hiện kiểm tra tại compile-time.

		*  Dùng cho: chuyển đổi số học, upcast/downcast trong kế thừa không đa hình, chuyển đổi `void*`.

				float f = 3.14f;
				int i = static_cast<int>(f);        // Rõ ràng và an toàn

	* `dynamic_cast(ptr)`

		* Dùng cho ép kiểu đa hình (polymorphism) với RTTI.

		* Thực hiện kiểm tra tại runtime.
			
		*  Nếu thất bại với con trỏ, trả về nullptr; với tham chiếu, ném ngoại lệ `std::bad_cast`.

	* `const_cast(ptr)`

		* Chỉ dùng để thêm hoặc loại bỏ thuộc tính `const/volatile`.

		* Thường cần khi tương tác với thư viện C legacy.
			
		*  Sửa đổi giá trị của đối tượng `const `ban đầu thông qua `const_cast` dẫn đến `Undefined Behavior`.

	* `reinterpret_cast(value)`

		* Thay đổi cách diễn dịch bit pattern mà không thay đổi bit.

		* Dùng trong lập trình hệ thống cấp thấp (địa chỉ phần cứng, network protocol, bit manipulation).
					
		*  Sử dụng sai rất dễ gây Segmentation Fault hoặc Undefined Behavior.

### **III.  OPERATORS VÀ EXPRESSION EVALUATION**

#### **3.1. Độ ưu tiên (Precedence) và trật tự kết hợp (Associativity)** 

* **Độ ưu tiên (Precedence):**

	* Độ ưu tiên quyết định toán tử nào được thực hiện trước.

	* VD: 

			a + b * c;   // Được hiểu là a + (b * c) vì * có độ ưu tiên cao hơn +

* **Trật tự kết hợp (Associativity):**

	* Khi nhiều toán tử có cùng độ ưu tiên, trật tự kết hợp quyết định hướng đánh giá:

		* Trái sang phải (Left-to-Right): Áp dụng cho hầu hết các toán tử số học (`+, -, *, /, %…`).

			a - b - c;   // Được hiểu là (a - b) - c

		* Phải sang trái (Right-to-Left): Áp dụng cho các toán tử gán (`=, +=, …`) và một số toán tử tiền tố (`++, --, *, &…`).

			a = b = c;   // Được hiểu là a = (b = c)
						
#### **3.2. Short-circuit Evaluation** 

* **Nguyên lý hoạt động:**

	* `&& (Logical AND)`:

		* Đánh giá từ trái sang phải.
		
		* Nếu toán hạng trái là `false`, toàn bộ biểu thức chắc chắn là `false` → bỏ qua toán hạng phải.  

	* `|| (Logical OR)`:

		* Nếu toán hạng trái là `true`, toàn bộ biểu thức chắc chắn là `true` → bỏ qua toán hạng phải.

* **Ứng dụng:**

		if (ptr != nullptr && ptr->value == 10) {
		    // ...
		}

	* Nếu `ptr` là `nullptr`, biểu thức `ptr->value` sẽ không bao giờ được thực thi, tránh lỗi Undefined Behavior (dereference null pointer).

* **Lưu ý:**

	* Không nên đặt các hàm có hiệu ứng phụ (side effects) ở toán hạng phải nếu việc thực thi của chúng là bắt buộc:

			if (isError() || updateLogFile()) { ... }  // updateLogFile() có thể không được gọi

#### **3.3. Bitwise Operations** 

* **Các toán tử bitwise cơ bản:**

	| Toán tử | Ý nghĩa | Ví dụ |  
	|----------|----------|--------|  
	| `&` | AND bit | `a & b` |  
	| `\|` | OR bit | `a \| b` |  
	| `^` | XOR bit | `a ^ b` |  
	| `~` | NOT bit (bù 1) | `~a` |  
	| `<<` | Dịch trái | `a << n` |  
	| `>>` | Dịch phải | `a >> n` |

* **Dịch bit (Bit Shifting):**

	* `x << n` tương đương toán học với `x × 2ⁿ` (nhanh hơn phép nhân thông thường).

	* `x >> n` tương đương với phép chia nguyên `x / 2ⁿ` (đối với số không dấu).

* **Kỹ thuật Bit Masking:**

	* Cho phép lưu trữ nhiều cờ trạng thái (flags) trong một biến nhỏ (thường là `uint8_t, uint32_t…`):

			uint8_t flags = 0;

			// Bật bit thứ n
			flags |= (1u << n);

			// Tắt bit thứ n
			flags &= ~(1u << n);

			// Đảo bit thứ n
			flags ^= (1u << n);

			// Kiểm tra bit thứ n
			bool isSet = (flags & (1u << n)) != 0;

	* **Lưu ý:**

		*  Dịch bit với số lượng vị trí lớn hơn hoặc bằng kích thước của kiểu dữ liệu (1 << 32 với `uint32_t`) hoặc dịch số âm là Undefined Behavior.
		
		*  Nên sử dụng hậu tố `u/ul/ull` khi dịch bit để tránh vấn đề với số có dấu.  
				    	 			
   </details> 
