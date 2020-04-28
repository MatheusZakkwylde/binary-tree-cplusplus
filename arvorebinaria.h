#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include<iostream>
using namespace std;

/**
 * @brief Classe No
 */
class No {

private:
    /**
     * @brief esq - Ponteiro do No que apontara para seu filho da esquerda
     * @brief dir- Ponteiro do No que apontara para o seu filho da direita
     */
    No* esq;
    No* dir;
    int chave;

public:
    /**
     * @brief No - Construtor do No
     * @param chave - valor unico passado para o No
     * Como regra do No sempre o No da esquerda e da direita serão nulos
     */
    No (int chave){
       this->chave = chave;
       this->esq = NULL;
       this->dir = NULL;
    }

    void setEsq(No* no){
        this->esq = no;
    }

    No* getEsq(){
        return this->esq;
    }

    void setDir(No* no){
        this->dir = no;
    }

    No* getDir(){
        return this->dir;
    }

    int getChave (){
        return this->chave;
    }
};

/**
 * @brief ArvoreBinaria de busca ou de pesquisa class
 * Como regra, uma arvore Binaria sempre tera no maximo dois filhos
 * um a esquerda e um a direita. Pais com nenhum filho são chamados de nos folhas
 * Sempre o filho a esquerda tera que ser menor que o da direita
 */
class ArvoreBinaria{

private:
    /**
     * @brief raiz No raiz ou no cabeça da arvore
     */
    No* raiz;

public:

    ArvoreBinaria(){
        this->raiz = NULL;
    }

    ~ArvoreBinaria(){
       //this->limpar();
    }

    No* getRaiz(){
        return this->raiz;
    }

    bool inserir (int chave){
        //se o no raiz for null é porque não existe filhos e os valor é inserido no No raiz
        if(raiz == NULL){
            raiz = new No(chave);
            return true;
        }else{
           return inserirAux(raiz,chave);
        }
    }

    No* buscarElemento (No* no,int elemento){

        if(no == NULL || no->getChave() == elemento){
            return no;
        }

        if(no->getChave() > elemento){
            return buscarElemento(no->getEsq(),elemento);
        }else if (no->getChave() < elemento){
            return buscarElemento(no->getDir(),elemento);
        }

        return 0;
    }

    /**
     * @brief preOrdem - Função de busca em pre ordem
     * Regra - Imprime o no raiz
     *         Vai para esquerda imprimindo sempre o no raiz ou anterior até que encontre o no folha e seu proximo seja null
     *         segue para direita seguindo o mesmo procedimento
     * @param no ponteiro de No
     */
    void preOrdem(No* no){
       if(no != NULL){
           cout<<no->getChave()<<endl;
           preOrdem(no->getEsq());
           preOrdem(no->getDir());
       }
    }

    /**
     * @brief emOrdem - Função de busca em ordem
     * Regra - percorrer a arvore pela direita até que encontre o no folha e seu proximo seja null
     * quando for null imprime o no folha e seque para direita da mesma forma
     * @param no ponteiro de No
     */
    void emOrdem(No* no){
           if(no != NULL){
               emOrdem(no->getEsq());
               cout<<no->getChave()<<endl;
               emOrdem(no->getDir());
           }
    }

    /**
     * @brief posOrdem
     * Regra - percorrer todas as arvores da direita depois o lado esquerdo e depois imprime
     * @param no
     */
    void posOrdem(No* no){
        if(no != NULL){
            posOrdem(no->getEsq());
            posOrdem(no->getDir());
            cout<<no->getChave()<<endl;
        }
    }


