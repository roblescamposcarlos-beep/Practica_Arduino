// ============================================================
//  DIEZ LEDS  ·  PAREJAS, CASCADA Y VUELTA  ·  Arduino UNO
//
//  La secuencia completa, en cuatro partes:
//    1) parejas de ida        1-2, 3-4, 5-6, 7-8, 9-10
//    2) cascada que llena     se van quedando prendidos hasta los 10
//    3) cascada que vacia     se apagan al reves, del 10 al 1
//    4) parejas de regreso    9-10, 7-8, 5-6, 3-4, 1-2
//
//  LED 1 -> pin 2   ...   LED 10 -> pin 11
// ============================================================

const int NUM_LEDS = 10;
const int LEDS[NUM_LEDS] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

// ---------- VELOCIDADES (milisegundos) ----------
const int VEL_PAREJAS = 250;   // cuanto dura encendida cada pareja
const int VEL_CASCADA = 120;   // cuanto tarda en sumarse cada LED
const int PAUSA       = 450;   // respiro entre una parte y la siguiente

// Aviso de las funciones que vienen mas abajo
void parejas(bool haciaLaDerecha);
void cascadaLlenar(bool haciaLaDerecha);
void cascadaVaciar(bool desdeLaDerecha);
void apagarTodos();


void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  apagarTodos();
}


void loop() {
  // ---------- IDA ----------
  parejas(true);            // 1-2, 3-4, 5-6, 7-8, 9-10
  delay(PAUSA);

  cascadaLlenar(true);      // se llena de izquierda a derecha
  delay(PAUSA);             // un momento con los 10 encendidos

  // ---------- VUELTA (todo al reves) ----------
  cascadaVaciar(true);      // se vacia empezando por el 10
  delay(PAUSA);

  parejas(false);           // 9-10, 7-8, 5-6, 3-4, 1-2
  delay(PAUSA);
}


// ============================================================
//  PARTE 1 y 4: las parejas
//  Se enciende una pareja, se apaga, y sigue la de junto.
//  Si quieres que se vayan acumulando en vez de correr,
//  borra (o comenta con //) las dos lineas marcadas abajo.
// ============================================================
void parejas(bool haciaLaDerecha) {
  apagarTodos();
  for (int p = 0; p < NUM_LEDS / 2; p++) {
    int pareja = haciaLaDerecha ? p : (NUM_LEDS / 2 - 1 - p);
    int primero = pareja * 2;

    digitalWrite(LEDS[primero],     HIGH);
    digitalWrite(LEDS[primero + 1], HIGH);
    delay(VEL_PAREJAS);

    digitalWrite(LEDS[primero],     LOW);   // <- borra esta linea
    digitalWrite(LEDS[primero + 1], LOW);   // <- y esta, para acumular
  }
  apagarTodos();
}


// ============================================================
//  PARTE 2: la cascada que llena
//  Cada LED se suma a los que ya estaban prendidos.
// ============================================================
void cascadaLlenar(bool haciaLaDerecha) {
  apagarTodos();
  for (int i = 0; i < NUM_LEDS; i++) {
    int cual = haciaLaDerecha ? i : (NUM_LEDS - 1 - i);
    digitalWrite(LEDS[cual], HIGH);
    delay(VEL_CASCADA);
  }
}


// ============================================================
//  PARTE 3: la cascada que vacia
//  Los apaga en orden contrario, hasta que no queda ninguno.
// ============================================================
void cascadaVaciar(bool desdeLaDerecha) {
  for (int i = 0; i < NUM_LEDS; i++) {
    int cual = desdeLaDerecha ? (NUM_LEDS - 1 - i) : i;
    digitalWrite(LEDS[cual], LOW);
    delay(VEL_CASCADA);
  }
}


void apagarTodos() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LEDS[i], LOW);
  }
}
