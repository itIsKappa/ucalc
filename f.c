#include <stdio.h>
#include <gmp.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char **argv) {
    bool interactive = strcmp(argv[2], "1") == 0 ? true : false;
    size_t i;
    mpz_t number;
    mpz_t theNumber;
    mpz_t placeValue;
    mpz_init(number);
    mpz_init(theNumber);
    mpz_init_set_si(placeValue, 1);
    char charNumber[strlen(argv[1])];
    char temporaryCharNumber;
    bool isNegative = false;
    bool isNotNumber = true;

    strcpy(charNumber, argv[1]);
    FILE* log = fopen("ucalcLogF.txt", "w");
    fprintf(log, "Labour has been received by Factoriser\n");
    for(i = strlen(charNumber); i > 0; i--) {
        temporaryCharNumber = charNumber[i - 1];
        fprintf(log ,"TemporaryCharNumber: %c\n", temporaryCharNumber);
        if(temporaryCharNumber == '-') {
            puts("UCalc Excuses: Cannot find factors of a negative integer");
            exit(0);
        }
        mpz_set_si(number, atoi(&temporaryCharNumber));
        if(mpz_cmp_si(number, 0) == 0) {
            if(temporaryCharNumber == '.') {
                puts("UCalc Excuses: Cannot find factors of a floating point number");
                exit(0);
            } else if(temporaryCharNumber != '0') {
                puts("UCalc Excuses: Cannot find factors of non-numerical values");
                exit(0);
            }
        }
        gmp_fprintf(log, "Number: %Zd CharNumber: %c\n", number, temporaryCharNumber);
        gmp_fprintf(log, "Place Value: %Zd * Number: %Zd\n", placeValue, number);
        mpz_mul(number, number, placeValue);
        gmp_fprintf(log, "Number: %Zd + TheNumber: %Zd\n", number, theNumber);
        mpz_add(theNumber, theNumber, number);
        gmp_fprintf(log, "TheNumber: %Zd\n", theNumber);
        mpz_mul_ui(placeValue, placeValue, 10);
    }
    mpz_clear(placeValue);
    if(mpz_cmp_si(theNumber, 0) == 0) {
        puts("UCalc Excuses: Cannot factors of zero");
        exit(0);
    }
    mpz_set_ui(number, 1);
    mpz_t howManyFactors;
    mpz_init_set_ui(howManyFactors, 0);
    if(interactive) gmp_printf("< REPLY >: %Zd => ( ", theNumber);
    else gmp_printf("UCalc Replies: %Zd => ( ", theNumber);
    while(true) {
        if(mpz_divisible_p(theNumber, number) != 0) {
            gmp_printf("%Zd, ", number);
            mpz_add_ui(howManyFactors, howManyFactors, 1);
        }
        mpz_add_ui(number, number, 1);
        if(mpz_cmp(theNumber, number) == 0) {
            mpz_add_ui(howManyFactors, howManyFactors, 1);
            gmp_printf("%Zd ) ", number);
            gmp_printf("%Zd\n", howManyFactors);
            break;
        }
    }
    fprintf(log, "Factoriser has done its labour\n");
    mpz_clear(howManyFactors);
    mpz_clear(number);
    mpz_clear(theNumber);
    fclose(log);
}