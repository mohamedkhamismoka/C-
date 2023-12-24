#include <stdint.h>
int i , h = 0 ;

void begin ( int budrate ) ;
int available(void) ;
uint8_t read () ;
void readBytes(char *buffer, int len) ;
void write (uint8_t  c )      ;
void writeBytes(const char *buffer, int len)  ;
void print (const char *str) ;
void println(const char *str) ;


void main() {

begin (11520) ;

}


void begin ( int budrate )  {
// 1. Enable the UART CLOCK and GPIO CLOCK
RCC_AHB1ENR   |= (1<<0) ;    //ENABLE PORT A CLOCK
RCC_APB1ENR   |= (1<<17) ;  //ENABLE UATR2 CLOCK

//2. Configure the UART PINS for Alternate Functions
GPIOA_MODER   |= ( (1<<5) | (1<<7) )  ;   //ALTERNATE FUNCTION TO PINS PA2 , PA3
GPIOA_OSPEEDR |= ( (1<<4) | (1<<5) | (1<<6) | (1<<7) ) ; // HIGH SPEED FOR PINS PA2, PA3
GPIOA_AFRL    |= ( (1<<8) | (1<<9) | (1<<10) | (1<<12) | (1<<13) | (1<<14) ) ;  // AF7 ALTERNATE FUNCTION FOR USART2 AT PINS PA2 , PA3

// 3. Enable the USART by writing the UE bit in USART_CRI register to 1.
USART2_CR1 |= (1<<13) ;        // ENABLE UART2

// 4. Program the M bit in USART_CRI to define the word length.
USART2_CR1 &=~ (1<<12) ;       // 8 BITS WORD LENGTH

// 5. Select the desired baud rate using the USART BRR register.
if ( BUDRATE ==11520)
{USART2_BRR |= (7<<0) | (244<<4) ;}      //BUD RATE OF 11520 , PCLK1 AT 45MHZ
else if (   BUDRATE == 9600)
{ USART2_BRR |= (15<<0) | (293<<4) ; }

// 6. Enable the Transmitter/Receiver by Setting the TE and RE bits in USART_CRI Register
USART2_CR1 |= ( (1<<2) | (1<<3) ) ;  // ENABLE OF TRANSMITTER AND RECEIVER
USART2_CR2 &= ~ ((1<<12) | (1<<13) );   // Configure for 1 stop bit (clear the STOP bits field)
USART2_CR1 &= ~ (1<<10) ; // Disable parity control
USART2_CR1 &= (1<<0) ;   // Set oversampling by 16 (default)

}


int available(void)
{return ( USART2_SR & (1<<5) );}  // Check the Receive Data Register Not Empty flag


char read ()
{
uint8_t TEMP ;
while (!available); // Wait for TC to SET.. This indicates that the data has been RECEIVED
TEMP = USART2_DR ;
return TEMP ;
}


void readBytes(char *buffer, int len) {
    for ( i ; i < len ; ++i)
     { buffer[i] = read();  }        // Read the received character and store it in the buffer
}


 void write (uint8_t  c )
{
USART2_DR = c ; // load the data into DR register
while (!(USART2_SR & (1<<6))); // Wait for TC to SET.. This indicates that the data has been transmitted
}


// Function to send a specified number of bytes via USART
void writeBytes(const char *buffer, int len) {
    for (h; h < len; ++h) {
        write(buffer[h]);
    }
}

// function to send a string via USART
void print (const char *str) {
     while (*str != '\0'){
        write(*str);
        str++;
 }
}

void println(const char *str) {
    while (*str != '\0') {
        write(*str);
        str++;
    }
 // Send null-terminator
    write('\0');
}





