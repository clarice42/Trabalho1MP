// Copyright 2019 Clara Resende

#include "gtest/gtest.h"
#include "romano.hpp"

/* Teste para verificar se as letras foram transformadas nos numeros devidos */
TEST(converteTeste, comparandoLetras) {
    EXPECT_EQ(1, converte('I'));
    EXPECT_EQ(5, converte('V'));
    EXPECT_EQ(10, converte('X'));
    EXPECT_EQ(50, converte('L'));
    EXPECT_EQ(100, converte('C'));
    EXPECT_EQ(500, converte('D'));
    EXPECT_EQ(1000, converte('M'));
}
/* Verificar se a soma de numeros como XXX foi feita adequadamente */
TEST(somaRomano, soma) {
    int vetor_teste1[] = {1, 1, 1, 0};
    int vetor_teste2[] = {5, 1, 1, 1, 0};
    int vetor_teste3[] = {10, 10, 5, 1, 0};
    int vetor_teste4[] = {50, 10, 10, 10, 5, 0};
    int vetor_teste5[] = {100, 100, 100, 50, 5, 1, 1, 1, 0};
    int vetor_teste6[] = {500, 100, 1, 1, 0};
    int vetor_teste7[] = {1000, 100, 100, 5, 0};
    int vetor_teste8[] = {1000, 1000, 500, 100, 100, 10, 10, 1, 1, 0};

    EXPECT_EQ(3, soma_romano(vetor_teste1));
    EXPECT_EQ(8, soma_romano(vetor_teste2));
    EXPECT_EQ(26, soma_romano(vetor_teste3));
    EXPECT_EQ(85, soma_romano(vetor_teste4));
    EXPECT_EQ(358, soma_romano(vetor_teste5));
    EXPECT_EQ(602, soma_romano(vetor_teste6));
    EXPECT_EQ(1205, soma_romano(vetor_teste7));
    EXPECT_EQ(2722, soma_romano(vetor_teste8));
}
/* Verificar se a subtracao de numeros como XC esta correta */
TEST(somaRomano, subtracao) {
    int vetor_teste1[] = {1, 5, 0};
    int vetor_teste2[] = {1000, 100, 500, 10, 100, 1, 10, 0};
    int vetor_teste3[] = {1000, 1000, 100, 100, 100, 10, 50, 1, 5, 0};
    int vetor_teste4[] = {1000, 1000, 100, 1000, 10, 100, 1, 10, 0};
    int vetor_teste5[] = {1000, 100, 1000, 10, 100, 1, 10, 0};
    int vetor_teste6[] = {10, 50, 1, 10, 0};
    int vetor_teste7[] = {500, 100, 100, 1, 10, 0};
    int vetor_teste8[] = {10, 100, 1, 5, 0};

    EXPECT_EQ(4, soma_romano(vetor_teste1));
    EXPECT_EQ(1499, soma_romano(vetor_teste2));
    EXPECT_EQ(2344, soma_romano(vetor_teste3));
    EXPECT_EQ(2999, soma_romano(vetor_teste4));
    EXPECT_EQ(1999, soma_romano(vetor_teste5));
    EXPECT_EQ(49, soma_romano(vetor_teste6));
    EXPECT_EQ(709, soma_romano(vetor_teste7));
    EXPECT_EQ(94, soma_romano(vetor_teste8));
}
/* Teste que verifica excecoes do tipo VV ou IIII */
TEST(excecoesTeste, numerosInvalidos1) {
    char string1[] = "XXXX";
    char string2[] = "XLDD";
    char string3[] = "MMVV";
    char string4[] = "IXLL";
    EXPECT_EQ(-1, verifica_excecao1(string1));
    EXPECT_EQ(-1, verifica_excecao1(string2));
    EXPECT_EQ(-1, verifica_excecao1(string3));
    EXPECT_EQ(-1, verifica_excecao1(string4));
}
/* Teste que verifica excecoes do tipo IIK ou VX */
TEST(excecoesTeste, numerosInvalidos2) {
    int vetor1[] = {1, 5, -1};
    int vetor2[] = {1000, 100, 10, 10, -1};
    int vetor3[] = {5, 10};
    int vetor4[] = {1, 50, 100};
    EXPECT_EQ(-1, verifica_excecao2(vetor1));
    EXPECT_EQ(-1, verifica_excecao2(vetor2));
    EXPECT_EQ(-1, verifica_excecao2(vetor3));
    EXPECT_EQ(-1, verifica_excecao2(vetor4));
}
/* Teste que verifica excecoes do tipo IIV e MDCM*/
TEST(excecoesTeste, numerosInvalidos3) {
    int vetor1[] = {1, 1, 5};
    int vetor2[] = {100, 100, 1000};
    int vetor3[] = {500, 100, 1000};
    int vetor4[] = {1000, 100, 500, 1000};
    EXPECT_EQ(-1, verifica_excecao3(vetor1));
    EXPECT_EQ(-1, verifica_excecao3(vetor2));
    EXPECT_EQ(-1, verifica_excecao3(vetor3));
    EXPECT_EQ(-1, verifica_excecao3(vetor4));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
