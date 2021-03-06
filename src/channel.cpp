/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "channel.h"

#include <future>

namespace codu {

Channel::Channel() {

}

Channel::~Channel() {

}

int Channel::init() {
    _channel_worker = new std::thread(&Channel::append_loop, this);
    return 0;
}

int Channel::destroy() {
    _channel_worker->join();
    return 0;
}

int Channel::append_block(Block* block) {
    _blocks.push_back(block);
    _cur_block = block;
    return 0;
}

int Channel::append(const Record& record, Addr* addr) {
    // TODO: do append async
    return _cur_block->append(record, addr);
}
   
void Channel::append_loop() {
}

void Channel::compact_loop() {
}

} //namespace codu
