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
    uint32_t size;
    uint32_t capacity;
    uint32_t ts;
    uint32_t ttl;
    char data[0];
}; //struct Record

struct RawString {
    uint32_t size;
    char data[0];
}; // struct RawString

struct RawLog {
    uint64_t record_id;
    uint64_t addr; 
}; // struct RawLog

inline bool get_record_key(const Record& record, std::string* key) {
    return false;
}

inline bool get_record_value(const Record& record, std::string* value) {
    return false;
}

} // namespace codu

#endif // __CODU_RECORD_H__
