/*(Package Inheritance Hierarchy) Package delivery services, such as FedEx
DHL® n UPs®, offer several different delivery options, each associated with a specific price. Create an inheritance hierarchy to represent the different types of packages. Use the class
Package as the base class in the hierarchy, then include the TwoDayPackage and Overnight Package classes that inherit from Rackage.
The Package base class should include data members that represent the name, address, city, and zip code for both the sender and recipient of the package,
as well as data members that store the mass (in ounces) and price per ounce to send the package. The Rackage constructor should initialize those data members. Ensure that the price per ounce contains a positive value.
The Rackage class should provide a public member function calculateCost that returns a double that represents the cost of shipping the package.
The calculateCost function of Package should determine the cost by multiplying the mass by the cost per ounce. The TwoDayPackage derived class should inherit the functionality of the Package base class, but also include a data member
which is a fixed price that the delivery company charges for a two-day delivery service.
The TwoDayPackage constructor needs to get a value to initialize this data member.
In the TwoDay Package class, the calculateCost member function should be redefined to calculate the shipping cost by adding a fixed cost to the price
 based on the mass calculated by the caluclateCost function of the Package class.
 The OvernightPackage class should inherit directly from the Package class and contains an additional data member representing the additional price per ounce charged for the overnight shipping service.
 The OvernightPackage class should redefine the calculateCost member function so that it adds the additional cost per ounce to the default cost per ounce before calculating the shipping cost.
*/

#include <iostream>
#include <string>
#include <iomanip>

class Package {
private:
    std::string sender_name;
    std::string sender_address;
    std::string sender_city;
    int sender_postal_code;
    std::string receiver_name;
    std::string receiver_address;
    std::string receiver_city;
    int receiver_postal_code;
    double weight;
    double price;

public:
    Package(const std::string& s_name, const std::string& s_address, const std::string& s_city, int s_code,
            const std::string& r_name, const std::string& r_address, const std::string& r_city, int r_code,
            double mass, double price_per_ounce)
        : sender_name(s_name), sender_address(s_address), sender_city(s_city), sender_postal_code(s_code),
          receiver_name(r_name), receiver_address(r_address), receiver_city(r_city), receiver_postal_code(r_code),
          weight(mass), price(price_per_ounce) {

        if (price < 0.0) {
            this->price = 0.0;
        }
    }

    virtual ~Package() {}

    virtual double calculateCost() const { // Äîäàäåí virtual
        return weight * price;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double new_price) {
        if (new_price >= 0.0) {
            price = new_price;
        }
    }

    double getWeight() const {
        return weight;
    }
};

class TwoDayPackage : public Package {
private:
    double fixedPrice;

public:
    TwoDayPackage(const std::string& s_name, const std::string& s_address, const std::string& s_city, int s_code,
                  const std::string& r_name, const std::string& r_address, const std::string& r_city, int r_code,
                  double mass, double price_per_ounce, double fixed_price)
        : Package(s_name, s_address, s_city, s_code, r_name, r_address, r_city, r_code, mass, price_per_ounce),
          fixedPrice(fixed_price) {}

    double calculateCost() const override {
        return Package::calculateCost() + fixedPrice;
    }

    double getFixedPrice() const {
        return fixedPrice;
    }

    void setFixedPrice(double fee) {
        fixedPrice = fee;
    }
};

class OvernightPackage : public Package {
private:
    double additionalRate;

public:
    OvernightPackage(const std::string& s_name, const std::string& s_address, const std::string& s_city, int s_code,
                     const std::string& r_name, const std::string& r_address, const std::string& r_city, int r_code,
                     double mass, double price_per_ounce, double additional_rate)
        : Package(s_name, s_address, s_city, s_code, r_name, r_address, r_city, r_code, mass, price_per_ounce),
          additionalRate(additional_rate) {}

    double calculateCost() const override {
        return (getPrice() + additionalRate) * getWeight();
    }

    double getAdditionalRate() const {
        return additionalRate;
    }

    void setAdditionalRate(double service) {
        additionalRate = service;
    }
};

int main() {
    Package package("John Doe", "123 Main St", "City1", 12345, "Jane Doe", "456 Oak St", "City2", 67890, 5.0, 2.0);
    TwoDayPackage twoDayPackage("John Doe", "123 Main St", "City1", 12345, "Jane Doe", "456 Oak St", "City2", 67890, 5.0, 2.0, 5.0);
    OvernightPackage overnightPackage("John Doe", "123 Main St", "City1", 12345, "Jane Doe", "456 Oak St", "City2", 67890, 5.0, 2.0, 1.5);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Package cost: $" << package.calculateCost() << std::endl;
    std::cout << "TwoDayPackage cost: $" << twoDayPackage.calculateCost() << std::endl;
    std::cout << "OvernightPackage cost: $" << overnightPackage.calculateCost() << std::endl;

    return 0;
}

