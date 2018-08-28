#include <iostream>
#include <stdlib.h>



using namespace std ;

void imprime(int *Vetor, int tam){
    int i;
    for(i = 0; i < tam; i++){
       cout <<  Vetor[i] << " ";  
  
    }
    cout << "\n";
  
 }  



void coutingSort(int *Vetor, int n , int RANGE){
	
 
   int count[RANGE]={0};
    int i;
    int out[n];
    
    
    for(i=0;i<n;i++)
    ++count[Vetor[i]];
    
    for(i=1;i<RANGE;i++)
    count[i]+=count[i-1];
    
   
    
    for(i=n-1;i>=0;i--){
        out[count[Vetor[i]]-1]=Vetor[i];
        --count[Vetor[i]];
    }
    
    for(i=0;i<n;i++)
   Vetor[i]= out[i];

}

int main()
 {  
         int Vetor[] = {1,2,4,8,4,6,6,10,15};
         int n= sizeof(Vetor)/sizeof(Vetor[0]);
         int RANGE = 20;
      cout <<"  Vetor Desordenado:\n" ; 
      imprime(Vetor,n);

      cout <<"  Vetor Ordenado:\n" ; 
      coutingSort(Vetor,n,RANGE);
      imprime(Vetor,n);



     return 0;
}