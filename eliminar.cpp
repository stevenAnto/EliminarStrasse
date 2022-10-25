/*me uso c++ con edito Vim
 * Librerias iostream y stdlib.h para matrices dinamicas
 * Nombre: Esteven antonio ralcina Puma
 * rUI :20074496
 * GUIa DE LabORaTORIO N`4
 * Ejercicio 1
 */
#include<iostream>
#include<stdlib.h>
using namespace std;


void pedirDatos();
void imprimir(int **,int , int );
void sumarMatrices(int **,int **,int **,int, int);
void restarMatrices(int **,int **,int **,int, int);
void multiMatriz22(int **,int **,int **,int,int);
void strassen(int **,int **, int **,int, int);
int **puntero_matriz1,**puntero_matriz2,nfilas,ncol, **puntero_matrizr;

int main(){
  pedirDatos();
  //  sumarMatrices(puntero_matriz1,puntero_matriz2,puntero_matrizr,nfilas,ncol);
  
  //imprimir(puntero_matrizr,nfilas,ncol);
  cout<<"matriz1"<<endl;
  imprimir(puntero_matriz1,nfilas,ncol);
  cout<<"matriz2"<<endl;
  imprimir(puntero_matriz2,nfilas,ncol);
  strassen(puntero_matriz1,puntero_matriz2,puntero_matrizr,nfilas,ncol);
  
  imprimir(puntero_matrizr,nfilas,ncol);
  for(int i=0;i<nfilas;i++){
    delete[] puntero_matrizr[i];
  }
  delete[] puntero_matrizr;
  //falta liberar memoria para la 2
  return 0;
}

