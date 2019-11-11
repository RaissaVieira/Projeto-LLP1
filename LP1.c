/*

Projeto da Disciplina de Laboratório de Linguagem de Programação I

    Autores: Yasmin Kely Lucena de Medeiros
             Raissa da Silva Vieira
             Mayra Cabral Amaral

    Objetivo: Programa que gerencia imóveis de uma imobiliária.

    Entrada: A seleção de acordo com os menus e os imóveis cadastrados no arquivo de texto.

    Saída: Arquivo que salva todos os imóveis cadastrados.

*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

//#define limparTela printf("\e[H\e[2J"); //LINUX
#define limparTela system("cls"); //WINDOWS

#define UP 72
#define DOWN 80
#define ENTER 13

//Galeria de estruturas I:

/*
 geral: [Atributos comuns à todos os tipos de imóveis]

*/

typedef struct{
    char nomerua[100], bairro[100], cidade[100], cep[15];
    int numero;
    float valor;
}geral;

/*
 informacoesc: [Atributos comuns a todos os imoveis, com uma variável do tipo geral, e atributos únicos referentes ao tipo casa.]

*/

typedef struct {
    geral casa;
    char titulo[100], tipo[100];
    int numquart, numpav, areat, areac;
}informacoesc;

/*
 informacoest: [Atributos comuns a todos os imoveis, com uma variável do tipo geral, e atributos únicos referentes ao tipo terreno.]

*/

typedef struct{
    geral geral;
    int area;
    char titulo[100], tipo[100];
}informacoest;

/*
 informacoesa: [Atributos comuns a todos os imoveis, com uma variável do tipo geral, e atributos únicos referentes ao tipo apartamente.]

*/

typedef struct {
    geral ap;
    char titulo[100], tipo[100];
    int numquart, numpav, areaAp;
}informacoesa;

/*
    Arrays de cada tipo, no qual será armazenado os imóveis cadastrados.
*/

informacoesc cadcasa[1000];
informacoest cadterreno[1000];
informacoesa cadap[1000];

/*
    Números de identificação para cada tipo de imóvel.
*/

int iTerreno = 0;
int iCasa=0;
int iApartamento=0;

//Galeria de Funções I:

/*
    ArquivoCasa(): [Função que salva todas as casas cadastradas no arquivo Casa.txt.]

*/

void ArquivoCasa(){

    FILE *fp;

    fp = fopen("Casa.txt", "w");

    if (fp==NULL){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iCasa; i++){
        printf("Salvando casa no arquivo.\n");
        fwrite(&cadcasa[i], sizeof(informacoesc), 1, fp);
    }

    fclose(fp);

    return 0;
}
/*
    ArquivoTerreno(): [Função que salva todos os terretos cadastradas no arquivo Terreno.txt.]

*/
void ArquivoTerreno(){

    FILE *fp;

    fp = fopen("Terreno.txt", "w");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    for (int i = 0; i<iTerreno; i++){
        printf("Salvando terreno no arquivo.\n");
        fwrite(&cadterreno[i], sizeof(informacoest), 1, fp);
    }

    fclose(fp);
    return 0;

}
/*
    ArquivoApartamento(): [Função que salva todos os apartamentos cadastradas no arquivo Apartamento.txt.]

*/

void ArquivoApartamento(){

    FILE *fp;

    fp = fopen("Apartamento.txt", "w");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");

    }
    for (int i = 0; i<iApartamento; i++){
        printf("Salvando apartamento no arquivo.\n");
        fwrite(&cadap[i], sizeof(informacoesa), 1, fp);
    }

    fclose(fp);
    return 0;
}
/*
    LerApartamentoArquivo(): [Função que cadastra todos os apartamentos advindos do arquivo Apartamento.txt.]

*/

void LerApartamentoArquivo(){

    int i = 0;
    FILE *fp;

    fp=fopen("Apartamento.txt", "r");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");

    }
    while((!feof(fp)) && (i <= 1000)){
        fread(&cadap[i], sizeof(informacoesa), 1, fp);
        i++;
    }
    iApartamento = i - 1;
    fclose(fp);
}

/*
    LerTerrenoArquivo(): [Função que cadastra todos os terrenos advindos do arquivo Terreno.txt.]

*/

void LerTerrenoArquivo(){

    int i = 0;
    FILE *fp;

    fp=fopen("Terreno.txt", "r");

    printf("Lendo do arquivo - iterreno = %i \n", iTerreno);

    if (!fp){
        printf("Erro ao abrir o arquivo\n");

    }

    while((!feof(fp)) && (i <= 1000)){
        fread(&cadterreno[i], sizeof(informacoest), 1, fp);

        i++;
    }
    iTerreno = i - 1;

    fclose(fp);
}

