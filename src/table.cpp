/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "table.h"

#include <boost/lexical_cast.hpp>

namespace codu {

static const char* DB_PATH_TABLE_DICT = "dict";

Table::Table()
    : _dict(nullptr) {
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

    // init dict
    const std::string dict_path = table_path + DB_PATH_TABLE_DICT; 
    _dict = new Dict();
    int ret = _dict->init(dict_path);
    if (ret != 0) {
        fprintf(stderr, "init dict [%s] failed\n", dict_path.c_str());
        return ret;
    }

    // init blocks
    // TODO: read block files from menifest
    int num_blocks = 4;
    std::vector<std::string> block_files(num_blocks);
    for (int i = 0; i < num_blocks; ++i) {
        std::string block_file = table_path + "/block." + boost::lexical_cast<std::string>(i);
        block_files[i] = block_file;
    }

    // init block objects
    for (int i = 0; i < num_blocks; ++i) {
        Block* block = new Block();
        if (block->init(block_files[i]) != 0) {
            fprintf(stderr, "init block [%d] failed\n", i);
            continue;
        }
        _blocks.push_back(block);
    }

    // init blocks

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

int Table::load_compress_dict(const std::string& dict_path) {
    return 0;
}

int Table::destroy() {
    return 0;
}

bool Table::append(const Record& record, Addr* addr) {
    int channel_id = select_channel(record);
    Record tmp_record;
    encode(record, &tmp_record);
    int ret = _channels[channel_id]->append(tmp_record, addr);
    if (ret != 0) {
        fprintf(stderr, "append record to channel[%d] failed\n", channel_id);
        return false;
    }
    return true;
}

bool Table::read(const Addr& addr, Record* record) {
    Block* block = _blocks[addr.block_id];
    Record tmp_record;
    int ret = block->read(addr.offset, &tmp_record);
    if (ret != 0) {
        fprintf(stderr, "read from block [%u] failed\n", addr.block_id);
    }
    decode(tmp_record, record);
    return true;
}

int Table::select_channel(const Record& record) {
    return record.record_id % _num_channels;
}

bool Table::encode(const Record& record, Record* coded_record) {
    return true;
}

bool Table::decode(const Record& record, Record* uncoded_record) {
    return true;
}

} // namespace codu
