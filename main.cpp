#include <iostream>
#include <Matrix.h>
using namespace std;

int main()
{
    Matrix<int> a;
    Matrix<int> b;
    Matrix<int> c, d, e;

   a.ingresarDatos("MatrizA.txt");
   b.ingresarDatos("MatrizB.txt");
   cout<<"Matriz A"<<endl;  cout<<a;
   cout<<"Matriz B"<<endl;  cout<<b;

   c = a+b;
   d = a-b;
   e = a*b;
   c.guardarDatos("MatrizRes.txt");
   //c.showMatrix();
   //d.showMatrix();


    cout<<"\n"<<"Matriz C: Suma "<<"\n";
    cout<<c<<"\n";
    cout<<"Matriz D: Resta"<<"\n";
    cout<<d<<"\n";
    cout<<"Matriz E: Multiplicacion"<<"\n";
    cout<<e<<"\n";

    cout << "Matrix Template!" << endl;
    return 0;
}

