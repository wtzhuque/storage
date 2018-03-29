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

    Options options;

    std::shared_ptr<Engine> engine = std::make_shared<Engine>();
    int ret = engine->init("./db", options);
    if (ret != 0) {
        fprintf(stderr, "init engine failed\n");
    }

    const std::string test_key = "test_key";
    std::string test_value = "test_value";

    engine->put(test_key, test_value);

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
