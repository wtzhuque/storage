/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_RECORD_POOL_H__
#define __CODU_RECORD_POOL_H__

#include "record.h"

namespace codu {

class RecordPool {
public:
    static Record* alloc(size_t size);

    static void free(Record* record);
}; // class Pool

} // namespace codu

#endif // __CODU_RECORD_POOL_H__
