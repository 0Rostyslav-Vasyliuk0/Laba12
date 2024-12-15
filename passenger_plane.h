#ifndef PASSENGER_PLANE_H
#define PASSENGER_PLANE_H

#include "airplane.h"

class PassengerPlane : public Airplane {
private:
    int numberOfPassengers;

public:
    PassengerPlane();
    ~PassengerPlane();

    void inputAirplane() override;
    void displayAirplane() const override;
    double calculateServiceCost() const override;
    void writeToFile(std::ofstream& outFile) const override;
};

#endif
