#include <iostream>

    using namespace std;

    //Esta es una funcion que calcula un numero en base 3, debido a que las permutaciones pueden calcualrse
    //como todos los numeros de 0 a 243 en base 3
    //ademas la funcion los almacena en una lista
    void convertToBase3(int num,int lista[]){
        for(int i=0;i<5;i++){
            if(num<3){
                lista[i]=num;
            }
            lista[i]=num%3;
            num=num/3;
        }

    }


    //Funcion que agrega los puntos a quienes les corresponda
    //si en la lista hay un 0 le añade 3 puntos al rival
    //si es 1 le añade 1 punto a cada uno
    //si es 2 le añade al equipo anfitrion
    void addPoints(int resultados[], int puntajes[]){
        for(int i=0;i<5;i++){
            if(resultados[i]==0){
                int a=puntajes[(i*2)+1];
                puntajes[(i*2)+1]=a+3;
            }
            else if(resultados[i]==1){
                int a=puntajes[i*2];
                int b=puntajes[(i*2)+1];
                puntajes[i*2]=a+1;
                puntajes[(i*2)+1]=b+1;
            }
            else if(resultados[i]==2){
                int a=puntajes[i*2];
                puntajes[i*2]=a+3;
            }

        }

    }

    //funcion qye ordena la tabla de posiciones y equipos por insercion
    void insertionSort(int equipos[],int puntos[]){
        int mayor;
        int aux;
        int aux1;


        for(int i=0;i<9;i++){
            mayor=i;

            for(int j=i+1;j<10;j++){
                if(puntos[j]>puntos[mayor]){
                    mayor=j;
                }

            }
            if(mayor!=i){
                aux=puntos[i];
                puntos[i]=puntos[mayor];
                puntos[mayor]=aux;

                aux1=equipos[i];
                equipos[i]=equipos[mayor];
                equipos[mayor]=aux1;



            }

        }

    }

    //Funcion qye imprime la tabla de posiciones y de acuerdo al numero imprime el pais
    void printTable(int equipos[],int puntos[],int n, int pos){
        /*for(int x=6;x<10;x++){
            if(equipos[x]==3){
                return;
            }

        }*/
        if(equipos[pos]==3){
            cout<<"Tabla "<<n<<"#####################################################"<<endl;
            for(int i=0;i<10;i++){
                if(equipos[i]==0){
                    cout<<"Bolivia: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==1){
                    cout<<"Chile: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==2){
                    cout<<"Ecuador: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==3){
                    cout<<"Peru: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==4){
                    cout<<"Paraguay: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==5){
                    cout<<"Uruguay: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==6){
                    cout<<"Colombia: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==7){
                    cout<<"Brasil: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==8){
                    cout<<"Argentina: "<<puntos[i]<<endl;
                }
                else if(equipos[i]==9){
                    cout<<"Venezuela: "<<puntos[i]<<endl;
                }

            }


        }

    }
    //Bolivia,Chile,Ecuador,Peru,Paraguay,Uruguay,Colombia,Brasil,Argentina,Venezuela

    //Funcion que imprime los resultados que tendrian que darse para que se genere esa tabla
    void printResults(int lista[],int equipos[],int pos){
        /*for(int x=6;x<10;x++){
            if(equipos[x]==3){
                return;
            }

        }*/


        if(equipos[pos]==3){
        //determina el pais
            for(int i=0;i<5;i++){
                if(i==0){
                    cout<<"Bolivia ";
                }
                else if(i==1){
                    cout<<"Ecuador ";
                }
                else if(i==2){
                    cout<<"Paraguay ";
                }
                else if(i==3){
                    cout<<"Colombia ";
                }
                else if(i==4){
                    cout<<"Argentina ";
                }




    //determina el resultado
                if(lista[i]==0){
                    cout<<"pierde"<<endl;
                }
                else if(lista[i]==1){
                    cout<<"empata"<<endl;
                }
                else if(lista[i]==2){
                    cout<<"gana"<<endl;
                }
            }
        }


    }


    int main()
    {
        //lista donde se almacenara el numero convertido a base 3
        int lista[5]={0,0,0,0,0};
        //string paises[10]={"Bolivia","Chile","Ecuador","Peru","Paraguay","Uruguay","Colombia","Brasil","Argentina","Venezuela"};
        //Bolivia,Chile,Ecuador,Peru,Paraguay,Uruguay,Colombia,Brasil,Argentina,Venezuela



        //for que recorre todos los numeros del 0 al 243, que son las posibilades que hay
        //aqui se ejecutan las diferentes funciones
        cout<<"Perú queda en 4to puesto"<<"************************************************************************"<<endl;
        for(int x=0;x<243;x++){
            //array que almacena los puntos en la tabla en orden de partidos
            int puntos[10]={10,23,20,21,21,24,25,36,23,7};
            //array que almacena los equipos que son representados por un numero
            int equipos[10]={0,1,2,3,4,5,6,7,8,9};
            //convertir a base 3
            convertToBase3(x,lista);
            //añadir puntos
            addPoints(lista,puntos);
            //ordenar las listas
            insertionSort(equipos,puntos);
            //imprimir la tabla de posiciones
            printTable(equipos,puntos,x,3);


            //indicar los resultados que deben darse para generar la tabla
            printResults(lista,equipos,3);

        }

        cout<<"Perú queda en 5to puesto"<<"************************************************************************"<<endl;
        for(int x=0;x<243;x++){
            //array que almacena los puntos en la tabla en orden de partidos
            int puntos[10]={10,23,20,21,21,24,25,36,23,7};
            //array que almacena los equipos que son representados por un numero
            int equipos[10]={0,1,2,3,4,5,6,7,8,9};
            //convertir a base 3
            convertToBase3(x,lista);
            //añadir puntos
            addPoints(lista,puntos);
            //ordenar las listas
            insertionSort(equipos,puntos);
            //imprimir la tabla de posiciones

            printTable(equipos,puntos,x,4);

            //indicar los resultados que deben darse para generar la tabla
            printResults(lista,equipos,4);

        }


    }