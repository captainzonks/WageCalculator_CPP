#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>

#include "data.h"

int main() {

    std::vector<data> our_data{};
    data new_data{};
    float wage{};
    bool exists{false};

    struct stat buffer{};
    if (stat("wage_data.csv", &buffer)) {
        std::cout << "Please enter your wage: ";
        std::cin >> wage;
        new_data.set_wage(wage);
    } else {
        exists = true;
    }

    std::fstream file("wage_data.csv", std::fstream::in | std::fstream::out | std::fstream::app);

    if (exists) {
        file >> new_data;
    }

    std::cout << "Please enter how many hours you worked today: ";
    float hours{};
    std::cin >> hours;
    new_data.add_hours(hours);
    new_data.set_today_hours(hours);

    std::cout << "Please enter your tips: ";
    float tips{};
    std::cin >> tips;
    new_data.add_tips(tips);
    new_data.set_today_tips(tips);

    file << new_data;

    std::cout << "\nTips Average: $" << new_data.get_average_tips();
    std::cout << "\nToday's Adjusted Hourly Rate: $" << new_data.get_today_average_wage();
    std::cout << "\nOverall Adjusted Hourly Rate: $" << new_data.get_overall_average_wage();

    file.close();

    return 0;
}
