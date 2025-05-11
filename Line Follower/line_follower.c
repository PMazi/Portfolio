#include <avr/io.h>
#define F_CPU 14745600UL

#include <util/delay.h>


#define sensor0 PC0
#define sensor1 PC1
#define sensor2 PC2
#define sensor3 PC3

#define MOTOR1_PLUS PD0
#define MOTOR1_MINUS PD1
#define MOTOR2_PLUS PD2
#define MOTOR2_MINUS PD3

int main(void)
{
    // Inicjalizacja
    DDRD |= (1<<MOTOR1_PLUS) | (1<<MOTOR1_MINUS) | (1<<MOTOR2_PLUS) | (1<<MOTOR2_MINUS);
    DDRC &= ~((1<<sensor0) | (1<<sensor1) | (1<<sensor2) | (1<<sensor3));
    PORTC |= (1<<sensor0) | (1<<sensor1) | (1<<sensor2) | (1<<sensor3);


    enum states{prosto,prawo,lewo};
    enum states state = prosto;


    while(1)
    {
        if(!(PINC & (1<<sensor1)) && !(PINC & (1<<sensor2)))
        {
            state = prosto;
        }
        else if((PINC & (1<<sensor1)))
        {
            state = lewo;
        }
        else if((PINC & (1<<sensor2)))
        {
            state = prawo;
        }


        switch(state)
        {
            case prosto: // prawy i lewy silnik do przodu
                PORTD |= (1<<MOTOR1_PLUS);
                PORTD &= ~(1<<MOTOR1_MINUS);
                PORTD |= (1<<MOTOR2_PLUS);
                PORTD &= ~(1<<MOTOR2_MINUS);
                break;
            case lewo: //skreca w lewo // prawy do przodu // lewy wylaczony
                PORTD |= (1<<MOTOR1_PLUS);
                PORTD &= ~(1<<MOTOR1_MINUS);
                PORTD &= ~(1<<MOTOR2_PLUS);
                PORTD &= ~(1<<MOTOR2_MINUS);
                break;
            case prawo: //skreca w prawo // prawy wylaczony // lewy do przodu
                PORTD &= ~(1<<MOTOR1_PLUS);
                PORTD &= ~(1<<MOTOR1_MINUS);
                PORTD |= (1<<MOTOR2_PLUS);
                PORTD &= ~(1<<MOTOR2_MINUS);
                break;
        }
    }
}