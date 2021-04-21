#include <iostream>
void fibonacci(int n, int m, int a, int b);
using namespace std;
int main()
{
    int n, a=1, b=1, c;
    cout<<"Ingresa el numero de veces que quieres que se ejecute la serie: ";
    cin>>n;
    fibonacci(n,1, 1, 1);
    return 0;
}
void fibonacci(int n, int m, int a, int b){
    int c;
    if(m<=n){
        if(m==1 || m==2){
            cout<<"F("<<m<<")= "<<a<<endl;
            fibonacci(n,m+1,a,b);
        }
        else{
           c=a+b;
           cout<<"F("<<m<<")= "<<c<<endl;
           fibonacci(n,m+1,b,c);
        }
    }
}
