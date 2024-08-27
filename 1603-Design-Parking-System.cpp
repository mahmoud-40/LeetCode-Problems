class ParkingSystem {
private:
    int bigSlots;
    int mediumSlots;
    int smallSlots;

public:
    ParkingSystem(int big, int medium, int small) {
        bigSlots = big;
        mediumSlots = medium;
        smallSlots = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1) { // Big car
            if (bigSlots) {
                bigSlots--;
                return true;
            }
        } else if (carType == 2) { // Medium car
            if (mediumSlots) {
                mediumSlots--;
                return true;
            }
        } else if (carType == 3) { // Small car
            if (smallSlots) {
                smallSlots--;
                return true;
            }
        }
        return false; 
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
