#include <stdlib.h>
#include "../include/filehelper.h"
#include "file_get_contents_unit_test.h"
#include "file_put_contents_unit_test.h"

/**
 * Main Unit Testing controller function.
 *
 * @param int argc
 *   The number of arguments passed by the user in the command line.
 * @param array argv
 *   Array of char, the arguments names.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int main(int argc, char const *argv[]) {
  if (run_file_get_contents_unit_tests() == READ_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  if (run_file_put_contents_unit_tests() == WRITE_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  // Unit tests succeeded.
  return EXIT_SUCCESS;
}
