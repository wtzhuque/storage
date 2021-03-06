/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_INDEX_H__
#define __CODU_INDEX_H__

#include <string>

#include "options.h"
#include "bplustree.h"
#include "addr.h"

namespace codu {

class Index {
public:
    Index();

    ~Index();

    /**
     * @brief init index from index_file
     */
    int init(const std::string& index_file, const Options& options);

    /**
     * @brief destroy index
     */
    int destroy();

    /**
     * @brief seek key from index, return address in table
     */
    bool seek(const std::string& key, Addr* addr);

    /**
     * @brief insert key to index.
     */
    bool insert(const std::string& key, const Addr& addr);

private:
    uint64_t sign(const std::string& str);

private:
    bplus_tree* _tree;
}; // class Index

} // namespace codu

#endif // __CODU_INDEX_H__
