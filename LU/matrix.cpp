#include"matrix.h"

template<class T>
ostream& operator<<(ostream& out,const Matrix<T>& o){
    for(int i=0;i<o.m_row;i++){
        for(int j=0;j<o.m_col;j++){
            out<<o.m_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;
}

template<class T>
Matrix<T>::Matrix(int fila,int col):m_row(fila),m_col(col){
    m_matrix = new T*[m_row];
    for(int i=0;i<m_row;i++){
        m_matrix[i]=new T[m_col];
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix &m):m_row(m.m_row),m_col(m.m_col){
    m_matrix = new T*[m_row];
    for(int k=0;k<m_row;k++){
        m_matrix[k]=new T[m_col];
    }
    for (int i=0; i < m_row; i++){
        for (int j=0; j < m_col; j++){
            *(*(m_matrix + i) + j)=*(*(m.m_matrix + i) + j);
        }
    }
}

template<class T>
Matrix<T>::~Matrix(){
    for(int i=0;i<m_row;i++)
        delete[] m_matrix[i];
    delete[] m_matrix;
}

template<class T>
void Matrix<T>::inicializar(){
    cout<<"ingrese los valores de la matrix: "<<endl;
    int elem;
    for (int i=0; i < m_row; i++){
        for (int j=0; j < m_col; j++){
            cout << "\nRow " << (i+1) << " Col " << (j+1) << " :";
            cin >> elem; 
            m_matrix[i][j]=elem;
        }
    }
}

template<class T>
void Matrix<T>::setMatrix(const vector<vector<T> > xs){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++)
            this->m_matrix[i][j]=xs[i][j];
    }
}

template<class T>
void Matrix<T>::zerox(){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++)
            m_matrix[i][j]=0;
    }
}

template<class T>
void Matrix<T>::identidad(){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            if(i==j)
                m_matrix[i][j]=1;
            else
                m_matrix[i][j]=0;
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix &o){
    Matrix rpta(m_row,m_col);
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            rpta.m_matrix[i][j]=m_matrix[i][j]+o.m_matrix[i][j];
        }
    }
    return rpta;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix &o){
    Matrix rpta(m_row,o.m_col);
    T total=0;
    for(int i=0;i<m_row;++i){
        for(int j=0;j<o.m_col;++j){
            for(int z=0;z<m_col;++z){
                total += m_matrix[i][z] * o.m_matrix[z][j];
            }
            rpta.m_matrix[i][j] =total;
            total=0;
        }
    }
    return rpta;
}

template<class T>
void Matrix<T>::operator=(const Matrix &o){
    m_row=o.m_row;
    m_col=o.m_col;
    m_matrix=new T*[m_row];
    for(int k=0;k<m_row;k++){
        m_matrix[k]=new T[m_col];
    }
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            *(*(m_matrix + i) + j)=*(*(o.m_matrix + i) + j);
        }
    }
}

