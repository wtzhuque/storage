/*********************************/
/* Codu07                        */
/* Email: wtzhuque@163.com       */
/*********************************/

#include <string>

namespace codu {

class Engine {
public:
    Engine();

    ~Engine();

    int init();

    int destroy();

    int put(const std::string& key, const std::string& value);

    int get(const std::string& key, std::string* value);
}; // class Engine

} // namespace codu
