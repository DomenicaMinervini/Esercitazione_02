/*************************************************************
**************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
**************************************************************
*************************************************************/

#include <string>
#include "random.h"

using namespace std;
 
int main (int argc, char *argv[]){

   Random rnd;
   int seed[4];
   int p1, p2;
   ifstream Primes("Primes");
   if (Primes.is_open()){
      Primes >> p1 >> p2 ;
	  Primes >> p1 >> p2 ;
   } else cerr << "PROBLEM: Unable to open Primes" << endl;
   Primes.close();

   ifstream input("seed.in");
   string property;
   if (input.is_open()){
      while ( !input.eof() ){
         input >> property;
         if( property == "RANDOMSEED" ){
            input >> seed[0] >> seed[1] >> seed[2] >> seed[3];
            rnd.SetRandom(seed,p1,p2);
         }
      }
      input.close();
   } else cerr << "PROBLEM: Unable to open seed.in" << endl;

   int a; //Variabile 0 o 1.
   int zero=0; //Quante volte è estratto 0.
   int one=0; //Quante volte è estratto 1.
   int stop; //E' la posizione finale.
   
   for(int i=0; i<100; i++){
	  //Estrae un numero decimale in [0,1), lo moltiplica per 2 e ne prende la parte intera: si ottiene così o 0 o 1.
      a = int(2.0*rnd.Rannyu()); 
	  
	  if(a == 0){ //Se hai estratto 0, incrementa zero.
		  zero++;
	  }
	  else{ //Se hai estratto 1, incrementa one.
		  one++;
	  }
	  	  
   }
   cout << "Ho estratto 0 " << zero << " volte e ho estratto 1 " << one << " volte. " << endl;
   
   //A zero associo un passo in avanti, a one un passo indietro: per questo one cambia segno.
   one = -one;
   stop = zero + one; // Sommo i passi in avanti e indietro: è la posizione finale.
   cout << "La posizione finale e': " << stop << endl;

   rnd.SaveSeed();
   return 0;
}

/*************************************************************
**************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
**************************************************************
*************************************************************/
