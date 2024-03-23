#include "s21_string.h"

void RefactorShortStr(char* str, long double num, long long int dec,
                      int accuracy) {
  int count = 0;
  while (str[s21_strlen(str) - 1] == '0') {
    count++;
    FloatToStr(str, accuracy - (NumLen(dec) + count), num);
  }
}

void ShortestForm(char* str, long double num, int* belowZero, int flagHigh,
                  int accuracy, int flagHash) {
  char strScience[512], strFloat[512];
  int tempAccuracy = 0, k = 0, y = 0;
  if (accuracy == -1)
    tempAccuracy = 6;
  else if (accuracy == 0)
    tempAccuracy = 0;
  else
    tempAccuracy = abs(accuracy);
  ScienceForm(strScience, tempAccuracy, num, belowZero, flagHigh);
  num = fabsl(num);
  long long int dec = (long long int)num;
  double ost = num - dec;
  if (accuracy > 0 && flagHash == 1) k = tempAccuracy - (NumLen(dec) + 1);
  if (k < 0) k = 0;
  if (dec > 0 && NumLen(dec) + 1 <= 6 && ost != 0) {
    FloatToStr(strFloat, tempAccuracy - (NumLen(dec) + 1), num);
    if (flagHash == 0) RefactorShortStr(strFloat, num, dec, tempAccuracy);
    if (tempAccuracy == 0)
      s21_strncat(str, strScience, s21_strlen(strScience));
    else
      s21_strncat(str, strFloat, s21_strlen(strFloat));
  } else if (num > 0 && num < 1) {  //&& zeros != 0
    FloatToStr(strFloat, tempAccuracy, num);
    if (flagHash == 0) RefactorShortStr(strFloat, num, dec, tempAccuracy);
    if (s21_strlen(strFloat) > s21_strlen(strScience))
      s21_strncat(str, strScience, s21_strlen(strScience));
    else
      s21_strncat(str, strFloat, s21_strlen(strFloat));
  } else if (NumLen(dec) + 1 <= 6 && ost == 0) {
    FloatToStr(strFloat, k, num);
    s21_strncat(str, strFloat, s21_strlen(strFloat));
  } else {
    if (tempAccuracy > 0) y = tempAccuracy - 1;
    ScienceForm(strScience, y, num, belowZero, flagHigh);
    FloatToStr(strFloat, tempAccuracy, num);
    if (s21_strlen(strFloat) > s21_strlen(strScience))
      s21_strncat(str, strScience, s21_strlen(strScience));
    else
      s21_strncat(str, strFloat, s21_strlen(strFloat));
  }
  if (NumLen(dec) + 1 == 6 && ost == 0 && flagHash == 1)
    s21_strncat(str, ".", 1);
  str[s21_strlen(str)] = '\0';
}

void ReverseStr(char* str) {
  char temp[s21_strlen(str) + 1];
  int k = 0;
  for (int i = s21_strlen(str) - 1; i >= 0; i--) {
    temp[k] = str[i];
    k++;
  }
  temp[k] = '\0';
  for (s21_size_t i = 0; i < s21_strlen(temp); i++) {
    str[i] = temp[i];
  }
}

void ScienceForm(char* str, int accuracy, long double num, int* belowZero,
                 int flagHigh) {
  int count = 0;
  char strEForm[3], strPow[128];
  char sign = 0, eChar = 0;
  if (flagHigh == 1)
    eChar = 'E';
  else
    eChar = 'e';
  if (num < 0) *belowZero = 1;
  num = fabsl(num);
  long long int numInt = (long long int)num;
  if (numInt > 10) {
    while (numInt > 10) {
      num /= 10;
      count++;
      numInt = (long long int)num;
    }
  } else if (num > 0 && num < 1) {
    while (numInt == 0) {
      num *= 10;
      count--;
      numInt = (long long int)num;
    }
  }
  if (count >= 0)
    sign = '+';
  else
    sign = '-';
  count = abs(count);
  strEForm[0] = eChar;
  strEForm[1] = sign;
  strEForm[2] = '\0';
  FloatToStr(str, accuracy, num);
  if (count < 10) {
    strPow[0] = '0';
    strPow[1] = count + 48;
    strPow[2] = '\0';
  } else
    ConvertNumToStr(count, strPow);
  s21_strncat(str, strEForm, s21_strlen(strEForm));
  s21_strncat(str, strPow, s21_strlen(strPow));
}

