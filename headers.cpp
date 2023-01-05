//---------------------------------------------------------------------
// Arquivo	    : headers.cpp
// Conteudo	    : implementacao do TAD HEADERS
// Autor	    : Marcelo Andrade
// Historico	: 2022-11-26
//---------------------------------------------------------------------

#include "headers.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

const int NUM = 31;

//*******************SIGNIFICADO*******************

//contrutor default - inicia a classe Significado sem argumentos
//entrada:
//saida:
Significado::Significado(){}

//metodo get para texto - retorna o valor de texto
//entrada:
//saida: texto
string Significado::getTexto(){

    return texto;
}

//metodo set para texto - altera o valor de texto
//entrada: string
//saida:
void Significado::setTexto(string _texto){

    texto = _texto;
}


//*******************VERBETE*******************

//contrutor default - inicia a classe Verbete sem argumentos
//entrada:
//saida:
Verbete::Verbete(){

    primeiro = NULL;
    ultimo = primeiro;
    contador = 0;
}

//metodo get para palavra - retorna o valor de palavra
//entrada:
//saida: palavra
string Verbete::getPalavra(){

    return palavra;
}

//metodo set para palavra - altera o valor de palavra
//entrada: string
//saida:
void Verbete::setPalavra(string _palavra){

    palavra = _palavra;
}

//metodo get para classe - retorna o valor de classe
//entrada:
//saida: classe
string Verbete::getClasse(){

    return classe;
}

//metodo set para classe - altera o valor de classe
//entrada: string
//saida:
void Verbete::setClasse(string _classe){

    classe = _classe;
}

//metodo adiciona significado - adiciona um significado ao final da lista
//entrada: string
//saida:
void Verbete::adicionaSignificado(string texto){

    Significado *aux, *novo = new Significado();

    novo->texto = texto;
    novo->prox = NULL;

    if(primeiro == NULL){
        primeiro = novo;
        ultimo = novo;
    }
    else{
        ultimo->prox = novo;
        ultimo = novo;
    }
    contador++;
}

//metodo imprime significado - imprime os significados em ordem FIFO para um arquivo
//entrada: string
//saida:
void Verbete::imprimeSignificados(string arquivoSaida){

    string filename(arquivoSaida);
    fstream output_fstream;
    output_fstream.open(filename, std::ios_base::app);

    int cont = 1;
    
    Significado *aux = primeiro;

    if(primeiro == NULL){
    }
    else{
        while(aux){
            output_fstream << cont << ". " << aux->getTexto() << endl;
            cont++;
            aux = aux->prox;
        }
    }
    output_fstream.close();
}

//metodo get para contador - retorna o valor de contador
//entrada:
//saida: contador
int Verbete::getContador(){

    return contador;
}


//*******************DICIONARIOAVL*******************

//contrutor default - inicia a classe DicionarioAVL sem argumentos
//entrada:
//saida:
DicionarioAVL::DicionarioAVL(){

    esq = NULL;
    dir = NULL;
}

//metodo destroi avl - libera espaço de memoria alocado
//entrada:
//saida:
void DicionarioAVL::destroiAVL(DicionarioAVL *no){
    
    if (no == NULL) 
        return;
    destroiAVL(no->esq);
    destroiAVL(no->dir);
    delete no;
}

//metodo get para altura - retorna o valor de altura
//entrada:
//saida: altura
int DicionarioAVL::getAltura(){

    return altura;
}

//metodo set para altura - altera o valor de altura
//entrada: int
//saida:
void DicionarioAVL::setAltura(int _altura){

    altura = _altura;
}

//metodo get para esq - retorna o valor de esq
//entrada:
//saida: esq
DicionarioAVL *DicionarioAVL::getEsq(){

    return esq;
}

//metodo set para esq - altera o valor de esq
//entrada: ponteiro de DicionarioAVL
//saida:
void DicionarioAVL::setEsq(DicionarioAVL *no){

    esq = no;
}

//metodo get para dir - retorna o valor de dir
//entrada:
//saida: dir
DicionarioAVL *DicionarioAVL::getDir(){

    return dir;
}

//metodo set para dir - altera o valor de dir
//entrada: ponteiro de DicionarioAVL
//saida:
void DicionarioAVL::setDir(DicionarioAVL *no){

    dir = no;
}

//metodo max - retorna o maior valor entre dois inteiros
//entrada: int e int
//saida: maior dos inteiros
int DicionarioAVL::max(int a, int b){

    return (a > b) ? a : b;
}

//metodo altura - retorna a altura do no
//entrada: ponteiro de DicionarioAVL
//saida: int
int DicionarioAVL::Altura(DicionarioAVL *no){

    if (no == NULL){
        return 0;
    }
    else{
        return no->getAltura();
    }
}