/*
    LerCasaArquivo(): [Função que cadastra todas as casas advindas do arquivo Casa.txt.]

*/

void LerCasaArquivo(){

    FILE *fp;
    int i = 0;

    fp = fopen("Casa.txt", "r");

    if (!fp){
        printf("Erro ao abrir o arquivo\n");
        RepetirOperacao();
    }
    while((!feof(fp)) && (i <= 1000)){
        fread(&cadcasa[i], sizeof(informacoesc), 1, fp);
        i++;
    }
    iCasa = i - 1;
    fclose(fp);
}

/*
 CaracteristicasTerreno(): [Função que printa as informações do terreno especificado pelo identificador do mesmo.]

    Parâmetro:
        iTerreno : [Identificador do terreno a ser printado na tela.]
*/

void CaracteristicasTerreno(int iTerreno){
    printf("Nome da rua: ");
    printf("%s",cadterreno[iTerreno].geral.nomerua);
    printf("Nome do bairro: ");
    printf("%s", cadterreno[iTerreno].geral.bairro);
    printf("Nome da cidade: ");
    printf("%s", cadterreno[iTerreno].geral.cidade);
    printf("CEP: ");
    printf("%s", cadterreno[iTerreno].geral.cep);
    printf("Numero: ");
    printf("%d\n", cadterreno[iTerreno].geral.numero);
    printf("Area do terreno: ");
    printf("%d\n", cadterreno[iTerreno].area);
    printf("Titulo: ");
    printf("%s", cadterreno[iTerreno].titulo);
    printf("Valor: ");
    printf("%.2f\n", cadterreno[iTerreno].geral.valor);
    printf("Tipo de imovel: ");
    printf("%s\n", cadterreno[iTerreno].tipo);
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n");

}

/*
 CaracteristicasCasa(): [Função que printa as informações da casa especificada pelo identificador da mesma.]

    Parâmetro:
        iCasa : [Identificador da casa a ser printada na tela.]
*/

void CaracteristicasCasa(int iCasa){
    printf("Nome da rua: ");
    printf("%s", cadcasa[iCasa].casa.nomerua);
    printf("Nome do bairro: ");
    printf("%s", cadcasa[iCasa].casa.bairro);
    printf("Nome da cidade: ");
    printf("%s", cadcasa[iCasa].casa.cidade);
    printf("CEP: ");
    printf("%s", cadcasa[iCasa].casa.cep);
    printf("Numero: ");
    printf("%d\n", cadcasa[iCasa].casa.numero);
    printf("Numero de pavimentos: ");
    printf("%d\n", cadcasa[iCasa].numpav);
    printf("Numero de quartos: ");
    printf("%d\n", cadcasa[iCasa].numquart);
    printf("Area do terreno: ");
    printf("%d\n", cadcasa[iCasa].areat);
    printf("Area construida: ");
    printf("%d\n", cadcasa[iCasa].areac);
    printf("Titulo: ");
    printf("%s", cadcasa[iCasa].titulo);
    printf("Valor: ");
    printf("%.2f\n", cadcasa[iCasa].casa.valor);
    printf("Tipo de imovel: ");
    printf("%s\n", cadcasa[iCasa].tipo);
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n");
}

/*
 CaracteristicasApartamento(): [Função que printa as informações do apartamento especificado pelo identificador do mesmo.]

    Parâmetro:
        iTerreno : [Identificador do apartamento a ser printado na tela.]
*/

void CaracteristicasApartamento(int iApartamento){
    printf("Nome da rua: ");
    printf("%s", cadap[iApartamento].ap.nomerua);
    printf("Numero: ");
    printf("%d\n", cadap[iApartamento].ap.numero);
    printf("Bairro: ");
    printf("%s", cadap[iApartamento].ap.bairro);
    printf("Cidade: ");
    printf("%s", cadap[iApartamento].ap.cidade);
    printf("CEP: ");
    printf("%s", cadap[iApartamento].ap.cep);
    printf("Quantidade de quartos: ");
    printf("%d\n", cadap[iApartamento].numquart);
    printf("Quantidade de pavimentos: ");
    printf("%d\n", cadap[iApartamento].numpav);
    printf("Area: ");
    printf("%d\n", cadap[iApartamento].areaAp);
    printf("Preco: ");
    printf("%f\n", cadap[iApartamento].ap.valor);
    printf("Titulo: ");
    printf("%s", cadap[iApartamento].titulo);
    printf("Tipo de imovel: [aluguel / venda]");
    printf("%s", cadap[iApartamento].tipo);
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n");
}

