//---------------------------------------------------------------------
// Arquivo	    : headers.h
// Conteudo	    : definicoes do TAD HEADERS
// Autor	    : Marcelo Andrade
// Historico	: 2022-11-26
//---------------------------------------------------------------------

#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>

using namespace std;

class Significado{
    private:
        string texto;
        Significado *prox;  //atributo para manipulacao da lista

    public:
        //construtores
        Significado();

        //metodos basicos
        string getTexto();
        void setTexto(string);

    friend class Verbete;
};

class Verbete{
    private:
        string palavra;
        string classe;
        int contador;

        Significado *primeiro;  //atributo para manipulacao da lista
        Significado *ultimo;    //atributo para manipulacao da lista
        
    public:
        //contrutores
        Verbete();

        //metodos basicos
        string getPalavra();
        void setPalavra(string);
        string getClasse();
        void setClasse(string);
        void adicionaSignificado(string);
        void imprimeSignificados(string);
        int getContador();
};

class DicionarioAVL{
    private:
        Verbete verbete;
        string chave;
        int altura;

        DicionarioAVL *esq;     //atributo para manipulacao da arvore
        DicionarioAVL *dir;     //atributo para manipulacao da arvore
        

    public:
        //construtores
        DicionarioAVL();
        void destroiAVL(DicionarioAVL *);

        //metodos basicos
        int getAltura();
        void setAltura(int);
        DicionarioAVL *getEsq();
        void setEsq(DicionarioAVL *);
        DicionarioAVL *getDir();
        void setDir(DicionarioAVL *);

        //outros metodos
        int max(int, int);
        int Altura(DicionarioAVL *);
        DicionarioAVL *novoNo(Verbete);
        DicionarioAVL *rotacaoEsq(DicionarioAVL *);
        DicionarioAVL *rotacaoDir(DicionarioAVL *);
        int getFatorBalanco(DicionarioAVL *);
        DicionarioAVL *insereNo(DicionarioAVL *, Verbete);
        DicionarioAVL *valorMinimoNo(DicionarioAVL *);
        DicionarioAVL *deletaNo(DicionarioAVL *, Verbete);
        DicionarioAVL *Busca(DicionarioAVL *, string);
        bool Existe(DicionarioAVL *, string);
        void alteraNo(DicionarioAVL *, string);
        void Imprime(DicionarioAVL *, string);
        void removeImprime(DicionarioAVL *, string);
};

class Celula{
    private:
        Verbete verbete;
        Celula *prox;       //atributo para manipulacao da lista

    public:
        //construtores
        Celula();

    friend class Lista;
};

class Lista{
    private:
        Celula *primeiro;       //atributo para manipulacao da lista
        Celula *ultimo;         //atributo para manipulacao da lista

    public:
        //construtores
        Lista();
        void destroiLista();

        //outros metodos
        void insereOrdenado(Verbete);
        void removeVerbete(string);
        Verbete Pesquisa(string);
        void imprimeLista(string);
        bool Existe(string);
        Celula *Busca(string);
        void alteraCelula(string, string);
        void excluiVerbeteSignificado();
};

class DicionarioHash{
    private:
        static const int M = 26;
        int buscaLista(string);
        Lista Tabela[M];

    public:
        //construtores
        DicionarioHash();
        void destroiHash();

        //outros metodos
        Verbete Pesquisa(string);
        void Insere(Verbete);
        void Remove(string);
        void imprimeHash(string);
        bool Existe(string);
        void adicionaSignificado(string, string);
        void removeVerbetes();
};

#endif