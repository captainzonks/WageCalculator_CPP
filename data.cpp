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
