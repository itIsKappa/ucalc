#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gmp.h>
#include <string.h>

#define STARTING_NUM 3

void main(int argc, char **argv) {
    char char_sum[strlen(argv[1])];
    bool interactive = strcmp(argv[2], "1") == 0 ? true : false;
    strcpy(char_sum, argv[1]);
    mpz_t sum, placeValue, toAdd;
    char temporaryCharNumber;
    int i;
    mpz_init_set_si(placeValue, 1);
    mpz_init(toAdd);
    mpz_init(sum);
    /* Acquiring Numeral */
    for(i = strlen(char_sum); i > 0; i--){
        temporaryCharNumber = char_sum[i - 1];
        if(temporaryCharNumber == '-') {
            puts("Negative numerals are not acceptable");
            exit(0);
        } else if(temporaryCharNumber == '.') {
            puts("Floating numerals are not acceptable");
            exit(0);
        }
        mpz_set_si(toAdd, atoi(&temporaryCharNumber));
        mpz_mul(toAdd, toAdd, placeValue);
        mpz_add(sum, sum, toAdd);
        mpz_mul_si(placeValue, placeValue, 10);
    } if(mpz_cmp_si(sum, 2) < 0) {
        puts("Value must be a numeral which must not be less than 2");
        exit(0);
    }
    /* CLEARS FOR VALUES OF NO USE FORTH */
    mpz_clear(placeValue);
    mpz_clear(toAdd);

    /* Fetching Primes */
    mpz_t counter;
    mpz_init(counter);
    if(interactive) gmp_printf("< REPLY >: %Zd => ", sum);
    else gmp_printf("UCalc Replies: %Zd => ", sum);
    mpz_add_ui(sum, sum, 1);
    bool isPrime = true;
    mpz_t I, J, upto;
    mpz_init(I);
    mpz_init(J);
    mpz_init(upto);
    mpz_set_si(I, STARTING_NUM);
    printf("( 2");
    while(mpz_cmp(sum, I) != 0) {
        isPrime = true;
        // gmp_printf("I: %Zd ", I);
        mpz_sqrt(upto, I);
        // gmp_printf("with sqrt(%Zd) ", upto);
        mpz_set_ui(J, 2);
        while(mpz_cmp(J, upto) <= 0) {
            // gmp_printf("J: %Zd ", J);
            if(mpz_divisible_p(I, J) != 0) {
                isPrime = false;
                break;
            }
            mpz_add_ui(J, J, 1);
        }  if(isPrime) {
            gmp_printf(", %Zd", I);
            mpz_add_ui(counter, counter, 1);
        }
        // if(isPrime) puts("is prime");
        // else puts("is not prime");
        mpz_add_ui(I, I, 1);
    }
    gmp_printf(" ) %Zd\n", counter);

    /* CLEARS AT END */
    mpz_clear(sum);
    mpz_clear(I);
    mpz_clear(J);
    mpz_clear(upto);
    mpz_clear(counter);
}