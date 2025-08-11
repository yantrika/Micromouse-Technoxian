// what should this contain 
// it should loop while the bot is traversing 
//read senosors
//update maze map
//decide the next move accroding to the weights
//drive drive
//ha ha repeat
#include "encoder.hpp"
#include "sensors.hpp"
#include "motors.hpp"
#include "pid.hpp"
#include "navigation.hpp"
#include "maze.hpp"
#include "utils.hpp"


// making global objects to avoid iteration in setup or loop 

Encoder encoderLeft, encoderRight;// measuring the distance travelled by motors and for pid correction
Sensors sensors;//hehe again detect
Motors motors;//motors pwm
PIDController pid;//pidpid
Navigation navigation;//it takes the decision and bots orintation
Maze maze;//holds the maze 