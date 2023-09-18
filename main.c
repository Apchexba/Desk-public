#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){

setlocale(LC_ALL, "Ru");

int i=0, qtyYers = 20;
int inflation = 7;
int investment = 9;

long long int capital_alice = 1000000*100;
long long int salary_alice = 200000*100;
long long int rent = 40000*100;
long long int deposite_alice =0;
long long int expenses_alice = 50000*100;

int apartment_price = 10000000*100;
long long int capital_bob = 0;
long long int salary_bob = 200000*100;
long long int mortgage = 110000*100;
long long int deposite_bob = 0;
long long int expenses_bob = 50000*100;

for (i=0;i<=qtyYers-1;++i){
   
    salary_alice *= 1.06;
    deposite_alice = capital_alice*pow(1+investment/(100*12), i*qtyYers) ;
    expenses_alice *=1.07 ;
    capital_alice +=(salary_alice-rent-expenses_alice)*12;

    salary_bob *= 1.06;
    deposite_bob = capital_bob*pow(1+investment/(100*12), i*qtyYers) ;
    expenses_bob *=1.07 ;
    capital_bob +=(salary_bob-mortgage-expenses_bob)*12;

}
capital_alice = deposite_alice;
capital_bob = deposite_bob+apartment_price;

printf("|%0.2lf | %0.2lf|\n %s", capital_alice, capital_bob,  (capital_alice > capital_bob) ? "alice сформирует больший капитал":"bob сформирует больший капитал");
    return 0;
}
