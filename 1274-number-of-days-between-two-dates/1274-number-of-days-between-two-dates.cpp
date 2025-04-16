class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int days1 = calculateDays(date1);
        int days2 = calculateDays(date2);
        return abs(days1 - days2);
    }
    
private:
    int calculateDays(const string& date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        int totalDays = 0;
        
        // Add days from all previous years
        for (int y = 1971; y < year; ++y) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }
        
        // Add days from all previous months in the current year
        for (int m = 1; m < month; ++m) {
            totalDays += daysInMonth(m, year);
        }
        
        // Add days in the current month
        totalDays += day;
        
        return totalDays;
    }
    
    bool isLeapYear(int year) {
        if (year % 4 != 0) {
            return false;
        } else if (year % 100 != 0) {
            return true;
        } else {
            return year % 400 == 0;
        }
    }
    
    int daysInMonth(int month, int year) {
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }
};