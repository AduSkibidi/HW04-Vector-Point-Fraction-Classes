# Lab 04 - Working with Array of Objects

**Tác giả**: Nguyen The Quan (24127514)  
**Môn học**: Lập trình hướng đối tượng (Object-Oriented Programming)  
**Trường**: VNU-HCMUS  
**Năm**: 2025  

## 📋 Mô tả

Bài thực hành số 4 về làm việc với mảng các đối tượng, bao gồm các lớp cơ bản trong C++:
- **Point**: Lớp biểu diễn điểm 2D
- **Fraction**: Lớp biểu diễn phân số
- **Vector**: Template mảng động tổng quát
- **Line**: Lớp biểu diễn đoạn thẳng
- **Input**: Lớp xử lý nhập liệu với validation
- **Parser**: Lớp phân tích chuỗi
- **App**: Lớp ứng dụng giao diện người dùng

## 🗂️ Cấu trúc Project

```
HW04/
├── Point/
│   ├── Point.h           # Lớp Point - điểm 2D
│   ├── Point.cpp         # Implementation Point
│   ├── App.h             # App cho Point
│   ├── App.cpp           # Implementation App Point
│   ├── main.cpp          # Chương trình chính Point
│   ├── main_test.cpp     # Test suite Point
│   └── class_diagram.md  # Sơ đồ lớp Point
├── Fractions/
│   ├── Fractions.h       # Lớp Fraction - phân số
│   ├── Fractions.cpp     # Implementation Fraction
│   ├── App.h             # App cho Fraction
│   ├── App.cpp           # Implementation App Fraction
│   ├── main.cpp          # Chương trình chính Fraction
│   ├── main_test.cpp     # Test suite Fraction
│   └── class_diagram.md  # Sơ đồ lớp Fraction
├── Vector/
│   ├── Vector.h          # Template Vector - mảng động
│   └── Vector.cpp        # (Rỗng - implementation trong header)
├── Line/
│   ├── Line.h            # Lớp Line - đoạn thẳng
│   └── Line.cpp          # Implementation Line
├── Input/
│   ├── Input.h           # Lớp Input - xử lý nhập liệu
│   └── Input.cpp         # Implementation Input
├── Parser/
│   ├── Parser.h          # Lớp Parser - phân tích chuỗi
│   └── Parser.cpp        # Implementation Parser
├── RegexPattern/
│   └── RegexPattern.h    # Các pattern regex thông dụng
├── utils/
│   └── utils.h           # Hàm tiện ích (gcd)
└── README.md             # File này
```

## ✨ Tính năng chính

### 🔵 Point (Điểm 2D)
- Lưu trữ tọa độ x, y
- Getter/setter cho tọa độ
- Ký tự phân cách configurable (`,`)

### 🔢 Fraction (Phân số)
- Tự động rút gọn phân số
- Các phép toán: cộng (+), trừ (-), nhân (*)
- Chuyển đổi sang chuỗi
- Ký tự phân cách configurable (`/`)

### 📦 Vector<T> (Mảng động)
- Template class tổng quát
- Tự động mở rộng capacity
- Copy constructor và assignment operator
- Các thao tác: push_back, operator[], size, clear

### 📏 Line (Đoạn thẳng)
- Được định nghĩa bởi 2 điểm Point
- Tính độ dài đoạn thẳng

### ⌨️ Input (Xử lý nhập liệu)
- Validation bằng regex
- Hỗ trợ std::expected cho error handling
- Đọc int, double, string, multiple values
- Error messages chi tiết

### 🔍 Parser (Phân tích chuỗi)
- Tách chuỗi theo delimiter
- Xử lý multiple values

## 🛠️ Build và Run

### Yêu cầu hệ thống
- **Compiler**: C++23 compatible (g++, clang++, MSVC)
- **OS**: Windows, macOS, Linux
- **Libraries**: STL standard library

### Build bằng g++

#### Point Application
```bash
cd Point
g++ -std=c++23 -I.. -o main main.cpp
./main
```

#### Fraction Application  
```bash
cd Fractions
g++ -std=c++23 -I.. -o main main.cpp
./main
```

#### Chạy Tests
```bash
# Point tests
cd Point
g++ -std=c++23 -I.. -o test main_test.cpp
./test

# Fraction tests
cd Fractions  
g++ -std=c++23 -I.. -o test main_test.cpp
./test
```

### Build với Visual Studio (Windows)
1. Mở folder project trong Visual Studio
2. Chọn file main.cpp hoặc main_test.cpp
3. Build và Run (Ctrl+F5)

## 🧪 Testing

Project bao gồm comprehensive test suite:

### Point Tests
- Constructor tests (default, parameterized)
- Getter/setter tests
- Distance calculation tests
- Edge cases

### Fraction Tests  
- Constructor tests với validation
- Arithmetic operations (+, -, *)
- Fraction reduction tests
- String conversion tests
- Edge cases (zero, negative numbers)

### Chạy tất cả tests
```bash
# Script đơn giản thay thế Google Test
cd Point && g++ -std=c++23 -I.. -o test main_test.cpp && ./test
cd ../Fractions && g++ -std=c++23 -I.. -o test main_test.cpp && ./test
```

## 📚 Documentation

Tài liệu đầy đủ được tạo bằng Doxygen:

```bash
cd ../docs
doxygen Doxyfile
```

Xem tài liệu tại: `docs/html/html/index.html`

## 🎯 Use Cases

### Point Application
1. Nhập nhiều điểm từ bàn phím
2. Tính tổng khoảng cách giữa các điểm liên tiếp
3. Hiển thị báo cáo kết quả

### Fraction Application
1. Nhập nhiều phân số từ bàn phím  
2. Tính tổng các phân số
3. Hiển thị kết quả đã rút gọn

## 🔧 Class Diagrams

Xem sơ đồ lớp chi tiết:
- [Point Class Diagram](Point/class_diagram.md)
- [Fraction Class Diagram](Fractions/class_diagram.md)

## 📝 Design Patterns & Best Practices

- **Template Programming**: Vector<T> cho generic container
- **Error Handling**: std::expected cho type-safe error handling  
- **RAII**: Automatic memory management trong Vector
- **Static Members**: Delimiter configuration
- **Const Correctness**: Const methods và parameters
- **Documentation**: Đầy đủ Doxygen comments

## 🚀 Advanced Features

- **Generic Programming**: Template Vector có thể chứa bất kỳ type nào
- **Regex Validation**: Input validation với custom patterns
- **Automatic Reduction**: Fraction tự động rút gọn về dạng tối giản
- **Memory Management**: Vector tự động quản lý memory allocation
- **Cross-platform**: Code tương thích multiple OS

## 🤝 Contributing

1. Fork repository
2. Tạo feature branch
3. Commit changes với message chi tiết
4. Push và tạo Pull Request

## 📄 License

Dự án này được tạo cho mục đích học tập tại VNU-HCMUS.

## 📞 Contact

**Nguyen The Quan**  
Student ID: 24127514  
University: VNU-HCMUS  
Year: 2025

---
