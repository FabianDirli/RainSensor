#include "RainSensor.h"
#include "mbed_wait_api.h"

/*******************************/
/*  Modulares LoRa Messsystem  */
/*  Rain sensor Library V1     */
/*  Author: Dirlinger Fabian   */
/*  Date:   14.01.2022         */
/*******************************/




/**************************************/
/*             RainSensor             */
/* Description: Constructor           */
/* Params: PinName pin     sensor pin */
/* Return:                            */
/**************************************/
RainSensor::RainSensor(PinName pin) : sensor(pin) {
    sensor.rise(callback(this, &RainSensor::_irq_drop));
    debounce.start();
}

/******************************************/
/*             _irq_drop()                */
/* Description: Interrupt Service Routine */
/* Params:                                */
/* Return:                                */
/******************************************/
void RainSensor::_irq_drop() {
    if(debounce.elapsed_time() > 200us) { //Schalterprellen abwarten
        if(timer.elapsed_time() > 0s) {     //Läuft der Timer schon?
            if(timer.elapsed_time() > 24h) {    //Ist bereits ein Tag vergangen?
                ammount = 0;         //Dann setze ammount auf 0
                timer.reset();          //end beginne erneut zu zählen                 
            } else {
                ammount += CAPACITY/SURFACE; //4ml Schaufeninhalt / 0,165m2 -> l/m2
            }
        } else {
            timer.start();
        }
        debounce.reset();
    }        
}

/**************************************************/
/*             get_ammount()                      */
/* Description: Getter method for ammount         */
/* Params:                                        */
/* Return: float ammount    rain ammount in L/m2  */
/**************************************************/
float RainSensor::get_ammount() {
    return ammount;
}