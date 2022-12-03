#include <iostream>
#include <queue>
using namespace std;

// mostrar o conteúdo da fila
void display_queue(queue<string> q);
void display_queue(queue<string> q) {
  while(!q.empty()) {
    cout << q.front() <<endl;
    q.pop();
  }
}
int main() {

    // cria uma fila do tipo string
    queue<string> cliente;
    string cliNome;
    int opcao;
    
    cout << "SELECIONE A OPÇÃO DESEJADA:"<< endl;
    cout << "Digite 1 para ADICIONAR um novo cliente no final da fila:" << endl;
    cout << "Digite 2 para REMOVER o cliente já atendido:" << endl;
    cout << "Digite 3 para IMPRIMIR todas os clientes que estão na fila:" << endl;
    cout << "Digite 4 para IMPRIMIR quantos clientes estão na fila:"<< endl;
    cout << "Digite 5 para FECHAR o caixa e limpar a fila:"<< endl;
   
    cin >> opcao;
    
    while (true){
        int size = cliente.size();
        //Adiciona o cliente no fim da fila
        if (opcao == 1)
        {   
            cout << "Digite o nome do cliente:" << endl;
            cin >> cliNome;
            cliente.push(cliNome);
            cout << "Cliente adicionado no final da fila!!" << endl;
        }
        //Remove o cliente que está na frente da fila
        if (opcao == 2)
        {
            cout << "Removendo cliente já atendido..." << endl;
            string front = cliente.front();
            cout << "Cliente: " << front << ", removido!"<< endl;
            cliente.pop();
        }
        //Imprime todos os clientes em espera
        if (opcao == 3)
        {
            cout << "Lista de clientes em espera:"<<endl;
            display_queue(cliente);
        }
        //Apresenta o número de clientes na fila
        if (opcao == 4)
        {   
            cout << "Número de clientes na fila: " << size << endl;
        }
        //Fechar programa
        if (opcao == 5)
        {
            cout << "Limpando fila..." << endl;
            while(!cliente.empty())  //esvazia a fila
            {
                cliente.pop();
            } 
            cout << "Caixa fechado!" << endl;
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
