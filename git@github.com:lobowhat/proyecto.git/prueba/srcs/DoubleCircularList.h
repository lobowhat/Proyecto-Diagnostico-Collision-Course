/*
 * DoubleCircularList->h
 *
 *  Created on: 20/02/2013
 *      Author: jose
 */

#ifndef DOUBLECIRCULARLIST_H_
#define DOUBLECIRCULARLIST_H_

#include "ListADT.h"
#include "DNode.h"

template<typename E> class DoubleCircularList: public ListADT<E> {

private:
	DNode<E>* _head; //Puntero al nodo inicial
	DNode<E>* _tail; //Puntero al nodo final
	int _size;

public:
	DoubleCircularList() { //Constructor
		this->_head = this->_tail = NULL;
		this->_size = 0;
	}

	~DoubleCircularList() {
	} //Destructor

	/**
	 * Insercion de datos de forma desordenada, inserta al final.
	 *
	 */
	void insert(const E& pData) {
		DNode<E>* nNode;
		nNode = new DNode<E>(pData, NULL, NULL);
		if (this->_head == NULL) {
			nNode->setNext(nNode);
			nNode->setPrevious(nNode);
			this->_head = this->_tail = nNode;
			this->_size++;
		} else {
			nNode->setPrevious(this->_head->getPrevious());
			nNode->setNext(this->_head);
			this->_head->getPrevious()->setNext(nNode);
			this->_head->setPrevious(nNode);
			this->_head = nNode;
			this->_size++;
		}
	}

	/**
	 * Inserta en orden los datos.
	 */
	void insertInOrder(const E& pData) {
		DNode<E>* nNode = new DNode<E>(pData);
		if (this->_head == NULL) {
			this->_head = nNode;
			nNode->setPrevious(nNode);
			nNode->setNext(nNode);
			this->_size++;
		} else {
			DNode<E>* tmp = this->_head;
			while (tmp->getData() < pData && tmp->getNext() != this->_head) {
				tmp = tmp->getNext();
			}
			if (tmp->getNext() == this->_head && tmp->getData() < pData) {
				nNode->setNext(tmp->getNext());
				nNode->setPrevious(tmp);
				tmp->getNext()->setPrevious(nNode);
				tmp->setNext(nNode);
				this->_size++;
			} else {
				nNode->setNext(tmp);
				nNode->setPrevious(tmp->getPrevious());
				tmp->getPrevious()->setNext(nNode);
				tmp->setPrevious(nNode);
				this->_size++;
			}
			if (tmp == this->_head) {
				this->_head = nNode;
			}
		}
	}

	/**
	 * Elimina el nodo buscado y devuelve el dato que le pertenece este nodo.
	 *
	 */
	E deleteNode(const E& pData) {
		if (this->_head == NULL) {
			std::cout << "La lista está vacía" << std::endl;
			return 0;
		} else if (this->_head->getNext() == this->_head) {
			E tmpData = this->_head->getData();
			DNode<E>* tmp = this->_head;
			this->_head = NULL;
			delete (tmp);
			this->_size--;
			return tmpData;
		} else if (this->_head->getData() == pData) {
			E tmpData = this->_head->getData();
			DNode<E>* tmp = this->_head;
			this->_head->getNext()->setPrevious(this->_head->getPrevious());
			this->_head->getPrevious()->setNext(this->_head->getNext());
			this->_head = this->_head->getNext();
			delete (tmp);
			this->_size--;
			return tmpData;

		} else {
			DNode<E>* tmp = this->_head;
			while (tmp->getNext() != this->_head && tmp->getData() != pData) {
				tmp = tmp->getNext();
			}
			if (tmp->getData() == pData) {
				E tmpData = tmp->getData();
				tmp->getPrevious()->setNext(tmp->getNext());
				tmp->getNext()->setPrevious(tmp->getPrevious());
				delete (tmp);
				this->_size--;
				return tmpData;
			}
			else{
				return 0;
			}
		}
	}

	/*
	 * Muestra el tamaño de la lista.
	 */
	int length() const {
		return this->_size;
	}

};

#endif /* DOUBLECIRCULARLIST_H_ */