/*
 VendaTerreno(): [Função que printa todos os terrenos que estão disponíveis para venda.]
*/

void VendaTerreno(){
    for(int j=0; j<=iTerreno; j++){
        if(strcmp("venda", cadterreno[j].tipo) == 0){
            CaracteristicasTerreno(j);
        }
    }
    RepetirOperacao();
}

/*
 VendaApartamento(): [Função que printa todos os apartamentos que estão disponíveis para venda.]
*/

void VendaApartamento(){
    for(int j=0; j<=iApartamento; j++){
        if(strcmp("venda", cadap[j].tipo) == 0){
            CaracteristicasApartamento(j);
        }
    }
    RepetirOperacao();
}

/*
 VendaCasa(): [Função que printa todos as casas que estão disponíveis para venda.]
*/

void VendaCasa(){
    for(int j=0; j<=iCasa; j++){
        if(strcmp("venda", cadcasa[j].tipo) == 0){
            CaracteristicasCasa(j);
        }
    }
    RepetirOperacao();
}

/*
 AlugaTerreno(): [Função que printa todos os terrenos que estão disponíveis para aluguel.]
*/

void AlugaTerreno(){
    for(int j=0; j<=iTerreno; j++){
        if(strcmp("aluguel", cadterreno[j].tipo) == 0){
            CaracteristicasTerreno(j);
        }
    }
    RepetirOperacao();
}

/*
 AlugaApartamento(): [Função que printa todos os apartamentos que estão disponíveis para aluguel.]
*/

void AlugaApartamento(){
    for(int j=0; j<=iApartamento; j++){
        if(strcmp("aluguel", cadap[j].tipo) == 0){
            CaracteristicasApartamento(j);
        }
    }
    RepetirOperacao();
}

/*
 AluguelCasa(): [Função que printa todos as casas que estão disponíveis para aluguel.]
*/

void AlugaCasa(){
    for(int j=0; j<=iCasa; j++){
        if(strcmp("aluguel", cadcasa[j].tipo) == 0){
            CaracteristicasCasa(j);
        }
    }
    RepetirOperacao();
}

/*
 TituloCasa(): [Função que printa todos as casas que estão anunciadas com o título digitado pelo usuário.]
*/

void TituloCasa(){

    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iCasa; j++){
        if(strcmp(titulo1, cadcasa[j].titulo) == 0){
            CaracteristicasCasa(j);
        }
    }
    RepetirOperacao();
}

/*
 TituloApartamento(): [Função que printa todos os apartamentos que estão anunciados com o título digitado pelo usuário.]
*/

void TituloApartamento(){

    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iApartamento; j++){
        if(strcmp(titulo1, cadap[j].titulo) == 0){
            CaracteristicasApartamento(j);
        }
    }
    RepetirOperacao();
}

/*
 TituloTerreno(): [Função que printa todos os terrenos que estão anunciados com o título digitado pelo usuário.]
*/

void TituloTerreno(){

    char titulo1[100];

    printf("Digite o titulo do imovel que deseja procurar: ");
    fgets(titulo1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iTerreno; j++){
        if(strcmp(titulo1, cadterreno[j].titulo) == 0){
            CaracteristicasTerreno(j);
        }
    }
    RepetirOperacao();
}

/*
 BairroCasa(): [Função que printa todos as casas que estão localizadas no bairro digitado pelo usuário.]
*/

void BairroCasa(){

    char bairro1[100];

    printf("Digite o bairro do imovel que deseja procurar: ");
    fgets(bairro1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iCasa; j++){
        if(strcmp(bairro1, cadcasa[j].casa.bairro) == 0){
            CaracteristicasCasa(j);
        }
    }
    RepetirOperacao();
}

/*
 BairroApartamento(): [Função que printa todos os apartamentos que estão localizados no bairro digitado pelo usuário.]
*/

void BairroApartamento(){

    char bairro1[100];

    printf("Digite o bairro do imovel que deseja procurar: ");
    fgets(bairro1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iApartamento; j++){
        if(strcmp(bairro1, cadap[j].ap.bairro) == 0){
            CaracteristicasApartamento(j);
        }
    }
    RepetirOperacao();
}

/*
 BairroTerreno(): [Função que printa todos os terrenos que estão localizados no bairro digitado pelo usuário.]
*/

