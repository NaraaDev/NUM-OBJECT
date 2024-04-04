#include <iostream>
using namespace std;

class Matrix
{
private:
    int row, column;
    float **values;

public:
    Matrix();                                    // baiguulagch function
    Matrix(int row, int column);                 // paramatert baiguulagch function
    Matrix(const Matrix &other);                 // Huulagch function
    ~Matrix();                                   // Ustgagch function
    void print() const;                          // Matrixig hevleh function
    int getRow() const;                          // Matrixin moriig awah function
    int getColumn() const;                       // Matrixin bagana iig awah function
    float getValue(int i, int j) const;          // Matrixin utgiig awah function
    void setValue(int i, int j, float x);        // Matrixin utgiig oorchloh function
    void setRow(int newRow);                     // Matrixin moriin setter function
    void setColumn(int newColumn);               // Matrixin baganiin setter function
    Matrix operator+(float x) const;             // Matrixig nemeh operator function
    Matrix operator+(const Matrix &other) const; // Matrixuudig nemeh operator function
    Matrix operator-(const Matrix &other) const; // Matrixuudig hasah function
    Matrix operator*(const Matrix &other) const; // Matrixuudig urjuuleh function
    Matrix &operator=(const Matrix &other);      // Matrixig onooh function
    Matrix &operator++();                        // Matrixin utgiig 1 eer nemegduuleh function
    Matrix &operator--();                        // Matrixin utgiig 1 eer horogduulah function
    Matrix &operator+=(const Matrix &other);     // Matrixig oor matrixaar nemegduuleh function
    Matrix &operator-=(const Matrix &other);     // Matrixig oor matrixaar horogudulah function
    Matrix &operator*=(const Matrix &other);     // Matrixig oor matrixar urjuuleh function
    void convert();                              // Matrixig horwuuleh function
};

Matrix::Matrix() : row(1), column(1)
{
    values = new float *[row];
    values[0] = new float[column];
    values[0][0] = 0;
}

Matrix::Matrix(int row, int column) : row(row), column(column)
{
    values = new float *[row];
    for (int i = 0; i < row; ++i)
    {
        values[i] = new float[column];
        for (int j = 0; j < column; ++j)
        {
            values[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &other) : row(other.row), column(other.column)
{
    values = new float *[row];
    for (int i = 0; i < row; ++i)
    {
        values[i] = new float[column];
        for (int j = 0; j < column; ++j)
        {
            values[i][j] = other.values[i][j];
        }
    }
}

Matrix::~Matrix() // Ustgagch function
{
    for (int i = 0; i < row; ++i)
        delete[] values[i];
    delete[] values;
}

void Matrix::print() const // Hevleh function
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
            cout << values[i][j] << ' ';
        cout << '\n';
    }
}

int Matrix::getRow() const
{
    return row;
}

int Matrix::getColumn() const
{
    return column;
}

float Matrix::getValue(int i, int j) const
{
    if (i >= 1 && i <= row && j >= 1 && j <= column)
    {
        return values[i - 1][j - 1];
    }
    return 0; // values[i][j] ni matrix d baihgui bol 0 iig butsaana.
}

void Matrix::setValue(int i, int j, float x)
{
    if (i >= 1 && i <= row && j >= 1 && j <= column) // values[i][j] ni baihgu bol yu ch hiihgui.
        values[i - 1][j - 1] = x;
}

void Matrix::setRow(int newRow)
{
    if (newRow > 0)
    {
        float **newValues = new float *[newRow];
        for (int i = 0; i < newRow; i++)
        {
            newValues[i] = new float[column];
            for (int j = 0; j < column; j++)
            {
                newValues[i][j] = (i < row) ? values[i][j] : 0; // shine mor nemej ogj baigaa uchir shineer nemegdsen morud 0 utga awna
            }
        }
        // Umnuh sanah oigoo tseverleh heregtei double detected aldaa zaana.
        for (int i = 0; i < row; ++i)
            delete[] values[i];
        delete[] values;

        values = newValues; // shine utgig onooj ogno.
        row = newRow;       // shine moriig onoono.
    }
}

void Matrix::setColumn(int newColumn)
{
    // setColumn set Row toi ijil zarchimtai ajilna.
    if (newColumn > 0)
    {
        for (int i = 0; i < row; ++i)
        {
            float *newRow = new float[newColumn];
            for (int j = 0; j < newColumn; ++j)
            {
                newRow[j] = (j < column) ? values[i][j] : 0;
            }
            delete[] values[i];
            values[i] = newRow;
        }
        column = newColumn;
    }
}

Matrix Matrix::operator+(float x) const
{
    Matrix temp(row, column); // temp nertei yag ijil matrix uusgene
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            temp.values[i][j] = values[i][j] + x; // temp iin utga ni omnoh matrixin utga dr x utgig nemsentei tentsu
        }
    }
    return temp; // tuunig butsaana
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (row != other.row || column != other.column)
    {
        // Ug 2 matrixig nemeh bolomjgui bol ijil hernee null matrix butsaana
        return Matrix(row, column);
    }

    Matrix result(row, column); // hariultig uusgej ogno.
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            result.values[i][j] = values[i][j] + other.values[i][j]; // ug matrixudin niilberig hadgalna
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    // Ug uildel operator+ uildeltei ijil zarchimtai ajilna
    if (row != other.row || column != other.column)
    {
        return Matrix(row, column);
    }

    Matrix result(row, column);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            result.values[i][j] = values[i][j] - other.values[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (column != other.row)
    {
        // ug 2 matrixig urjih bolomjgui bol 0 eer duursen matrix butsaana
        return Matrix(row, other.column);
    }

    Matrix result(row, other.column); // hariultig zarlana
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < other.column; j++)
        {
            for (int k = 0; k < column; k++)
            {
                result.values[i][j] += values[i][k] * other.values[k][j]; // matrixin urjih uildliig hiine
            }
        }
    }
    return result;
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other) // free(): double free detected erroros sergiilne
    {
        // Odoo baigaa sanah oig tseverleh
        for (int i = 0; i < row; i++)
        {
            delete[] values[i];
        }
        delete[] values;

        row = other.row;       // rowiin hemjeeg huulah
        column = other.column; // columiin hemjeeg huulah sanah oig zov ashigtai zarutsuulah heregtei
        values = new float *[row];
        for (int i = 0; i < row; i++)
        {
            values[i] = new float[column];
            for (int j = 0; j < column; j++)
                values[i][j] = other.values[i][j]; // huulah uildel
        }
    }
    return *this;
}

