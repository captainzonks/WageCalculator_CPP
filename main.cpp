#include <cmath>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <vector>

#include "data.h"

void ask_for_wage(data& in_data);
void print_pretty_data(data& in_data);

int main() {
    data today_data{};
    float wage{};
    bool exists{ false };

    struct stat buffer{};
    if (stat("wage_data", &buffer)) {
        ask_for_wage(today_data);
    } else {
        exists = true;
    }

    std::fstream file("wage_data", std::fstream::in | std::fstream::out | std::fstream::app);

    std::vector<data> data;
    if (exists) {
        while (!file.eof()) {
            file >> today_data;
            data.push_back(today_data);
        }
        data.pop_back();
    }

    file.close();

    file.open("wage_data", std::fstream::in | std::fstream::out | std::fstream::app);

    char change_wage{'n'};
    std::cout << "Would you like to change your wage from $" << today_data.get_wage() << "/hr? (Y or N) ";
    std::cin >> change_wage;
    if (std::tolower(change_wage) == 'y')
    {
        ask_for_wage(today_data);
    }

    std::cout << "Please enter how many hours you worked today: ";
    float hours{};
    std::cin >> hours;
    today_data.add_hours(hours);
    today_data.set_today_hours(hours);

    std::cout << "Please enter your tips: ";
    float tips{};
    std::cin >> tips;
    today_data.add_tips(tips);
    today_data.set_today_tips(tips);

    file << today_data;

    print_pretty_data(today_data);

    file.close();

    return 0;
}

void ask_for_wage(data& in_data) {
    float wage{};
    std::cout << "Please enter your wage: ";
    std::cin >> wage;
    in_data.set_wage(wage);
}

void print_pretty_data(data& in_data) {
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.precision(2);
    std::cout << "\nWage: $" << in_data.get_wage();
    std::cout << "\nTotal hours worked: " << in_data.get_total_hours();
    std::cout << "\nEarned today (before tax): $" << in_data.get_total_daily_earned();
    std::cout << "\nEarned today (after tax): $" << in_data.get_total_daily_earned_post_tax();
    std::cout << "\nTotal tips (rounded to nearest dollar): $" << std::round(in_data.get_total_tips());
    std::cout << "\nTips Average: $" << in_data.get_average_tips();
    std::cout << "\nToday's Adjusted Hourly Rate (before tax): $" << in_data.get_today_average_wage();
    std::cout << "\nToday's Adjusted Hourly Rate (after tax): $" << in_data.get_today_average_wage_post_tax();
    std::cout << "\nOverall Adjusted Hourly Rate (before tax): $" << in_data.get_overall_average_wage();
    std::cout << "\nOverall Adjusted Hourly Rate (after tax): $" << in_data.get_overall_average_wage_post_tax();
    std::cout << std::endl;
}