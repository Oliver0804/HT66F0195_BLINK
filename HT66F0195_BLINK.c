#include "HT66F0195.h"  // Include the HT66F0195 header file

// Type definitions for variable types
typedef unsigned char u8;    // Type definition for an unsigned 8-bit integer
typedef char s8;             // Type definition for a signed 8-bit integer
typedef unsigned short u16;  // Type definition for an unsigned 16-bit integer
typedef short s16;           // Type definition for a signed 16-bit integer
typedef unsigned long u32;   // Type definition for an unsigned 32-bit integer
typedef long s32;            // Type definition for a signed 32-bit integer

void Delayms(u16 del);  // Declaration of the delay function

int main() {
    _wdtc = 0b10101111; // Disable watchdog timer

    // Initialize port, assuming LED is connected at PA7
    _pac7 = 0;  // Set PA7 to output mode
    _pa7 = 0;   // Ensure the initial state of PA7 is low

    while(1) {
        _pa7 = 1;  // Set PA7 to high level, turn on the LED
        Delayms(1000);  // Delay, for example 1000 milliseconds
        _pa7 = 0;  // Set PA7 to low level, turn off the LED
        Delayms(1000);  // Delay, for example 1000 milliseconds
    }

    return 0;
}

void Delayms(u16 del)
{   u16 i;
    for(i=0; i<del; i++) GCC_DELAY(2000);
}
