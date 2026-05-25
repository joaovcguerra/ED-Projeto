# ED-Projeto

## Membros
### João Vitor
### João Gabriel
### Renato Hideki

## Como Compilar e Executar

O projeto é composto por um único arquivo fonte principal (`main.c`) e não possui dependências externas.

### Opção 1: Via CLion
O Projeto foi feito inteiramente através do Clion (IDE da Jetbrains).

1. Abra a pasta do projeto diretamente no CLion.
2. Certifique-se de que o arquivo `CMakeLists.txt` na raiz do projeto contenha o seguinte formato (atenção ao nome `main.c` em minúsculo):
   ```cmake
   cmake_minimum_required(VERSION 4.2)
   project(ED_Projeto C)
   
   set(CMAKE_C_STANDARD 11)
   
   add_executable(ED_Projeto 
           main.c)
   ```
3. Aguarde alguns segundos para que o CLion carregue e indexe o perfil do CMake.
4. Clique no botão de **"Play"** (Run) verde no canto superior direito da tela (ou pressione `Shift + F10`). O menu interativo aparecerá no console inferior da IDE.


### Opção 2: Via VS Code / Terminal
Não utilizamos o VsCode na hora de desenvolver o projeto, então rodar por ele não é o recomendado.

1. Abra a pasta do projeto no VS Code.
2. Abra um novo Terminal (`Ctrl + '` ou `Terminal > New Terminal`).
3. Compile o código executando o comando abaixo:
   ```bash
   gcc main.c -o sistema_hash
   ```
4. Execute o programa gerado:
    - No **Windows**: `.\sistema_hash.exe`
    - No **Linux/macOS**: `./sistema_hash`