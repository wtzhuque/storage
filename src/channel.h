/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_CHANNEL_H__
#define __CODU_CHANNEL_H__

#include <list>
#include <thread>

#include "block.h"
#include "addr.h"

namespace codu {

class Channel {
public:
    Channel();

    ~Channel();

    int init();

    int destroy();

    int append_block(Block* block);

    int append(const Record& record, Addr* addr);

private:
    void append_loop();

    void compact_loop();

private:
    std::thread* _channel_worker {nullptr};
    Block* _cur_block {nullptr};
    std::list<Block*> _blocks;
}; // class Channel

} // namespace codu

#endif
