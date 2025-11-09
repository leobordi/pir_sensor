#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_PIR_DATA 16
#define PIN_LED 15

int main()
{
    stdio_init_all();

    /**
     * Inizializza il pin a cui è collegato il sensore pir e lo setta come pin di input;
     * di default l'output del pir è high, quando rileva un movimento diventa low
     */
    gpio_init(PIN_PIR_DATA);
    gpio_set_dir(PIN_PIR_DATA, GPIO_IN);
    // Abilita la resistenza di pull up interna al pico
    //gpio_pull_up(PIN_PIR_DATA);


    /**
     * Inizializza il pin del led e lo setta come output;
     * il led si accenderà quando il sensore pir rileverà movimento
     */
    gpio_init(PIN_LED);
    gpio_set_dir(PIN_LED, GPIO_OUT);
    gpio_put(PIN_LED, 0);

    sleep_ms(1000);

    while (1) {
        int state = gpio_get(PIN_PIR_DATA);
        
        if (state == 1) {
            printf("Movement detected!\n");
            gpio_put(PIN_LED, 1);
        } else {
            printf("Waiting for movement ...\n");
            gpio_put(PIN_LED, 0);
        }
        sleep_ms(200);
    }

    return 0;
}
