//Igor Butignon
//Caio Sousa

#include <iostream>

using namespace std;

struct Produto {
  string nome;
  int quantidade;
  double valor;
};

Produto produtos[10] = {
    {"Coca-Cola", 10, 5.50},
    {"Pepsi-Twist", 9, 5.00},
    {"Guaraná-Kuat", 6, 4.55},
    {"Fanta-Laranja", 5, 4.55},
    {"Heineken-600Ml", 2, 7.90},
};

void exibirProdutosADM() {
  int tamanho = sizeof(produtos) / sizeof(produtos[0]);
  cout << "Codigo \t\t Quantidade \t\t Nome" << endl;
  for (int i = 0; i < tamanho; i++) {
    if (produtos[i].nome != "") {
      cout << i << "\t\t\t\t" << produtos[i].quantidade << "\t\t\t\t" << produtos[i].nome << endl;
    }
  }
}

void exibirProdutosUSER() {
  int tamanho = sizeof(produtos) / sizeof(produtos[0]);
  cout << "Codigo \t\t Disponível \t\t Nome \t\t\t\t Preço" <<  endl;
  for (int i = 0; i < tamanho; i++) {
    if (produtos[i].nome != "") {
      cout << i << "\t\t\t\t" << produtos[i].quantidade << "\t\t\t\t" << produtos[i].nome << "\t\t R$ " << produtos[i].valor << endl;
    }
  }
}

void repor() {
  int quantidade, i, indice;
  string sair;

  do {
    exibirProdutosADM();
        
    cout << "Informe o codigo do produto que deseja repor:" << endl;
    cin >> i;
    system("clear");
    cout << "Produto selecionado: " << produtos[i].nome << "\nInforme a quantidade:" << endl;
    cin >> quantidade;
  
    produtos[i].quantidade += quantidade;
  
    cout << "Digite [S] para sair ou qualquer tecla para fazer uma nova reposição" << endl;
    cin >> sair;
    system("clear");
    
  } while (sair != "S" && sair != "s");
}

void adicionar() {
  string produto, sair;
  int quantidade, i = 0;
  double valor;

  do {
    while (produtos[i].nome != "") {
      i++;
    }
    
    cout << "Informe o nome do produto" << endl;
    cin >> produto;
    cout << "Adicione a quantidade" << endl;
    cin >> quantidade;
    cout << "Informe o valor do novo produto" << endl;
    cin >> valor;
  
    produtos[i] = {produto, quantidade, valor};
    system("clear");
    cout << "Produto: " << produtos[i].nome << endl;
    cout << "Quantidade: " << produtos[i].quantidade << endl;
    cout << "Valor unitario: " << "R$ " << produtos[i].valor << endl;
    cout << "Pressione qualquer tecla para dicionar um novo produto ou pressione [S] para confirmar e sair." << endl;
    cin >> sair;
    system("clear");
    
  } while (sair != "S" && sair != "s");
}

void admin() {

  string menu, lucros, sair, reposicao;
  int tamanho = sizeof(produtos) / sizeof(produtos[0]);

  cout << "Menu de seleção: \n[R]eposição\n[I]nventario\n[F]aturamento" << endl;
  cin >> menu;
  //=====MENU DE REPOSIÇÃO====//
  if (menu == "R" || menu == "r") {
    system("clear");
    cout << "Selecione:\n[R]eposição\n[A]dicionar novo produto" << endl;
    cin >> reposicao;

      if (reposicao == "R" || reposicao == "r"){
        system("clear");
        repor();
      }
      if (reposicao == "A" || reposicao == "a"){
        system("clear");
        adicionar();
      }
  }
  //=====MENU DE INVENTARIO ATUAL=====//
  else if (menu == "I" || menu == "i") {
    system("clear");
    string sair;
    
    do {
      cout << "Inventario:" << endl;
      exibirProdutosADM();
      cout << "Digite [S] para sair" << endl;
      cin >> sair;
      system("clear");
    } 
    while (sair != "S" && sair != "s");
  }
    
  //=====MENU DE FATURAMENTO=====//
  else if (menu == "F" || menu == "f") {
    system("clear");
    cout << "Você pode verificar os lucros atuais e os lucros futuros:" << endl;
    cout << "Selecione o metodo de verificação:\n[A]tuais\n[F]uturos" << endl;
    cin >> lucros;

    if (lucros == "A" || lucros == "a") {
      system("clear");
      cout << "Lucros atuais: " << endl;
      for (int i = 0; i < tamanho; i++) {
        if (produtos[i].nome != ""){
          cout << "R$ "  << produtos[i].quantidade * produtos[i].valor << "\t\t" <<produtos[i].nome << endl;
        }
      }
    cout << "Pressione qualquer tecla para sair" << endl;
    cin >> sair;
    
    } else if (lucros == "F" || lucros == "f") {
        system("clear");
        cout << "Lucros futuros: " << endl;

      for (int i = 0; i < tamanho; i++){
        if (produtos[i].nome != ""){
          cout << "R$ " << produtos[i].quantidade * produtos[i].valor << "\t\t" << produtos[i].nome << endl;
        }
      }
      cout << endl << "Digite qualquer tecla para sair:" << endl;
      cin >> sair;
      return;
      
    } else {
      cout << "Entrada inválida\n" << endl;
      admin();
    }
  }
}

