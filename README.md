## LibFile: A Lightweight and Easy-to-Use C Library for Common File Operations.

`LibFile` provides easy-to-use helper functions for file operations. This library simplifies the process of reading and writing files in C by offering straightforward functions to write data to a file and read the entire contents of a file into a string.

### Key Features

- **Write Data to a File**: Easily write data to a specified file.
- **Read Entire File**: Read the entire contents of a file into a dynamically allocated string, handling all memory management for you.
- **Error Handling**: Built-in error handling to manage common file operation issues.


### Prerequisites

Ensure you have a C compiler installed on your system, such as `gcc` or `clang`.

### Getting Started

To start using `LibFile`, clone the repository, include it in your project and refer to the documentation for
guidance on how to implement each function within file operations.

### Installation

To make sure you obtain the most updated stable version
of [shared library](https://en.wikipedia.org/wiki/Library_(computing)#Shared_libraries)(a DLL in Windows or .so in
Unix/Linux), you’ll download this software from
its [official Github repository](https://github.com/adrian-tech-enthusiast/libfile).

First, confirm the latest version available in
their [releases page](https://github.com/adrian-tech-enthusiast/libfile/releases). At the time of this writing,
the most current stable version is `1.0.0`.

1. The following command will download the `1.0.0` release and save the shared library file at
   /usr/local/lib/libfile.so, which will make this library globally accessible to clients:

    ```bash
    sudo curl -L "https://github.com/adrian-tech-enthusiast/libfile/releases/download/v1.0.0/libfile.so" -o /usr/local/lib/libfile.so
    ```

2. Next, We need to tell the loader it is available for use, so let us update the cache, invoke the `ldconfig` utility,
   which configures the system's dynamic loader. This configuration ensures that the loader will find the newly
   published library:

    ```bash
    sudo ldconfig;
    ```

   That should create a link to our shared library and update the cache so it is available for immediate use. To verify
   you can run:

    ```bash
    ldconfig -p | grep file
    ```

3. Copy the library header file(`filehelper.h`) to where it can be included in one of the C compiler's search path.
   Typical locations are `/usr/include` and `/usr/local/include`;

    ```bash
    sudo curl -L "https://raw.githubusercontent.com/adrian-tech-enthusiast/libfile/v1.0.0/include/filehelper.h" -o /usr/local/include/filehelper.h;
    ```

   This allows the library header file to be included in your C project as follows:

    ```c
    #include <stdio.h>  /* standard input/output functions */
    #include <filehelper.h> /* C File Helper Library functions */
    ```
   Without this `#include`, the compiler would complain about missing declarations for functions provided by the C
   File Library.

4. Finally, in order to compile your code with the library, add the link flag to the library during the compilation of
   your C project:

    ```bash
    gcc -o tester tester.c -lactivation
    ```

### Example Usage

#### Example 1: Writing to a File

```c
#include "file_put_contents.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *data = "Hello, World!";
    const char *file_path = "example.txt";

    // Write data to file
    if (file_put_contents(file_path, data) != WRITE_SUCCESS) {
        fprintf(stderr, "Failed to write to file.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```

#### Example 2: Reading from a File

```c
#include "file_get_contents.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *file_path = "example.txt";
    char *file_contents = file_get_contents(file_path);

    if (file_contents == NULL) {
        fprintf(stderr, "Failed to read from file.\n");
        return EXIT_FAILURE;
    }

    printf("File contents: %s\n", file_contents);
    free(file_contents);

    return EXIT_SUCCESS;
}
```

#### Compiling the Code

To compile your program, you might use a command like this, depending on your setup:

```bash
gcc -o my_program my_program.c -lfilehelper
```

Replace `my_program.c` with the name of your source file. Make sure that the libfile is correctly linked.

### Contributions

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any
contributions you make are greatly appreciated.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### License

This library is licensed under the `GNU General Public License v3.0` License. See the LICENSE file for details.

### Contact

Mr. Adrián Morelos - adrian.tech.enthusiast@gmail.com