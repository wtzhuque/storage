/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_TABLE_H__
#define __CODU_TABLE_H__

#include <string>
#include <vector>
#include <list>

#include "options.h"
#include "record.h"
#include "addr.h"
#include "channel.h"
#include "block.h"

namespace codu {

class Table {
public:
    Table();

    ~Table();

    /**
     * @brief Init table, load table files from table_path
     */
    int init(const std::string& table_path, const Options& options);

    /**
     * @brief deinit table
     */
    int destroy();

    /**
     * @brief append new record to this table, and return record address
     */
    bool append(const Record& record, Addr* addr);

    /**
     * @brief read from table
     */
    bool read(const Addr& addr, Record* record);

private:
    int select_channel(const Record& record);

    int load_manifest(const std::string& manifest_path);

private:
    uint32_t _num_channels;
    uint32_t _num_blocks;
    std::vector<Channel*> _channels;
    std::vector<Block*> _blocks;
}; // class Table

} // namespace codu

#endif // __CODU_TABLE_H__