void pedirDatos(){
  cout<<"Llenando matriz1\n";
  cout << "digite el numero de filas";
  cin >> nfilas;
  cout << "digite el numero de columnas";
  cin >> ncol;

  puntero_matriz1 = new int*[nfilas]; //reservando memoria para las filas
  for (int i=0;i<4;i++){
    puntero_matriz1[i] = new int[ncol]; //reservando memeoria para laas columnas
  }
  cout <<"\n digitando elementos de la matriz";
  for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
      cout << " ingrese datos"<<"["<<i<<"]"<<"["<<j<<"]";
      *(*(puntero_matriz1+i)+j)= 1;
//      cin >>*(*(puntero_matriz1+i)+j);
    }
  }
  cout<<"\nLlenando para la segunda matriz\n";
  cout << "digite el numero de filas";
  cin >> nfilas;
  cout << "digite el numero de columnas";
  cin >> ncol;

  puntero_matriz2 = new int*[nfilas]; //reservando memoria para las filas
  for (int i=0;i<nfilas;i++){
    puntero_matriz2[i] = new int[ncol]; //reservando memeoria para laas columnas
  }
  cout <<"\n digitando elementos de la matriz";
  for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
      cout << " ingrese datos"<<"["<<i<<"]"<<"["<<j<<"]";
      *(*(puntero_matriz2+i)+j)= 1;
      //cin >>*(*(puntero_matriz2+i)+j);
    }
  }
  ////aqui se llenara la nueva matriz
  puntero_matrizr = new int*[nfilas]; //reservando memoria para las filas
  for (int i=0;i<nfilas;i++){
    puntero_matrizr[i] = new int[ncol]; //reservando memeoria para laas columnas
  }
}
void sumarMatrices(int **puntero_matriz1,int **puntero_matriz2,int **puntero_matrizr, int nfilas, int ncolu){
	cout<<"entro a sumar"<<endl;
  for(int i=0;i<nfilas;i++){
    for(int j=0;j<ncol;j++){
      *(*(puntero_matrizr+i)+j) = *(*(puntero_matriz1+i)+j)+*(*(puntero_matriz2+i)+j);
      // *(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j);
    }
  }
  imprimir(puntero_matrizr,nfilas,ncolu);
  cout<<"salido sumar"<<endl;
}
void restarMatrices(int **puntero_matriz1,int **puntero_matriz2,int **puntero_matrizr, int nfilas, int ncolu){
	cout<<"restar matrices"<<endl;
  for(int i=0;i<nfilas;i++){
    for(int j=0;j<ncol;j++){
      *(*(puntero_matrizr+i)+j) = *(*(puntero_matriz1+i)+j)-*(*(puntero_matriz2+i)+j);
      // *(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j);
    }
  }
  imprimir(puntero_matrizr,nfilas,ncolu);
}
void multiMatriz22(int **a,int **b,int **puntero_matrizr, int nfilas, int ncolu){
  int m1=( a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
  int m2=( a[1][0]+a[1][1])*(b[0][0]);
  int m3=( a[0][0])*(b[0][1]-b[1][1]);
  int m4=( a[1][1])*(b[1][0]-b[0][0]);
  int m5=( a[0][0]+a[0][1])*(b[1][1]);
  int m6=( a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
  int m7=( a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
  puntero_matrizr[0][0]=m1+m4-m5+m7;
  puntero_matrizr[0][1]=m3+m5;
  puntero_matrizr[1][0]=m2+m4;
  puntero_matrizr[1][1]=m1+m3-m2+m6;
}
void imprimir ( int **puntero_matriz, int nfilas, int ncol){
  for(int i=0;i<nfilas;i++){
    for(int j=0;j<ncol;j++){
      cout << *(*(puntero_matriz+i)+j)<<",";//puntero_matriz[i][j]
    }
    cout<<endl;
  }
}
void strassen(int **a, int **b, int **r, int nfilas, int ncol){
	cout << "ingreso a recursivstra" <<endl;
  //me divide las matrices en 4 partes
  int **a00 ;
  int **a01 ;
  int **a10 ;
  int **a11 ;
  int **b00;
  int **b01;
  int **b10;
  int **b11;
  int **r00;
  int **r01;
  int **r10;
  int **r11;
  a00 = new int*[nfilas]; 
  a01 = new int*[nfilas]; 
  a10 = new int*[nfilas]; 
  a11 = new int*[nfilas]; 
  b00 = new int*[nfilas]; 
  b01 = new int*[nfilas]; 
  b10 = new int*[nfilas]; 
  b11 = new int*[nfilas]; 
  r00 = new int*[nfilas]; 
  r01 = new int*[nfilas]; 
  r10 = new int*[nfilas]; 
  r11 = new int*[nfilas]; 
  for (int i=0;i<nfilas;i++){
    a00[i] = new int[ncol];
    a01[i] = new int[ncol];
    a10[i] = new int[ncol];
    a11[i] = new int[ncol];
    b00[i] = new int[ncol];
    b01[i] = new int[ncol];
    b10[i] = new int[ncol];
    b11[i] = new int[ncol];
    r00[i] = new int[ncol];
    r01[i] = new int[ncol];
    r10[i] = new int[ncol];
    r11[i] = new int[ncol];
  }
  //coeficientes strassen
  int **m1;
  int **m2;
  int **m3;
  int **m4;
  int **m5;
  int **m6;
  int **m7;
  m1= new int*[nfilas];
  m2= new int*[nfilas];
  m3= new int*[nfilas];
  m4= new int*[nfilas];
  m5= new int*[nfilas];
  m6= new int*[nfilas];
  m7= new int*[nfilas];
  for(int i=0;i<nfilas;i++){
    m1[i] = new int[ncol];
    m2[i] = new int[ncol];
    m3[i] = new int[ncol];
    m4[i] = new int[ncol];
    m5[i] = new int[ncol];
    m6[i] = new int[ncol];
    m7[i] = new int[ncol];
  }
  //Matricez auxiliares para guardar los calculos
  int **t1; 
  int **t2;
  t1 = new int*[nfilas];
  t2 = new int*[nfilas];
  for(int i=0;i<nfilas;i++){
    t1[i] = new int[ncol];
    t2[i] = new int[ncol];
  }
  //como debe ser cuadrada

  //raso base
  if(nfilas==2){
    multiMatriz22(a,b,r,nfilas,ncol);
  }
  //raso recursivos
  else{
    //dividimos la matriz que es cuadradada
    for(int i=0;i<nfilas/2;i++){
      for(int j=0;j<ncol/2;j++){
	a00 [i][j]=a[i][j];
	a01 [i][j]=a[i][j+nfilas/2];
	a10 [i][j]=a[i+nfilas/2][j];
	a11 [i][j]=a[i+nfilas/2][j+nfilas/2];
	b00 [i][j]=b[i][j];
	b01 [i][j]=b[i][j+nfilas/2];
	b10 [i][j]=b[i+nfilas/2][j];
	b11 [i][j]=b[i+nfilas/2][j+nfilas/2];
      }
    }
    sumarMatrices(a00,a11, t1,nfilas/2,ncol/2);
    sumarMatrices(a00,b11, t2,nfilas/2,ncol/2);
    strassen(t1,t2,m1,nfilas/2,ncol/2);

    sumarMatrices(a10,a11,t1,nfilas/2,ncol/2);
    strassen(t1,b00,m2,nfilas/2,ncol/2);
    /*m3=a11*(b12+b22)*/
    restarMatrices(b01,b11,t1,nfilas/2,ncol/2);
    strassen(a00,t1,m3,nfilas/2,ncol/2);
    /*m4=a22×(b21+b11)*/
    sumarMatrices(b10,b00,t1,nfilas/2,ncol/2);
    strassen(a11,t1,m4,nfilas/2,ncol/2);
    /*m5=(a11+a12)×b22*/
    sumarMatrices(a00,a01,t1,nfilas/2,ncol/2);
    strassen(t1,b11,m5,nfilas/2,ncol);
    /*m6=(a11+a22)×(b11+b22)*/
    restarMatrices(a10,a00,t1,nfilas/2,ncol/2);
    sumarMatrices(b00,b01,t2,nfilas/2,ncol/2);
    strassen(t1,t2,m6,nfilas/2,ncol/2);
    /*m7=(a12+a22)×(b21+b22)*/
    restarMatrices(a01,a11,t1,nfilas/2,ncol/2);
    sumarMatrices(b10,b11,t2,nfilas/2,ncol/2);
    strassen(t1,t2,m7,nfilas/2,ncol/2);
    /*r11 = m1+m4-m5+m7*/
    sumarMatrices(m1,m4,t1,nfilas/2,ncol/2);
    restarMatrices(m7,m5,t2,nfilas/2,ncol/2);
    sumarMatrices(t1,t2,r00,nfilas/2,ncol/2);
    /*r12 = m3+m5*/
    sumarMatrices(m3,m5,r01,nfilas/2,ncol/2);
    /*r21 = m2+m4*/
    sumarMatrices(m2,m4,r10,nfilas/2,ncol/2);
    /*r22 = m1-m2+m3+m6*/
    restarMatrices(m1,m2,t1,nfilas/2,ncol/2);
    sumarMatrices(m3,m6,t2,nfilas/2,ncol/2);
    sumarMatrices(t1,t2,r11,nfilas/2,ncol/2);

  }
}
