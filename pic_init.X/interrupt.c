#include "interrupt.h"
#include <xc.h>

extern volatile uint16_t adcValue;

volatile uint8_t pwm_counter = 0;

void __interrupt() interrupt_handler(void) {
    if (PIR1bits.TMR2IF) {
        PIR1bits.TMR2IF = 0;

        // Simple software PWM on RD5
        uint8_t duty = adcValue >> 2; // Scale 10-bit ADC to 8-bit

        if (pwm_counter < duty) {
            PORTDbits.RD4 = 1;
        } else {
            PORTDbits.RD4 = 0;
        }

        pwm_counter++;
        if (pwm_counter >= 255)
            pwm_counter = 0;
    }
}

void init_tim(void) {
    // Configure Timer2 for ~1kHz PWM frequency (adjust PR2 as needed)
    T2CON = 0x04; // Prescaler 1:1, Timer2 on
    PR2 = 255;    // Period register
    PIR1bits.TMR2IF = 0;
    PIE1bits.TMR2IE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
}
