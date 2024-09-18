class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        tm tm1 = {};
        tm tm2 = {};
        
        sscanf(date1.c_str(), "%4d-%2d-%2d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday);
        tm1.tm_year -= 1900;
        tm1.tm_mon -= 1; 
        
        sscanf(date2.c_str(), "%4d-%2d-%2d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday);
        tm2.tm_year -= 1900; 
        tm2.tm_mon -= 1;
        
        time_t time1 = mktime(&tm1);
        time_t time2 = mktime(&tm2);
        
        double sc = difftime(time1, time2);
        return abs(sc / (60 * 60 * 24)); 
    }
};