#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int NumLen(long long int num);
int FromArrToInt(int arr[100], int index);
void TransformDecToOctal(char* arr, char* type, va_list argList);
char CheckHex(int temp, int flagHigh);
void TransformFromDecimalToHex(char* res, va_list argList, int flagHigh,
                               char* type);
void FormatParser(const char* format, va_list argList, char* str, int* pointer);
void spec_c(va_list argList, char** str, int* pointer, int flagMinus,
            int width);
int IsNum(char temp);
int IsFlag(char temp);
int GetWidth(const char* str, int pointer, int* isWidth, va_list argList);
void AddWidth(char** str, int width, int* pointer, char temp);
int GetFlags(char flags[100], const char* str, int pointer);
void FlagParser(const char* flags, int* flagMinus, int* flagPlus, int* flagZero,
                int* flagSpace, int* flagHash);
void NumToStrInt(char* str, long long num);
void FloatToStr(char* str, int accuracy, long double num);
void spec_d(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int flagZero, int flagSpace, int flagPlus, char* type,
            int accuracy);
void spec_f(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int accuracy, int flagZero, int flagSpace, int flagPlus, char* type,
            int flagHash, int hasDot);
void spec_s(va_list argList, char** str, int* pointer, int flagMinus,
            int width);
int CheckPercentage(const char* format, int pointer, int* counter);
void spec_u(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int flagZero, char* type, int accuracy);
void FlagWork(char** str, int* pointer, int flagMinus, int* width, int flagZero,
              int flagSpace, int flagPlus, int belowZero);
void WorkingWithString(char** str, int* pointer, int flagMinus, int width,
                       int flagZero, int flagPlus, int belowZero, char* strInt);
void ConnectingStrings(char** str, char* strInt, int* pointer);
void GetLength(const char* format, int* i, char* type, int* typeIndex);
void SpecParser(const char* format, int i, va_list argList, char* str,
                int* pointer, int flagMinus, int width, char* type,
                int typeIndex, int flagZero, int flagPlus, int flagSpace,
                int accuracy, int flagHash, int hasDot);
void GetAccuracy(const char* format, int* i, int* accuracy, int* isWIdth,
                 va_list argList, int* hasDot);
void ParcingWidth(int* width, const char* format, int* i, int* isWIdth,
                  va_list argList);
void FormatFlagWork(char* flags, const char* format, int* i, int* flagMinus,
                    int* flagPlus, int* flagZero, int* flagSpace,
                    int* flagHash);
void ZeroVariables(int* flagMinus, int* flagPlus, int* flagZero, int* flagSpace,
                   int* typeIndex, int* width, int* accuracy, int* isWIdth,
                   char* type, int* flagHash, int* hasDot, int* counter);
long long int LengthParserInt(char* type, va_list arglist);
void spec_xop(va_list argList, char** str, int* pointer, int flagMinus,
              int width, int flagZero, char* type, int flagHigh, int flagX,
              int flagO, int flagP, int flagHash, int accuracy, int flagPlus,
              int flagSpace);
void NumToStrUnsigned(char* type, char* str, va_list arglist);
unsigned long long int LengthParserUnsigned(char* type, va_list arglist);
void ConvertNumToStr(unsigned long long int num, char* str);
void GetAddress(va_list argList, char* str);
void RefactorShortStr(char* str, long double num, long long int dec,
                      int accuracy);
void FloatLengthParser(va_list argList, long double* num, char* type);
void ReverseStr(char* str);
void spec_e(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int accuracy, int flagZero, int flagSpace, int flagPlus,
            int flagHigh);
void spec_g(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int accuracy, int flagZero, int flagSpace, int flagPlus,
            int flagHigh, int flagHash);
void ShortestForm(char* str, long double num, int* belowZero, int flagHigh,
                  int accuracy, int flagHash);
void ScienceForm(char* str, int accuracy, long double num, int* belowZero,
                 int flagHigh);
#endif