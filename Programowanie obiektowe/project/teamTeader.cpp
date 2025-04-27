#include "classes.h"

//konstruktor klasy TeamLeader, który dziedziczy konstruktor klasy Employee
TeamLeader::TeamLeader(int &ID_count) : Employee(ID_count){
    setSalary(25000); //ustawia zmienną salary dla TeamLeader na 25000
    setType("Team Leader");
}

//Wyświetlanie informacji o pracownikach
void TeamLeader::getEmployeeData(vector<unique_ptr<Employee>> &employees){
    for (int employee = 0; employee < employees.size(); employee++){
        cout << "------------------------" << endl;
        cout << ">>>>>  " << employees[employee]->getName() << "  <<<<<" << endl;
        cout << "Workplace: " << employees[employee]->getEmployeeType() << endl;
        cout << "Age: " << employees[employee]->getAge() << endl;
        cout << "Salary: " << employees[employee]->getSalary() << endl;
        cout << "ID: " << employees[employee]->getID() << endl;
        cout << "Password: " << employees[employee]->getPassword() << endl;
        cout << "------------------------" << endl << endl;
    }
}


// funkcja dodająca pracownika do wektora employees
void TeamLeader::addEmployee(vector<unique_ptr<Employee>> &employees, int &ID_count){
    cout << "Jakiego pracownika chcesz zatrudnic?" << endl;
    cout << "1 - Zwyklego pracownika" << "\n2 - Pracownika ds. finansow" << "\n3 - Pracownika z dzialu administracji" << "\n4 - Powrot" << endl;
    int option;
    cout << "Wybierz opcje: ";
    while (!(cin >> option)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
    }
    cout << endl;
                    
    switch(option){
        case 1:{
            employees.push_back(make_unique<Employee>(ID_count));
            break;
        }
        case 2:{ 
            employees.push_back(make_unique<FinancialEmployee>(ID_count));
            break;
        }
        case 3:{
            employees.push_back(make_unique<AdministrativeEmployee>(ID_count));
            break;
        }
        default:
            cout << endl << "Wybrano nieprawidlowa opcje" << endl;
            return;
    }
}


//funkcja usuwa pracownika z wektora employee
void TeamLeader::delEmployee(vector<unique_ptr<Employee>> &employees, vector<Employee> &deletedEmployees, vector<string> &passwords){
    
    int identyfier = 0;
    while (true){
        cout << "Podaj ID pracownika, ktorego chcesz usunac: ";
        while (!(cin >> identyfier)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
        }
        cout << endl;

        if (identyfier == 0){
            cout << "Nie mozesz usunac Lidera!" << endl << endl;
            break;
        } 

        bool deleted = false;
        for (int employee = 0; employee < employees.size(); employee++)
        {
            if (employees[employee]->getID() == identyfier){
                //dodawanie pracownika do wektora deletedEmployees poprzez *employees[employee]
                //employees[employee] ma typ wskaźnika, a chcemy dodać obiekt, więc *employees[employee]
                deletedEmployees.push_back(*employees[employee]); 
                //usuwanie pracownika z wektora employees
                employees.erase(employees.begin() + employee);
                //usuwa haslo z wektora haseł
                passwords.erase(passwords.begin() + employee);
                deleted = true;
                cout << "Pracownik o identyfikatorze " << identyfier << " zostal usuniety" << endl << endl;
                return;
            }    
        }
        if(!deleted){
            cout << "Nie ma pracownika o takim ID" << endl << endl;
            int option = 0;
            while(option != 1){
                cout << "Czy chcesz wybrac innego pracownika do usuniecia?" << endl;
                cout << "1 - Tak" << endl << "2 - Nie" << endl;

                cout << "Wybierz opcje: ";
                while (!(cin >> option)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
                }
                cout << endl;

                if(option == 1){
                    break;
                }
                else if(option == 2){
                    return;
                } 
                else{
                    cout << "Wybrano nieprawidlowa opcje" << endl << endl;
                }
            }
        }   
    }
}

void TeamLeader::getDeletedEmployeesData(vector<Employee> &deletedEmployees){
    if (deletedEmployees.size() == 0){
        cout << "Brak danych" << endl;
    }
    else{
        cout << "Pracownicy ktorzy pracowali w przeszlosci:" << endl << endl;
        for (int employee = 0; employee < deletedEmployees.size(); employee++){
            cout << "------------------" << endl;
            cout << ">>>>>  " << deletedEmployees[employee].getName() << "  <<<<<" << endl;
            cout << "Workplace: " << deletedEmployees[employee].getEmployeeType() << endl;
            cout << "Age: " << deletedEmployees[employee].getAge() << endl;
            cout << "Salary: " << deletedEmployees[employee].getSalary() << endl;
            cout << "ID: " << deletedEmployees[employee].getID() << endl;
            cout << "Password: " << deletedEmployees[employee].getPassword() << endl;
            cout << "------------------" << endl;
        }
    }
}

void TeamLeader::activity(vector<unique_ptr<Employee>> &employees, vector<Employee> &deletedEmployees, int &ID_count){
    int option = 0;

    while(true){ //pętla wykonuje się tak długo aż użytkownik poda numer większy niż 4
        cout << "Jaka czynnosc chcesz wykonac?" << endl;
        cout << "1 - Wyswietl swoje dane" << endl;
        cout << "2 - Dodac nowego pracownika" << endl;
        cout << "3 - Usunac pracownika" << endl;
        cout << "4 - Wyswietlic dane o wszystkich pracownikach w firmie" << endl;
        cout << "5 - Wyswietlic dane o pracownikach pracujacych w przeszlosci" << endl;
        cout << "6 - Wylogowac sie" << endl; 
        cout << "Wybierz opcje: ";

        while (!(cin >> option)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
        }
        cout << endl;

        switch (option){
        case 1:
            Employee::getEmployeeData(); //Wywołanie funkcji z klasy Employee 
            break;
        case 2:
            addEmployee(employees, ID_count);
            break;
        case 3:
            delEmployee(employees, deletedEmployees, passwords);
            break;
        case 4:
            getEmployeeData(employees);
            break;
        case 5:
            getDeletedEmployeesData(deletedEmployees); cout << endl;
            break;
        case 6:
            cout << "Nastapilo wylogowanie" << endl << endl;
            return;
        default:
            cout << "Wybrano nieprawidlowa opcje" << endl << endl;
            break;
        }
    }
}