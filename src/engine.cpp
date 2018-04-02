/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "engine.h"

#include <stdio.h>

namespace codu {

const char* DB_PATH_WAL = "/wal";
const char* DB_PATH_INDEX = "/index";
const char* DB_PATH_TABLE = "/table";

Engine::Engine()
    : _index(nullptr),
      _table(nullptr) {
}

Engine::~Engine() {
}
    
int Engine::init(const std::string& db_path, const Options& options) {
    _db_path.assign(db_path);

    int ret = 0;

    _index = new Index();
    std::string index_path = _db_path + DB_PATH_INDEX;
    ret = _index->init(index_path, options);
    if (ret != 0) {
        fprintf(stderr, "index init failed err=%d\n", ret);
        return ret;
    }

    _table = new Table();
    std::string table_path = _db_path + DB_PATH_TABLE;
    ret = _table->init(table_path, options);
    if (ret != 0) {
        fprintf(stderr, "table init failed err=%d\n", ret);
        return ret;
    }
    
    
    fprintf(stderr, "init engine [%s] succ\n", db_path.c_str());
    return ret;
}

int Engine::destroy() {
    fprintf(stderr, "destroy engine succ\n");

    int ret = 0;

    if (_index != nullptr) {
        ret = _index->destroy();
        if (ret != 0) {
            fprintf(stderr, "destroy index failed err=%d\n", ret);
        }
    }

    if (_table != nullptr) {
        ret = _table->destroy();
        if (ret != 0) {
            fprintf(stderr, "destroy table failed err=%d\n", ret);
        }

    }

    return ret;
}

int Engine::put(const std::string& key, const std::string& value) {
    // TODO: alloc from object pool
    Record* record = new Record();
    Addr* addr = new Addr();

    // generate record
    if (!encode_record(key, value, record)) {
        return -1;
    }
    
    // append record to table and get address
    if (!_table->append(*record, addr)) {
        return -1;
    }

    // update address in index
    if (!_index->insert(key, *addr)) {
        return -1;
    }

    return 0;
}

int Engine::get(const std::string& key, std::string* value) {
    // TODO: alloc from object pool
    Record* record = new Record();
    Addr* addr = new Addr();

    // seek address from index
    if (!_index->seek(key, addr)) {
        return -1;
    }

    // read data from table
    if (_table->read(*addr, record)) {
        return -1;
    }

    // decode value
    if (!decode_record(*record, nullptr, value)) {
        return -1;
    }

    return 0;
}

bool Engine::encode_record(const std::string& key, const std::string& value, Record* record) {
    return true;
}

bool Engine::decode_record(const Record& record, std::string* key, std::string* value) {
    return true;
}

} // namespace codu
