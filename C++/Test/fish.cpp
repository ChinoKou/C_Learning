#include "fish.h"
bool FishNet (Date Fish) {
    Date isFish = {1900, 1, 1};
    int year = Fish.year - isFish.year;
    int month = Fish.month - isFish.month;
    int day = Fish.day - isFish.day;
    int count = year * 12 * 30 + month * 30 + day;
    if (count % 5 >= 0 && count % 5 <= 2) {
        return true;
    }
    else {
        return false;
    }
}