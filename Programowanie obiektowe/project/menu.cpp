#include "classes.h"
#include <limits>

void Menu::showMenu(vector<unique_ptr<Employee>> &employees, vector<Employee> deletedEmployees, int &ID_count){
    
    while(true){
        cout << "----------- MENU -----------" << endl;
        cout << "1 - Logowanie\n" << "2 - Baza Danych\n" "3 - Wyjscie z systemu\n"; 
        int menuOption;
        cout << "Wybierz opcje: "; 
        
        while (!(cin >> menuOption)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledne dane. Wprowadz ponownie opcje; ";
        }
        cout << endl;

        if(menuOption == 1){
            string password;
            bool isPasswordCorrect = false;
            cout << "----------- LOGOWANIE -----------" << endl;
            cout << "Podaj haslo: "; cin >> password; cout << endl;

            for(int employee = 0; employee < employees.size(); employee++){
                if(employees[employee]->getPassword() == password){
                    isPasswordCorrect = true;
                    if(employees[employee]->getEmployeeType() == "Employee"){
                        employees[employee]->activity(employees);
                    }
                    else if(employees[employee]->getEmployeeType() == "Team Leader"){
                        dynamic_cast<TeamLeader*>(employees[employee].get())->activity(employees, deletedEmployees, ID_count);   
                    }
                    else if(employees[employee]->getEmployeeType() == "Financial Employee"){
                        employees[employee]->activity(employees);
                    }
                    else if(employees[employee]->getEmployeeType() == "Administrative Employee"){
                        employees[employee]->activity(employees);
                    }
                }
            }
            if(!isPasswordCorrect){
                cout << "Podano nieprawidlowe haslo!" << endl << endl;
            }  
        }
        else if(menuOption == 2){
            int printOption = 0;
            while(printOption != 3){
                cout << "----------- BAZA DANYCH -----------" << endl;
                cout << "Jakie informacje chcesz wyswietlic?\n";
                cout << "1 - Dane wszystkich pracownikow\n" << "2 - Dane o pracownikach z konkretnych stanowisk\n" << "3 - Wyjdz\n";
                cout << "Wybierz opcje: ";

                while (!(cin >> printOption)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
                }
                cout << endl;

                if(printOption == 1){
                    AllEmployeesData allEmployeesData;
                    int showOption = 0;
                    while(showOption != 1 && showOption != 2){
                        cout << "Wybierz sposob wyswietlania informacji:\n";
                        cout << "1 - Wszystkie informacje o pracownikach\n" << "2 - Wybrane informacje o pracownikach\n";
                        cout << "Wybierz opcje: ";

                        while (!(cin >> showOption)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
                        }
                        cout << endl;

                        if(showOption == 1){
                            //wypisywanie danych polega na odczytywaniu wektora printOptions
                            //kazdy kolejny indeks wektora printOptions zawiera informacje co ma być wypisane
                            //domyślnie wypisanie danych w funkcji printData odbywa się za pomocą opcji 1 2 3 4 5 6
                            vector<int> printOptions = {1, 2, 3, 4, 5, 6};
                            allEmployeesData.printData(employees, printOptions);
                            break;
                        }
                        else if(showOption ==2){

                            vector<int> printOptions;
                            //funckja wypelnia wektor printOptions, aby wyswietlic dane w sposob spersonalizowany
                            allEmployeesData.whatToPrint(printOptions);
                            allEmployeesData.printData(employees, printOptions);
                            break;

                        }
                        else{
                            cout << "Wybrano nieprawidlowa opcje\n\n";
                        }
                    }
                }
                else if(printOption == 2){
                    WorkplaceData workplaceData;
                    int showOption = 0;
                    while(showOption != 1 && showOption != 2){
                        cout << "Wybierz sposob wyswietlenia informacji:\n";
                        cout << "1 - Wszystkie informacje o pracownikach\n";
                        cout << "2 - Wybrane informacje o pracownikach\n";
                        cout << "Wybierz opcje: ";

                        while (!(cin >> showOption)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
                        }
                        cout << endl;

                        if(showOption == 1){
                            vector<int> printOptions = {1, 2, 3, 4, 5, 6};
                            workplaceData.printData(employees, printOptions);
                        }
                        else if(showOption == 2){
                            vector<int> printOptions;
                            workplaceData.whatToPrint(printOptions);
                            workplaceData.printData(employees, printOptions);
                        }
                        else{
                            cout << "Wybrano nieprawidlowa opcje\n\n";
                        }
                    }   
                }
                else if(printOption == 3){
                    break;
                }
                else{
                    cout << "Wybrano nieprawidlowa opcje\n\n";
                }
            }
        }
        else if(menuOption == 3){
            return;
        }
        else{
            cout << "Wybrano nieprawidlowa opcje" << endl << endl;
        }
    }
}