    bool remover(No* no, int chave){

      if(no == NULL){ //se o valor não for encontrado retorna false
          return false;
      }

      if(chave < no->getChave()){ //se a chave for menor entra pela esquerda até encontrar o valor,ou não seja encontrado
          remover(no->getEsq(),chave);
      }else if(chave > no->getChave()){//se a chave maior entra pela direita até encontrar o valor, ou não seja encontrado
          remover(no->getDir(),chave);
      }else{//se não é maior e nem menor então é o numero que estou procurando
          No* aux = no; // recebe o valor a ser deletado

          if(no->getEsq() == NULL && no->getDir() == NULL){//Se ambos forem nulos é porque o numero não possui filhos e a arvore não precisa ser modificada
              delete aux;
              no = NULL;
              return true;
          }else{

              if(no->getEsq() == NULL){ //se o filho da esquerda for null então só tem o filho da direita
                  no = no->getDir();// então o no recebe o seu filho da direita
                  aux->setDir(NULL);// Apos o valor recebe seu valor da direita o novo valor tem seu filho como null pois ele não pode está nos dois locais
                  delete aux;
                  aux = NULL;
                  return true;
              }else if(no->getDir() == NULL){// Se o filho do no da direita for igual a null é porque só existe o filho da esquerda
                  no = no->getEsq();
                  aux->setEsq(NULL);
                  delete aux;
                  aux = NULL;
                  return true;
              }else{
                //escolhido ir pela esquerda então vou pegar seu maior valor da direita como regra da arvore
                //caso queira usar a outra função basta substitutuir aux = menorEsquerda(no->getDir());
                aux = maiorDireita(no->getEsq());
                aux->setEsq(no->getEsq());
                aux->setDir(no->getDir());
                no->setEsq(NULL);
                no->setDir(NULL);
                delete no;
                no = aux;
                aux = NULL;
                return true;
              }
          }
      }
    }
private:
    No* maiorDireita(No* no){
        if(no->getDir()!= NULL){ //enquando for difente de null desse até que o no folha o seu filho seja null
            return maiorDireita(no->getDir());
        }else {
           No* aux = no; //se o proximo da direita for null aux recebe seu pai
           if(no->getEsq() != NULL){ //caso o no filho da esquerda não seja null
               no = no->getEsq(); //o no recebe o no da esquerda para que os filhos do no da esquerda não seja perdido
           }else{//caso o no da esquerda seja nul então o no recebe nul pois não tem filhos
               no = NULL;
           }

           return aux;
        }
    };


    No* menorEsquerda (No* no){
        if(no->getEsq() != NULL){//enquando o no a esquerda for diferente de null desse a esquerda recursivamente
            return menorEsquerda(no->getEsq());
        }else{ // se o no a esquerda for null,aux recebe seu pai
            No* aux = no;
            if(no->getDir()!= NULL){//Se o no a direita for diferente de null ele passa a ser o pai no lugar do no porque se não ele perde os filhos
                no = no->getDir();
            }else{ //Se os filhos de no são nulos então no recebe null pois niguém ira substitui-lo
                no = NULL;
            }

            return aux;
        }
    };


    bool inserirAux(No* no,int chave){
        //se a chave for menor que a chave do no entra na esquerda
        if(chave < no->getChave()){
            //se o elemento for igual null ele recebe o novo no
            if(no->getEsq() == NULL){

                No* novo_No = new No(chave);
                no->setEsq(novo_No);
                return true;
            //se não for null vai decendo ate o no folha
            }else{

                inserirAux(no->getEsq(),chave);
            }
        //se a chave for maior que a chave o no entra na direita
        }else if(chave > no->getChave()){
            //se o no da direita for null ele recebe o novo no
            if(no->getDir() == NULL){

                No* novo_No = new No(chave);
                no->setDir(novo_No);
                return true;
            //se não ele desse  mais para o no folha
            }else{

                inserirAux(no->getDir(),chave);
            }
        }

        //se nem for maior e nem menor é porque é igual e não pode ser igual
        return false;
    }
};

void limpar(No* no){
    if(no != NULL){
        limpar(no->getEsq());
        limpar(no->getDir());
        delete no;
    }
};

#endif // ARVOREBINARIA_H
