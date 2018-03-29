/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <string>

#include "record.h"

namespace codu {

class WAL {
public:
    WAL();

    ~WAL();

    int init(const std::string& file);

    int destroy();

    int append();

    int flush();
}; // class WAL

} // namespace codu
