#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/filehelper.h"
#include "file_get_contents_unit_test.h"

/**
 * {@inheritdoc}
 */
int run_file_get_contents_unit_tests() {
  // Define the expected file content.
  const char expected_content[] = "test file content";
  // Read the plain text file content.
  char *file_content = file_get_contents("./tests/test-read-file.txt");
  if (file_content == NULL) {
    perror("Error reading file");
    return READ_FAILURE;
  }
  // Compare the file content with the expected content.
  if (strcmp(file_content, expected_content) != 0) {
    perror("File content does not match expected content");
    // Free the memory.
    free(file_content);
    return READ_FAILURE;
  }
  // Print success message.
  printf("[Passed] file_gets_contents.\n");
  // Free the memory.
  free(file_content);
  return READ_SUCCESS;
}