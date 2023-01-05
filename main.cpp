//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa de avaliacao do TAD HEADERS
// Autor        : Marcelo Andrade
// Historico    : 2022-11-26 
//---------------------------------------------------------------------

#include "headers.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>
//#include <sys/resource.h>

using namespace std;

void imprimeSugestao();
int numeroPalavras(string);
bool palavraDupla(string);
void metodoAVL(string, string);
void metodoHASH(string, string);

int main(int argc, char* argv[]){

    if(argc < 6) {
        printf("Número de argumentos insuficientes. Digite comandos como do exemplo:\n");
        imprimeSugestao();
        return 1;
    }

    if(strcmp("-i", argv[1]) != 0){
        printf("Numero de argumentos insuficientes (falta Entrada). Os argumentos passados são invalidos, escreva\n");
        imprimeSugestao();
    }

    string _arquivoEntrada = argv[2];

    if(strcmp("-o", argv[3]) != 0){
        printf("Numero de argumentos insuficientes (falta Saida). Os argumentos passados são invalidos, escreva\n");
        imprimeSugestao();
    }

    string _arquivoSaida = argv[4];

    if(strcmp("-t", argv[5]) != 0){
        printf("Numero de argumentos insuficientes (falta Metodo). Os argumentos passados são invalidos, escreva\n");
        imprimeSugestao();
    }

    string metodo = argv[6];

    if(metodo == "arv"){
        metodoAVL(_arquivoEntrada, _arquivoSaida);
    }
    else if(metodo == "hash"){
        metodoHASH(_arquivoEntrada, _arquivoSaida);
    }

    return 0;
}

void imprimeSugestao(){
    printf("   bin/tp3 -i entrada.txt -o saida.txt -t arv\n");
    printf("   bin/tp3 -i entrada.txt -o saida.txt -t hash\n");

}

int numeroPalavras(string _linha){

    string aux;
    stringstream str;
    int contador = -1;

    str << _linha;

    while(str){

        str >> aux;
        contador++;
    }

    return contador;
}

bool palavraDupla(string linha){

    stringstream str;
    string p1, p2, p3;
    str << linha;

    str >> p1 >> p2 >> p3;

    p3.erase(0, (p3.length() - 1));

    if(p3 == "]"){
        return true;
    }
    else{
        return false;
    }
}

void metodoAVL(string _arquivoEntrada, string _arquivoSaida){

    string filename(_arquivoSaida);  //cria o arquivo aonde ira constar a saida
    fstream output_fstream;
    output_fstream.open(filename, std::ios_base::out);
    if(!output_fstream.is_open()){
        cout << "Falha ao abrir" << filename << endl;
    }

    string arquivoEntrada = _arquivoEntrada;

    ifstream arq;
    arq.open(arquivoEntrada);

    string linha, classe, palavra, significado;

    DicionarioAVL *a = NULL;

    while(getline(arq, linha)){

        stringstream str;

        str << linha;

        if(numeroPalavras(linha) > 2){
            if(palavraDupla(linha) == false){
                str >> classe >> palavra;
    
                string mensagem;
    
                while(str){
                    string aux;
                    str >> aux;
                    mensagem += aux;
                    mensagem += " ";
                }
                if(!mensagem.empty()){
                    mensagem.erase(mensagem.size() - 2);
                }
        
                significado = mensagem;
    
                palavra.erase(0, 1);
                if(!palavra.empty()){
                    palavra.erase(palavra.size() - 1);
                }
    
                if(a->Existe(a, palavra) == false){
                    string auxiliar;
                    auxiliar = significado;
                    Verbete _verbete;
                    _verbete.setPalavra(palavra);
                    _verbete.setClasse(classe);
                    _verbete.adicionaSignificado(auxiliar);
    
                    a = a->insereNo(a, _verbete);
                }
                else{
                    string auxiliar;
                    auxiliar = significado;
                    
                    a->alteraNo(a->Busca(a, palavra), auxiliar);
                }
            }
            else if(numeroPalavras(linha) > 3){
                string p1, p2;
                str >> classe >> p1 >> p2;
                palavra = p1 + " " + p2;

                string mensagem;
    
                while(str){
                    string aux;
                    str >> aux;
                    mensagem += aux;
                    mensagem += " ";
                }
                if(!mensagem.empty()){
                    mensagem.erase(mensagem.size() - 2);
                }
        
                significado = mensagem;
    
                palavra.erase(0, 1);
                if(!palavra.empty()){
                    palavra.erase(palavra.size() - 1);
                }
    
                if(a->Existe(a, palavra) == false){
                    string auxiliar;
                    auxiliar = significado;
                    Verbete _verbete;
                    _verbete.setPalavra(palavra);
                    _verbete.setClasse(classe);
                    _verbete.adicionaSignificado(auxiliar);
    
                    a = a->insereNo(a, _verbete);
                }
                else{
                    string auxiliar;
                    auxiliar = significado;
                    
                    a->alteraNo(a->Busca(a, palavra), auxiliar);
                }
            }
            else{
                string p1, p2;
                str >> classe >> p1 >> p2;
                palavra = p1 + " " + p2;

                palavra.erase(0, 1);
                if(!palavra.empty()){
                    palavra.erase(palavra.size() - 1);
                }
    
                if(a->Existe(a, palavra) == false){
                    Verbete _verbete;
                    _verbete.setPalavra(palavra);
                    _verbete.setClasse(classe);
    
                    a = a->insereNo(a, _verbete);
                }
                else{
                    //se existe nao faz nada
                }
            }
        }
        else if(numeroPalavras(linha) < 3){

            str >> classe >> palavra;

            palavra.erase(0, 1);
            if(!palavra.empty()){
                palavra.erase(palavra.size() - 1);
            }

            if(a->Existe(a, palavra) == false){
                Verbete _verbete;
                _verbete.setPalavra(palavra);
                _verbete.setClasse(classe);

                a = a->insereNo(a, _verbete);
            }
            else{
                //se existe nao faz nada
            }
        }
    }

    a->Imprime(a, _arquivoSaida);
    a->removeImprime(a, _arquivoSaida);
    
    a->destroiAVL(a);
}

