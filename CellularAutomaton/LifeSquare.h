#pragma once

namespace MyCell
{
	using namespace System::Drawing;

	public ref class LifeSquare
	{
	public:
		bool curState, prevState;
		array<LifeSquare ^> ^ neibors;
		int xPostion, yPosition;
		Rectangle^ rec;

		LifeSquare(int x, int y)
		{
			curState = false;
			prevState = false;
			neibors = gcnew array<LifeSquare ^>(8);
			xPostion = x;
			yPosition = y;
			rec = gcnew Rectangle();
		}

		bool isGoingToLive()
		{
			int aliveCells = countAliveAround();
			if (prevState && (aliveCells == 3 || aliveCells == 2))
				return true;
			if (!prevState && aliveCells == 3)
				return true;
			return false;
		}

		int countAliveAround()
		{
			int counter = 0;
			for (int i = 0; i < 8; i++)
				if (neibors[i]->prevState)
					counter++;
			return counter;
		}

		void recount()
		{
			prevState = curState;
			curState = false;
		}

		

		void drawBorder()
		{
			
		}
		
	};
}