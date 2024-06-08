#include <stdio.h>
#include <stdlib.h>
#include "../include/filehelper.h"

/**
 * {@inheritdoc}
 */
int file_put_contents(const char *filepath, char *data) {
  // Try to open the file.
  FILE *stream = fopen(filepath, "w");
  if (stream == NULL) {
    perror("It was not possible to open the given filepath.");
    return WRITE_FAILURE;
  }
  // Write data to the file.
  if (fputs(data, stream) == EOF) {
    fclose(stream);
    perror("Error writing to file");
    return WRITE_FAILURE;
  }
  // Close the file stream.
  fclose(stream);
  // Returns a successful exit code.
  return WRITE_SUCCESS;
}
