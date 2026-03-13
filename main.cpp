#include "main.h"

int main()
{
	FixConsoleWindow();
	StartGame();
	bool validEnter = true;
	while (1)
	{
		_COMMAND = toupper(getch());
		switch (_COMMAND)
		{
		case 27:
			ExitGame();
			return 0;
		case 'A':
			MoveLeft();
		case 'W':
			MoveUp();
		case 'S':
			MoveDown();
		case 'D':
			MoveRight();
		case 13:
			// Người dùng đánh dấu trên màn hình bàn cờ
			switch (CheckBoard(_X, _Y))
			{
			case -1:
				printf("X");
				break;
			case 1:
				printf("O");
				break;
			case 0:
				validEnter = false; // Khi đánh vào ô đã đánh rồi
			}
			// Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
			if (validEnter == true)
			{
				switch (ProcessFinish(TestBoard()))
				{
				case -1:
				case 1:
				case 0:
					if (AskContinue() != 'Y')
					{
						ExitGame();
						return 0;
					}
					else
						StartGame();
				}
			}
			validEnter = true; // Mở khóa
		// TODO: 4.1 Xử lý lưu/tải trò chơi (save/load)
		case 'L':
		case 'T':
		}
	}
	return 0;
}
