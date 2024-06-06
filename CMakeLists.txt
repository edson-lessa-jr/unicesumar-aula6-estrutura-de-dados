cmake_minimum_required(VERSION 3.28)
project(unicesumar_aula6_estrutura_dados C)

set(CMAKE_C_STANDARD 11)

add_executable(unicesumar_aula6_estrutura_dados main.c
        01_pilha_lista_dinamica/01_pilha_lista_dinamica.c
        01_pilha_lista_dinamica/01_pilha_lista_dinamica.h
        02_fila_lista_dinamica/02_fila_lista_dinamica.h
        02_fila_lista_dinamica/02_fila_lista_dinamica.c)
