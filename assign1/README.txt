/////////////////CS - 525 Assignment 1///////////////////////
/////////////////Storage Manager////////////////////////////
/////////////////////Group 15///////////////////////////////

Daniel Lee - A20378466 - daniel.lee@iit.edu
Vatsal Mishra - A20522004 - vmishra6@hawk.iit.edu
Tejas Sinapanahalli Gangadharaiah - A20466768 - tsinapanahalligangad@hawk.iit.edu		

////////////////////////	///////////////////////////////////

 Github Structure submitted:
		git
			assign1
			    Makefile
			    README.txt
			    dberror.c
			    dberror.h
			    storage_mgr.c
			    storage_mgr.h
			    test_assign1_1.c
			    test_helper.h
			   

Instructions for running:

Steps for running through makefile:

Step 1: $ make
Step 2: $ ./test_assign1_1	

Additional test case running step

Step 1-  $ ./test_assign1_2

//////////////////////////////////////////////////////////

createPageFile:

1. Opens a file with mode "w+" (write and read)
2. Allocates memory for a page using calloc, and sets the memory to zero
3. Writes the contents of the memory block to the file
4. Frees the memory used for the page
5. Closes the file
6. Returns RC_OK if successful, or RC_FILE_NOT_FOUND or RC_WRITE_FAILED if failed


openPageFile:

1.Opens a file with mode "r" (read-only)
2.If the file is successfully opened, stores the file name and other information in the SM_FileHandle struct
3.Returns RC_OK if successful, or RC_FILE_NOT_FOUND if failed


getFileSize:

1.Gets the current position of the file pointer
2.Moves the file pointer to the end of the file
3.Gets the size of the file
4.Moves the file pointer back to its original position
5.Returns the size of the file


closePageFile:

1.Closes the file handle pointed to by fHandle->mgmtInfo
2.If the file handle was closed successfully, sets the mgmtInfo field of the file handle to NULL and returns RC_OK
3.If the file handle was not closed successfully, returns RC_FILE_NOT_CLOSED


destroyPageFile:

1. Deletes the file using the remove function
2. If the file was successfully deleted, returns RC_OK
3. If the file was not found, returns RC_FILE_NOT_FOUND

 
Write Functions():

a)writeBlock(): Writes data to a specific page. It checks if the page number is valid, if the file handle is not null,
sets the file pointer to the correct position, writes the block, updates the current page position, 
and updates the total number of pages.

b)writeCurrentBlock(): Writes data to the current page. It gets the current page position, calls the writeBlock() function,
and returns RC_OK if the write is successful, else RC_WRITE_FAILED.


c)appendEmptyBlock(): Appends an empty block to the file. It checks if the file handle is not null, 
creates a buffer of PAGE_SIZE, sets the file pointer to the end of the file, writes an empty block,
and updates the total number of pages and the current page position.

d)ensureCapacity(): Ensures the file has sufficient capacity. It checks if the total number 
of pages is less than the desired capacity, calculates the number of pages to be added, 
and appends empty blocks until the desired capacity is reached.
