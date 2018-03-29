/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_BLOCK_H__
#define __CODU_BLOCK_H__

#include <string>

#include "record.h"

namespace codu {

class Block {
public:
    Block();

    ~Block();

    int init(const std::string& block_path);

    int destroy();

    int append(const Record& record);
}; // class Block

} // namespace codu

#endif // // __CODU_BLOCK_H__
