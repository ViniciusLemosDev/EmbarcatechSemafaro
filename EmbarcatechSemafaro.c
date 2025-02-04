#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_RED 13
#define LED_YELLOW 12
#define LED_GREEN 11

volatile int state = 0; // Estado do semáforo

bool repeating_timer_callback(struct repeating_timer *t)
{
    printf("Mudando estado do semáforo...\n");

    // Desliga todos os LEDs antes de acender o próximo
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_RED, 0);

    // Para rodar na placa BitDogLab comente esse switch
    //  Alterna os estados usando switch-case
    //  switch (state) {
    //      case 0:
    //          gpio_put(LED_RED, 1);
    //          printf("Vermelho ACESO\n");
    //          break;

    //     case 2:
    //         gpio_put(LED_GREEN, 1);
    //         printf("Verde ACESO\n");
    //         break;
    // }

    // Alterna os estados usando switch-case
    switch (state)
    {
    case 0:
        gpio_put(LED_RED, 1);
        printf("Verde ACESO\n");
        break;  
    // Para rodar na placa BitDogLab comente esse case 1
    case 1:
        gpio_put(LED_YELLOW, 1);
        printf("Amarelo ACESO\n");
        break;
    // Para rodar na placa BitDogLab descomente esse case 1
    // case 1:
    //     gpio_put(LED_RED, 1);
    //     gpio_put(LED_GREEN, 1);
    //     printf("Amarelo ACESO\n");
    //     break;
    case 2:
        gpio_put(LED_GREEN, 1);
        printf("Vermelho ACESO\n");
        break;
    }

    state = (state + 1) % 3; // Alterna entre 0, 1 e 2
    return true;
}

int main()
{
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0); // Garante que começa desligado

    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_put(LED_YELLOW, 0);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    // Liga o primeiro LED antes do loop principal
    gpio_put(LED_RED, 1);
    printf("Semáforo Iniciado - Vermelho ACESO\n");

    // Inicializa o temporizador
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true)
    {
        printf("Sistema rodando...\n");
        sleep_ms(1000); // Imprime mensagem a cada 1s
    }
}
