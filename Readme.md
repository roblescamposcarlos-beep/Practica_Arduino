# Nombre del proyecto

Funcionamiento arduino/leds

## Descripción

Programa en Arduino UNO R4 WiFi que enciende y apaga 10 LEDs conectados
en una protoboard siguiendo una secuencia programada (efecto cascada),
demostrando el control de múltiples salidas digitales.

## Objetivos de aprendizaje

Programar y controlar múltiples salidas digitales en un Arduino UNO R4
WiFi, utilizando estructuras de control (bucles) para generar una
secuencia de encendido y apagado en cascada sobre 10 LEDs conectados a
una protoboard.

## Material utilizado

- Arduino UNO R4 WiFi
- Protoboard
- 10 LEDs
- 10 resistencias de 220 Ω
- Cables Dupont

## Diagrama del circuito

[Diagrama/diagrama_circuito_10leds.png](Diagrama/diagrama_circuito_10leds.png)

## Código

[Codigo/leds_secuencia.ino](Codigo/leds_secuencia.ino)

## Video del funcionamiento

[Video/demostracion_secuencia_leds.mp4](Video/demostracion_secuencia_leds.mp4)

[Ver video en YouTube](https://youtu.be/M-Ngqcof4YU)

## Evidencias de armado

[Resultados/circuito_armado.jpeg](Resultados/circuito_armado.jpeg)

## Terminal

[Terminal/compilacion_arduino_ide.png](Terminal/compilacion_arduino_ide.png) —
captura del Arduino IDE mostrando la compilación exitosa del sketch.

## Reporte

[Reporte/Reporte_Practica_Arduino.md](Reporte/Reporte_Practica_Arduino.md)

Incluye:

- Objetivos y material
- Descripción del código
- Resultados y observaciones
- Conclusiones

## Conclusiones

La práctica permitió reforzar el manejo de múltiples salidas digitales
en Arduino mediante arreglos y bucles, así como el diseño de
secuencias temporizadas con `delay()`. El resultado (parejas, cascada
de llenado, cascada de vaciado y parejas de regreso) demuestra el
control preciso del estado de cada LED de forma independiente.
