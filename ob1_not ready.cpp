#include <iostream>
#include "stdlib.h"
#include <ctime>

using namespace std;


class matrix{
    unsigned int con;
    double *array;
    unsigned int xy[2];//x,y

public:
    matrix(unsigned int x, unsigned int y){

        xy[0] = x; xy[1] = y;
        array = new double[x*y]();
        con = 1;
    }
    matrix(unsigned int x, unsigned int y, auto p){
        
        
        xy[0] = x; xy[1] = y;
        array = new double[x*y]();
        int i,i2;
        for(i = 0; i < xy[1]; ++i){
            for(i2 = 0; i2 < xy[0]; ++i2){
                *(array + i * xy[0] + i2) = p;
            }
        }
        con = 2;
    }
    /*
    matrix(matrix new_array){
        
    }
    */

    void T(){
        int i,i2;
        int i3, i4;
        double *array2 = new double[xy[0]*xy[1]]();
        for(i = 0, i3 = 0; i < xy[0]; ++i){
            for(i2 = 0; i2 < xy[1]; ++i2){
                *(array2 + i * xy[1]+i2) = *(array + i2 * xy[0]+i); 
            }
        }
        unsigned q = xy[0];
        xy[0] = xy[1];
        xy[1] = q;
        delete [] array;
        array = array2;
    }
    void print(){
        int i, i2;
        cout<<"lenx = "<<xy[0]<<"\nleny = "<<xy[1]<<endl;
        for(i = 0; i < xy[1]; ++i){
            for(i2 = 0; i2 < xy[0]; ++i2){
                cout<<*(array+i*xy[0]+i2)<<" ";
            }
            cout<<endl;
        }
    }
    unsigned int* size(){
        return xy;
    }
    double *adress(){
        return array;
    }
    matrix operator+(matrix arr2){
        unsigned int *xy2 = arr2.size();
        if(xy[0] == xy2[0] && xy[1] == xy2[1]){

        }
        else{
            //cout<<"\nError\n";
            throw "Error: the size of the matrix does not match!";
        }
    }

    matrix operator<=(matrix new_array){

    }
    matrix operator=(matrix old_array){
        unsigned int * xy2 = old_array.size();

        xy[0] = xy2[0]; xy[1] = xy2[1];
        con = 3;
        int i,i2;
        delete [] array;
        array = new double[xy[0] * xy[1]]();
        double *array2 = old_array.adress();
        for( i = 0; i < xy[1]; ++i){
            for(i2 = 0; i2 < xy[0]; ++i2){
                *(array + i * xy[0] + i2) = *(array2+i*xy[0] + i2);
            }
        }
    }

};




void zalp(double dat[], int x, int y, int d1, int d2){
    int i, i2;
    for(i = 0; i < y; ++i){
        for(i2 = 0; i2 < x; ++i2){
            double c = rand()%d2+d1;
            *(dat + i * x + i2) = c;
        }
    }


}



int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    int x = 21, y = 5;

    matrix data = matrix(x,y, 9);
    matrix data2 = matrix(6,6, 10);
    


    double *d2 = data.adress();
    zalp(d2, x, y, 30, 40);
    
    
    data.print();
    data2.print();
    data.T();
    data2 = data;
    //data.print();
    //data.T();
    //data.print();
    data2.print();
    unsigned int *xy = data.size();
    cout<<xy[0]<<" - "<<xy[1]<<endl;
    cout<<"The end!\n";
}








