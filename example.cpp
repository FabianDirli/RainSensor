/********************************************/
/*  Modulares LoRa Messsystem               */
/*  Rain sensor Library V1 example          */
/*  Author: Dirlinger Fabian                */
/*  Date:   14.01.2022                      */
/*  Description: Example application for    */
/*      rain sensor library. Prints rain    */
/*      ammount in L/m2 to console          */
/********************************************/

#include "mbed.h"
#include "RainSensor.h"
#include "mbed_wait_api.h"


int main() {

    RainSensor sensor(PB_1);
    while(1) {
        printf("Rain ammount: %f\n", sensor.get_ammount());
        wait_us(10E6); //wait for 10s
    }

}