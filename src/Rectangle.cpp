/*************************************************************************
** Rectangle cpp file **

***************************************************************************/


#include"Rectangle.h"


//=======================================================================================
//constructer builds rectangle from two verticies.
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	: m_bottomLeft(bottomLeft), m_topRight(topRight)
{
	//check if vertex are valid, if not set default
	Validate();
}
//=======================================================================================
//constructor builds rectangle using arr of verticies
Rectangle::Rectangle(const Vertex vertices[2])
	:m_bottomLeft(vertices[0]), m_topRight(vertices[1])
{
	//check if vertex are valid, if not set default
	Validate();
}
//=======================================================================================
//constructor builds rectangle using 4 double vireble.
Rectangle::Rectangle(double x0, double y0, double x1, double y1) 
	:m_bottomLeft{ x0,y0 }, m_topRight{ x1,y1 }
{
	//check if vertex are valid, if not set default
	Validate();
}
//=======================================================================================
//constructor builds rectangle using 1 vertex ,width & hight.
Rectangle::Rectangle(const Vertex& start, double width, double hight)
	: m_bottomLeft(start), m_topRight { m_bottomLeft.get_col() + width, m_bottomLeft.get_row() + hight }
{
	//check if vertex are valid, if not set default
	Validate();
}
//=======================================================================================
//defult rectangle cordinats if the input is wrong.
void Rectangle::setDefult() 
{
	m_bottomLeft = { 20, 10 };
	m_topRight = { 30, 20 };
}
//=======================================================================================
//function to calculate and return Center of the rectangle.
Vertex Rectangle::getCenter()const 
{
	return Vertex (((m_topRight.m_col + m_bottomLeft.m_col) * 0.5),
				   ((m_topRight.m_row + m_bottomLeft.m_row) * 0.5));
}
//=======================================================================================
////function to calculate and return Area of the rectangle.
double Rectangle::getArea()const
{
	return getWidth() * getHight();
}
//=======================================================================================
//function to calculate and return the perimeter of the rectangle.
double Rectangle::getPerimeter()const 
{
	return getHight() * 4;
}
//=======================================================================================
//draw function of 4 valid verticies of the rectangle.
void Rectangle::draw(Board& board) const
{
	board.drawLine(m_bottomLeft , getTopLeft());
	board.drawLine(getTopLeft(), m_topRight);
	board.drawLine(m_topRight, getBottomRight());
	board.drawLine(getBottomRight(), m_bottomLeft);
}
//=======================================================================================
//function to calculate and return new scale, that multiplie by factor of the rectangle.
bool Rectangle::scale(double factor)
{
	if (factor <= 0)
		return false;

	Vertex newBottomLeft, newTopRight;
	
	newBottomLeft = { getCenter().m_col - (factor * (getCenter().m_col - m_bottomLeft.m_col)) ,
					  getCenter().m_row - (factor * (getCenter().m_row - m_bottomLeft.m_row)) };
	newTopRight = { getCenter().m_col + (factor * (m_topRight.m_col - getCenter().m_col)),
					getCenter().m_row + (factor * (m_topRight.m_row - getCenter().m_row)) };

	if (!(newBottomLeft.isValid() && newTopRight.isValid()))
		return false;

	m_bottomLeft = newBottomLeft;
	m_topRight = newTopRight;

	return true;
}
//=======================================================================================
//function that returns the bounding rectangle of this rectangle, which is the same one
Rectangle Rectangle::getBoundingRectangle() const 
{
	return Rectangle(m_bottomLeft,m_topRight);
}
//=======================================================================================
//function returns the bottom right vertex of our rectangle
Vertex Rectangle::getBottomRight()const
{
	return Vertex(m_topRight.m_col, m_bottomLeft.m_row);
}
//=======================================================================================
//function that calculate & returns the top left vertex of our rectangle
Vertex Rectangle::getTopLeft()const
{
	return Vertex(m_bottomLeft.m_col,m_topRight.m_row);
}
//=======================================================================================
//function that calculate & returns the width of our rectangle
double Rectangle::getWidth()const
{
	return m_topRight.m_col - m_bottomLeft.m_col;
}
//=======================================================================================
//function that calculate & returns the hight of our rectangle
double Rectangle::getHight()const
{
	return m_topRight.m_row - m_bottomLeft.m_row;
}
//=======================================================================================
//function that calculate the validate of our rectangle (vertecies in the board area & correct input)
void Rectangle::Validate()
{
	if (!(m_bottomLeft.isValid() && m_topRight.isValid())
			|| (m_bottomLeft.isToTheRightOf(m_topRight))
			|| (m_bottomLeft.isHigherThan(m_topRight)))
		setDefult();
}