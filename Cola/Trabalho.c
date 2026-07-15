#include <stdio.h>

struct Produtos
{
    char NomeProd[51];
    int CodProd ;
    double PrecoProd ;
    double QntProd ; 
};
struct Produtos produto[10];
int totalProdutos = 0;

void realizarCadastro(int quantidade) {
    int i;
    int inicio = totalProdutos;
    
    for(i = inicio; i < inicio + quantidade; i++){
        printf("\n-Cadastro do produto %d-\n", i+1);
        
        printf("\nInforme o nome do produto: ");
        scanf(" %[^\n]", produto[i].NomeProd);
        
        printf("\nInforme o código do produto: ");
        scanf("%7d", &produto[i].CodProd);
        
        printf("\nInforme o preço do produto (utilize ponto): ");
        scanf("%lf", &produto[i].PrecoProd);
        
        printf("\nInforme a quantidade recebida do produto: ");
        scanf("%lf", &produto[i].QntProd);
    }
    
    totalProdutos += quantidade;
    printf("\n%d produto(s) cadastrado(s) com sucesso!\n", quantidade);
}
void CadProd(){
    int quantidade;
    int disponivel = 10 - totalProdutos;
    int result;
    
    printf("\nDigite 0 caso deseje voltar para o menu sem cadastrar produtos.");
    printf("\n\nQuantos produtos deseja cadastrar? (max 10): ");
    
    result = scanf("%d", &quantidade);
    while(getchar() != '\n');
    
    if(result != 1 || quantidade < 0) {
        printf("Entrada inválida! Digite apenas números positivos.\n");
    }
    else if(quantidade == 0) {
        printf("Você escolheu não cadastrar produtos!\n");
    }
    else if(quantidade > disponivel) {
        printf("ATENÇÃO. Você só pode cadastrar mais %d produtos\n", disponivel);
        printf("Informe um valor igual ou menor que %d: ", disponivel);
        
        result = scanf("%d", &quantidade);
        while(getchar() != '\n');
        
        if(result != 1 || quantidade > disponivel || quantidade <= 0) {
            printf("Entrada inválida! Operação cancelada.\n");
        }
        else {
            realizarCadastro(quantidade);
        }
    }
    else {
        realizarCadastro(quantidade);
    }
    
    printf("Pressione ENTER para continuar...");
    getchar();
}
void ExibirProds(){
    int i;
    //valida se a memoria não esta vazia
    if(totalProdutos == 0 ){
        printf("Nenhum produto cadastrado ainda.");
        return;
    }
    
    printf("\n\n-Produtos Registrados-\n");    
    for(i=0; i < totalProdutos; i++){
        printf("\n- Produto %d-", i+1);
        /*aqui precisei de ajuda da IA, pois quando eu colocova espaço em um nome, 
        o programa bugava, desta forma o programa pega tudo oque tiver até chegar na quebra de linha*/
        printf("\nNome: %s\n", produto[i].NomeProd);
        printf("Código: %d\n", produto[i].CodProd);
        printf("Preço: R$ %.2f\n", produto[i].PrecoProd);
        printf("Quantidade: %.1f\n", produto[i].QntProd); 
        //decidi colocar um delay com enter aqui também para ficar mais facil de vizualizar cada produto
        if(i < totalProdutos - 1){
            printf("Pressione ENTER para o proximo produto.");
            getchar();  // espera o ENTER
            }
    }
    //precisei adcionar isso por causa do loop do menu que tampava os resultados dessa funçaõ
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();  // espera o ENTER
    return;
}
void CalcularEstoque(){
    double totalGeral = 0;
    double valorProduto;
    int i;
    //valida se a memoria não esta vazia
    if(totalProdutos == 0){
        printf("Nenhum produto cadastrado ainda.");
        return;
    }
    printf("\nValor do Estoque\n");
    for (i=0; i < totalProdutos; i++){
        valorProduto = produto[i].PrecoProd * produto[i].QntProd;
        totalGeral += valorProduto;
        
        printf("Produto %d\n", i+1);
        printf("Nome: %s\n", produto[i].NomeProd);
        printf("Valor em estoque: R$%.2f\n", valorProduto);
        //pausa entre cada produto para vizualizar melhor
        if(i < totalProdutos - 1){
            printf("\nPressione ENTER para o proximo produto.");
            getchar();  // espera o ENTER
            }
    }
    
    printf("\n\nValor total do estoque: R$%.2f", totalGeral);
    
    printf("\nPressione ENTER para continuar...");
    getchar();  // espera o ENTER
    return;
}
void ProcurarProd(){
    int i;
    int OpsBusca;
    int CodBusca;
    int encontrado;
    //valida se a memoria não esta vazia
    if(totalProdutos == 0){
        printf("Nenhum produto cadastrado ainda.");
        return;}
    do
    {
        printf("\n\n-Menu de pesquisa-");
        printf("\n1. Listar codigos cadastrados.\n2.Pesquisar produto por codigo.\n3.Voltar ao menu principal\n\n");
        printf("Escolha uma opção:");
        scanf("%d", &OpsBusca);

        //switch que chama função de acordo com oque foi escolhido no menu
        switch (OpsBusca)
        {
        case 1:
            for(i = 0; i < totalProdutos; i++) {
                    printf("Produto %-2d --> Código: %-5d\n", i+1, produto[i].CodProd);
                    printf("\n");
                }
            break;
        
        case 2:
            printf("Digite codigo do produto que deseja encontrar: ");
            scanf("%d", &CodBusca);
            
            encontrado = 0;
            for(i = 0; i <totalProdutos; i++){
                if(produto[i].CodProd == CodBusca){
                    printf("\nProduto encontrado:");
                    printf("\nNome:%-20s", produto[i].NomeProd);
                    printf("\nCódigo:%-20d", produto[i].CodProd);
                    printf("\nPreço:R$ %-17.2f", produto[i].PrecoProd);
                    printf("\nQuantidade: %-19.0f", produto[i].QntProd);
                    encontrado = 1;
                    break;
                }
            }
            if(!encontrado){
                printf("Produto não encotrado!");
            }          
            break;
        
        case 3:
            printf("Voltando ao menu.");
            break;
        default:
            printf("Escolha uma das opções validas para prosseguir.");
            break;
        }
    } while (OpsBusca != 3);
    

}
int main (){
    int Seletor;
    printf("Bem vindo ao gerenciador de estoque!");
    do{
    printf("\n\n-Gerenciador de estoque-");
    printf("\n\nInsira o numero da função que deseja:");
    printf("\n\n1. Cadastrar produto\n2. Listar todos os produtos cadastrados\n3. Mostrar o valor total em estoque (preço x quantidade)\n4. Buscar produto pelo código\n0. Sair do programa\n\n");
    scanf("%i",&Seletor);

    /*coloquei para limpar o buffer aqui no loop, assim não 
    preciso inserir em cada função que tem o daley com enter*/
    while(getchar() != '\n');

    switch (Seletor)
    {
    case 1:
        CadProd();
        break;
    case 2:
        ExibirProds();
        break;
    case 3:
        CalcularEstoque();
        break;
    case 4:
        ProcurarProd();
        break;    
    
    case 0:
        printf("\nObrigado por utilizar o gerenciador de estoque!\n\n");
        break;
    }
    }while(Seletor != 0);

    return 0;
}