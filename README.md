# 📊 Push_swap - Algoritmos de Ordenação para Pilhas

![Push_swap](https://img.shields.io/badge/Language-C-blue) ![Makefile](https://img.shields.io/badge/Tool-Makefile-yellow) ![Norminette](https://img.shields.io/badge/Style-Norminette-green)

O projeto **Push_swap** desafia os estudantes a desenvolver algoritmos de classificação eficientes para ordenar uma pilha de números inteiros em ordem ascendente, utilizando um conjunto limitado de instruções. Este projeto é uma introdução prática a conceitos avançados como algoritmos de ordenação, manipulação de pilhas e otimização.

---

## 📋 Objetivo do Projeto

🔹 Criar dois programas principais:  
1. Um programa para ordenar uma pilha de números inteiros.  
2. Um programa que verifica se um conjunto de instruções ordena a pilha corretamente.  

🔹 **Desenvolver algoritmos de ordenação eficientes** para diferentes tamanhos de entrada.  
🔹 Trabalhar com **manipulação de pilhas** e implementar operações específicas.  
🔹 Focar na **otimização** para minimizar o número de operações e reduzir a complexidade temporal.

---

## 📚 Conceitos Principais

- 📊 **Algoritmos de Ordenação**: implementar técnicas de classificação customizadas e eficientes.  
- 📂 **Manipulação de Pilhas**: operações de push, pop, swap e rotacionar elementos.  
- 🔄 **Otimização de Algoritmos**: reduzir o número total de instruções usadas para ordenar a pilha.  
- ⏱️ **Complexidade Temporal**: avaliar e melhorar o desempenho dos algoritmos implementados.  

---

## ✨ Funcionalidades Implementadas

### 🔧 Operações Básicas de Pilha
- `sa` → Troca os dois primeiros elementos da pilha `a`.  
- `sb` → Troca os dois primeiros elementos da pilha `b`.  
- `ss` → Troca os dois primeiros elementos de ambas as pilhas simultaneamente.  
- `pa` → Move o primeiro elemento do topo da pilha `b` para o topo da pilha `a`.  
- `pb` → Move o primeiro elemento do topo da pilha `a` para o topo da pilha `b`.  
- `ra` → Rotaciona todos os elementos da pilha `a` para cima.  
- `rb` → Rotaciona todos os elementos da pilha `b` para cima.  
- `rr` → Rotaciona ambas as pilhas para cima simultaneamente.  
- `rra` → Rotaciona todos os elementos da pilha `a` para baixo.  
- `rrb` → Rotaciona todos os elementos da pilha `b` para baixo.  
- `rrr` → Rotaciona ambas as pilhas para baixo simultaneamente.  

### 🛠️ Estrutura dos Programas
1. **Ordenador de Pilha (`push_swap`)**:  
   - Recebe uma lista de números como entrada e retorna a sequência mínima de operações para ordená-la.  

2. **Validador de Instruções (`checker`)**:  
   - Verifica se um conjunto de operações aplicado a uma pilha resulta em uma pilha ordenada.  

### 🔄 Algoritmos de Ordenação
- **Ordenação para pequenas entradas**: abordagem direta para 3 a 5 elementos.  
- **Algoritmos otimizados para grandes entradas**: divisão e conquista, particionando os números para reduzir operações.  

---

## 🛠️ Ferramentas e Padrões

| Ferramenta/Padrão      | Descrição                                               |
|-------------------------|-------------------------------------------------------|
| **GIT**                | Controle de versão para acompanhar o desenvolvimento do código. |
| **Makefile**           | Automação da compilação e geração dos binários.         |
| **Norminette**         | Garantia de conformidade com os padrões de estilo da 42. |

---
