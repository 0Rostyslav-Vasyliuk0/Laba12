#include <iostream>
#include "passenger_plane.h"
#include "cargo_plane.h"
#include <vector>
#include <fstream>

// Функція для виведення інформації про літак
void displayPlaneInfo(const Airplane& plane) {
    plane.displayAirplane();
    std::cout << "Вартість обслуговування: $" << plane.calculateServiceCost() << "\n" << std::endl;
}

int main() {
    std::vector<Airplane*> airplanes;
    std::ofstream outFile("airplanes.txt", std::ios::out);
    std::ifstream inFile("airplanes.txt", std::ios::in);

    if (!outFile || !inFile) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return 1;
    }

    try {
        PassengerPlane* passengerPlane = new PassengerPlane();
        CargoPlane* cargoPlane = new CargoPlane();

        std::cout << "Введення даних пасажирського літака:" << std::endl;
        passengerPlane->inputAirplane();
        airplanes.push_back(passengerPlane);

        std::cout << "\nВведення даних транспортного літака:" << std::endl;
        cargoPlane->inputAirplane();
        airplanes.push_back(cargoPlane);

        for (const auto& plane : airplanes) {
            plane->writeToFile(outFile);
        }

        outFile.close();

        std::cout << "\nДані про літаки з файлу:" << std::endl;
        inFile.clear();
        inFile.seekg(0, std::ios::beg);

        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }

        inFile.close();

        for (const auto& plane : airplanes) {
            displayPlaneInfo(*plane);
        }

        for (auto& plane : airplanes) {
            delete plane;
        }

    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