//metodo novo no - cria um novo no
//entrada: verbete
//saida: no
DicionarioAVL *DicionarioAVL::novoNo(Verbete verbete){

    DicionarioAVL *no = new DicionarioAVL();
    no->chave = verbete.getPalavra();
    no->altura = 1;
    no->verbete = verbete;

    return no;
}

//metodo rotaciona para esquerda - rotaciona o no para esquerda
//entrada: ponteiro de DicionarioAVL
//saida: no
DicionarioAVL *DicionarioAVL::rotacaoEsq(DicionarioAVL *no){

    DicionarioAVL *aux = no->getDir();
    DicionarioAVL *aju = aux->getEsq();

    aux->setEsq(no);
    no->setDir(aju);
    no->setAltura(max(Altura(no->getEsq()), Altura(no->getDir()) + 1));
    aux->setAltura(max(Altura(aux->getEsq()), Altura(aux->getDir()) + 1));

    return aux;
}

//metodo rotaciona para direita - rotaciona o no para direita
//entrada: ponteiro de DicionarioAVL
//saida: no
DicionarioAVL *DicionarioAVL::rotacaoDir(DicionarioAVL *no){

    DicionarioAVL *aux = no->getEsq();
    DicionarioAVL *aju = aux->getDir();

    aux->setDir(no);
    no->setEsq(aju);
    no->setAltura(max(Altura(no->getEsq()), Altura(no->getDir()) + 1));
    aux->setAltura(max(Altura(aux->getEsq()), Altura(aux->getDir()) + 1));

    return aux;
}

//metodo get fator de balanco - retorna o fator de balanco
//entrada: ponteiro de DicionarioAVL
//saida: int
int DicionarioAVL::getFatorBalanco(DicionarioAVL *no){

    if(no == NULL){
        return 0;
    }
    else{
        return Altura(no->getEsq()) - Altura(no->getDir());
    }
}

//metodo insere no - insere novo no na arvore
//entrada: ponteiro de DicionarioAVL e verbete
//saida: int
DicionarioAVL *DicionarioAVL::insereNo(DicionarioAVL *no, Verbete verbete){

    if(no == NULL){
        return novoNo(verbete);
    }
    if(verbete.getPalavra() < no->chave){
        no->esq = insereNo(no->esq, verbete);
    }
    else if(verbete.getPalavra() > no->chave){
        no->dir = insereNo(no->dir, verbete);
    }
    else{
        return no;
    }

    no->altura = 1 + max(Altura(no->esq), Altura(no->dir));
    int fatorBalanco = getFatorBalanco(no);
    if(fatorBalanco > 1){
        if(verbete.getPalavra() < no->esq->chave){
            return rotacaoDir(no);
        }
        else if(verbete.getPalavra() > no->esq->chave){
            no->esq = rotacaoEsq(no->esq);
            return rotacaoDir(no);
        }
    }
    if(fatorBalanco < -1){
        if(verbete.getPalavra() > no->dir->chave){
            return rotacaoEsq(no);
        }
        else if(verbete.getPalavra() < no->dir->chave){
            no->dir = rotacaoDir(no->dir);
            return rotacaoEsq(no);
        }
    }

    return no;
}

//metodo valor mininimo - retorna o no com valor minimo
//entrada: ponteiro de DicionarioAVL
//saida: no
DicionarioAVL *DicionarioAVL::valorMinimoNo(DicionarioAVL *no){

    DicionarioAVL *aux = no;

    while(aux->esq != NULL){
        aux = aux->esq;
    }

    return aux;
}

//metodo deleta no - deleta um no
//entrada: ponteiro de DicionarioAVL e verbete
//saida: no
DicionarioAVL *DicionarioAVL::deletaNo(DicionarioAVL *no, Verbete verbete){

    if(no == NULL){
        return no;
    }
    if(verbete.getPalavra() < no->chave){
        no->esq = deletaNo(no->esq, verbete);
    }
    else if(verbete.getPalavra() > no->chave){
        no->dir = deletaNo(no->dir, verbete);
    }
    else{
        if(no->esq == NULL || no->dir == NULL){
            DicionarioAVL *temp = no->esq ? no->esq : no->dir;
            if(temp == NULL){
                temp = no;
                no = NULL;
            }
            else{
                *no = *temp;
            }
            free(temp);
        }
        else{
            DicionarioAVL *temp = valorMinimoNo(no->dir);
            no->chave = temp->chave;
            Verbete aux;
            aux.setPalavra(temp->chave);
            no->dir = deletaNo(no->dir, aux);
        }
    }

    if(no == NULL){
        return no;
    }

    no->altura = 1 + max(Altura(no->esq), Altura(no->dir));
    int fatorBalanco = getFatorBalanco(no);
    if(fatorBalanco > 1){
        if(getFatorBalanco(no->esq) >= 0){
            return rotacaoDir(no);
        }
        else{
            no->esq = rotacaoEsq(no->esq);
            return rotacaoDir(no);
        }
    }

    return no;
}

