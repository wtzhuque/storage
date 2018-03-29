/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "engine.h"

#include <stdio.h>

namespace codu {

const char* DB_PATH_WAL = "wal";
const char* DB_PATH_INDEX = "index";
const char* DB_PATH_TABLE = "table";

Engine::Engine()
    : _wal(nullptr),
      _index(nullptr),
      _table(nullptr) {
}

Engine::~Engine() {
}
    
int Engine::init(const std::string& db_path) {
    _db_path.assign(db_path);

    _wal = new WAL();

    _index = new Index();

    _table = new Table();
    
    fprintf(stderr, "init engine [%s] succ\n", db_path.c_str());

    return 0;
}

int Engine::destroy() {
    fprintf(stderr, "destroy engine succ\n");
    return 0;
}

int Engine::put(const std::string& key, const std::string& value) {
    return 0;
}

int Engine::get(const std::string& key, std::string* value) {
    return 0;
}

} // namespace codu
