//
// GE/Telair T6606-5 Library
//
#include <SoftwareSerial.h>
#include "T6603.h"

T6603::T6603() {

}

T6603::~T6603() {
    if ( NULL != _serial ) {
        delete _serial;
        _serial = NULL;
    }
}

void T6603::begin(uint8_t rx, uint8_t tx) {
    _serial = new SoftwareSerial(rx, tx);
    _serial->begin(19200);
}

int T6603::get_co2(void) {
    _serial->overflow();
    _serial->write(FLAG);
    _serial->write(BRDCST);
    _serial->write(0x02);
    _serial->write(CMD_READ); 
    _serial->write(CO2_PPM);
    delay(50);

    for ( int attempts = 0; attempts < MAX_ATTEMPTS; attempts++ ) {
        byte reading[5]; 
        int bytesRead = 0;        
        
        while ( _serial->available() && bytesRead < 6) {
            reading[bytesRead] = _serial->read();
            bytesRead++;
            delay(10);
        }

        if ( reading[0] == 0xFF && reading[1] == 0xFA ) {
            int i = 0;
            i |= reading[3] & 0xFF;
            i <<= 8;
            i |= reading[4] & 0xFF;
            _lastReading = i;
            return (_lastReading); 
        }
    }
    
    return (_lastReading);
}

