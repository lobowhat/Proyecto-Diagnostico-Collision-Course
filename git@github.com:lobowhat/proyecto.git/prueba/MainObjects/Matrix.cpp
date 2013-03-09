/*
 * Matrix.cpp
 *
 *  Created on: 07/03/2013
 *      Author: howar
 */

#include "Matrix.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

//namespace Matrix {

Matrix::Matrix() {
	// TODO Auto-generated constructor stub

    this->_rangex=12;//12xml   134793
    this->_rangey=9;//9 xml
	this->_mathecua=12;//xml
	this->_empty=0;//xml
	this->_xposition=0;//xml
	this->_yposition=0;//xml
	this->_object=0;//xml
	this->_matrix=new int  [_rangex*_rangey];//
	this->_k=15;
	/*for(int i = 0; i<this->_rangex;i++)     {
	      for(int j=0;j<this->_rangey;j++) {
			this->_matrix[this->_k] = 23;
		}
	    }//i*this->_rangey + j*/




}

Matrix::~Matrix() {
	// TODO Auto-generated destructor stub

}
 int Matrix:: getEmpty() const {
		return this->_empty;
 }

 void Matrix::setEmpty(int pempty) {
		this->_empty = pempty;
 }



int Matrix:: getObject() const {
		return this->_object;
	}

void Matrix:: setObject(int pobject) {
		this->_object = pobject;
	}



int Matrix:: getXposition() const {
		return this->_xposition;
	}

void Matrix:: setXposition(int pxposition) {
		this->_xposition = pxposition;
	}

int Matrix:: getYposition() const {
		return this->_yposition;
	}

void Matrix:: setYposition(int pyposition) {
		this->_yposition = pyposition;
	}
int Matrix::getMathecua() const {
		return this->_mathecua;
	}

void Matrix::setMathecua(int pmathecua) {
		this->_mathecua = pmathecua;
	}

int Matrix:: getRangex() const {
		return this->_rangex;
	}

void Matrix:: setRangex(int prangex) {
		this->_rangex = prangex;
	}

int Matrix::getRangey() const {
		return this->_rangey;
	}

void Matrix:: setRangey(int prangey) {
		this->_rangey = prangey;
	}
