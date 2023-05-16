#include "car_rental.h"

void searchInformation() {
    cout << "\nEnter the search criteria: " << endl;
    cout << "a. Brand" << endl;
    cout << "b. Color" << endl;
    cout << "c. Number" << endl;
    cout << "d. Year of manufacture" << endl;
    cout << "e. Tenant" << endl;
    cout << "f. Price range" << endl;

    char option;
    cin >> option;

    FILE* file;
    if (fopen_s(&file, "../information.txt", "rb") != 0) {
        cout << "Error: could not open file for reading." << endl;
        return;
    }

    Contract contract;
    bool found = false;

    switch (option) {
    case 'a': {
        cout << "\nEnter the brand: ";
        char searchBrand[100];
        cin >> searchBrand;

        while (fread(&contract, sizeof(contract), 1, file) == 1) {
            if (strstr(contract.car.brand, searchBrand)) {
                found = true;
                cout << "\nBrand: " << contract.car.brand << endl;
                cout << "Vehicle number: " << contract.car.vehicleNumber << endl;
                cout << "Color: " << contract.car.color << endl;
                cout << "Year of manufacture: " << contract.car.yearOfManufacture << endl;
                cout << "Model: " << contract.car.model << endl;
                cout << "Name: " << contract.buyer.name << endl;
                cout << "Surname: " << contract.buyer.surname << endl;
                cout << "Patronymic: " << contract.buyer.patronymic << endl;
                cout << "Date of lease: " << contract.buyer.dateOfLease << endl;
                cout << "Price per day: " << contract.buyer.pricePerDay << endl << endl;
            }
        }
        break;
    }
    case 'b': {
        cout << "\nEnter the color: ";
        char searchColor[100];
        cin >> searchColor;

        while (fread(&contract, sizeof(contract), 1, file) == 1) {
            if (strstr(contract.car.color, searchColor)) {
                found = true;
                cout << "\nBrand: " << contract.car.brand << endl;
                cout << "Vehicle number: " << contract.car.vehicleNumber << endl;
                cout << "Color: " << contract.car.color << endl;
                cout << "Year of manufacture: " << contract.car.yearOfManufacture << endl;
                cout << "Model: " << contract.car.model << endl;
                cout << "Name: " << contract.buyer.name << endl;
                cout << "Surname: " << contract.buyer.surname << endl;
                cout << "Patronymic: " << contract.buyer.patronymic << endl;
                cout << "Date of lease: " << contract.buyer.dateOfLease << endl;
                cout << "Price per day: " << contract.buyer.pricePerDay << endl << endl;
            }
        }
        break;
    }
    case 'c': {
        cout << "\nEnter the vehicle number: ";
        char searchNumber[100];
        cin >> searchNumber;

        while (fread(&contract, sizeof(contract), 1, file) == 1) {
            if (strstr(contract.car.vehicleNumber, searchNumber)) {
                found = true;
                cout << "\nBrand: " << contract.car.brand << endl;
                cout << "Vehicle number: " << contract.car.vehicleNumber << endl;
                cout << "Color: " << contract.car.color << endl;
                cout << "Year of manufacture: " << contract.car.yearOfManufacture << endl;
                cout << "Model: " << contract.car.model << endl;
                cout << "Name: " << contract.buyer.name << endl;
                cout << "Surname: " << contract.buyer.surname << endl;
                cout << "Patronymic: " << contract.buyer.patronymic << endl;
                cout << "Date of lease: " << contract.buyer.dateOfLease << endl;
                cout << "Price per day: " << contract.buyer.pricePerDay << endl << endl;
            }
        }
        break;
    }
    case 'd': {
        cout << "\nEnter the year of manufacture: ";
        int searchYear;
        cin >> searchYear;

        while (fread(&contract, sizeof(contract), 1, file) == 1) {
            if (contract.car.yearOfManufacture == searchYear) {
                found = true;
                cout << "\nYear of manufacture: " << contract.car.yearOfManufacture << endl;
            }
        }
        break;
    }
    case 'e': {
        cout << "\nEnter the tenant name: ";
        char searchTenant[100];
        cin >> searchTenant;

        while (fread(&contract, sizeof(contract), 1, file) == 1) {
            if (strstr(contract.buyer.name, searchTenant)) {
                found = true;
                cout << "\nName: " << contract.buyer.name << endl;
                cout << "Surname: " << contract.buyer.surname << endl;
                cout << "Patronymic: " << contract.buyer.patronymic << endl;
                cout << "Date of lease: " << contract.buyer.dateOfLease << endl;
                cout << "Price per day: " << contract.buyer.pricePerDay << endl << endl;
            }
        }
        break;
    }
    case 'f': {
        cout << "\nEnter the price range (minimum and maximum): ";
        double minPrice, maxPrice;
        cin >> minPrice >> maxPrice;

        while (fread(&contract, sizeof(contract), 1, file) == 1) {
            if (contract.buyer.pricePerDay >= minPrice && contract.buyer.pricePerDay <= maxPrice) {
                found = true;
                cout << "\nBrand: " << contract.car.brand << endl;
                cout << "Vehicle number: " << contract.car.vehicleNumber << endl;
                cout << "Color: " << contract.car.color << endl;
                cout << "Year of manufacture: " << contract.car.yearOfManufacture << endl;
                cout << "Model: " << contract.car.model << endl;
                cout << "Name: " << contract.buyer.name << endl;
                cout << "Surname: " << contract.buyer.surname << endl;
                cout << "Patronymic: " << contract.buyer.patronymic << endl;
                cout << "Date of lease: " << contract.buyer.dateOfLease << endl;
                cout << "Price per day: " << contract.buyer.pricePerDay << endl << endl;
            }
        }
        break;
    }
    default:
        cout << "\nInvalid option. Please try again." << endl;
    }

    if (!found) {
        cout << "\nNo matching records found." << endl;
    }
fclose(file);
}



