#include "Definitions.h"
#include "dht11.h"

#define MAXTIMINGS	85

int dht11_dat[5] = { 0, 0, 0, 0, 0 };


void dht11_constructor(Dht11* this,char* name, uint8_t GPIOnum){
    this->name = name;
    this->GPIOnum = GPIOnum;

    this->readData = readData;
}

uint8_t readData(Dht11* this){
    uint8_t laststate	= HIGH;
    uint8_t counter;
    uint8_t j = 0, i;
    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
    bcm2835_gpio_fsel(this->GPIOnum, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(this->GPIOnum, LOW);
    bcm2835_delay(18);
    bcm2835_gpio_write(this->GPIOnum, HIGH);
    bcm2835_delayMicroseconds(40);
    bcm2835_gpio_fsel(this->GPIOnum, BCM2835_GPIO_FSEL_INPT);

    for ( i = 0; i < MAXTIMINGS; i++ ){
        counter = 0;
        while ( bcm2835_gpio_lev(this->GPIOnum) == laststate ){
            counter++;
            bcm2835_delayMicroseconds( 2 );
            if ( counter == 255 ) break;
        }
        laststate = bcm2835_gpio_lev(this->GPIOnum);
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
        this->data_ok = true;
    }
    else this->data_ok = false;
    if(this->data_ok == true){
        this->temperatura = (uint16_t)dht11_dat[2];
        this->wilgotnosc = (uint16_t)dht11_dat[0];
        printf("%s Temperature = %d C Humidity = %d%%  |   ",
               this->name,
               this->temperatura, this->wilgotnosc);
        return 0;
    }
    else{
        this->data_ok = false;
        return 1;
    }
}
