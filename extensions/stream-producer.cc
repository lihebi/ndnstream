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

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"
// #include "../hebi.h"
#include<boost/foreach.hpp>

#include "stream-producer.h"

NS_LOG_COMPONENT_DEFINE("StreamProducer");

namespace ns3 {

  NS_OBJECT_ENSURE_REGISTERED(StreamProducer);


  TypeId StreamProducer::GetTypeId()
  {
    static TypeId tid = TypeId("StreamProducer")
    .SetParent<ndn::App>()
    .AddConstructor<StreamProducer>()
    ;
    return tid;
  }

  void StreamProducer::StartApplication()
  {
    // NS_LOG_DEBUG(Simulator::Now().GetSeconds());

    ndn::App::StartApplication();
    Ptr<ndn::Fib> fib = GetNode()->GetObject<ndn::Fib>();
    Ptr<ndn::Name> prefix = Create<ndn::Name>("/video");
    fib->Add(*prefix, m_face, 0);
  }

  void StreamProducer::StopApplication()
  {
    ndn::App::StopApplication();
  }

  void StreamProducer::DataPeriod(std::string name)
  {
    SendData(name, "Hello");
    name[name.length()-1]++;
    Simulator::Schedule(Seconds(1), &StreamProducer::DataPeriod, this, name);
  }

  void StreamProducer::OnInterest(Ptr<const ndn::Interest> interest)
  {
    NS_LOG_DEBUG("Received Interest: "<<interest->GetName());
    ndn::App::OnInterest(interest);
    // DataPeriod(interest->GetName().toUri());
    Simulator::Schedule(Seconds(0), &StreamProducer::DataPeriod, this, interest->GetName().toUri());
  }

  void StreamProducer::OnData(Ptr<const ndn::Data> contentObject)
  {
    NS_LOG_DEBUG("Received Data for: "<<contentObject->GetName());
  }

  void StreamProducer::SendData(const std::string &name, const std::string &msg)
  {
    const ndn::Name _name(name);
    SendData(_name, msg);
  }
  void StreamProducer::SendData(const ndn::Name &name, const std::string &msg)
  {
    NS_LOG_DEBUG("Send Data for: "<<name);
    Ptr<Packet> packet = Create<Packet>(msg);
    Ptr<ndn::Data> data = Create<ndn::Data>(packet);
    data->SetName(name);
    m_transmittedDatas(data, this, m_face);
    m_face->ReceiveData(data);
  }




} //ns3
