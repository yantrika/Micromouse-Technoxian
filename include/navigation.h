#ifndef __NAVIGATION_HPP
#define __NAVIGATION_HPP

#include <Arduino.h>
#include "sensors.hpp"

class Navigation {
    private:
        // Wall detection threshold in cm
        const float WALL_THRESHOLD = 6.0;
        
        // Pointer to sensors object
        Sensors* sensors;
        
    public:
        // Wall flags: 0 = open, 1 = blocked
        bool LW = 0;  // Left Wall
        bool FW = 0;  // Front Wall  
        bool RW = 0;  // Right Wall
        
        // Constructor and destructor
        Navigation(Sensors* sensorPtr);
        ~Navigation();
        
        // Exposed APIs
        void detectWalls();
        void printWallStatus();  // Optional: for debugging
};

#endif