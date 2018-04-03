/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_COMPRESS_DICT_H__
#define __CODU_COMPRESS_DICT_H__

#include <string>

namespace codu {

class Dict {
public:
    Dict();

    ~Dict();

    int init(const std::string& dict_path);

    int destroy();

    bool seek(const char* seq, size_t size, size_t* offset);

    bool update(const char* seq, size_t size);
}; // class CompressDict

} // namespace codu

#endif // __CODU_COMPRESS_DICT_H__