//
// Created by Patryk on 17.06.2022.
//

#include "button.h"
#include <stdio.h>

void button_constructor(Button* button, uint8_t GPInum, uint8_t GPOnum){
    button->GPInum = GPInum;
    button->GPOnum = GPOnum;
    button->input = false;
    button->LastBtnState = false;
    button->qButton = false;
    button->qTrig = false;
    button->qTrigMem = false;
    button->Time = 0;
    button->clicks = 0;

    button->getInput = getInput;
    button->toggle = toggle;

    bcm2835_gpio_fsel(button->GPInum, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(button->GPInum, BCM2835_GPIO_PUD_DOWN);

}

void getInput(Button* button, uint64_t Curr_time){
    button->input = bcm2835_gpio_lev(button->GPInum);
    if(button->input == button->LastBtnState){
        if(button->input == HIGH){
            if(button->Time + 50 < Curr_time){
                button->qButton = true;
            }
        }
        else button->qButton = false;
    }
    else{
        button->LastBtnState = button->input;
        button->Time = bcm2835_st_read() / 1000;
        button->clicks += 1;
    }

    if (button->qTrig == true) button->qTrig = false;

    if(button->qButton != button->qTrigMem){
        if(button->qButton == true){
            button->qTrig = true;
            printf("BUTTON CLICKS: %u, ", button->clicks);
            button->clicks = 0;
        }
        button->qTrigMem = button->qButton;
    }
}

void toggle(Button* button){
    if(button->qTrig) {
        if(bcm2835_gpio_lev(button->GPOnum) == LOW){
            bcm2835_gpio_write(button->GPOnum, HIGH);
        }
        else {
            bcm2835_gpio_write(button->GPOnum, LOW);
        }
        printf("value out state: %u, GPO number: %d, GPI number: %d\n",
               bcm2835_gpio_lev(button->GPOnum),
               button->GPOnum,
               button->GPInum);
    }
}