template<class T>
void Matrix<T>::imprimir(){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            cout<<m_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template<class T>
void Matrix<T>::resizeCol(int nuevo){
    int minsize=(nuevo>m_col ? m_col : nuevo);
    for(int i=0;i<m_row;i++){
        T *xs=new T[nuevo];
        for(int j=0;j<minsize;j++){
            xs[j]=m_matrix[i][j];
        }
        delete[] m_matrix[i];
        m_matrix[i]=xs;
    }
    m_col=nuevo;
}

template<class T>
void Matrix<T>::insertCol(vector<T> xs){
    resizeCol(m_col+1);
    for(int i=0;i<m_row;i++)
        m_matrix[i][m_col-1]=xs[i];
}

template<class T>
void Matrix<T>::swapRow(int fila_1,int fila_2){
    if(fila_1>m_row || fila_2>m_row){
        cout<<"fila de rango"<<endl;
    }
    else{
        T temp;
        for(int i=0;i<m_col;i++){
            temp=m_matrix[fila_1][i];
            m_matrix[fila_1][i]=m_matrix[fila_2][i];
            m_matrix[fila_2][i]=temp;
        }
    }
}

template<class T>
void Matrix<T>::escalonar(){
    for(int j=0;j<m_row-1;j++){
        for(int i=j+1;i<m_row;i++){
            T m=m_matrix[i][j]/m_matrix[j][j];
            for(int k=0;k<m_col;k++){
                m_matrix[i][k]-=m*m_matrix[j][k];
                cout<<m_matrix[i][k]<<" ";
            }
            cout<<endl;
        }
    }
}

template<class T>
void Matrix<T>::escalonarPivote(){
    for(int j=0;j<m_row-1;j++){
        T max_val=m_matrix[j][j];
        int max_file=j;
        for(int x=j+1;x<m_row;x++){
            if(max_val<m_matrix[x][j]){
                max_val=m_matrix[x][j];
                max_file=x;
            }
        }
        if(j!=max_file)
            swapRow(j,max_file);
        for(int i=j+1;i<m_row;i++){
            T m=m_matrix[i][j]/m_matrix[j][j];
            for(int k=0;k<m_col;k++){
                m_matrix[i][k]-=m*m_matrix[j][k];
            }
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::inversa(){
    Matrix<T> A=*this;
    Matrix inv(m_row,m_col);
    inv.identidad();
    //escalonamiento inferior 000
    for(int j=0;j<m_row-1;j++){
        T max_val=A.m_matrix[j][j];
        int max_file=j;
        //identificacion del mayor valor en la columna j
        for(int x=j+1;x<m_row;x++){
            if(max_val<A.m_matrix[x][j]){
                max_val=A.m_matrix[x][j];
                max_file=x;
            }
        }
        if(j!=max_file){
            A.swapRow(j,max_file);
            inv.swapRow(j,max_file);
        }
        //Resta de Filas para escalonar
        for(int i=j+1;i<m_row;i++){
            T m=A.m_matrix[i][j]/A.m_matrix[j][j];
            for(int k=0;k<m_col;k++){
                A.m_matrix[i][k]-=m*A.m_matrix[j][k];
                inv.m_matrix[i][k]-=m * inv.m_matrix[j][k];
            }
        }
    }
    // igualando a 1 la diagonal principal
    for(int i=0;i<m_row;i++){
        T max_val=A.m_matrix[i][i];
        for(int j=0;j<m_col;j++){
            A.m_matrix[i][j]/=max_val;
            inv.m_matrix[i][j]/=max_val;
        }
    }
    //escalonamimento superior 000
    for(int j=m_row-1;j>0;j--){
        for(int i=j-1;i>-1;i--){
            T m=A.m_matrix[i][j]/A.m_matrix[j][j];
            for(int k=0;k<m_col;k++){
                A.m_matrix[i][k]-=m*A.m_matrix[j][k];
                inv.m_matrix[i][k]-=m * inv.m_matrix[j][k];
            }
        }
    }
    return inv;
}

template<class T>
Matrix<T> Matrix<T>::transpuesta(){
    Matrix trans(m_col,m_row);
    for(int i=0;i<m_row;i++)
        for(int j=0;j<m_col;j++)
            trans.m_matrix[j][i]=m_matrix[i][j];
    return trans;
}

template<class T>
vector<T> Matrix<T>::getCol(const int pos){
    vector<T> xs;
    for(int i=0;i<m_row;i++)
        xs.push_back(m_matrix[i][pos]);
    return xs;
}

template<class T>
vector<T> Matrix<T>::sust_regresiva(vector<T> xs){
    vector<T> rpta(m_row,0);
    for(int i=m_row-1;i>=0;i--){
        T s=0;
        for(int j=i;j<m_row;j++){
            s+=m_matrix[i][j]*rpta[j];
        }
        rpta[i]=(xs[i]-s)/m_matrix[i][i];
    }
    return rpta;
}

template<class T>
vector<T> Matrix<T>::sust_progresiva(vector<T> xs){
    vector<T> rpta(m_row,0);
    for(int i=0;i<m_row;i++){
        T s=0;
        for(int j=0;j<i;j++){
            s+=m_matrix[i][j]*rpta[j];
        }
        rpta[i]=(xs[i]-s)/m_matrix[i][i];
    }
    return rpta;
}

template<class T>
vector<T> Matrix<T>::elim_gauss(vector<T> xs){
    insertCol(xs);
    escalonarPivote();
    vector<T> temp=getCol(m_col-1);
    vector<T> r=this->sust_regresiva(temp);
    return r;
}