void addInformation() {
    FILE* file;
    if (fopen_s(&file, "../information.txt", "a") != 0) {
        cout << "Error: could not create file." << endl;
        return;
    }

    Car car;
    cout << "Enter brand: ";
    cin >> car.brand;
    cout << "Enter vehicle number: ";
    cin >> car.vehicleNumber;
    cout << "Enter color: ";
    cin >> car.color;
    cout << "Enter year of manufacture: ";
    cin >> car.yearOfManufacture;
    cout << "Enter model: ";
    cin >> car.model;

    Buyer buyer;
    cout << "Enter name: ";
    cin >> buyer.name;
    cout << "Enter surname: ";
    cin >> buyer.surname;
    cout << "Enter patronymic: ";
    cin >> buyer.patronymic;
    cout << "Enter date of lease (dd/mm/yyyy): ";
    int day, month, year;
    cin >> day >> month >> year;
    buyer.dateOfLease = day + (month - 1) * 30 + (year - car.yearOfManufacture) * 365;
    cout << "Enter price per day: ";
    cin >> buyer.pricePerDay;

    Contract contract = { car, buyer };
    fwrite(&contract, sizeof(Contract), 1, file);

    fclose(file);

    cout << "Information added successfully." << endl;
}



void deleteInformation() {
    cout << "\nChoose an option: " << endl;
    cout << "a. Delete car" << endl;
    cout << "b. Delete contract" << endl;
    cout << "c. Delete all information" << endl;

    char option;
    cin >> option;

    if (option == 'a' || option == 'b') {
        FILE* input;
        if (fopen_s(&input, "../information.txt", "rb") != 0) {
            cout << "Error: could not open file." << endl;
            return;
        }

        FILE* output;
        if (fopen_s(&output, "../temp.txt", "wb") != 0) {
            cout << "Error: could not create file." << endl;
            fclose(input);
            return;
        }

        char vehicleNumber[100];
        if (option == 'a') {
            cout << "Enter vehicle number of the car to be deleted: ";
        }
        else {
            cout << "Enter contract number of the contract to be deleted: ";
        }
        cin >> vehicleNumber;

        Contract contract;
        bool deleted = false;
        while (fread(&contract, sizeof(Contract), 1, input) != 0) {
            if (strcmp(contract.car.vehicleNumber, vehicleNumber) != 0) {
                fwrite(&contract, sizeof(Contract), 1, output);
            }
            else {
                deleted = true;
            }
        }

        fclose(input);
        fclose(output);

        if (!deleted) {
            remove("..\\temp.txt");
            if (option == 'a') {
                cout << "Car with vehicle number " << vehicleNumber << " not found." << endl;
            }
            else {
                cout << "Contract with contract number " << vehicleNumber << " not found." << endl;
            }
        }
        else {
            remove("..\\information.txt");
            rename("..\\temp.txt", "..\\information.txt");
            if (option == 'a') {
                cout << "Car with vehicle number " << vehicleNumber << " deleted successfully." << endl;
            }
            else {
                cout << "Contract with contract number " << vehicleNumber << " deleted successfully." << endl;
            }
        }
    }
    else if (option == 'c') {
        remove("..\\information.txt");
        cout << "All information deleted successfully." << endl;
    }
}



