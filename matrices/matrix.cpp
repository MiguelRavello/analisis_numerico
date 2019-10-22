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
void Matrix<T>::insertCol(const vector<T> xs){
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
        /* max_val elemento pivote */
        T max_val=m_matrix[j][j];
        int max_file=j;
        for(int x=j+1;x<m_row;x++){
            /* hallando el valor maximo para q se pivote */
            if(max_val<abs(m_matrix[x][j])){
                max_val=m_matrix[x][j];
                max_file=x;
            }
        }
        /* donde esta la fila con el valor q va ser pivote
         * se lo lleva para arriba */
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
void Matrix<T>::escalonadoReducido(){
    for(int j=0;j<m_row-1;j++){
        /* max_val elemento pivote */
        T max_val=m_matrix[j][j];
        int max_file=j;
        for(int x=j+1;x<m_row;x++){
            /* hallando el valor maximo para q se pivote */
            if(max_val<abs(m_matrix[x][j])){
                max_val=m_matrix[x][j];
                max_file=x;
            }
        }
        /* donde esta la fila con el valor q va ser pivote
         * se lo lleva para arriba */
        if(j!=max_file)
            swapRow(j,max_file);
        for(int i=j+1;i<m_row;i++){
            T m=m_matrix[i][j]/m_matrix[j][j];
            for(int k=0;k<m_col;k++){
                m_matrix[i][k]-=m*m_matrix[j][k];
            }
        }
    }
    // igualando a 1 la diagonal principal
    for(int i=0;i<m_row;i++){
        T max_val=m_matrix[i][i];
        for(int j=0;j<m_col;j++){
            m_matrix[i][j]/=max_val;
        }
    }
    //escalonamimento superior 000
    for(int j=m_row-1;j>0;j--){
        for(int i=j-1;i>-1;i--){
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
vector<T> Matrix<T>::getFila(const int pos){
    vector<T> xs;
    for(int i=0;i<m_col;i++)
        xs.push_back(m_matrix[pos][i]);
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
    bool verdad=rangoAumentadoComparado(xs);
    /* matriz aumentada */
    if(verdad){
        insertCol(xs);
        /* matriz escalonada reducida por filas */
        escalonarPivote();
        vector<T> temp=getCol(m_col-1);
        vector<T> r=this->sust_regresiva(temp);
        return r;
    }
    /* tiene infinitas soluciones o es inconsistente */
    vector<T> nulo(m_row,-1);
    return nulo;
}

template<class T>
vector<T> Matrix<T>::elim_gauss_reducido(const vector<T> xs){
    bool verdad=rangoAumentadoComparado(xs);
    if(verdad){
        insertCol(xs);
        escalonadoReducido();
        vector<T> r=getCol(m_col-1);
        return r;
    }
    /* tiene infinitas soluciones o es inconsistente */
    vector<T> nulo(m_row,-1);
    return nulo;
}

template<class T>
int Matrix<T>::rango(){
    Matrix<T> C=*this;
    bool verdad=true;
    /* asumimos q no tiene filas nulas */
    int contador=m_row;
    C.escalonarPivote();
    for(int i=0;i<C.m_row;i++){
        for(int j=0;j<C.m_col;j++){
            /*recorre la fila buscando un elemento diferente de cero*/
            if(C.m_matrix[i][j]!=0){
                verdad=false;
                break;
            }
        }
        if(verdad){
            /* cuando no lo encuentra, el rango inicial se reduce */
            contador--;
        }
        verdad=true;
    }
    return contador;
}

template<class T>
bool Matrix<T>::rangoAumentadoComparado(const vector<T> xs){
    Matrix<T> A=*this;
    Matrix<T> Ab=*this;
    Ab.insertCol(xs);
    int i=A.rango();
    int j=Ab.rango();
    if(i==j){
        if(m_row==i){
            //cout<<"el sistema tiene solucion unica"<<endl;
            return true;
        }
        else{
            //cout<<"el sistema tiene infinitas soluciones"<<endl;
            return false;
        }
    }
    else{
        //cout<<"el sistema no tiene solucion"<<endl;
        return false;
    }
    /* el sistema no tiene solucion  */
    /*si el rango(A)==rango(Ab) tiene solucion
     * */
}

template<class T>
Matrix<T> Matrix<T>::cambioBase(const vector<vector<T> > xs){
    Matrix<T> base1=*this;
    /* Los vectores de B1 les hago la transpuesta
     * dado que es la forma para q entre en un
     * sistema de ecuaciones */
    base1=base1.transpuesta();
    Matrix base2(m_row,m_col);
    base2.setMatrix(xs);
    base2=base2.transpuesta();
    /* creo la matriz respuesta R de m_row filas 
     * la cual se le va insertar las coordenadas
     * de la elimininacion de gauss
     * de cada vector de B1 */
    Matrix<T> R(m_row,0);
    for(int j=0;j<m_col;j++){
        vector<T> insertado=base1.getCol(j);
        Matrix<T> base_2=base2;
        vector<T> rpta=base_2.elim_gauss_reducido(insertado);
        R.insertCol(rpta);
    }
    return R;
    /* rpta son las coordenadas de a1v1+a2v2+...+anvn para B1 */
}

template<class T>
Matrix<T> Matrix<T>::coordenadaB1_B2(const vector<vector<T> > xs,const vector<T> ys){
    /* Matriz cambio de base de B1 a B2 */
    Matrix<T> M12=this->cambioBase(xs);
    Matrix<T> B1=this->transpuesta();
    /* Coordenadas en B1 del vector v::ys*/
    vector<T> coordenadaB1=B1.elim_gauss_reducido(ys);
    Matrix<T> CB1(m_row,0);
    CB1.insertCol(coordenadaB1);
    cout<<"matrix cambio de base de B1 a B2"<<endl;
    cout<<M12<<endl;
    cout<<"coordenadas de v en B1"<<endl;
    cout<<CB1<<endl;
    cout<<"coordenadas de v en B2"<<endl;
    Matrix<T> R=M12*CB1;
    cout<<R<<endl;
    return R;
}

template<class T>
Matrix<T> Matrix<T>::gramSchmith(){
    Matrix<T> G(m_row,m_col);
    vector<vector<T> > xs;
    for(int i=0;i<m_row;i++){
        vector<T> temp1(m_col,0);
        vector<T> a=this->getFila(i);
        for(int j=0;j<i;j++){
            vector<T> b=xs[j];
            T k=productoInterno<T>(a,b);
            vector<T> temp2=productoPorEscalar<T>(k,b);
            temp1=sumaVectores<T>(temp1,temp2);
        }
        if(temp1.size()==0){
            vector<T> temp3=a;
            T modulo=1.0/sqrt(productoInterno<T>(temp3,temp3));
            temp3=productoPorEscalar<T>(modulo,temp3);
            xs.push_back(temp3);
        }
        else{
            temp1=productoPorEscalar<T>(-1,temp1);
            vector<T> temp3=sumaVectores<T>(a,temp1);
            T modulo=1.0/sqrt(productoInterno<T>(temp3,temp3));
            temp3=productoPorEscalar<T>(modulo,temp3);
            xs.push_back(temp3);
        }
    }
    G.setMatrix(xs);
    return G;
}

