/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_ENGINE_H__
#define __CODU_ENGINE_H__

#include <string>

#include "options.h"
#include "index.h"
#include "table.h"
#include "menifest.h"
#include "record.h"

namespace codu {

class Engine {
public:
    Engine();

    ~Engine();

    int init(const std::string& db_path, const Options& options);

    int destroy();

    int put(const std::string& key, const std::string& value);

    int get(const std::string& key, std::string* value);

private:
    bool encode_record(const std::string& key, const std::string& value, Record* record);

    bool decode_record(const Record& record, std::string* key, std::string* value);

private:
    Index* _index;
    Table* _table;
    Menifest* _menifest;
    std::string _db_path;
}; // class Engine

} // namespace codu

#endif // __CODU_ENGINE_H__
