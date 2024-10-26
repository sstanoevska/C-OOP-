#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CommissionEmployee {
private:
    string firstName;
    string lastName;
    string ssn;
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee(const string& first, const string& last, const string& num, double sales, double rate)
        : firstName(first), lastName(last), ssn(num) {
        setGrossSales(sales);
        setCommissionRate(rate);
    }

    void setFirstName(const string& first) {
        firstName = first;
    }

    string getFirstName() const {
        return firstName;
    }

    void setLastName(const string& last) {
        lastName = last;
    }

    string getLastName() const {
        return lastName;
    }

    void setSSN(const string& num) {
        ssn = num;
    }

    string getSSN() const {
        return ssn;
    }

protected:
    void setGrossSales(double sales) {
        grossSales = (sales < 0.0) ? 0.0 : sales;
    }

    double getGrossSales() const {
        return grossSales;
    }

    void setCommissionRate(double rate) {
        commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
    }

    double getCommissionRate() const {
        return commissionRate;
    }

public:
    double earnings() const {
        return commissionRate * grossSales;
    }

    void print() const {
        cout << fixed << setprecision(2);
        cout << "Commission employee: " << firstName << " " << lastName
             << "\nSSN: " << ssn
             << "\nGross sales: " << grossSales
             << "\nCommission rate: " << commissionRate;
    }
};

class BasePlusCommissionEmployee : public CommissionEmployee {
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee(const string& first, const string& last, const string& num, double sales = 0.0, double rate = 0.0, double salary = 0.0)
        : CommissionEmployee(first, last, num, sales, rate), baseSalary(salary) {}

    void setBaseSalary(double salary) {
        baseSalary = (salary < 0.0) ? 0.0 : salary;
    }

    double getBaseSalary() const {
        return baseSalary;
    }

    double earnings() const override {
        return baseSalary + getCommissionRate() * getGrossSales();
    }

    void print() const override {
        cout << fixed << setprecision(2);
        cout << "Base-salaried commission employee:\n "
             << getFirstName() << " " << getLastName()
             << "\nSSN: " << getSSN()
             << "\nGross sales: " << getGrossSales()
             << "\nCommission rate: " << getCommissionRate()
             << "\nBase salary: " << baseSalary;
    }
};

int main() {
    BasePlusCommissionEmployee employee("John", "Doe", "123-45-6789", 5000.0, 0.1, 1000.0);
    employee.print();
    cout << "\nEarnings: " << employee.earnings() << endl;

    return 0;
}
