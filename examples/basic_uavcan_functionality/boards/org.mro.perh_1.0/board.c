#include <hal.h>

void boardInit(void) {
    // default AFIO mapping puts CAN RX/TX on PA11/PA12
    // Choose alternate function for these pins; USB is the default function
    palSetLineMode(BOARD_PAL_LINE_CAN_RX, PAL_MODE_INPUT);
    palSetLineMode(BOARD_PAL_LINE_CAN_TX, PAL_MODE_STM32_ALTERNATE_PUSHPULL);

#if HAL_USE_SERIAL
    static const SerialConfig uartCfg =
    {
      57600,
      0,
      USART_CR2_STOP1_BITS,
      0
    };

    /*
     * Activates the serial driver 1 using the driver default configuration.
     * PA9 and PA10 are routed to USART1.
     */
    sdStart(&SD1, &uartCfg);
#endif
}
