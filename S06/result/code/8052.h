#include <8052.H> 

#define _imkstr_(x)#x 

#define ROM_VECTOR(TIMER2, t2int_handler) asm("global_" _imkstr_(t2int_handler));asm("psect vectors, ovrld");asm("org 2bh");asm("ljmp_" _imkstr_(t2int_handler));asm("psect text"); //Эта часть программы вставляет переход по функции прерывания на адрес прерывания таймера

unsigned int cnt,i; //переменные счётчиков задержки
unsigned int tmpCnt; //переменная, определяющая текущее значение скважности
unsigned int incr; //инкремент длительности
const unsigned int minPWM = 83;//макс. и минимальные значения ШИМ
const unsigned int maxPWM = 166;
bank2 

interrupt void t2int_handler(void) //обработчик прерывания таймера TIMER2
{
	TF2 = 0; 
	cnt = tmpCnt; 
	P10 = 1; 
	while (cnt != 0)cnt--;
	P10 = 0; 	
}

void main() 
{
	tmpCnt = 83; 
	incr = 1;
	ROM_VECTOR(TIMER2, t2int_handler); 
	P1 = 0xFE; 
	T2CON &= 0xFC;
	ET2 = 1; 
	EA = 1; 
	T2CON |= 0x4;
	RCAP2H = 0xB1; 
	RCAP2L = 0xE0; 
	TH2 = RCAP2H;
	TL2 = RCAP2L;
	while (1)
	{
		tmpCnt+=incr;
		if ((tmpCnt>maxPWM)||(tmpCnt<minPWM))
			incr=-incr;
		for (i=0;i!=0xFF;i++)
			asm("nop");
	}
}
