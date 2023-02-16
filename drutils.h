//
//  drutils.h
//

#ifndef drutils_drutils_h
#define drutils_drutils_h

/***********************/
/* Constants           */
/***********************/
#define BOLD "\e[1m"
#define BLINK "\e[5m"
#define BLACK "\e[30m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define BRIGHTWHITE "\e[37m"
#define UNDERLINE "\e[4m"

#define OFF "\e[m"

/*********************/
/* enum Declarations */
/**********************/
enum eDays { SUN, MON, TUE, WED, THU, FRI, SAT };

/***********************/
/* struct Declarations */
/***********************/

/*************************/
/* function Declarations */
/*************************/
extern void   Bel(void);
extern float  CelsiusToFahrenheit(float tempC);
extern void   Delay(int numSeconds);
extern void   FlowerBox(const char* str);
extern float  FahrenheitToCelsius(float tempF);
extern void   IntToDayStr(int dayInt, char* dayStr);
extern int    IsLeapYear(int year);
extern int    MakeInt(char digitChar);
extern void   MakeLower(char * str);
extern void   MakeUpper(char * str);
extern char*  MakeStringInHeap(const char* str);
extern void   SetWD(const char* path);
extern void   SetWDHome(void);
extern void   SwapInt(int* a, int* b); 

#endif
