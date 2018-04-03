/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "dict.h"

namespace codu {

Dict::Dict() {
}

Dict::~Dict() {
}

int Dict::init(const std::string& dict_path) {
    return 0;
}

int Dict::destroy() {
    return 0;
}

bool Dict::seek(const char* seq, size_t size, size_t* offset) {
    return true;
}

bool Dict::update(const char* seq, size_t size) {
    return true;
}

} // namespace codu