//metodo busca - busca um no
//entrada: ponteiro de DicionarioAVL e string
//saida: no
DicionarioAVL *DicionarioAVL::Busca(DicionarioAVL *no, string str){

    if(no == NULL){
        return NULL;
    }
    else if(str < no->verbete.getPalavra()){
        return Busca(no->esq, str);
    }
    else if(str > no->verbete.getPalavra()){
        return Busca(no->dir, str);
    }
    return no;
}

//metodo booleano existe - verifica se um no existe
//entrada: ponteiro de DicionarioAVL e string
//saida: true ou false
bool DicionarioAVL::Existe(DicionarioAVL *no, string str){

    DicionarioAVL *aux = Busca(no, str);
    if(aux == NULL){
        return false;
    }
    else{
        return true;
    }
}

//metodo altera no - modifica um no
//entrada: ponteiro de DicionarioAVL e string
//saida:
void DicionarioAVL::alteraNo(DicionarioAVL *no, string _significado){

    no->verbete.adicionaSignificado(_significado);
}

//metodo imprime - imprime todos os nos da arvore para um arquivo
//entrada: ponteiro de DicionarioAVL e string
//saida:
void DicionarioAVL::Imprime(DicionarioAVL *no, string arquivoSaida){
    
    if(no != NULL){
        Imprime(no->esq, arquivoSaida);

        string filename(arquivoSaida);
        fstream output_fstream;
        output_fstream.open(filename, std::ios_base::app);
        
        output_fstream << no->chave << " (" << no->verbete.getClasse() << ")" << endl;
        output_fstream.close();
        
        no->verbete.imprimeSignificados(arquivoSaida);
        Imprime(no->dir, arquivoSaida);
    }
}

//metodo remove imprime - remove os nos com significado e imprime todos os nos da arvore para um arquivo
//entrada: ponteiro de DicionarioAVL e string
//saida:
void DicionarioAVL::removeImprime(DicionarioAVL *no, string arquivoSaida){
    
    if(no != NULL){
        removeImprime(no->esq, arquivoSaida);

        if(no->verbete.getContador() == 0){
            string filename(arquivoSaida);
            fstream output_fstream;
            output_fstream.open(filename, std::ios_base::app);
            output_fstream << no->chave << " (" << no->verbete.getClasse() << ")" << endl;
            output_fstream.close();
            no->verbete.imprimeSignificados(arquivoSaida);
        }

        removeImprime(no->dir, arquivoSaida);
    }
}

//*******************CELULA*******************
//contrutor default - inicia a classe Celula sem argumentos
//entrada:
//saida:
Celula::Celula(){};


//*******************LISTA*******************
//contrutor default - inicia a classe Lista sem argumentos
//entrada:
//saida:
Lista::Lista(){
    primeiro = NULL;
    ultimo = primeiro;
};

//metodo destroi lista - libera espaço de memoria alocado
//entrada:
//saida:
void Lista::destroiLista(){
    Celula *atual = primeiro;
    while (atual != NULL) {
        Celula *proximo = atual->prox;
        delete atual;
        atual = proximo;
    }
    primeiro = NULL;
}

//metodo pesquisa - pesquisa uma celula na lista
//entrada: string
//saida: celula
Verbete Lista::Pesquisa(string chave){

    Verbete aux;
    Celula *p;

    p = primeiro->prox;
    while(p != NULL){
        if(p->verbete.getPalavra() == chave){
            aux = p->verbete;
            break;
        }
        p = p->prox;
    }
    return aux;
}

//metodo insere ordenado - insere uma celula na lista ordenando
//entrada: verbete
//saida:
void Lista::insereOrdenado(Verbete verbete){

    Celula *aux, *nova = new Celula();

    nova->verbete = verbete;

    if(primeiro == NULL){
        nova->prox = NULL;
        primeiro = nova;
    }
    else if(nova->verbete.getPalavra() < primeiro->verbete.getPalavra()){
        nova->prox = primeiro;
        primeiro = nova;
    }
    else{
        aux = primeiro;

        while(aux->prox && nova->verbete.getPalavra() > aux->prox->verbete.getPalavra())
                aux = aux->prox;
            nova->prox = aux->prox;
            aux->prox = nova;
        
    }
}

//metodo remove verbete - remove uma celula da lista
//entrada: string
//saida:
void Lista::removeVerbete(string chave){

    Celula *aux, *remover = NULL;

    if(primeiro->verbete.getPalavra() == chave){
        remover = primeiro;
        primeiro = remover->prox;
    }
    else{
        aux = primeiro;
        
        while(aux->prox && aux->prox->verbete.getPalavra() != chave)
            aux = aux->prox;
        if(aux->prox){
            remover = aux->prox;
            aux->prox = remover->prox;
        }
    }
}