void GetAddress(va_list argList, char* str) {
  int k = 0;
  unsigned long long int address =
      (unsigned long long int)va_arg(argList, void*);
  if (address == 0)
    s21_memcpy(str, "(nil)\0", 6);
  else {
    int index = 0;
    char tempStr[100];
    while (address > 16) {
      int temp_ = address % 16;
      tempStr[index] = CheckHex(temp_, 0);
      index++;
      address /= 16;
    }
    tempStr[index] = CheckHex(address, 0);
    tempStr[index + 1] = '\0';
    for (int i = index; i >= 0; i--) {
      str[k] = tempStr[i];
      k++;
    }
    str[k] = '\0';
  }
}

void FlagParser(const char* flags, int* flagMinus, int* flagPlus, int* flagZero,
                int* flagSpace, int* flagHash) {
  int i = 0;
  while (flags[i] != '\0') {
    if (flags[i] == '-') *flagMinus = 1;
    if (flags[i] == '+') *flagPlus = 1;
    if (flags[i] == '0') *flagZero = 1;
    if (flags[i] == ' ') *flagSpace = 1;
    if (flags[i] == '#') *flagHash = 1;
    i++;
  }
}

void FlagWork(char** str, int* pointer, int flagMinus, int* width, int flagZero,
              int flagSpace, int flagPlus, int belowZero) {
  if (flagPlus == 1 && belowZero == 0) *width -= 1;
  if (belowZero == 1) *width -= 1;
  if (flagSpace == 1 && flagPlus == 0 && belowZero == 0) {
    (*str)[(*pointer)] = ' ';
    (*pointer)++;
    *width -= 1;
  }
  if (flagZero == 1 && flagMinus == 0) {
    if (flagPlus == 1 && belowZero == 0) {
      (*str)[(*pointer)] = '+';
      (*pointer)++;
    }
    if (belowZero == 1) {
      (*str)[(*pointer)] = '-';
      (*pointer)++;
    }
    AddWidth(str, *width, pointer, '0');
  }
}

void WorkingWithString(char** str, int* pointer, int flagMinus, int width,
                       int flagZero, int flagPlus, int belowZero,
                       char* strInt) {
  if (flagMinus == 1) {
    if (flagPlus == 1 && belowZero == 0) {
      (*str)[(*pointer)] = '+';
      (*pointer)++;
    }
    if (belowZero == 1) {
      (*str)[(*pointer)] = '-';
      (*pointer)++;
    }
    ConnectingStrings(str, strInt, pointer);
    AddWidth(str, width, pointer, ' ');
  } else {
    if (flagZero == 0) AddWidth(str, width, pointer, ' ');
    if (flagPlus == 1 && belowZero == 0 && flagZero == 0) {
      (*str)[(*pointer)] = '+';
      (*pointer)++;
    }
    if (belowZero == 1 && flagZero == 0) {
      (*str)[(*pointer)] = '-';
      (*pointer)++;
    }
    ConnectingStrings(str, strInt, pointer);
  }
}

void ConnectingStrings(char** str, char* strInt, int* pointer) {
  for (long unsigned int i = 0; i < s21_strlen(strInt); i++) {
    (*str)[(*pointer)] = strInt[i];
    (*pointer)++;
  }
  (*str)[(*pointer)] = '\0';
}

int CheckPercentage(const char* format, int pointer, int* counter) {
  int res = 1;
  while (format[pointer] != '%' && format[pointer] != '\0') {
    if (IsNum(format[pointer]) == 0 && IsFlag(format[pointer]) == 0) res = -1;
    pointer++;
    (*counter)++;
  }
  return res;
}

void ConvertNumToStr(unsigned long long int num, char* str) {
  int index = 0;
  s21_memcpy(str, "", 1);
  if (num == 0) {
    str[index] = 0 + 48;
    index++;
  }
  while (num > 0) {
    str[index] = num % 10 + 48;
    num /= 10;
    index++;
  }
  str[index] = '\0';
  ReverseStr(str);
}

