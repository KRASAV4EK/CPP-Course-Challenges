// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    for (int i = 0; i < 70; i++)
        std::cout << "=";
    std::cout << std::endl;

    std::cout << std::setw(50) << tours.title << std::endl;

    for (int i = 0; i < 70; i++)
        std::cout << "=";
    std::cout << std::endl;

    bool first_row;

    for (auto country : tours.countries) {
        std::cout << std::setw(10) << std::left << country.name;
        first_row = true;
        for(auto city : country.cities) {
            if (first_row) {
                std::cout << std::setw(20) << std::right << city.name;
                first_row = false;
            } else {
                std::cout << std::setw(30) << std::right << city.name;
            }
            std::cout << std::setw(20) << std::right << city.population;
            std::cout << std::setw(20) << std::right << city.cost << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}