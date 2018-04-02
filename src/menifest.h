/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_MENIFEST_H__
#define __CODU_MENIFEST_H__

#include <string>

namespace codu {

class Menifest {
public:
    Menifest();

    ~Menifest();

    int init(const std::string& menifest_path);

    int destroy();
}; // class Menifest

} // namespace codu

#endif // __CODU_MENIFEST_H__
