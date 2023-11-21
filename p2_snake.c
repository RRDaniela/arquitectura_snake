#include "ripes_system.h"
#include <stdio.h>
#include <stdlib.h>

#define SW0 (0x01)
#define SW1 (0x02)
#define SW2 (0x04)
#define SW3 (0x08)

struct node{
    int coords[2];
    struct node *next;
};	


void setCoords(struct node *n, int x, int y) {
    n->coords[0] = x;
    n->coords[1] = y;
};

volatile unsigned int * led_base = LED_MATRIX_0_BASE;
volatile unsigned int * d_pad_up = D_PAD_0_UP;
volatile unsigned int * d_pad_do = D_PAD_0_DOWN;
volatile unsigned int * d_pad_le = D_PAD_0_LEFT;
volatile unsigned int * d_pad_ri = D_PAD_0_RIGHT;

void main()
{
    
    //Initialize nodes
    struct node *head;
    struct node *body_1 = NULL;
    struct node *body_2 = NULL;
    struct node *body_3 = NULL;
    struct node *body_4 = NULL;	
    
    //Allocate memory
    body_1 = malloc(sizeof(struct node));
    body_2 = malloc(sizeof(struct node));
    body_3 = malloc(sizeof(struct node));
    body_4 = malloc(sizeof(struct node));
    
    //Assign body coordinates
    setCoords(body_1, 0, 3);
    setCoords(body_2, 0, 2);
    setCoords(body_3, 0, 1);
    setCoords(body_4, 0, 0);
	
    
    //Connecting nodes
    body_1->next = body_2;
    body_2->next = body_3;
    body_3->next = body_4;
    body_4->next = NULL;
    
    head = body_1;

    
unsigned int mask = 0;
int a;
int direction = 0;
while(1)
{
    for(int i = 0; i< 10000; i++){
        a = i;
    }
if(*d_pad_up == 1 || direction == 1){
    direction = 1;
    led_base -= LED_MATRIX_0_WIDTH;
}
if(*d_pad_do == 1 || direction == 2){
    direction = 2;
    led_base += LED_MATRIX_0_WIDTH;
}
if(*d_pad_le == 1 || direction == 3){
    direction = 3;
    led_base -= 1;
    }
if(*d_pad_ri == 1 || direction == 4){
    direction = 4;
    led_base += 1;
}
*led_base = 0xC70D0F;
}
}