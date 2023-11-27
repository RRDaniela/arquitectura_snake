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

volatile unsigned int * snake = LED_MATRIX_0_BASE;
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
int nFoodX = 15;
int nFoodY = 10;
int index = nFoodY * LED_MATRIX_0_WIDTH + nFoodX;
food += index;
*food = 0x8fce00;
border_2 += 840;
snake+=30;
border_4 += 34;
bool isDead = false;
int snakeBody[875];
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
while(1)
{
for(int i = 0; i<10000; i++){
a = i;
}
// Verificar si la serpiente puede moverse hacia arriba y no toca el color indicado
if (*d_pad_up == 1 && *(snake - LED_MATRIX_0_WIDTH) != 0xc800ce) {
    snake -= LED_MATRIX_0_WIDTH;
}

// Verificar si la serpiente puede moverse hacia abajo y no toca el color indicado
if (*d_pad_do == 1 && *(snake + LED_MATRIX_0_WIDTH) != 0xc800ce) {
    snake += LED_MATRIX_0_WIDTH;
}

// Verificar si la serpiente puede moverse hacia la izquierda y no toca el color indicado
if (*d_pad_le == 1 && *(snake - 1) != 0xc800ce) {
    snake -= 1;
}

// Verificar si la serpiente puede moverse hacia la derecha y no toca el color indicado
if (*d_pad_ri == 1 && *(snake + 1) != 0xc800ce) {
    snake += 1;
}
*snake = 0x00e8ff;
}
}
