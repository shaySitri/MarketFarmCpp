/*
 * Exceptions.h
 *
 *  Created on: Jan 7, 2022
 *      Author: ise
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include <exception>
using namespace std;



class cowException : public exception{
public:
	cowException() {}
	virtual ~cowException() {}
	virtual const char* what() const throw() {return "Insert valid number of cow farms";}


};

class sheepException : public exception{
public:
	sheepException() {}
	virtual ~sheepException() {}
	virtual const char* what() const throw() {return "Insert valid number of sheep farms";}


};

class chickenException : public exception{
public:
	chickenException() {}
	virtual ~chickenException() {}
	virtual const char* what() const throw() {return "Insert valid number of chicken farms";}

};
#endif /* EXCEPTIONS_H_ */
