#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

// Khai báo kiểu dữ liệu
struct _POINT
{
	int x, y, c;
}; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu

// Hằng số
#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ
#define LEFT 3		  // Tọa độ trái màn hình bàn cờ
#define TOP 1		  // Tọa độ trên màn hình bàn cờ

_POINT _A[BOARD_SIZE][BOARD_SIZE]; // Ma trận bàn cờ

bool _TURN;	  // true là lượt người thứ nhất và false là lượt người thứ hai
int _COMMAND; // Biến nhận giá trị phím người dùng nhập
int _X, _Y;	  // Tọa độ hiện hành trên màn hình bàn cờ

// 1. Hàm nhóm View
void FixConsoleWindow();
void GotoXY(int x, int y);
void DrawBoard(int pSize);
// Hàm xử lý khi người chơi thua
int ProcessFinish(int pWhoWin);
// Hàm hỏi người chơi có muốn tiếp tục chơi hay không
int AskContinue();
// 2. Hàm nhóm model
// Hàm khởi tạo dữ liệu mặc định ban đầu cho ma trận bàn cờ
void ResetData();
// Hàm dọn dẹp tài nguyên
void GabageCollect();
// Hàm kiểm tra xem có người thắng/thua hay hòa
int TestBoard();
int CheckBoard(int pX, int pY);
// 3. Hàm nhóm control
// Hàm bắt đầu game
void StartGame();
// Hàm thoát game
void ExitGame();
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();