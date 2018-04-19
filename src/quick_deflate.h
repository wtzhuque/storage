/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_QUICK_DEFLATE_H__
#define __CODU_QUICK_DEFLATE_H__

#include <string>

namespace codu {

class Codec;
class Decoder;
class Encoder;
class CodecBuilder;

class CodecBuilder {
public:
    int init();

    int destroy();

    void put(const std::string& buffer);

    void put(const char* buffer, size_t size);

    void dump(const std::string& file);

private:
}; // class Builder

class Codec {
public:
    int init(const std::string& coding_table);

    int destroy();

    bool seek_prefix(const char* code, size_t code_size, char* prefix, size_t& prefix_size);

    bool seek_code(const char* prefix, size_t prefix_size, char* code, size_t& code_size);
}; // class Codec

class Decoder {
public:
    Decoder(Codec* codec);

    bool decode(const char* buff_in, size_t size_in, char* buff_out, size_t& size_out);
}; // class Decoder

class Encoder {
public:
    Encoder(Codec* codec);

    bool encode(const char* buff_in, size_t size_in, char* buff_out, size_t& size_out);
}; // class Encoder

} // namespace codu

#endif