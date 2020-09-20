## Algoritmos Evolutivos - Detector de valor máximo

Esse repositório tem como intuito guardar o algoritmo genético desenvolvido durante a disciplina de **SSC0713 - Sistemas Evolutivos e Aplicados à Robótica**. Esse algoritmo é um exemplo simples de como implemetar um AG (Algoritmo Genético) com o intuito de econtrar o valor máximo de uma determinada função complexa. Segue abaixo requisitos e breve explicação de como executar:

### Requisitos:
- CMake Version 3.5.1
- GCC 5.4.0
- C11 Standard Version
- OpenGL legacy

### Como executar:
- Clone o repositório e entre na pasta **build**, onde ficará os arquivos de configuração CMake: 
```console
cd build
```
- Exucete o comando cmake para configurar o ambiente:
```console
cmake ..
```
- Chame o make para compilar:
```console
make
```
- O arquivo executável será gerado **Executable.exe**, para executá-lo faça:
```console
./Executable
```

### Organização:
Segue a organização atual caso queira realizar contribuições:
- include : diretório em que fica os aquivos .h das classes
- build : diretório de configuração de ambiente do cmake
- src: diretório em que fica os arquivos .cpp para implementação
