#include "Input.h"
 
// #include <iostream>

int main() {
    std::cout << "Nhập một số nguyên: ";
    auto result = Input::readInt();
    
    if (result.has_value()) {
        std::cout << "Số bạn đã nhập là: " << result.value() << std::endl;
    } else {
        std::cout << "Lỗi: " << Input::getErrorMessage(result.error()) << std::endl;
    }

    return 0;
}