#include <iostream>

using namespace std;
 


void imprime(int Vetor[], int n)
{
    for (int i = 0; i < n; i++){
        cout << Vetor[i] << " ";
    }
        cout << "\n";
}
 


int getMax(int Vetor[], int n)
{
    int mx = Vetor[0];
    for (int i = 1; i < n; i++)
        if  (Vetor[i] > mx)
            mx = Vetor[i];
    return mx;
}
 
// funcao count sort

void countSort(int Vetor[], int n, int exp)
{
    int output[n]; // 
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(Vetor[i]/exp)%10 ]++;
 
    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(Vetor[i]/exp)%10 ] - 1] = Vetor[i];
        count[(Vetor[i]/exp)%10 ]--;
    }
 
    
    for (i = 0; i < n; i++)
        Vetor[i] = output[i];
}
 

void radixsort(int Vetor[], int n)
{
  
    int m = getMax(Vetor, n);
 
   
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(Vetor, n, exp);
}
 




int main()
{
    int Vetor[] = {170, 45, 75, 90, 802, 24,32,5,66,25};
    int n = sizeof (Vetor)/sizeof(Vetor[0]);
    
     cout <<"  Vetor Desordenado:\n\n" ; 
     imprime(Vetor,n);
      cout << "\n";

    
    cout << "  Vetor Ordenado:\n\n" ; 
    radixsort (Vetor, n);
    imprime (Vetor, n);
     cout << "\n";

    return 0;
}
