#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
       
  string str= argv[1];
  
  //Apresenta na tela a palavra digitada
  cout << "Palavra inserida: ";
 
    for (size_t i = 0; i < str.size(); i++)
    {
      cout << str[i];
    } 
  
    cout << endl;

  //=============================================
    int contador, local, crepetido=0;
    
    for (size_t i= 0; i < str.size(); i++)
    {   
        contador = 0;
        for (size_t j = 0; j < str.size(); j++)
        {
            if (str[i] == str[j])
            {
                contador = contador +1;
            }
        }
        if(contador >= 2)
        {
            cout << "A letra: [" << str[i] << "] está repetida" <<endl;
        }
        else
        {
            cout << "A letra: [" <<str[i] << "] foi encontrada 1 vez. "<< endl;
        }
        if(crepetido < contador)
        { 
            crepetido = contador;
            local = i;
        }
    }
    cout << "========================================================="<< endl;
    cout << "A letra que mais se repetiu foi: [" << str[local] << "] com um total de: " << crepetido << endl;
    cout << endl;
        
    return EXIT_SUCCESS;
} 