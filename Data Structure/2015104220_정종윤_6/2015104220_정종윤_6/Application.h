#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "LinkedList.h"
#include "MyBase.h"
#include "MyCircle.h"
#include "MyTriangle.h"
#include "MyRectangle.h"

#include <iostream>
using namespace std;


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
		m_nCurCommand = 0;
	}

	/**
	*	destructor.
	*/
	~Application()
	{
	}

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
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAll();


	/**
	*	@brief	call draw funtion in Polygon.h
	*	@pre	m_list should be initialized
	*	@post	new item is added into the list.
	*	@param	[item] item that user want to add
	*/
	void DrawItem(MyBase* item);



private:
	int m_nCurCommand;	///< current command number
	DoublyUnsortedLinkedList<MyBase*> m_list; ///< Linked-list for ItemType.
};

#endif