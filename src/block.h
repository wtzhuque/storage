/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_BLOCK_H__
#define __CODU_BLOCK_H__

#include <string>

#include "record.h"
#include "addr.h"

namespace codu {

class Block {
public:
    Block();

    ~Block();

    int init(const std::string& block_path);

    int destroy();

    int append(const Record& record, Addr* addr);

    int read(uint32_t offset, Record* record);

private:
    int _cur_offset;
    int _cur_size;
    int _id;
    FILE* _fp;
}; // class Block

} // namespace codu

#endif // // __CODU_BLOCK_H__