long long int LengthParserInt(char* type, va_list arglist) {
  long long int num = 0;
  if (s21_strncmp(type, "d", 1) == 0 || s21_strncmp(type, "i", 1) == 0) {
    int tempNum = (int)va_arg(arglist, int);
    num = (long long int)tempNum;
  } else if (s21_strncmp(type, "ld", 2) == 0 ||
             s21_strncmp(type, "li", 2) == 0) {
    long int tempNum = (long int)va_arg(arglist, long int);
    num = (long long int)tempNum;
  } else if (s21_strncmp(type, "lld", 3) == 0 ||
             s21_strncmp(type, "lli", 3) == 0)
    num = (long long int)va_arg(arglist, long long int);
  else if (s21_strncmp(type, "hd", 2) == 0 || s21_strncmp(type, "hi", 2) == 0) {
    short tempNum = (short)va_arg(arglist, int);
    num = (long long int)tempNum;
  }
  return num;
}

unsigned long long int LengthParserUnsigned(char* type, va_list arglist) {
  unsigned long long int num = 0;
  if (s21_strncmp(type, "u", 1) == 0 || s21_strncmp(type, "x", 1) == 0 ||
      s21_strncmp(type, "X", 1) == 0 || s21_strncmp(type, "o", 1) == 0) {
    unsigned int tempNum = (unsigned int)va_arg(arglist, unsigned int);
    num = (long long int)tempNum;
  } else if (s21_strncmp(type, "hu", 2) == 0 ||
             s21_strncmp(type, "hx", 2) == 0 ||
             s21_strncmp(type, "hX", 2) == 0 ||
             s21_strncmp(type, "ho", 2) == 0) {
    unsigned short int tempNum =
        (unsigned short int)va_arg(arglist, unsigned int);
    num = (unsigned long long int)tempNum;
  } else if (s21_strncmp(type, "lu", 2) == 0 ||
             s21_strncmp(type, "lx", 2) == 0 ||
             s21_strncmp(type, "lX", 2) == 0 ||
             s21_strncmp(type, "lo", 2) == 0) {
    unsigned long int tempNum =
        (unsigned long int)va_arg(arglist, unsigned long int);
    num = (unsigned long long int)tempNum;
  } else if (s21_strncmp(type, "llu", 3) == 0 ||
             s21_strncmp(type, "llx", 3) == 0 ||
             s21_strncmp(type, "llX", 3) == 0 ||
             s21_strncmp(type, "llo", 3) == 0) {
    unsigned long long int tempNum =
        (unsigned long long int)va_arg(arglist, unsigned long long int);
    num = (long long int)tempNum;
  }
  return num;
}

void NumToStrInt(char* str, long long num) {
  ConvertNumToStr(num, str);
  str[s21_strlen(str)] = '\0';
}

void NumToStrUnsigned(char* type, char* str, va_list arglist) {
  unsigned long long int num = 0;
  int k = 0;
  char strInt[256];
  num = LengthParserUnsigned(type, arglist);
  ConvertNumToStr(num, strInt);
  ConnectingStrings(&str, strInt, &k);
  str[k] = '\0';
}

void FloatLengthParser(va_list argList, long double* num, char* type) {
  if (s21_strncmp(type, "f", -1) == 0) {
    double temp = va_arg(argList, double);
    *num = (long double)temp;
  }
  if (s21_strncmp(type, "lf", -1) == 0) {
    double temp = (double)va_arg(argList, double);
    *num = (long double)temp;
  }
  if (s21_strncmp(type, "Lf", -1) == 0)
    *num = (long double)va_arg(argList, long double);
}

