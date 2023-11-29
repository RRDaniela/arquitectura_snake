#include "ripes_system.h"
#include "time.h"
#include "math.h"

#define SW0 (0x01)
#define SW1 (0x02)
#define SW2 (0x04)
#define SW3 (0x08)
#define true 1
#define false 0

typedef int bool;

// Define snake head and tail
volatile unsigned int *snake_head = LED_MATRIX_0_BASE;
volatile unsigned int *snake_tail = LED_MATRIX_0_BASE;
volatile unsigned int *test = LED_MATRIX_0_BASE;

volatile unsigned int *border = LED_MATRIX_0_BASE;
volatile unsigned int *border_2 = LED_MATRIX_0_BASE;
volatile unsigned int *border_3 = LED_MATRIX_0_BASE;
volatile unsigned int *border_4 = LED_MATRIX_0_BASE;
volatile unsigned int *food = LED_MATRIX_0_BASE;
volatile unsigned int *d_pad_up = D_PAD_0_UP;
volatile unsigned int *d_pad_do = D_PAD_0_DOWN;
volatile unsigned int *d_pad_le = D_PAD_0_LEFT;
volatile unsigned int *d_pad_ri = D_PAD_0_RIGHT;

#define SIZE (LED_MATRIX_0_WIDTH * LED_MATRIX_0_HEIGHT)

void main() {
    unsigned int mask = 0;
    int a;
    // Position where the food will appear
    int nFoodX = 15;
    int nFoodY = 10;
    int index = nFoodY * LED_MATRIX_0_WIDTH + nFoodX;
    food += index;
    *food = 0x8fce00;
    // Border 2
    border_2 += 840;

    // Initial snake length
    int snake_length = 4;

    // Initial snake direction
    int direction = 0;

    // Initial position of snake head
    snake_head += 437;
    test += 437;

    // Border 4
    border_4 += 34;

    // Boolean to check if the snake has died
    bool isDead = false;

    // Draw borders
    for (int i = 0; i < 35; i++) {
        *border = 0xc800ce;
        *border_2 = 0xc800ce;
        border = border + 1;
        border_2 = border_2 + 1;
    }

    // Draw borders
    for (int i = 0; i < 25; i++) {
        *border_3 = 0xc800ce;
        *border_4 = 0xc800ce;
        border_3 = border_3 + 35;
        border_4 = border_4 + 35;
    }

    int snake_segments[875]; // Store snake directions

    for (int i = 0; i < snake_length; ++i) {
        snake_segments[i] = (int)(snake_head - i);
        *(snake_head - i) = 0x00e8ff; // Draw the snake initially
    }

    snake_tail = snake_segments[snake_length - 1];

    // Move the snake to the right initially
    bool gameStarted = false; // Flag to indicate if the game has started

    while (1 && !isDead) {
        for (int i = 0; i < 10000; i++) {
            a = i;
        }
        
        //Actualizar la dirección
    if (*d_pad_up == 1 && direction != 1) {
            direction = 0; // Move up
    } else if (*d_pad_do == 1 && direction != 0) {
            direction = 1; // Move down
    } else if (*d_pad_le == 1 && direction != 3) {
        direction = 2; // Move left
    } else if (*d_pad_ri == 1 && direction != 2) {
        direction = 3; // Move right
    }

    
if (direction == 0  && *(snake_head - LED_MATRIX_0_WIDTH) != 0xc800ce && *(snake_head - LED_MATRIX_0_WIDTH) != 0x00e8ff)  {
    *snake_tail = 0x000000; // Borra la cola anterior


    // Actualizar las posiciones en snake_segments para simular el movimiento
    for (int i = snake_length - 1; i > 0; i--) {
        snake_segments[i] = snake_segments[i - 1]; // Mover cada segmento hacia adelante
    }

    // Mover la cabeza hacia arriba
    snake_head -= LED_MATRIX_0_WIDTH;
    if(*snake_head == 0x8fce00){
        snake_length+=1;
    }

    // Dibujar la nueva cabeza
    *snake_head = 0x00e8ff;
    snake_segments[0] = snake_head; // Actualizar la dirección de la cabeza en snake_segments
    snake_tail = snake_segments[snake_length - 1]; // Actualizar la cola
}
else if (direction == 1  && *(snake_head + LED_MATRIX_0_WIDTH) != 0xc800ce && *(snake_head + LED_MATRIX_0_WIDTH) != 0x00e8ff) {
    *snake_tail = 0x000000; // Borra la cola anterior


    // Actualizar las posiciones en snake_segments para simular el movimiento
    for (int i = snake_length - 1; i > 0; i--) {
        snake_segments[i] = snake_segments[i - 1]; // Mover cada segmento hacia adelante
    }

    // Mover la cabeza hacia arriba
    snake_head += LED_MATRIX_0_WIDTH;
    if(*snake_head == 0x8fce00){
        snake_length+=1;
    }

    // Dibujar la nueva cabeza
    *snake_head = 0x00e8ff;
    snake_segments[0] = snake_head; // Actualizar la dirección de la cabeza en snake_segments
    snake_tail = snake_segments[snake_length - 1]; // Actualizar la cola
}
else if (direction == 2  && *(snake_head - 1) != 0xc800ce && *(snake_head - 1) != 0x00e8ff) {
    *snake_tail = 0x000000; // Borra la cola anterior


    // Actualizar las posiciones en snake_segments para simular el movimiento
    for (int i = snake_length - 1; i > 0; i--) {
        snake_segments[i] = snake_segments[i - 1]; // Mover cada segmento hacia adelante
    }

    // Mover la cabeza hacia arriba
    snake_head -= 1;
    if(*snake_head == 0x8fce00){
        snake_length+=1;
    }

    // Dibujar la nueva cabeza
    *snake_head = 0x00e8ff;
    snake_segments[0] = snake_head; // Actualizar la dirección de la cabeza en snake_segments
    snake_tail = snake_segments[snake_length - 1]; // Actualizar la cola
}
else if (direction == 3  && *(snake_head + 1) != 0xc800ce && *(snake_head + 1) != 0x00e8ff) {
    *snake_tail = 0x000000; // Borra la cola anterior


    // Actualizar las posiciones en snake_segments para simular el movimiento
    for (int i = snake_length - 1; i > 0; i--) {
        snake_segments[i] = snake_segments[i - 1]; // Mover cada segmento hacia adelante
    }
    // Mover la cabeza hacia arriba
    snake_head +=1;

    // Dibujar la nueva cabeza
    *snake_head = 0x00e8ff;
    if(*snake_head == 0x8fce00){
        snake_length+=1;
    }
    snake_segments[0] = snake_head; // Actualizar la dirección de la cabeza en snake_segments
    snake_tail = snake_segments[snake_length - 1]; // Actualizar la cola
        }else{
            isDead=true;
        }
    }
}
