#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>
//do unique_ptr
#include <memory>
//do generowania liczby losowej
#include <cstdlib>  // dla funkcji rand
#include <ctime>    // dla funkcji time
//do walidacji danych
#include <limits>

using namespace std;

class Employee{
    private:
        string type = "Employee";
        int ID;
        int age;
        int salary;
        string name;
        string password;

        //static oznacza, że zmienna jest taka sama dla każdego obiektu, trzeba dodać definicje w pliku .cpp!
    protected:
        static vector<string> passwords;
        bool isPasswordCorrect(vector<string> passwords, string &newPassword);

    public:
        Employee() = default; //konstruktor domyślny, ustawiony na default
        Employee(int &ID_count); //konsturktor przeciążony, prosi o wypełnienie danych pracownik

        //gettery
        int getID();
        int getAge();
        int getSalary();
        string getName();
        string getPassword();
        string getEmployeeType();

        //settery
        void setSalary(int newSalary);
        void setType(string newType);
        void setPassword(string newPassword);

        //wyświetla informacje o aktualnym pracowniku
        void getEmployeeData();
        void changeSalary();
        virtual void activity(vector<unique_ptr<Employee>> &employees);
};


class TeamLeader : public Employee{

    public:
        TeamLeader(int &ID_count); //konstruktor

        void getEmployeeData(vector<unique_ptr<Employee>> &employees);

        void addEmployee(vector<unique_ptr<Employee>> &employees, int &ID_count); //dodaje pracownika
        void delEmployee(vector<unique_ptr<Employee>> &employees, vector<Employee> &deletedEmployees, vector<string> &passwords); //usuwa pracownika z wektora employees
        //Nadpisana funkcja wirtualna z klasy Employees
        void getDeletedEmployeesData(vector<Employee> &deletedEmployees);

        void activity(vector<unique_ptr<Employee>> &employees, vector<Employee> &deltedEmployees, int &ID_count);
};

class FinancialEmployee : public Employee{

    public:
        FinancialEmployee() = default;
        FinancialEmployee(int &ID_count); //konstruktor

        void changeSalary(vector<unique_ptr<Employee>> &employees);
        void activity(vector<unique_ptr<Employee>> &employees) override;
};

class AdministrativeEmployee : public Employee{

    public:
        AdministrativeEmployee() = default;
        AdministrativeEmployee(int &ID_count);

        void changeEmployeeData(vector<unique_ptr<Employee>> &employees);
        void activity(vector<unique_ptr<Employee>> &employees) override;
};



//Klasa wirtualna
class DataBase{
    public:
        virtual void printData(vector<unique_ptr<Employee>> &employees, vector<int> printOptions) = 0;
        void whatToPrint(vector<int> &printOptions);
};

//Ta klasa nadpisuje funkcje z klasy wirtualnej
//wyświetla wszystkie informacje o pracownikach
class AllEmployeesData : public DataBase{
    public:
        void printData(vector<unique_ptr<Employee>> &employees, vector<int> printOptions) override;
};

//Ta klasa nadpisuje funkcję z klasy wirtualnej
//Wyświetla wszystkie informacje o pracownikach z danego stanowiska (Employee / Financial Employee / Administrative Employee)
class WorkplaceData : public DataBase{
    public:
        void printData(vector<unique_ptr<Employee>> &employees, vector<int> printOptions) override;
};



class Menu{
    public:
        void showMenu(vector<unique_ptr<Employee>> &employees, vector<Employee> deletedEmployees, int &ID_count);
};

#endif