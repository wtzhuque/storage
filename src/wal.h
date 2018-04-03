/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <string>
#include <list>

#include "record.h"
#include "block.h"

namespace codu {

class WAL {
public:
    WAL();

    ~WAL();

    /**
     * @brief 初始化WAL日志.
     */
    int init(const std::string& wal_path);

    int destroy();

    /**
     * @brief 追加Log
     */
    int append(const RawLog& log);

    /**
     * @brief 刷新缓存到文件.
     */
    int flush();

private:
    Block* _cur_block;
    std::list<Block*> _blocks;
}; // class WAL

} // namespace codu