void FloatToStr(char* str, int accuracy, long double num) {
  int k = 0;
  char strInt[512] = "\0";
  long long int first = (long long int)num;
  if (accuracy == -1) accuracy = 6;
  if (first < 0) first *= -1;
  num = fabsl(num);
  num -= first;
  double addOne = 1 * pow(10, -accuracy);
  long long int last = (long long int)fmod((num * pow(10, accuracy + 1)), 10);
  if (last >= 5) num += addOne;
  first += (int)num;
  ConvertNumToStr(first, strInt);
  ConnectingStrings(&str, strInt, &k);
  if (accuracy != 0) {
    str[k] = '.';
    k++;
    strInt[0] = '\0';
    accuracy = abs(accuracy);
    char* accuracyStr = (char*)malloc((accuracy + 1) * sizeof(char));
    if (accuracyStr) {
      int index = 0;
      for (int i = 0; i < accuracy; i++) {
        int tempAcNum = 0;
        long long int temp = num * 10;
        tempAcNum = temp % 10;
        accuracyStr[index] = (int)tempAcNum + 48;
        index++;
        num *= 10;
      }
      accuracyStr[accuracy] = '\0';
      ConnectingStrings(&str, accuracyStr, &k);
    }
    free(accuracyStr);
  }
  str[k] = '\0';
}

int IsFlag(char temp) {
  int res =
      (temp == '+' || temp == '-' || temp == ' ' || temp == '#' || temp == '0')
          ? 1
          : 0;
  return res;
}
int IsNum(char temp) {
  int res = ((int)temp >= 48 && (int)temp <= 57) ? 1 : 0;
  return res;
}

int GetWidth(const char* str, int pointer, int* isWidth, va_list argList) {
  int res = 0;
  if (str[pointer] == '*') {
    res = va_arg(argList, int);
  } else {
    int arr[100], k = 0;
    while (IsNum(str[pointer]) == 1) {
      arr[k] = (int)str[pointer] - 48;
      k++;
      pointer++;
    }
    for (int i = 0; i < k; i++) {
      res += arr[i] * pow(10, k - 1 - i);
    }
    if (k == 0) *isWidth = 0;
  }
  return res;
}

int GetFlags(char flags[100], const char* str, int pointer) {
  int k = 0;
  flags[0] = '\0';
  while (IsFlag(str[pointer]) == 1) {
    flags[k] = str[pointer];
    k++;
    pointer++;
  }
  flags[k] = '\0';
  return k;
}

void AddWidth(char** str, int width, int* pointer, char temp) {
  int k = (*pointer) + width - 1;
  while ((*pointer) < k) {
    (*str)[(*pointer)] = temp;
    (*pointer)++;
  }
}

int NumLen(long long int num) {
  int res = 0;
  if (num == 0) res = 1;
  while (num > 0) {
    res++;
    num /= 10;
  }
  return res - 1;
}

void TransformDecToOctal(char* arr, char* type, va_list argList) {
  int index = 0;
  unsigned long long int num = LengthParserUnsigned(type, argList);
  while (num >= 8) {
    arr[index] = (num % 8) + 48;
    index++;
    num /= 8;
  }
  arr[index] = num + 48;
  arr[index + 1] = '\0';
  ReverseStr(arr);
}

char CheckHex(int temp, int flagHigh) {
  char *alphabetLow = "abcdef", *alphabetHigh = "ABCDEF", res;
  if (temp >= 10 && flagHigh == 0)
    res = alphabetLow[temp - 10];
  else if (temp >= 10 && flagHigh == 1)
    res = alphabetHigh[temp - 10];
  else
    res = temp + 48;
  return res;
}

void TransformFromDecimalToHex(char* res, va_list argList, int flagHigh,
                               char* type) {
  unsigned long long int num = LengthParserUnsigned(type, argList);
  char temp_arr[256];
  int index = 0, k = 0;
  while (num >= 16) {
    int temp = num % 16;
    temp_arr[index] = CheckHex(temp, flagHigh);
    index++;
    num /= 16;
  }
  temp_arr[index] = CheckHex(num, flagHigh);
  temp_arr[index + 1] = '\0';
  for (int i = index; i >= 0; i--) {
    res[k] = temp_arr[i];
    k++;
  }
  res[k] = '\0';
}

void GetLength(const char* format, int* i, char* type, int* typeIndex) {
  if (format[(*i)] == 'l' || format[(*i)] == 'h') {
    type[(*typeIndex)] = format[(*i)];
    (*typeIndex)++;
    (*i)++;
    if (format[(*i)] == 'l') {
      type[(*typeIndex)] = format[(*i)];
      (*typeIndex)++;
      (*i)++;
    }
  }
}

