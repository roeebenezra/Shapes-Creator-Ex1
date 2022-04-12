/*************************************************************************
** Square cpp file **

***************************************************************************/


#include "Square.h"


//=======================================================================================
//constructer builds rectangle from two verticies.
Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
	: m_bottomLeft(bottomLeft), m_topRight(topRight)
{
	//check if vertex are valid, if not set default
	Validate();
}

//=======================================================================================
//constructor builds rectangle using arr of verticies
Square::Square(const Vertex& start, double length)
	:m_bottomLeft(start), m_topRight{ m_bottomLeft.get_col() + length, m_bottomLeft.get_row() + length }
{
	if (length < 0)
		setDefult();
	//check if vertex are valid, if not set default
	Validate();
}

//=======================================================================================
//draw function of 4 valid verticies of the rectangle.
void Square::draw(Board& board) const
{
	board.drawLine(m_bottomLeft, getBottomRight());
	board.drawLine(getBottomRight(), m_topRight);
	board.drawLine(m_topRight,getTopLeft());
	board.drawLine(getTopLeft(), m_bottomLeft);
}
//=======================================================================================
Rectangle Square::getBoundingRectangle()const
{
	return Rectangle(m_bottomLeft,m_topRight);
}
//=======================================================================================
//function returns the bottom right vertex of our square
Vertex Square::getBottomRight()const
{
	return Vertex(m_topRight.m_col, m_bottomLeft.m_row);
}
//=======================================================================================
//function returns the bottom left vertex of our square
Vertex Square::getTopLeft()const
{
	return Vertex(m_bottomLeft.m_col, m_topRight.m_row);
}
//=======================================================================================
//function returns the Area of our square
double Square::getArea() const
{
	return getLength() * getLength();
}
//=======================================================================================
//function returns the perimeter of the square
double Square::getPerimeter()const
{
	return getLength() * 4;
}
//=======================================================================================
//function returns the center vertex of our square
Vertex Square::getCenter()const
{
	return Vertex( ((m_topRight.get_col() + m_bottomLeft.get_col()) * 0.5),
				   ((m_topRight.get_row() + m_bottomLeft.get_row()) * 0.5) );
}
//=======================================================================================
//function returns the lenghte of our square
double Square::getLength() const
{
	return m_topRight.m_row - m_bottomLeft.m_row;
}

//=======================================================================================
// function for scaling the shape by factor size, if the new shape out of borders,
// scaling failing.
bool Square::scale(double factor)
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
//default verticies values
void Square::setDefult()
{
	m_bottomLeft = { 20, 10 };
	m_topRight = { 30, 20 };
}
//=======================================================================================
//validate function to check the if the shape is valid square
void Square::Validate()
{
	if ( !m_bottomLeft.isValid() || !m_topRight.isValid()
		|| m_bottomLeft.isToTheRightOf(m_topRight) 
		|| m_bottomLeft.isHigherThan(m_topRight) 
		|| !doubleEqual( distance(m_bottomLeft,getBottomRight()) ,
			             distance(getBottomRight(), getTopRight()) ))
		setDefult();
}