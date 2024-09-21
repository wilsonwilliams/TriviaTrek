#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

class ServoMotor {
    private:
        int feedbackPin;
        int controlPin;
    
    public:
        ServoMotor();    // Constructor
        void startMotor();      // speeds up motor to what our top speed is
        void stopMotor(int pos);       // stops motor to a determined position
};

#endif SERVOMOTOR_H