void currentDebt() {
    FILE* input;
    if (fopen_s(&input, "../information.txt", "rb") != 0) {
        cout << "Error: could not open file." << endl;
        return;
    }

    char name[100], surname[100];
    cout << "Enter name of the buyer: ";
    cin >> name;
    cout << "Enter surname of the buyer: ";
    cin >> surname;

    int day, month, year;
    cout << "Enter the current date (day month year): ";
    cin >> day >> month >> year;

    Contract contract;
    bool found = false;
    while (fread(&contract, sizeof(Contract), 1, input) != 0)
    {
        if (strcmp(contract.buyer.name, name) == 0 && strcmp(contract.buyer.surname, surname) == 0) {
            found = true;

            int leaseStartYear = contract.car.yearOfManufacture + (contract.buyer.dateOfLease / 365);
            int leaseStartMonth = ((contract.buyer.dateOfLease % 365) / 30) + 1;
            int leaseStartDay = (contract.buyer.dateOfLease % 365) % 30;

            int daysSinceLeaseStart = (day - leaseStartDay) + ((month - leaseStartMonth) * 30) + ((year - leaseStartYear) * 365);

            if (daysSinceLeaseStart > 0) {
                double debt = daysSinceLeaseStart * contract.buyer.pricePerDay;
                cout << "The current debt of " << name << " " << surname << " is " << debt << " dollars." << endl;
            }
            else {
                cout << name << " " << surname << " has no debt." << endl;
            }
        }
    }

    fclose(input);

    if (!found)
        cout << "Buyer not found." << endl;
}



void displayAllInformation()
{
    FILE* file;
    if (fopen_s(&file, "../information.txt", "rb") != 0)
    {
        cout << "Error: could not open file for reading." << endl;
        return;
    }

    Contract contract;
    while (fread(&contract, sizeof(contract), 1, file) == 1)
    {
        cout << "\nBrand: " << contract.car.brand << endl;
        cout << "Vehicle number: " << contract.car.vehicleNumber << endl;
        cout << "Color: " << contract.car.color << endl;
        cout << "Year of manufacture: " << contract.car.yearOfManufacture << endl;
        cout << "Model: " << contract.car.model << endl;
        cout << "Name: " << contract.buyer.name << endl;
        cout << "Surname: " << contract.buyer.surname << endl;
        cout << "Patronymic: " << contract.buyer.patronymic << endl;
        cout << "Date of lease: " << contract.buyer.dateOfLease << endl;
        cout << "Price per day: " << contract.buyer.pricePerDay << endl << endl;
    }

    fclose(file);
}