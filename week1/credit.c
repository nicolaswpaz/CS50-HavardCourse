#include <cs50.h>
#include <math.h>
#include <stdio.h>

#define AMEX_NUMB1 34
#define AMEX_NUMB2 37
#define MASTER_NUMB1 51
#define MASTER_NUMB2 52
#define MASTER_NUMB3 53
#define MASTER_NUMB4 54
#define MASTER_NUMB5 55
#define VISA_NUMB1 4

int sum_other(long number);
int sum_mult_every(long number);
int sum_digits(int number);
int count_number(long number);
bool isValidCard(long credit);
int inicial_numbers(long numb);

int main(void)
{
    long credit_number = get_long("Number: ");

    if (isValidCard(credit_number))
    {

        int n = count_number(credit_number);
        int i = inicial_numbers(credit_number);

        if (n == 15 && ((i == AMEX_NUMB1) || (i == AMEX_NUMB2)))
        {
            printf("AMEX\n");
        }
        else if (n == 16 && ((i == MASTER_NUMB1) || (i == MASTER_NUMB2) || (i == MASTER_NUMB3) ||
                             (i == MASTER_NUMB4) || (i == MASTER_NUMB5)))
        {
            printf("MASTERCARD\n");
        }
        else if ((n == 16 || n == 13) && (i / 10 == VISA_NUMB1))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int inicial_numbers(long numb)
{
    int n = count_number(numb);
    return numb / (pow(10, (n - 2)));
}

bool isValidCard(long credit_number)
{
    int sum = sum_mult_every(credit_number) + sum_other(credit_number);
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

int count_number(long number)
{
    int i = 0;
    while (number != 0)
    {
        number /= 10;
        i++;
    }
    return i;
}

int sum_mult_every(long number)
{
    number = number / 10;
    int sum = 0;

    do
    {
        sum += sum_digits(2 * (number % 10));
        number /= 100;
    }
    while (number != 0);

    return sum;
}

int sum_other(long number)
{
    int sum = 0;

    do
    {
        sum += number % 10;
        number /= 100;
    }
    while (number != 0);

    return sum;
}

int sum_digits(int number)
{
    if ((number % 10) == number)
    {
        return number;
    }
    return ((number % 10) + (number / 10));
}
