#include "car_rental.h"



int main() 
{
    FILE* fp;
    if (fopen_s(&fp, "information.txt", "rb") != 0) 
    {
        if (fopen_s(&fp, "information.txt", "wb") != 0) 
        {
            cout << "Error: could not create file." << endl;
            return 1;
        }
        fclose(fp);
    }

    int choice = 0;

    while (choice != 6) 
    {
        cout << "1. Search for information" << endl;
        cout << "2. Add information" << endl;
        cout << "3. Delete information" << endl;
        cout << "4. Calculate current debt of a particular client" << endl;
        cout << "5. Display all information on the screen" << endl;
        cout << "6. Exit" << endl;

        cout << endl;
        cin >> choice;

        switch (choice) 
        {
        case 1:
            searchInformation();
            break;
        case 2:
            addInformation();
            break;
        case 3:
            deleteInformation();
            break;
        case 4:
            currentDebt();
            break;
        case 5:
            displayAllInformation();
            break;
        default:
            break;
        }
    }
    return 0;
}