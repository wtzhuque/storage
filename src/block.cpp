/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include "block.h"

namespace codu {

Block::Block()
    : _cur_offset(0),
      _cur_size(0),
      _fp(nullptr) {
}

Block::~Block() {
}

int Block::init(const std::string& block_path) {
    _fp = fopen(block_path.c_str(), "ab+");
    if (_fp == nullptr) {
        fprintf(stderr, "init block [%s] failed\n", block_path.c_str());
    }
    return 0;
}

int Block::destroy() {
    if (_fp != nullptr) {
        fflush(_fp);
        fclose(_fp);
    }
    return 0;
}

int Block::append(const Record& record, Addr* addr) {
    if (_cur_offset != _cur_size) {
        fseek(_fp, _cur_size, SEEK_SET);
        _cur_offset = _cur_size;
    }
    
    size_t record_size = fwrite(&record, sizeof(record) + record.size, sizeof(char), _fp);

    addr->offset = _cur_offset;
    addr->block_id = _id;

    _cur_size += record_size;
    _cur_offset += record_size;
    return 0;
}

int Block::append(const RawLog& log) {
    if (_cur_offset != _cur_size) {
        fseek(_fp, _cur_size, SEEK_SET);
        _cur_offset = _cur_size;
    }

    size_t log_size = fwrite(&log, sizeof(log), sizeof(char), _fp);

    _cur_size += log_size;
    _cur_offset += log_size;
    return 0;
}

int Block::read(uint32_t offset, Record* record) {
    fseek(_fp, offset, SEEK_SET);
    fread((void*)record, sizeof(Record), 1, _fp);
    fread((void*)record->data, record->size, sizeof(char), _fp);
    _cur_offset = offset;
    return 0;
}

} // namespace codu
