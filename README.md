# 🚦 Semáforo com Raspberry Pi Pico W

Este projeto implementa um **sistema de semáforo** utilizando um **Raspberry Pi Pico W**. O código controla três LEDs (vermelho, amarelo e verde) que simulam o funcionamento de um semáforo, alternando entre os estados com um temporizador.

## 📌 Funcionalidades
- Alternância automática entre os LEDs para simular um semáforo.
- Configuração compatível com a **placa BitDogLab** (com opção de ajustes no código).
- Impressão dos estados no terminal serial.

## 🛠 Componentes necessários
- 1 × Raspberry Pi Pico W (ou BitDogLab)
- 1 × LED vermelho
- 1 × LED amarelo
- 1 × LED verde
- 3 × Resistores (330Ω)

## 📌 Esquema de ligação (GPIOs)

| LED      | Pino GPIO |
|----------|----------|
| Vermelho | 13       |
| Amarelo  | 12       |
| Verde    | 11       |

## 🚀 Como rodar na BitDogLab
Se estiver usando a BitDogLab, no código estará indicado o case que deve ser comentado e o case que deve ser descomentado para funcionar. Tudo isso é devido ao led RGB da placa, que para funcionar o amarelo, tem que ser acionado o verde e o vermelho juntos:

Esses são os Cases que devem ser alterados de acordo com onde vai ser executado o código(Simulador/VSCode e Placa BitDogLab).
```c
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
```

Depois disso, basta compilar e enviar o código para a placa.

## 🏁 Conclusão
Este projeto demonstra um sistema básico de semáforo utilizando Raspberry Pi Pico W e BitDogLab, podendo ser facilmente adaptado para outros fins, como controle de tráfego em miniaturas e aprendizado de eletrônica. 🚦🚗


