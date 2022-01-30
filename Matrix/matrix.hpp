


class matrix{
    struct info{
        double *array;
        unsigned int x;
        unsigned int y;
    } desc;

public:
    matrix(unsigned int x, unsigned int y);
    matrix(unsigned int x, unsigned int y, double p);
    void T();
    void print();
    double *adress();
    unsigned int size(char key = 's');
    matrix operator=(matrix old_array);
    matrix operator+(matrix arr2);
    matrix operator*(double a);
};

matrix operator*(double a, matrix arr2);


