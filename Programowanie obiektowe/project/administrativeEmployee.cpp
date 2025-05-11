#include "classes.h"

AdministrativeEmployee::AdministrativeEmployee(int &ID_count) : Employee(ID_count){
    setSalary(6000);
    setType("Administrative Employee");
}

void AdministrativeEmployee::changeEmployeeData(vector<unique_ptr<Employee>> &employees){

    while(true){
        int ID;
        cout << "Podaj ID pracownika ktorego dane chcesz zmienic: ";
        while (!(cin >> ID)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
        }
        cout << endl;

        bool changed = false;
        for (int employee = 0; employee < employees.size(); employee++){
            if (ID == employees[employee]->getID()){
                cout << "Podaj informacje, ktore chcesz zmienic:" << endl;
                cout << "1 - Haslo\n" << "2 - Wybralem zle ID, chce dokonac ponownego wyboru\n" << "3 - Wstecz\n"; //-------------------------------------------------------------
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
                        string newPassword;
                        cout << "Podaj nowe haslo pracownika: ";
                        cin >> newPassword;
                        employees[employee]->setPassword(newPassword);
                        changed = true;
                        cout << "Haslo pracownika o ID = " << employees[employee]->getID() << " zostalo zmienione na '" << employees[employee]->getPassword() << "'" << endl << endl;
                        return;
                    }
                    case 2:
                        //dodane aby dalsza część kodu if(!changed) nie wykonała się
                        changed = true;
                        break;
                    default:
                        return;
                }
            }
        }
        if(!changed){ 
            cout << "Nie ma pracownika o takim ID\n";
            cout << "Czy chcesz wybrac innego pracownika ktorego dane chcesz zmienic?\n";
            cout << "1 - tak\n" << "2 - nie" << endl;
            int option;

            cout << "Wybierz opcje: ";
            while (!(cin >> option)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
            }
            cout << endl;
            
            if(option != 1){
               return; 
            }
        }
    }
}

void AdministrativeEmployee::activity(vector<unique_ptr<Employee>> &employees){
    
    while(true){
        cout << "Wybierz czynnosc:" << endl;
        cout << "1 - Wyswietl swoje dane" << endl;
        cout << "2 - Zmien dane pracownika" << endl;
        cout << "3 - Popros o podwyzke" << endl;
        cout << "4 - Wyloguj sie" << endl;
        int option;

        cout << "Wybierz opcje: ";
        while (!(cin >> option)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledne dane. Wprowadz ponownie opcje: ";
        }
        cout << endl;

        if(option == 1){
            getEmployeeData();
        }
        else if(option == 2){
            changeEmployeeData(employees);
        }
        else if(option == 3){
            changeSalary();
        }
        else if(option == 4){
            cout << "Nastapilo wylogowanie" << endl << endl;
            return;
        }
        else{
            cout << "Wybrano nieprawidlowa opcje" << endl << endl;
        }
    }
}