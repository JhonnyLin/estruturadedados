#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
template <typename Tipo>

struct Fila{
    Tipo *v;
    int inicio,fim, qtde, tamanho;

    Fila(int tam){                      //costrutor inici as varieveis
        tamanho = tam;
        inicio = 0;
        fim=-1;//mudei aq
        qtde =0;
        v = new Tipo[tamanho];          //new reserva um espaço na memoria com tipo generico
    }
    bool filaCheia(){
        return qtde==tamanho;
    }
    bool filaVazia(){
        return qtde==0;
    }
////////////////////////////Operações inversas////////////////////////////////////////////////////////

    void inserirTop(Tipo x){            //insere x na posição final

        if(fim==tamanho){               //se fim e tamanho forem iguais zera fim
            fim =0;
        }
        fim++;
        v[fim]=x;                       //aloca x na dentro do array na posição indicada por fim
        qtde++;                         //almenta um na quantidade

    }
    void inserirBot(Tipo x){            //insere x no inico da fila
        if(qtde!=0){
           inicio--;
        }else{
            fim++;
        }
                                //diminui um para n sobrescrever o inicio anterior
        if(inicio < 0){                 //se menor que zero
            inicio = tamanho-1;         //inicio tamanho -1 pq lembrando q array começa em zero
        }
        v[inicio]=x;                    //aloca x no inicio
        qtde++;

    }
    Tipo removerTop(){                  //remove no final
        Tipo tp= v[fim];                //valo pra ser retornado
        fim--;                          //diminui fim em 1 no indice (de traz pra frente)
        if(fim<0){                      //se fim for menor que 0 pq o decremento é antes;
            fim=tamanho-1;              //fim = tamanho menos 1
        }
        qtde--;                         //quantidade menos 1
        return tp;                      //retorna o valor que foi "apagado"
    }
    Tipo removerBot(){                  //remove no inicio
        Tipo tp= v[inicio];
        inicio++;                       //aumenta inicio em 1 no indice(da frete pra traz)
        if(inicio==tamanho){            //inicio e tamanho iguais
            inicio =0;                  //manda pro indice 0
        }
        qtde--;                         //qtde menos um pq esta removendo
        return tp;
    }

    Tipo Primeiro(){
        return v[inicio];
    }
    Tipo Ultimo(){
        return v[fim];
    }
////////////////////////////////////////Destrutor/////////////////////////////////////////////////////

    ~Fila(){                            //destrutor
        delete v;                       //devolve a memoria q v utilizou para o sistema operacional
    }
/////////////////////////////////////////GETS////////////////////////////////////////////////////////
    int getIncio(){
        return inicio;
    }
    int getFim(){
        return fim;
    }
    Tipo getValor(int a){
        return v[a];
    }
    int getQtde(){
        return qtde;
    }
    int getTamanho(){
        return tamanho;
    }

};

#endif // FILA_H_INCLUDED
