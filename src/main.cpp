/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <memory>

#include "engine.h"

namespace codu {

int run(int argc, char** argv) {
    fprintf(stderr, "Storage Benchmark\n");

    std::shared_ptr<Engine> engine = std::make_shared<Engine>();
    int ret = engine->init();
    if (ret != 0) {
        fprintf(stderr, "init engine failed\n");
    }

    ret = engine->destroy();
    if (ret != 0) {
        fprintf(stderr, "destroy engine failed\n");
    }

    return 0;
}

} // namespace codu

int main(int argc, char** argv) {
    return codu::run(argc, argv);
}
