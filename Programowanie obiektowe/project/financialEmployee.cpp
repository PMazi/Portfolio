#include "classes.h"

FinancialEmployee::FinancialEmployee(int &ID_count) : Employee(ID_count){
    setSalary(8000); //Ustawia wynagrodzenie na 8000 dla FinancialEmployee
    setType("Financial Employee");
}

//Zmiana wynagrodzenia pracownika
void FinancialEmployee::changeSalary(vector<unique_ptr<Employee>> &employees){
    int identyfier = 0;

    while (identyfier == 0 || identyfier == getID()){
        cout << "Podaj identyfikator pracownika ktorego wynagrodzenie chcesz zmienic: ";
        
        while(!(cin >> identyfier)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledna opcje. Wprowadz dane ponownie: ";
        }
        cout << endl;

        if (identyfier == 0){
            cout << "Nie mozesz zmienic wynagrodzenia Leadera!" << endl << endl;
        }
        if(identyfier == getID()){
            cout << "Nie mozesz zmienic wlasnego wynagrodzenia!" << endl << endl;
        }
    }

    bool changed = false;
    for (int employee = 0; employee < employees.size(); employee++){
        if (employees[employee]->getID() == identyfier){
            int newSalary;
            cout << "Podaj nowe wynagrodzenie pracownika: ";
            
            while(!(cin >> newSalary)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Podano bledna opcje. Wprowadz dane ponownie: ";
            }
            cout << endl;

            employees[employee]->setSalary(newSalary);

            changed = true;
            cout << "Pensja pracownika o ID = " << identyfier << " zostala zmieniona na " << employees[employee]->getSalary() << endl << endl;
        }
    }
    if (!changed){
        int option = 0;
        while(option != 1 || option != 2){
            cout << "Nie ma pracownika o takim ID, czy nadal chcesz dokonac zmiany wynagrodzenia pracownika?" << endl;
            cout << "1 - tak" << endl << "2 - nie" << endl;
            
            cout << "Wybierz opcje: ";
            while(!(cin >> option)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Podano bledna opcje. Wprowadz dane ponownie: ";
            }
            cout << endl;

            switch (option){
                case 1:
                    changeSalary(employees);
                    return;
                case 2:
                    return;
                default:
                    cout << "Wybrano nieprawidlowa opcje" << endl << endl;
                    break;
            }
        }
    }    
}

void FinancialEmployee::activity(vector<unique_ptr<Employee>> &employees){
    while(true){
        cout << "Wybierz czynnosc:" << endl;
        cout << "1 - Wyswietl swoje dane" << endl;
        cout << "2 - Zmien wynagrodzenie pracownika" << endl;
        cout << "3 - Popros o podwyzke" << endl;
        cout << "4 - Wyloguj sie " << endl;
        int option;
        cout << "Wybierz opcje: ";
        while(!(cin >> option)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledna opcje. Wprowadz dane ponownie: ";
        }
        cout << endl;
        
        switch (option){
            case 1:
                getEmployeeData();
                break;
            case 2:
                //wywołanie funkcji changeSalary nadpisanej z klasy FinancialEmployee
                changeSalary(employees);
                break;
            case 3:
                //wywołanie funkcji change salary z klasy Employee
                Employee::changeSalary();
                break;
            case 4:
                cout << "Nastapilo wylogowanie" << endl << endl;
                return;
            default:
                cout << "Wybrano nieprawidlowa opcje" << endl << endl;
        }
    }
}