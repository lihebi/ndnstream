/*
* Need Improve:
* 	1. use boost::posix_time instead of time(NULL)
* Next Step:
* 	1. add tracer
* 	2. do experiment
* 	3. implement ChronoSync
*/

// #include "drs-app.h"
#include "ns3/ptr.h"
#include "ns3/log.h"
#include "ns3/simulator.h"
#include "ns3/packet.h"

#include "ns3/ndn-app-face.h"
#include "ns3/ndn-interest.h"
#include "ns3/ndn-data.h"

#include "ns3/ndn-fib.h"
#include "ns3/random-variable.h"
#include "ns3/core-module.h"
// #include "../hebi.h"
#include<boost/foreach.hpp>

#include "stream-consumer.h"

NS_LOG_COMPONENT_DEFINE("StreamConsumer");

namespace ns3 {

  NS_OBJECT_ENSURE_REGISTERED(StreamConsumer);


  TypeId StreamConsumer::GetTypeId()
  {
    static TypeId tid = TypeId("StreamConsumer")
    .SetParent<ndn::App>()
    .AddConstructor<StreamConsumer>()
    ;
    return tid;
  }

  void StreamConsumer::StartApplication()
  {
    // NS_LOG_DEBUG(Simulator::Now().GetSeconds());
    ndn::App::StartApplication();
    Simulator::Schedule(Seconds(1), &StreamConsumer::Period, this);
  }

  void StreamConsumer::Period()
  {
    SendInterest("/video/0");
    // Simulator::Schedule(Seconds(1), &StreamConsumer::Period, this);
  }

  void StreamConsumer::StopApplication()
  {
    ndn::App::StopApplication();
  }

  void StreamConsumer::OnInterest(Ptr<const ndn::Interest> interest)
  {
    NS_LOG_DEBUG("Received Interest: "<<interest->GetName());
    ndn::App::OnInterest(interest);
  }
  void StreamConsumer::OnData(Ptr<const ndn::Data> contentObject)
  {
    NS_LOG_DEBUG("Received Data for: "<<contentObject->GetName());
  }

  void StreamConsumer::SendInterest(const std::string &name)
  {
    const ndn::Name _name(name);
    SendInterest(_name);
  }
  void StreamConsumer::SendInterest(const ndn::Name &name)
  {
    NS_LOG_DEBUG("Send Interest for: "<<name);
    Ptr<ndn::Interest> interest = Create<ndn::Interest>();
    UniformVariable rand(0, std::numeric_limits<uint32_t>::max());
    interest->SetNonce(rand.GetValue());
    interest->SetName(name);
    interest->SetInterestLifetime(Seconds(5)); //????
    m_transmittedInterests(interest, this, m_face);
    m_face->ReceiveInterest(interest);
  }


} //ns3