void Matrix::creationmatrix(){
	for (int i = 0; i<_rangex*_rangey; i++) {

			this->_matrix[i]= this->_empty;/// creation the matrix in the game
		}

}
bool Matrix::verification(int pposition,int pobject){//verification of position of object in the matrix central
	if (this->_matrix[pposition]==pobject){          //verification
		return true;
	}
	else{
		return false;
	}
}
void Matrix::changereference(int pposition,int pobject){
	if(verification(pposition,this->_empty)==true){
		this->_matrix[pposition]=pobject;
	}
	else{
         int number=randomeletion(pposition);
         this->_matrix[number]=pobject;

	}
}
int Matrix::randomeletion(int pposition)const{
	srand(time(NULL));
	bool _flag=false;
	int _randomnumber=0 + (rand() % (this->_rangex*this->_rangey));
	while (!_flag){
		if (this->_matrix[_randomnumber]==this->_empty){
			_flag=true;
		}
		else{
			if (this->_matrix[_randomnumber]==pposition){
			_flag=false;
			_randomnumber=0 + (rand() % (this->_rangex*this->_rangey));
			}
			else{
				_flag=false;
				_randomnumber=0 + (rand() % (this->_rangex*this->_rangey));
			}
		}
	}
	return _randomnumber;
}
int Matrix::position(int pobject)const{//application mathematic about calculation of x in interfaz
	bool _flag=false;                 //calculation about position
	int number=0;                     //enter number of position matrix :get out position x what give interfaz
	while(!_flag){
		if (this->_matrix[number]==pobject){
			_flag=true;
		}
		else{
			if(number==this->_rangex*this->_rangey){
				cout<<"Dont Found"<<endl;
				return 0;
			}
			else{
				_flag=false;
				number++;
			}
		}
	}
	cout<<number<<endl;
	return number;
}
bool Matrix::positionidentificX(int position,int ppositionI)const{
     bool _flag=false;
     int _j=position;
     while(!_flag){
    	 if(_j==ppositionI){
    		 _flag=true;
    	 }
    	 else{
    		 if(_j>ppositionI){
    			 return false;
    		 }
    		 _j+=this->_mathecua;
    	 }
     }
     return true;

}
int Matrix::positiongraphicX(int pposition)const{//recursion about matrix
	    bool _flag=false;                        //identify x in position correct in the matrix
	    int i=0;
	    while(!_flag){
	    	if(positionidentificX(i,pposition)==true){
                  _flag=true;
	    	}
	    	else{
	    		if(i>this->_rangey){
	    			_flag=true;
	    		}
	    		i++;
	    	}


	}
	    cout<<(i+2)*10<<endl;
	    return (i+2)*10;

}
bool Matrix::positionidentificY(int position,int ppositionI)const{
     bool _flag=false;
     int _j=position;
     while(!_flag){
    	 if(_j==ppositionI){
    		 _flag=true;
    	 }
    	 else{
    		 if(_j>position+this->_rangex-2){
    			 return false;
    		 }
    		 _j++;
    	 }
     }
     return true;

}
int Matrix::positiongraphicY(int pposition)const{//recursion about matrix
	    bool _flag=false;                        //identify x in position correct in the matrix
	    int i=0;                                 // math equal (10-8)+i ,10-8=2,2-8=-6
	    int _data=10;
	    int _crash=8;
	    int _save;
	    while(!_flag){
	    	if(positionidentificY(i,pposition)==true){
                  _flag=true;
	    	}
	    	else{
	    		if(i>this->_rangey*_rangex-10){
	    			_flag=true;
	    		}
	    		_save=_data-_crash;
	    		_data=_save;
	    		i+=this->_mathecua;
	    	}
	    }
	    cout<<(_data-_crash)+i<<endl;
	    return (_data-_crash)+i;
}
int Matrix::Graphiccontrolgame(int xposition,int yposition)const{
	int _position=0;
	int _widht=134;                    //explication about concept this funtion is a form of to know
	int _varx=15;                      //the size of matrix in (x,y) and you can to know the position in column y row
	int _varxend=24;                   //the position about matrix
	int _vary=0;
	int _varyend=4;
	bool _control=false;
	while(!_control){
		if ((_varx<=xposition)&&(_varxend>=xposition)&&(_vary<=yposition)&&(_varyend>=yposition)){
		   _control=true;
	   }
	   else{
		   if(_varxend>_widht){
			   _varx=15;
			   _varxend=24;
			   _vary+=4;
			   _varyend+=4;
			   _control=false;
		   }
		   else{
			   if(_varx==15){
				   _varx+=9;
				   _varxend+=10;
				   _position++;
				   _control=false;
			   }
			   else{
				   _varx+=10;
				   _varxend+=10;
				   _position++;
				   _control=false;
			   }
			 }
	   }
	}
	cout<<_position<<endl;
	return _position;
}
bool Matrix::Matrixcrash(int object1,int object2)const{
	if (object1==object2){
		return true;
	}
	else{
		return false;
	}
}



void Matrix::showMatrix(){
	for (int i = 0; i<111; i++) {

		        cout << " matrix[" << i << "][" << i <<"] = " << this->_matrix[i]<<endl;
	}
}


//int  main() {
//   Matrix* object=new Matrix();
//
//    object->creationmatrix();
//    object->changereference(23,1500);
//    object->changereference(26,1700);
//    object->changereference(29,1720);
//    object->changereference(46,17);
//    object->changereference(66,20);
//    object->changereference(78,80);
//    object->changereference(99,19);
//    object->changereference(2,256);
//    object->changereference(26,89);
//    //object->showMatrix();
//    object->positiongraphicX(97);
//    object->positiongraphicY(97);
//   /* object->Graphiccontrolgame(15,3);
//    object->Graphiccontrolgame(16,6);
//    object->Graphiccontrolgame(20,9);
//    object->Graphiccontrolgame(21,16);
//    object->Graphiccontrolgame(24,18);
//    object->Graphiccontrolgame(23,22);
//    object->Graphiccontrolgame(22,27);
//    object->Graphiccontrolgame(20,31);
//    object->Graphiccontrolgame(18,36);*/
//}