void usuario() {
  int quantidade, i, indice,notas100, notas50, notas20, notas10, notas5, notas2, moedas100, moedas50, moedas25, moedas10, moedas5, moedas1, tempTroco;
  double valor=0, troco, dinheiro; 
  string sair, listaDeCompras="", senha, pagamento, finalizar;

  do {
    system("clear");
    exibirProdutosUSER();
    
    cout << "Digite o código do produto que deseja comprar" << endl;
    cin >> i;
    system("clear");
    cout << "Produto selecionado: " << produtos[i].nome << "\nInforme a quantidade:" << endl;
    cin >> quantidade;

    if (quantidade > produtos[i].quantidade){
      cout << "Quantidade indisponível" << endl;
      continue;
    }
    
    produtos[i].quantidade -= quantidade;
    valor += produtos[i].valor * quantidade; 
    listaDeCompras += produtos[i].nome + "\t\t\t" + to_string(quantidade) + "\t\t" + to_string(produtos[i].valor * quantidade) + "\n";
    system("clear");  
    cout << "Digite qualquer tecla para selecionar outro produto ou [F] para finalizar a compra" << endl;
    cin >> sair;
    system("clear");
    
  } while (sair != "F" && sair != "f");
  cout << "Nome \t\t\t\t Quantidade \t\t\t Preço" << endl;
  cout << listaDeCompras;
  cout << "Valor total da compra: \t\t\t R$ " << valor << endl;

  cout << "Selecione o metodo de pagamento:\n[C]artão\n[D]inheiro" << endl;
  cin >> pagamento;

  if (pagamento == "C" || pagamento =="c"){
    system("clear");
    cout << "Insira o cartão e digite sua senha" << endl;
    cin >> senha;
    cout << "Agradecemos a sua compra, volte sempre!" << endl;
    cout << "Digite qualquer tecla para sair." << endl;
    cin >> sair;
    return;
  }
  if (pagamento == "D" || pagamento == "d"){
    system("clear");
    cout << "Insira o valor no compartimento iluminado no painel" << endl;
    cin >> dinheiro;
    if (dinheiro < valor){
      system("clear");
      cout << "Valor insuficiente" << endl;
      cout << "Pressione qualquer tecla para sair" << endl;
      cin >> sair;
    }
    else if (dinheiro == valor){
      system("clear");
      cout << "Retire os produtos no compartimento abaixo.\nAgradecemos a sua compra, volte sempre!" << endl;
      cout << "Pressione qualquer tecla para finalizar" << endl;
      cin >> sair;
    }
    else{
      system("clear");
      troco = dinheiro - valor;
      cout << "Valor do troco R$ " << troco << endl;
      tempTroco = troco * 100;
      notas100 = tempTroco / 10000;
      tempTroco %= 10000;
      notas50 = tempTroco / 5000;
      tempTroco %= 5000;
      notas20 = tempTroco / 2000;
      tempTroco %= 2000;
      notas10 = tempTroco / 1000;
      tempTroco %= 1000;
      notas5 = tempTroco / 500;
      tempTroco %= 500;
      notas2 = tempTroco/ 200;
      tempTroco %= 200;
      moedas100 = tempTroco / 100;
      tempTroco %= 100;
      moedas50 = tempTroco / 50;
      tempTroco %= 50;
      moedas25 = tempTroco / 25;
      tempTroco %= 25;
      moedas10 = tempTroco / 10;
      tempTroco %= 10;
      moedas5 = tempTroco / 5;
      tempTroco %= 5;
      moedas1 = tempTroco / 1;
      tempTroco %= 1;
      cout << "Retire seu troco no compartimento iluminado" << endl;
      if (notas100 > 0){
        cout << "Nota de R$ 100,00: " << notas100 << endl;
      }
      if (notas50 > 0){
        cout << "Nota de R$ 50,00: " << notas50 << endl;
      }
      if (notas20 > 0){
        cout << "Nota de R$ 20,00: " << notas20 << endl;
      }
      if (notas10 > 0){
        cout << "Nota de R$ 10,00: " << notas10 << endl;
      }
      if (notas5 > 0){
        cout << "Nota de R$ 5,00: " << notas5 << endl;
      }
      if (notas2 > 0){
        cout << "Nota de R$ 2,00: " << notas2 << endl;
      }
      if (moedas100 > 0){
        cout << "Moeda de R$ 1,00: " << moedas100 << endl;
      }
      if (moedas50 > 0){
        cout << "Moeda de R$ 0,50: " << moedas50 << endl;
      }
      if (moedas25 > 0){
        cout << "Moeda de R$ 0,25: " << moedas25<< endl;
      }
      if (moedas10 > 0){
        cout << "Moeda de R$ 0,10: " << moedas10 << endl;
      }
      if (moedas5 > 0){
        cout << "Moeda de R$ 0,05: " << moedas5 << endl;
      }
      if (moedas1 > 0){
        cout << "Moeda de R$ 0,01: " << moedas1 << endl;
      }
      cout << "Pressione qualquer tecla para finalizar." << endl;
      cin >> finalizar;
      return;
    }
  }
}
  

int main() {

  string entrada, senha, sair;
    
  do {
    system("clear");
    cout << "Selecione a entrada:\n[U]suario\n[A]dministrador\n[S]air\n";
    cin >> entrada;
  
    if (entrada == "U" || entrada == "u") {
      usuario();
    }
    
    if (entrada == "A" || entrada == "a") {
      system("clear");
      cout << "Insira sua senha:" << endl;
      cin >> senha;
      system("clear");
      if (senha != "1234") {
        cout << "Senha invalida!" << endl;
        cout << "Pressione qualquer tecla para retornar" << endl;
        cin >> sair;
        continue;
        system("clear");
      }
      admin();     
    }
    
    if (entrada != "U" && entrada != "u" && entrada != "A" && entrada != "a" && entrada != "S" && entrada != "s") {
      cout << "Entrada incorreta";
    }    
  } while(entrada != "S" && entrada != "s");
  cout << "Até logo!";
  system ("clear");
  
  return 0;
}
