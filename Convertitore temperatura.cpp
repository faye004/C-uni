/*
Write a program that takes in three arguments, a start temperature (in Celsius), an end temperature (in Celsius) and a step size.

Print out a table that goes from the start temperature to the end temperature, in steps of the step size; for each value you also need to provide the Fahrenheit value; you do not actually need to print the final end temperature if the step size does not exactly match.

You should perform input validation: do not accept start temperatures less than a lower limit (which your code should specify as a constant) or higher than an upper limit (which your code should also specify).

You should not allow a step size greater than the difference in temperatures.
*/



#include <iostream>
#include <cmath>
using namespace std;

#define LOWER_LIMIT 0
#define HIGHER_LIMIT 10

int main(){
    int step, times = 0; 
    float t_i, t_fahrenheit, t_f; //t_i = temperatura iniziale, t_f = temperatura finale
    
    do{
        cout << "Inserisci la temperatura iniziale (criterio " << LOWER_LIMIT << " <= t <= " << HIGHER_LIMIT << "): ";
        cin >> t_i;
    }while(t_i < 0 || t_i > 10);

    do{
        cout << "Inserisci la temperatura finale. (criterio t_f < 115): ";
        cin >> t_f;
    }while(t_f <= t_i || t_f > 115);

    do{
        cout << "Inserisci lo step size (un valore intero) : ";
        cin >> step;
    }while(step <= 0 || step > (t_f - t_i));

    cout << "\n\n\n\n Celsius \t\t\t Fahrenheit\n";

    do{
        times++;
        t_fahrenheit = (t_i * 9.0)/5.0 + 32.0;
        cout << "-----------------------------------------------------------------------\n";
        cout << " " << t_i << " \t\t\t\t " << t_fahrenheit << " \t\t\t ||| step n°" << times << "\n";
        cout << "-----------------------------------------------------------------------\n";
        t_i += step;
    }while(t_f >= t_i);
    cout << "\n\n\n" << endl;

    return 0;
}