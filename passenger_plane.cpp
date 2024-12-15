#include "passenger_plane.h"
#include <limits>

PassengerPlane::PassengerPlane() : numberOfPassengers(0) {}
PassengerPlane::~PassengerPlane() {}

void PassengerPlane::inputAirplane() {
    Airplane::inputAirplane();
    while (true) {
        std::cout << "Введіть кількість пасажирів: ";
        std::cin >> numberOfPassengers;
        if (std::cin.fail() || numberOfPassengers <= 0 || numberOfPassengers > capacity) {
            std::cerr << "Помилка: Кількість пасажирів має бути додатною і не перевищувати місткість літака (" << capacity << "). Спробуйте ще раз." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

void PassengerPlane::displayAirplane() const {
    Airplane::displayAirplane();
    std::cout << "Кількість пасажирів: " << numberOfPassengers << std::endl;
}

double PassengerPlane::calculateServiceCost() const {
    return numberOfPassengers * 50.0;
}

void PassengerPlane::writeToFile(std::ofstream& outFile) const {
    Airplane::writeToFile(outFile);
    outFile << "Кількість пасажирів: " << numberOfPassengers << std::endl;
}