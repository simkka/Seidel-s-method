#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


bool diagonal(double a[10][10], int n){ // функція перевірки діагональної переваги
    int i, j, k = 1;
    double sum;
    for (i = 0; i < n; i++) {  // пробігаємось по масиву та підраховуємо суму
        sum = 0;
        for (j = 0; j < n; j++) sum += abs(a[i][j]);
        sum -= abs(a[i][i]);
        if (sum > a[i][i]){    // порівнюємо суму з коефіціентом
            k = 0;
            cout << a[i][i] << " < " << sum << endl;
        }
        else{
            cout << a[i][i] << " > " << sum << endl;
        }
    }
    cout << endl<< endl<< endl;
    return (k == 1);
}

double max(double *k, int n){   // функція максимуму для подвльших обрахунків
      int i;
      double t=k[0];
      for (i=1;i<n;i++){
            if(t<k[i]) t=k[i];
}
return t; }

double norm(int n, double *x, double *x1 ){       //функція пошуку max|x*(k+1)-x*k|
      int i;
 double k[n];
    for (i=0;i<n;i++){
          k[i]=fabs(x[i]-x1[i]);}
    double r;
    r=max(k,n);
    cout << "|x*(k+1)-x*k| = "<<r<< endl;
    return r;}                        // r = max|x*(k+1)-x*k|

void Zejdel(int n, double a[10][10], double b[10]){
      int i,j;
      double eps=0.000001;   // задаємо розміри масивів та точність
      double A[4][4];
      double B[4];
      for(i=0;i<n;i++){     // пробігаємось по матрицям та зводимо їх до
            for(j=0;j<n;j++){
                  if(i==j) A[i][j]=0;
                  else {
                        A[i][j]=-a[i][j]/a[i][i];
} }
            B[i]=b[i]/a[i][i];
      }
    cout << "Fixed matrix"<< endl;  // виведемо виправлену матрицю
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
}
    cout << "Free digits: " << endl;    // виведемо виправлену матрицю
    for (i = 0; i < n; i++){
    for (i = 0; i < n; i++){
            cout << B[i];
        cout << endl;
    }
    cout << endl<< endl;
    
    
      double x[10], x1[10];
      cout << "First approximation: "<< endl;  // знаходимо та виводимо перше наближення
      for(i=0;i<n;i++) {
            x[i]=B[i];
          cout << "x"<<i+1<<"="<<x[i]<< endl;
      }
        cout << endl;    // починаємо ітерації
            int f=1;
                do{ cout<< endl << "Iteration  "<<f<< endl;   // проводимо інтерації за алгоритмом методу Зейделя
                                       for(i=0;i<n;i++){
                                             double sum=0.0;
                                 x1[i]=x[i];
                                 for(j=0;j<n;j++){
                                       sum+=A[i][j]*x[j];
                                 }
                                 x[i]=sum+B[i];
                                cout << "x"<<i+1<<"="<<x[i]<< endl;
                           }f++;
                           }while(norm(n,x,x1)>eps);   // продовжуємо поки norma > наближення
        
                           printf("\n\nSolution:\n\n");   // виводимо розв'язок
                           for(i=0;i<n;i++){
                               cout << "x"<<i+1<<"="<<x[i]<< endl;}}
}


int main(){
    double  a[10][10], b[10], x[10] ;       // вводимо матрицю
    int i, j = 0;
    int n=4;
    a[0][0]=2.958; a[0][1]=0.147; a[0][2]=0.354; a[0][3]=0.238;  b[0]=0.651;
    a[1][0]=0.127; a[1][1]=2.395; a[1][2]=0.256; a[1][3]=0.273;  b[1]=0.898;
    a[2][0]=0.403; a[2][1]=0.184; a[2][2]=3.815; a[2][3]=0.416;  b[2]=0.595;
    a[3][0]=0.259; a[3][1]=0.361; a[3][2]=0.281; a[3][3]=3.736;  b[3]=0.389;
    cout << endl << endl;
    cout << "Matrix: " << endl;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << "Free members: " << endl;    // вводимо вільні члени
    for (i = 0; i < n; i++){
            cout << b[i];
        cout << endl;
    }
    cout << endl<< endl;

    for (int i = 0; i < n; i++)
        x[i] = 1;

    cout << "Let's check the diagonal advantage: " << endl;
    if (diagonal(a, n)) { // якщо виконується перевага діагоналей
        Zejdel(4,a,b);}  // обраховуємо по функції
    else {
        cout << "mistake" << endl; // якщо не виконується перевага діагоналей
    }
    return 0;
}
