/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "record_pool.h"

#include <string.h>
#include <list>

namespace {
    static thread_local std::list<::codu::Record*> t_free_records;
}

namespace codu {

static const int DEFAULT_RECORD_SIZE = 4 * 1024;

Record* malloc_new_record(size_t size) {
    Record* record = (Record*)(new char[sizeof(Record) + size]);
    record->record_id = 0;
    record->size = 0;
    record->capacity = size;
    record->ts = 0;
    record->ttl = 0;
}

Record* realloc_record(Record* record, size_t size) {
    if (record->capacity >= size) {
        return record;
    } else {
        Record* tmp = (Record*)(new char[sizeof(Record) + size]);
        memmove((void*)tmp, (void*)record, sizeof(Record) + record->size);
        tmp->capacity = size;
        delete [] (char*)(record);
        return tmp;
    }
}

Record* RecordPool::alloc(size_t size) {
    if (size == 0) {
        if (t_free_records.size() > 0) {
            Record* tmp = t_free_records.front();
            t_free_records.pop_front();
            return tmp;
        } else {
            return malloc_new_record(DEFAULT_RECORD_SIZE);
        }
    } else {
        for (auto& iter : t_free_records) {
            if (iter->capacity >= size) {
                return iter;
            }
        }
        return malloc_new_record(size);
    }
}

void RecordPool::free(Record* record) {
    t_free_records.push_back(record);
}

} // namespace codu
