//Exemplo adaptado de: geeksforgeeks
#include <iostream>
using namespace std;
  
// classe para nodo da pilha
class nodoPilha 
{
   public:
   string data;
   nodoPilha* proximo;
};
  
nodoPilha* novoNodo(string data) 
{
   nodoPilha* nodo = new nodoPilha();
   nodo->data = data;
   nodo->proximo = NULL;
   return nodo;
}
  
int isEmpty(nodoPilha *base) 
{
   return !base;
}
  
void push(nodoPilha** base, string novoItem)
{
   nodoPilha* nodo = novoNodo(novoItem);
   nodo->proximo = *base;
   *base = nodo;
   cout<<"Adicionado o valor: "<<novoItem<<endl;
}
  
void pop(nodoPilha** base){
   if (isEmpty(*base))
   exit;
   nodoPilha* temp = *base;
   *base = (*base)->proximo;
   string popped = temp->data;
   free(temp);
   cout<<"Valor removido: "<< popped << endl;
}
void imprimePilha(nodoPilha* base)
{
    if (isEmpty(base)){
       exit;
    }
    else {
        cout << "Os itens da pilha são: "<<endl;
        while (base != NULL) {
            cout<< base->data <<endl;
            base = base->proximo;
        }
    }
    cout << endl;
    exit;
}
bool verifica(string link) //Funçao pra verificar se começa com http
{
    int cont=0;
    char compara[]="http";
    for (size_t i=0; i < 4; i++)
    {
        if (compara[i]==link[i])
        {
            cont = cont +1;
        }
    }
    if (cont == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    nodoPilha* base = NULL;
    int opcao;
    cout << "SELECIONE A OPÇÃO DESEJADA:"<< endl;
    cout << "Digite 1 para ADICIONAR uma URL ao registro" << endl;
    cout << "Digite 2 para REMOVER o último registro" << endl;
    cout << "Digite 3 para IMPRIMIR todas as URLs salvas" << endl;
    cout << "Digite 4 para EXCLUIR várias URLs registradas (defina a quantidade)"<< endl;
    cout << "Digite 5 para FINALIZAR o programa."<< endl;
   
    cin >> opcao;    
   
    //fica repetindo enquanto não for 5
    int contUm =0; // contador para verificar numero de vezes que a função 1 foi usada
    while (true){
        if (opcao == 1)
        {   
            string link;
            
            cout << "Digite sua URL:" << endl;
            cin >> link; 
          
            verifica(link);//chama função de verificar

            if (verifica(link)==true) //entra se for igual a http
            {
                cout<<"URL válido"<< endl;
                push(&base, link);
                contUm = contUm+1;
            }
            else //entra se não for http no inicio
            {
                cout<<"URL inválido, digite um Url válido!"<< endl;
            }  
        }
        if (opcao == 2)
        {
            if (contUm ==0) //caso função 1 não for utiliada ele entra aqui avisando que não tem elementos
            {
                cout << "Lista vazia!Não existem elementos para remover."<< endl;
            }
            else
            {
                pop(&base);
                contUm = contUm -1; //diminui a contagem de itens
            }       
        }
        //Imprime a pilha
        if (opcao == 3)
        {
            imprimePilha(base);
        }
        //Esvaziar pilha
        if (opcao == 4)
        {   
            int casMaior, numUrls = 0;
            cout <<"Digite o número de URLs:"<<endl;
            cin >> numUrls; //le o numero de urls que quer apagar

            if (numUrls > contUm) //caso existam menos elementos na lista do que foi pedido para apagar define o numero de elementos existentes
            {
                casMaior = contUm;
                for (size_t i=0; i < contUm; i++)
                {
                    pop(&base);
                }
                cout << "Lista esvaziada!"<<endl;    
            }
            else //se o numero de urls for menor entra aqui
            {
                for (size_t i=0; i < numUrls; i++)
                {
                    pop(&base);
                }  
            }    
        }
        //Fechar programa
        if (opcao == 5)
        {
            return -1;
        }
        cout << "================================"<< endl;
        cout << "SELECIONE A OPÇÃO DESEJADA:"<< endl;
        if (opcao < 1 || opcao > 5)
        {
            cout << "Opção inexistente!"<< endl;
        }
        cin >> opcao;
    }
}

//Cite dois exemplos adicionais de aplicação do mundo real onde, na sua opinião,
// o trabalho 3 poderia ser aplicado e explique por qual motivo e como ele poderia
//resolver tais problemas.
 
//Poderia ser utilizado para um controle de estoque para supermercado/fábrica
//onde os produtos são estocados em pilhas, e os que são mais utilizados teriam que ser
//adicionados por último(para ficarem por cima), para que não fosse preciso remover
//todos os outros produtos de cima.
 
//Poderia ser utilizado em um estacionamento onde só é possível passar com um carro
//por vez, e os mesmos são colocados em fila, um atrás do outro, para que todos os
//funcionários conseguissem sair no seu horário e não terem problemas, o algoritmo
//iria definir qual carro deveria entrar primeiro e qual por último, para que o
//primeiro a chegar, fosse o último a sair.


