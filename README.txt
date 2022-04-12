README

Project: ex01.

Made by: 1)Name: danielyo, ID: 322017518.
	     2)Name: roibe,    ID: 206123994.

This project prints different shapes, and calculates their area, hight, perimeter, 
center and length according to vertacise we give it.
In order to do so the program uses different files:
 header_files: 1) Vertex.h- gives us the struct of vertex we will use for input
				  and validetion.
		       2) Utilities.h- gives us different functions to use for 
							calculation between vertecies.  
		       3) Macros.h- givs us the max_row and max_col.
		       4) Board.h- gives us the class of Board for drawing,
			      printing and clearing from the board.
			   5) Vertex.h - gives us the class of Vertex for drawing,
			      printing and clearing from the board.
		       5) Rectangle.h - presents the class of the shape Rectangle.
		       6) Square.h- presents the class of the shape Square.
		       7) Triangle.h - presents the class of the shape Triangle.
		       8) Hourglass.h - presents the class of the shape Hourglass which is
				  made up by two triangles.

  src_files:   1) main.cpp- uses all the files in order to read info from the user
			      and according to the info the different files will act.
		       2) Utilities.cpp- holds the calculation functions themselfs.
		       3) Board.cpp- holds the the functions givin in the header file.
		       4) Rectangle.cpp- holds the the functions givin in the header file.
		       5) Square.cpp- holds the the functions givin in the header file.
		       6) Triengle.cpp- holds the the functions givin in the header file.
		       7) Hourglass.cpp- holds the the functions givin in the header file.
	
Main data stucrturs :

		1. Rectangle class - Contains four constructers which build the rectangle
				     based on the bottom-left and the top-right vertexes.
				    when getting the vertexes we will check to see that the
				    vertexes are valid,. if they are not then the program 
		          will send them to default and from there procede to printing the shape. 
				 
		2. Square class - Contains two constructers which build the square
				     based on the bottom-left and the top-right vertexes.
				    when getting the vertexes we will check to see that the
				    vertexes are valid. if they are not then the program 
		         will send them to default and from there procede to printing the shape.
 
		3. Triangle class - Contains two constructers which build the triangle based
				on three vertexes or by two vertexes and the hight of the triangle.
				also in this class we have a check up if the information that was read
				is valid or not. and according to the validation also here we will 
				default vertexes to build a proper triangle that has three equal sides.

		4. Hourglass class - This class is a bit different from the fact that this is a shape
				that relays on the build of two triangls built one on top of the other
				so that their bases are peralel and they share a vertex.
				In order to do so this class will build based on the help by the triangle
				class. And the same as the rest of shapes (classes) this class will 
				check the vadility of the triangls that were put in and according to the
			        result it will give two defult triangles.
				
		In addition all classes will provide other required functions: 
		The drawing of the shape, getting a rectangle that bounds the shape,
		getting the area of the shape, gettign the parimeter of the shape,
		getting the center of the shape and seeing if the shape could be 
				inlarged according to a number givin to the function.

        Data structers: The vertex struct that based on the information we give
		to this struct the program will build the shape.

        Allgoritums: The operators of the Hourglass work based on the operators of the triangle.

Bugs: unknown.

Additional: none.




 






 


			
	


   