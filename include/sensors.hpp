#ifndef __SENSORS_HPP
#define __SENSORS_HPP

#include <Arduino.h>
#include <NewPing.h>

class Sensors{

    private:

        //To store the sensor pin config
        uint8_t TRIG_L = 18;
        uint8_t ECHO_L = 13; 
        uint8_t TRIG_F = 19;
        uint8_t ECHO_F = 35;
        uint8_t TRIG_R = 21;
        uint8_t ECHO_R = 34;
        uint8_t MAX_DISTANCE = 200;  // in cm

        //Pointers to store the newping stuffings
        NewPing* sonarLeft;
        NewPing* sonarFront;
        NewPing* sonarRight; 

         
    public:

        //To store sensor readings
        float left=0, right=0, front=0;

        //Constructor and destructor
        Sensors();
        ~Sensors();


        //Exposed APIs
        void update_vals();

};

#endif