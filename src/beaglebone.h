
//#define FEATURE_GPIO_MEM 1

/** @file beaglebone
 *  @brief basic procedures the beaglebone/io library
 *  @mainpage Introduction
 *
 */
#ifndef _BEAGLEBONE_H
#define _BEAGLEBONE_H

#include "beaglegpio.h"
#include "beagledelay.h"

typedef struct {
	volatile unsigned long* rawAddr;
	unsigned int bitMask;
} GPIO;

#ifdef FEATURE_GPIO_MEM
  extern int setup_gpio_mem_map();
#endif

/** Least significant byte first
 *
 */
#define LSBFIRST 1

/** Most significant byte first
 *
 */
#define MSBFIRST 0

/** set a GPIO pin mode.
 *
 * set a GPIO pin into a particular mode.
 * @param pin the desired PIN
 * @param mode INPUT or OUTPUT
 *
 */
extern void pinMode(const PIN pin, unsigned mode);
extern void pinMode_OUTPUT_raw(const PIN pin, unsigned mode, GPIO* out);

/** write to a pin.
 *
 * write the value to the specified pin
 * @param pin the desired pin
 * @param value either HIGH or LOW
 */
extern void digitalWrite(const PIN pin, unsigned value);

/** write to a pin a HIGH then LOW value.
 *
 * write the values to the specified pin
 * @param pinNo the gpioNo of the disired pin
 */
extern void digitalLatch_raw(GPIO* );

/** write to a pin.
 *
 * write the value to the specified pin
 * @param pinNo the gpioNo of the disired pin
 * @param value either HIGH or LOW
 */
extern void digitalWrite_raw(GPIO* , unsigned value);

/** read from a pin.
 * 
 * read a value from the specific pin
 * @param pin the desired pin
 * @return the value 
 */
extern unsigned digitalRead(const PIN);
extern unsigned digitalRead_raw(GPIO *);

/** read from an analog pin.
 *
 * @param pin the number of the analog pin specified a 0..6
 * @return the read value
 */
extern unsigned analogRead(const unsigned pin);

/** push the value serially to the dataPin.
 * Writes the designated byte in value bitwise to the dataPin, using clockPin 
 * as clock.
 * The implementation is an exact copy of the algorithm found in bonescript.
 * @param dataPin the datapin
 * @param clockPin the clockpin
 * @param bitOrder one of LSBFIRST or MSBFIRST
 * @param value the value to write
 */
extern void shiftOut(const PIN dataPin, const PIN clockPin, const unsigned bitOrder, const unsigned value);

/**
 * Run a programm.
 * Executes the setup function once and loops over the loop function. The loop
 * will be executed as long as the function loop returns a non 0 value.
 * @param setup a pointer to a function returning void with no parameters
 * @param loop a pointer to a function returning an int. 
 */
extern void run(void (*setup)(void), int (*loop)(void));
#endif
