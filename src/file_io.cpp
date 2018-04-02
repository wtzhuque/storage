/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "file_io.h"

namespace codu {

FileIO::FileIO(int fd)
    : _fd(fd) {
}

FileIO::~FileIO() {
}

int FileIO::append(const char* buffer, uint32_t size) {
    return 0;
}

int FileIO::read(uint32_t offset, uint32_t size, char* buffer, uint32_t* rsize) {
    return 0;
}

int FileIO::write(uint32_t offset, uint32_t size, char* buffer, uint32_t* wsize) {
    return 0;
}

int FileIO::flush() {
    return 0;
}

} // namespace codu