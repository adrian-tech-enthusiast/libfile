/**
 * File read exit status.
 */
#define READ_FAILURE 1
#define READ_SUCCESS 0

/**
 * File write exit status.
 */
#define WRITE_FAILURE 1
#define WRITE_SUCCESS 0

#ifndef FILE_GET_CONTENTS_H
#define FILE_GET_CONTENTS_H

/**
 * Reads entire file into a string.
 *
 * @param const char* filepath
 *   The path to the file to read.
 *
 * @return char*
 *   A dynamically allocated string containing the read data, or NULL on failure.
 */
char *file_get_contents(const char *filepath);

#endif /* FILE_GET_CONTENTS_H */

#ifndef FILE_PUT_CONTENTS_H
#define FILE_PUT_CONTENTS_H

/**
 * Write data to a file.
 *
 * @param const char* filepath
 *   The path to the file where to write the data.
 * @param char* data
 *   The data to write to the file.
 *
 * @return int
 *   Returns WRITE_SUCCESS if the operation succeeded, or WRITE_FAILURE on failure.
 */
int file_put_contents(const char *filepath, char *data);

#endif /* FILE_PUT_CONTENTS_H */