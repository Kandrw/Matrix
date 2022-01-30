
#include "matrix.hpp"
#include <iostream>
using namespace std;



matrix::matrix(unsigned int x, unsigned int y){
    desc.x = x; desc.y = y;
    desc.array = new double[x*y]();
}
matrix::matrix(unsigned int x, unsigned int y, double p){
        
        desc.x = x; desc.y = y;
        desc.array = new double[x*y]();
        int i,i2;
        for(i = 0; i < y; ++i){
            for(i2 = 0; i2 < x; ++i2){
                *(desc.array + i * x + i2) = p;
            }
        }
       
}

void matrix::T(){
        int i,i2;
        int i3, i4;
        double *array2 = new double[desc.x*desc.y]();
        for(i = 0, i3 = 0; i < desc.x; ++i){
            for(i2 = 0; i2 < desc.y; ++i2){
                *(array2 + i * desc.y+i2) = *(desc.array + i2 * desc.x+i); 
            }
        }
        unsigned q = desc.x;
        desc.x = desc.y;
        desc.y = q;
        delete [] desc.array;
        desc.array = array2;
}


void matrix::print(){
        int i, i2;
        cout<<"lenx = "<<desc.x<<"\nleny = "<<desc.y<<endl;
        for(i = 0; i < desc.y; ++i){
            for(i2 = 0; i2 < desc.x; ++i2){
                cout<<*(desc.array+i*desc.x+i2)<<" ";
            }
            cout<<endl;
        }
}
double* matrix::adress(){
        return desc.array;
}
unsigned int matrix::size(char key/* = 's'*/){
        if(key == 'y'){
            return desc.y;
        }
        else if(key == 'x'){
            return desc.x;
        }
        else{
            return desc.x*desc.y;
        }
}



matrix matrix::operator=(matrix old_array){
        unsigned int x2 = old_array.size('x');
        unsigned int y2 = old_array.size('y');
        desc.x = x2; desc.y = y2;

        int i,i2;
        delete [] desc.array;
        desc.array = new double[y2 * x2]();
        double *array2 = old_array.adress();
        
        for( i = 0; i < y2; ++i){
            for(i2 = 0; i2 < x2; ++i2){
                *(desc.array + i * x2 + i2) = *(array2 + i * x2 + i2);
            }
        }
}

matrix matrix::operator+(matrix arr2){
        unsigned int x2 = arr2.size('x');
        unsigned int y2 = arr2.size('y');
        if(desc.x == x2 && desc.y == y2){
            double * array2 = arr2.adress();
            matrix newarr = matrix(x2,y2);
            double * array3 = newarr.adress();
            int i,i2;
            for(i = 0; i < y2; ++i){
                for(i2 = 0; i2 < x2; ++i2){
                    *(array3+i*x2 + i2) = *(desc.array+i*x2 + i2) + *(array2+i*x2 + i2);
                }
            }
            return newarr;

        }
        else{
            /*
            При несоответствии размеров матриц из каждой выюирается наименьшее x и y 
            и создается новая матрица(x y) 
            */
            unsigned int x3 = x2>desc.x?desc.x:x2;
            unsigned int y3 = y2>desc.y?desc.y:y2;
            double * array2 = arr2.adress();
            matrix newarr = matrix(x3,y3);
            double * array3 = newarr.adress();
            int i, i2;
            for(i = 0; i < y3; ++i){
                for(i2 = 0; i2 < x3; ++i2){
                    *(array3 + i*x3 + i2) = *(desc.array + i*x3 + i2) + *(array2 + i*x3 + i2);
                }
            }
            return newarr;
        }

}

matrix matrix::operator*(double a){
        int i, i2;
        matrix newarr = matrix(desc.x, desc.y);
        double *array2 = newarr.adress();
        for(i = 0; i < desc.y; ++i){
            for(i2 = 0; i2 < desc.x; ++i2){
                *(array2 + i*desc.x + i2) = *(desc.array + i*desc.x + i2) * a;
            }
        }
        return newarr;
}


matrix operator*(double a, matrix arr2){
        int i, i2;
        matrix newarr = matrix(arr2.size('x'), arr2.size('y'));
        double *array2 = newarr.adress();
        for(i = 0; i < arr2.size('y'); ++i){
            for(i2 = 0; i2 < arr2.size('x'); ++i2){
                *(array2 + i*arr2.size('x') + i2) = *(arr2.adress() + i*arr2.size('x') + i2) * a;
            }
        }
        return newarr;
}





