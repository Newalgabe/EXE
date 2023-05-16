#ifndef CAR_RENTAL_H
#define CAR_RENTAL_H

#include <iostream>

using namespace std;

struct Car 
{
    char brand[100];
    char vehicleNumber[100];
    char color[100];
    int yearOfManufacture;
    char model[100];
};

struct Buyer 
{
    char name[100];
    char surname[100];
    char patronymic[100];
    int dateOfLease;
    double pricePerDay;
};

struct Contract 
{
    Car car;
    Buyer buyer;
};

void searchInformation();
void addInformation();
void deleteInformation();
void currentDebt();
void displayAllInformation();

#endif 