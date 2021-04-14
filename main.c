#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

    FILE* Banco;
    FILE* Materias;
    FILE* Cursos;
    int codigo_curso,codigo_curso_check;
    int credito_calculo[4];
    char nome_curso[20];
    char ch;
    char login[20],senha[20];
    char login_digitado[20], senha_digitada[20];
    char login_check[20];
    char materia[5][50];
    int credito=0,credito_soma=0,nota=0,nota_coeficiente=0,aprovado=0,reprovado_falta=0,reprovado=0,quantidade_aprovado=0,quantidade_reprovado_falta=0,quantidade_reprovado=0;
    float coeficiente_rendimento=0,porcentagem_total=0,porcentagem_obrigatorias=0,porcentagem_limitadas=0,porcentagem_livres=0;
    int creditos_obrigatorios=0,creditos_livres=0,creditos_limitados=0,materias_obrigatorias=0,materias_limitadas=0,materias_livres=0;
    char v[11];
    char v1[]="Obrigatoria";
    char v2[]="Livre";
    char v3[]="Limitada";

    do{
        printf("Insira o seu Login: \n");
        scanf("%s", login_digitado);
        Banco = fopen("Banco.txt" ,"r");
        do{
            fscanf(Banco,"%s %s", login, senha);
            ch=fgetc(Banco);
        }while((strcmp(login, login_digitado)==1 || strcmp(login, login_digitado)==-1) && ch!=EOF);
        fclose(Banco);
        if(strcmp(login, login_digitado)==1 || strcmp(login, login_digitado)==-1){
            printf("\nLogin incorreto\n");
        }
    }while(strcmp(login, login_digitado)==1 || strcmp(login, login_digitado)==-1);

    //Esta parte do código busca no banco de dados com o nome "Banco" pelo login que o usuário digitou
    //Se o login digitado bater com algum login do banco, a senha vinculada ao login ja é armazenada em outra variável
    //Caso não bater, é pedido que o usuario digite um novo login

        for(int i=4;i>0;i--){
            printf("\nInsira a sua Senha: \n");
            scanf("%s",senha_digitada);
            printf("\n");
            if(strcmp(senha, senha_digitada)==0){
                break;
            }
            else{
                printf("\nSenha incorreta\n");
                printf("Voce tem mais %i tentativas\n", i-1);
                if(i==1){
                    exit(0);
                }
            }
        }

        //Nesta parte o usuário tem 4 tentativas até acertar a senha correspondente ao login digitado
        //O programa se encerra se o usuário errar a senha 4 vezes

    Materias=fopen("materias.txt", "r");
    Cursos = fopen("Cursos.txt" ,"r");

    do{
        fscanf(Materias,"%s", login_check);
        ch=fgetc(Materias);
    }while((strcmp(login, login_check)==1 || strcmp(login, login_check)==-1) && ch!=EOF);

    fscanf(Materias,"%i", &codigo_curso);

    do{
        fscanf(Cursos,"%i",&codigo_curso_check);
        ch=fgetc(Cursos);
    }while((strcmp(codigo_curso, codigo_curso_check)==1 || strcmp(codigo_curso, codigo_curso_check)==-1) && ch!=EOF);

    fscanf(Cursos,"%s",&nome_curso);
    for(int i=0;i<4;i++){
        fscanf(Cursos,"%i",credito_calculo[i]);
    }

    fclose(Cursos);

    while(materia[0][0]!=';'){
        for(int i=0;i<6&&materia[0][0]!=';';i++){
            switch(i){
                case 0:
                    fscanf(Materias,"%s", materia[i]);
                    if(materia[0][0]==';'){
                        break;
                    }
                    else{
                        printf("%s",materia[i]);
                        break;
                    }
                case 1:
                    fscanf(Materias,"%[^0-9]s", materia[i]);
                    printf("%s",materia[i]);
                    break;
                case 2:
                    fscanf(Materias,"%s", materia[i]);
                    printf("%s ",materia[i]);
                    if(materia[2][0]=='6'){
                        credito=6;
                    }
                    else if(materia[2][0]=='5'){
                        credito=5;
                    }
                    else if(materia[2][0]=='4'){
                        credito=4;
                    }
                    else if(materia[2][0]=='3'){
                        credito=3;
                    }
                    else if(materia[2][0]=='2'){
                        credito=2;
                    }
                    credito_soma=credito_soma+credito;
                    break;
                case 3:
                    fscanf(Materias,"%s", materia[i]);
                    printf("%s ",materia[i]);
                    if(materia[3]=='A'){
                        nota=4;
                        aprovado=aprovado+1;
                        quantidade_aprovado=quantidade_aprovado+credito;
                    }
                    else if(materia[3][0]=='B'){
                        nota=3;
                        aprovado=aprovado+1;
                        quantidade_aprovado=quantidade_aprovado+credito;

                    }
                    else if(materia[3][0]=='C'){
                        nota=2;
                        aprovado=aprovado+1;
                        quantidade_aprovado=quantidade_aprovado+credito;

                    }
                    else if(materia[3][0]=='D'){
                        nota=1;
                        aprovado=aprovado+1;
                        quantidade_aprovado=quantidade_aprovado+credito;

                    }
                    else if(materia[3][0]=='F'){
                        nota=0;
                        reprovado=reprovado+1;
                        quantidade_reprovado=quantidade_reprovado+credito;
                    }
                    else if(materia[3][0]=='O'){
                        nota=0;
                        reprovado_falta=reprovado_falta+1;
                        quantidade_reprovado_falta=quantidade_reprovado_falta+credito;
                    }
                    nota_coeficiente=nota_coeficiente+nota*credito;

                    break;
                case 4:
                    fscanf(Materias,"%s", materia[i]);
                    printf("%s ",materia[i]);
                    break;
                case 5:
                    fscanf(Materias,"%s", v);
                    printf("%s\n",v);
                    int c=strcmp(v,v1);
                    if((nota==4||nota==3||nota==2||nota==1)&&strcmp(v,v1)==0){
                       creditos_obrigatorios=creditos_obrigatorios+credito;
                       materias_obrigatorias=materias_obrigatorias+1;
                    }
                    if((nota==4||nota==3||nota==2||nota==1)&&strcmp(v,v2)==0){
                       creditos_livres=creditos_livres+credito;
                       materias_livres=materias_livres+1;
                    }
                    if((nota==4||nota==3||nota==2||nota==1)&&strcmp(v,v3)==0){
                       creditos_limitados=creditos_limitados+credito;
                       materias_limitadas=materias_limitadas+1;
                    }
                    break;
            }
        }
    }
    fclose(Materias);

    //Nesta parte, cada linha do banco de dados com o nome "materias" é vinculado a uma matriz até ser encontrado o ; no banco
    //Os dados de cada materia são impressos a medida em que as matrizes são feitas
    //Os acumuladores dentro de cada caso fazem os calculos necessarios

    coeficiente_rendimento=(float)nota_coeficiente/credito_soma;



    porcentagem_total=(float)quantidade_aprovado*100/credito_calculo[0];
    porcentagem_obrigatorias=(float)creditos_obrigatorios*100/credito_calculo[1];
    porcentagem_limitadas=(float)creditos_limitados*100/credito_calculo[2];
    porcentagem_livres=(float)creditos_livres*100/credito_calculo[3];


    printf("Voce esta matriculado no(a) %s",nome_curso);
    printf("--------------------------------------------------------------------------------\n");
    printf("Coeficiente de rendimento: %.2f\n",coeficiente_rendimento);
    printf("--------------------------------------------------------------------------------\n");
    printf("Aprovado em %i materias\nReprovado em %i materias\nReprovado por falta em %i materias\n", aprovado,reprovado,reprovado_falta);
    printf("--------------------------------------------------------------------------------\n");
    printf("Voce cursou %i creditos\n", credito_soma);
    printf("Foi aprovado em %i creditos\nFoi reprovado em %i creditos\nFoi reprovado por falta em %i creditos \n",quantidade_aprovado,quantidade_reprovado,quantidade_reprovado_falta);
    printf("--------------------------------------------------------------------------------\n");
    printf("Voce foi aprovado em:\n%i materias obrigatorias\n%i materias livres\n%i materias limitadas\n",materias_obrigatorias,materias_livres,materias_limitadas);
    printf("--------------------------------------------------------------------------------\n");
    printf("Voce foi aprovado em:\n%i creditos obrigatorios\n%i creditos livres\n%i creditos limitados\n",creditos_obrigatorios,creditos_livres,creditos_limitados);
    printf("--------------------------------------------------------------------------------\n");
    printf("Voce concluiu %.1f %% do curso\nConcluiu %.1f %% das materias obrigatorias\nConcluiu %.1f %% das materias limitas\nConcluiu %.1f das materias livres\n\n",porcentagem_total,porcentagem_obrigatorias,porcentagem_limitadas,porcentagem_livres);



    //Depois são impressos os valores acumulados
}
