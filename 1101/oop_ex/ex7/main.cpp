#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Employee abstract base class.*/

class Employee {
public:
    Employee(const string &);
    void setName(const string &);
    string getName() const;
    virtual void print() const = 0;
    virtual double earning() const = 0;
private:
    string Name;
};

Employee::Employee(const string &name) : Name(name) {}

void Employee::setName(const string &name) {
    Name = name;
}

string Employee::getName() const {
    return Name;
}


void Employee::print() const {
    cout << getName();
}


/*SalariedEmployee class derived from Employee.*/

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(const string &, double = 0.0);
    void setWeeklySalary(double salary){ weeklySalary = salary; }
    double getWeeklySalary() const { return weeklySalary; }
    void print() const;
    double earning() const;
private:
    double weeklySalary;
};

/*CommissionEmployee class derived from Employee.*/

class CommissionEmployee : public Employee {
public:
    CommissionEmployee(const string &, double = 0.0, double = 0.0);
    void setGrossSales(double sales) { grossSales = sales; }
    double getGrossSales() const { return grossSales; }
    void setCommissionRate(double rate) { commissionRate = rate; }
    double getCommissionRate() const { return commissionRate; }
    void print() const;
    double earning() const;
private:
    double grossSales;
    double commissionRate;
};

/*BasePlusCommissionEmployee class derived from CommissionEmployee.*/

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
    BasePlusCommissionEmployee(const string &, double = 0.0, double = 0.0, double = 0.0);
    void setBaseSalary(double  salary) { baseSalary = salary; }
    double getBaseSalary() const { return baseSalary; }
    void print() const;
    double earning() const;
private:
    double baseSalary;
};

void virtualViaPointer(const Employee *const baseClassPtr) {
    baseClassPtr->print();
    cout << "earned $" << baseClassPtr->earning() << "\n\n";
}

int main() {
    string name1, name2, name3;
    double salary, sales, rate, basesales, baserate, basesalary;
    while (cin >> name1 >> salary >> name2 >> sales >> rate >> name3 >> basesales >> baserate >> basesalary){
        SalariedEmployee salariedEmployee(name1, salary);
        CommissionEmployee commissionEmployee(name2, sales, rate);
        BasePlusCommissionEmployee basePlusCommissionEmployee(name3, basesales, baserate, basesalary);
        vector<Employee *> employee(3);
        employee[0] = &salariedEmployee;
        employee[1] = &commissionEmployee;
        employee[2] = &basePlusCommissionEmployee;
        for (size_t i = 0; i < employee.size(); i++)
            virtualViaPointer(employee[i]);
    }
}

SalariedEmployee::SalariedEmployee(const string& name, double salary) : Employee(name) {
    setWeeklySalary(salary);
}

void SalariedEmployee::print() const {
    cout << "salaried employee: " << getName() << endl;
    cout << "weekly salary: " << getWeeklySalary() << endl;
}

double SalariedEmployee::earning() const {
    return getWeeklySalary();
}

CommissionEmployee::CommissionEmployee(const string& name, double sales, double rate) : Employee(name){
    setCommissionRate(rate);
    setGrossSales(sales);
}

void CommissionEmployee::print() const {
    cout << "commission employee: " << getName() << endl;
    cout << "gross sales: " << getGrossSales() << "; commission rate: " << getCommissionRate() << endl;
}

double CommissionEmployee::earning() const {
    return getGrossSales() * getCommissionRate();
}

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& name, double basesales, double baserate, double basesalary) : CommissionEmployee(name, basesales, baserate){
    setBaseSalary(basesalary);
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried commission employee: " << getName() << endl;
    cout << "gross sales: " << getGrossSales() << "; commission rate: " << getCommissionRate() << "; base salary: " << getBaseSalary() << endl;
}

double BasePlusCommissionEmployee::earning() const {
    return getBaseSalary() + (getCommissionRate() * getGrossSales());
}