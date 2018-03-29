/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_META_H__
#define __CODU_META_H__

#include <string>

namespace codu {

class Meta {
public:
    Meta();

    ~Meta();

    int init(const std::string& meta_path);

    int destroy();

private:
    
}; // class Meta

} // namespace codu

#endif // __CODU_META_H__
