#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/filehelper.h"
#include "file_put_contents_unit_test.h"

/**
 * {@inheritdoc}
 */
int run_file_put_contents_unit_tests() {
  // Define the expected file content.
  char expected_content[] = "test file content";
  // Write content to the plain text file.
  if (file_put_contents("./tests/test-write-file.txt", expected_content) == WRITE_FAILURE) {
    perror("Error writing to file");
    return WRITE_FAILURE;
  }
  // Read back the content to verify the write operation.
  char *file_content = file_get_contents("./tests/test-write-file.txt");
  if (file_content == NULL) {
    perror("Error reading file");
    return WRITE_FAILURE;
  }
  // Compare the written content with the expected content.
  if (strcmp(file_content, expected_content) != 0) {
    perror("Written content does not match expected content");
    free(file_content);
    return WRITE_FAILURE;
  }
  // Print success message.
  printf("[Passed] file_put_contents.\n");
  // Clean up and return success.
  free(file_content);
  return WRITE_SUCCESS;
}