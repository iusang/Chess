//中国象棋1.0
//盲棋
#include<iostream>
#include<cstring>
using namespace std;
//struct Chessboard{
//
//};

struct Pieces{
    string name;
//    int id;
    int x;
    int y;
};

int main(){
    int Chessboard[9][10];     //声明棋盘
    Pieces p[32];  //声明棋子
    for(int i=0; i<9; i++){   //初始化黑方棋子
        if(i%8 == 0) p[i].name = "车";
        if((i-4)*(i-4) == 9) p[i].name = "马";
        if((i-4)*(i-4) == 4) p[i].name = "象";
        if((i-4)*(i-4) == 1) p[i].name = "士";
        if(i == 4) p[i].name = "将";
        p[i].x = i;
        p[i].y = 0;
    }

    for(int i=23; i<32; i++){   //初始化红方棋子
        if((i-27)*(i-27) == 16) p[i].name = "车";
        if((i-27)*(i-27) == 9) p[i].name = "马";
        if((i-27)*(i-27) == 4) p[i].name = "象";
        if((i-27)*(i-27) == 1) p[i].name = "士";
        if(i == 27) p[i].name = "将";
        p[i].x = i-23;
        p[i].y = 9;
    }

    for(int i=11; i<=15; i++){    //初始化5个卒
        p[i].name = "卒";
        p[i].x = (i-11)*2;
        p[i].y = 3;
    }

    for(int i=16; i<=20; i++){    //初始化5个兵
        p[i].name = "卒";
        p[i].x = (i-16)*2;
        p[i].y = 6;
    }

    p[9].name = p[10].name = p[21].name = p[22].name = "炮";
    p[9].x = p[21].x = 1;
    p[10].x = p[22].x = 7;
    p[9].y = p[10].y = 2;
    p[21].y = p[22].y = 7;
    

    for(int i=0; i<9; i++)
        for(int j=0; j<10; j++)
            Chessboard[i][j] = -1;
    for(int i=0; i<32; i++){   //初始化棋盘
        Chessboard[p[i].x][p[i].y] = i;
    }

    for(int j=0; j<10; j++){       //打印棋盘
        for(int i=0;i<9;i++){
            if(Chessboard[i][j] >= 0)
                cout<<p[Chessboard[i][j]].name<<" ";
            else
                 cout<<"   ";
        }
        cout<<endl;
    }

//    for(int i=0; i<32; i++){
//        cout<<p[i].name<<" "<<"("<<p[i].x<<", "<<p[i].y<<")"<<endl;
//    }
//    cout<<"_++++++-";
    
    return 0;
}
