#include "Definitions.h"
#include "dht11.h"

#define MAXTIMINGS	85

int dht11_dat[5] = { 0, 0, 0, 0, 0 };


Dht11* dht11_constructor(Dht11* dht11,char* name, uint8_t GPIOnum){
    dht11->name = name;
    dht11->GPIOnum = GPIOnum;

    dht11->readData = readData;
}

uint8_t readData(Dht11* dht11){
    uint8_t laststate	= HIGH;
    uint8_t counter;
    uint8_t j = 0, i;
    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
    bcm2835_gpio_fsel(dht11->GPIOnum, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(dht11->GPIOnum, LOW);
    bcm2835_delay(18);
    bcm2835_gpio_write(dht11->GPIOnum, HIGH);
    bcm2835_delayMicroseconds(40);
    bcm2835_gpio_fsel(dht11->GPIOnum, BCM2835_GPIO_FSEL_INPT);

    for ( i = 0; i < MAXTIMINGS; i++ ){
        counter = 0;
        while ( bcm2835_gpio_lev(dht11->GPIOnum) == laststate ){
            counter++;
            bcm2835_delayMicroseconds( 2 );
            if ( counter == 255 ) break;
        }
        laststate = bcm2835_gpio_lev(dht11->GPIOnum);
        if ( counter == 255 ) break;
        if ( (i >= 4) && (i % 2 == 0) ){
            dht11_dat[j / 8] <<= 1;
            if ( counter > 16 )
                dht11_dat[j / 8] |= 1;
            j++;
        }
    }
    if ( (j >= 40) &&
         (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) ){
        dht11->data_ok = true;
    }
    else dht11->data_ok = false;
    if(dht11->data_ok == true){
        dht11->temperatura = (uint16_t)dht11_dat[2];
        dht11->wilgotnosc = (uint16_t)dht11_dat[0];
        printf("%s Temperature = %d C Humidity = %d%%  |   ",
               dht11->name,
               dht11->temperatura, dht11->wilgotnosc);
        return 0;
    }
    else{
        dht11->data_ok = false;
        return 1;
    }
}
