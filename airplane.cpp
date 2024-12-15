#include "airplane.h"
#include <limits>

Airplane::Airplane() : model(""), capacity(0) {}
Airplane::~Airplane() {}

void Airplane::inputAirplane() {
    while (true) {
        std::cout << "Введіть модель літака: ";
        std::cin >> model;
        if (!model.empty()) {
            break;
        } else {
            std::cerr << "Помилка: Модель не може бути порожньою. Спробуйте ще раз." << std::endl;
        }
    }

    while (true) {
        std::cout << "Введіть місткість літака: ";
        std::cin >> capacity;
        if (std::cin.fail() || capacity <= 0) {
            std::cerr << "Помилка: Місткість має бути додатним числом. Спробуйте ще раз." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void Airplane::displayAirplane() const {
    std::cout << "Модель: " << model << ", Місткість: " << capacity << std::endl;
}

void Airplane::writeToFile(std::ofstream& outFile) const {
    outFile << "Модель: " << model << ", Місткість: " << capacity << std::endl;
}
