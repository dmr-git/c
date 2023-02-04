//
//  drutils.h
//

#ifndef drutils_drutils_h
#define drutils_drutils_h

/***********************/
/* Constants           */
/***********************/
#define COLOR_RED "\e[31m"
#define COLOR_OFF "\e[m"

/***********************/
/* Struct Declarations */
/***********************/

/*************************/
/* function Declarations */
/*************************/
extern void   Bel(void);
extern float  CelsiusToFahrenheit(float tempC);
extern void   Delay(int numSeconds);
extern void   FlowerBox(const char* str);
extern float  FahrenheitToCelsius(float tempF);
extern void   MakeLower(char * str);
extern void   MakeUpper(char * str);
extern char*  MakeStringInHeap(const char* str);
extern void   SetWD(const char* path);
extern void   SetWDHome(void);
extern void   SwapInt(int* a, int* b); 

#endif