void SpecParser(const char* format, int i, va_list argList, char* str,
                int* pointer, int flagMinus, int width, char* type,
                int typeIndex, int flagZero, int flagPlus, int flagSpace,
                int accuracy, int flagHash, int hasDot) {
  if (format[i] == 'c') spec_c(argList, &str, pointer, flagMinus, width);
  if (format[i] == 's') spec_s(argList, &str, pointer, flagMinus, width);
  if (format[i] == 'p')
    spec_xop(argList, &str, pointer, flagMinus, width, flagZero, type, 0, 0, 0,
             1, flagHash, accuracy, flagPlus, flagSpace);
  if (format[i] == 'd' || format[i] == 'i') {
    type[typeIndex] = format[i];
    type[typeIndex + 1] = '\0';
    spec_d(argList, &str, pointer, flagMinus, width, flagZero, flagSpace,
           flagPlus, type, accuracy);
  }
  if (format[i] == 'f') {
    type[typeIndex] = 'f';
    type[typeIndex + 1] = '\0';
    spec_f(argList, &str, pointer, flagMinus, width, accuracy, flagZero,
           flagSpace, flagPlus, type, flagHash, hasDot);
  }
  if (format[i] == 'u') {
    type[typeIndex] = 'u';
    type[typeIndex + 1] = '\0';
    spec_u(argList, &str, pointer, flagMinus, width, flagZero, type, accuracy);
  }
  if (format[i] == 'x') {
    type[typeIndex] = 'x';
    type[typeIndex + 1] = '\0';
    spec_xop(argList, &str, pointer, flagMinus, width, flagZero, type, 0, 1, 0,
             0, flagHash, accuracy, flagPlus, flagSpace);
  }
  if (format[i] == 'X') {
    type[typeIndex] = 'X';
    type[typeIndex + 1] = '\0';
    spec_xop(argList, &str, pointer, flagMinus, width, flagZero, type, 1, 1, 0,
             0, flagHash, accuracy, flagPlus, flagSpace);
  }
  if (format[i] == 'o') {
    type[typeIndex] = 'o';
    type[typeIndex + 1] = '\0';
    spec_xop(argList, &str, pointer, flagMinus, width, flagZero, type, 0, 0, 1,
             0, flagHash, accuracy, flagPlus, flagSpace);
  }
  if (format[i] == 'e')
    spec_e(argList, &str, pointer, flagMinus, width, accuracy, flagZero,
           flagSpace, flagPlus, 0);
  if (format[i] == 'E')
    spec_e(argList, &str, pointer, flagMinus, width, accuracy, flagZero,
           flagSpace, flagPlus, 1);
  if (format[i] == 'g')
    spec_g(argList, &str, pointer, flagMinus, width, accuracy, flagZero,
           flagSpace, flagPlus, 0, flagHash);
  if (format[i] == 'G')
    spec_g(argList, &str, pointer, flagMinus, width, accuracy, flagZero,
           flagSpace, flagPlus, 1, flagHash);
}

void GetAccuracy(const char* format, int* i, int* accuracy, int* isWIdth,
                 va_list argList, int* hasDot) {
  if (format[(*i)] == '.' && IsNum(format[(*i) + 1]) == 1) {
    *hasDot = 1;
    (*i)++;
    *accuracy = GetWidth(format, *i, isWIdth, argList);
    (*i) += NumLen(*accuracy) + 1;
  }
  if (format[(*i)] == '.' && IsNum(format[(*i) + 1]) == 0 &&
      (format[(*i) + 1]) != '*') {
    *hasDot = 1;
    *accuracy = 0;
    (*i)++;
  }
  if (format[(*i)] == '.' && (format[(*i) + 1]) == '*') {
    *hasDot = 1;

    *accuracy = va_arg(argList, int);
    (*i) += 2;
  }
}

void ParcingWidth(int* width, const char* format, int* i, int* isWIdth,
                  va_list argList) {
  *width = GetWidth(format, *i, isWIdth, argList);
  if (format[(*i)] == '*')
    (*i)++;
  else if (*isWIdth == 1)
    (*i) += NumLen(*width) + 1;
}

