#ifndef __MOTORS_HPP
#define __MOTORS_HPP

class Motors {

    private:
        int AIN1 = 14; // Pin for left motor direction
        int AIN2 = 27; // Pin for left motor direction
        int BIN1 = 26; // Pin for right motor direction
        int BIN2 = 33; // Pin for right motor direction
        
        int PWMA = 25;  // Pin for left motor speed control
        int PWMB = 32;  // Pin for right motor speed control
        int STBY = 12;   // Pin for standby mode

        int currspeedL = 50;  // CurrPWMt speed of the left motor
        int currspeedR = 50; // CurrPWMt speed of the right motor

    public:
        Motors();
        void moveFroward(int pid);
        void slightLeft();
        void slightRight();
        void turnLeft();
        void turnRight();
        void stopMotors();
};

#endif // __MOTORS_HPP