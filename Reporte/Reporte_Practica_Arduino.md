# Reporte técnico — Funcionamiento Arduino/LEDs

## 1. Introducción

Esta práctica consiste en el control de 10 LEDs conectados a una placa
Arduino UNO R4 WiFi mediante una protoboard, con el objetivo de generar
una secuencia de encendido y apagado programada por software.

## 2. Objetivos de aprendizaje

Programar y controlar múltiples salidas digitales en un Arduino UNO R4
WiFi, utilizando estructuras de control (bucles) para generar una
secuencia de encendido y apagado en cascada sobre 10 LEDs conectados a
una protoboard.

## 3. Material utilizado

- Arduino UNO R4 WiFi
- Protoboard
- 10 LEDs
- 10 resistencias de 220 Ω
- Cables Dupont

## 4. Diagrama del circuito

Cada LED está conectado a un pin digital del Arduino (pines 2 al 11),
en serie con una resistencia de 220 Ω hacia la línea de tierra de la
protoboard. Ver diagrama completo en
[`Diagrama/diagrama_circuito_10leds.png`](../Diagrama/diagrama_circuito_10leds.png).

| LED | Pin Arduino |
|-----|-------------|
| 1   | 2  |
| 2   | 3  |
| 3   | 4  |
| 4   | 5  |
| 5   | 6  |
| 6   | 7  |
| 7   | 8  |
| 8   | 9  |
| 9   | 10 |
| 10  | 11 |

## 5. Descripción del código

El código (ver [`Codigo/leds_secuencia.ino`](../Codigo/leds_secuencia.ino))
define un arreglo con los 10 pines usados y ejecuta, en un ciclo
continuo, cuatro etapas:

1. **Parejas de ida** — enciende y apaga las parejas de LEDs en orden
   (1-2, 3-4, 5-6, 7-8, 9-10).
2. **Cascada que llena** — enciende los LEDs uno por uno, acumulándose
   hasta que los 10 quedan encendidos.
3. **Cascada que vacía** — los apaga uno por uno en orden inverso,
   empezando por el LED 10.
4. **Parejas de regreso** — repite el patrón de parejas en sentido
   contrario (9-10, 7-8, 5-6, 3-4, 1-2).

Los tiempos de la secuencia se controlan con tres constantes:
`VEL_PAREJAS` (250 ms), `VEL_CASCADA` (120 ms) y `PAUSA` (450 ms) entre
cada etapa.

## 6. Resultados

Al cargar el programa, los 10 LEDs ejecutan la secuencia descrita de
forma continua y visible, confirmando el control correcto de las
salidas digitales del Arduino. Evidencia en video:
[Practica Arduino R4 WiFi](https://youtu.be/M-Ngqcof4YU).

## 7. Observaciones

- El uso de un arreglo (`LEDS[]`) para los pines permitió recorrer los
  10 LEDs con bucles `for`, evitando repetir código para cada uno.
- Las resistencias de 220 Ω en serie con cada LED limitan la corriente
  y evitan dañar tanto los LEDs como los pines del Arduino.
- Separar la lógica en funciones (`parejas`, `cascadaLlenar`,
  `cascadaVaciar`, `apagarTodos`) facilitó construir la secuencia de
  cuatro partes sin duplicar lógica de encendido/apagado.

## 8. Conclusiones

La práctica permitió reforzar el manejo de múltiples salidas digitales
en Arduino mediante arreglos y bucles, así como el diseño de
secuencias temporizadas con `delay()`. El resultado (parejas, cascada
de llenado, cascada de vaciado y parejas de regreso) demuestra el
control preciso del estado de cada LED de forma independiente.
