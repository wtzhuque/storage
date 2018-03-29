/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_TABLE_H__
#define __CODU_TABLE_H__

#include <string>

#include "record.h"
#include "addr.h"

namespace codu {

class Table {
public:
    Table();

    ~Table();

    /**
     * @brief Init table, load table files from table_path
     */
    int init(const std::string& table_path);

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

}; // class Table

} // namespace codu

#endif // __CODU_TABLE_H__
