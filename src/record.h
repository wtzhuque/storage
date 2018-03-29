/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_RECORD_H__
#define __CODU_RECORD_H__

#include <string>

namespace codu {

struct Record {
    uint64_t record_id;
    char data[0];
}; //struct Record

inline bool get_record_key(const Record& record, std::string* key) {
    return false;
}

inline bool get_record_value(const Record& record, std::string* value) {
    return false;
}

} // namespace codu

#endif // __CODU_RECORD_H__
