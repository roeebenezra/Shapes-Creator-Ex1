/*************************************************************************
** Hourglass cpp file **

***************************************************************************/

#pragma once
#include "Hourglass.h"


//======================================================================================
//constructor of hourglass from 2 Triangles
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
	:m_upper(upper), m_lower(lower)
{
	//check if vertex are valid, if not set default
	Validate();
}
//=======================================================================================
//constructor of hourglass from 1 Triangles
Hourglass::Hourglass(const Triangle& lower)
	:m_lower(lower), m_upper(Vertex(lower.getVertex(0).m_col, lower.getVertex(0).m_row + getHight()),
							 Vertex(lower.getVertex(1).m_col, lower.getVertex(1).m_row + getHight()),
							 -lower.getHight())
{
	//check if vertex are valid, if not set default
	Validate();
}
//=======================================================================================
//function to define & return the boundding rectangle of the hourglass
Rectangle Hourglass::getBoundingRectangle()const
{
	return Rectangle(m_lower.getVertex(0), m_upper.getVertex(1));
}
//=======================================================================================
//draw hourglass function
void Hourglass::draw(Board& board) const
{
	m_upper.draw(board);
	m_lower.draw(board);
}
//=======================================================================================
//function to calculate & return hight of the hour glass
double Hourglass::getHight()const
{
	return m_lower.getHight() *2;
}
//=======================================================================================
//function to calculate & return perimeter of the hour glass
double Hourglass::getPerimeter()const
{
	return m_lower.getPerimeter() *2 ;
}
//=======================================================================================
//function to calculate & return Lengthe of the hour glass
double Hourglass::getLength()const
{
	return m_lower.getLength();
}
//=======================================================================================
//function to calculate & return Area of the hourglass
double Hourglass::getArea() const
{
	return m_lower.getArea() *2 ;
}
//=======================================================================================
//function that scaling the size of the hourglass by factor size, while the new shape
//is in the board borders.
bool Hourglass::scale(double factor)
{
	if (factor < 0)
		return false;

	Vertex First_newUpper = { getCenter().m_col - (factor * (getCenter().m_col - m_upper.getFirst().m_col)),
							  getCenter().m_row + (factor * (m_upper.getFirst().m_row - getCenter().m_row) ) };
	
	Vertex Second_newUpper = { getCenter().m_col + (factor * (m_upper.getSecond().m_col - getCenter().m_col)),
							   getCenter().m_row + (factor * (m_upper.getFirst().m_row - getCenter().m_row)) };
	
	Vertex First_newLower = { getCenter().m_col - (factor * (getCenter().m_col - m_lower.getFirst().m_col)),
						      getCenter().m_row - (factor * (getCenter().m_row - m_lower.getFirst().m_row)) };
	
	Vertex Second_newLower = { getCenter().m_col + (factor * (m_lower.getSecond().m_col - getCenter().m_col)),
							   getCenter().m_row - (factor * (getCenter().m_row - m_lower.getSecond().m_row)) };

	if ( !Second_newUpper.isValid() || !First_newLower.isValid()) //validate check of the new verticies.
		return false;

	Vertex newLowerVer[3] = { First_newLower,Second_newLower,getCenter() };
	m_lower = Triangle(newLowerVer);

	Vertex newUpperVer[3] = { First_newUpper,Second_newUpper,getCenter() };
	m_upper = Triangle(newUpperVer);

	return true;
}
//=======================================================================================
//function to return the center of the hour glass
Vertex Hourglass::getCenter()const
{
	return m_lower.getThird();
}
//=======================================================================================
//default verticies of hourglass if the input verticies not valid.
void Hourglass::setDefault()
{
	m_upper = Triangle(Vertex(20, 20 + (2 * sqrt(75))), Vertex(30, 20 + (2 * sqrt(75))), -sqrt(75));
	m_lower = Triangle(Vertex(20,20), Vertex(30,20) , sqrt(75));
}
//=======================================================================================
//function for validate check of the input triangles .
void Hourglass::Validate()
{
	if (  !m_lower.getThird().isHigherThan(m_lower.getFirst()) || 
		  !m_upper.getFirst().isHigherThan(m_upper.getThird()) ||
		  !doubleEqual(distance(m_lower.getFirst(), m_lower.getSecond()), distance(m_upper.getFirst(), m_upper.getSecond())) ||
		  !doubleEqual(m_lower.getThird().m_col, m_upper.getThird().m_col) ||
		  !doubleEqual(m_lower.getThird().m_row, m_upper.getThird().m_row))
	setDefault();
}