#include "cargo_plane.h"
#include <limits>

CargoPlane::CargoPlane() : cargoWeight(0) {}
CargoPlane::~CargoPlane() {}

void CargoPlane::inputAirplane() {
    Airplane::inputAirplane();
    while (true) {
        std::cout << "Введіть вагу вантажу (в кг): ";
        std::cin >> cargoWeight;
        if (std::cin.fail() || cargoWeight <= 0 || cargoWeight > capacity) {
            std::cerr << "Помилка: Вага вантажу має бути додатною і не перевищувати місткість літака (" << capacity << " кг). Спробуйте ще раз." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void CargoPlane::displayAirplane() const {
    Airplane::displayAirplane();
    std::cout << "Вага вантажу: " << cargoWeight << " кг" << std::endl;
}

double CargoPlane::calculateServiceCost() const {
    return cargoWeight * 0.5;
}

void CargoPlane::writeToFile(std::ofstream& outFile) const {
    Airplane::writeToFile(outFile);
    outFile << "Вага вантажу: " << cargoWeight << " кг" << std::endl;
}
