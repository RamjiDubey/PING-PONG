#include <raylib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Ball
{
	float x, y;
	float speedX, speedY;
	float radius;

	void Draw()
	{
		DrawCircle((int) x, (int) y, radius, WHITE);
	}
};

struct Paddle
{
	float x, y;
	float speed;
	float width, height;

	Rectangle GetRect()
	{
		return Rectangle { x - width / 2, y - height / 2, 10, 200};
	}

	void Draw()
	{
		DrawRectangleRec(GetRect(), WHITE);
	}
};

int main()
{
	int choice;
	while (1) 
	{
		cout << "	1 -> START A NEW GAME  "<<endl;
		cout << "	2 -> CLOSE THIS GAME  "<< endl;
		cout << "	ENTER YOUR CHOICE  " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				InitWindow(1300, 800, ".									       PING  PONG   GAME (:				");
				SetWindowState(FLAG_VSYNC_HINT);

				Ball ball;
				ball.x = GetScreenWidth() / 2.0f;
				ball.y = GetScreenHeight() / 2.0f;
				ball.radius = 10;
				ball.speedX = 300;
				ball.speedY = 300;

				Paddle leftPaddle;
				leftPaddle.x = 25;
				leftPaddle.y = GetScreenHeight() / 2;
				leftPaddle.width = 40;
				leftPaddle.height = 100;
				leftPaddle.speed = 500;

				Paddle rightPaddle;
				rightPaddle.x = GetScreenWidth() - 30;
				rightPaddle.y = GetScreenHeight() / 2;
				rightPaddle.width = 5;
				rightPaddle.height = 100;
				rightPaddle.speed = 500;

				const char* winnerText = nullptr;

				while (!WindowShouldClose())
				{
					ball.x += ball.speedX * GetFrameTime();
					ball.y += ball.speedY * GetFrameTime();

					if (rightPaddle.y < 0)
					{
						rightPaddle.y = 0;
					}
					if (rightPaddle.y > GetScreenHeight())
					{
						rightPaddle.y = GetScreenHeight();

					}

					if (leftPaddle.y < 0)
					{
						leftPaddle.y = 0;
					}
					if (leftPaddle.y > GetScreenHeight())
					{
						leftPaddle.y = GetScreenHeight();

					}

					if (ball.y < 0)
					{
						ball.y = 0;
						ball.speedY *= -1;
					}
					if (ball.y > GetScreenHeight())
					{
						ball.y = GetScreenHeight();
						ball.speedY *= -1;
					}

					if (IsKeyDown(KEY_W))
					{
						leftPaddle.y -= leftPaddle.speed * GetFrameTime();
					}

					if (IsKeyDown(KEY_S))
					{
						leftPaddle.y += leftPaddle.speed * GetFrameTime();
					}

					if (IsKeyDown(KEY_UP))
					{
						rightPaddle.y -= rightPaddle.speed * GetFrameTime();
					}

					if (IsKeyDown(KEY_DOWN))
					{
						rightPaddle.y += rightPaddle.speed * GetFrameTime();
					}

					if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, leftPaddle.GetRect()))
					{
						if (ball.speedX < 0)
						{
							ball.speedX *= -1.1f;
							ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * 300;
						}
					}

					if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, rightPaddle.GetRect()))
					{
						if (ball.speedX > 0)
						{
							ball.speedX *= -1.1f;
							ball.speedY = (ball.y - rightPaddle.y) / (rightPaddle.height / 2) * 300;
						}
					}

					if (ball.x < 0)
					{
						winnerText = " RIGHT PLAYER WINS! ";
					}

					if (ball.x > GetScreenWidth())
					{
						winnerText = " LEFT PLAYER WINS! ";
					}
					
					if (winnerText && IsKeyPressed(KEY_SPACE))
					{
						//ball.x = GetScreenWidth() / 2;
						//ball.y = GetScreenHeight() / 2;
						//ball.speedX = 300;
						//ball.speedY = 300;
						//winnerText = nullptr;
						CloseWindow();
					}

					BeginDrawing();
					ClearBackground(BLACK);

					ball.Draw();
					leftPaddle.Draw();
					rightPaddle.Draw();

					if (winnerText)
					{
						int textWidth = MeasureText(winnerText, 60);
						DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, YELLOW);
					}

					DrawFPS(10, 10);
					EndDrawing();
				}
				break;
			}
			case 2:
			{
				return 0;
			}

		    default:
			break;
		};
	}
	return 0;
}
	