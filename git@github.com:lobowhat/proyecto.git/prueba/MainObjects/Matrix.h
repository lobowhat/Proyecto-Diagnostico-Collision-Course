/*
 * Matrix.h
 *
 *  Created on: 07/03/2013
 *      Author: howar
 */

#ifndef MATRIX_H_
#define MATRIX_H_

//namespace Matrix {

class Matrix {
private:
	int _empty; //Asignation a reference the matrix
	int _rangex;// range in column of matrix
	int _rangey;// range in row of matrix
	//static int _matrix[_rangeX][_rangeY];//matrix
	int _xposition;//position of object
	int _yposition;//position of object
	int _object;//object search
	//int _matrix[];//matrix global in the logic
	int _mathecua;//creation constant following
	int *_matrix;
	int _k;// position especial of matrix





public:
	Matrix();
	//range of matrix
	virtual ~Matrix();


	bool verification(int position,int pobject);
	/*
	 * verification de position de object under in the matrix
	 */
	void changereference(int position,int pobject);
	/*
	 * change reference in the side of the matrix
	 */
	void showMatrix();
	/*
	 * show matrix in the game
	 */
	int position(int pobject)const;
	/*
	 * throw position of object
	 */
	int randomeletion(int position)const;
	/*
	 * if the position of object is equal to full
	 */
	void updatematrix();
	/*
	 * creation new matrix
	 */
	void positionnow(int pobject);
	/*
	 * actualization of position matrix in every step in the matrix
	 */
	bool positionidentificY(int pposition,int ppositionI)const;
	/*
	 * graphic position
	 *
	 */
	bool positionidentificX(int pposition,int ppositionI)const;
	/*
	 * graphic position
	 */
	void creationmatrix();
	/*
	 * recreation of matrix
	 */
	int positiongraphicX(int position)const;
	/*
	 * throw position of matrix in position graphic x
	 */
	int positiongraphicY(int position)const;
	/*
	 * throw position matrix in graphic y
	 */
	int Graphiccontrolgame(int xposition,int yposition)const;
	/*
	 * Control of the game about interfaz:cursor of keyboard of interface
	 */
	bool Matrixcrash(int pobject1,int pobject2)const;
	/*
	 * identific crash in the matrix about two objects
	 */
	int getEmpty() const;
	/*
	 * constant of empty ==null in the matrix
	 */
	void setEmpty(int pempty);
	/*
	 * reference in null
	 */

	const int* getMatrix() const ;
	/*
	 * get matrix general
	 */
	int getObject() const ;
	/*
	 * get object especific
	 */
	void setObject(int pobject);
	/*
	 * change
	 */

	int getXposition() const ;
	/*
	 * get position x
	 */
	void setXposition(int position) ;
	/*
	 * change position x
	 */
	int getYposition() const ;
	/*
	 * get y
	 */
	void setYposition(int position) ;
	/*
	 * change y position
	 */
	int getMathecua() const;
	/*
	 * get mat ecuation graphic
	 */
	void setMathecua(int mathecua);
	/*
	 * change math ecua
	 */

	int getRangex() const;
	/*
	 * return range x
	 */

	void setRangex(int rangex);
	/*
	 * change range x
	 */

	int getRangey() const;
	/*
	 * range y
	 */
	void setRangey(int rangey);
	/*
	 * change range y
	 */
};




#endif /* MATRIX_H_ */
