#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Nodo
{
   public:
   string data;
   string data2;
   Nodo *proximo;
};
void append(Nodo** head_ref, string new_data)
{
   // 1. aloca
   Nodo* new_Nodo = new Nodo();
   //usado no passo 5
   Nodo *last = *head_ref;
   // 2. preenche com dados
   new_Nodo->data = new_data;
   /* 3. o novo nodo será o último, então o proximo será NULL*/
   new_Nodo->proximo = NULL;
   /* 4. se a lista encadeada está vazia, faz o novo ser o início */
   if (*head_ref == NULL)
   {
       *head_ref = new_Nodo;
       return;
   }
   /* 5. ou percorra até o último nodo */
   while (last->proximo != NULL)
   {
       last = last->proximo;
   }
   /* 6. altera o proximo do últio nodo */
   last->proximo = new_Nodo;
   return;
}
// imprime o conteúdo da lista a partir do início recebido
void printList(Nodo *Nodo)
{
   while (Nodo != NULL)
   {
       cout << ", " << Nodo->data;
       Nodo = Nodo->proximo;
   }
   cout <<"."<< endl;
}
 

//Implemente aqui a funçao que identifica e remove palavras duplicadas
//li em: https://www.geeksforgeeks.org/recursive-function-delete-k-th-node-linked-list/?ref=gcse
void deletaRepetidos(Nodo *key) 
{   //Ponteiro fixo
    Nodo *fpont;
    //Ponteiro para fazera  comparação
    Nodo *temp;
    //Ponteiro dos paises repetidos
    Nodo *repetido;
    //Atribui ao ponteiro fixo o valor da cabeça (head)
    fpont = key;

    //função while: https://acervolima.com/remover-duplicatas-de-uma-lista-vinculada-nao-classificada/
    while (fpont !=NULL && fpont -> proximo != NULL)
    {
        temp = fpont;
        while (temp->proximo != NULL )
        {
            if (fpont->data == temp->proximo->data )
            {
                repetido = temp->proximo;                    
                temp->proximo = temp->proximo->proximo;
                delete (repetido);
            }
            //Se na comparação não tiverem iguais ele vai para o próximo nodo
            else
            {
                temp = temp->proximo;
            }
        }
        fpont = fpont->proximo;
    }
} 
int main (int argc, char **argv) {   
   fstream arquivo;
   string palavra;
   if (argc < 2){
       cout << "Faltou passar o arquivo como argumento!\n";
       return 1;
   }
   //arg 1 é um arquivo com as palavras a ser aberto      
   arquivo.open(argv[1]);
   if (!arquivo.is_open()) { //Se retornar algum erro:
       cout << "Erro ao abrir o arquivo!\n";
       return 1;
   }
   Nodo* head = NULL; 
   // extrai todas as palavras e adiciona a lista:
   while (arquivo >> palavra)
       append(&head, palavra);
  
   cout << "ENTRADA:" << endl;
   printList(head);
   /* Aqui é chamada a função que filtra os dados duplicados */
   //Função pra detectar e apagar os nodos repetidos
   deletaRepetidos(head);
   cout << endl;
   cout << "RESULTADO REMOVENDO DUPLICADOS:" << endl;
   printList(head);
   return 0;
}

