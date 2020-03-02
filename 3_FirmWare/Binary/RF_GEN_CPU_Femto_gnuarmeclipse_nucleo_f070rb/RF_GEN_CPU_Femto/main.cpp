#include "mbed.h"
#include "FastPWM.h"

//AD9834 DDS pinout
void spi_send_data(uint16_t data);

DigitalOut DDS_SLEEP(PB_0);
DigitalOut DDS_RESET(PB_1);
DigitalOut FSYNC(PB_2);
DigitalOut SCLK(PB_10);
DigitalOut SDATA(PB_11);

//Operation GPIO
DigitalOut PRE_AMP_ENA(PC_8);
DigitalOut PWR_ENA(PC_7);
DigitalOut PD2_GPIO_ON(PD_2);
DigitalOut BIAS_ON(PB_6);



//LED
DigitalOut COM_LED(PB_3);
DigitalOut WDT_LED(PB_4);
DigitalOut PLA_ON_LED(PB_9);

//Operation INPUT
DigitalIn JP_BIAS(PB_14);

int main() {
    
    //User status LED on
    COM_LED = 1;
    WDT_LED = 1;
    PLA_ON_LED = 1;


    spi_send_data(0x2100);
    spi_send_data(0x4E8A);//50C7
    spi_send_data(0x4B92);//4000
    spi_send_data(0xC000);
    spi_send_data(0x2000);

    FastPWM *PW_PWM = new FastPWM(PC_6);
    //COM_LED = 0;
    
    while(1) {
        COM_LED = !COM_LED;
        //WDT_LED = !WDT_LED;
        wait(1);
        
        if(JP_BIAS.read() == 0){

            //DDS 13.56MHz set
            SCLK = 1;
            SDATA = 0;
            FSYNC = 1;
    
            wait(0.1);

            spi_send_data(0x2100);
            spi_send_data(0x4E8A);//50C7
            spi_send_data(0x4B92);//4000
            spi_send_data(0xC000);
            spi_send_data(0x2000);
            PLA_ON_LED = 0; //PLA_LED_ON    

            //PWM duty set
            PW_PWM->period_us(20);
            PW_PWM->pulsewidth_us(10.0);        
            
            //GPIO SET
            PWR_ENA = 1;
            PRE_AMP_ENA = 1;
            PD2_GPIO_ON = 0;
            BIAS_ON = 1;
            
        }else{
            //Turn PWM OFF
            delete PW_PWM;
            FastPWM *PW_PWM = new FastPWM(PC_6);        
            
            spi_send_data(0x0040);  //DDS disable
            PLA_ON_LED = 1; //PLA_LED_OFF    
            
            //GPIO SET        
            PWR_ENA = 0;
            PRE_AMP_ENA = 0;
            PD2_GPIO_ON = 1;
            BIAS_ON = 0;
        }
    }
}

void spi_send_data(uint16_t data) {
 
    FSYNC = 0;
    data & 0x8000? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x4000? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x2000? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x1000? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0800? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0400? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0200? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0100? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0080? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0040? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0020? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0010? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0008? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0004? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0002? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    data & 0x0001? SDATA = 1 : SDATA = 0; SCLK = 0;wait_us(1); SCLK = 1;
    FSYNC = 1;
}
