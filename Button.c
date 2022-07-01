//
// Created by Patryk on 17.06.2022.
//

#include "button.h"
#include <stdio.h>

void button_constructor(Button* this, uint8_t GPInum, uint8_t GPOnum){
    this->GPInum = GPInum;
    this->GPOnum = GPOnum;
    this->input = false;
    this->LastBtnState = false;
    this->qButton = false;
    this->qTrig = false;
    this->qTrigMem = false;
    this->Time = 0;
    this->clicks = 0;

    this->getInput = getInput;
    this->toggle = toggle;

    bcm2835_gpio_fsel(this->GPInum, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(this->GPInum, BCM2835_GPIO_PUD_DOWN);

}

void getInput(Button* this, uint64_t Curr_time){
    this->input = bcm2835_gpio_lev(this->GPInum);
    if(this->input == this->LastBtnState){
        if(this->input == HIGH){
            if(this->Time + 50 < Curr_time){
                this->qButton = true;
            }
        }
        else this->qButton = false;
    }
    else{
        this->LastBtnState = this->input;
        this->Time = bcm2835_st_read() / 1000;
        this->clicks += 1;
    }

    if (this->qTrig == true) this->qTrig = false;

    if(this->qButton != this->qTrigMem){
        if(this->qButton == true){
            this->qTrig = true;
            printf("BUTTON CLICKS: %u, ", this->clicks);
            this->clicks = 0;
        }
        this->qTrigMem = this->qButton;
    }
}

void toggle(Button* this){
    if(this->qTrig) {
        if(bcm2835_gpio_lev(this->GPOnum) == LOW){
            bcm2835_gpio_write(this->GPOnum, HIGH);
        }
        else {
            bcm2835_gpio_write(this->GPOnum, LOW);
        }
        printf("value out state: %u, GPO number: %d, GPI number: %d\n",
               bcm2835_gpio_lev(this->GPOnum),
               this->GPOnum,
               this->GPInum);
    }
}
