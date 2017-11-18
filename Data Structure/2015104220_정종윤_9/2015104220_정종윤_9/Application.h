#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <iostream>
using namespace std;

#include "ItemType.h"
#include "Graph.h"

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
	*	@brief	Add new vertex into list.
	*	@pre	Graph should be initialized.
	*	@post	new vertex is added into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int AddVertex();

	/**
	*	@brief	Add new weight into list.
	*	@pre	Graph should be initialized.
	*	@post	new weight is added into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int AddWeight();

	/**
	*	@brief	Display all items in the graph on screen.
	*	@pre	none.
	*	@post	All Items are displayed.
	*/
	void PrintItem();

	/**
	*	@brief	Display all weights in the graph on screen.
	*	@pre	none.
	*	@post	All weights are displayed.
	*/
	void PrintWeight();

	/**
	*	@brief	Retrieve item in the list by getting ID
	*	@detail	Get ID and search items. Print iterator number if items exist, otherwise error message
	*	@pre	Get ID
	*/
	void RetrieveItem();

private:
	CGraph<ItemType> m_List;	///< binary search tree data structure
	int m_nCurCommand;	///< current command number 
};

#endif