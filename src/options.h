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
     * @brief index block size, 64MB for default
     */
    uint32_t index_block_size;

    /**
     * @brief table block size, 512MB for default
     */
    uint32_t table_block_size;

    /**
     * @brief wal block size, 512MB for default
     */
    uint32_t wal_block_size;

    /**
     * @brief default ttl time (in seconds) for records, -1 for default
     */
    int default_ttl;

    Options()
        : create_if_not_exist(false),
          num_channels(4),
          index_block_size(64 * 1024 * 1024),
          table_block_size(512 * 1024 * 1024),
          wal_block_size(512 * 1024 * 1024),
          default_ttl(-1) {}
}; // struct Options

} // namespace codu

#endif // __CODU_OPTIONS_H__
