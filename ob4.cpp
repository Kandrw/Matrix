#include <iostream>
#include "stdlib.h"
#include <ctime>

using namespace std;





class matrix{
    
    struct info{
        double *array;
        unsigned int x;
        unsigned int y;
    } desc;

public:
    matrix(unsigned int x, unsigned int y){

        desc.x = x; desc.y = y;
        desc.array = new double[x*y]();

    }
    matrix(unsigned int x, unsigned int y, auto p){
        
        desc.x = x; desc.y = y;
        desc.array = new double[x*y]();
        int i,i2;
        for(i = 0; i < y; ++i){
            for(i2 = 0; i2 < x; ++i2){
                *(desc.array + i * x + i2) = p;
            }
        }
       
    }
    void T(){
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
    void print(){
        int i, i2;
        cout<<"lenx = "<<desc.x<<"\nleny = "<<desc.y<<endl;
        for(i = 0; i < desc.y; ++i){
            for(i2 = 0; i2 < desc.x; ++i2){
                cout<<*(desc.array+i*desc.x+i2)<<" ";
            }
            cout<<endl;
        }
    }
    double *adress(){
        return desc.array;
    }
    unsigned int size(char key = 's'){
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


    matrix operator=(matrix old_array){
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

    matrix operator+(matrix arr2){
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
            //throw string("Error: the size of the matrix does not match!");
            //return nullptr;
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


    matrix operator*(double a){
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
   

};

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


void zalp(double dat[], int x, int y, int d1, int d2){
    int i, i2;
    for(i = 0; i < y; ++i){
        for(i2 = 0; i2 < x; ++i2){
            double c = rand()%d2+d1;
            *(dat + i * x + i2) = c;
        }
    }


}
// test print
void test1(){
    int test = 1;
    cout<<"\nTEST print"<<endl;

    int x = 21, y = 5;
    matrix d1 = matrix(x,y, 1);
    
    d1.print();
    cout<<"The test "<<test<<" is passed!\n";
}

// test transposition
void test2(){
    cout<<"\nTEST transposition"<<endl;
    int test = 2;
    int x = 21, y = 5;
    matrix d1 = matrix(x,y, 2);
    d1.print();
    d1.T();
    d1.print();
    cout<<"The test "<<test<<" is passed!\n";
}

// test adress
void test3(){
    cout<<"\nTEST adress"<<endl;
    int test = 3;
    int x = 10, y = 5;
    matrix d1 = matrix(x, y, 3);
    d1.print();
    double *d2 = d1.adress();
    zalp(d2,x,y, 40, 50);
    d1.print();
    cout<<"The test "<<test<<" is passed!\n";

}

// test size
void test4(){
    cout<<"\nTEST size"<<endl;
    int test = 4;
    int x = 12, y = 7;
    matrix d1 = matrix(x,y,4);
    unsigned int x2 = d1.size('x');
    unsigned int y2 = d1.size('y');
    unsigned int size = d1.size();
    cout<<"x = "<<x<<"  y = "<<y<<"  xy = "<<x*y<<endl;
    cout<<"x2 = "<<x2<<"  y2 = "<<y2<<"  xy2 = "<<x2*y2<<endl;
    cout<<"The test "<<test<<" is passed!\n";

}

// test =
void test5(){
    cout<<"\nTEST ="<<endl;
    int test = 5;
    int x1 = 21, y1 = 3;
    int x2 = 1, y2 = 7;
    matrix d1 = matrix(x1, y1, 5);
    matrix d2 = matrix(x2, y2, 1.2);
    cout<<"\ttest type(matrix)"<<endl;
    cout<<"|\t\td1\t\t|"<<endl;
    d1.print();
    cout<<"|\t\td2!=d1\t\t|"<<endl;
    d2.print();
    cout<<"|\t\td2=d1\t\t|"<<endl;
    d2 = d1;
    d2.print();
    cout<<"|\t\td3(not initialized)=d1\t\t|"<<endl;
    matrix d3 = d1;
    d3.T();
    d3.print();
    cout<<"The test "<<test<<" is passed!\n";

}
// test + and type(info)
void test6(){
    cout<<"TEST +"<<endl;
    int test = 6;
    int x1 = 10, y1= 5;
    int x2 = 1, y2 = 7;
    matrix d1 = matrix(x1,y1, 6);
    matrix d2 = matrix(x1, y1, 5.5);
    matrix d3 = matrix(x2, y2, 7.8);
    cout<<"|\t\td3\t\t|"<<endl;
    d3.print();
    cout<<"|\t\td3 = d1+d2\t\t|"<<endl;
    d3 = d1+d2;
    d3.print();
    cout<<"|\t\td4(not initialized) = d1+d3+d1\t\t|"<<endl;
    matrix d4 = d1+d3+d1;
    d4.print();
    cout<<"|\t\td3 = d5+d1, d5.y != d1.y && d5.x != d1.x  \t\t|"<<endl;
    matrix d5 = matrix(y1,x1,8);
    d3 = d5+d4;
    d3.print();
    cout<<"The test "<<test<<" is passed!\n";
}
// test multiplying a matrix by a number
void test7(){
    cout<<"TEST multiplying a matrix by a number"<<endl;
    int test = 7;
    int x1 = 10, y1= 5;
    matrix d1 = matrix(x1, y1, 7);
    cout<<"|\t\td1\t\t|"<<endl;
    d1.print();
    cout<<"|\t\td1 * 29\t\t|"<<endl;
    matrix d2 = d1*29;
    d2.print();
    cout<<"|\t\t7.7*d1\t\t|"<<endl;
    d2 = 7.7*d1;
    d2.print();
    //cout<<"The test "<<test<<" is passed!\n";

}




int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    cout<<"The end!\n";
}








