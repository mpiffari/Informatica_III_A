#include "../Matrix/Matrix.h"
#include "../Functions/Square.h"

using namespace std;

int main() {
    Matrix<int>* matrix_a = new Matrix<int>(3,3); // Identity matrix 3 x 3
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    cout<<"Create identity matrix 3x3 MATRIX_A:"<<endl<<matrix_a<<endl;
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    matrix_a->set(0,0,3);
    matrix_a->set(2,1,8);
    matrix_a->set(1,2,7);
    cout<<"Set some new values in MATRIX_A:"<<endl<<matrix_a<<endl;
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    (*matrix_a)(0,0) = 8;
    cout<<"Operator overloading test: change element in position (0,0) of MATRIX_A:"<<endl<<matrix_a<<endl;

    cout<<"Get element in position (0,0) from MATRIX_A with operator:"<<endl<<(*matrix_a)(0,0)<<endl;
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    Matrix<int>* matrix_b = new Matrix<int>(3,3);
    (*matrix_b)(0,0) = 1;
    (*matrix_b)(0,1) = 1;
    (*matrix_b)(0,2) = 1;
    (*matrix_b)(1,0) = 1;
    (*matrix_b)(1,1) = 1;
    (*matrix_b)(1,2) = 1;
    (*matrix_b)(2,0) = 1;
    (*matrix_b)(2,1) = 1;
    (*matrix_b)(2,2) = 1;
    Stringable* matrix_c = matrix_a->add(matrix_b);
    cout<<"Sum [method] (element by element) MATRIX_A + MATRIX_B:"<<endl<<matrix_c<<endl;
    cout<<"Sum [operator] (element by element) MATRIX_A + MATRIX_B:"<<endl<<(Matrix<int>*)(*matrix_a+matrix_b)<<endl;
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    cout<<"Add [method] (element by element) MATRIX_D [5x5] + MATRIX_A [3x3]:"<<endl;
    Matrix<int>* matrix_d = new Matrix<int>(5,5); // Identity matrix 5 x 5
    // Try summation with a 3 x 3 matrix (MATRIX_A)
    Matrix<int>* matrix_e =  new Matrix<int>(3,3);
    matrix_e = matrix_d->add(matrix_a);
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    Matrix<int>* matrix_f = new Matrix<int>(3,3);
    matrix_f = matrix_b->multiply(3);
    cout<<"Multiply (element by element) MATRIX_B * 3:"<<endl<<matrix_f<<endl;
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    Matrix<int>* matrix_g = new Matrix<int>(5,5);// Identity matrix 5 x 5
    list<int>* l = matrix_g->toList();
    cout<<"Rollout as list of MATRIX_G:"<<endl<<matrix_g;
    list<int>::iterator i = l->begin();
    while(i!=l->end()){
        cout << *i << " ";
        i++;
    }
    cout<<endl;
    cout<<"Mean of MATRIX_G: "<<matrix_g->getMean()<<endl;
    cout<<"Max of MATRIX_G: "<<matrix_g->getMax()<<endl;
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    Square s;
    cout<<endl<<"MATRIX_B:"<<endl<<matrix_b<<endl;
    Matrix<int>* matrix_h = new Matrix<int>(3,3);
    matrix_h = matrix_b->multiply(3)->apply(s);
    cout<<"MATRIX_B after multiplication (by 3) and square function application:"<<endl<<matrix_h<<endl;
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|"<<endl;
    cout<<"A\n";
    delete matrix_a;
    cout<<"\nB\n";
    delete matrix_b;
    cout<<"\nC\n";
    delete matrix_c;
    cout<<"\nD\n";
    delete matrix_d;
    cout<<"\nE\n";
    delete matrix_e;
    cout<<"\nF\n";
    delete matrix_f;
    cout<<"\nG\n";
    delete matrix_g;
    cout<<"\nH\n";
    delete matrix_h;
    cout<<"|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n"<<endl;

    return 0;
}
