#include "App.h"

Fraction App::enterFractionUntilValidUseCase(){
    Fraction fraction;
    while (true) {
        std::cout << "Nhập phân số (ví dụ: 1/2): ";
        auto fractionInput = Input::readMultipleIntegers(Fraction::delimiter);
        if (!fractionInput.has_value()) {
            std::cout << std::format("Lỗi: {}\n", Input::getErrorMessage(fractionInput.error()));
        } else {
            if (fractionInput.value().size() == 1){
                fraction.setFraction(fractionInput.value()[0], 1);
            } else {
                fraction.setFraction(fractionInput.value()[0], fractionInput.value()[1]);
                if (fraction.getDenominator() == 0) {
                std::cout << "Lỗi: Mẫu số không thể là 0. Vui lòng nhập lại.\n";
                continue;
                }
            }
            break; // Thoát khỏi vòng lặp nếu nhập hợp lệ
        }
    }

    return fraction;
}

Vector<Fraction> App::enterMultipleFractionsUseCase() {
    int numberOfFractions;
    while (true) {
        std::cout << "Nhập số lượng phân số bạn muốn nhập: ";
        auto countInput = Input::readInt();
        if (!countInput.has_value()) {
            std::cout << std::format("Lỗi: {}. Vui lòng nhập lại...\n", Input::getErrorMessage(countInput.error()));
        } else {
            numberOfFractions = countInput.value();
            if (numberOfFractions < 0) {
                std::cout << "Số lượng phân số phải lớn hoặc bằng 0. Vui lòng nhập lại...\n";
            } else {
                break;
            }
        }
    }

    Vector<Fraction> fractions;
    for (int i = 0; i < numberOfFractions; ++i) {
        std::cout << std::format("Nhập phân số thứ {}: ", i + 1);
        Fraction fraction = enterFractionUntilValidUseCase();
        fractions.push_back(fraction);
        std::cout << std::format("Phân số thứ {} đã được nhập: {}\n", i + 1, fraction.toString());
    }

    std::cout << std::format("Đã nhập {} phân số thành công.\n", numberOfFractions);
    return fractions;
}

Fraction App::computeFractionsSumUseCase(const Vector<Fraction>& fractions) {
    Fraction sum(0, 1);
    for (int i = 0; i < fractions.size(); ++i) {
        sum = sum + fractions[i];
    }

    return sum;
}

void App::printSumReportUseCase(const Fraction& f) {
    std::string header = "FRACTION SUM REPORT";
    std::string footer = "END OF REPORT";
    size_t padding = 10; // Padding for the borders
    size_t maxWidth = std::max(header.size(), footer.size()) + padding * 2;

    std::cout << std::format("|{}|", std::string(maxWidth - 2, '=')) << "\n";
    std::cout << std::format("|{:^{}s}|", header, maxWidth - 2) << "\n";
    std::cout << std::format("|{}|", std::string(maxWidth - 2, '-')) << "\n";

    std::cout << std::format("|{:^{}s}|", std::format("Sum of all the fractions: {}", f.toString()), maxWidth - 2) << "\n";
    
    std::cout << std::format("|{}|", std::string(maxWidth - 2, '-')) << "\n";
    std::cout << std::format("|{:^{}s}|", footer, maxWidth - 2) << "\n";
    std::cout << std::format("|{}|", std::string(maxWidth - 2, '=')) << "\n";
}