#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"

#define FILENAMESIZE 1024

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
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	Search a item from list.
	*	@pre	There must be exist data that user want to search.
	*	@post	Display item that user want to search.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchItem();

	/**
	*	@brief	Delete a item from the list.
	*	@pre	There must be exist data that user want to delete.
	*	@post	Get ID from user and delete the item which have same name.
	*	@return	noen.
	*/	
	void DeleteItem();

	/**
	*	@brief	Update a item in the list.
	*	@pre	There must be exist data that user want to update.
	*	@post	Data in item are renewed.
	*	@return none.
	*/
	void UpdataItem();

	/**
	*	@brief	Search list by checking there is a same name.
	*	@pre	none.
	*	@post	Call retrieveRecordByMemberName().
	*	@return	Return 1 if this fucntion works well.
	*/
	int retrieveRecordByMemberName();

	/**
	*	@brief	Search List by member name.
	*	@pre	There must be exist data that user want to search.
	*	@post	Print data.
	*	@param	inData	Role primary key.
	*	@return Return 1 if this fucntion works well.
	*/
	int SearchListByMemberName(ItemType& inData);
	
	
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	ArrayList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H