void BairroTerreno(){

    char bairro1[100];

    printf("Digite o bairro do imovel que deseja procurar: ");
    fgets(bairro1, 100, stdin);
    printf("\n");

    for(int j=0; j<=iTerreno; j++){
        if(strcmp(bairro1, cadterreno[j].geral.bairro) == 0){
            CaracteristicasTerreno(j);
        }
    }
    RepetirOperacao();
}

/*
 BuscarpeloPrecoAp(): [Função que printa todos os apartamentos que estão estipulados pelo valor acima do especificado pelo usuário.]
*/

void BuscarPeloPrecoAp(){

    float precoParaBuscar;
    int i;

    printf("Digite o valor a ser buscado: ");
    scanf("%f", &precoParaBuscar);
    printf("\n");

        for(i = 0; i < iApartamento; i++){

            if(cadap[i].ap.valor  >= precoParaBuscar){
                CaracteristicasApartamento(i);
            }
        }

        RepetirOperacao();
}

/*
 BuscarpeloPrecoCasa(): [Função que printa todos as casas que estão estipuladas pelo valor acima do especificado pelo usuário.]
*/

void BuscarPeloPrecoCasa(){

    float precoParaBuscar;
    int i;

    printf("Digite o valor a ser buscado: ");
    scanf("%f", &precoParaBuscar);
    printf("\n");

        for(i = 0; i < iCasa; i++){

            if(cadcasa[i].casa.valor >= precoParaBuscar){
                CaracteristicasCasa(i);
            }
        }
        RepetirOperacao();
}

/*
 BuscarpeloPrecoTerreno(): [Função que printa todos os terrenos que estão estipulados pelo valor acima do especificado pelo usuário.]
*/

void BuscarPeloPrecoTerreno(){

    float precoParaBuscar;
    int i;

    printf("Digite o valor a ser buscado: ");
    scanf("%f", &precoParaBuscar);
    printf("\n");

        for(i = 0; i < iTerreno; i++){

            if(cadterreno[i].geral.valor >= precoParaBuscar){
                CaracteristicasTerreno(i);
            }
        }
    RepetirOperacao();
}

/*
 ListarImoveisAp(): [Função que printa todos os apartamentos cadastrados.]
*/

void ListarImoveisAp(){
    int i;

    for(i = 0; i < iApartamento; i++){
        CaracteristicasApartamento(i);
    }
    RepetirOperacao();
}

/*
 ListarImoveisCasa(): [Função que printa todas as casas cadastradas.]
*/

void ListarImoveisCasa(){
    int i;

    for(i = 0; i < iCasa; i++){
        CaracteristicasCasa(i);
    }
    RepetirOperacao();
}

/*
 ListarImoveisTerreno(): [Função que printa todos os terrenos cadastrados.]
*/

void ListarImoveisTerreno(){
    int i;

    for(i = 0; i < iTerreno; i++){
        CaracteristicasTerreno(i);
    }
    RepetirOperacao();
}

/*
 RemoverTerreno(): [Função que remove o terreno especificado pelo usuário.]
    Parâmetro:
        cadterreno[] : [Array que carrega todos os terrenos cadastrados.]
*/

void RemoverTerreno( informacoest cadterreno[]) {
    printf("Lista de Terrenos\n");

    for(int i=0;i<iTerreno;i++){
        printf("\nTerreno %d: \n", i+1);
        CaracteristicasTerreno(i);
    }

    int j;
    printf("Digite o indice do terreno que deseja remover: ");
    scanf("%d", j);

    j--;

    for(; j<iTerreno;j++){
        cadterreno[j] = cadterreno[j+1];
    }

    iTerreno--;
    RepetirOperacao();
}

/*
 RemoverCasa(): [Função que remove a casa especificada pelo usuário.]
     Parâmetro:
        cadcasa[] : [Array que carrega todas as casas cadastradas.]

*/

void RemoverCasa(informacoesc cadcasa[]) {
    printf("Lista de Casas\n");

    for(int i=0;i<iCasa;i++){
        printf("\nCasa %d: \n", i+1),
        CaracteristicasCasa(i);
    }

    int j;
    printf("Digite o indice do casa que deseja remover: ");
    scanf("%d", &j);

    j--;

    for( ; j<iCasa;j++){
        cadcasa[j] = cadcasa[j+1];
    }

    iCasa--;
    RepetirOperacao();
}

/*
 RemoverAp(): [Função que remove o apartamento especificado pelo usuário.]
     Parâmetro:
        cadap[] : [Array que carrega todos os apartamentos cadastrados.]
*/

