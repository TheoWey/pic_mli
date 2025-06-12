/*
 * File:   main.h
 * Author: weyth
 *
 * Created on 10 juin 2025, 11:31
 */

#ifndef INTERRUPT_H
#define INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

#define _XTAL_FREQ 20e6 // 20MHz

#ifdef __cplusplus
}
#endif
/**
 * @brief Initializes Timer2 for PWM generation.
 *
 * This function configures Timer2 to generate interrupts at a specific
 * frequency, allowing for PWM signal generation on the appropriate pins.
 */
void init_tim(void);

/**
 * @brief Interrupt service routine for handling Timer2 interrupts.
 *
 * This function is called when a Timer2 interrupt occurs. It handles
 * the PWM signal generation based on the ADC value.
 */
void __interrupt() interrupt_handler(void);

#endif /* INTERRUPT_H */
