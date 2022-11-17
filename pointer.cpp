#include <iostream>
using namespace std;

//  swap two numbers using pointer
void swaping1(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}
/*  p1 and p2 are 2 pointers point to 2 numbers num1 and num2
   In swaping1 function we dont need to pass by reference. We use the pointers
   that hold the addresss of num1 and num2 to change their values despite of passing them to the function
   (*p1= *p2 means num1 = num2 and it do not affected by the term of passing by reference or passing by value)
*/


//  swap two numbers using pointer version 2
void swaping2 (int *&p1,int*&p2){
    int*temp = p1;
    p1 = p2;
    p2 = temp;
}

/* 
in swaping2 function it is more simple that we only need to swap 2 value for each other (swap the holding addresss)
*/

void initialize_2D_Matrix (int **a, int n, int m){
    // n is the numbers of row, m is the numbers of columns

    //first we initialize the level2 pointer, this is the pointer manages the array of level1 pointer's addresss
    a = new int*[n];
    for (int i =0;i<n;i++){
        // in each line we initialize the level1 pointer, that manages the array of numbers each rows
        a[i] = new int[m];
        for (int j = 0; j<m;j++){
            a[i][j]=0;
        }
    }
    
    
    // print the 2d matrix
    for (int i =0;i<n;i++){
        for (int j = 0; j<m;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    // delete the pointers (in other words it is restore the memory,to avoid a memory leak erros)
    for (int i =0;i<n;i++)
        delete a[i];
    delete a;
    // simply, the pointer we use new keyword to initialize, the pointer we use conrespond delete keyword to restore
}

int main()
{
  int num1= 1;
  int num2=2;
  cout << num1 << " " << num2 << endl;
  int*p1 = &num1;
  int *p2 = &num2;
  swaping1(p1,p2);
  //swaping1(p1,p2);
  cout << "after changed " << endl;
  cout << *p1 << " " << *p2 << endl;

  
    int **a;
    cout << "creae a 2D matrix using pointer " << endl;
    initialize_2D_Matrix(a,5,5);
}