void RemoverAp(informacoesc cadap[]) {
    printf("Lista de Apartamentos\n");

    for(int i=0; i<iApartamento; i++){
        printf("\nApartamento %d: \n", i+1),
        CaracteristicasApartamento(i);
    }

    int j;
    printf("Digite o indice do casa que deseja remover: ");
    scanf("%d", j);

    j--;

    for( ; j<iApartamento;j++){
        cadap[j] = cadap[j+1];
    }

    iApartamento--;
    RepetirOperacao();

}
/*
 EditarCasa(): [Função que edita a casa especificada pelo usuário.]
     Parâmetro:
        cadcasa[] : [Array que carrega todas as casas cadastradas.]

*/
void EditarCasa(informacoesc cadcasa[]){
    printf("Lista de Casa\n");
    for(int i=0;i<iCasa;i++){
            printf("\nCasa %d: ", i+1);
            printf("\n");
            CaracteristicasCasa(i);
            printf("\n");
    }
    int j;
    printf("Digite o numero da casa, a qual você deseja editar: ");
    scanf("%d%*c",&j);
    j--;
    printf("\t\tEDITAR CASA(S)\n");

    printf("Nome da rua: ");
    fgets(cadcasa[j].casa.nomerua, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadcasa[j].casa.bairro, 100, stdin);
    printf("Nome da cidade: ");
    fgets(cadcasa[j].casa.cidade, 100, stdin);
    printf("CEP: ");
    fgets(cadcasa[j].casa.cep, 100, stdin);
    printf("Numero: ");
    scanf("%d", &cadcasa[j].casa.numero);
    printf("Numero de pavimentos: ");
    scanf("%d", &cadcasa[j].numpav);
    printf("Numero de quartos: ");
    scanf("%d", &cadcasa[j].numquart);
    printf("Area do terreno: ");
    scanf("%d", &cadcasa[j].areat);
    printf("Area construida: ");
    scanf("%d%*c", &cadcasa[j].areac);
    printf("Titulo: ");
    fgets(cadcasa[j].titulo, 100, stdin);
    printf("Valor: ");
    scanf("%f%*c", &cadcasa[j].casa.valor);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadcasa[j].tipo, 100, stdin);
    cadcasa[j].tipo[strlen(cadcasa[j].tipo)-1] = '\0';

    RepetirOperacao();
}

/*
 EditarApartamento(): [Função que edita o apartamento especificado pelo usuário.]
     Parâmetro:
        cadap[] : [Array que carrega todos os apartamento cadastrados.]

*/

void EditarApartamento(informacoesa cadap[]){
    printf("Lista de Apartamentos\n");
    for(int i=0;i<iApartamento;i++){
            printf("\nApartamento %d: ", i+1);
            printf("\n");
            CaracteristicasApartamento(i);
            printf("\n");
    }
    int j;
    printf("Digite o numero do Apartamento, o qual você deseja editar: ");
    scanf("%d%*c",&j);
    j--;

    printf("\t\tEDITAR APARTAMENTO(S)\n");

    printf("Nome da rua: ");
    fgets(cadap[j].ap.nomerua, 100, stdin);
    printf("Numero: ");
    scanf("%i%*c", &cadap[j].ap.numero);
    printf("Bairro: ");
    fgets(cadap[j].ap.bairro, 100, stdin);
    printf("Cidade: ");
    fgets(cadap[j].ap.cidade, 100, stdin);
    printf("CEP: ");
    fgets(cadap[j].ap.cep, 15, stdin);
    printf("Quantidade de quartos: ");
    scanf("%i%*c", &cadap[j].numquart);
    printf("Quantidade de pavimentos: ");
    scanf("%i%*c", &cadap[j].numpav);
    printf("Area: ");
    scanf("%i%*c", &cadap[j].areaAp);
    printf("Digite o preco: ");
    scanf("%f%*c", &cadap[j].ap.valor);
    printf("Digite o titulo: ");
    fgets(cadap[j].titulo, 100, stdin);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadap[j].tipo, 100, stdin);
    cadap[j].tipo[strlen(cadap[j].tipo)-1] = '\0';

    RepetirOperacao();
}

/*
 EditarTerreno(): [Função que edita o terreno especificado pelo usuário.]
     Parâmetro:
        cadterreno[] : [Array que carrega todos os terrenos cadastrados.]

*/

