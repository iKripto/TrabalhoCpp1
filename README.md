Escreva um programa para criar as seguintes estruturas que simularão arquivos sequenciais para uma aplicação de Controle Clínica Veterinária:

Cidades: código (PK), nome, UF

Raças: código (PK), descrição

Animais: código (PK), nome, código da raça, idade, peso, código do tutor

Tutores: código (PK), nome, CPF, endereço, código da cidade

Veterinários: código (PK), nome, endereço, código da cidade

Consultas: código (PK), código do Animal, código do Veterinário, data da consulta, valor da consulta


1) Escreva funções específicas para a leitura dos dados das estruturas.

2) Escreva uma função para permitir a inclusão de novos registros na tabela de tutores. 
2.1) Quando o usuário digitar o CPF, o programa deverá realizar a validação do CPF.
2.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e o estado.

3) Escreva uma função para permitir a inclusão de novos registros na tabela de animais.
3.1) Quando o usuário digitar o código da raça, o programa deverá buscar este código na tabela de raças e exibir a descrição.
3.2) Quando o usuário digitar o código do tutor, o programa deverá buscar este código na tabela de tutores e exibir o nome do tutor e o nome de sua cidade.

4) Escreva uma função para permitir ao usuário realizar uma consulta.
4.1) O código da consulta (PK) deverá ser gerado automaticamente e sequencialmente a partir do último registro cadastrado.
4.2) O usuário deverá informar o código do animal e o programa deverá buscar este código na tabela de Animais e exibir a seu nome, o nome da raça e o nome do tutor.
4.3) O usuário deverá informar o código do veterinário e o programa deverá buscar este código na tabela de Veterinários e exibir seu nome e o nome de sua cidade.
4.4) O usuário deverá informar a data da consulta e o valor da consulta.

5) Escreva uma função para exibir todas as consultas realizadas em determinado intervalo de datas (data inicial e data final).
5.1) Os seguintes dados devem ser exibidos: nome do animal, nome do veterinário, data da consulta, valor da consulta.
5.2) Ao final, a função deverá exibir o valor total das consultas.

6) Escreva uma função para exibir todas as consultas realizadas em determinado intervalo de datas (data inicial e data final) para determinado Veterinário.
6.1) Os seguintes dados devem ser exibidos: nome do animal, nome do veterinário, data da consulta, valor da consulta.
6.2) Ao final, a função deverá exibir o valor total das consultas.

Todas as funções descritas acima deverão ser chamadas através de um menu de opções que será chamado a partir da função main().

Obs: não utilizar variáveis globais.
