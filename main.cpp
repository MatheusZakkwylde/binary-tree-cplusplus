#include <iostream>
#include "arvorebinaria.h"
using namespace std;

int main()
{
    ArvoreBinaria arvore;
    cout<<"Arvore Binaria de busca"<<endl;
    cout<<"          4   "<<endl<<endl;
    cout<<"    2          6"<<endl<<endl;
    cout<<"1      3    5     7"<<endl<<endl;

    arvore.inserir(4);
    arvore.inserir(6);
    arvore.inserir(2);
    arvore.inserir(3);
    arvore.inserir(1);
    arvore.inserir(5);
    arvore.inserir(7);

    cout<<"Listagem em preOrdem. Esperando: 4,2,1,3,6,5,7."<<endl;
    arvore.preOrdem(arvore.getRaiz());
    cout<<"Listagem em emOrdem. Esperando: 1,2,3,4,5,6,7."<<endl;
    arvore.emOrdem(arvore.getRaiz());
    cout<<"Listagem em PosOrdem. Esperando: 1,3,2,5,7,6,4."<<endl;
    arvore.posOrdem(arvore.getRaiz());

    cout<<"Buscando o valor na arvore"<<endl;
    cout<<"Valor 5:"<<endl;

    if(arvore.buscarElemento(arvore.getRaiz(),5)){
        cout<<"encontrado"<<endl;
    }else{
        cout<<"Não encontrado"<<endl;
    }

    cout<<"Valor 10:"<<endl;

    if(arvore.buscarElemento(arvore.getRaiz(),10)){
        cout<<"encontrado"<<endl;
    }else{
        cout<<"Não encontrado"<<endl;
    }

    cout<<arvore.remover(arvore.getRaiz(),2)<<endl ;

   return 0;
}

