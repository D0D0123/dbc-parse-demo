#include <fstream>
#include <dbcppp/Network.h>

using namespace dbcppp;

int main() 
{
    std::unique_ptr<dbcppp::INetwork> net;
    std::ifstream idbc("example.dbc");
    net = dbcppp::INetwork::LoadDBCFromIs(idbc);

    /* 
        Once the library parses the DBC file, 
        it serialises the information into various iterable objects (IMessage, ISignal, etc).
    */
    for (const IMessage& msg : net->Messages()) {
        std::cout << "Name: " << msg.Name() << std::endl;
        std::cout << "Id: " << msg.Id() << std::endl;
        std::cout << "Length in bytes: " << msg.MessageSize() << std::endl;
        
        std::cout << "Signals: " << std::endl;
        for (const ISignal& sig : msg.Signals()) {
            std::cout << "=========================" << std::endl;
            std::cout << "Sensor Name: " << sig.Name() << std::endl;
            std::cout << "Start Bit: " << sig.StartBit() << std::endl;
            std::cout << "Bit Size: " << sig.BitSize() << std::endl;
            std::cout << "Units: " << sig.Unit() << std::endl;
        }

    }
}