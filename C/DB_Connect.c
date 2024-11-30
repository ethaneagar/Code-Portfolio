/*------------------------------------------------------------------------------
	Function: 			DB_Connect
	
	Call before all other functions. 

	Opens a database and assigns the connection a handle. 
		
	Parameters:
		connectionSring	- string holding SQL connection statement
		multiThread 		- integer to be provided for thread options

								- Single Threaded Program: 	DB_INIT_SINGLETHREADED
								- Multithreaded Program:		DB_INIT_MULTITHREADED

	Return Value:
		status as an integer (DB_SUCCESS, DB_FAILURE)

	Note:
		Updates global dbLastError on error. Use DB_GetLastError() to access. 
------------------------------------------------------------------------------*/
int DB_Connect(char* connectionString, int multiThread)
{
	// check for valid values
	if ((multiThread != DB_INIT_SINGLETHREADED) && (multiThread != DB_INIT_MULTITHREADED))
	{
		// update global last error
		snprintf(dbLastError, sizeof(dbLastError), "Multithread parameter invalid %i.", multiThread);
		return DB_FAILURE;
	}
	
	// -----------------------------------
	// init the SQL toolkit (LabWindows CVI function)
	if (DBInit(multiThread) != DB_SUCCESS)
	{
		return DB_FAILURE;
	}
	
	// open the database and assign handle (LabWindows CVI function)
	dbHandle = DBConnect(connectionString);
	
	// ----------------------------------- 
	// error if connection fails
	if (dbHandle <= 0)
	{
		// update global last error
		snprintf(dbLastError, sizeof(dbLastError), "Failed creating connection to %s.", connectionString);
		return DB_FAILURE;
	} // end if connection error
	
	// update global connection strings
	DB_SetConnectionStatus();

	return DB_SUCCESS;
}	