void FormatFlagWork(char* flags, const char* format, int* i, int* flagMinus,
                    int* flagPlus, int* flagZero, int* flagSpace,
                    int* flagHash) {
  int jump = GetFlags(flags, format, *i);
  FlagParser(flags, flagMinus, flagPlus, flagZero, flagSpace, flagHash);
  s21_strncpy(flags, "", 0);
  (*i) += jump;
}

void ZeroVariables(int* flagMinus, int* flagPlus, int* flagZero, int* flagSpace,
                   int* typeIndex, int* width, int* accuracy, int* isWIdth,
                   char* type, int* flagHash, int* hasDot, int* counter) {
  *flagMinus = 0;
  *hasDot = 0;
  *flagPlus = 0;
  *flagZero = 0;
  *flagSpace = 0;
  *typeIndex = 0;
  *width = 0;
  *accuracy = -1;
  *isWIdth = 1;
  *flagHash = 0;
  *counter = 0;
  type[0] = '\0';
}

void FormatParser(const char* format, va_list argList, char* str,
                  int* pointer) {
  int width = 0, i = 0, flagMinus = 0, flagPlus = 0, flagZero = 0,
      accuracy = -1, flagSpace = 0, typeIndex = 0, counter = 0, isWIdth = 1,
      flagHash = 0, hasDot = 0;
  char flags[100], type[100];
  while (format[i] != '\0') {
    if (format[i] == '%') {
      i++;
      if (CheckPercentage(format, i, &counter) == 1) {
        str[(*pointer)] = '%';
        (*pointer)++;
        i += counter;
      } else {
        FormatFlagWork(flags, format, &i, &flagMinus, &flagPlus, &flagZero,
                       &flagSpace, &flagHash);
        ParcingWidth(&width, format, &i, &isWIdth, argList);
        if (width < 0) flagMinus = 1;
        width = abs(width);
        GetAccuracy(format, &i, &accuracy, &isWIdth, argList, &hasDot);
        GetLength(format, &i, type, &typeIndex);
        SpecParser(format, i, argList, str, pointer, flagMinus, width, type,
                   typeIndex, flagZero, flagPlus, flagSpace, accuracy, flagHash,
                   hasDot);
      }
    } else {
      str[(*pointer)] = format[i];
      (*pointer)++;
    }
    i++;
    ZeroVariables(&flagMinus, &flagPlus, &flagZero, &flagSpace, &typeIndex,
                  &width, &accuracy, &isWIdth, type, &flagHash, &hasDot,
                  &counter);
  }
}

int s21_sprintf(char* str, const char* format, ...) {
  int pointer = 0;
  str[0] = '\0';
  if (format != NULL) {
    va_list argList;
    va_start(argList, format);
    FormatParser(format, argList, str, &pointer);
    str[pointer] = '\0';
    va_end(argList);
  } else
    pointer = -1;
  return pointer;
}

void spec_c(va_list argList, char** str, int* pointer, int flagMinus,
            int width) {
  char tempChar = va_arg(argList, int);
  if (flagMinus == 1) {
    (*str)[(*pointer)] = tempChar;
    (*pointer)++;
    AddWidth(str, width, pointer, ' ');
  } else {
    AddWidth(str, width, pointer, ' ');
    (*str)[(*pointer)] = tempChar;
    (*pointer)++;
  }
}

void spec_s(va_list argList, char** str, int* pointer, int flagMinus,
            int width) {
  char* tempStr = va_arg(argList, char*);
  width = width - s21_strlen(tempStr) + 1;
  if (flagMinus == 1) {
    ConnectingStrings(str, tempStr, pointer);
    AddWidth(str, width, pointer, ' ');
  } else {
    AddWidth(str, width, pointer, ' ');
    ConnectingStrings(str, tempStr, pointer);
  }
}

