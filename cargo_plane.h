#ifndef CARGO_PLANE_H
#define CARGO_PLANE_H

#include "airplane.h"

class CargoPlane : public Airplane {
private:
    int cargoWeight;

public:
    CargoPlane();
    ~CargoPlane();

    void inputAirplane() override;
    void displayAirplane() const override;
    double calculateServiceCost() const override;
    void writeToFile(std::ofstream& outFile) const override;
};

#endif