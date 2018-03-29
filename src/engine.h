/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <string>

#include "options.h"
#include "index.h"
#include "table.h"
#include "wal.h"

namespace codu {

class Engine {
public:
    Engine();

    ~Engine();

    int init(const std::string& db_path);

    int destroy();

    int put(const std::string& key, const std::string& value);

    int get(const std::string& key, std::string* value);

private:
    WAL* _wal;
    Index* _index;
    Table* _table;
    std::string _db_path;
}; // class Engine

} // namespace codu
