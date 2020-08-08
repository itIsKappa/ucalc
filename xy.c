#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <stdbool.h>
#include <string.h>

void main(int argc, char **argv) {
    FILE* log = fopen("ucalcLogXY.txt", "w");
    if(argc < 5) {
        puts("\nUCalc Excuses: There is insuffient arguments for finding the Product-Sum factor.\n"\
             "UCalc Exemplifies: xy::(Product)::(Sum)::(Counter Upto), xy::100::25::100\n");
        exit(0);
    }
    mpz_t product, sum, c, toAdd, placeValue;
    size_t i;
    char temporaryCharNumber;
    mpz_init(product);
    mpz_init(toAdd);
    mpz_init_set_si(placeValue, 1);
    char char_product[strlen(argv[1])];
    char char_sum[strlen(argv[2])];
    char char_c[strlen(argv[3])];
    strcpy(char_product, argv[1]);
    strcpy(char_sum, argv[2]);
    strcpy(char_c, argv[3]);
    bool beNegative = false;
    bool interactive = strcmp(argv[4], "1") == 0 ? true : false;
    fprintf(log, "N1S: %s  N2S: %s  CS: %s\n", char_product, char_sum, char_c);
    /* Acquiring N1 */
    for(i = strlen(char_product); i > 0; i--) {
        temporaryCharNumber = char_product[i - 1];
        mpz_set_si(toAdd, atoi(&temporaryCharNumber));
        if(mpz_cmp_ui(toAdd, 0) == 0) {
            if(temporaryCharNumber == '-' || temporaryCharNumber == '~') {
                beNegative = true;
            } else if(temporaryCharNumber == '0') {/*PASS*/} else {
                puts("UCalc Excuses: Non-numeric product");
                exit(0);
            }
        }
        mpz_mul(toAdd, toAdd, placeValue);
        mpz_add(product, product, toAdd);
        mpz_mul_ui(placeValue, placeValue, 10);
    }
    if(beNegative) {
        mpz_neg(product, product);
        beNegative = false;
    }
    gmp_fprintf(log, "Product: %Zd\n", product);
    mpz_init(sum);
    mpz_set_ui(placeValue, 1);
    /* Acquiring N2 */
    for(i = strlen(char_sum); i > 0; i--) {
        temporaryCharNumber = char_sum[i - 1];
        mpz_set_si(toAdd, atoi(&temporaryCharNumber));
        if(mpz_cmp_ui(toAdd, 0) == 0) {
            if(temporaryCharNumber == '-' || temporaryCharNumber == '~') {
                beNegative = true;
            } else if(temporaryCharNumber == '0') {/*PASS*/} else {
                puts("UCalc Excuses: Non-numeric sum.");
                exit(0);
            }
        }
        mpz_mul(toAdd, toAdd, placeValue);
        mpz_add(sum, sum, toAdd);
        mpz_mul_ui(placeValue, placeValue, 10);
    }
    if(beNegative) {
        mpz_neg(sum, sum);
        beNegative = false;
    }
    gmp_fprintf(log, "Sum: %Zd\n", sum);
    mpz_init(c);
    mpz_set_ui(placeValue, 1);
    /* Acquiring Counter */
    for(i = strlen(char_c); i > 0; i--) {
        temporaryCharNumber = char_c[i - 1];
        mpz_set_si(toAdd, atoi(&temporaryCharNumber));
        if(mpz_cmp_ui(toAdd, 0) == 0) {
            if(temporaryCharNumber == '-' || temporaryCharNumber == '~') {
                puts("UCalc Excuses: Counter value can never be negative.");
                exit(0);
            } else if(temporaryCharNumber == '0' && strlen(char_c) == 1) {
                puts("UCalc Excuses: Counter value can never be zero.");
                exit(0);
            } else if(temporaryCharNumber == '0') {/*PASS*/} else {
                puts("UCalc Excuses: Counter value must be a number.");
                exit(0);
            }
        }
        mpz_mul(toAdd, toAdd, placeValue);
        mpz_add(c, c, toAdd);
        mpz_mul_ui(placeValue, placeValue, 10);
    }
    gmp_fprintf(log, "Counter: %Zd\n", c);
    mpz_clear(placeValue);
    //printf("N1S: %s  N2S: %s  CS: %s\n", char_product, char_sum, char_c);
    //gmp_printf("N1: %Zd  N2: %Zd  C: %Zd\n", product, sum, c);
    mpz_t counter_i, counter_j;
    mpz_init_set_ui(counter_i, 1);
    mpz_init_set_ui(counter_j, 1);
    mpz_t multiValue, sumValue;
    mpz_init_set_ui(multiValue, 0);
    mpz_init_set_ui(sumValue, 0);
    bool foundFactor = false;
    while(true) {
        while(true) {
            mpz_mul(multiValue, counter_i, counter_j);
            mpz_add(sumValue, counter_i, counter_j);
            gmp_printf("\r%Zd %Zd", counter_i, counter_j);
            if(mpz_cmp(multiValue, product) == 0 && mpz_cmp(sumValue, sum) == 0) {
                if(interactive) gmp_printf("\r< REPLY >: ( X: %Zd )( Y: %Zd ) %Zdx%Zd=%Zd, %Zd+%Zd=%Zd\n", counter_i, counter_j, counter_i, counter_j, multiValue, counter_i, counter_j, sumValue);
                else gmp_printf("\rUCalc Replies: ( X: %Zd )( Y: %Zd ) %Zdx%Zd=%Zd, %Zd+%Zd=%Zd\n", counter_i, counter_j, counter_i, counter_j, multiValue, counter_i, counter_j, sumValue);
                foundFactor = true;
            }
            mpz_neg(counter_i, counter_i);
            mpz_mul(multiValue, counter_i, counter_j);
            mpz_add(sumValue, counter_i, counter_j);
            if(mpz_cmp(multiValue, product) == 0 && mpz_cmp(sumValue, sum) == 0) {
                if(interactive) gmp_printf("\r< REPLY >: ( X: %Zd )( Y: %Zd ) %Zdx%Zd=%Zd, %Zd+%Zd=%Zd\n", counter_i, counter_j, counter_i, counter_j, multiValue, counter_i, counter_j, sumValue);
                else gmp_printf("\rUCalc Replies: ( X: %Zd )( Y: %Zd ) %Zdx%Zd=%Zd, %Zd+%Zd=%Zd\n", counter_i, counter_j, counter_i, counter_j, multiValue, counter_i, counter_j, sumValue);
                foundFactor = true;
            }
            mpz_neg(counter_i, counter_i);
            mpz_neg(counter_j, counter_j);
            mpz_mul(multiValue, counter_i, counter_j);
            mpz_add(sumValue, counter_i, counter_j);
            if(mpz_cmp(multiValue, product) == 0 && mpz_cmp(sumValue, sum) == 0) {
                if(interactive) gmp_printf("\r< REPLY >: ( X: %Zd )( Y: %Zd ) %Zdx%Zd=%Zd, %Zd+%Zd=%Zd\n", counter_i, counter_j, counter_i, counter_j, multiValue, counter_i, counter_j, sumValue);
                else gmp_printf("\rUCalc Replies: ( X: %Zd )( Y: %Zd ) %Zdx%Zd=%Zd, %Zd+%Zd=%Zd\n", counter_i, counter_j, counter_i, counter_j, multiValue, counter_i, counter_j, sumValue);
                foundFactor = true;
            }
            mpz_neg(counter_i, counter_i);
            mpz_mul(multiValue, counter_i, counter_j);
            mpz_add(sumValue, counter_i, counter_j);
            if(mpz_cmp(multiValue, product) == 0 && mpz_cmp(sumValue, sum) == 0) {
                if(interactive) gmp_printf("\r< REPLY >: ( X: %Zd )( Y: %Zd ) %Zdx%Zd=%Zd, %Zd+%Zd=%Zd\n", counter_i, counter_j, counter_i, counter_j, multiValue, counter_i, counter_j, sumValue);
                else gmp_printf("\rUCalc Replies: ( X: %Zd )( Y: %Zd ) %Zdx%Zd=%Zd, %Zd+%Zd=%Zd\n", counter_i, counter_j, counter_i, counter_j, multiValue, counter_i, counter_j, sumValue);
                foundFactor = true;
            }
            /* Checking for reaching counter value */
            mpz_neg(counter_j, counter_j);
            mpz_neg(counter_i, counter_i);
            if(mpz_cmp(counter_j, c) == 0) {
                mpz_set_ui(counter_j, 0);
                break;
            } else if(foundFactor) break;
            mpz_add_ui(counter_j, counter_j, 1);
        }
        /* Checking for reaching counter value */
        if(mpz_cmp(counter_i, c) == 0) break;
        else if(foundFactor) break;
        mpz_add_ui(counter_i, counter_i, 1);
    }
    if(!foundFactor) {
        if(interactive) puts("\r< REPLY >: Found None.");
        else puts("\rUCalc Replies: Found None.");
        fprintf(log, "No Value Found\n");
    } else fprintf(log, "Value Found\n");
    mpz_clear(counter_i);
    mpz_clear(counter_j);
    mpz_clear(multiValue);
    mpz_clear(sumValue);
    mpz_clear(sum);
    mpz_clear(product);
    mpz_clear(c);
    mpz_clear(toAdd);
    fclose(log);
}