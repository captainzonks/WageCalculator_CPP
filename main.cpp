#include <cmath>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include "data.h"

void ask_for_wage(data& in_data);

void ask_to_change_wage(data& in_data);

void ask_for_hours(data& in_data);

void ask_for_tips(data& in_data);

void print_pretty_data(data& in_data);


int main() {
    data today_data{};
    bool exists{ false };

    // Check if file exists, if not, ask to initialize wage
    struct stat buffer{};
    if (stat("wage_data", &buffer)) {
        ask_for_wage(today_data);
    } else {
        exists = true;
    }

    std::fstream file;

    file.open("wage_data", std::fstream::in | std::fstream::out | std::fstream::app);

    // Retrieve the most recent data from the file
    if (file) {
        if (exists) {
            while (!file.eof()) {
                file >> today_data;
            }
        }
    } else {
        std::cout << "Error opening file";
        file.close();
        return 1;
    }

    file.close();
    file.open("wage_data", std::fstream::in | std::fstream::out | std::fstream::app);

    if (file) {
        ask_to_change_wage(today_data);
        ask_for_hours(today_data);
        ask_for_tips(today_data);

        file << today_data;

        print_pretty_data(today_data);
    } else {
        std::cout << "Failed to open file";
        file.close();
        return 1;
    }

    file.close();

    return 0;
}

void ask_for_wage(data& in_data) {
    float wage{};
    std::cout << "Please enter your wage: ";
    std::cin >> wage;
    in_data.set_wage(wage);
}

void ask_to_change_wage(data& in_data) {
    char change_wage{ 'n' };
    std::cout << "Would you like to change your wage from $" << in_data.get_wage() << "/hr? (Y or N) ";
    std::cin >> change_wage;
    if (tolower(change_wage) == 'y') {
        ask_for_wage(in_data);
    }
}

void ask_for_hours(data& in_data) {
    std::cout << "Please enter how many hours you worked today: ";
    float hours{};
    std::cin >> hours;
    in_data.add_hours(hours);
    in_data.set_today_hours(hours);
}

void ask_for_tips(data& in_data) {
    std::cout << "Please enter your tips: ";
    float tips{};
    std::cin >> tips;
    in_data.add_tips(tips);
    in_data.set_today_tips(tips);
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
