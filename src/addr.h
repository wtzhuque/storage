/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_ADDR_H__
#define __CODU_ADDR_H__

#include <stdlib.h>

namespace codu {

struct Addr {
    uint16_t block_id;
    uint16_t _t;
    uint32_t offset;
}; // struct Addr

} // namespace codu

#endif // __CODU_ADDR_H__
