#include "adc.h"

void ADC_Init(void) {
    /**
     * @brief Configures the ADC module.
     *
     * ADCON1 Register:
     * - Bit 7: ADFM (A/D Result Format Select bit)
     *   - 1 = Right justified
     * - Bits 6-4: Unimplemented (Read as '0')
     * - Bits 3-0: PCFG<3:0> (A/D Port Configuration Control bits)
     *   - 0x0 = All pins are configured as analog inputs (AN0-AN7).

     * ADCON0 Register:
     * - Bit 7: ADCS1 (A/D Conversion Clock Select bit 1)
     *   - 0 = FOSC/8
     * - Bit 6: ADCS0 (A/D Conversion Clock Select bit 0)
     *   - 1 = FOSC/8
     * - Bit 5: CHS2 (A/D Channel Select bit 2)
     *   - 0 = Selects AN3 as the input channel
     * - Bit 4: CHS1 (A/D Channel Select bit 1)
     *   - 1 = Selects AN3 as the input channel
     * - Bit 3: CHS0 (A/D Channel Select bit 0)
     *   - 1 = Selects AN3 as the input channel
     * - Bit 2: GO/DONE (A/D Conversion Status bit)
     *   - 0 = A/D conversion is not in progress
     * - Bit 1: Unimplemented (Read as '0')
     * - Bit 0: ADON (A/D On bit)
     *   - 1 = A/D converter module is enabled
     */
    // Configure the ADC
    ADCON1 = 0x80; // Keep all pins as analog inputs
    ADCON0 = 0x99; // Enable the ADC module (ADON = 1), set FOSC/32 as the clock
                   // source, and select AN3 as the input channel
}

void ADC_read(uint8_t channel, uint16_t *adcValue) {
    // Select the ADC channel
    if (channel > 4) {
        // Invalid channel, return without reading
        *adcValue = 0;
        return;
    }
    ADCON0bits.CHS = channel; // Directly set the desired channel
    // Start the ADC conversion
    __delay_us(20); // Small delay to ensure the conversion is complete
    ADCON0bits.GO_nDONE = 1;

    // Wait for the conversion to complete
    while (ADCON0bits.GO_nDONE)
        ;
    // Read the ADC value
    if (ADCON0bits.GO_nDONE == 0) {
        // Conversion is done, read the result
        *adcValue = ((uint16_t)ADRESH << 8) | ADRESL;
    }
}
