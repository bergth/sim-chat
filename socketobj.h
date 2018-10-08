#include <string>

class Socketobj
{
    private:
        int fd;
        
    public:
        Socketobj();
        void co(std::string addr, int port);
        void li(int port);
        void se(char* val, size_t n);
        void re();
        
};