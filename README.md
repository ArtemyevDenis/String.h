# String.h/Sprintf function
### This project realize sprintf function in string.h library

int sprintf(char *str, const char *format, ...) - sends formatted output to a string pointed to, by str.

where:
- str − This is the C string that the function processes as its source to retrieve the data;
- format − This is the C string that contains one or more of the following items: Whitespace character, Non-whitespace character and Format specifiers. A format specifier for print functions follows this prototype: %[flags][width][.precision][length]specifier. A format specifier for scan functions follows this prototype: %[*][width][length]specifier.

### sprintf specifiers

|No.|Specifier|Sprintf output|
|:-:|:--------|:-------------|
|1|c|Character|
|2|d|Signed decimal integer|
|3|i|Signed decimal integer|
|4|e|Scientific notation (mantissa/exponent) using e character (the output of the numbers must match up to e-6)|
|5|E|Scientific notation (mantissa/exponent) using E character|
|6|f|Decimal floating point|
|7|g|Uses the shortest representation of decimal floating point|
|8|G|Uses the shortest representation of decimal floating point with E|
|9|o|Unsigned octal|
|10|s|String of characters|
|11|u|Unsigned decimal integer|
|12|x|Unsigned hexadecimal integer|
|13|X|Unsigned hexadecimal integer (capital letters)|
|14|p|Pointer address|
|15|%|Character %|

### sprintf flags

|No.|Flag|Description|
|:-:|:--------|:-------------|
|1|-|Left-justify within the given field width; Right justification is the default (see width sub-specifier).|
|2|+|Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign.|
|3|(space)|If no sign is going to be written, a blank space is inserted before the value.|
|4|0|Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier).|
|5|#|Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow. By default, if no digits follow, no decimal point is written. Used with g or G the result is the same as with e or E but trailing zeros are not removed.|

### sprintf Width Description

|No.|Width|Description|
|:-:|:--------|:-------------|
|1|(number)|Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
|2|*|In sprintf the * sign means, that the width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. In sscanf the * sign placed after % and before the format specifier reads data of the specified type, but suppresses their assignment.|


### sprintf Precision Description

|No.|.precision|Description|
|:-:|:--------|:-------------|
|1|.number|For integer specifiers (d, i, o, u, x, X) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E and f specifiers − this is the number of digits to be printed after the decimal point. For g and G specifiers − This is the maximum number of significant digits to be printed. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified for specifiers e, E, f, g and G, the default one is 6. When no precision is specified for all other kind of specifiers, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed.|
|2|.*|The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|


### sprintf Length Description

|No.|Length|Description|
|:-:|:--------|:-------------|
|1|h|The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X).|
|2|l|The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X), and as a wide character or wide character string for specifiers c and s.|
|3|L|The argument is interpreted as a long double (only applies to floating point specifiers − e, E, f, g and G).|