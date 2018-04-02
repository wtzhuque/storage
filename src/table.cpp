/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "table.h"

namespace codu {

Table::Table() {
}

Table::~Table() {
}

int Table::init(const std::string& table_path, const Options& options) {
    fprintf(stderr, "init table from [%s]\n", table_path.c_str());
    _num_channels = options.num_channels;

    _channels.resize(_num_channels);

    for (uint32_t i = 0; i < _num_channels; ++i) {
        _channels[i] = new Channel();
    }

    // init blocks
    std::string menifest_path = table_path + "/menifest";
    int ret = load_manifest(menifest_path);
    if (ret != 0) {
        fprintf(stderr, "load menifest failed");
    }

    // init channel with blocks
    for (size_t i = 0; i < _blocks.size(); ++i) {
        size_t channel_id = i % _num_channels;
        _channels[channel_id]->append_block(_blocks[i]);
    }

    return 0;
}

int Table::load_manifest(const std::string& manifest_path) {
    return 0;
}

int Table::destroy() {
    return 0;
}

bool Table::append(const Record& record, Addr* addr) {
    int channel_id = select_channel(record);
    int ret = _channels[channel_id]->append(record, addr);
    if (ret != 0) {
        fprintf(stderr, "append record to channel[%d] failed\n", channel_id);
        return false;
    }
    return true;
}

bool Table::read(const Addr& addr, Record* record) {
    Block* block = _blocks[addr.block_id];
    int ret = block->read(addr.offset, record);
    if (ret != 0) {
        fprintf(stderr, "read from block [%u] failed\n", addr.block_id);
    }
    return true;
}

int Table::select_channel(const Record& record) {
    return record.record_id % _num_channels;
}

} // namespace codu
