/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#ifndef __CODU_OPTIONS_H__
#define __CODU_OPTIONS_H__

namespace codu {

struct Options {
    bool create_if_not_exist;

    /**
     * @brief number of channels, 4 for default 
     */
    uint32_t num_channels;

    /**
     * @brief default ttl time (in seconds) for records, -1 for default
     */
    int default_ttl;

    Options()
        : create_if_not_exist(false),
          num_channels(4),
          default_ttl(-1) {}
}; // struct Options

} // namespace codu

#endif // __CODU_OPTIONS_H__
