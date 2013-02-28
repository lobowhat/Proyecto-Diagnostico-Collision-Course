/*
 * DoubleCircularList.h
 *
 *  Created on: 20/02/2013
 *      Author: jose
 */

#ifndef LISTADT_H_
#define LISTADT_H_

//Clase Abstracta de Lista

template<typename E>
class ListADT {

public:
	ListADT() {
	} //Constructor
	virtual ~ListADT() {
	} //Destructor

	// Inserta un elemento.
	// item: Elemento a insertar.
	virtual void insert(const E& item) = 0;

	// Inserta un dato en orden.
	// item: Elemento a insertar.
	virtual void insertInOrder(const E& item) = 0;

	// Elimina y devuelve el valor.
	// Retorna: el elemento que fue borrado.
	virtual int deleteNode(const E& pData) = 0;

	// Retorna: Tamaño de la lista.
	virtual int length() const = 0;
};

#endif /* LISTADT_H_ */
