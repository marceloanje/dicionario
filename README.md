# Dicionário de Palavras

## Descrição

Este trabalho propõe o projeto, codificação e avaliação de diferentes implementações de um dicionário de palavras. O dicionário deve suportar consultas, inserções, remoções, impressão ordenada e atualização de entradas. As implementações a serem comparadas incluem uma baseada em árvore de pesquisa balanceada (AVL) e outra baseada em tabela hash.
### Principais Funcionalidades

- **Consulta de Palavras:** Busca por palavras no dicionário.
- **Inserção e Remoção:** Adição e exclusão de palavras no dicionário.
- **Impressão Ordenada:** Visualização das palavras em ordem.
- **Atualização de Entradas:** Modificação dos significados associados a uma palavra.

---

## Complexidade Temporal e Espacial

### Complexidade Temporal

A complexidade temporal do programa é \( O(n^3) \), onde \( n \) representa a quantidade de operações realizadas. Isso indica que o tempo de execução do programa aumenta de forma cúbica à medida que a quantidade de operações ou elementos cresce.

### Complexidade Espacial

A complexidade espacial do programa é \( O(n^2) \), refletindo que a quantidade de memória utilizada cresce quadraticamente com o aumento da quantidade de elementos ou operações.

---

### Instruções de Execução

Para compilar e executar este programa, siga estas etapas:

#### Requisitos

Certifique-se de ter os seguintes requisitos instalados no seu sistema:

- **GCC**: Um compilador C++ para compilar o código.
- **Make**: Uma ferramenta de automação de compilação.

#### Passos

1. **Clone o Repositório**
   ```bash
   git clone https://github.com/marceloanje/dicionario.git
   ```

2. **Navegue até a pasta do Projeto**
   ```bash
   cd dicionario
   ```

3. **Compilação**       
   Execute o comando make na pasta raiz do projeto para compilar o código.
   ```bash
   make
   ```
   
4. **Exucução**       
   Após a compilação bem-sucedida, execute o programa.
   ```bash
   run.out -i entrada.txt -o saida.txt -t arv
   run.out -i entrada.txt -o saida.txt -t hash
   ```

---

### Mais Detalhes

Um documento PDF contendo detalhes adicionais sobre o sistema está disponível [aqui](https://github.com/marceloanje/servidor_emails/blob/main/Documentacao.pdf). Esse documento oferece uma visão mais abrangente do projeto, incluindo descrições detalhadas, especificações técnicas e outras informações relevantes.
