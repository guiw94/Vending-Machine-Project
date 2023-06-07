#include <iostream>

using namespace std;

struct Produto {
  int quantidade_max;
  string nome;
  int quantidade;
  double valor;
};

Produto produtos[] = {
    {10, "Coca Cola", 10, 5.50},     {10, "Pepsi", 9, 5.00},
    {10, "Guaraná Kuat", 6, 4.55},   {10, "Fanta Laranja", 5, 4.55},
    {10, "Heineken 600Ml", 2, 7.90},

};

void admin() {

  string menu, lucros, sair;

  cout << "Menu de seleção: \n[R]eposição\n[I]nventario\n[F]aturamento" << endl;
  cin >> menu;
  //=====MENU DE REPOSIÇÃO====//
  if (menu == "R" || menu == "r") {
    cout << "reposição teste";

  }
  //=====MENU DE INVENTARIO ATUAL=====//
  else if (menu == "I" || menu == "i") {
    cout << "Inventario:" << endl;
    cout << produtos[0].nome << "(" << produtos[0].quantidade << ")" << endl;
    cout << produtos[1].nome << "(" << produtos[1].quantidade << ")" << endl;
    cout << produtos[2].nome << "(" << produtos[2].quantidade << ")" << endl;
    cout << produtos[3].nome << "(" << produtos[3].quantidade << ")" << endl;
    cout << produtos[4].nome << "(" << produtos[4].quantidade << ")" << endl;
  }
  //=====MENU DE FATURAMENTO=====//
  else if (menu == "F" || menu == "f") {
    cout << "Você pode verificar os lucros atuais e os lucros futuros:" << endl;
    cout << "Selecione o metodo de verificação:\n[A]tuais\n[F]uturos" << endl;
    cin >> lucros;

    if (lucros == "A" || lucros == "a") {
      cout << "Lucros atuais: " << endl;
      cout << produtos[0].nome << " R$ "
           << (produtos[0].quantidade_max - produtos[0].quantidade) *
                  produtos[0].valor
           << endl;
      cout << produtos[1].nome << " R$ "
           << (produtos[1].quantidade_max - produtos[1].quantidade) *
                  produtos[1].valor
           << endl;
      cout << produtos[2].nome << " R$ "
           << (produtos[2].quantidade_max - produtos[2].quantidade) *
                  produtos[2].valor
           << endl;
      cout << produtos[3].nome << " R$ "
           << (produtos[3].quantidade_max - produtos[3].quantidade) *
                  produtos[3].valor
           << endl;
      cout << produtos[4].nome << " R$ "
           << (produtos[4].quantidade_max - produtos[4].quantidade) *
                  produtos[4].valor
           << endl;
    } else if (lucros == "F" || lucros == "f") {
      cout << "Lucros futuros: " << endl;
      cout << produtos[0].nome << " R$ "
           << produtos[0].quantidade * produtos[0].valor << endl;
      cout << produtos[1].nome << " R$ "
           << produtos[1].quantidade * produtos[1].valor << endl;
      cout << produtos[2].nome << " R$ "
           << produtos[2].quantidade * produtos[2].valor << endl;
      cout << produtos[3].nome << " R$ "
           << produtos[3].quantidade * produtos[3].valor << endl;
      cout << produtos[4].nome << " R$ "
           << produtos[4].quantidade * produtos[4].valor << endl;
      cout << endl
           << "Digite [V] para voltar para o Menu de administrador ou qualquer "
              "tecla para sair:"
           << endl;
      cin >> sair;

      if (sair == "V" || sair == "v") {
        cout << endl;
        admin();
      } else {
        cout << "falta o retorno";
      }
    } else {
      cout << "Entrada inválida\n" << endl;
      admin();
    }
  }
}

void usuario() {

  string menu;

  cout << "Escolha o item que deseja:";
}

int main() {
  cout << "Estruturas de repeticao";

  int i = 0;
  while(i < 10) {
    cout << i;
    i++;
  }
}

// int main() {

//   string entrada, senha;

//   cout << "Selecione a entrada:\n[U]suario\n[A]dministrador\n";
//   cin >> entrada;

//   if (entrada == "U" || entrada == "u") {
//     cout << "entrando";
//   } else if (entrada == "A" || entrada == "a") {
//     cout << "Insira sua senha: ";
//     cin >> senha;

//     if (senha == "1234") {
//       admin();
//     } else {
//       cout << "Senha Inválida";
//     }
//   } else {
//     cout << "Entrada incorreta";
//   }

//   return 0;
// }
