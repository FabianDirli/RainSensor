#ifndef MBED_RAINSENSOR_H
#define MBED_RAINSENSOR_H

/*******************************/
/*  Modulares LoRa Messsystem  */
/*  Rain sensor Library V1     */
/*  Author: Dirlinger Fabian   */
/*  Date:   14.01.2022         */
/*******************************/


/*******************************/
/*          !!!!!!!!!!         */
/*        mbed_app.json:       */
/*          !!!!!!!!!!         */
/*******************************/
/*
"target_overrides": {
        "*": {
            "target.printf_lib": "minimal-printf-enable-floating-point"
        }
    }
*/

/* USE PULL UP/DOWN RESISTOR!  */

#include "InterruptIn.h"
#include "Timer.h"
#include "mbed.h"
#include "Callback.h"
#include <ctime>

/*
    Rain sensor dimensions: 11x15cm
    Rain sensor surface area: 0,165m2
    assumed capacity of shovel: 4ml
*/

#define CAPACITY 4E-3
#define SURFACE 0.165

 
class RainSensor {

    private:
       InterruptIn sensor;
       float ammount;
       Timer debounce;
       Timer timer;
       time_t time = 0; // time in microseconcs

    public:

        RainSensor(PinName pin);

        void _irq_drop();

        float get_ammount();

};
 
#endif