//metodo imprime - imprime todas as celulas para um arquivo
//entrada: string
//saida:
void Lista::imprimeLista(string arquivoSaida){

    Celula *aux = primeiro;

    if(primeiro == NULL){
    }
    else{
        while(aux){
            string filename(arquivoSaida);
            fstream output_fstream;
            output_fstream.open(filename, std::ios_base::app);
            output_fstream << aux->verbete.getPalavra() << " (" << aux->verbete.getClasse() << ")" << endl;
            output_fstream.close();

            aux->verbete.imprimeSignificados(arquivoSaida);
            aux = aux->prox;
        }
    }
}

//metodo booleano existe - verifica se uma celula existe
//entrada: string
//saida: true ou false
bool Lista::Existe(string str){

    Celula *aux = primeiro;
    
    while(aux){
	    if(aux->verbete.getPalavra() == str)
		    return true;
		aux = aux->prox;
	}
	return false;
}

//metodo busca - busca uma celula na lista
//entrada: string
//saida: celula
Celula *Lista::Busca(string str){

    Celula *aux = primeiro;
    
    while(aux){
	    if(aux->verbete.getPalavra() == str)
		    return aux;
		aux = aux->prox;
	}
}

//metodo altera celula - altera uma celula na lista
//entrada: string e string
//saida:
void Lista::alteraCelula(string str, string significado){

    Celula *cel = Busca(str);
    
    cel->verbete.adicionaSignificado(significado);
}

//metodo exclui verbete significado - exclui todas celulas cujo verbetes nao tem lista vazia
//entrada:
//saida:
void Lista::excluiVerbeteSignificado(){

    Celula *aux = primeiro;
    
    while(aux){
	    if(aux->verbete.getContador() > 0)
		    removeVerbete(aux->verbete.getPalavra());
		aux = aux->prox;
	}
}

//*******************DICIONARIOHASH*******************

//metodo busca lista - retorna em qual lista deve se tratar
//entrada: string
//saida: int
int DicionarioHash::buscaLista(string palavra){

    string aux = palavra;
    if(!aux.empty()){
        aux.erase(aux.size() - (aux.size() - 1));
    }

    if(aux == "A" || "B" || "C" || "D" || "E" || "F" || "G" || "H" || "I" || "J" || "K" 
    || "L" || "M" || "N" || "O" || "P" || "Q" || "R" || "S" || "T" || "U" || "V" || "W" || "X" || "Y" || "Z"){
        return 0;
    }

    int posi;
    posi = (aux[0] & NUM);

    return posi;
}

//contrutor default - inicia a classe Lista sem argumentos
//entrada:
//saida:
DicionarioHash::DicionarioHash(){}

//metodo destroi dicionario hash - destroi o dicionario
//entrada:
//saida:
void DicionarioHash::destroiHash(){

    for(int i = 0; i < 27; i++){
        Tabela[i].destroiLista();
    } 
}

//metodo busca lista - retorna em qual lista deve se tratar
//entrada: string
//saida: int
Verbete DicionarioHash::Pesquisa(string palavra){

    int posi;
    Verbete item;

    posi = buscaLista(palavra);
    item = Tabela[posi].Pesquisa(palavra);
    
    return item;
}

//metodo insere - adiciona verbete na tabela
//entrada: verbete
//saida:
void DicionarioHash::Insere(Verbete verbete){

    Verbete aux;
    int posi;

    posi = buscaLista(verbete.getPalavra());
    Tabela[posi].insereOrdenado(verbete);
}

//metodo remove - remove verbete da tabela
//entrada: string
//saida:
void DicionarioHash::Remove(string chave){

    int posi;

    posi = buscaLista(chave);
    Tabela[posi].removeVerbete(chave);
}

//metodo imprime hash - imprime toda a tabela
//entrada: string
//saida:
void DicionarioHash::imprimeHash(string arquivoSaida){

    for(int i = 0; i < 27; i++){
        Tabela[i].imprimeLista(arquivoSaida);
    }
}

//metodo booleano existe - verifica o verbete existe na tabela
//entrada: string
//saida: true ou false
bool DicionarioHash::Existe(string str){

    int posi;
    bool retorno;

    posi = buscaLista(str);
    retorno = Tabela[posi].Existe(str);

    return retorno;
}

//metodo adiciona significado - adiciona significado a um verbete da tabela
//entrada: string e string
//saida:
void DicionarioHash::adicionaSignificado(string str, string significado){

    int posi;

    posi = buscaLista(str);
    Tabela[posi].alteraCelula(str, significado);
    
}

//metodo remove verbetes - remove os verbetes da tabela
//entrada:
//saida:
void DicionarioHash::removeVerbetes(){

    for(int i = 0; i < 27; i++){
        Tabela[i].excluiVerbeteSignificado();
    }
}