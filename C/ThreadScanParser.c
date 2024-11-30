/*------------------------------------------------------------------------------
	Function:	ThreadScanParser

	This function will check and return the type of data that was scanned in.

	Parameters:
		scanData	- 	pointer to char, the scanned information

	Return Value:
		BARCODE_TYPE	-	see <Barcode Types>
------------------------------------------------------------------------------*/
int ThreadScanParser(char *scanData)
{
	int index;
	
	// check for each barcode type
	for (index = 0; index < MAX_BARCODES; ++index)
	{
		// see if the scan is a match to a known barcode type
		if (strcmp(scanData, BARCODE_STR[index]) == 0)
		{
			if (debugMode == TRUE)
			{
				// display status	
				sprintf(statusStr, "scanner: FOUND known barcode (%s)", scanData);  		
			}
			return index;
		}
	} // end of for each barcode 
	
	// else the scan code be a serial, return to caller and let them figure it out
	return BARCODE_SERIAL;
	
}
