//
// Created by barhamm on 7/30/22.
//

#ifndef WAGE_CALCULATOR_DATA_H
#define WAGE_CALCULATOR_DATA_H

const float FEDERAL_TAX{0.153};
const float CO_STATE_TAX{0.0455};
const float FICA_STATE_INS_TAX{0.0765};

#include <iostream>

class data {
public:

    float get_average_hours() const;

    float get_average_tips() const;

    float get_today_average_wage() const;

    float get_today_average_wage_post_tax() const;

    float get_overall_average_wage() const;

    float get_overall_average_wage_post_tax() const;

    float get_total_daily_earned() const;

    float get_total_daily_earned_post_tax() const;


    friend std::ostream& operator<<(std::ostream& out, const data& obj) {
        out << obj.wage_
            << "\n"
            << obj.total_hours_
            << "\n"
            << obj.days_
            << "\n"
            << obj.total_tips_
            << "\n"
            << obj.today_hours_
            << "\n"
            << obj.today_tips_
            << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, data& obj) {
        in >> obj.wage_;
        in >> obj.total_hours_;
        in >> obj.days_;
        in >> obj.total_tips_;
        in >> obj.today_hours_;
        in >> obj.today_tips_;
        return in;
    }

    /// Setters ///
    void set_wage(float in_wage) { wage_ = in_wage; }

    void set_today_hours(float in_hours) { today_hours_ = in_hours; }

    void set_today_tips(float in_tips) { today_tips_ = in_tips; }

    void add_hours(float in_hours) {
        total_hours_ += in_hours;
        days_++;
    }

    void add_tips(float in_tips) { total_tips_ += in_tips; }

    /// Getters ///
    float get_wage() const { return wage_; }

    int get_days() const { return days_; }

    float get_total_hours() const { return total_hours_; }

    float get_total_tips() const { return total_tips_; }

    float get_today_hours() const { return today_hours_; }

    float get_today_tips() const { return today_tips_; }

private:
    float wage_{};
    int days_{};
    float total_hours_{};
    float total_tips_{};
    float today_hours_{};
    float today_tips_{};
};


#endif //WAGE_CALCULATOR_DATA_H
