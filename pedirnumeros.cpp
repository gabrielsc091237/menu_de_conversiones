#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cout<<"Ingrese un valor para A";
    cin>>a;
    cout<<"Ingrese un valor para B";
    cin>>b;
    cout<<"Ingrese un valor para C";
    cin>>c;
    int suma = a + b + c;
    int resta = a - b - c;
    int multiplicacion = a * b * c;

    double promedio = static_cast <double>(suma)/3; 
    cout<<"el promedio es: " << promedio << endl;
    cout<<"la suma es: " <<suma<<endl;
    cout<<"la resta es: " <<resta<<endl;
    cout<<"la multiplicacion es: " <<multiplicacion<<endl;





    return 0;

}