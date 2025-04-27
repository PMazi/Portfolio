#include "classes.h"

void DataBase::whatToPrint(vector<int> &printOptions){
    cout << "Wypisz po spacji informacje jakie chcesz wyswietlic:\n";
    cout << "1 - Imie i Nazwisko\n" << "2 - Stanowisko\n" <<"3 - Wiek\n" << "4 - Id pracownika\n" << "5 - Wynagrodzenie\n" << "6 - Haslo\n" << "0 - Koniec wprowadzania danych\n";
    cout << "Przyklad: 3 5 0 wypisze wiek i wynagrodzenie danego pracownika\n";
    cout << "Wybierz opcje: ";
    int printOption = 1;
    while(printOption != 0){
        cin >> printOption;
        printOptions.push_back(printOption);
    }
    cout << endl;
}

void AllEmployeesData::printData(vector<unique_ptr<Employee>> &employees, vector<int> printOptions){
    for (int employee = 0; employee < employees.size(); employee++){
        cout << employee+1 << "." << endl << "-----------------------" << endl;
        for(int option = 0; option < printOptions.size(); option++){
            if(printOptions[option] == 0){
                break;
            }
            else if(printOptions[option] == 1){
                cout << ">>>>>  " << employees[employee]->getName() << "  <<<<<" << endl;
            }
            else if(printOptions[option] == 2){
                cout << "Workplace: " << employees[employee]->getEmployeeType() << endl;
            }
            else if(printOptions[option] == 3){
                cout << "Age: " << employees[employee]->getAge() << endl;
            }
            else if(printOptions[option] == 4){
                cout << "ID: " << employees[employee]->getID() << endl;
            }
            else if(printOptions[option] == 5){
                cout << "Salary: " << employees[employee]->getSalary() << endl;
            }
            else if(printOptions[option] == 6){
                cout << "Password: " << employees[employee]->getPassword() << endl;
            }
        }
        cout << "-----------------------" << endl << endl;
    }
}

void WorkplaceData::printData(vector<unique_ptr<Employee>> &employees, vector<int> printOptions){
    int option;
    while(true){
        cout << "Podaj o jakich pracownikach informacje chcesz uzyskac" << endl;
        cout << "1 - Employees\n" << "2 - Financial Employees\n" << "3 - Administrative Employees\n" << "4 - Wyjdz" << endl;
        
        cout << "Wybierz opcje: ";

        while (!(cin >> option)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
        }
        cout << endl;

        if (option == 1){
            for (int employee = 0; employee < employees.size(); employee++){
                if (employees[employee]->getEmployeeType() == "Employee"){
                    cout << employee+1 << "." << endl << "-----------------------" << endl;
                    for(int option = 0; option < printOptions.size(); option++){
                        if(printOptions[option] == 0){
                            break;
                        }
                        else if(printOptions[option] == 1){
                            cout << ">>>>>  " << employees[employee]->getName() << "  <<<<<" << endl;
                        }
                        else if(printOptions[option] == 2){
                            cout << "Workplace: " << employees[employee]->getEmployeeType() << endl;
                        }
                        else if(printOptions[option] == 3){
                            cout << "Age: " << employees[employee]->getAge() << endl;
                        }
                        else if(printOptions[option] == 4){
                            cout << "ID: " << employees[employee]->getID() << endl;
                        }
                        else if(printOptions[option] == 5){
                            cout << "Salary: " << employees[employee]->getSalary() << endl;
                        }
                        else if(printOptions[option] == 6){
                            cout << "Password: " << employees[employee]->getPassword() << endl;
                        }
                    }
                    cout << "-----------------------" << endl << endl;
                }
            }
        }
        else if (option == 2){
            for (int employee = 0; employee < employees.size(); employee++){
                if (employees[employee]->getEmployeeType() == "Financial Employee"){
                    cout << employee+1 << "." << endl << "-----------------------" << endl;
                    for(int option = 0; option < printOptions.size(); option++){
                        if(printOptions[option] == 0){
                            break;
                        }
                        else if(printOptions[option] == 1){
                            cout << ">>>>>  " << employees[employee]->getName() << "  <<<<<" << endl;
                        }
                        else if(printOptions[option] == 2){
                            cout << "Workplace: " << employees[employee]->getEmployeeType() << endl;
                        }
                        else if(printOptions[option] == 3){
                            cout << "Age: " << employees[employee]->getAge() << endl;
                        }
                        else if(printOptions[option] == 4){
                            cout << "ID: " << employees[employee]->getID() << endl;
                        }
                        else if(printOptions[option] == 5){
                            cout << "Salary: " << employees[employee]->getSalary() << endl;
                        }
                        else if(printOptions[option] == 6){
                            cout << "Password: " << employees[employee]->getPassword() << endl;
                        }
                    }
                    cout << "-----------------------" << endl << endl;
                }
            }
        }
        else if (option == 3){
            for (int employee = 0; employee < employees.size(); employee++){
                if (employees[employee]->getEmployeeType() == "Administrative Employee"){
                    cout << employee+1 << "." << endl << "-----------------------" << endl;
                    for(int option = 0; option < printOptions.size(); option++){
                        if(printOptions[option] == 0){
                            break;
                        }
                        else if(printOptions[option] == 1){
                            cout << ">>>>>  " << employees[employee]->getName() << "  <<<<<" << endl;
                        }
                        else if(printOptions[option] == 2){
                            cout << "Workplace: " << employees[employee]->getEmployeeType() << endl;
                        }
                        else if(printOptions[option] == 3){
                            cout << "Age: " << employees[employee]->getAge() << endl;
                        }
                        else if(printOptions[option] == 4){
                            cout << "ID: " << employees[employee]->getID() << endl;
                        }
                        else if(printOptions[option] == 5){
                            cout << "Salary: " << employees[employee]->getSalary() << endl;
                        }
                        else if(printOptions[option] == 6){
                            cout << "Password: " << employees[employee]->getPassword() << endl;
                        }
                    }
                    cout << "-----------------------" << endl << endl;
                }
            }
        }
        else if(option == 4){
            return;
        }
        else{
            cout << "Wybrano nieprawidlowo opcje\n\n";
        }
    }
}