#include "Arduino.h"
#include <SoftwareSerial.h>

#define MAX_ATTEMPTS 10

class T6603 {

 private:
    static const byte FLAG        = 0xFF;
    static const byte BRDCST      = 0xFE;
    static const byte CMD_READ    = 0x02;
    static const byte CMD_UPDATE  = 0x03;
    static const byte CMD_STATUS  = 0xB6;

    static const byte CO2_PPM      = 0x03;
    static const byte SERIL        = 0x01;
    static const byte ELEVATION    = 0x0F;   

    SoftwareSerial* _serial;
    int _lastReading;    
    
 public:
    T6603();  
    ~T6603();  
    void begin(uint8_t, uint8_t);
    int get_co2(void);
};