void EditarTerreno(informacoest cadterreno[]){
    printf("Lista de Terreno\n");
    for(int i=0;i<iTerreno;i++){
            printf("\nTerreno %d: ", i+1);
            printf("\n");
            CaracteristicasTerreno(i);
            printf("\n");
    }
    int j;
    printf("Digite o terreno, o qual você deseja editar: ");
    scanf("%d%*c",&j);
    j--;

    printf("\t\tEDITAR TERRENO(S)\n");

    printf("Nome da cidade: ");
    fgets(cadterreno[j].geral.cidade, 100, stdin);
    printf("Numero do CEP: ");
    fgets(cadterreno[j].geral.cep, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadterreno[j].geral.bairro, 100, stdin);
    printf("Nome da rua: ");
    fgets(cadterreno[j].geral.nomerua, 100, stdin);
    printf("Numero do terreno: ");
    scanf("%d%*c", &cadterreno[j].geral.numero);
    printf("Area do Terreno: ");
    scanf("%d%*c", &cadterreno[j].area);
    printf("Valor do Terreno: ");
    scanf("%f%*c", &cadterreno[j].geral.valor);
    printf("Titulo: ");
    fgets(cadterreno[j].titulo, 100, stdin);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadterreno[j].tipo, 100, stdin);
    cadterreno[j].tipo[strlen(cadterreno[j].tipo)-1] = '\0';

    RepetirOperacao();
}

/*
 CadastroTerreno(): [Função que cadastra terrenos.]
 Parâmetro:
        pos : [Identificador do terreno a ser cadastrado.]
*/

void CadastroTerreno(int pos){

    printf("\t\tCADASTRO DE TERRENO(S)\n");

    printf("Nome da cidade: ");
    fgets(cadterreno[pos].geral.cidade, 100, stdin);
    printf("Numero do CEP: ");
    fgets(cadterreno[pos].geral.cep, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadterreno[pos].geral.bairro, 100, stdin);
    printf("Nome da rua: ");
    fgets(cadterreno[pos].geral.nomerua, 100, stdin);
    printf("Numero do terreno: ");
    scanf("%d%*c", &cadterreno[pos].geral.numero);
    printf("Area do Terreno: ");
    scanf("%d%*c", &cadterreno[pos].area);
    printf("Valor do Terreno: ");
    scanf("%f%*c", &cadterreno[pos].geral.valor);
    printf("Titulo: ");
    fgets(cadterreno[pos].titulo, 100, stdin);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadterreno[pos].tipo, 100, stdin);
    cadterreno[pos].tipo[strlen(cadterreno[pos].tipo)-1] = '\0';

    iTerreno++;

    RepetirOperacao();
}

/*
 CadastroCasa(): [Função que cadastra casas.]
 Parâmetro:
        pos : [Identificador da casa a ser cadastrada.]
*/

void CadastroCasa(int pos){

    printf("\t\tCADASTRO DE CASA(S)\n");

    printf("Nome da rua: ");
    fgets(cadcasa[pos].casa.nomerua, 100, stdin);
    printf("Nome do bairro: ");
    fgets(cadcasa[pos].casa.bairro, 100, stdin);
    printf("Nome da cidade: ");
    fgets(cadcasa[pos].casa.cidade, 100, stdin);
    printf("CEP: ");
    fgets(cadcasa[pos].casa.cep, 100, stdin);
    printf("Numero: ");
    scanf("%d", &cadcasa[pos].casa.numero);
    printf("Numero de pavimentos: ");
    scanf("%d", &cadcasa[pos].numpav);
    printf("Numero de quartos: ");
    scanf("%d", &cadcasa[pos].numquart);
    printf("Area do terreno: ");
    scanf("%d", &cadcasa[pos].areat);
    printf("Area construida: ");
    scanf("%d%*c", &cadcasa[pos].areac);
    printf("Titulo: ");
    fgets(cadcasa[pos].titulo, 100, stdin);
    printf("Valor: ");
    scanf("%f%*c", &cadcasa[pos].casa.valor);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadcasa[pos].tipo, 100, stdin);
    cadcasa[pos].tipo[strlen(cadcasa[pos].tipo)-1] = '\0';
    iCasa++;
    limparTela;
    RepetirOperacao();
}

/*
 CadastroApartamento(): [Função que cadastra apartamentos.]
 Parâmetro:
        pos : [Identificador do apartamento a ser cadastrado.]
*/

