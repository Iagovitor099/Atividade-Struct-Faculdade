#include <stdio.h>
#include <stdlib.h>


typedef enum{
    APROVADO,
    REPROVADO
}tSituacao;

typedef struct{
    char nome[30];
    double matricula;
    float nota1,nota2,nota3,media;
    tSituacao Situacao;
}tAluno;


void Menu(){
    printf("Menu\n1-Exibir\n2-Cadastrar\n3-Buscar\n4-Sair\n\nEscolha: ");
}


void Cadastrar(tAluno Alunos[], int *PonteiroNumeroAlunos){

    if(*PonteiroNumeroAlunos >= 50)
    {
        printf("Sala cheia!!");
    }else
    {
        int resposta;
        printf("\nQuantos alunos deseja cadastrar: ");
        scanf("%d",&resposta);

        if((resposta + *PonteiroNumeroAlunos) > 50)
        {
            printf("Numero de alunos ultrapassa o limite!!");
        }else
        {
            Alunos[resposta];

            for(int i =0; i< resposta; i++)
            {
                printf("\nNome do aluno (%d): ", i+1);
                scanf("%s", Alunos[*PonteiroNumeroAlunos].nome);

                //fgets(Alunos[*PonteiroNumeroAlunos].nome, 50, stdin);  EU SEI PQ NÃO TA FUNCIONANDO DESSE JEITO, POR ALGUM MOTIVO ELE IDENTIFICA LIXO NA MEMORIA, JA TENTEI FFLUSH() MAS NÃO FUCNIONA

                printf("Matricula do aluno (%d): ",i+1);
                scanf("%lf", &Alunos[*PonteiroNumeroAlunos].matricula);


                printf("Digite a nota 1: ");
                scanf("%f", &Alunos[*PonteiroNumeroAlunos].nota1);
                printf("Digite a nota 2: ");
                scanf("%f", &Alunos[*PonteiroNumeroAlunos].nota2);
                printf("Digite a nota 3: ");
                scanf("%f", &Alunos[*PonteiroNumeroAlunos].nota3);

                Alunos[*PonteiroNumeroAlunos].media = (Alunos[*PonteiroNumeroAlunos].nota1 + Alunos[*PonteiroNumeroAlunos].nota2 + Alunos[*PonteiroNumeroAlunos].nota3)/3;

                if(Alunos[*PonteiroNumeroAlunos].media >= 7)
                {
                    printf("Aluno Aprovado! %.2f", Alunos[*PonteiroNumeroAlunos].media);
                    Alunos[*PonteiroNumeroAlunos].Situacao = 0;
                }else
                {
                    printf("Aluno Reprovado! %.2f", Alunos[*PonteiroNumeroAlunos].media);
                    Alunos[*PonteiroNumeroAlunos].Situacao = 1;
                }
                *PonteiroNumeroAlunos = *PonteiroNumeroAlunos + 1;

            }
        }
    }
}


void Exibir(tAluno Alunos[], int *PonteiroNumeroAlunos){

    if(*PonteiroNumeroAlunos == 0)
    {
        printf("Nenhuma aluno cadastrado!");
    }else{
        system("clear");
        for(int i = 0; i< *PonteiroNumeroAlunos;i++){
            printf("\n\nNome: %s", Alunos[i].nome);
            printf("\nMatricula: %.0lf", Alunos[i].matricula);
            printf("\nNotas: %.1f, %.1f, %.1f", Alunos[i].nota1,Alunos[i].nota2, Alunos[i].nota3);
            printf("\nMédia: %.1f", Alunos[i].media);
        }
    }
}

void Buscar(tAluno Alunos[] ,int *PonteiroParaAlunos){
    int achou =0; //Gambiarra para Saber se achou O USUARIO ou não!!
    double matricula;
    printf("Digite o número da matricula: ");
    scanf("%lf", &matricula);

    for(int i=0; i < *PonteiroParaAlunos; i++){
        if(Alunos[i].matricula == matricula){
            printf("\nNome do aluno: %s", Alunos[i].nome);
            printf("\nMatricula: %.0lf",Alunos[i].matricula);
            printf("\nNota 1: %.1f", Alunos[i].nota1);
            printf("\nNota 2: %.1f", Alunos[i].nota2);
            printf("\nNota 3: %.1f", Alunos[i].nota3);
            printf("\nMédia Final: %.1f", Alunos[i].media);
            achou = 1;
        }
    }
    if(achou == 0){
        printf("\nAluno não encontrado!!");
    }

}

int Resposta(int *ptrResposta){
    int resposta;
    printf("\n\nDeseja Continuar (1 = s/ 0 = n)? ");
    scanf("%d",&resposta);
    *ptrResposta = resposta;
    return resposta;
}

int main()
{
    int EscolhaMenu, resposta;
    tAluno Alunos[50];
    int numeroAlunos = 0;
    int *ptrNumeroAlunos = &numeroAlunos;
    int *ptrParaResposta = &resposta;

    do{
        system("clear");
        Menu();
        scanf("%d", &EscolhaMenu);

        switch(EscolhaMenu)
        {
            case 1:
                Exibir(Alunos, ptrNumeroAlunos);
                Resposta(ptrParaResposta);
                break;
            case 2:
                Cadastrar(Alunos, ptrNumeroAlunos);
                Resposta(ptrParaResposta);
                break;
            case 3:
                Buscar(Alunos,ptrNumeroAlunos);
                Resposta(ptrParaResposta);
                break;
            case 4:
                resposta = 0;
                break;
            default:
                printf("Opção invalida!! ");
                resposta =0;
                break;
        }
    }while(resposta == 1);
    return 0;
}
