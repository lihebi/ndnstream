// #ifndef _CHATAPP_H_
// #define _CHATAPP_H_
#include "ns3/ndn-app.h"

#include "ns3/ndn-app-face.h"
#include "ns3/random-variable.h"

namespace ns3 {

class StreamProducer : public ndn::App
{
public:
  static TypeId GetTypeId();
  void StartApplication();
  void StopApplication();
  void OnInterest(Ptr<const ndn::Interest> interest);
  void OnData(Ptr<const ndn::Data> contentObject);
  void SendData(const std::string &name, const std::string &msg);
  void SendData(const ndn::Name &name, const std::string &msg);
  void DataPeriod(std::string name);
};

} //end namespace ns3

// #endif