void metodoHASH(string _arquivoEntrada, string _arquivoSaida){

    
    string filename(_arquivoSaida);  //cria o arquivo aonde ira constar a saida
    fstream output_fstream;
    output_fstream.open(filename, std::ios_base::out);
    if(!output_fstream.is_open()){
        cout << "Falha ao abrir" << filename << endl;
    }

    string arquivoEntrada = _arquivoEntrada;

    ifstream arq;
    arq.open(arquivoEntrada);

    string linha, classe, palavra, significado;

    DicionarioHash *a = new DicionarioHash();

    while(getline(arq, linha)){

        stringstream str;

        str << linha;

        if(numeroPalavras(linha) > 2){
            if(palavraDupla(linha) == false){
                str >> classe >> palavra;
    
                string mensagem;
    
                while(str){
                    string aux;
                    str >> aux;
                    mensagem += aux;
                    mensagem += " ";
                }
                if(!mensagem.empty()){
                    mensagem.erase(mensagem.size() - 2);
                }
        
                significado = mensagem;
    
                palavra.erase(0, 1);
                if(!palavra.empty()){
                    palavra.erase(palavra.size() - 1);
                }
    
                if(a->Existe(palavra) == false){
                    string auxiliar;
                    auxiliar = significado;
                    Verbete _verbete;
                    _verbete.setPalavra(palavra);
                    _verbete.setClasse(classe);
                    _verbete.adicionaSignificado(auxiliar);
    
                    a->Insere(_verbete);
                }
                else{
                    string auxiliar;
                    auxiliar = significado;
                    
                    a->adicionaSignificado(palavra, auxiliar);
                }
            }
            else if(numeroPalavras(linha) > 3){
                string p1, p2;
                str >> classe >> p1 >> p2;
                palavra = p1 + " " + p2;

                string mensagem;
    
                while(str){
                    string aux;
                    str >> aux;
                    mensagem += aux;
                    mensagem += " ";
                }
                if(!mensagem.empty()){
                    mensagem.erase(mensagem.size() - 2);
                }
        
                significado = mensagem;
    
                palavra.erase(0, 1);
                if(!palavra.empty()){
                    palavra.erase(palavra.size() - 1);
                }
    
                if(a->Existe(palavra) == false){
                    string auxiliar;
                    auxiliar = significado;
                    Verbete _verbete;
                    _verbete.setPalavra(palavra);
                    _verbete.setClasse(classe);
                    _verbete.adicionaSignificado(auxiliar);
    
                    a->Insere(_verbete);
                }
                else{
                    string auxiliar;
                    auxiliar = significado;
                    
                    a->adicionaSignificado(palavra, auxiliar);
                }
            }
            else{
                string p1, p2;
                str >> classe >> p1 >> p2;
                palavra = p1 + " " + p2;

                palavra.erase(0, 1);
                if(!palavra.empty()){
                    palavra.erase(palavra.size() - 1);
                }
    
                if(a->Existe(palavra) == false){
                    Verbete _verbete;
                    _verbete.setPalavra(palavra);
                    _verbete.setClasse(classe);
    
                    a->Insere(_verbete);
                }
                else{
                    //se existe nao faz nada
                }
            }
        }
        else if(numeroPalavras(linha) < 3){

            str >> classe >> palavra;

            palavra.erase(0, 1);
            if(!palavra.empty()){
                palavra.erase(palavra.size() - 1);
            }

            if(a->Existe(palavra) == false){
                Verbete _verbete;
                _verbete.setPalavra(palavra);
                _verbete.setClasse(classe);

                a->Insere(_verbete);
            }
            else{
                //se existe nao faz nada
            }
        }
    }

    a->imprimeHash(_arquivoSaida);
    a->removeVerbetes();
    a->imprimeHash(_arquivoSaida);
    a->destroiHash();
}