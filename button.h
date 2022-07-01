//
// Created by Patryk on 17.06.2022.
//

#ifndef MYCPROJECT_BUTTON_H
#define MYCPROJECT_BUTTON_H
#include <stdint.h>
#include <stdbool.h>
#include <bcm2835.h>
#include "Definitions.h"

typedef struct sButton{
    uint8_t GPInum;
    uint8_t GPOnum;
    bool input;
    bool LastBtnState;
    bool qButton;
    bool qTrig, qTrigMem;
    uint64_t Time;
    uint8_t clicks;
    void (*getInput)(struct sButton*, uint64_t);
    void (*toggle)(struct sButton*);
} Button;


void button_constructor(Button*, uint8_t GPInum, uint8_t GPOnum);

void getInput(Button*, uint64_t Curr_time);
void toggle(Button*);

#endif //MYCPROJECT_BUTTON_H
