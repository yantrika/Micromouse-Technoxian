#include <Arduino.h>
#include "navigation.hpp"

Navigation::Navigation(Sensors* sensorPtr) {
    sensors = sensorPtr;
    // Initialize wall flags
    LW = 0;
    FW = 0;
    RW = 0;
}

Navigation::~Navigation() {
    // No dynamic memory to clean up
    // sensors pointer is managed externally
}

void Navigation::detectWalls() {
    // Update sensor readings first
    sensors->update_vals();
    
    // Detect walls based on threshold
    // Note: NewPing returns 0 if no echo (out of range), so we need to handle this
    LW = (sensors->left > 0 && sensors->left < WALL_THRESHOLD) ? 1 : 0;
    FW = (sensors->front > 0 && sensors->front < WALL_THRESHOLD) ? 1 : 0;
    RW = (sensors->right > 0 && sensors->right < WALL_THRESHOLD) ? 1 : 0;
}

void Navigation::printWallStatus() {
    Serial.print("Walls - Left: ");
    Serial.print(LW ? "BLOCKED" : "OPEN");
    Serial.print(" | Front: ");
    Serial.print(FW ? "BLOCKED" : "OPEN");
    Serial.print(" | Right: ");
    Serial.print(RW ? "BLOCKED" : "OPEN");
    Serial.print(" | Distances - L:");
    Serial.print(sensors->left);
    Serial.print("cm F:");
    Serial.print(sensors->front);
    Serial.print("cm R:");
    Serial.print(sensors->right);
    Serial.println("cm");
}