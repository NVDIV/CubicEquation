#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

// Constants and struct's declaration

#define PI  3.1415926

struct Complex {
    double re;
    double im;
};

char initial_data_exp[3] = {'a','b','c'};

bool input_check = false;

// Function prototypes

void capture();
double get_input(int position);
void solve_equation(double a, double b, double c);
bool continue_calculations();
void clear_console();

int main() 
{
    // Clear console

    clear_console();

    // Author, title and name

    capture();

    double a = 0;
    double b = 0;
    double c = 0;

    int position;

    do
    {
        // Get and check coefficients

        do
        {
            position = 0;
            a = get_input(position);
        } 
        while (!input_check);

        do
        {
            position = 1;
            b = get_input(position);
        } 
        while (!input_check);


        do
        {
            position = 2;
            c = get_input(position);
        } 
        while (!input_check);

        // Solve the equation

        solve_equation(a, b, c);

    } 
    while (continue_calculations() == true);

    return 0;
}

// Clear console

void clear_console() 
{
    system("cls");
}

// Author and title

void capture()
{
    // Author

    printf("\nNadiia Rybak 2023\n");

    // Title

    printf("\nCUBIC EQUATION\n");

    // Decription

    printf("\nSolve cubic equation.\n\n");
}

// Get and check input

double get_input(int position)
{
    // Get input

    char input[10];

    printf("\nEnter coefficient %c (up to 10 symbols): ", initial_data_exp[position]);

    scanf("%s", input);

    // Check input

    // Check is that a number

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-')
        {
            printf("\nYour input is invalid.\n");
            input_check = false;
            return -1;
        }
    }

    input_check = true;

    return atof(input);
}

// Function to solve cubic equation

void solve_equation(double a, double b, double c) 
{
    double p = b - (a*a) / 3;

    double q = 2 * (a*a*a) / 27 - a * b / 3 + c;

    double d = (p * p * p) / 27 + q * q / 4;

    if (d > 0)
    {
        double x1;
        struct Complex x2;
        struct Complex x3;

        double y = -q/2 + sqrt(d);
        double u = (y>0) ? (pow(y,1/3.)) : (pow(fabs(y), 1/3.)*(-1));
        double v = -p/(3*u);

        x1 = u + v;

        x2.re = (u+v)/(-2) - a/3;
        x2.im = (sqrt(3)*(u-v))/2;

        x3.re = (u+v)/(-2) - a/3;
        x3.im = -(sqrt(3)*(u-v))/2;

        printf("x1: %f\n", x1);
        printf("x2: (%f;%f)\n", x2.re, x2.im);
        printf("x3: (%f;%f)\n", x3.re, x3.im);
    }
    else if (d == 0)
    {
        double x1, x2;
        x1 = 3 * q / p - a/3;
        x2 = -3 * q / (2 * p) - a/3;

        printf("x1: %f\n", x1);
        printf("x2: %f\n", x2);
         printf("x3: %f\n", x2);
    }
    else 
    {
        if ((p*p*p/(-27)) >= 0)
        {
            double x1, x2, x3;

            double r = sqrt(p*p*p/(-27));
            double ph = acos(-q/(2*r));

            x1 = 2*fabs(pow(r, 1/3.))* cos(ph/3) - a/3;
            x2 = 2*fabs(pow(r, 1/3.))* cos((ph+2*PI)/3) - a/3;
            x3 = 2*fabs(pow(r, 1/3.))* cos((ph +4*PI)/3) - a/3;

            printf("x1: %f\n", x1);
            printf("x2: %f\n", x2);
            printf("x3: %f\n", x3);
        }
        else
        {
            printf("It's impossible to solve this equation!");
        }
    }
}

// Function to enter initial data one more time or quit the programm

bool continue_calculations()
{
    printf("\nDo you want to enter initial data one more time? (enter/esc) \n");

    while(1)
    {
        char response = getch(); 

        if (response == 13)  
        {
            return true;
        }
        else if (response == 27)  
        {
            return false;
        }
    }
}