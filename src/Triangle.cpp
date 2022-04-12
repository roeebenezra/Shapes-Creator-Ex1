/*************************************************************************
** Triangle cpp file **

***************************************************************************/

#include "Triangle.h"


//=======================================================================================
//constructer builds Triangle from 3 verticies in array.
Triangle::Triangle(const Vertex verticies[3])
{
	for (int i = 0; i < 3; i++)
		m_verticies[i] = verticies[i];
	//check if vertex are valid, if not set default
	Validate();
}
//=======================================================================================
//constructer builds Triangle from two verticies + hight .
Triangle::Triangle(const Vertex& v0, const Vertex& v1, double hight)
{
	m_verticies[First] = v0;
	m_verticies[Second]= v1;
	m_verticies[Third] = { m_verticies[First].m_col + (getLength() * 0.5),
							m_verticies[First].m_row + hight };
	//check if vertex are valid, if not set default
	Validate();
}
//=======================================================================================
//get vertex function from array + which index in the array .
Vertex Triangle::getVertex(int index)const
{
	return m_verticies[index];
}
//=======================================================================================
//function to get the hight of a triangle 
double Triangle::getHight() const
{
		return (m_verticies[Third].isHigherThan(m_verticies[First])) ?
				   m_verticies[Third].m_row - m_verticies[First].m_row
			     : m_verticies[First].m_row - m_verticies[Third].m_row;
}
//=======================================================================================
//function to calculate & return the Lengthe of the triangle

double Triangle::getLength()const
{
	return m_verticies[Second].m_col - m_verticies[First].m_col;
}
//=======================================================================================
//default verticies for the triangle if the input not valid.
void Triangle::setDefult()
{
	m_verticies[First] = { 20,20 };
	m_verticies[Second] = {30,20};
	m_verticies[Third] = {25,20+sqrt(75)};
}
//=======================================================================================
//function for validate check of the input verticies. 
void Triangle::Validate()
{
	if (!m_verticies[First].isValid() || 
		!m_verticies[Second].isValid()||
		!m_verticies[Third].isValid() ||
		!m_verticies[Second].isToTheRightOf(m_verticies[First])||
		!sameRow(m_verticies[First], m_verticies[Second])||
		!doubleEqual(distance(m_verticies[First], m_verticies[Second]) ,
		             distance(m_verticies[Second], m_verticies[Third]))
			|| !doubleEqual(distance(m_verticies[Second], m_verticies[Third]) , 
				            distance(m_verticies[First], m_verticies[Third])))
		setDefult();
}
//=======================================================================================
//draw of the triangle function
void Triangle::draw(Board& board) const
{
	board.drawLine(m_verticies[First], m_verticies[Second]);
	board.drawLine(m_verticies[Second], m_verticies[Third]);
	board.drawLine(m_verticies[Third], m_verticies[First]);
}
//=======================================================================================
//function to define & return the boundding rectangle of the Triangle
Rectangle Triangle::getBoundingRectangle() const
{
	return Rectangle(m_verticies[2].isHigherThan(m_verticies[0]) ? m_verticies[0]
				     : Vertex(m_verticies[0].m_col, m_verticies[2].m_row),
		              m_verticies[2].isHigherThan(m_verticies[0]) ?
		               Vertex(m_verticies[1].m_col, m_verticies[2].m_row) : m_verticies[1]);
}
//=======================================================================================
//function that scaling the size of the triangle by factor size, while the new shape
//is in the board borders oterwise the scaling is failing.
bool Triangle::scale(double factor)
{
	if (factor <= 0)
		return false;

	Vertex newVerticies[3];

	newVerticies[First] = {getCenter().m_col - (factor * (getCenter().m_col - m_verticies[First].m_col)) ,
						   getCenter().m_row - (factor * (getCenter().m_row - m_verticies[First].m_row)) };

	newVerticies[Second] = { getCenter().m_col + (factor * (m_verticies[Second].m_col - getCenter().m_col)),
							getCenter().m_row + (factor * (m_verticies[Second].m_row - getCenter().m_row)) };

	newVerticies[Third] = {m_verticies[Third].m_col, getCenter().m_row + (factor * 
										(m_verticies[Third].m_row - getCenter().m_row))};

	if ( !newVerticies[First].isValid() ||
		 !newVerticies[Second].isValid()||
		 !newVerticies[Third].isValid() ) //checking validate of the new verticies.
		return false;

	for (int i = 0; i < 3; i++)
		m_verticies[i] = newVerticies[i];

	return true;
}
//=======================================================================================
//function to calculate & return Area of the Triangle
double Triangle::getArea() const
{
	return (getHight() * getLength()) *0.5 ;
}
//=======================================================================================
//function to calculate & return perimeter of the triangle
double Triangle::getPerimeter()const
{
	return getLength() * 3 ;
}
//=======================================================================================
//function to calculate & return center vertex of the triangle
Vertex Triangle::getCenter()const
{
	if (m_verticies[First].isHigherThan(m_verticies[Third]))
		return Vertex(m_verticies[First].m_col + getLength() * 0.5,
				m_verticies[First].m_row - getHight() * 0.5);

	return Vertex(m_verticies[First].m_col + getLength() * 0.5,
				m_verticies[First].m_row + getHight() * 0.5);
}