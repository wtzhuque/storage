/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <stdio.h>

#include "index.h"

namespace codu {

Index::Index()
    : _tree(nullptr) {
}

Index::~Index() {
}

int Index::init(const std::string& index_file, const Options& options) {
    fprintf(stderr, "init index from [%s]\n", index_file.c_str());
    _tree = bplus_tree_init(index_file.c_str(), options.index_block_size);
    if (_tree == nullptr) {
        fprintf(stderr, "create bplus tree failed");
        return -1;
    }
    return 0;
}

int Index::destroy() {
    if (_tree != nullptr) {
        bplus_tree_deinit(_tree);
    }
    return 0;
}

bool Index::seek(const std::string& key, Addr* addr) {
    uint64_t key_sign = sign(key);
    long tmp = bplus_tree_get(_tree, key_sign);
    if (tmp == 0) {
        return false;
    } else {
        *addr = *((Addr*)(&tmp));
        return true;
    }
}

bool Index::insert(const std::string& key, const Addr& addr) {
    uint64_t key_sign = sign(key);
    int ret = bplus_tree_put(_tree, key_sign, *(long*)(&addr));
    if (ret != 0) {
        return false;
    } else {
        return true;
    }
}

uint64_t Index::sign(const std::string& str) {
    return 0;
}


} // namespace codu
