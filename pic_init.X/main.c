/*
 * File:   main.c
 * Author: weyth
 *
 * Created on 10 juin 2025, 11:31
 */

#include "main.h"

volatile uint16_t adcValue = 0;

int main(int argc, char **argv) {
    init();     // Initialize peripherals
    ADC_Init(); // Initialize ADC
    init_tim(); // Initialize Timer2 and enable interrupts

    while (1) {
        ADC_read(1, (uint16_t *)&adcValue); // Read ADC channel 1
        __delay_ms(10);                     // Small delay
    }

    return (EXIT_SUCCESS);
}

void init(void) {
    // Set RD5 as output for PWM
    TRISDbits.TRISD4 = 0;
    PORTDbits.RD4 = 0;
    TRISDbits.TRISD2 = 0;
    PORTDbits.RD2 = 1; // Initialize RD4 for PWM output

    // Optionally, configure other pins as needed
}
