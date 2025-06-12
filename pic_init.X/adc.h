/*
 * File:   main.h
 * Author: weyth
 *
 * Created on 10 juin 2025, 11:31
 */

#ifndef ADC_H
#define ADC_H

#include <xc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _XTAL_FREQ 20e6 // 20MHz

#ifdef __cplusplus
}
#endif

/**
 * @brief Initializes the ADC module.
 *
 * This function configures the ADC module for operation, setting the
 * appropriate registers to enable the ADC and select the input channel.
 */
void ADC_Init(void);
/**
 * @brief Reads the ADC value from the specified channel.
 *
 * @param channel The ADC channel to read (0-4).
 * @param adcValue Pointer to store the ADC value.
 */
void ADC_read(uint8_t channel, uint16_t *adcValue);

extern volatile uint16_t adcValue; // ADC value read from the ADC module

#endif /* ADC_H */
