/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <stdio.h>
#include <stdlib.h>

namespace codu {

class FileIO {
public:
    FileIO(int fd);

    ~FileIO();

    int append(const char* buffer, uint32_t size);
    
    int read(uint32_t offset, uint32_t size, char* buffer, uint32_t* rsize);

    int write(uint32_t offset, uint32_t size, char* buffer, uint32_t* wsize);

    int flush();

private:
    int _fd;
}; // class FileIO

} // namespace
