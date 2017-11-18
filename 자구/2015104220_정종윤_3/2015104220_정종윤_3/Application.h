#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "CircularQueueType.h"

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}

	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Push new record into the queue.
	*	@pre	The queue should be initialized.
	*	@post	A new record is pushed into the queue.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int enQueueItem();

	/**
	*	@brief	Pop a record of top from the queue.
	*	@pre	The queue should be initialized.
	*	@post	A top record is poped.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int deQueueItem();

	/**
	*	@brief	Check the queue is empty state.
	*	@pre	The queue should be initialized.
	*	@post	Display the state of queue on screen.
	*	@return	1 if the queue is empty, otherwise 0.
	*/
	int CheckEmpty();

	/**
	*	@brief	Check the queue is full state.
	*	@pre	The queue should be initialized.
	*	@post	Display the state of queue on screen.
	*	@return	1 if the queue is full, otherwise 0.
	*/
	int CheckFull();

	/**
	*	@brief	Test the exeception of empty queue.
	*	@pre	The queue should be initialized.
	*	@post	Do exception funciton when the queue is empty.
	*/
	void TestEmptyException();

	/**
	*	@brief	Test the exeception of full queue.
	*	@pre	The queue should be initialized.
	*	@post	Do exception funciton when the queue is full.
	*/
	void TestFullException();

	/**
	*	@brief	Display all records in the queue on screen.
	*	@pre	The queue should be initialized.
	*	@post	Display all records on screen.
	*/
	void DisplayAllItem();

private:
	CircularQueueType<ItemType> m_queue;	///< item queue.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H