void spec_d(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int flagZero, int flagSpace, int flagPlus, char* type,
            int accuracy) {
  if (flagMinus == 1 && flagZero == 1) flagZero = 0;
  if (accuracy != -1) flagZero = 1;
  int belowZero = 0, track = 0;
  char strInt[512], strNorm[512];
  long long int num = 0;
  num = LengthParserInt(type, argList);
  belowZero = (num < 0) ? 1 : 0;
  if (num < 0) num *= -1;
  int widthZero = 0, index = 0;
  if (accuracy != 0 || num != 0) NumToStrInt(strInt, num);
  if (num == 0 && accuracy == 0) strInt[0] = '\0';
  if (flagPlus == 1 && belowZero == 0) {
    strNorm[track] = '+';
    track++;
    index++;
  }
  if (flagSpace == 1 && flagPlus == 0) {
    strNorm[track] = ' ';
    track++;
    index++;
  }
  if (belowZero == 1) {
    strNorm[track] = '-';
    track++;
    index++;
  }
  if (accuracy != -1) widthZero = accuracy - s21_strlen(strInt);
  if (flagZero == 1 && accuracy == -1) widthZero = width - s21_strlen(strInt);
  if (flagZero == 1) {
    int endO = index + widthZero;
    while (index < endO) {
      strNorm[index] = '0';
      index++;
    }
  }
  strNorm[index] = '\0';
  s21_strncat(strNorm, strInt, -1);
  strNorm[s21_strlen(strNorm)] = '\0';
  width = width - s21_strlen(strNorm) + 1;
  if (flagMinus == 1) {
    ConnectingStrings(str, strNorm, pointer);
    AddWidth(str, width, pointer, ' ');
  } else {
    AddWidth(str, width, pointer, ' ');
    ConnectingStrings(str, strNorm, pointer);
  }
}

void spec_f(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int accuracy, int flagZero, int flagSpace, int flagPlus, char* type,
            int flagHash, int hasDot) {
  int belowZero = 0;
  char strFloat[512] = "\0";
  long double num = 0;
  FloatLengthParser(argList, &num, type);
  belowZero = num < 0;
  FloatToStr(strFloat, accuracy, num);
  // printf("accuracy = %d\n", accuracy);
  if (accuracy == 0 && flagHash == 1 && hasDot == 1) {
    strFloat[s21_strlen(strFloat)] = '.';
  }
  width = width - s21_strlen(strFloat) + 1;
  FlagWork(str, pointer, flagMinus, &width, flagZero, flagSpace, flagPlus,
           belowZero);
  WorkingWithString(str, pointer, flagMinus, width, flagZero, flagPlus,
                    belowZero, strFloat);
}

void spec_u(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int flagZero, char* type, int accuracy) {
  char strInt[512], strNorm[512];
  if (flagMinus == 1 && flagZero == 1) flagZero = 0;
  int widthZero = 0, index = 0;
  NumToStrUnsigned(type, strInt, argList);
  if (accuracy != -1) widthZero = accuracy - s21_strlen(strInt);
  if (flagZero == 1 && accuracy == -1) widthZero = width - s21_strlen(strInt);
  if (flagZero == 1 || widthZero != 0) {
    int endO = index + widthZero;
    while (index < endO) {
      strNorm[index] = '0';
      index++;
    }
  }
  strNorm[index] = '\0';
  s21_strncat(strNorm, strInt, -1);
  strNorm[s21_strlen(strNorm)] = '\0';
  width = width - s21_strlen(strNorm) + 1;
  if (flagMinus == 1) {
    ConnectingStrings(str, strNorm, pointer);
    AddWidth(str, width, pointer, ' ');
  } else {
    AddWidth(str, width, pointer, ' ');
    ConnectingStrings(str, strNorm, pointer);
  }
  (*str)[(*pointer)] = '\0';
}

