#include "ripes_system.h"
#include "time.h"
#include "math.h"
#define SW0 (0x01)
#define SW1 (0x02)
#define SW2 (0x04)
#define SW3 (0x08)
#define true 1
#define false 0


typedef int bool; //Definir bool

//Definir cabeza y cola de la serpiente
volatile unsigned int * snake_head = LED_MATRIX_0_BASE;
volatile unsigned int * snake_tail = LED_MATRIX_0_BASE;

volatile unsigned int * border = LED_MATRIX_0_BASE;
volatile unsigned int * border_2 = LED_MATRIX_0_BASE;
volatile unsigned int * border_3 = LED_MATRIX_0_BASE;
volatile unsigned int * border_4 = LED_MATRIX_0_BASE;
volatile unsigned int * food = LED_MATRIX_0_BASE;
volatile unsigned int * d_pad_up = D_PAD_0_UP;
volatile unsigned int * d_pad_do = D_PAD_0_DOWN;
volatile unsigned int * d_pad_le = D_PAD_0_LEFT;
volatile unsigned int * d_pad_ri = D_PAD_0_RIGHT;

void main()
{
unsigned int mask = 0;
int a;
//Posición donde aparecerá la comida
int nFoodX = 15;
int nFoodY = 10;
int index = nFoodY * LED_MATRIX_0_WIDTH + nFoodX;
food += index;
*food = 0x8fce00;

//Borde 2
border_2 += 840;

//Longitud inicial de la serpiente
int snake_length= 4;

//Dirección inicial de la serpiente
int direction = 0;

//Posición inicial de la cabeza de la serpiente
snake_head+=437;

//Borde 4
border_4 += 34;

//Booleano para saber si ya murió la serpiente
bool isDead = false;

int snake_headBody[875];
//Pintar los bordes de arriba y abajo
for(int i = 0; i<35; i++){ 
    *border = 0xc800ce; 
    *border_2 = 0xc800ce; 
    border = border + 1;
    border_2 = border_2+1;
}

//Pintar los bordes de de los lados
for(int i=0; i<25; i++){
    *border_3 = 0xc800ce; 
    *border_4 = 0xc800ce;
    border_3 = border_3+35;
    border_4 = border_4+35;
}

while(1 && !isDead)
{
for(int i = 0; i<10000; i++){
a = i;
}
// Verificar y actualizar la dirección basada en la entrada del usuario
if (*d_pad_up == 1 && direction != 1) {
direction = 0; // Mover hacia arriba
} else if (*d_pad_do == 1 && direction != 0) {
direction = 1; // Mover hacia abajo
} else if (*d_pad_le == 1 && direction != 3) {
direction = 2; // Mover hacia la izquierda
} else if (*d_pad_ri == 1 && direction != 2) {
direction = 3; // Mover hacia la derecha
}

// Actualizar la posición de la cabeza de la serpiente según la dirección
if (direction == 0 && *(snake_head - LED_MATRIX_0_WIDTH) != 0xc800ce && *(snake_head - LED_MATRIX_0_WIDTH) != 0x00e8ff) {
snake_head -= LED_MATRIX_0_WIDTH;
} else if (direction == 1 && *(snake_head + LED_MATRIX_0_WIDTH) != 0xc800ce && *(snake_head + LED_MATRIX_0_WIDTH) != 0x00e8ff) {
snake_head += LED_MATRIX_0_WIDTH;
} else if (direction == 2 && *(snake_head - 1) != 0xc800ce && *(snake_head - 1) != 0x00e8ff) {
snake_head -= 1;
} else if (direction == 3 && *(snake_head + 1) != 0xc800ce && *(snake_head + 1) != 0x00e8ff) {
snake_head += 1;
}else{
    isDead = true; }

*snake_head = 0x00e8ff;
}
}

