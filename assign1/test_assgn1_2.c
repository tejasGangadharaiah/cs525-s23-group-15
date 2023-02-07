// C Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// MACROS Definition Files
#include "dberror.h"
#include "storage_mgr.h"
#include "test_helper.h"

// Output File
#define FILE_NAME "DummyPageFile.bin"

// Functions Holding File Operations
static void testFileOperations(void);
static void additionalTestSinglePageOperations(void);

// Executable Functions
int main(void) {
  char *test_name = "Initialize Test Cases";

  initStorageManager();
  testFileOperations();
  additionalTestSinglePageOperations();

  return 0;
}

/*-----------------------------------------FILE OPERATIONS ( CREATE/OPEN/CLOSE * )-------------------------*/
void testFileOperations(void) {
  SM_FileHandle file_handle;

  char *test_name = "File Operations";

  // Step 1 :- Create File
  TEST_CHECK(createPageFile(FILE_NAME));

  // Step 2 :- Open File
  TEST_CHECK(openPageFile(FILE_NAME, &file_handle));

  /*---------------------USE CASES-----------------------------------------------------------------------*/

  // Use Case 1 :- Check File Name
  ASSERT_TRUE(strcmp(file_handle.fileName, FILE_NAME) == 0, "FileName Verified");

  // Use Case 2 :- Check File Consists of 1 Page
  ASSERT_TRUE((file_handle.totalNumPages == 1), "File Consists of 1 Page");

  // Use Case 3 :- Check Current Page Position
  ASSERT_TRUE((file_handle.curPagePos == 0), "File Page Positiion Should be 0");

  /*-----------------------------------------------------------------------------------------------------*/

  // Step 3 :- Close the File
  TEST_CHECK(closePageFile(&file_handle));

  // Step 4 :- Destroy the file
  TEST_CHECK(destroyPageFile(FILE_NAME));

  // Use Case 4 :- Opening Closed File
  ASSERT_TRUE((openPageFile(FILE_NAME, &file_handle) != RC_OK),
              "Error Opening Non-Existent File");

  // Test Case Completed
  TEST_DONE();
}
