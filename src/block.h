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

    /**
     * @brief 初始化Block
     */
    int init(const std::string& block_path);

    /**
     * @brief 销毁Block对象.
     */
    int destroy();

    /**
     * @brief 追加Record到Block文件尾.
     */
    int append(const Record& record, Addr* addr);

    /**
     * @brief 追加Log到Block文件尾.
     */
    int append(const RawLog& log);

    /**
     * @brief 从Block读文件, 偏移量offset.
     */
    int read(uint32_t offset, Record* record);

private:
    int _cur_offset;
    int _cur_size;
    int _id;
    FILE* _fp;
}; // class Block

} // namespace codu

#endif // // __CODU_BLOCK_H__