void CadastroApartamento(int pos){

    printf("\t\tCADASTRO DE APARTAMENTO(S)\n");

    printf("Nome da rua: ");
    fgets(cadap[pos].ap.nomerua, 100, stdin);
    printf("Numero: ");
    scanf("%i%*c", &cadap[pos].ap.numero);
    printf("Bairro: ");
    fgets(cadap[pos].ap.bairro, 100, stdin);
    printf("Cidade: ");
    fgets(cadap[pos].ap.cidade, 100, stdin);
    printf("CEP: ");
    fgets(cadap[pos].ap.cep, 15, stdin);
    printf("Quantidade de quartos: ");
    scanf("%i%*c", &cadap[pos].numquart);
    printf("Quantidade de pavimentos: ");
    scanf("%i%*c", &cadap[pos].numpav);
    printf("Area: ");
    scanf("%i%*c", &cadap[pos].areaAp);
    printf("Digite o preco: ");
    scanf("%f%*c", &cadap[pos].ap.valor);
    printf("Digite o titulo: ");
    fgets(cadap[pos].titulo, 100, stdin);
    printf("Tipo de imovel: [aluguel / venda] ");
    fgets(cadap[pos].tipo, 100, stdin);
    cadap[pos].tipo[strlen(cadap[pos].tipo)-1] = '\0';
    iApartamento++;
    limparTela;
    RepetirOperacao();

}
//Galeria de Estruturas II

/*
 Opsetas:[Apresenta dois inteiros, sendo um responsável por guardar a posição da seta e o outro guarda a tecla que está sendo precionada pelo usuário.]
*/

typedef struct{
    int select;// SETA
    int key; // TECLA
} OpSetas;

OpSetas atual;// variável que cria a estrutura OPsetas e será utilizado em todo o manuseio do menu.

//Galeria de Funções II:

void Opcoes (int max){
    atual.key = getch();
    if(atual.key == DOWN) atual.select+= 1;
    if(atual.key == UP) atual.select-= 1;
    if (atual.select > max) atual.select = 1;
    if (atual.select < 1) atual.select = max;
    limparTela;
}

/* Listar() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser listado.] */

void Listar(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Listar Casas\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Listar Apartamentos\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Listar Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        ListarImoveisCasa();
        break;
    case 2:
        ListarImoveisAp();
        break;
    case 3:
        ListarImoveisTerreno();
        break;
    case 4:
        menuPrincipal();
        break;

    }
}

/* Cadastrar() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser cadastrado.] */

void Cadastrar(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Cadastrar Casa\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Cadastrar Apartamento\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Cadastrar Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        CadastroCasa(iCasa);
        break;
    case 2:
        CadastroApartamento(iApartamento);
        break;
    case 3:
        CadastroTerreno(iTerreno);
        break;

    case 4:
        menuPrincipal();
        break;

    }
}

/* Remover() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser removido.] */

void Remover(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Remover Casa\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Remover Apartamento\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Remover Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select)
    {

    case 1:
        RemoverCasa(&cadcasa);
        break;
    case 2:
        RemoverAp(&cadap);
        break;
    case 3:
        RemoverTerreno(&cadterreno);
        break;
    case 4:
        menuPrincipal();
        break;

    }
}

/* Editar() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser editado.] */

void Editar(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Editar Casa\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Editar Apartamento\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Editar Terreno\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select)
    {

    case 1:
        EditarCasa(&cadcasa);
        break;
    case 2:
        EditarApartamento(&cadap);
        break;
    case 3:
        EditarTerreno(&cadterreno);
        break;
    case 4:
        menuPrincipal();
        break;

    }
}

/* Buscar() : [Funcao que sera chamada para o usuario escolher o tipo de busca a ser feita.] */

void Buscar(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar por Titulo\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar por Bairro\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar por Valor\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Buscar Imovel para Venda\n", (atual.select == 4) ? "->" : "  ");
        printf(" %s Buscar Imovel para Locacao\n", (atual.select == 5) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 6) ? "->" : "  ");

        Opcoes(6);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){
    case 1:
        SelecionaTitulo();
        break;
    case 2:
        SelecionaBairro();
        break;
    case 3:
        SelecionaValor();
        break;
    case 4:
        SelecionaVenda();
    case 5:
        SelecionaLocacao();
    case 6:
        menuPrincipal();
        break;
    }
}

/* SelecionaTitulo() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser procurado por titulo.] */

void SelecionaTitulo(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa por Titulo\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento por Titulo\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno por Titulo\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        TituloCasa();
        break;
    case 2:
        TituloApartamento();
        break;
    case 3:
        TituloTerreno();
        break;
    case 4:
        Buscar();
        break;
    }
}

/* SelecionaBairro() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser procurado por bairro.] */

