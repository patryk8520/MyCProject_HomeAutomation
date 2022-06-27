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
    bool qOut;
    uint64_t Time;
    uint8_t clicks;
    void (*getInput)(struct sButton* self, uint64_t Curr_time);
    void (*toggle)(struct sButton* self);
} Button;

Button* button_constructor(Button* button, uint8_t GPInum, uint8_t GPOnum);

void getInput(Button* button, uint64_t Curr_time);
void toggle(Button* button);

#endif //MYCPROJECT_BUTTON_H
