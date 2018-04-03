/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "wal.h"

namespace codu {

WAL::WAL()
    : _cur_block(nullptr) {
}

WAL::~WAL() {
}

int WAL::init(const std::string& wal_path) {
    return 0;
}

int WAL::destroy() {
    return 0;
}

int WAL::append(const RawLog& log) {
    return 0;
}

int WAL::flush() {
    return 0;
}

} // namespace codu