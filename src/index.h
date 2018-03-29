/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <string>

#include "addr.h"

namespace codu {

class Index {
public:
    Index();

    ~Index();

    int init(const std::string& index_file);

    int destroy();

    int seek(const std::string& key, Addr* addr);

    int insert(const std::string& key, Addr* addr);
}; // class Index

} // namespace codu
