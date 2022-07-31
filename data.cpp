//
// Created by barhamm on 7/30/22.
//

#include "data.h"

float data::get_average_hours() const {
    if (days_ != 0) {
        return total_hours_ / static_cast<float>(days_);
    }
    return 0;
}

float data::get_average_tips() const {
    if (days_ != 0) {
        return total_tips_ / static_cast<float>(days_);
    }
    return 0;
}

float data::get_today_average_wage() const {
    if (total_hours_ != 0) {
        return wage_ + (today_tips_ / today_hours_);
    }
    return 0;
}

float data::get_overall_average_wage() const {

    if (total_hours_ != 0) {
        return wage_ + (total_tips_ / total_hours_);
    }
    return 0;
}

float data::get_total_daily_earned() const {
    return wage_ * today_hours_ + today_tips_;
}

float data::get_overall_average_wage_post_tax() const {
    return get_overall_average_wage() - (get_overall_average_wage() * FEDERAL_TAX) -
           (get_overall_average_wage() * CO_STATE_TAX) - (get_overall_average_wage() * FICA_STATE_INS_TAX);
}

float data::get_total_daily_earned_post_tax() const {
    return get_total_daily_earned() - (get_total_daily_earned() * FEDERAL_TAX) -
           (get_total_daily_earned() * CO_STATE_TAX) - (get_total_daily_earned() * FICA_STATE_INS_TAX);
}

float data::get_today_average_wage_post_tax() const {
    return get_today_average_wage() - (get_today_average_wage() * FEDERAL_TAX) -
           (get_today_average_wage() * CO_STATE_TAX) - (get_today_average_wage() * FICA_STATE_INS_TAX);
}
