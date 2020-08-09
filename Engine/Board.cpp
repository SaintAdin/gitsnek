#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{

}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x <= width);
	assert(loc.y >= 0);
	assert(loc.y <= height);
	
	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	gfx.DrawRectDim(loc.x * dimension + off_x + cellPadding, loc.y * dimension + off_y + cellPadding, dimension - cellPadding * 2, dimension - cellPadding * 2, c);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return loc.x >= 0 && loc.x < width&&
		loc.y >= 0 && loc.y < height;
}

void Board::DrawBorder() const
{
	int top = y;
	int left = x;
	int bottom = y + (borderWidth + borderWidth) * 2 + dimension * height;
	int right = x + (borderWidth + borderWidth) * 2 + dimension * width;
	//top
	gfx.DrawRect(left, top, right, top + borderWidth, BorderColor);
	//bottom
	gfx.DrawRect(left, bottom- borderWidth, right,bottom, BorderColor);
	//left
	gfx.DrawRect(left, top, left + borderWidth, bottom,BorderColor);
	//right
	gfx.DrawRect(right - borderWidth, top, right, bottom,BorderColor);

}
