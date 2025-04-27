#include "classes.h"
//do utworzenia pliku i przekazania do niego danych
#include <fstream> 
//do poprawnego wczytywania typów danych (walidacja danych)
#include <limits>

//gettery
int Employee::getID(){ return ID; }
int Employee::getAge(){ return age; }
int Employee::getSalary(){ return salary; }
string Employee::getName(){ return name; }
string Employee::getPassword(){ return password; }
string Employee::getEmployeeType(){ return type; }

//settery
void Employee::setSalary(int newSalary){
    salary = newSalary;
}

void Employee::setType(string newType){
    type = newType;
}

void Employee::setPassword(string newPassword){
    password = newPassword;
}

//trzeba dodać definicje wektora!!!
vector<string> Employee::passwords;

bool Employee::isPasswordCorrect(vector<string> passwords, string &newPassword){
    //auto na podstawie elementów w wektorze passwords automatycznie dopasowuje typ zmiennej
    //password : passwords oznacza, że password będzie kolejnymi elementami z wektora passwords
    for(auto password : passwords){
        if(newPassword == password){
            cout << "Podane haslo juz istnieje!\n\n";
            return false;
        }
    }
    return true;
}

Employee::Employee(int &ID_count) : salary(5000), ID(ID_count) { //konstruktor klasy Employee, inicjalizacja salary oraz ID wraz z inkrementacją +1

    string inputString;
    //Ten if powoduje, że podczas dodawania nowego pracownika getline nie wczytuje znaku nowej linii
    if(ID_count > 0){ //ID_count = 0 -> true oznacza że dodawany jest conajmniej drugi nowy pracownik (pierwszy pracownik ma ID = 0, drugi ma ID = 1)
        cin.ignore(); 
    }

    if(ID_count == 0){
        cout << "Podaj swoje imie i nazwisko: ";
    }
    else{
    cout << "Podaj imie i nazwisko pracownika: ";
    }
    getline(cin, inputString);
    name = inputString;

    while(true){
        //dla teamLeadera
        if(ID_count == 0){
            cout << "Podaj swoj wiek: ";
        }
        //dla reszty pracowników
        else{
            cout << "Podaj wiek pracownika: ";
        }
        if(cin >> age){
            break;
        }
        else{
            //Wyczyszczenie błędów wejścia
            cin.clear(); 
            //Ignorowanie błędnych , numeric_limits<streamsize>::max() określa maksymalną liczbe znaków,
            //'\n' że strumień danych ma być ignorowany aż do napotkania snaku nowej linii
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Bledne dane. Wprowadz ponownie wiek." << endl;
        }
    }

    bool uniquePassword = false;
    while(!uniquePassword){
        if(ID_count == 0){
            cout << "Podaj swoje haslo: ";
        }
        else{
            cout << "Podaj haslo pracownika: ";
        }
        cin >> password; cout << endl;
        //funkcja sprawdza czy podane haslo ma już inny pracownik
        //gdy haslo jest unique zwraca true
        uniquePassword = isPasswordCorrect(passwords, password);
    }
    passwords.push_back(password);

    // Zapisywanie danych do pliku ()
    ofstream outputFile("employees.txt", ios::app); // ios::app oznacza tryb dodawania do istniejącego pliku
    if (outputFile.is_open()) {
        outputFile << "Name: " << name << ", ID: " << ID << ", Password: " << password << endl;
        outputFile.close();
    } else {
        cerr << "Błąd podczas otwierania pliku." << endl;
    }

    ID_count++;
}


//Wyświetlanie informacji o pracowniku
void Employee::getEmployeeData(){
    
    cout << "------------------" << endl;
    cout << ">>>>>  " << getName() << "  <<<<<" << endl;
    cout << "Workplace: " << getEmployeeType() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Salary: " << getSalary() << endl;
    cout << "ID: " << getID() << endl;
    cout << "Password: " << getPassword() << endl;
    cout << "------------------" << endl << endl;
}

void Employee::changeSalary(){
    double newSalary;
    cout << "Twoje obecne wynagrodzenie wynosi " << getSalary() << ". Zaproponuj nowe wynagrodzenie: ";
    while(!(cin >> newSalary)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledna opcje. Wprowadz dane ponownie: ";
        }
        cout << endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    //obliczanie prawdopodobieństwa od 0 do 100 zaakceptowania nowego wynagrodzenia
    //static_cast<double>(salary) wymusza zmiane typu zmiennej salary na double (salary miało wcześniej typ int)
    double propability = ((newSalary - static_cast<double>(salary)) / static_cast<double>(salary)) * 5 * 100;
    //losowanie liczby z zakresu 0 - 100
    double randomNumber = rand() % 100 + 1;

    if(randomNumber > propability){
        salary = newSalary;
        cout << "Prosba zostala zaakceptowana! Twoje nowe wynagrodzenie wynosi " << salary << endl << endl;
    }
    else{
        cout << "Twoja prosba zostala odrzucona" << endl << endl;
    }
}

void Employee::activity(vector<unique_ptr<Employee>> &employees){
    int option;

    while(true){
        cout << "Wybierz czynnosc: " << endl;
        cout << "1 - Wyswietl swoje dane\n" << "2 - Popros o podwyzke\n" << "3 - wyloguj sie\n";
        cout << "Wybierz opcje: ";

        while(!(cin >> option)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Podano bledna opcje. Wprowadz dane ponownie: ";
        }
        cout << endl;

        if (option == 1){
            getEmployeeData();
        }
        else if (option == 2){
            changeSalary();
        }
        else if (option == 3){
            cout << "Nastapilo wylogowanie" << endl << endl;
            break;
        }
        else{
            cout << "Wybrano nieprawidlowa opcje" << endl << endl;
        }
    } 
}