#include "data.h"

Data::Data()
{
    int array1[4][4]={  {1,1,1,1},
                        {1,1,0,1},
                        {1,0,0,0},
                        {1,1,0,1}};
    QVector<QVector<int>> v;
    for(int i=0;i<4;i++){
        QVector<int> temp;
        for(int j=0;j<4;j++){
            temp.push_back(array1[i][j]);
        }
        v.push_back(temp);
    }
    this->num1.insert(1,v);
    int array2[4][4]={  {1,0,1,1},
                        {0,0,1,1},
                        {1,1,0,0},
                        {1,1,0,1}};
    QVector<QVector<int>> v2;
    for(int i=0;i<4;i++){
        QVector<int> temp;
        for(int j=0;j<4;j++){
            temp.push_back(array2[i][j]);
        }
        v2.push_back(temp);
    }
    this->num1.insert(2,v2);

    int array3[4][4]={  {1,0,1,1},
                        {0,0,1,1},
                        {1,1,0,0},
                        {1,1,0,1}};
    QVector<QVector<int>> v3;
    for(int i=0;i<4;i++){
        QVector<int> temp;
        for(int j=0;j<4;j++){
            temp.push_back(array3[i][j]);
        }
        v3.push_back(temp);
    }
    this->num1.insert(3,v3);

    int array4[4][4]={  {0,0,0,0},
                        {0,1,1,0},
                        {0,1,1,0},
                        {0,0,0,0}};
    QVector<QVector<int>> v4;
    for(int i=0;i<4;i++){
        QVector<int> temp;
        for(int j=0;j<4;j++){
            temp.push_back(array4[i][j]);
        }
        v4.push_back(temp);
    }
    this->num1.insert(4,v4);

    int array5[4][4]={  {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0}};
    QVector<QVector<int>> v5;
    for(int i=0;i<4;i++){
        QVector<int> temp;
        for(int j=0;j<4;j++){
            temp.push_back(array5[i][j]);
        }
        v5.push_back(temp);
    }
    this->num1.insert(5,v5);

    int array6[4][4]={  {0,1,0,0},
                        {1,0,1,0},
                        {0,1,0,1},
                        {0,0,1,0}};
    QVector<QVector<int>> v6;
    for(int i=0;i<4;i++){
        QVector<int> temp;
        for(int j=0;j<4;j++){
            temp.push_back(array6[i][j]);
        }
        v6.push_back(temp);
    }
    this->num1.insert(6,v6);


    int array7[4][4]={  {0,0,0,1},
                        {0,0,0,0},
                        {0,1,0,0},
                        {0,0,0,0}};
    QVector<QVector<int>> v7;
    for(int i=0;i<4;i++){
        QVector<int> temp;
        for(int j=0;j<4;j++){
            temp.push_back(array7[i][j]);
        }
        v7.push_back(temp);
    }
    this->num1.insert(7,v7);
}
