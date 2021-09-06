/*
    PAGE: 67
    ---
    Ex: Extend atof to handle scientific notation of the form 123.45e-6
        where a floating-point number may be followed by e or E and an 
        optionally signed exponent. 
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LEN           32

/* atof: convert string s to double */
double my_atof(char * s);

int main(){
    
    int c;
    char str[MAX_INPUT_LEN];
    double val;

    for(unsigned i = 0; (c = getchar()) != EOF && i < MAX_INPUT_LEN; i++){
        str[i] = c;
    }

    val = my_atof(str);

    printf("Res: %f\n", val);

    return 0;
}

/* atof: convert string s to double, (Book example, PAGE 65 */ 
double my_atof(char * s){
    double val, power, exp = 1;
    int i, sign, len;
    char cur, next;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    /* There are at least 2 chars left (for a min of 'e/E' + 'digit' ) not counting '\0' */
    if(i < ((len = strlen(s)) - 2)){ 
        if(s[i] == 'e' || s[i] == 'E'){ /* Found an exponent */
            if(s[i + 1] == '-'){  /* Whether positive or negative */
                exp = -1.0 ;
                i++;
            }
            /* There are at least two digits left */
            if(i < len - 2){
                cur = s[++i], next = s[++i];
                
                /* Take two digits */
                if(isdigit(next))
                    exp *= (10 * (cur - '0')) + next - '0';
                else 
                    exp *= cur - '0';
            }
            /* There's only one digit left */
            else{
                cur = s[++i];
                /* Take only one digit */
                exp *= isdigit(cur) * (cur - '0');
            }
        }
    }
    return (sign * val / power) * pow(10, exp);
}