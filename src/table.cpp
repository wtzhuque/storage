/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "table.h"

namespace codu {

Table::Table() {
}

Table::~Table() {
}

int Table::init(const std::string& table_path) {
    fprintf(stderr, "init table from [%s]\n", table_path.c_str());
    return 0;
}

int Table::destroy() {
    return 0;
}

bool Table::append(const Record& record, Addr* addr) {
    return true;
}

bool Table::read(const Addr& addr, Record* record) {
    return true;
}

} // namespace codu
