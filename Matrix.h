#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



template<class T>
class Matrix
{
private:

    int rows;
    int cols;
    vector< vector<T> > m;


public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();

    void initMatrix();
    int getRows() const;
    void setRows(int value);
    int getCols() const;
    void setCols(int value);

    void setValue(int row, int cols, T value);
    T getValue(int row, int cols);
    void showMatrix();

    T getData();

    void suma(const Matrix &a, const Matrix &b);
    Matrix<T> &suma(const Matrix &b) const;
    Matrix<T> &operator +(const Matrix &b);

    void resta(const Matrix &a, const Matrix &b);
    Matrix<T> &resta(const Matrix &b) const;
    Matrix<T> &operator -(const Matrix &b);

    Matrix<T> &mult(const Matrix &a, const Matrix &b);
    Matrix<T> &operator *(const Matrix &b);

    void scalar(T scalar);
    Matrix<T> &scalar(const Matrix &a, T scalar) const;

    void transpose(const Matrix a);
    Matrix<T> &transpose() const;

    void ingresarDatos( string filename);
    void guardarDatos(string filename);

    friend ostream& operator<< (ostream &o, const Matrix<T> &a)
    {
        o<<"Rows: "<<a.rows<<", Cols: "<<a.cols<<"\n";
        for(int i = 0; i<a.rows; i++)
        {
            for(int j = 0; j<a.cols; j++)
            {
                o<<a.m[i][j]<<" ";
            }
            o<<"\n";
        }
        return o;
    }
};

template<class T>
Matrix<T>::Matrix()
{
    m.resize(0);
    rows = 0;
    cols =0;

}

template<class T>
Matrix<T>::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    m.resize(rows);

    for(int i=0; i<m.size();i++)
    {
        m[i].resize(cols);
    }
}

template<class T>
Matrix<T>::~Matrix()
{

}
template<class T>
int Matrix<T>::getRows() const
{
    return rows;
}

template<class T>
void Matrix<T>::setRows(int value)
{
    rows = value;
}
template<class T>
int Matrix<T>::getCols() const
{
    return cols;
}
template<class T>
void Matrix<T>::setCols(int value)
{
    cols = value;
}

template<class T>
void Matrix<T>::setValue(int row, int cols, T value)
{
     m[rows][cols] = value;
}

template<class T>
T Matrix<T>::getValue(int row, int cols)
{
   return m[rows][cols];
}

template<class T>
T Matrix<T>::getData()
{
    return m;
}


template<class T>
void Matrix<T>::initMatrix()
{
    m.resize(rows);

    for(int i=0; i<m.size();i++)
    {
        m[i].resize(cols);
    }
}

template<class T>
void Matrix<T>::suma(const Matrix &a, const Matrix &b)
{

    this->cols = a.getCols();    this->rows= a.getRows();

    for(int i = 0; i<this->rows; i++)
    {
        for(int j=0; j<this->cols; j++)
        {
            this->m[i][j]=a.m[i][j]+b.m[i][j];
        }
    }

}

template<class T>
Matrix<T> &Matrix<T>::suma(const Matrix &b) const
{

    Matrix<T> *c = new Matrix(b.rows, b.cols);

    for(int i = 0; i<c->rows; i++)
    {
        for(int j = 0; j<c->cols; j++)
        {
           c->m[i][j] = this->m[i][j] + b.m[i][j];
        }
    }
    return *c;
}

template<class T>
Matrix<T> &Matrix<T>::operator +(const Matrix &b)
{
    return this->suma(b);
}

template<class T>
void Matrix<T>::resta(const Matrix &a, const Matrix &b)
{
    this->cols = a.getCols();   this->rows= a.getRows();

    for(int i = 0; i<this->rows; i++)
    {
        for(int j=0; j<this->cols; j++)
        {
            this->m[i][j]=a.m[i][j]-b.m[i][j];
        }
    }
}