void spec_xop(va_list argList, char** str, int* pointer, int flagMinus,
              int width, int flagZero, char* type, int flagHigh, int flagX,
              int flagO, int flagP, int flagHash, int accuracy, int flagPlus,
              int flagSpace) {
  if (flagMinus == 1 && flagZero == 1) flagZero = 0;
  char strP[512], strNorm[512];
  strP[0] = '\0';
  strNorm[0] = '\0';
  int widthZero = 0, index = 0;
  if (flagX == 1 && flagHigh == 0)
    TransformFromDecimalToHex(strP, argList, 0, type);
  if (flagX == 1 && flagHigh == 1)
    TransformFromDecimalToHex(strP, argList, 1, type);
  if (flagO == 1) TransformDecToOctal(strP, type, argList);
  if (flagP == 1) GetAddress(argList, strP);
  if (s21_strncmp(strP, "(nil)", 5) == 0) {
    flagSpace = 0;
    flagHash = 0;
    flagZero = 0;
    flagPlus = 0;
  }
  if (accuracy != -1 && (s21_strncmp(strP, "(nil)", 5) != 0))
    widthZero = accuracy - s21_strlen(strP);
  if (flagZero == 1 && accuracy == -1) widthZero = width - s21_strlen(strP);
  if (flagX == 0 && flagSpace == 1 && flagO == 0 && flagPlus == 0) {
    s21_strncat(strNorm, " ", 1);
    index += 1;
    if (accuracy == -1) widthZero -= 1;
  }
  if ((flagPlus == 1 && flagX == 0 && flagO == 0) ||
      (flagP == 1 && flagPlus == 1)) {
    s21_strncat(strNorm, "+", 1);
    index++;
    if (accuracy == -1) widthZero--;
  }
  if ((flagP == 1 && (s21_strncmp(strP, "(nil)", 5) != 0)) ||
      (flagX == 1 && flagHigh == 0 && flagHash == 1 &&
       s21_strncmp(strP, "0", 1) != 0)) {
    s21_strncat(strNorm, "0x", 2);
    index += 2;
    if (accuracy == -1) widthZero -= 2;
  }
  if (flagX == 1 && flagHigh == 1 && flagHash == 1 &&
      s21_strncmp(strP, "0", 1) != 0) {
    s21_strncat(strNorm, "0X", 2);
    index += 2;
    // widthZero -= 2;
  }
  if (flagO == 1 && flagHash == 1 && s21_strncmp(strP, "0", 1) != 0) {
    s21_strncat(strNorm, "0", 1);
    index++;
    widthZero -= 1;
  }
  if (flagZero == 1 || widthZero != 0) {
    int endO = index + widthZero;
    while (index < endO) {
      strNorm[index] = '0';
      index++;
    }
  }
  strNorm[index] = '\0';
  s21_strncat(strNorm, strP, s21_strlen(strP));
  strNorm[s21_strlen(strNorm)] = '\0';
  width = width - s21_strlen(strNorm) + 1;
  if (flagMinus == 1) {
    ConnectingStrings(str, strNorm, pointer);
    AddWidth(str, width, pointer, ' ');
  } else {
    AddWidth(str, width, pointer, ' ');
    ConnectingStrings(str, strNorm, pointer);
  }
  (*str)[(*pointer)] = '\0';
}

void spec_e(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int accuracy, int flagZero, int flagSpace, int flagPlus,
            int flagHigh) {
  int belowZero = 0;
  char strFloat[500];
  strFloat[0] = '\0';
  long double num = 0;
  FloatLengthParser(argList, &num, "lf");
  ScienceForm(strFloat, accuracy, num, &belowZero, flagHigh);
  width = width - s21_strlen(strFloat) + 1;
  FlagWork(str, pointer, flagMinus, &width, flagZero, flagSpace, flagPlus,
           belowZero);
  WorkingWithString(str, pointer, flagMinus, width, flagZero, flagPlus,
                    belowZero, strFloat);
}

void spec_g(va_list argList, char** str, int* pointer, int flagMinus, int width,
            int accuracy, int flagZero, int flagSpace, int flagPlus,
            int flagHigh, int flagHash) {
  int belowZero = 0;
  char strFloat[500];
  strFloat[0] = '\0';
  double num = 0;
  num = (double)va_arg(argList, double);
  ShortestForm(strFloat, num, &belowZero, flagHigh, accuracy, flagHash);
  width = width - s21_strlen(strFloat) + 1;
  FlagWork(str, pointer, flagMinus, &width, flagZero, flagSpace, flagPlus,
           belowZero);
  WorkingWithString(str, pointer, flagMinus, width, flagZero, flagPlus,
                    belowZero, strFloat);
}
