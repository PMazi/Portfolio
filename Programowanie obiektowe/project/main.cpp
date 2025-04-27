#include "classes.h"

int main(){
    int ID_count = 0; //Pierwszy pracownik ma id 0, każdy kolejny o 1 większe
    
    vector<unique_ptr<Employee>> employees; //stworzenie wektora o nazwie employees, który przechowuje obiekty klasy Employee
    vector<Employee> deletedEmployees; //wektor przechowujący usuniętych pracowników
    cout << endl;
    employees.push_back(make_unique<TeamLeader>(ID_count));

    //dynamic_cast służy do dynamicznego rzutowania wskaźników w czasie działanie programu
    //składnia wygląda następująco: dynamic_cast<Typ na jaki chcemy rzutować>(wyrażenie jakie chcemy rzutować)
    //np. dynamic_cast<TeamLeader*>(employee[0]) wykonuje próbe rzutowania employee[0] na wskaźnik do typu TeamLeader (wskaźnik, bo jest zapis <TeamLeader*>)
    //Gdy employee[0] ma typ TeamLeader to dynamic cast zwraca wskaźnik na typ TeamLeader, natomiast gdy employee[0] ma typ np Employee to dynamic_cast zwraca nullptr
    dynamic_cast<TeamLeader*>(employees[0].get())->activity(employees, deletedEmployees, ID_count);

    Menu menu;

    menu.showMenu(employees, deletedEmployees, ID_count);

    //usuniecie pliku
    remove("employees.txt");
    return 0;
}