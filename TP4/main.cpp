#include <iostream>
#include "Fila.h"                                                   //inclusão da biblioteca
#include <stdlib.h>
using namespace std;
int main()
{
    Fila<int> f(12);                                                //intanciando f como fila do tipo inteiro e tamanho 12
                                                                    //f igual struct fila ou seja construtor
    int opcao =0,op =0;

    do{
        cout<<">>>>>>Fila dupla<<<<<<"<<endl;
        cout<<"Selecione uma opcao"<<endl;
        cout<<"1 - Inserir"<<endl;
        cout<<"2 - Remover"<<endl;
        cout<<"3 - Exibir todos"<<endl;
        cout<<"4 - Exibir inicio/fim da fila"<<endl;
        cout<<"6 - Sair"<<endl;
        cin>>opcao;
         system("cls");
        switch(opcao){
        case 1:
            cout<<"insira o numero"<<endl;
            cin>>op;
            do{
                cout<<"1-Comeco"<<endl;
                cout<<"2-Fim"<<endl;
                cin>>opcao;
                                                                      //laço pra ficar ate digitar opção valida
                switch(opcao){
                case 1:                                                  //inserir no inicio
                    if(f.filaCheia()){                                   // se fila cheia print
                        cout<<"Fila cheia"<<endl;
                    }else{                                               //se não
                        f.inserirBot(op);                                //chama função inserir no inicio e passa o numero
                        cout<<"inserido"<<endl;
                    }
                    break;
                case 2:                                                  //inserir no final
                    if(f.filaCheia()){                                   // se fila cheia print
                        cout<<"Fila cheia"<<endl;
                    }else{                                               //se não
                        f.inserirTop(op);                                //função interir no fim
                        cout<<"inserido"<<endl;
                    }
                    break;

                default:
                    cout<<"infelizmente opcao nao existete"<<endl;
                    cout<<"tente de novo"<<endl;
                    opcao=0;                                               //pra fazer ficar no laço
                    break;
                }
            }while(opcao==0);
            break;
        case 2:
             do{                                                          //laço para força opcao valida
                if(f.filaVazia()){
                    cout<<"lista vazia.."<<endl;
                }else{
                                        cout<<"1 - Inicio"<<endl;
                    cout<<"2 - Final"<<endl;
                    cin>>opcao;
                    switch(opcao){
                    case 1:                                                 //remover no inicio
                        cout<<f.removerBot()<<endl;
                        break;
                    case 2:                                                 //remover no final
                        cout<<f.removerTop()<<endl;
                        break;
                    default:
                        cout<<"opcao não existente"<<endl;
                        opcao=0;
                        break;
                    }

                }

            }while(opcao==0);
            break;
        case 3:
            if(f.getQtde()>0){
                if(f.getIncio()<=f.getFim()){                                         //se inicio for menor ou igual a fim
                    for(int i = f.getIncio(); i <= f.getFim();i++){                   //vai de inicio ao fim
                        cout<<"Numero: "<<f.getValor(i)<<"indice"<< i<<endl;          //função de trazer elemento pelo parametro
                    }
                }else{                                                                //se não
                   // cout<<"entrou no else"<<endl;
                    for(int i = f.getIncio(); i <f.getTamanho();i++){               //vai do inicio ate tamanho -1
                        cout<<"Numero: "<<f.getValor(i)<<"indice"<< i<<endl;
                    }
                   // cout<<"s 1 for"<<endl;
                    for(int i = 0; i<=f.getFim();i++){                                //vai de 0 a fim
                       // cout<<"e 2 for"<<endl;
                        cout<<"Numero: "<<f.getValor(i)<<"indice"<< i<<endl;
                    }
                   // cout<<"s2 for"<<endl;
                }
            }else{
                cout<<"lista vazia"<<endl;
            }
            system("pause");
            break;
        case 4:
            cout<<"Primeiro: "<<f.Primeiro()<<endl;
            cout<<"Ultimo: "<<f.Ultimo()<<endl;
            break;
        case 6:
            opcao = 0;
            break;
        default:
            cout<<"Nao ha essa opcao"<<endl;
            break;
        }
    }while(opcao != 0);
}