Matrix &Matrix::operator++() // Matrixin utguudig 1eer nemegduuleh
{
    // Tuhain matrixin mor bolon baganaar gvih
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            values[i][j]++; // utgig 1 eer nemegduuleh
        }
    }
    return *this;
}

Matrix &Matrix::operator--() // Matrixin utguudig 1eer horogduulah
{
    // operator++ uildeltei yg ijil zarchimtai ajilna
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            values[i][j]--;
        }
    }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &other) // Matrixig oor matrixaar nemegduuleh
{
    if (row == other.row && column == other.column) // Row bolon column tentsuu uyd nemegduulne
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                values[i][j] += other.values[i][j];
            }
        }
    }
    return *this; // Hervee mor bagana tentsuu bish uyd tuhain matrixig oorig ni butsaana esvel nemegdsen matrixig butsaana
}

Matrix &Matrix::operator-=(const Matrix &other) // Matrixig oor matrixaar horogduulah uildel
{
    // operator+= ijil zarchimtai ajilna
    if (row == other.row && column == other.column)
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                values[i][j] -= other.values[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &other) // Matrixig oor negen matrixaar urjuuleh uildel
{
    if (column == other.row)
    {
        Matrix temp(*this * other);
        *this = temp;
    }
    return *this;
}

void Matrix::convert() // Matrixig horwuuleh uildel
{
    Matrix temp(*this);           // ijil hemjeetei shine matrix zarlana
    for (int i = 0; i < row; ++i) // odoo baigaa matrixin sanah oig choloolno
    {
        delete[] values[i];
    }
    delete[] values;

    row = temp.column; // horwuulj bui uchir row bolon columnig solino
    column = temp.row;
    values = new float *[row];
    for (int i = 0; i < row; ++i)
    {
        values[i] = new float[column];
        for (int j = 0; j < column; ++j)
        {
            values[i][j] = temp.values[j][i]; // solison row columnin utguudig hoorond ni solino
        }
    }
}

int main()
{
    // Testing
    Matrix a(2, 3);
    Matrix b = a + 1;
    b.print();
    Matrix c = a + b;
    cout << "C matrix = Matrix a + Matrix b " << '\n';
    c.print();
    Matrix d = c - b;
    d.print();
    Matrix temp(3, 2);
    Matrix product = temp * c;
    cout << "Matrix vrjwer " << '\n';
    product.print();
    Matrix k(4, 4);
    k = k + 1;
    cout << "Matrix k : " << '\n';
    k.print();
    Matrix multii = k * k;
    cout << "Matrix k kwadrat: " << '\n';
    multii.print();
    multii = b;
    cout << "Matrix k kwadratiig oor matrixig onooj ogoh: " << '\n';
    multii.print();
    --multii;
    cout << "Onooj ogson matrixig 1eer horogduulah " << '\n';
    multii.print();
    multii += b;
    multii += b;
    cout << "Matrixig 2 udaa b matrixaar nemegduuleh " << '\n';
    multii.print();
    Matrix s(3, 2);
    s = s + 2;
    cout << "Matrixin utgig 2oor nemegduuleh  " << '\n';
    s.print();
    s *= multii;
    cout << "S matrixig multii matrixar urjuuleh " << '\n';
    s.print();
    Matrix q(2, 3);
    ++q, ++q;
    cout << "q matrixig 2 udaa 1 eer nemegduuleh " << '\n';
    q.print();
    q.convert();
    cout << "q matrixig horwuuleh " << '\n';
    q.print();
    q.setRow(1);
    cout << "Moriin hemjeeg setlej ogoh " << '\n';
    q.print();
}
