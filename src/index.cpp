/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <stdio.h>

#include "index.h"

namespace codu {

Index::Index() {
}

Index::~Index() {
}

int Index::init(const std::string& index_file, const Options& options) {
    fprintf(stderr, "init index from [%s]\n", index_file.c_str());
    return 0;
}

int Index::destroy() {
    return 0;
}

bool Index::seek(const std::string& key, Addr* addr) {
    return 0;
}

bool Index::insert(const std::string& key, const Addr& addr) {
    return 0;
}


} // namespace codu