template<class T>
Matrix<T> &Matrix<T>::resta(const Matrix &b) const
{
    Matrix<T> *c = new Matrix(b.rows, b.cols);

    for(int i = 0; i<c->rows; i++)
    {
        for(int j = 0; j<c->cols; j++)
        {
            c->m[i][j] = this->m[i][j] - b.m[i][j];
        }
    }

    return *c;
}

template<class T>
Matrix<T> &Matrix<T>::operator -(const Matrix &b)
{
    return this->resta(b);
}


template<class T>
Matrix<T> &Matrix<T>::mult(const Matrix &a, const Matrix &b)
{
    Matrix<T> *c = new Matrix<T>(a.cols, b.rows);
    if(a.cols == b.rows)
    {
        for (int i = 0; i < c->rows; i++)
        {
            for (int j = 0; j < c->cols; j++)
            {
                c->m[i][j]=0;
                for (int k = 0; k < c->cols; k++)
                {
                    c->m[i][j] += a.m[i][k]*b.m[k][j];
                }
            }
        }
    }
    else{
    cout<<"No se puede multiplicar"<<endl;
    }

    return *c;
}

template<class T>
Matrix<T> &Matrix<T>::operator *(const Matrix &b)
{
    Matrix<T> *c = new Matrix<T>(b.rows, this->cols);
    if(b.rows == this->cols)
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                c->m[i][j]=0;
                for (int k = 0; k < this->cols; k++)
                {
                    c->m[i][j]=c->m[i][j] + (this->m[i][k]*b.m[k][j]);
                }
            }
        }
    }
    else{
        cout<<"No se puede multiplicar"<<endl;
    }

    return *c;
}

template<class T>
void Matrix<T>::scalar(T scalar)
{
    for(int i = 0; i<this->rows; i++)
    {
         for(int j = 0; j<this->cols; j++)
         {
             this->m[i][j] = this->m[i][j]*scalar;
         }
    }
}

template<class T>
Matrix<T> &Matrix<T>::scalar(const Matrix &a, T scalar) const
{
   Matrix<T> *c = new Matrix<T>(a.rows, a.cols);

   for(int i = 0; i<c->rows; i++)
   {
        for(int j = 0; j<c->cols; j++)
        {
            c->m[i][j] = a.m[i][j]*scalar;
        }
   }

   return *c;


}

template<class T>
void Matrix<T>::transpose(const Matrix a)
{
   for(int i = 0; i<this->rows; i++)
   {
        for(int j=0; j<this->cols; j++)
        {
            this->m[j][i]=a.m[i][j];
        }
   }
}


template<class T>
Matrix<T> &Matrix<T>::transpose() const
{

   Matrix<T> *c = new Matrix<T>(this->cols, this->rows);
   for(int i = 0; i<c->cols; i++)
   {
        for(int j=0; j<c->rows; j++)
        {
            c->m[j][i]=this->m[i][j];
        }
   }

   return *c;

}

template<class T>
void Matrix<T>::ingresarDatos( string filename)
{


    ifstream file;
    file.open(filename.c_str());
    if(file.is_open())
    {
    file>>this->rows;    file>>this->cols;

    this->initMatrix();
    for(int i = 0;i<this->rows;i++)
    {
        for(int j = 0;j<this->cols;j++)
            {
            file >> this->m[i][j];
            }
    }

         file.close();
    }
}

template<class T>
void Matrix<T>::guardarDatos(string filename)
{
   ofstream file;
   file.open(filename.c_str());
   if(file.is_open())
   {
   file<<this->rows<<" "<<file<<this->cols<<endl;

   for(int i = 0;i<this->rows;i++)
   {
        for(int j = 0;j<this->cols;j++)
        {
            file<<this->m[i][j]<<" ";
        }

        file<<endl;
   }


   file.close();

   }
}

template<class T>
void Matrix<T>::showMatrix()
{
    cout<<"Rows: "<<this->rows<<", Cols: "<<this->cols<<endl;
    for(int i = 0; i<this->rows; i++)
    {
        for(int j = 0; j<this->cols; j++)
        {
            cout<<m[i][j]<<" ";
        }

        cout<<endl;
    }
}




#endif // MATRIX_H
