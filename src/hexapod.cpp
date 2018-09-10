 #include "Hexapod.h"

#include "util/Point.h"

#ifndef DEBUG
  #include <util/delay.h>
#else
  #include <iostream>
#endif

<<<<<<< HEAD
Hexapod::Hexapod()
: servocontroller1 { Servocontroller {0x40}}, servocontroller2 {Servocontroller {0x41}},
  legs {
    // Left (Front - Middle - Rear)
    Leg { Servo {servocontroller1,  0, 105, 465}, Servo {servocontroller1,  1,  95, 472}, Servo {servocontroller1,  2, 135, 510}, Pointf { 11.5f,  14.5f, 0.0f}, 8.5f,  62},
    Leg { Servo {servocontroller1,  5, 130, 400}, Servo {servocontroller1,  6, 100, 475}, Servo {servocontroller1,  7,  92, 445}, Pointf {  0.0f,  15.0f, 0.0f}, 6.5f,   0},
    Leg { Servo {servocontroller1, 13, 100, 450}, Servo {servocontroller1, 14, 132, 492}, Servo {servocontroller1, 15, 110, 475}, Pointf {-11.5f,  14.5f, 0.0f}, 8.5f, 298},
    // Right(Front - Middle - Rear)
    Leg { Servo {servocontroller2, 13, 130, 440}, Servo {servocontroller2, 14,  85, 455}, Servo {servocontroller2, 15,  85, 380}, Pointf { 11.5f, -14.5f, 0.0f}, 8.5f, 118},
    Leg { Servo {servocontroller2,  5, 125, 415}, Servo {servocontroller2,  6,  90, 454}, Servo {servocontroller2,  7,  89, 445}, Pointf {  0.0f, -15.0f, 0.0f}, 6.5f, 180},
    Leg { Servo {servocontroller2,  0,  85, 445}, Servo {servocontroller2,  1, 130, 430}, Servo {servocontroller2,  2,  85, 389}, Pointf {-11.5f, -14.5f, 0.0f}, 8.5f, 242}
=======
Hexapod::Hexapod(Servocontroller& servocontroller1, Servocontroller& servocontroller2)
: servocontroller1 {servocontroller1}, servocontroller2 {servocontroller2},
  legs {
    Leg { Servo { 0, 105, 465}, Servo { 1,  95, 472}, Servo { 2, 135, 510}, Pointf { 11.5f,  14.5f, 0.0f}, 8.5f,  62},
    Leg { Servo { 5, 130, 400}, Servo { 6, 100, 475}, Servo { 7,  92, 445}, Pointf {  0.0f,  15.0f, 0.0f}, 6.5f,   0},
    Leg { Servo {13, 100, 450}, Servo {14, 132, 492}, Servo {15, 110, 475}, Pointf {-11.5f,  14.5f, 0.0f}, 8.5f, 298},
    Leg { Servo { 0,  85, 445}, Servo { 1, 130, 430}, Servo { 2,  85, 389}, Pointf {-11.5f, -14.5f, 0.0f}, 8.5f, 242},
    Leg { Servo { 5, 125, 415}, Servo { 6,  90, 454}, Servo { 7,  89, 445}, Pointf {  0.0f, -15.0f, 0.0f}, 6.5f, 180},
    Leg { Servo {13, 130, 440}, Servo {14,  85, 455}, Servo {15,  85, 380}, Pointf { 11.5f, -14.5f, 0.0f}, 8.5f, 118}
>>>>>>> 788df7600ed8d2195db7387da2d44e901ce40c31
  } {
    //Initial Position
    /*
    moveLegDirectlyToPoint(LegPosition::FrontLeft,   Pointf {   8.0f,  12.0f, 0.0f }, 200);
    moveLegDirectlyToPoint(LegPosition::MiddleLeft,  Pointf {   0.0f,  14.0f, 0.0f }, 200);
    moveLegDirectlyToPoint(LegPosition::RearLeft,    Pointf { -10.0f,  12.0f, 0.0f }, 200);
    */

    //moveLegDirectlyToPoint(LegPosition::FrontRight,  Pointf {   8.0f, -12.0f, 0.0f }, 0, 200);

    /*
    moveLegDirectlyToPoint(LegPosition::MiddleRight, Pointf {   0.0f, -14.0f, 0.0f }, 200);
    moveLegDirectlyToPoint(LegPosition::RearRight,   Pointf { -10.0f, -12.0f, 0.0f }, 200);
    */

    this->legs[static_cast<int>(LegPosition::FrontRight)].setAngle(Joint::Tibia, 30);
    this->legs[static_cast<int>(LegPosition::FrontRight)].move(Joint::Tibia, 1000);

    /*
    Servo servo {servocontroller2, 15,  85, 380};
    servo.move();
    _delay_ms(1000);
    servo.setAngle(30);
    servo.move(1000);
    */
}

void Hexapod::update(uint32_t currentMillis) {
  for(uint8_t i = 0; i < 6; i++) {
    legs[i];
  }
}

void Hexapod::test() {
/*
  for(uint8_t i = 0; i < 20; i++) {
    moveLegToPoint(LegPosition::FrontLeft,   Pointf {  10.0f,  12.0f, 0.0f }, 200);
    moveLegToPoint(LegPosition::MiddleRight, Pointf {   2.0f, -14.0f, 0.0f }, 200);
    moveLegToPoint(LegPosition::RearLeft,    Pointf {  -8.0f,  12.0f, 0.0f }, 200);
    moveLegToPoint(LegPosition::FrontRight,  Pointf {  10.0f, -14.0f, 0.0f }, 200);
    moveLegToPoint(LegPosition::MiddleLeft,  Pointf {   2.0f,  12.0f, 0.0f }, 200);
    moveLegToPoint(LegPosition::RearRight,   Pointf {  -8.0f, -12.0f, 0.0f }, 200);

    moveLegDirectlyToPoint(LegPosition::FrontLeft,  Pointf {   8.0f, 12.0f, 0.0f }, 0);
    moveLegDirectlyToPoint(LegPosition::MiddleLeft, Pointf {   0.0f, 14.0f, 0.0f }, 0);
    moveLegDirectlyToPoint(LegPosition::RearLeft,   Pointf { -10.0f, 12.0f, 0.0f }, 0);

    moveLegDirectlyToPoint(LegPosition::FrontRight,  Pointf {   8.0f, -12.0f, 0.0f },   0);
    moveLegDirectlyToPoint(LegPosition::MiddleRight, Pointf {   0.0f, -14.0f, 0.0f },   0);
    moveLegDirectlyToPoint(LegPosition::RearRight,   Pointf { -10.0f, -12.0f, 0.0f }, 200);
  }*/
}

void Hexapod::moveLegDirectlyToPoint(LegPosition legPosition, const Pointf& destination, uint16_t time, uint16_t waitTime) {
  this->legs[static_cast<int>(legPosition)].setPosition(destination);
  this->legs[static_cast<int>(legPosition)].updateAngles();
  this->legs[static_cast<int>(legPosition)].moveAll(time);

  #ifndef DEBUG
  for(uint16_t i = 0; i < waitTime; i++) {
    _delay_ms(1);
  }
  #endif
}

void Hexapod::moveLegToPoint(LegPosition legPosition, const Pointf& destination, uint16_t time) {
  /*
  Pointf movementPath[STEPS+1];
  this->legs[static_cast<int>(legPosition)].calculateMovementTo(movementPath, destination);

  for(uint8_t i = 0; i < STEPS+1; i++) {
    moveLegDirectlyToPoint(servocontroller, legPosition, movementPath[i], 10);

    #ifdef DEBUG
      std::cout <<  movementPath[i] << std::endl;
    #endif
  }

  #ifdef DEBUG
    for(uint16_t i = 0; i < time; i++) {
      _delay_ms(1);
    }
  #endif
  */
}
