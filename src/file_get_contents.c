#include <stdio.h>
#include <stdlib.h>
#include "../include/filehelper.h"
#include <string.h>
#include <errno.h>

/**
 * {@inheritdoc}
 */
char *file_get_contents(const char *filepath) {
  // Try to open the file.
  FILE *stream = fopen(filepath, "rb");
  if (stream == NULL) {
    perror("It was not possible to open the given filepath");
    return NULL;
  }
  // Moves file pointer position to the end of file.
  fseek(stream, 0, SEEK_END);
  // Get the file length.
  size_t size = ftell(stream);
  // Moves file pointer position back to the beginning of the file.
  fseek(stream, 0, SEEK_SET);
  // Creates the string for the file contents.
  char *buffer = (char *)malloc(sizeof(char) * (size + 1));
  if (buffer == NULL) {
    fclose(stream);
    perror("Failed to allocate memory for the given file");
    return NULL;
  }
  // Set the contents of the string.
  size_t bytes_read = fread(buffer, sizeof(char), size, stream);
  if (bytes_read != size) {
    fclose(stream);
    free(buffer);
    perror("Failed to read the given file");
    return NULL;
  }
  // Add end of character symbol.
  buffer[size] = '\0';
  // Close the file stream.
  fclose(stream);
  // Return the read data.
  return buffer;
}