void SelecionaBairro(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa por Bairro\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento por Bairro\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno por Bairro\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        BairroCasa();
        break;
    case 2:
        BairroApartamento();
        break;
    case 3:
        BairroTerreno();
        break;

    case 4:
        Buscar();
        break;
    }
}

/* SelecionaValor() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser procurado por valor.] */

void SelecionaValor(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa por Valor\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento por Valor\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno por Valor\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        BuscarPeloPrecoCasa();
        break;
    case 2:
        BuscarPeloPrecoAp();
        break;
    case 3:
        BuscarPeloPrecoTerreno();
        break;
    case 4:
        Buscar();
        break;
    }
}

/* SelecionaTitulo() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser procurado para venda.] */

void SelecionaVenda(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa para Venda\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento para Venda\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno para Venda\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        VendaCasa();
        break;
    case 2:
        VendaApartamento();
        break;
    case 3:
        VendaTerreno();
        break;

    case 4:
        Buscar();
        break;
    }
}

/* SelecionaLocacao() : [Funcao que sera chamada para o usuario escolher o tipo de imovel a ser procurado para aluguel.] */

void SelecionaLocacao(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Buscar Casa para Locacao\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar Apartamento para Locacao\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Buscar Terreno para Locacao\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Voltar\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        AlugaCasa();
        break;
    case 2:
        AlugaApartamento();
        break;
    case 3:
        AlugaTerreno();
        break;
    case 4:
        Buscar();
        break;
    }
}

/* SelecionaArquivo() : [Funcao que sera chamada para o usuario escolher onde será armazenada as
                            informacoes digitadas por ele de acordo com o tipo de imovel.] */

void SelecionaArquivo(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf(" %s Salvar em Arquivo Casa(s)\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Salvar em Arquivo Apartamento(s)\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Salvar em Arquivo Terreno(s)\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Salvar Todos em Arquivo\n", (atual.select == 4) ? "->" : "  ");
        Opcoes(4);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        ArquivoCasa();
        break;
    case 2:
        ArquivoApartamento();
        break;
    case 3:
        ArquivoTerreno();
        break;
    case 4:
        ArquivoApartamento();
        ArquivoCasa();
        ArquivoTerreno();
        break;
    }
}

/* SalvarArquivo() : [Funcao que sera chamada para o usuario dizer se quer armazenar ou nao as informacoes digitadas.] */

void SalvarArquivo(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("");
        printf("Deseja salvar em arquivo?\n");
        printf(" %s Sim\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Nao\n", (atual.select == 2) ? "->" : "  ");
        Opcoes(2);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        SelecionaArquivo();
        break;
    case 2:
        return 0;
    }
}

/* RepetirOperacao() : [Funcao que sera chamada para o usuario dizer se quer sair do programa ou realizar outras operacoes.] */

void RepetirOperacao(){
    atual.select = 1;

    while (1)
    {
        puts("");
        printf("Deseja Realizar Uma Nova Operacao?\n");
        printf(" %s Sim\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Nao\n", (atual.select == 2) ? "->" : "  ");
        Opcoes(2);
        if(atual.key == ENTER)
            break;
    }

    switch(atual.select){

    case 1:
        menuPrincipal();
        break;
    case 2:
        SalvarArquivo();
    }

}

/* menuPrincipal() : [Apresenta todas as operacoes que podem ser realizadas pelos usuarios.] */

void menuPrincipal(){
    atual.select = 1;
    limparTela;

    while (1)
    {
        puts("----------MOBIL----------");
        puts("");
        printf(" %s Cadastrar\n", (atual.select == 1) ? "->" : "  ");
        printf(" %s Buscar\n", (atual.select == 2) ? "->" : "  ");
        printf(" %s Remover\n", (atual.select == 3) ? "->" : "  ");
        printf(" %s Editar\n", (atual.select == 4) ? "->" : "  ");
        printf(" %s Listar\n", (atual.select == 5) ? "->" : "  ");
        printf(" %s Sair\n", (atual.select == 6) ? "->" : "  ");

        Opcoes(6);

        if(atual.key == ENTER)
            break;
    }
    switch(atual.select)
    {
    case 1:
        Cadastrar();
        break;
    case 2:
        Buscar();
        break;
   case 3:
        Remover();
        break;
    case 4:
        Editar();
        break;
    case 5:
        Listar();
        break;
    case 6:
        SalvarArquivo();
    }
}

int main(void){
    LerApartamentoArquivo();
    LerCasaArquivo();
    LerTerrenoArquivo();
    menuPrincipal();
    return 0;
}
